#include "DNSCache.h"
#include <iostream>

using namespace std;

void DNSCache::incrementSize()
{
	this->size++;
}

void DNSCache::increaseCap()
{
	this->cap *= 2;
}

void DNSCache::resize()
{
	increaseCap();
	DNSRecord* newRecords = new DNSRecord[getCap()];
	for (unsigned i = 0; i < getSize(); i++)
	{
		newRecords[i] = this->records[i];
	}
	delete[] records;
	this->records = newRecords;
}

bool DNSCache::isEmpty() const
{
	return size == 0;
}

bool DNSCache::isFull() const
{
	return size == cap;
}

DNSCache::DNSCache()
{
	size = 0;
	cap = 1;
	this->records = new DNSRecord[size];
}

DNSCache::DNSCache(const DNSCache & d)
{
	delete[] this->records;
	this->records = new DNSRecord[d.getSize()];
	setSize(d.getSize());
	setCap(d.getCap());
}

DNSCache DNSCache::operator=(const DNSCache & d)
{
	if (this != &d)
	{
		delete[] this->records;
		this->records = new DNSRecord[d.getSize()];
		setSize(d.getSize());
		setCap(d.getCap());
		for (int i = 0; i < getSize(); i++)
		{
			this->records[i].setDomainName(d[i].getDomainName());
			this->records[i].setIpAddress(d[i].getIpAddress());
		}
	}
	return *this;
}

DNSCache::~DNSCache()
{
	delete[] this->records;
}

void DNSCache::setCap(unsigned int cap)
{
	this->cap = cap;
}

void DNSCache::setSize(unsigned int size)
{
	this->size = size;
}

unsigned int DNSCache::getCap() const
{
	return this->cap;
}

unsigned int DNSCache::getSize() const
{
	return this->size;
}

DNSRecord DNSCache::operator[](int index) const
{
	if (index > getSize()) return DNSRecord();
	else return records[index];
}

void DNSCache::add(const DNSRecord& d)
{
	if (isFull()) resize();
	if (isEmpty()) resize();
	records[getSize()] = DNSRecord(d);
	incrementSize();
}

char * DNSCache::lookup(const char * domainName) const
{
	for (int i = 0; i < getSize(); i++)
	{
		if (strcmp(records[i].getDomainName(), domainName) == 0)
		{
			return records[i].getIpAddress();
		}
	}
	return NULL;
}

void DNSCache::flush()
{
	delete[] records;
	records = new DNSRecord[size];
}

void DNSCache::print() const
{
	for (int i = 0; i < getSize(); i++)
	{
		records[i].print();
	}
}
