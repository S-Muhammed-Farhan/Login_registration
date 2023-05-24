#include<bits/stdc++.h>
#include<fstream>
#include<stdlib.h>
using namespace std;

void login();
void registration();
void forgot();


int main()
{
	int choice;
	cout<<"\n\n";
	cout<<"\t\t_____________________________________________________\n\n";
	cout<<"\t\t              Welcome to Login page                  \n\n";
	cout<<"\t\t______________________MENU___________________________\n\n";
	cout<<"\n\n";
	cout<<"\t\t  Press 1 to LOGIN       "<<endl;
	cout<<"\t\t  Press 2 to REGISTER       "<<endl;
	cout<<"\t\t  Press 3 to if you forgot PASSWORD       "<<endl;
	cout<<"\t\t  Press 4 to EXIT       "<<endl;
	cout<<"\n";
	cout<<"\t\t\t  Please enter your choice : ";
	cin>>choice;
	cout<<endl;
	
	switch(choice)
	{
		case 1:
			login();
			break;
		case 2:
			 registration();
			 break;
		case 3:
			forgot();
			break;
		case 4:
			cout<<"\t\t\t  Thank You ! \n\n";
			break;
		default:
			system("CLS");            /* system(cls) clears the screen*/
			cout<<"\t\t\t Option not found \n\n"<<endl;
			main();
	}
	
}

void login()
{
	int count;
	string userId,password,id,pass;
	system("CLS");
	cout<<"\t\t\t Please enter the username and password : "<<endl;
	cout<<"\t\t\t  USERNAME : ";
	cin>>userId;
	cout<<"\t\t\t  PASSWORD : ";
	cin>>password;
	
	ifstream input("records.txt");   /* if stream will check if the login info exists or not*/
	
	while(input>>id>>pass)  /*here we are reading the id and pass*//*then check inside the record*/
	{
		if(id==userId && pass==password)
		{
			count=1;
			system("CLS");
		}
	}
	input.close();  /*this is to close the file*/
	
	if(count==1)
	{
		cout<<" "<<userId<<"\n Login Successful \n";
		cout<<" Thanks for logging in \n";
		main();
	}
	else
	{
		cout<<"\n Login Error \n Please check your username and password\n"<<endl;
		main();
	}
}

void registration()
{
	string ruserId,rpassword,rid,rpass;   /*r=registration* so ruserId is registration userid*/
	system("CLS");
	cout<<"\t\t\t Enter the username : ";
	cin>>ruserId;
	cout<<"\t\t\t Enter the password : ";
	cin>>rpassword;
	
	ofstream f1("records.txt",ios::app);  /*app mode ,ofstream writes ,iftream reads , f1 object name*/
	f1<<ruserId<<' '<<rpassword<<endl;  /*we need some space b/w userid and password so ' ' */
	system("CLS");
	cout<<"\n\t\t\t Registration Successful !\n";
	main();
}

void forgot()
{
	int option;
	system("CLS");
	cout<<"\t\t\t Press 1 to search your Id by username "<<endl;
	cout<<"\t\t\t Press 2 to go back to main menu "<<endl;
	cout<<"\n"<<endl;
	cout<<"\t\t\t Enter your choice : ";
	cin>>option;
	
	switch(option)
	{
		case 1:
		{
			int count=0;
			string suserId,sId,spass,sm;
			cout<<"Enter username :";
			cin>>suserId;
			
			ifstream f2("records.txt");
			while(f2>>sId>>spass)
			{
				if(sId==suserId)
				{
					count=1;
					cout<<"\n\nYour password is : "<<spass<<endl;
				}
			}
			f2.close();
			if(count==1 )
			{
				cout<<"\n\nPlease enter your username and the password given above to login \n"<<endl;
				main();
			}
			else
			{
				cout<<"\n\t Sorry this account does not exist in database \n";
				main();
			}
			break;
		}
		case 2:
			{
				main();
			}
		default:
			{
				cout<<"\t\t\t Wrong choice! Please try again"<<endl;
				forgot();
			}
	}
}