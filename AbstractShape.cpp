//������� ����������� ���� Shape ��� ��������� ������� �����.�������� �������� ������ :
//Show() � ��������� �� ����� ���������� ��� ������,
//Save() � ���������� ������ � ����,
//Load() � ���������� ������ � �����.
//�������� ������ �����:
//Square � �������, ���� ��������������� ������������ ����� ��������� ���� � �������� �������;
//Rectangle � ����������� �� �������� ������������ ��������� ����� ���� � ��������;
//Circle � ���� �� �������� ������������ ������ � �������;
//Ellipse � ���� � �������� ������������ ��������� ���� ��������� ������� ����� ������������ � ���������, ������������ ���� ���������, � �������� ����� ������������.
//������� ����� �����, �������� ������ � ����, ���������� � ����� ����� � ������� �� ����� ���������� ��� ����� � �����.


// !!! � ��������� ������������ ������������� ��� �����, ������� ��� ��� �������� � �������� � �������� ������� �������� � �������� ������, �������������� ����������� ������.
#include <iostream>
#include"Shape.h"
#include"Circle.h"
#include"Rectangle.h"
#include"Square.h"
#include "Ellipse.h"
using namespace std;
constexpr auto NUM = 4; // ���-�� ����� � �������
constexpr const char* FILENAME = "shapes.txt"; // ��� ����� ��� ���������� � ������ ������� �����


class ShapeLibrary // �������� �����, �������������� ������ � ����� 
{
private:
	static ShapeLibrary* shapeLibrary_;
	string fileName;
	fstream file;

	ShapeLibrary(const ShapeLibrary& otherObject) = delete; // ��������� �����������
	ShapeLibrary& operator=(const ShapeLibrary& otherObject) = delete; // ��������� ������������
	ShapeLibrary(const string& filename_) : fileName(filename_), file(fileName, fstream::binary | fstream::out | fstream::trunc) //����������� -  ������� ����, ��� ������� ���������
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
	static ShapeLibrary& getInstance(const string& filename) // ����������� ����� �������� ������ ���������� ������
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


	void Show(Shape* obj[], unsigned number) // ����� ������ ������� ��������
	{
		for (size_t i = 0; i < number; i++)
			obj[i]->Show();
	}


	void writeObject(Shape* obj[], unsigned number) // ����� ������ � ���� ������� ��������
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


	bool readObject(Shape* obj[], unsigned number)// ����� ������ �� ����� ������� �������� (��� ������������ ������� ������������ ����� ��������� � �������)
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
	ShapeLibrary& myShapeLibrary = ShapeLibrary::getInstance(FILENAME); // �������� ������� �������

	Shape* shapes1[NUM] = // �������� ������� �����  (N1)
	{
		new Square(10, 10, 50),
		new Rectangle(20, 30, 60, 40),
		new Circle(100, 100, 30),
		new Ellipse(200, 200, 80,40)
	};


	Shape* shapes2[NUM] = // �������� ������� �����  (N2)
	{
		new Square(30, 30, 30),
		new Rectangle(100, 100, 10, 10),
		new Circle(20, 50, 100),
		new Ellipse(30, 60, 100,50)
	};

	myShapeLibrary.Show(shapes1, NUM);  // ������ ������� �����  (N1)
	cout << endl << "_____________________________________________________________________________Array N1 " << endl;
	myShapeLibrary.Show(shapes2, NUM);  // ������ ������� �����  (N2)
	cout << endl << "_____________________________________________________________________________Array N2 " << endl;
	myShapeLibrary.writeObject(shapes1, NUM);  // ������ ������� �����  (N1) � ����
	myShapeLibrary.readObject(shapes2, NUM);  // ������ ������� �����  (N1) �� ����� � ������ �����  (N2)
	myShapeLibrary.Show(shapes2, NUM);  // ������ ������� �����  (N2) - � ����������� ���������� (����� �������N1)
	cout << endl << "_____________________________________________________________________________Array N2 " << endl;
	return 0;
}