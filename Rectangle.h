//Rectangle � ����������� �� �������� ������������ ��������� ����� ���� � ��������
#pragma once
#include"Shape.h"

class Rectangle : public Shape
{
	int x, y, width, height;

public:
	Rectangle(int _x, int _y, int _width, int _height) : x(_x), y(_y), width(_width), height(_height) {}
	void Show() override { cout << endl << "Rectangle: Left top corner (" << x << ", " << y << ") with width = " << width << " and height = " << height; }
	void Save(fstream& file_) override;	//  ������ ����� � ������ ��������
	void Load(fstream& file_) override;	//  ������ ����� � ������ ��������
};