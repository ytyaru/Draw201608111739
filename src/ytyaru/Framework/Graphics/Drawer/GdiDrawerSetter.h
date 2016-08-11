#pragma once
#include <tchar.h>
#include <string>
#include <vector>
#include "IGdiDrawer.h"

namespace ytyaru {
namespace Framework {
namespace Graphics {
namespace Drawer {
class GdiDrawerSetter
{
public:
	GdiDrawerSetter(void);
	~GdiDrawerSetter(void);
	void Set(int index);
	void Next();
	void Prev();
	void First();
	void Last();
	void Set(std::basic_string<TCHAR> name);
private:
	ytyaru::Framework::Graphics::Drawer::IGdiDrawer* m_selected;
	std::vector<std::pair<std::basic_string<TCHAR>, ytyaru::Framework::Graphics::Drawer::IGdiDrawer*>> m_drawers;
};
}
}
}
}
