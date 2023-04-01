#pragma once
#include <iostream>
#include <fstream>
using namespace std;

// абстрактный класс
class Shape
{

public:
	virtual void Load(fstream& file_) = 0; // чистые виртуальные методы
	virtual void Save(fstream& file_) = 0;
	virtual void Show() = 0;
};
