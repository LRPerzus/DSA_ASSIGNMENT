#pragma once
#include <iostream>
#include <string>
#include "Admin.h"
typedef Admin ItemType;

class BinaryNode
{
public:
	ItemType item;
	BinaryNode* left;
	BinaryNode* right;
};

