//Square Ч квадрат, €кий характеризуЇтьс€ координатами л≥вого верхнього кута ≥ довжиною сторони;
#pragma once
#include"Shape.h"

class Square : public Shape
{
	int x;
	int y;
	int side;
public:
	Square(int _x, int _y, int _side) : x(_x), y(_y), side(_side) {}
	void Show() override {cout << endl << "Square: Left top corner (x = " << x << ", y = " << y << "), side length = " << side;}
	void Save(fstream& file_) override;	//  запись файла в режиме бинарном
	void Load(fstream& file_) override;	//  чтение файла в режиме бинарном
};
