#pragma once
//#include <gdiplus.h>
#include "IGdiPlusDrawer.h"

class GdiPlusDrawer : public ytyaru::Framework::Graphics::Drawer::IGdiPlusDrawer
{
public:
	GdiPlusDrawer(void);
	~GdiPlusDrawer(void);
	virtual void Draw(Gdiplus::Graphics* g);
	virtual void Initialize();
	virtual void Finalize();
};

