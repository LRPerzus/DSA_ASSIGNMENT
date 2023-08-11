#pragma once
#include <iostream>
#include <string>
using namespace std;

class Admin
{
private:
	int adminId;
	string email;
	string password;
	int restaurentid;

public:

	int hashValue;
	int lengthUsername;

	Admin();

	Admin(int adminID, string EmailAddress, string pwd, int restaurtentID);

	~Admin();

	int hashing(string username);

	void viewOrders(int restaurentId);

	string viewEmailUserName();

	int viewEmailLength();

	int updateStauts(int orderId);

	void viewOrderDetails(int restaurentId, int orderId);


};

