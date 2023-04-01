//Rectangle Ч пр€мокутник ≥з заданими координатами верхнього л≥вого кута ≥ розм≥рами
#pragma once
#include"Rectangle.h"


//  запись файла в режиме бинарном
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


//  чтение файла в режиме бинарном
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