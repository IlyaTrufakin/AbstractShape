//Rectangle � ����������� �� �������� ������������ ��������� ����� ���� � ��������
#pragma once
#include"Rectangle.h"


//  ������ ����� � ������ ��������
void Rectangle::Save(fstream& file_)
{
	if (!file_)
	{
		cout << endl << "Error! The file by Rectangle object is not open!";
		return;
	}
	cout << endl << "Rectangle object was Saved!";
	file_.write((char*)this, sizeof(Rectangle));
}


//  ������ ����� � ������ ��������
void Rectangle::Load(fstream& file_)
{
	if (!file_)
	{
		cout << endl << "Error! The file by Rectangle object is not open!";
		return;
	}

	if (file_.read((char*)this, sizeof(Rectangle)))
		cout << endl << "Rectangle object was read!";
	else
		cout << endl << "Error while reading file!";
}