#include "cshape_abstract.h"

void Cshape::Rotate()
{
	bool **newshape = new bool*[width]; //���������� �������
		
	for(uc i = 0; i < width; i++) //������� �� 90 ��������
	{
		newshape[i] = new bool[height];
		for(uc j = 0; j < height; j++) newshape[i][j] = body[height - j - 1][i];
	}
	
	for(uc i = 0; i < height; i++) delete [] body[i];

	swap(width, height);
	body = newshape;
}