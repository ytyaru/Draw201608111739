#pragma once
#include "IDrawWndProc.h"
#include "IGdiDrawer.h"

class GdiWndProc : public IDrawWndProc
{
public:
	//GdiWndProc(void);
	explicit GdiWndProc(ytyaru::Framework::Graphics::Drawer::IGdiDrawer* drawer);
	~GdiWndProc(void);
	virtual void Initialize();
	virtual void Finalize();
	virtual LRESULT CALLBACK PartWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL* pIsReturn);
private:
	//void OnPaint(HDC hdc);
	ytyaru::Framework::Graphics::Drawer::IGdiDrawer* m_drawer;
};

