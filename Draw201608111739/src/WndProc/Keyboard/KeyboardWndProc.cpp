#include "KeyboardWndProc.h"

KeyboardWndProc::KeyboardWndProc(GraphicsArchitectureSetter* graphicsArchitectureSetter)
	: m_graphicsArchitectureSetter(graphicsArchitectureSetter) {}
KeyboardWndProc::~KeyboardWndProc(void) {}
LRESULT CALLBACK KeyboardWndProc::PartWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL* pIsReturn)
{
	switch (uMsg) {
		case WM_KEYDOWN:
			switch (wParam)
			{
			case 0x31: //VK_1: ASCII�R�[�h�Ɠ���
			case 0x61: //VK_NUMPAD1:
				m_graphicsArchitectureSetter->Set(_T("GDI"));
				SetWindowText(::GetActiveWindow(), _T("GDI�ŕ`�悵�Ă��܂��B1:GDI, 2:GDI+, 3:DirectX9  1�`3�̂����ꂩ�̃L�[����͂��ĉ������B"));
				break;
			case 0x32: //VK_2: ASCII�R�[�h�Ɠ���
			case 0x62: //VK_NUMPAD2:
				m_graphicsArchitectureSetter->Set(_T("GDI+"));
				SetWindowText(::GetActiveWindow(), _T("GDI+�ŕ`�悵�Ă��܂��B1:GDI, 2:GDI+, 3:DirectX9  1�`3�̂����ꂩ�̃L�[����͂��ĉ������B"));
				break;
			case 0x33: //VK_3: ASCII�R�[�h�Ɠ���
			case 0x63: //VK_NUMPAD3:
				m_graphicsArchitectureSetter->Set(_T("DirectX9"));
				SetWindowText(::GetActiveWindow(), _T("DirectX9�ŕ`�悵�Ă��܂��B1:GDI, 2:GDI+, 3:DirectX9  1�`3�̂����ꂩ�̃L�[����͂��ĉ������B"));
				break;
			default:
				MessageBox(hWnd, _T("Window1 KeyboardWndProc::PartWndProc"), _T("WM_KEYDOWN"), MB_OK);
				break;
			}
			break;
		default:
			break;
	}
	return (0L);
}
