#pragma once
#ifndef SHAPES_ALL_H
#define SHAPES_ALL_H

#include "cshape_abstract.h"

#pragma region Tetramino_Shapes

class CTfigure: public Cshape //T - ������
{
public: CTfigure();
};

class CZfigure: public Cshape //Z - ������
{
public: CZfigure();
};

class CSfigure: public Cshape //S - ������
{
public: CSfigure();
};

class CLfigure: public Cshape //L - ������
{
public: CLfigure();
};

class CJfigure: public Cshape //J - ������
{
public: CJfigure();
};

class COfigure: public Cshape //O - ������
{
public:
	COfigure();
	void Rotate() { } //��������� ������ �� �� ������� ���������
};

class CIfigure: public Cshape //J - ������
{
public: CIfigure();
};

#pragma endregion

#endif //SHAPES_ALL_H