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
	LPTSTR lptStr = TEXT("���̕������GDI�ŕ`�悵�Ă��܂��B");
	TextOut(hdc , 10 , 10 , lptStr , _tcslen(lptStr));
}