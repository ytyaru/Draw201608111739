#pragma once
#include "IDrawWndProc.h"
#include <Windows.h>
#include <d3d9.h>
#include "IDirectX9Drawer.h"

class DirectX9WndProc : public IDrawWndProc
{
public:
	//DirectX9WndProc(void);
	explicit DirectX9WndProc(ytyaru::Framework::Graphics::Drawer::IDirectX9Drawer* drawer);
	~DirectX9WndProc(void);
	virtual void Initialize();
	virtual void Finalize();
	virtual LRESULT CALLBACK PartWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL* pIsReturn);
private:
	//void OnPaint();
	ytyaru::Framework::Graphics::Drawer::IDirectX9Drawer* m_drawer;
	LPDIRECT3D9 m_pD3D;
	LPDIRECT3DDEVICE9 m_pD3DDev;
};

