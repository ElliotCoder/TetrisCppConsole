#include "cgameprocess.h"

void main()
{
	setlocale(0, "Russian");
	//��������� ����
	HWND hWnd = GetConsoleWindow();
	SetWindowPos(hWnd, HWND_TOPMOST, 5, 5, 0, 0, 0);
	
	system("mode con cols=124 lines=59"); //��� 1024 * 768
	SetConsoleTitle(L"������(c) 2012, ���� �������, �� ���");
	system("color f0");

	CGameProcess Game; Game.MainMenu();
}