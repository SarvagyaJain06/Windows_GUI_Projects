#include <windows.h>
///**********************************
// This program adds menus and sub menus 
//  to the window creted.
///*********************************


#define FILE_MENU_NEW 1
#define FILE_MENU_OPEN 2
#define FILE_MENU_SAVE 3
#define FILE_MENU_EXIT 4
#define FILE_MENU_SUBMENU 5

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
void AddMenus(HWND hwnd);
HMENU hMenu;

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
	CreateWindowW(L"myWindowClass", L"My window", WS_OVERLAPPED | WS_VISIBLE, 100, 100, 500, 500, NULL, NULL, NULL, NULL);

	MSG msg = { 0 };
	while (GetMessage(&msg, NULL, NULL, NULL))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}




LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg)
	{
	case WM_COMMAND:
	{
		switch (wParam) {
		case FILE_MENU_NEW:
		{
			MessageBeep(MB_OK);
			break;
		}
		case FILE_MENU_EXIT:
		{
			DestroyWindow(hWnd);
			break;
		}
		}
	}
	case WM_CREATE:
	{
		AddMenus(hWnd);
	}
	break;
	case WM_DESTROY:
	{
		PostQuitMessage(0);
	}
	break;
	default:
	{
		return DefWindowProcW(hWnd, msg, wParam, lParam);
	}

	}
}

void AddMenus(HWND hWnd) {
	hMenu = CreateMenu();
	HMENU hFileMenu = CreateMenu();
	HMENU hSubMenu = CreateMenu();

	AppendMenuW(hSubMenu, MF_STRING, FILE_MENU_SUBMENU, L"Open with");
	AppendMenuW(hFileMenu, MF_STRING, FILE_MENU_NEW, L"New");
	AppendMenuW(hFileMenu, MF_POPUP,(UINT) hSubMenu, L"Open");
	AppendMenuW(hFileMenu, MF_STRING, FILE_MENU_SAVE, L"Save");
	AppendMenuW(hFileMenu, MF_SEPARATOR, NULL, NULL);
	AppendMenuW(hFileMenu, MF_STRING, FILE_MENU_EXIT, L"Exit");

	AppendMenuW(hMenu,MF_POPUP,(UINT_PTR) hFileMenu,L"File" );
	AppendMenuW(hMenu, MF_STRING, 1, L"Help");
	SetMenu(hWnd,hMenu);
}