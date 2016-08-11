#pragma once
#include "Window.h"
#include "IPartWndProc.h"
#include "IDrawWndProc.h"

#include "IGdiDrawer.h"
#include "IGdiPlusDrawer.h"
#include "IDirectX9Drawer.h"

class GraphicsArchitectureSetter
{
public:
    GraphicsArchitectureSetter();
    ~GraphicsArchitectureSetter();
	void Initialize();
	void Finalize();
    void Set(const std::basic_string<TCHAR> &name);
	IDrawWndProc* Get();
	IDrawWndProc* Get(const std::basic_string<TCHAR> &name);
private:
	void Change(IDrawWndProc* newProc);
	IDrawWndProc* m_selected;

	// �ؑւł���@�\���ق���
	IDrawWndProc* m_gdi;
	IDrawWndProc* m_gdiPlus;
	IDrawWndProc* m_directX9;
	// �ؑւł���@�\���ق���
	ytyaru::Framework::Graphics::Drawer::IGdiDrawer* m_gdiDrawer;
	ytyaru::Framework::Graphics::Drawer::IGdiPlusDrawer* m_gdiPlusDrawer;
	ytyaru::Framework::Graphics::Drawer::IDirectX9Drawer* m_directX9Drawer;
};
