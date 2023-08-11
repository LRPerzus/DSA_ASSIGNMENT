#pragma once
#include "BinaryNode.h"

using namespace std;

typedef Admin ItemType; //alr in hashtable.h

class AVLTree
{
private:
	BinaryNode* root;
public:
	

	AVLTree();

	bool isEmpty();

	ItemType* binarySearch(string username);

	ItemType* binarySearch(BinaryNode* currentNode, string user);

	void insert(ItemType user);

	void insert(BinaryNode*& root, ItemType user);

	void binaryRemove(string target);

	void binaryRemove(BinaryNode*& currentNode, string target);

	void printRoot();

	// compute the height of the binary search tree
	int getHeights();
	int getHeights(BinaryNode* t);

	// check if the binary search tree is balanced
	bool isBalanced();
	bool isBalanced(BinaryNode* t);

	//Rotations

	BinaryNode* rightRightRotate(BinaryNode*& t);
	BinaryNode* rightLeftRotate(BinaryNode*& t);

	BinaryNode* leftLeftRotate(BinaryNode*& t);
	BinaryNode* leftRightRotate(BinaryNode*& t);

	int diffInWeight(BinaryNode* t);

	BinaryNode* rebalance();
	BinaryNode* rebalance(BinaryNode*& Nnode);

	void PrintTree();

	void PrintTree(BinaryNode* r);



};
