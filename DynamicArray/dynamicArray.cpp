#include "dynamicArray.h"

DynamicArray::DynamicArray()
{
	capacite = 100;
	tabElements = new int[100]{0};
}

unsigned int DynamicArray::getCapacite() const
{
	return capacite;
}

const int DynamicArray::getElement(unsigned int _index) const
{
	return tabElements[_index];
}

void DynamicArray::setElement(const int _index, const int _valeur)
{
	tabElements[_index] = _valeur;
}