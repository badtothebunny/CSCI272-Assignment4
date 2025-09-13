//This program deals with accounts for Guardian Bank. It can read from files,
//debit and credit money, search for existing accounts, and displays information.
//This program utilizes classes.
//Programmer: Maria Psomas
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Date.h" //Here I am including the Date class.
#include "SavAcct.h" //Here is my SavAcct class.
using namespace std;
int main(int argc, char** argv) {
	float interest,pay;
	int i=0,cnt,j=0,option;
	string account;
	SavAcct users[20]; //Here I am creating an array of the SavAcct class.
	ifstream accountfile; //Declaring a file to read from.
	accountfile.open("accounts.txt",ios::in);
	if(!accountfile)
	{		
		cout<<"Unable to open accounts file.";
		return 0;
	}
	while (i<20 && accountfile.peek()!= EOF)//The conditions here is for when it
	{	//reaches either max data for the array or reaches End Of File.
		users[i].readSavAcct(accountfile); //sending file to the read function.
		i++; //Here I increment i by 1 for each data read.
	}
	cnt=i-1; //After while loop ends, i will contain one more than the actual count.
	//As per the instructions, I will now add 3.5% annual interest rate for one month. 
	//This means after finding 3.5% interest rate, I will divide that by 12 and add it.
	for (i=0;i<cnt;i++)
	{
		interest=(users[i].getBalance()*0.035)/12; //Recall that 3.5% = 0.035 
		users[i].debit(interest); //Debit member function subtracts from the balance.
	}
	cout<<"Welcome to Guardian Bank's database. Please enter the account number: "<<endl;
	cin>>account;
	while (j<cnt && users[j].getAcctnumber() != account)
		j++;
	if (j==cnt)
		cout<<endl<<"Account was not found."<<endl;
	else
		{	
			cout<<"Account was found.Choose one of the following options: "<<endl
				<<"1.Credit money"<<endl<<"2.Debit money"<<endl<<"3.Display account info"<<endl
				<<"4.End program."<<endl;
			cin>>option; //Here I allow the user to choose what to do next.
			if (option == 1)
				{	
					cout<<"Enter amount of money"<<endl;
					cin>>pay;
					users[j].credit(pay);
					users[j].displaySavAcct();
				}
			else if (option == 2)
				{
				cout<<"Enter amount of money"<<endl;
				cin>>pay;
				users[j].debit(pay);
				users[j].displaySavAcct();
				}
			else if (option == 3)
				users[j].displaySavAcct();
			else if (option ==4)
				{
					cout<<"Thank you for using this program.";
					return 0;
				}
			else 
				{
					cout<<"Invalid option";
					return 0;
				}
		}
	return 0;
}
