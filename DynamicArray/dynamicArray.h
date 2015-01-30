#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_


class DynamicArray
{

public:
	DynamicArray();
	DynamicArray(unsigned int _capacite);
	DynamicArray(const DynamicArray & _oldArray);
	~DynamicArray();
	int getCapacite() const;
	const int getElement(unsigned int _index) const;
	void setElement(const unsigned int _index, const int _valeur);
	void setCapacite(const unsigned int _capacite);

private:
	unsigned int capacite;
	int * tabElements;
};


#endif //DYNAMICARRAY_H_