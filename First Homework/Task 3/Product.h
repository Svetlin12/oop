#ifndef PRODUCT_H
#define PRODUCT_H

// the product is a laptop
class Product {
private:
	//declaring a static variable in order to keep count of all the objects created
	static int SKU;

	//variable that holds the number of the stock keeping unit for each object
	int currentSKU;

	//name of the brand that produces the laptop
	char* brand = nullptr;

	//name of the mark of the laptop
	char* model = nullptr;

	//price of the laptop
	double price;

	//number of laptops of the model
	unsigned int count;

	//the storage of the model
	unsigned int storage;

	//the RAM of the model
	unsigned int RAM;

	//the processor of the model
	char* processor = nullptr;

public:

	//constructors
	Product();
	Product(const char*, const char*, double, unsigned int, unsigned int, unsigned int, const char*);
	Product(const Product&);

	//destructor
	~Product();

	//currentSKU setter and getter
	int getSKU() const;
	void setSKU(int);

	//sets current SKU to the static SKU and increments the static SKU
	void incerementSKU();

	//brand setter and getter
	void setBrand(const char*);
	char* getBrand() const;

	//model setter and getter
	void setModel(const char*);
	char* getModel() const;

	//price setter and getter
	void setPrice(double);
	double getPrice() const;

	//count setter and getter
	void setCount(unsigned int);
	unsigned int getCount() const;

	//storage setter and getter
	void setStorage(unsigned int);
	unsigned int getStorage() const;

	//RAM setter and getter
	void setRAM(unsigned int);
	unsigned int getRAM() const;

	//processor setter and getter
	void setProcessor(const char*);
	char* getProcessor() const;

	//prints the product
	void print() const;
};

#endif 
