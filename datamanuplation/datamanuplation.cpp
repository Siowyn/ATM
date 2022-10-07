// datamanuplation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "datamanuplation.h"
string username, password, un, pw;
string typee, usernamee, balancee;
char type[10];
int amount = 0;
int totalbalance = 0;
bool isNumberString(const std::string& s) {
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    return true;
}

void reg()
{
    string atmdata = "atmdatabase";
    string username, password;
    cout << "Account ID \n"; cin >> username;
    ofstream file;
    file.open(username +".txt");
    file << username << endl;
    file.close();
    window();
}

bool login()
{

    cout << "Username" << endl;
    cin >> username;

    ifstream read(username + ".txt");
    getline(read, un);
    if (un == username)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void signout()
{
    main();
}

void window()
{
    int choice;
    while (1) {
        cout << "Enter Your Choice\n";
        cout << "\t1. Enter name, Account "
            << "number, Account type\n";
        cout << "\t2. Account Data\n";
        cout << "\t3. Deposit Money\n";
        cout << "\t4. Show Balance\n";
        cout << "\t5. Withdraw Money\n";
        cout << "\t6. Sign Out\n";
        cout << "\t7. Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            setvalue();
            break;
        case 2:
            getvalue();
            break;
        case 3:
            deposit();
            break;
        case 4:
            showbalance();
            break;
        case 5:
            withdraw();
            break;
        case 6:
            signout();
            break;
        case 7:
            exit(1);
            break;
        default:
            cout << "\nInvalid choice\n";
        }
    }
}

int main()
{
	string choice;
	

	while (true)
	{
		cout << "Would You Like To Register or Login? \n"; cin >> choice;
		if (choice == "Register")
		{
			reg();

		}
		else if (choice == "Login")
		{
			bool status = login();

			if (!status)
			{
				cout << "Incorrect Login Details" << endl;
				main();
			}
			else
			{
				cout << "Login Successfull" << endl;
                ifstream read("c:\\" + username + ".txt");
                getline(read, un);
				window();
				return 1;
			}

		}
		else
		{
			cout << "You have to either register or login" << endl;
			main();
		}

	}

}

void setvaluefunc()
{
    ofstream file;
    file.open(username + "ATMDATA" + ".txt");
    file << username << endl;
    file << type << endl;
    file << totalbalance << endl;
    file.close();
}

void setvalue()
{
    cout << "Enter Account type\n";
    cin >> type;
    cout << "Enter Balance\n";
    cin >> totalbalance;
    setvaluefunc();
}

void getvaluefunc()
{

    ifstream read(username + "ATMDATA" + ".txt");
    getline(read, usernamee);
    getline(read, typee);
    getline(read, balancee);
}

void getvalue()
{
    getvaluefunc();
    cout << "Account ID:" << usernamee << endl;
    cout << "Account Type:" << typee << endl;
    cout << "Account Balance:" << balancee << endl;
}
void deposit()
{
    getvaluefunc();
    int depositamount;
    int tempbalanced;
    cout << "Current Balance:" << balancee << endl;
    cout << "How Much Do You Want To Deposit?\n";
    cin >> depositamount;
    int balanceinint = stoi(balancee);
    tempbalanced = balanceinint + depositamount;
    cout << "New Balance:" << tempbalanced << endl;
    totalbalance = tempbalanced;
    setvaluefunc();
}

void withdraw()
{
    getvaluefunc();
    int withdrawamount;
    int tempbalancew;
    cout << "Current Balance:" << balancee << endl;
    cout << "How Much Do You Want To Withdraw?\n";
    cin >> withdrawamount;
    int balanceinint = stoi(balancee);
    tempbalancew = balanceinint - withdrawamount;
    cout << "New Balance:" << tempbalancew << endl;
    totalbalance = tempbalancew;
    setvaluefunc();
}

void showbalance()
{
    getvaluefunc();
    cout << "Current Balance:" << balancee << endl;
}