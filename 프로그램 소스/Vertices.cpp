
#include "CCore.h"


//-----------------------------------------------------------------------------
// Name: wWinMain()
// Desc: The application's entry point
//-----------------------------------------------------------------------------
INT WINAPI wWinMain( HINSTANCE hInst, HINSTANCE, LPWSTR, INT )
{

	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	srand((unsigned int)time(NULL));

	if (!GET_SINGLE(CCore)->Init(hInst))
	{
		DESTROY_SINGLE(CCore);
		return 0;
	}

	GET_SINGLE(CCore)->Run();


	DESTROY_SINGLE(CCore);

    return 0;
}
