#include "Admin.h"

Admin::Admin()
{
	adminId = NULL;
	email = "";
	password = "";
	restaurentid = NULL;
}

Admin::Admin(int adminID, string EmailAddress, string pwd, int restaurtentID)
{
	adminId = adminID;
	email = EmailAddress;
	hashValue = hashing(email);
	lengthUsername = viewEmailLength();
	password = pwd;
	restaurentid = restaurtentID;
}

Admin::~Admin()
{
	adminId = NULL;
	email = "";
	password = "";
	restaurentid = NULL;
}

int Admin::hashing(string str) // since it only looking at each letter it does no comparison hence O(1)
{
	int hash = 0;

	for (char c : str)
	{
		int ascii = static_cast<int>(c);
		hash = hash + ascii;
	}


	return hash % 255;
}

void Admin::viewOrders(int rId)
{
	cout << "Work in Progress" << endl;
}

string Admin::viewEmailUserName()
{
	string UserName = "";
	for (char item : email)
	{
		if (item == '@')
		{
			break;
		}
		UserName += item;
	}

	return UserName;
}

int Admin::viewEmailLength()
{
	string str = viewEmailUserName();
	int length = 0;
	for (char c : str)
	{
		length++;
	}

	return length;
}

int updateStatus(int orderId)
{
	return -1; // work in progress
}

void Admin::viewOrderDetails(int restaurentId, int orderID)
{
	cout << "Work in progress" << endl;
}