#include "HashTable.h"
#include "AVLTree.h"



HashTable::HashTable()
{
	size = 0;
}

HashTable::~HashTable()
{

}

bool HashTable::add(ItemType item)
{

	int hashedindex = item.hashValue; // O(1) 
	int lengthUsername = item.lengthUsername;

	SizeTable* table = &hashes[hashedindex];
	AVLTree* itemLocation = &(table->sizeTable)[lengthUsername];


	itemLocation->insert(item);
	BinaryNode* root = itemLocation->rebalance();

	itemLocation->PrintTree();
	cout << "Rebalanced Root is: " << root << endl;
	size++;

	return true;
}

ItemType* HashTable::search(int hashed, int length, string username)
{
	if (size == 0)
	{
		return NULL;	
	}

	SizeTable* table = &hashes[hashed];
	AVLTree* itemLocation = &table->sizeTable[length];

	cout << "The Root" << endl;
	itemLocation->printRoot();

	itemLocation->PrintTree();

	return itemLocation->binarySearch(username);
}