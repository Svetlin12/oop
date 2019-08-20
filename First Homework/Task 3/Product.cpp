#include "Product.h"
#include <iostream>

//sets the static variable SKU to 0
int Product::SKU = 0;

//default constructor
Product::Product()
{
	incerementSKU();
	setBrand("Default");
	setModel("Default");
	setPrice(0);
	setCount(0);
	setStorage(0);
	setRAM(0);
	setProcessor("Default");
}

//constructor with parameters
Product::Product(const char * brand, const char * model, double price, unsigned int count, 
	unsigned int storage, unsigned int RAM, const char * processor)
{
	incerementSKU();
	setBrand(brand);
	setModel(model);
	setPrice(price);
	setCount(count);
	setStorage(storage);
	setRAM(RAM);
	setProcessor(processor); 
}

//copy constructor
Product::Product(const Product & p)
{
	incerementSKU();
	setBrand(p.getBrand());
	setModel(p.getModel());
	setPrice(p.getPrice());
	setCount(p.getCount());
	setStorage(p.getStorage());
	setRAM(p.getRAM());
	setProcessor(p.getProcessor());
}

//destructor
Product::~Product()
{ 
	SKU--;
	delete[] brand;
	delete[] model;
	delete[] processor;
}

//gets currentSKU
int Product::getSKU() const
{
	return this->currentSKU;
}

//sets currentSKU
void Product::setSKU(int currentSKU)
{
	this->currentSKU = currentSKU;
}

//sets current SKU to SKU and then increments SKU 
void Product::incerementSKU()
{
	this->currentSKU = SKU;
	SKU++;
}

//sets brand
void Product::setBrand(const char * brand)
{
	if (this->brand != nullptr) delete[] this->brand;
	this->brand = new char[strlen(brand) + 1];
	strcpy_s(this->brand, strlen(brand) + 1, brand);
}

//gets brand
char * Product::getBrand() const
{
	return this->brand;
}

//sets model
void Product::setModel(const char * model)
{
	if (this->model != nullptr) delete[] this->model;
	this->model = new char[strlen(model) + 1];
	strcpy_s(this->model, strlen(model) + 1, model);
}

//gets model
char * Product::getModel() const
{
	return this->model;
}

//sets price
void Product::setPrice(double price)
{
	this->price = price;
}

//gets price
double Product::getPrice() const
{
	return this->price;
}

//sets count
void Product::setCount(unsigned int count)
{
	this->count = count;
}

//gets count
unsigned int Product::getCount() const
{
	return this->count;
}

//sets storage
void Product::setStorage(unsigned int storage)
{
	this->storage = storage;
}

//gets storage
unsigned int Product::getStorage() const
{
	return this->storage;
}

//sets RAM
void Product::setRAM(unsigned int RAM)
{
	this->RAM = RAM;
}

//gets RAM
unsigned int Product::getRAM() const
{
	return this->RAM;
}

//sets processor
void Product::setProcessor(const char * processor)
{
	if (this->processor != nullptr) delete[] this->processor;
	this->processor = new char[strlen(processor) + 1];
	strcpy_s(this->processor, strlen(processor) + 1, processor);
}

//gets processor
char * Product::getProcessor() const
{
	return this->processor;
}

//prints the characteristics of the laptop
void Product::print() const
{
	std::cout << "SKU: " << getSKU() << std::endl << "brand: " << getBrand() << std::endl << "model: " << getModel() << std::endl
		<< "price: " << getPrice() << std::endl << "count: " << getCount() << std::endl << "storage: " << getStorage()
		<< std::endl << "RAM: " << getRAM() << std::endl << "processor: " << getProcessor() << std::endl;
}