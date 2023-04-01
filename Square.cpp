//Square Ч квадрат, €кий характеризуЇтьс€ координатами л≥вого верхнього кута ≥ довжиною сторони;
#pragma once
#include"Square.h"


	//  запись файла в режиме бинарном
void Square::Save(fstream& file_)
{
	if (!file_)
	{
		cout << endl << "Error! The file by Square object is not open!";
		return;
	}
	cout << endl << "Square object was Saved!";
	file_.write((char*)this, sizeof(Square));
}


//  чтение файла в режиме бинарном
void Square::Load(fstream& file_)
{
	if (!file_)
	{
		cout << endl << "Error! The file by Square object is not open!";
		return;
	}

	if (file_.read((char*)this, sizeof(Square)))
		cout << endl << "Square object was read!";
	else
		cout << endl << "Error while reading file!";
}