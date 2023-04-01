//Ellipse � ���� � �������� ������������ ��������� ���� ��������� ������� ����� ������������ � ���������, ������������ ���� ���������, � �������� ����� ������������.
#pragma once
#include"Shape.h"

class Ellipse : public Shape
{
	int x, y, width, height;

public:
	Ellipse(int _x, int _y, int _width, int _height) : x(_x), y(_y), width(_width), height(_height) {}
	void Show() override { cout << endl << "Ellipse: Left top corner (" << x << ", " << y << ") with width = " << width << " and height = " << height; }
	void Save(fstream& file_) override;//  ������ ����� � ������ ��������
	void Load(fstream& file_) override;//  ������ ����� � ������ ��������
};



