#ifndef STORE_H
#define STORE_H

#include "Product.h"

//store for laptops
class Store {
private:
	//the cap of products(the array)
	unsigned int storeCount = 0;

	//array of products
	Product** products;

	//current size of the array
	unsigned int size = 0;

	//increase size of the array
	void increaseSize();

	//decrease size of the array
	void decreaseSize();

	//increase the cap of the array
	void increaseStoreCount();

	//getter for the cap of the array
	unsigned int getStoreCount() const;
	
	//function to make the array bigger and keep it the same at the same time
	void resize();

public:
	//destructor
    ~Store();

	//getter for the size of the array
	int getSize() const;

	//function to add a product to the array
	void addProduct(const Product&);

	//function to remove a product from the array
	bool removeProduct(int);

	//function to change a certain product by the user's choice
	bool changeProduct(int, const Product&);

	//function to print all the products in the store
	void printStore() const;
};

#endif
