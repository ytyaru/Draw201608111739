#pragma once
#include <Windows.h>
#include <tchar.h>
#include <vector>
#include <map>
#include <string>
#include "IPartWndProc.h"
#include "GraphicsArchitectureSetter.h"
#include "GdiWndProc.h"
#include "GdiPlusWndProc.h"
#include "DirectX9WndProc.h"

class DrawWndProc : public ytyaru::Framework::WndProc::IPartWndProc
{
public:
	explicit DrawWndProc(GraphicsArchitectureSetter* graphicsArchitectureSetter);
	~DrawWndProc(void);
	virtual LRESULT CALLBACK PartWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL* pIsReturn);
	void Initialize();
	void Finalize();
private:
	GraphicsArchitectureSetter* m_graphicsArchitectureSetter;
};

