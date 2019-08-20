#include <iostream>
#include "Product.h"
#include "Store.h"

using namespace std;

int main() 
{
	//the menu
	std::cout << "A          Add new product" 
		<< std::endl;
	std::cout << "X          Delete product"
		<< std::endl;
	std::cout << "C          Change product"
		<< std::endl;
	std::cout << "D          Display products"
		<< std::endl;
	std::cout << "Q          Quit" << std::endl;

	Store s;

	//a character used to determine the user's wish
	char letter;

	//an endless cycle which is stopped only when the user enters the character 'Q'
	while (true)
	{
		cin >> letter;

		//checking the input and from it determine in which case we will go toS
		switch (letter)
		{
			case 'A':
			{
				char* brand = new char[30];
				cout << "brand:";
				cin.ignore();
				cin.getline(brand, 30);

				char* model = new char[30];
				cout << "model:";
				cin.getline(model, 30);

				double price;
				cout << "price:";
				cin >> price;
				cin.ignore();

				unsigned int count;
				cout << "count:";
				cin >> count;
				cin.ignore();

				unsigned int storage;
				cout << "storage:";
				cin >> storage;
				cin.ignore();

				unsigned int RAM;
				cout << "RAM:";
				cin >> RAM;
				cin.ignore();

				char* processor = new char[30];
				cout << "processor:";
				cin.getline(processor, 30);

				Product p(brand, model, price, count, storage, RAM, processor);
				s.addProduct(p);
				break;
			}
			case 'X':
			{
				int index;
				cout << "Which product do you want to remove?" << endl;
				cin >> index;
				s.removeProduct(index - 1);
				break;
			}
			case 'C':
			{
				int index;
				cout << "Which product do you want to change?" << endl;
				cin >> index;
				cin.ignore();

				char* brand = new char[30];
				cout << "brand:";
				cin.getline(brand, 30);

				char* model = new char[30];
				cout << "model:";
				cin.getline(model, 30);

				double price;
				cout << "price:";
				cin >> price;
				cin.ignore();

				unsigned int count;
				cout << "count:";
				cin >> count;
				cin.ignore();

				unsigned int storage;
				cout << "storage:";
				cin >> storage;
				cin.ignore();

				unsigned int RAM;
				cout << "RAM:";
				cin >> RAM;
				cin.ignore();

				char* processor = new char[30];
				cout << "processor:";
				cin.getline(processor, 30);

				Product p(brand, model, price, count, storage, RAM, processor);

				s.changeProduct(index - 1, p);
				delete[] brand;
				delete[] model;
				delete[] processor;
				break;
			}
			case 'D':
			{
				s.printStore();
				break;
			}
			case 'Q':
			{
				cout << "Exiting...";

				//a variable which purpose is only to hold the console
				int x;
				cin >> x;

				return 0;
			}
			default:
			{
				break;
			}
		}
	}
}