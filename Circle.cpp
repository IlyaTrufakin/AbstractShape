//Circle � ���� �� �������� ������������ ������ � �������;
#pragma once
#include"Circle.h"

//  ������ ����� � ������ ��������
void Circle::Save(fstream& file_)
{
	if (!file_)
	{
		cout << endl << "Error! The file by Circle object is not open!";
		return;
	}
	cout << endl << "Circle object was Saved!";
	file_.write((char*)this, sizeof(Circle));
}


//  ������ ����� � ������ ��������
void Circle::Load(fstream& file_)
{
	if (!file_)
	{
		cout << endl << "Error! The file by Circle object is not open!";
		return;
	}

	if (file_.read((char*)this, sizeof(Circle)))
		cout << endl << "Circle object was read!";
	else
		cout << endl << "Error while reading file!";
}