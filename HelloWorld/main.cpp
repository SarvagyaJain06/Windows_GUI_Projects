#include <windows.h>


///******************************************
// This program is creates a message box.
//
//*******************************************
int WINAPI WinMain(HINSTANCE hInst,HINSTANCE hPrevInst,LPSTR args,int ncmdshow ) {
	MessageBox(NULL, L"Hello World", L"My first GUI",MB_OK);
	return 0;
}
