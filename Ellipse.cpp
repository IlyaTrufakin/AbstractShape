//Ellipse Ч ел≥пс з заданими координатами верхнього кута описаного навколо нього пр€мокутника з≥ сторонами, паралельними ос€м координат, ≥ розм≥рами цього пр€мокутника.
#pragma once
#include "Ellipse.h"


//  запись файла в режиме бинарном
void Ellipse::Save(fstream& file_)
{
	if (!file_)
	{
		cout << endl << "Error! The file by Ellipse object is not open!";
		return;
	}
	cout << endl << "Ellipse object was Saved!";
	file_.write((char*)this, sizeof(Ellipse));
}


//  чтение файла в режиме бинарном
void Ellipse::Load(fstream& file_)
{
	if (!file_)
	{
		cout << endl << "Error! The file by Ellipse object is not open!";
		return;
	}

	if (file_.read((char*)this, sizeof(Ellipse)))
		cout << endl << "Ellipse object was read!";
	else
		cout << endl << "Error while reading file!";
}