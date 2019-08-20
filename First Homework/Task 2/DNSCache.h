#ifndef DNS_CACHE_
#define DNS_CACHE_

#include "DNSRecord.h"

class DNSCache
{
private:
	//size of the array
	unsigned int size;

	//array of DNSRecords
	DNSRecord* records = nullptr;

	//capacity of the array
	unsigned int cap;

	//increases the capacity
	void increaseCap();

	//increments the size of the array
	void incrementSize();

	//makes the array larger
	void resize();

	//checks if the array is empty
	bool isEmpty() const;

	//checks if the array is full
	bool isFull() const;

public:

	//constructors
	DNSCache();
	DNSCache(const DNSCache&);

	//operator=
	DNSCache operator= (const DNSCache&);

	//destructor
	~DNSCache();

	//getters
	unsigned int getCap() const;
	unsigned int getSize() const;

	//setters
	void setSize(unsigned int);
	void setCap(unsigned int);

	//operator[]
	DNSRecord operator[](int index) const;

	//adds a DNSRecord to the array
	void add(const DNSRecord&);

	//searches for a DNSRecord with the given domainName and returns the ipAddress of it is if found or NULL if not
	char* lookup(const char*) const;

	//deletes the DNSRecords in the DNSCache
	void flush();

	//prints the DNSCache with its DNSRecords
	void print() const;

};

#endif
