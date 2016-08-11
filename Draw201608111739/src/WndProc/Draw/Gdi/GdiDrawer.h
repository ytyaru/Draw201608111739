#pragma once
#include "IGdiDrawer.h"

class GdiDrawer : public ytyaru::Framework::Graphics::Drawer::IGdiDrawer
{
public:
	GdiDrawer(void);
	~GdiDrawer(void);
	virtual void Draw(const HDC hdc);
	virtual void Initialize();
	virtual void Finalize();
};

