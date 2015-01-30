#include "dynamicArray.h"
#include <stdexcept>

DynamicArray::DynamicArray()
{
	capacite = 100;
	tabElements = new int[100]{0};
}

DynamicArray::DynamicArray(unsigned int _capacite)
{
	if (_capacite < 1) throw std::invalid_argument("Le tableau ne peut pas être vide");

	capacite = _capacite;
	tabElements = new int[capacite]{0};
}

DynamicArray::~DynamicArray()
{
	delete tabElements;
}

int DynamicArray::getCapacite() const
{
	return capacite;
}

const int DynamicArray::getElement(unsigned int _index) const
{
	if (_index > 0 && _index > capacite)
		throw std::out_of_range("L'index n'est pas dans le tableau");

	return tabElements[_index];
}

void DynamicArray::setElement(const unsigned int _index, const int _valeur)
{
	if (_index >= capacite) setCapacite(_index + 1);
	tabElements[_index] = _valeur;
}

void DynamicArray::setCapacite(const unsigned int _capacite)
{
	if (_capacite < 1) throw new std::invalid_argument("Le tableau ne peut pas être vide");

	int * tempTabElement = new int[_capacite];
	for (unsigned int i = 0; i < _capacite; i++)
	{
		if (i < capacite)
			tempTabElement[i] = tabElements[i];
		else
			tempTabElement[i] = 0;
	}

	capacite = _capacite;

	delete tabElements;
	tabElements = tempTabElement;
}