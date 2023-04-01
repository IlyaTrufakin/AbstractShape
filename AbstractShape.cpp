//—твор≥ть абстрактний клас Shape дл€ малюванн€ плоских ф≥гур.¬изначте в≥ртуальн≥ методи :
//Show() Ч виведенн€ на екран ≥нформац≥њ про ф≥гуру,
//Save() Ч збереженн€ ф≥гури в файл,
//Load() Ч зчитуванн€ ф≥гури з файлу.
//¬изначте пох≥дн≥ класи:
//Square Ч квадрат, €кий характеризуЇтьс€ координатами л≥вого верхнього кута ≥ довжиною сторони;
//Rectangle Ч пр€мокутник ≥з заданими координатами верхнього л≥вого кута ≥ розм≥рами;
//Circle Ч коло ≥з заданими координатами центра ≥ рад≥усом;
//Ellipse Ч ел≥пс з заданими координатами верхнього кута описаного навколо нього пр€мокутника з≥ сторонами, паралельними ос€м координат, ≥ розм≥рами цього пр€мокутника.
//—твор≥ть масив ф≥гур, збереж≥ть ф≥гури в файл, завантажте в ≥нший масив ≥ вивед≥ть на екран ≥нформац≥ю про кожну з ф≥гур.


// !!! в программе используетс€ фиксированное им€ файла, поэтому дл€ его открыти€ и закрыти€ € применил паттерн ќƒ»Ќќ„ ј в основном классе, обеспечивающее монопольный доступ.
#include <iostream>
#include"Shape.h"
#include"Circle.h"
#include"Rectangle.h"
#include"Square.h"
#include "Ellipse.h"
using namespace std;
constexpr auto NUM = 4; // кол-во фигур в массиве
constexpr const char* FILENAME = "shapes.txt"; // им€ файла дл€ сохранени€ и чтени€ массива фигур


class ShapeLibrary // ќсновной класс, осуществл€ющий доступ к файлу 
{
private:
	static ShapeLibrary* shapeLibrary_;
	string fileName;
	fstream file;

	ShapeLibrary(const ShapeLibrary& otherObject) = delete; // запрещаем копирование
	ShapeLibrary& operator=(const ShapeLibrary& otherObject) = delete; // запрещаем присваивание
	ShapeLibrary(const string& filename_) : fileName(filename_), file(fileName, fstream::binary | fstream::out | fstream::trunc) //конструктор -  создаем файл, или очищаем имеющийс€
	{
		cout << endl << "Constructor ShapeLibrary - " << fileName << endl;
		if (!file.is_open())
		{
			cerr << "Failed to open file: " << fileName << endl;
			return;
		}
		file.close();
		cout << "File ready to work: " << fileName << endl;
	}


public:
	static ShapeLibrary& getInstance(const string& filename) // статический метод создани€ одного экземпл€ра класса
	{
		static ShapeLibrary shapeLibrary_(filename);
		return shapeLibrary_;
	}

	~ShapeLibrary()
	{
		cout << endl << "Destructor ShapeLibrary" << endl;
		if (file.is_open())
		{
			file.close();
		}
	}


	void Show(Shape* obj[], unsigned number) // метод печати массива объектов
	{
		for (size_t i = 0; i < number; i++)
			obj[i]->Show();
	}


	void writeObject(Shape* obj[], unsigned number) // метод записи в файл массива объектов
	{
		file.open(fileName, fstream::binary | fstream::out);
		if (!file.is_open())
		{
			cerr << "Failed to open file for writing: " << fileName << endl;
			return;
		}

		for (size_t i = 0; i < number; i++)
			obj[i]->Save(file);
		file.close();
		cout << endl << "file was written - " << fileName << endl;
	}


	bool readObject(Shape* obj[], unsigned number)// метод чтени€ из файла массива объектов (тип считываемого объекта определ€етс€ типом указател€ в массиве)
	{
		file.open(fileName, fstream::binary | fstream::in);
		if (!file.is_open())
		{
			cerr << "Failed to open file for reading: " << fileName << endl;
			return false;
		}
		cout << endl << endl << "File is open for reading...";
		for (size_t i = 0; i < number; i++)
			obj[i]->Load(file);

		file.close();
		cout << endl << "file was read - " << fileName << endl;
		return true;
	}
};




int main()
{
	ShapeLibrary& myShapeLibrary = ShapeLibrary::getInstance(FILENAME); // создание единого объекта

	Shape* shapes1[NUM] = // создание массива фигур  (N1)
	{
		new Square(10, 10, 50),
		new Rectangle(20, 30, 60, 40),
		new Circle(100, 100, 30),
		new Ellipse(200, 200, 80,40)
	};


	Shape* shapes2[NUM] = // создание массива фигур  (N2)
	{
		new Square(30, 30, 30),
		new Rectangle(100, 100, 10, 10),
		new Circle(20, 50, 100),
		new Ellipse(30, 60, 100,50)
	};

	myShapeLibrary.Show(shapes1, NUM);  // печать массива фигур  (N1)
	cout << endl << "_____________________________________________________________________________Array N1 " << endl;
	myShapeLibrary.Show(shapes2, NUM);  // печать массива фигур  (N2)
	cout << endl << "_____________________________________________________________________________Array N2 " << endl;
	myShapeLibrary.writeObject(shapes1, NUM);  // запись массива фигур  (N1) в файл
	myShapeLibrary.readObject(shapes2, NUM);  // чтение массива фигур  (N1) из файла в массив фигур  (N2)
	myShapeLibrary.Show(shapes2, NUM);  // печать массива фигур  (N2) - с измененными значени€ми (копи€ массиваN1)
	cout << endl << "_____________________________________________________________________________Array N2 " << endl;
	return 0;
}