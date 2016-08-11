#include "DirectX9Drawer.h"

DirectX9Drawer::DirectX9Drawer(void)
{
}
DirectX9Drawer::~DirectX9Drawer(void)
{
}
void DirectX9Drawer::Initialize()
{
}
void DirectX9Drawer::Finalize()
{
}
void DirectX9Drawer::Draw(const LPDIRECT3DDEVICE9 lpD3DDev)
{
	lpD3DDev->Clear( 0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0,0,255), 1.0f, 0 );
	lpD3DDev->BeginScene();

	// ‰½‚©•`‰æ‚·‚é

	lpD3DDev->EndScene();
	lpD3DDev->Present( NULL, NULL, NULL, NULL );
}