//Circle � ���� �� �������� ������������ ������ � �������;
#pragma once
#include"Shape.h"

class Circle : public Shape
{
	int x, y, r;

public:
	Circle(int _x, int _y, int _r) : x(_x), y(_y), r(_r) {}
	void Show() override { cout << endl << "Circle: (x = " << x << ", y = " << y << ") with radius = " << r; }
	void Save(fstream& file_) override;//  ������ ����� � ������ ��������
	void Load(fstream& file_) override;//  ������ ����� � ������ ��������
};