#include "cframe.h"

Cframe::Cframe(us margin_left, us margin_top, us width, us height, uc thickness, uc red, uc green, uc blue):
margin_left(margin_left), margin_top(margin_top), width(width), height(height), thickness(thickness),
	red(red), green(green), blue(blue)
{
	hDC = GetDC(GetConsoleWindow()); 
	Edge_Pen = CreatePen(PS_SOLID, thickness, RGB(red, green, blue)); //������� ����� � ���� � RGB
	Erase_Pen = CreatePen(PS_SOLID, thickness, RGB(255, 255, 255)); //����� ����
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//��� ��� ������� ������ ��� 1 ����� � ������� - (8 * 12) px
	Left_top.X = margin_left / 8 + 1; Left_top.Y = margin_top / 12 + 1; 
}

void Cframe::Draw() const
{
	SelectObject(hDC, Edge_Pen);
	//������ �����
	RoundRect(hDC, margin_left, margin_top, width + margin_left, height + margin_top, width / 40, height / 40); 
	//��������� ��� ��������� - ����������� ���������� �����
}

void Cframe::SetCursorToRow(const uc row_index) const
{
	//����� ���������� ����������� ������������ ������������ (������� �����)
	COORD Current = Left_top; Current.Y += row_index; 
	SetConsoleCursorPosition(hConsole, Current);
}

void Cframe::Erase() const
{
	SelectObject( hDC, Erase_Pen );
	//������� ��� ���������� �����
	Rectangle(hDC, margin_left, margin_top, width + margin_left, height + margin_top); 
}

void Cframe::ClearRow(const uc row_index) const
{
	SetCursorToRow(row_index);
	for(uc i = 0; i < width / 8; i++) cout<<' ';
}