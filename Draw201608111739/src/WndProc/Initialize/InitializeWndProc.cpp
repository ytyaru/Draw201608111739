#include "InitializeWndProc.h"

InitializeWndProc::InitializeWndProc(void) {}
InitializeWndProc::~InitializeWndProc(void) {}
LRESULT CALLBACK InitializeWndProc::PartWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL* pIsReturn)
{
	switch (uMsg) {
    	case WM_CREATE:
    		MessageBox(hWnd, _T("Window1 InitializeWndProc::PartWndProc"), _T("WM_CREATE"), MB_OK);
			SetWindowText(::GetActiveWindow(), _T("1:GDI, 2:GDI+, 3:DirectX9  1�`3�̂����ꂩ�̃L�[����͂��ĉ������B"));
    		break;
		default:
			break;
	}
	return (0L);
}
