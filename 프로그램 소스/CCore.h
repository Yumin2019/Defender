#pragma once

#include "Game.h"

class CCore
{
	DECLARE_SINGLE(CCore);

private:
	HWND m_hWnd;
	HINSTANCE m_hInst;
	WNDCLASSEX wc;
	

public:
	static LPDIRECT3D9             m_pd3d;
	static LPDIRECT3DDEVICE9       m_pd3dDevice;
	static LPD3DXSPRITE			m_pSprite;
	static LPD3DXFONT				m_pFont;
	static bool m_bLoop;

private:
	HRESULT InitD3D();
	HRESULT InitGame();

	void Window();


	static LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static VOID Cleanup();

	void Logic();
	void Input(float fDeltaTime);
	void Collision(float fDeltaTime);
	void Update(float fDeltaTime);
	void Render(float fDeltaTime);

public:

	bool Init(HINSTANCE hInst);
	void Run();

	HWND GetHandle() const;

};

