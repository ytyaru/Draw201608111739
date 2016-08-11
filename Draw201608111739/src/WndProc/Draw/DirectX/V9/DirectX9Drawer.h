#pragma once
#include "IDirectX9Drawer.h"

class DirectX9Drawer : public ytyaru::Framework::Graphics::Drawer::IDirectX9Drawer
{
public:
	DirectX9Drawer(void);
	~DirectX9Drawer(void);
	virtual void Draw(const LPDIRECT3DDEVICE9 lpD3DDev);
	virtual void Initialize();
	virtual void Finalize();
};
