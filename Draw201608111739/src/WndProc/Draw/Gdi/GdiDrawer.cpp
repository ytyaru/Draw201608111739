#include "GdiDrawer.h"
#include "Windows.h"
#include "tchar.h"

GdiDrawer::GdiDrawer(void)
{
}
GdiDrawer::~GdiDrawer(void)
{
}
void GdiDrawer::Initialize()
{
}
void GdiDrawer::Finalize()
{
}
void GdiDrawer::Draw(const HDC hdc)
{
	LPTSTR lptStr = TEXT("この文字列はGDIで描画しています。");
	TextOut(hdc , 10 , 10 , lptStr , _tcslen(lptStr));
}