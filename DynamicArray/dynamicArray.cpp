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

DynamicArray::DynamicArray(const DynamicArray & _oldArray)
{
	capacite = _oldArray.getCapacite();
	tabElements = new int[capacite];

	for (unsigned int i = 0; i < capacite; i++)
	{
		tabElements[i] = _oldArray.getElement(i);
	}
}

DynamicArray::~DynamicArray()
{
	delete tabElements;
}

void DynamicArray::operator=(const DynamicArray& _oldArray)
{
	this->setCapacite(_oldArray.getCapacite());

	for (unsigned int i = 0; i < capacite; i++)
	{
		tabElements[i] = _oldArray.getElement(i);
	}
}

bool DynamicArray::operator==(const DynamicArray& _compareArray) const
{
	bool equals = false;

	if (this->capacite == _compareArray.getCapacite())
	{
		for (unsigned int i = 0; i < capacite; i++)
		{
			if (tabElements[i] == _compareArray.getElement(i))
			{
				equals = true;
			}
			else
			{
				return false;
			}
		}
	}
	else
	{
		equals = false;
	}

	return equals;
}

void DynamicArray::operator+=(const DynamicArray& _secondArray)
{
	if (!(*this == _secondArray))
	{
		for (unsigned int i = 0; i < _secondArray.getCapacite(); i++)
		{
			this->setElement(capacite, _secondArray.getElement(i));
		}
	}
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
	if (_capacite < 1) throw std::invalid_argument("Le tableau ne peut pas être vide");

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