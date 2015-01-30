#include "dynamicArray.h"

DynamicArray::DynamicArray()
{
	capacite = 100;
	tabElements = new int[100]{0};
}

DynamicArray::DynamicArray(unsigned int _capacite)
{
	capacite = _capacite;
	tabElements = new int[capacite]{0};
}

int DynamicArray::getCapacite() const
{
	return capacite;
}

const int DynamicArray::getElement(unsigned int _index) const
{
	return tabElements[_index];
}

void DynamicArray::setElement(const unsigned int _index, const int _valeur)
{
	tabElements[_index] = _valeur;
}

void DynamicArray::setCapacite(const unsigned int _capacite)
{
	int * tempTabElement = new int[_capacite];
	for (unsigned int i = 0; i < _capacite; i++)
	{
		if (i < capacite)
		{
			tempTabElement[i] = tabElements[i];
		}
		else
		{
			tempTabElement[i] = 0;
		}
	}

	capacite = _capacite;

	delete tabElements;
	tabElements = tempTabElement;
}