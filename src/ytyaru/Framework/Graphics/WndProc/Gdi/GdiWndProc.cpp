#include "GdiWndProc.h"
using ytyaru::Framework::Graphics::Drawer::IGdiDrawer;

//GdiWndProc::GdiWndProc(void) {}
GdiWndProc::GdiWndProc(IGdiDrawer* drawer) : m_drawer(drawer) {}
GdiWndProc::~GdiWndProc(void) {}
void GdiWndProc::Initialize() { m_drawer->Initialize(); }
void GdiWndProc::Finalize() { m_drawer->Finalize(); }
LRESULT CALLBACK GdiWndProc::PartWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL* pIsReturn)
{
	switch (uMsg) {
		// ƒoƒO‚é
		//case WM_ERASEBKGND:
		//	*pIsReturn = TRUE;
		//	return TRUE;
		case WM_PAINT:
			HDC hdc;
			PAINTSTRUCT ps;
			hdc = BeginPaint(hWnd , &ps);
			//OnPaint(hdc);
			m_drawer->Draw(hdc);
			EndPaint(hWnd , &ps);
			break;
		default:
			break;
	}
	return (0L);
}
//void GdiWndProc::OnPaint(HDC hdc)
//{
//	LPTSTR lptStr = TEXT("‚±‚Ì•¶š—ñ‚ÍGDI‚Å•`‰æ‚µ‚Ä‚¢‚Ü‚·B");
//	TextOut(hdc , 10 , 10 , lptStr , _tcslen(lptStr));
//}