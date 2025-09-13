#include "SavAcct.h"
//Declaration section- written by Maria Psomas 
SavAcct::SavAcct()	//Default constructor initializes 
	{				//everything with 0.
		name=" ";
		acctnumber=" ";
		balance=0.0;
		opened=Date(0,0,0);//Date is initalized with 0/0/0
	}
SavAcct::SavAcct(string name1,string num1,float bal1,Date &d1)
	{	//Assignment constructor.
		name=name1;
		acctnumber=num1;
		balance=bal1;
		opened.copyDate(d1); //Since this project was assigneed before
	}		//we learned operator overloading, I am using copydate function here.
string SavAcct::getName()//Now I am writing the get-individual-variables 
	{				//member functions, starting with the name variable.
		return name;
	}
string SavAcct::getAcctnumber()
	{
		return acctnumber;
	}
float SavAcct::getBalance()
	{
		return balance;
	}
Date SavAcct::getSavAcctDate()
	{
		return opened;
	}
void SavAcct::getSavAcct()
	{	//I wanted to make this easier for the user by having them type one thing at a time.
		cout<<"Please enter the following data: "<<endl<<"Name of the account owner: ";
		cin>>name;
		cout<<endl<<"Account number: ";
		cin>>acctnumber;
		cout<<endl<<"The current balance: ";
		cin>>balance;
		cout<<"And the date it was opened."<<endl;
		opened.getDate();	//Once again, I will use a member function here to get the date since
	}			    	//We didn't learn operator overloading until recently. 
void SavAcct::setSavAcct(string name2,string num2,float bal2,Date &d2)
	{	//Our set function.
		name=name2;
		acctnumber=num2;
		balance=bal2;
		opened.copyDate(d2);
	}
void SavAcct::displaySavAcct()//Our display function 
	{	//NOTE TO SELF: use iomannip library to make a nice table.
		cout<<"Account Name"<<setw(20)<<" Account Number"<<setw(10)<<"Balance"<<setw(30)<<"Date Account was opened"<<endl;
		cout<<name<<setw(20)<<acctnumber<<setw(17)<<balance<<setw(15);
		opened.displayDate();
	}
void SavAcct::readSavAcct (ifstream &str1) //Our function to read a file.
	{
		str1 >> name >> acctnumber >> balance;
		opened.readDate(str1);
	}
void SavAcct::credit(float add)
	{
		balance=balance+add;
	}
void SavAcct::debit(float subtract)
	{
		balance=balance-subtract;
	}
