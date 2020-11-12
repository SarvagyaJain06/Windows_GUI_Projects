#include <windows.h>

///******************************************
// This program is creates a window.
//
//*******************************************

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);


int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow)
{
	WNDCLASSW windowClass = { 0 };

	windowClass.hbrBackground = (HBRUSH)COLOR_WINDOW;
	windowClass.hCursor = LoadCursor(NULL, IDC_CROSS);
	windowClass.hInstance = hInst;
	windowClass.lpszClassName = L"myWindowClass";
	windowClass.lpfnWndProc = WindowProcedure;

	if (!RegisterClassW(&windowClass))
		return -1;
	CreateWindowW(L"myWindowClass",L"My window",WS_OVERLAPPED | WS_VISIBLE,100,100,500,500,NULL,NULL,NULL,NULL);

	MSG msg = { 0 };
	while (GetMessage(&msg,NULL,NULL,NULL))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}




LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg)
	{
	case WM_DESTROY :
	{
		PostQuitMessage(0);
	}
	break;
	default :
	{
		return DefWindowProcW(hwnd, msg, wParam, lParam);
	}

	}
}