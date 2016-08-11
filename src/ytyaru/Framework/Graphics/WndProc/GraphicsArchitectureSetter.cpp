#include "GraphicsArchitectureSetter.h"
#include "GdiWndProc.h"
#include "GdiPlusWndProc.h"
#include "DirectX9WndProc.h"

#include "GdiDrawer.h"
#include "GdiPlusDrawer.h"
#include "DirectX9Drawer.h"

using ytyaru::Framework::Graphics::Drawer::IGdiDrawer;
using ytyaru::Framework::Graphics::Drawer::IGdiPlusDrawer;
using ytyaru::Framework::Graphics::Drawer::IDirectX9Drawer;

GraphicsArchitectureSetter::GraphicsArchitectureSetter()
{
	m_gdi = NULL;
	m_gdiPlus = NULL;
	m_directX9 = NULL;
	m_selected = NULL;
}
GraphicsArchitectureSetter::~GraphicsArchitectureSetter(void)
{
	Finalize();
}
void GraphicsArchitectureSetter::Initialize()
{
	// 以下を切替できる機構がほしい
	// GraphicsArchitectureWndProc
	//   GdiWndProc
	//   GdiPlusWndProc
	//   DirectX9WndProc
	// GraphicsArchitectureDrawer
	//   GdiDrawer
	//   GdiPlusDrawer
	//   DirectX9Drawer

	m_gdiDrawer = (IGdiDrawer*) new GdiDrawer();
	m_gdiPlusDrawer = (IGdiPlusDrawer*) new GdiPlusDrawer();
	m_directX9Drawer = (IDirectX9Drawer*) new DirectX9Drawer();
	
	if (NULL == m_gdi) { m_gdi = new GdiWndProc(m_gdiDrawer); }
	if (NULL == m_gdiPlus) { m_gdiPlus = new GdiPlusWndProc(m_gdiPlusDrawer); }
	if (NULL == m_directX9) { m_directX9 = new DirectX9WndProc(m_directX9Drawer); }

	//if (NULL == m_gdi) { m_gdi = new GdiWndProc(); }
	//if (NULL == m_gdiPlus) { m_gdiPlus = new GdiPlusWndProc(); }
	//if (NULL == m_directX9) { m_directX9 = new DirectX9WndProc(); }
	Set(_T("GDI"));
}
void GraphicsArchitectureSetter::Finalize()
{
	//// 切替できる機構がほしい 	
	// 現在 Drawer の delete は GdiWndProc, GdiPlusWndProc, DirectX9WndProc がそれぞれやってくれている
	//if (NULL != m_gdiDrawer) {
	//	delete m_gdiDrawer;
	//	m_gdiDrawer = NULL;
	//}
	//if (NULL != m_gdiPlusDrawer) {
	//	delete m_gdiPlusDrawer;
	//	m_gdiPlusDrawer = NULL;
	//}
	//if (NULL != m_directX9Drawer) {
	//	delete m_directX9Drawer;
	//	m_directX9Drawer = NULL;
	//}
	


	if (NULL != m_gdi) {
		delete m_gdi;
		m_gdi = NULL;
	}
	if (NULL != m_gdiPlus) {
		delete m_gdiPlus;
		m_gdiPlus = NULL;
	}
	if (NULL != m_directX9) {
		delete m_directX9;
		m_directX9 = NULL;
	}
}
void GraphicsArchitectureSetter::Set(const std::basic_string<TCHAR> &name)
{
	if (3 == _tcslen(name.c_str()) && 0 == _tcsnicmp(_T("GDI"), name.c_str(), 3)) { this->Change(m_gdi); }
	else if (0 == _tcsnicmp(_T("GDI+"), name.c_str(), 4)
		|| 0 == _tcsnicmp(_T("GDIPlus"), name.c_str(), 7)
		|| 0 == _tcsnicmp(_T("GDI_Plus"), name.c_str(), 8)
		|| 0 == _tcsnicmp(_T("GDI-Plus"), name.c_str(), 8)
		|| 0 == _tcsnicmp(_T("GDI Plus"), name.c_str(), 8)) { this->Change(m_gdiPlus); }
	else if (0 == _tcsnicmp(_T("DirectX9"), name.c_str(), 8)
		|| 0 == _tcsnicmp(_T("DirectX_9"), name.c_str(), 9)
		|| 0 == _tcsnicmp(_T("DirectX-9"), name.c_str(), 9)
		|| 0 == _tcsnicmp(_T("DirectX 9"), name.c_str(), 9)) { this->Change(m_directX9); }
	else { this->Change(NULL); }
}
IDrawWndProc* GraphicsArchitectureSetter::Get()
{
	return m_selected;
}
IDrawWndProc* GraphicsArchitectureSetter::Get(const std::basic_string<TCHAR> &name)
{
	if (0 == _tcsnicmp(_T("GDI"), name.c_str(), 3)) { return m_gdi; }
	else if (0 == _tcsnicmp(_T("GDI+"), name.c_str(), 4)
		|| 0 == _tcsnicmp(_T("GDIPlus"), name.c_str(), 7)
		|| 0 == _tcsnicmp(_T("GDI_Plus"), name.c_str(), 8)
		|| 0 == _tcsnicmp(_T("GDI-Plus"), name.c_str(), 8)
		|| 0 == _tcsnicmp(_T("GDI Plus"), name.c_str(), 8)) { return m_gdiPlus; }
	else if (0 == _tcsnicmp(_T("DirectX9"), name.c_str(), 8)
		|| 0 == _tcsnicmp(_T("DirectX_9"), name.c_str(), 9)
		|| 0 == _tcsnicmp(_T("DirectX-9"), name.c_str(), 9)
		|| 0 == _tcsnicmp(_T("DirectX 9"), name.c_str(), 9)) { return m_directX9; }
	else { return NULL; }
}
void GraphicsArchitectureSetter::Change(IDrawWndProc* newProc)
{
	if (NULL == newProc) {
		if (NULL != m_selected) { 
			m_selected->Finalize();
		}
		m_selected = NULL;
		InvalidateRect(0, 0, FALSE); // 画面全体を再描画
	}
	else if (m_selected != newProc) {
		if (NULL != m_selected) { 
			m_selected->Finalize();
		}
		m_selected = newProc;
		m_selected->Initialize();
		InvalidateRect(0, 0, FALSE); // 画面全体を再描画
	}
	else {}
}