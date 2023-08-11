#pragma once
#include <iostream>
#include <string>

#include "SizeTable.h"
using namespace std;

const int hashSize = 255;

typedef int	KeyType;





class HashTable
{
private:

	SizeTable hashes[hashSize];
	int size;


public:

	// constructor
	HashTable();

	//desctor
	~HashTable();

	bool add(ItemType item);

	ItemType* search(int hashed, int length, string username);




};