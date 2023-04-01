//Circle Ч коло ≥з заданими координатами центра ≥ рад≥усом;
#pragma once
#include"Shape.h"

class Circle : public Shape
{
	int x, y, r;

public:
	Circle(int _x, int _y, int _r) : x(_x), y(_y), r(_r) {}
	void Show() override { cout << endl << "Circle: (x = " << x << ", y = " << y << ") with radius = " << r; }
	void Save(fstream& file_) override;//  запись файла в режиме бинарном
	void Load(fstream& file_) override;//  чтение файла в режиме бинарном
};