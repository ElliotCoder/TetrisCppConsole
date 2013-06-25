#pragma once
#ifndef CINTERFACE_H
#define CINTERFACE_H

#include "cframe.h"
#include "cmatrix.h"
#include "shapes_all.h"
#include <conio.h>
#include <iostream>
using namespace std;

class CGameProcess
{
	us score; //����
	Cmatrix *field; //����
	HDC hDC;
	HPEN Edge_Pen; 
	HPEN Erase_Pen;
	Cframe *ScoreTable, *Glass, *IngameMenu, *SaveMenu, MatrixCreationDialog, Menu, About, LoadMenu; 

public:
	CGameProcess(); //�����������
	
#pragma region UI
	void MainMenu(); //������� ����
	void IngameOptions(); //������� ����
	void StartGame(); //������ ����
	void NoCursor() const; //������ ������
	void AboutInfo(); //��� ���������
	void DrawField() const; //���������� ���� ����
	void SetScores() const; //�������� ����
#pragma endregion
	
#pragma region MatrixProcessing
	void CreateMatrix(); //������� �������
	//�������� ����������� �������� ������ �����
	bool FigureLeftMoveCheck(Cshape *Random, const uc &ins_y, const uc &ins_x) const;
	//�������� ����������� �������� ������ ������
	bool FigureRightMoveCheck(Cshape *Random, const uc &ins_y, const uc &ins_x) const; 
	void FigureErase(Cshape *Random, const uc &ins_y, const uc &ins_x); //�������� ������
	void FigureInsert(Cshape *Random, const uc &ins_y, const uc &ins_x); //������� ������
	//������� ������
	bool FigureRotate(Cmatrix *field, Cshape *Random, const uc &ins_y, const uc &ins_x); 
	//�������� �� ������������ ������ � ������
	bool FigureStopCheck(Cshape *Random, const uc &ins_y, const uc &ins_x) const; 
	Cshape *SetRandomShape() const; //������� ��������� ������
	bool FigureFall(); //������� ������
	void MatrixEraseRow(const uc &row_index); //�������� ������ �� �������
	void FieldCheck(); //�������� ���� �� ������������ ������ ��� ������������
	void GameOver() { MainMenu(); }
#pragma endregion

#pragma region Files
	void SaveToFile();
	void LoadFromFile();
#pragma endregion
};

#endif //CINTERFACE H