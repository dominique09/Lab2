#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_


class DynamicArray
{

public:
	DynamicArray();
	unsigned int getCapacite() const;
	const int getElement(unsigned int _index) const;

private:
	unsigned int capacite;
	int * tabElements;
};


#endif //DYNAMICARRAY_H_