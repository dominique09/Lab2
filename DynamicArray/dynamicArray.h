#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_


class DynamicArray
{

public:
	DynamicArray();
	unsigned int getCapacite() const;
	const int getElement(unsigned int _index) const;
	void setElement(const int _index, const int _valeur);

private:
	unsigned int capacite;
	int * tabElements;
};


#endif //DYNAMICARRAY_H_