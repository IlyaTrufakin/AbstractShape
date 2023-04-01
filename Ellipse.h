//Ellipse Ч ел≥пс з заданими координатами верхнього кута описаного навколо нього пр€мокутника з≥ сторонами, паралельними ос€м координат, ≥ розм≥рами цього пр€мокутника.
#pragma once
#include"Shape.h"

class Ellipse : public Shape
{
	int x, y, width, height;

public:
	Ellipse(int _x, int _y, int _width, int _height) : x(_x), y(_y), width(_width), height(_height) {}
	void Show() override { cout << endl << "Ellipse: Left top corner (" << x << ", " << y << ") with width = " << width << " and height = " << height; }
	void Save(fstream& file_) override;//  запись файла в режиме бинарном
	void Load(fstream& file_) override;//  чтение файла в режиме бинарном
};



