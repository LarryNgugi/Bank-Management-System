#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include<stdio.h> 
//sleep 
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <cstdlib>

using namespace std;

// admin function 
void registerClient(){
	
	string newClient;
	string newPassword;
	int initialDeposit;
	
	ofstream user;
	user.open("C:\\Users\\larry\\OneDrive\\Desktop\\bank project\\userDB.txt", ios::app);
	
	cout << "Enter New client name: ";
	cin >> newClient;
							
	cout << "Enter new client password: ";
	cin >> newPassword;
							
	cout << "Enter initial deposit: ";
	cin >> initialDeposit;
	
	user << newClient << "\t\t" << newPassword << "\t\t" << initialDeposit << endl;
	
	user.close();
	
}

void adminDeposit(){
	
	string verifyName,password,name;
	int deposit,initialDeposit;
	
	ifstream user;
	user.open("C:\\Users\\larry\\OneDrive\\Desktop\\bank project\\userDB.txt", ios::app);
	
	ofstream data;
	data.open("data.txt");
				
	cout << "Enter account name: ";
	cin >> verifyName;
	
	while (user >> name >> password >> initialDeposit){
		
		if( name != verifyName){
		
			data << name << " " << password << " " << initialDeposit <<endl;
		
		}else {
			
			cout << "Enter Deposit amount: ";
			cin >> deposit;
			
			while (deposit < 0){
				
				cout << "Invalid entry."<< endl;
				
				cout << "Enter deposit amount:";
				cin >> deposit;
				
				
			}
			int currentBal = initialDeposit + deposit;
			
			data << name << " " << password << " " << currentBal <<endl;
			
			cout << "You have successfully deposited " << deposit << endl;
			cout << "Account balance: " << currentBal <<endl;
			
			Sleep(3000);
		}
		
	
	}
	user.close();
	data.close();
	remove("C:\\Users\\larry\\OneDrive\\Desktop\\bank project\\userDB.txt");
	rename("C:\\Users\\larry\\OneDrive\\Desktop\\bank project\\data.txt", "C:\\Users\\larry\\OneDrive\\Desktop\\bank project\\userDB.txt");								
	
}
void newWithdrawFunc(){
	
	string verifyName,password,name;
	int withdraw,initialDeposit;
	
	ifstream user;
	user.open("C:\\Users\\larry\\OneDrive\\Desktop\\bank project\\userDB.txt", std::ios::app);
	
	ofstream data2;
	data2.open("C:\\Users\\larry\\OneDrive\\Desktop\\bank project\\data2.txt");
				
	cout << "Enter account name: ";
	cin >> verifyName;
	
	while (user >> name >> password >> initialDeposit){
		
		if( name != verifyName){
			
			data2 << name << " " << password << " " << initialDeposit <<endl;
					
		}else {
			
			cout << "Enter withdraw amount: ";
			cin >> withdraw;
			
			while (withdraw < 0){
				
				cout << "Invalid Amount."<< endl;
				
				cout << "Enter withdraw amount:";
				cin >> withdraw;
				
			}
			while (withdraw > initialDeposit){
				
				cout << "Invalid Amount."<< endl;
				
				cout << "Enter withdraw amount:";
				cin >> withdraw;
			}
			
		
					
			int currentBal = initialDeposit - withdraw;
			
			data2 << name << " " << password << " " << currentBal <<endl;
			
			cout << "*******************************************************"<< endl;

			cout << "You have successfully withdrawn " << withdraw << endl;
			
			cout << "*******************************************************"<< endl;

			cout << "Account balance: " << currentBal <<endl;
			
			cout << "*******************************************************"<< endl;
			cout << " " << endl;

		}
		
	
	}
	
	user.close();
	data2.close();
	
	remove("C:\\Users\\larry\\OneDrive\\Desktop\\bank project\\userDB.txt");
	rename("C:\\Users\\larry\\OneDrive\\Desktop\\bank project\\data2.txt","C:\\Users\\larry\\OneDrive\\Desktop\\bank project\\userDB.txt");								
	
}


void resetPassword(){
	
	ifstream admin;
	ofstream pass;
			
	admin.open("C:\\Users\\larry\\OneDrive\\Desktop\\bank project\\admin.txt",ios::app);
	
	string adminreset,newPass,username,password;
	int check = 0;
	
	cout << "Enter old password: ";
	cin >> adminreset;
	
	while (admin >> username >> password){
		
		if (password == adminreset){
			check = 1;
		
		}		
		
	}
	admin.close();
	pass.open("C:\\Users\\larry\\OneDrive\\Desktop\\bank project\\admin.txt",ios::app);
	
	if (check == 1){
		
		cout << "Enter New password: ";
				
		int ch;
 		ch = _getch();
 		while (ch != 13){
 			newPass.push_back(ch);
 			cout << "*";
 			ch = _getch();
		 }
		cout << endl;
		
		pass << username << " " << newPass;
	}
							
	pass.close();
	
}

// users function 

void checkBal(){
	
	string name,password,amount,accName,pass;
	
	
	ifstream user;
	user.open("C:\\Users\\larry\\OneDrive\\Desktop\\bank project\\userDB.txt", ios::app);
	
	ofstream data;
	data.open("C:\\Users\\larry\\OneDrive\\Desktop\\bank project\\data.txt",ios::app);
	
	cout << "Enter account name: ";
	cin >> accName;
	
	cout << "Enter account password: ";
	cin >> pass;
	
	while(user >> name >> password >> amount){
		
		if( name != accName && password != pass){
		
			data << name << " " << password << " " << amount <<endl;
		
		}else {
			
			cout << "Your account balance is: " << amount << endl;
			
			
		}
	}
	
	
	
	data.close();
	user.close();
	remove("C:\\Users\\larry\\OneDrive\\Desktop\\bank project\\data.txt");
}

void userResetPassword(){
	
	ifstream user;	
		
	user.open("C:\\Users\\larry\\OneDrive\\Desktop\\bank project\\userDB.txt",ios::app);
	
	
	string pass,name,password,amount,newPass;
	int check = 0;
	
	cout << "Enter old password: ";
	cin >> pass;
	
	while( user >> name >> password >> amount ){
		
		if (password == pass ){
	
			check = 1;
				
		} else {
			
			check = 0;
			
		}
			
	}
	
	user.close();
		
	ofstream data;
	data.open("C:\\Users\\larry\\OneDrive\\Desktop\\bank project\\userDB.txt",ios::app);
	
	if ( check == 1){
		
		cout << "Enter New password: ";
		cin >> newPass;
		
		data << name << " " << newPass << " " << amount << endl;
	}
	
	data.close();
	
	
}


void adminSection(){
	
	ifstream admin;
	admin.open("C:\\Users\\larry\\OneDrive\\Desktop\\bank project\\admin.txt");
	
	int adminOption;
	string adminUsername,adminPassword;
	string name,pass;
	
	admin >> name;
	admin >> pass;
	
	system("cls");
	cout << "------------------------------------------------------"<< endl;
	cout << "Enter administrator username and password." << endl;
		
	cout << "Enter username: ";
	cin  >> adminUsername;
		
	cout << "Enter Password: ";
 	 	
 	int ch;
 	ch = _getch();
 	while (ch != 13){
 		adminPassword.push_back(ch);
 		cout << "*";
 		ch = _getch();
	 }
	cout << endl;
 	
		
	if (adminUsername == name && adminPassword == pass ){
			
			cout << "------------------------------------------------------"<< endl;
			cout << "Welcome" << " " << adminUsername <<endl;
			cout << "1. Deposit Money for client" << endl;
			cout << "2. Register new client." << endl;
			cout << "3. Reset your password." << endl;
					
			cout << "Enter option to proceed: ";
			cin >> adminOption;
			
			switch(adminOption){
				case 1 :
					adminDeposit();
					break;
				case 2:
					registerClient();
					break;
				case 3:
					resetPassword();
					break;
					
			}
		
	}else {
		
		cout << "Invalid Username or Password."<< endl;
		
	}
}


void normalUser(){
	string name,password,username,pass;
	int amount,option;
	
	ifstream user;
		
	user.open("C:\\Users\\larry\\OneDrive\\Desktop\\bank project\\userDB.txt",ios::app);
	
		
	cout << "Enter account name: ";
	cin >> name;
	
	cout << "Enter password: ";
	
	
	int ch;
 	ch = _getch();
 	while (ch != 13){
 		password.push_back(ch);
 		cout << "*";
 		ch = _getch();
	 }
	cout << endl;
	
	while(user >> username >> pass >> amount){
		
		if (name == username && password == pass){
			
			system("cls");			
			cout << "------------------------------------------------------"<< endl;
		
			cout << "Welcome" << " "<< username <<endl;
			
			cout << "------------------------------------------------------"<< endl;	
									
			cout << "1. Withdraw cash" << endl;
			cout << "2. Check Balance" << endl;
			cout << "3. Reset your password" << endl;
				
			cout << "Enter Option to proceed: ";
			cin >> option;
			
		
			
			cout << "------------------------------------------------------"<< endl;
			
			
		}
	}
		user.close();
		
		switch(option){
				case 1:
					newWithdrawFunc();
					break;
				
				case 2:
					checkBal();
					break;
				
				case 3:
					userResetPassword();
					break;
					
			}
		
	
}


int main(){
	
	
	
	int deposit,oldAcc;
	string adminreset,operation; 
	string newClient,accNumber;
	string newPass;
	string choose,option,adminOption;
	string username,password,adminUsername,adminPassword;
	
	
		
	bool user_validation = false;
	
	
	
	ifstream admin;
		
	admin.open("admin.txt");
	cout<< ("This\nis\na\ntest\n\n\tShe said, \"How are you?\"\n");
	cout << "************************** Welcome to E-Cash Services **************************"<< endl;
	
	cout << "1. Normal User Login"<<endl;
	cout << "2. Administrator login" << endl;
	
	cout << "Choose an option to login: ";
	cin >> choose;
	
	do {
		
		if (choose == "1")
	{
		
		cout << "------------------------------------------------------"<< endl;
		cout << "Welcome to the Normal User Login  page:"<< endl;
		cout << "------------------------------------------------------"<< endl;
		
		normalUser();	
		
	
		}else if (choose == "2"){
			
			adminSection();
			

		}else{
			cout << "Invalid Option.Kindly try again." << endl;
			break;
		
		}
		
	}while (user_validation == false);
	
	 
	return 0;
}
