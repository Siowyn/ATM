#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <stdlib.h>
#include <fstream>

using std::string;
using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::stringstream;
using std::stoi;

	bool login();
	void reg();
	void setvalue();
	void getvalue();
	void deposit();
	void showbalance();
	void withdraw();
	void window();
	void signout();
	int main();