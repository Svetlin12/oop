#include <iostream>
#include "Store.h"
#include "Product.h"

//destructor
Store::~Store()
{
	for (int i = 0; i < getSize(); i++)
	{
		delete products[i];
	}

	delete[] products;
}

//increases the size of the products array
void Store::increaseSize()
{
	this->size++;
}

//decreases the size of the products array
void Store::decreaseSize()
{
	if (getSize() > 0)
	{
		this->size--;
	}
}

//increases the cap of the products array
void Store::increaseStoreCount()
{
	if (getStoreCount() == 0)
	{
		this->storeCount = 2;
	}
	else
	{
		this->storeCount *= 2;
	}
}

//the function first increases the cap of the array by first using the incremention function above and then
//coppies all the elements of the old array to the new one which has double the size of the previous one
void Store::resize()
{
	increaseStoreCount();
	Product** newProducts = new Product*[getStoreCount()];

	for (int i = 0; i < getSize(); i++)
	{
		newProducts[i] = products[i];
	}

	delete[] products;
	products = newProducts;
}

//gets the cap of the array
unsigned int Store::getStoreCount() const
{
	return this->storeCount;
}

//gets the size of the array
int Store::getSize() const
{
	return size;
}

//adds a product to the array if it is possible, if it is not, the function increases its cap using the resize()
//function from above
void Store::addProduct(const Product& p)
{
	if (getSize() == getStoreCount())
	{
		resize();
	}

	increaseSize();

	products[getSize() - 1] = new Product(p.getBrand(), p.getModel(), p.getPrice(), p.getCount(), p.getStorage(), p.getRAM(),
		p.getProcessor());
}

//removes a product only if the given index is less than the size of the array, otherwise doesn't do anything else
//but return false
bool Store::removeProduct(int index)
{
	if (index < getSize())
	{
		delete products[index];

		for (int i = index; i < getSize() - 1; i++)
		{
			products[i] = products[i + 1];
		}
		for (int i = 0; i < getSize(); i++)
		{
			if (i > index) 
			{
				products[i - 1]->setSKU(products[i - 1]->getSKU() - 1);
			}
		}
		decreaseSize();
		return true;
	}

	return false;
}

//using the same logic from the function above, this one changes a product onlt if the given index is correct
bool Store::changeProduct(int index, const Product& s)
{
	if (index < getSize()) {
		int currentSKU = products[index]->getSKU();
		delete products[index];
		products[index] = new Product(s.getBrand(), s.getModel(), s.getPrice(), s.getCount(), s.getStorage(),
			s.getRAM(), s.getProcessor());
		products[index]->setSKU(currentSKU);
		return true;
	}
	else return false;
}

//prints the Products using the print() function from the class Product
void Store::printStore() const
{
	if (size == 0) std::cout << "There are no products available in the store" << std::endl;
	else {
		for (int i = 0; i < size; i++)
		{
			products[i]->print();
			std::cout << std::endl;
		}
	}
}
