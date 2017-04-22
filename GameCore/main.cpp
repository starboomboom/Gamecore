#include <Windows.h>
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define  WINDOW_TITLE L"程序核心框架"

LRESULT CALLBACK WndProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam);
//窗口过程函数

int WINAPI WinMain( __in HINSTANCE hInstance, __in_opt HINSTANCE hPrevInstance, __in LPSTR lpCmdLine, __in int nShowCmd )
{

	WNDCLASSEX winClass = {0};
	winClass.cbSize = sizeof(WNDCLASSEX);
	winClass.style = CS_HREDRAW|CS_VREDRAW;
	winClass.lpfnWndProc  = WndProc;
	winClass.cbClsExtra = 0;
	winClass.cbWndExtra = 0;
	winClass.hInstance = hInstance;
	winClass.hIcon = (HICON)::LoadImage(NULL,L"icon.ico",IMAGE_ICON,0,0,LR_DEFAULTSIZE|LR_LOADFROMFILE);
	winClass.hCursor = LoadCursor(NULL,IDC_ARROW);
	winClass.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	winClass.lpszMenuName = NULL;
	winClass.lpszClassName = L"ForTheDreamOfGameDevelop";

	//注册窗口类
	if(!RegisterClassEx(&winClass))
		return -1;
	//正式创建窗口
	HWND hwnd = CreateWindow(L"ForTheDreamOfGameDevelop",WINDOW_TITLE,WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,WINDOW_WIDTH,WINDOW_HEIGHT,NULL,NULL,hInstance,NULL);

	MoveWindow(hwnd,250,80,WINDOW_WIDTH,WINDOW_HEIGHT,true);

	ShowWindow(hwnd,nShowCmd);
	UpdateWindow(hwnd);

	MSG msg = {0};
	while(msg.message!=WM_QUIT)
	{

		if(PeekMessage(&msg,0,0,0,PM_REMOVE))
		{

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

	}

	//窗口类注销
	UnregisterClass(L"ForTheDreamOfGameDevelop",winClass.hInstance);
	return 0;

}
LRESULT CALLBACK WndProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam)
{

	switch (message)
	{
	case WM_PAINT:
		ValidateRect(hwnd,NULL);
		break;
	case WM_KEYDOWN:
		if(wParam==VK_ESCAPE)
			DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd,message,wParam,lParam);
	}
	return 0;
}