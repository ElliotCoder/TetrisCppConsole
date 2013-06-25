#pragma once
#ifndef CSHAPE_H
#define CSHAPE_H

#include "definitions.h"
#include <iostream>
using namespace std;

class Cshape //������ ����� ����������� � ���� ���������� bool - �������
{
protected:
	bool **body; //������
	uc width, height; //���������

public:
	virtual void Rotate();
	friend class CGameProcess;
	~Cshape() { for(uc i = 0; i < height; i++) delete [] body[i]; }
};

#endif //CSHAPE_H