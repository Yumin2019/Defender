#include "CCore.h"
#include "CCollisionManager.h"
#include "CCreateManager.h"
#include "CInput.h"
#include "CTimer.h"
#include "CSceneManager.h"



DEFINITION_SINGLE(CCore);


LPDIRECT3D9             CCore::m_pd3d				= NULL;
LPDIRECT3DDEVICE9       CCore::m_pd3dDevice			= NULL;
LPD3DXSPRITE			CCore::m_pSprite			= NULL;
LPD3DXFONT				CCore::m_pFont				= NULL;
bool					CCore::m_bLoop = true;



CCore::CCore()
{
	//_CrtSetBreakAlloc(3321);

	ShowCursor(FALSE);
}


CCore::~CCore()
{
	UnregisterClass(L"D3D Tutorial", wc.hInstance);


	DESTROY_SINGLE(CSceneManager);
	DESTROY_SINGLE(CCollisionManager);
	DESTROY_SINGLE(CCreateManager);
	DESTROY_SINGLE(CInput);
	DESTROY_SINGLE(CTimer);



}

HRESULT CCore::InitD3D()
{
	// Create the D3D object.
	if (NULL == (m_pd3d = Direct3DCreate9(D3D_SDK_VERSION)))
		return E_FAIL;

	// Set up the structure used to create the D3DDevice
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));


	/*d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
*/

	d3dpp.Windowed = FALSE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.hDeviceWindow = m_hWnd;
	d3dpp.BackBufferHeight = RS_HEIGHT;
	d3dpp.BackBufferWidth = RS_WIDTH;




	// Create the D3DDevice
	if (FAILED(m_pd3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, m_hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp, &m_pd3dDevice)))
	{
		return E_FAIL;
	}

	// Device state would normally be set here

	return S_OK;
}

HRESULT CCore::InitGame()
{
	// 스프라이트 

	D3DXCreateSprite(m_pd3dDevice, &m_pSprite);


	// 폰트 
	D3DXCreateFont(m_pd3dDevice, 50, 30, 500, 0, NULL, NULL, NULL, NULL, NULL, L"Font", &m_pFont);


	// 서브매니저

	// 생성 관리자 초기화
	if (!GET_SINGLE(CCreateManager)->Init())
		return S_FALSE;

	// 입력 관리자 초기화
	if (!GET_SINGLE(CInput)->Init())
		return S_FALSE;

	// 장면 관리자 초기화
	if (!GET_SINGLE(CSceneManager)->Init())
		return S_FALSE;

	// 충돌 관리자
	if (!GET_SINGLE(CCollisionManager)->Init())
		return S_FALSE;

	// 타이머
	if (!GET_SINGLE(CTimer)->Init())
		return S_FALSE;



	return S_OK;
}

void CCore::Window()
{

	

	// Register the window class
	wc =
	{
		sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0L, 0L,
		GetModuleHandle(NULL), LoadIcon(m_hInst, MAKEINTRESOURCE(IDI_ICON1)), NULL, NULL, NULL,
		L"D3D Tutorial", NULL
	};
	RegisterClassEx(&wc);

	// Create the application's window
	m_hWnd = CreateWindow(L"D3D Tutorial", L"Defender",
		WS_EX_TOPMOST | WS_POPUP, 100, 100, 300, 300,
		NULL, NULL, wc.hInstance, NULL);


	// WS_EX_TOPMOST WS_POPUP

	RECT rc = { 0, 0, RS_WIDTH, RS_HEIGHT };

	AdjustWindowRect(&rc, WS_EX_TOPMOST| WS_POPUP, FALSE);
	
	SetWindowPos(m_hWnd, HWND_TOPMOST, 0, 0, rc.right - rc.left, rc.bottom - rc.top, SWP_NOZORDER);


}

LRESULT __stdcall CCore::MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		Cleanup();
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

VOID CCore::Cleanup()
{
	if (m_pFont != NULL)
		m_pFont->Release();

	if (m_pSprite != NULL)
		m_pSprite->Release();

	if (m_pd3dDevice != NULL)
		m_pd3dDevice->Release();

	if (m_pd3d != NULL)
		m_pd3d->Release();
}

void CCore::Logic()
{
	GET_SINGLE(CTimer)->Update();

	float fDeltaTime = GET_SINGLE(CTimer)->GetDelta();

	Input(fDeltaTime);

	Collision(fDeltaTime);

	Update(fDeltaTime);

	Render(fDeltaTime);

	if (!m_bLoop)
	{
		DestroyWindow(m_hWnd);
	}
}

void CCore::Input(float fDeltaTime)
{
	// 인식
	GET_SINGLE(CInput)->Update();

	GET_SINGLE(CSceneManager)->Input(fDeltaTime);
}

void CCore::Collision(float fDeltaTime)
{
	// 추가
	GET_SINGLE(CSceneManager)->Collision(fDeltaTime);

	// 처리

	GET_SINGLE(CCollisionManager)->Update();
}

void CCore::Update(float fDeltaTime)
{
	GET_SINGLE(CSceneManager)->Update(fDeltaTime);

}


void CCore::Render(float fDeltaTime)
{
	m_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);

	// Begin the scene
	if (SUCCEEDED(m_pd3dDevice->BeginScene()))
	{

		
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND);


		// SceneManager Render

		GET_SINGLE(CSceneManager)->Render(fDeltaTime);


		m_pSprite->End();

		// End the scene
		m_pd3dDevice->EndScene();
	}

	// Present the backbuffer contents to the display
	m_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}

bool CCore::Init(HINSTANCE hInst)
{

	m_hInst = hInst;

	Window();

	return true;
}

void CCore::Run()
{

	// Initialize Direct3D
	if (SUCCEEDED(InitD3D()))
	{
		// Create the vertex buffer
		if (SUCCEEDED(InitGame()))
		{
			// Show the window
			ShowWindow(m_hWnd, SW_SHOWDEFAULT);
			UpdateWindow(m_hWnd);

			// Enter the message loop
			MSG msg;
			ZeroMemory(&msg, sizeof(msg));
			while (msg.message != WM_QUIT)
			{
				if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
				{
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
				else
					Logic();
			}
		}
	}
}

HWND CCore::GetHandle() const
{
	return m_hWnd;
}
