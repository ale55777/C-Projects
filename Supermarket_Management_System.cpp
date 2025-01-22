#include<bits/stdc++.h>
#include<iomanip>
#include<fstream>
#include<string.h>
#include<unistd.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

using namespace std;

void admin_registration();
void customer_registration();
void staff_registration();

void login_admin();
void login_customer();
void login_staff();

void create_account_admin() ;
void create_account_customer() ;
void create_account_staff() ;

void staff_module() ;
void place_your_order();
void admin_module();
void add_product();
void check_inventory();
void check_orders();

ofstream file1 ;
ifstream file2 ;
fstream file3;

// registration type
int registration_type()
{
	system("CLS") ;
	int type ;
	cout << "\n\n\t\t =================== Welcome to Registration Module ===================" ;
	cout << "\n Choose your account type " ;
	cout << "\n  1. Admin" ;
	cout << "\n  2. Customer" ;
	cout << "\n  3. Staff" ;
	cout << "\n  4. Exit the system" ;
	cout << "\n\n  Account type: " ;
	cin >> type ;
	
	switch(type) {
		case 1: admin_registration(); break;
		case 2: customer_registration(); break;
		case 3: staff_registration(); break;
		case 4: exit(0);
		default:
			cout << "\n Invalide choice!!!" ;
			registration_type();
	}
}

// registration module for admin
void admin_registration()
{
	system("CLS") ;
	cout << "\n\n\t\t ************** Welcome to Admin Registration Module ************** " ;
	cout << "\n\n" ;
	cout << "\n Kindly create your own username and password" << endl << endl;
	
	string username, password ;
	// get the username and password
	cout << "\n Username: " ;
	cin >> username ;
	cout << "\n Password: " ;
	cin >> password ;
	
	// now open the file to save the username and password
	file1.open("C:\\Users\\MANISH\\OneDrive\\Desktop\\College\\Codespeedy\\Supermarket Management System\\admin_login.txt", ios::app|ios::binary) ;
	
	if(!file1) { cout << "\n Can not open the requested file."	;}
	else {
		cout << endl ;
		file1 << username << ":" << password << endl ;
		file1.close() ;
	}
	cout << "\n Your account has been created." << endl ;
	cout << "\n Redirecting to Admin Login module......" ;
	sleep(2) ;
	// call admin login
	login_admin();
}

void customer_registration()
{
	system("CLS") ;
	cout << "\n\n\t\t ************** Welcome to Customer Registration Module ************** " ;
	cout << "\n\n" ;
	cout << "\n Kindly create your own username and password" << endl << endl;
	
	string username, password ;
	// get the username and password
	cout << "\n Username: " ;
	cin >> username ;
	cout << "\n Password: " ;
	cin >> password ;
	
	// now open the file to save the username and password
	file1.open("C:\\Users\\MANISH\\OneDrive\\Desktop\\College\\Codespeedy\\Supermarket Management System\\customer_login.txt", ios::app|ios::binary) ;
	
	if(!file1) { cout << "\n Can not open the requested file."	;}
	else {
		cout << endl ;
		file1 << username << ":" << password << endl ;
		file1.close() ;
	}
	cout << "\n Your account has been created." << endl ;
	cout << "\n Redirecting to Customer Login module......" ;
	sleep(2) ;
	login_customer();
}

void staff_registration()
{
	system("CLS") ;
	cout << "\n\n\t\t ************** Welcome to Staff Registration Module ************** " ;
	cout << "\n\n" ;
	cout << "\n Kindly create your own username and password" << endl << endl;
	
	string username, password ;
	// get the username and password
	cout << "\n Username: " ;
	cin >> username ;
	cout << "\n Password: " ;
	cin >> password ;
	
	// now open the file to save the username and password
	file1.open("C:\\Users\\MANISH\\OneDrive\\Desktop\\College\\Codespeedy\\Supermarket Management System\\staff_login.txt", ios::app|ios::binary) ;
	
	if(!file1) { cout << "\n Can not open the requested file."	;}
	else {
		cout << endl ;
		file1 << username << ":" << password << endl ;
		file1.close() ;
	}
	cout << "\n Your account has been created." << endl ;
	cout << "\n Redirecting to Staff Login module......" ;
	sleep(2) ;
	// call staff login
	login_staff();
}

// login for admin
void login_admin() 
{
	system("CLS") ;
	cout << "\n\n\t\t ************** Admin Login Module ************** " ;
	cout << "\n\n" ;
	cout << "\n Enter your credentials to login" ;
	
	string username, password ;
	bool _log = false ;
	
	// get the username and password of the admin user
	cout << "\n\n Username: " ;
	cin >> username ;
	cout << "\n Password: " ;
	cin >> password ;
	// open the file in read mode to check the data
	file2.open("C:\\Users\\MANISH\\OneDrive\\Desktop\\College\\Codespeedy\\Supermarket Management System\\admin_login.txt", ios::in|ios::binary) ;
	if(file2.is_open()) {
		string line ;
		while(getline(file2, line)) {
			if(line == (username+":"+password)) {
				_log = true ;
				cout << "\n Logged in successfully." ;
				sleep(1);
				admin_module();
				break ;
			}
		}
		if(_log == false) {
			cout << "\n Incorrect username or password!!!" ;
			cout << "\n Or you may not have been registered into the system" ;
		}
		file2.close();
	}
}

// login for customer
void login_customer() 
{
	system("CLS") ;
	cout << "\n\n\t\t ************** Customer Login Module ************** " ;
	cout << "\n\n" ;
	cout << "\n Enter your credentials to login" ;
	
	string username, password ;
	bool _log = false ;
	
	// get the username and password of the admin user
	cout << "\n\n Username: " ;
	cin >> username ;
	cout << "\n Password: " ;
	cin >> password ;
	// open the file in read mode to check the data
	file2.open("C:\\Users\\MANISH\\OneDrive\\Desktop\\College\\Codespeedy\\Supermarket Management System\\customer_login.txt", ios::in|ios::binary) ;
	if(file2.is_open()) {
		string line ;
		while(getline(file2, line)) {
			if(line == (username+":"+password)) {
				_log = true ;
				cout << "\n Logged in successfully." ;
				sleep(1);
				place_your_order();
				break ;
			}
		}
		if(_log == false) {
			cout << "\n Incorrect username or password!!!" ;
			cout << "\n Or you may not have been registered into the system" ;
		}
		file2.close();
	}
}

// login for staff
void login_staff() 
{
	system("CLS") ;
	cout << "\n\n\t\t ************** Staff Login Module ************** " ;
	cout << "\n\n" ;
	cout << "\n Enter your credentials to login" ;
	
	string username, password ;
	bool _log = false ;
	
	// get the username and password of the admin user
	cout << "\n\n Username: " ;
	cin >> username ;
	cout << "\n Password: " ;
	cin >> password ;
	// open the file in read mode to check the data
	file2.open("C:\\Users\\MANISH\\OneDrive\\Desktop\\College\\Codespeedy\\Supermarket Management System\\staff_login.txt", ios::in|ios::binary) ;
	if(file2.is_open()) {
		string line ;
		while(getline(file2, line)) {
			if(line == (username+":"+password)) {
				_log = true ;
				cout << "\n Logged in successfully." ;
				sleep(1);
				staff_module();
				break ;
			}
		}
		if(_log == false) {
			cout << "\n Incorrect username or password!!!" ;
			cout << "\n Or you may not have been registered into the system" ;
		}
		file2.close();
	}
}

// staff_module()
void staff_module()
{
	cout << "\n \n Setting up the environment" ;
	cout << "\n Please wait......" ; 
	sleep(3); // pause for 3 seconds
	cout << "\n Your Bill Generator is ready" << endl ;
	system("CLS") ;
	cout << "\n \n \t\t ================= BILL GENERATOR ================= " ;
	// Bill generator
	int sum = 0 ;
	int arr[30] ; // store the products
	int n ; // n = no. of products customer bought
	cout << "\n\n How many products did the customer bought?  " ;
	cin >> n ;
	cout << "\n Enter the price details of the product below..." ;
	for(int i=1; i<=n; i++) {
		cout << "\n Price of product" << i << " ";
		cin >> arr[i] ;
	}
	// go for the sum
	for(int i=1; i<=n; i++) {
		sum = sum+arr[i] ;
	}
	// return the total ammount
	cout << "\n Total amount: " << sum ;
	cout << "\n Discount of: 20%" ;
	int amount, discount;
	discount = sum*0.2 ;
	amount = sum - discount ;
	cout << "\n Amount to be paid: " << amount ;
	// call the staff module if required
	char chs;
	cout << "\n\n Dou you want to use the environment more? " ;
	cin >> chs;
	if(chs == 'Y' || chs == 'y'){
		staff_module();
	} else{ exit(0);	}
}

// customer_module
void place_your_order()
{
	cout << "\n Please wait while the system is getting ready......" ;
	sleep(3) ;
	cout << "\n System is ready" ;
	sleep(1) ;
	system("CLS") ;
	cout << "\n\n\t\t  ==================== PLACE YOUR ORDER HERE ====================" ;
	cout << "\n\n\n We accept CASH ON DELIVERY" ;
	cout << "\n NOTE: Maximum 10 orders you can place at a time." ;
	string product_name, address;
	int quantity ;
	int orders ;
	cout << endl;
	cout << "\n How many orders do you want to place? ";
	cin >> orders ;
	// get the product_name and quantity
	for(int i=1; i<=orders; i++) {
		cout << "\n Product name: " ;
		cin >> product_name ;
		cout << "\n Quantity: " ;
		cin >> quantity ;
		file1.open("C:\\Users\\MANISH\\OneDrive\\Desktop\\College\\Codespeedy\\Supermarket Management System\\customers_order.txt",ios::app|ios::binary) ;
		// write in the file
		file1 << "Product: " << product_name << " " << "Quantity: "<< quantity << " " << endl;
		file1.close();
		sleep(1);
		cout << endl;
	}
	cout << "\n Mention your address: " ;
	string addr ;
	cin >> addr;
	file1.open("C:\\Users\\MANISH\\OneDrive\\Desktop\\College\\Codespeedy\\Supermarket Management System\\customers_order.txt",ios::app|ios::binary) ;
	file1 << endl << "Address: " << addr << endl ;
	sleep(1);
	cout << "\n Please wait for the confirmation from the store....." ;
	sleep(2) ;
	cout << "\n Your order has been placed successfully. " ;
	cout << "\n We will reach you out as soon as possible. ";
	exit(0) ;
}

// admin_module
void admin_module()
{
	system("CLS") ;
	cout << "\n\n\t\t  ==================== ADMIN MODULE ====================" ;
	cout << "\n\n";
	cout << "\n  1. Add Product" ;
	cout << "\n  2. Check your Inventory" ;
	cout << "\n  3. Check your orders" ;
	cout << "\n  4. Exit the module" ;
	
	int choice ;
	cout << "\n\n Your choice: " ;
	cin >> choice ;
	switch(choice) {
		case 1: add_product(); break ;
		case 2: check_inventory(); break ;
		case 3: check_orders(); break ;
		case 4: exit(0); break ;
	}
}

// add_product module
void add_product()
{
	string product_name ;
	int price ;
	
	cout << "\n\n\n Add your products here." ;
	cout << "\n\n" ;
	cout <<"\n Product name: " ; cin >> product_name ;
	cout << "\n Price: " ; cin >> price ;
	file1.open("C:\\Users\\MANISH\\OneDrive\\Desktop\\College\\Codespeedy\\Supermarket Management System\\products.txt",ios::app|ios::binary) ;
	if(!file1){ cout << "\n Can not open the requested file!!" ; }
	else{
		cout << endl;
		file1 <<"Product Name: " << product_name << " " <<"Price: " << price << endl;
		file1.close();
	}
	// send the confirmation msg
	cout << "\n Product has been added." ;
	char ch;
	cout << "\n Do you want to add more products? " ;
	cin >> ch ;
	if(ch == 'y' || ch == 'Y') {
		add_product();
	}
	else { admin_module(); }
}

// check your inventory
void check_inventory()
{
	system("CLS") ;
	string read ;
	file3.open("C:\\Users\\MANISH\\OneDrive\\Desktop\\College\\Codespeedy\\Supermarket Management System\\products.txt",ios::out|ios::in);
	cout << "\n\n\n\t\t****************************************" << endl ;
	cout << "\t\t             Your Inventory" ;
	cout << "\n\t\t****************************************" << endl ;
	while(getline(file3, read)) {
		cout << endl ;
		cout << read << endl ;
	}
	cout << "=====================================" << endl ;

	file3.close();
	
	
	cout << "\n want to perform more operations? ";
	char ch;
	cin >> ch;
	if(ch == 'y') {
		admin_module();
	}
	else {
		exit(0);
	}	
}

// check the orders from the customers
void check_orders()
{
	system("CLS") ;
	string read ;
	file3.open("C:\\Users\\MANISH\\OneDrive\\Desktop\\College\\Codespeedy\\Supermarket Management System\\customers_order.txt",ios::out|ios::in);
	cout << "\n\n\n\t\t****************************************" << endl ;
	cout << "\t\t             Order Received" ;
	cout << "\n\t\t****************************************" << endl ;
	while(getline(file3, read)) {
		cout << endl ;
		cout << read << endl ;
	}
	cout << "=====================================" << endl ;

	file3.close();
	remove("customers_order.txt");
	cout << "\n Order compeleted." << endl;
	cout << "\n want to perform more operations? ";
	char ch;
	cin >> ch;
	if(ch == 'y') {
		admin_module();
	}
	else {
		exit(0);
	}
	
}

// Login menu
int user_menu()
{
	char chs ;
	// there will be three modules
	int choice ;
	cout << "\n\n			###############################################" << endl ;
	cout << "				 SUPERMARKET MANAGEMENT SYSTEM " ;
	cout << "\n			###############################################" << endl ;
	cout << "\n\n\n			************ LOGIN/REGISTRATION MODULE ************" << endl ;
	cout << "\n\n\n  1. Customer Login" << endl ;
	cout << "  2. Staff Login" << endl ;
	cout << "  3. Admin Login" << endl ;
	cout << "  4. Registration" << endl ;
	cout << "  5. Exit the module" << endl ;
	cout << "\n\n  Login type as: " ;
	cin >> choice ;
	
	switch(choice) {
		case 1: login_customer() ; break ;
		case 2: login_staff() ; break ;
		case 3: login_admin() ; break ;
		case 4: registration_type(); break; 
		case 5: exit(0) ;
		default: cout << "\n Invalid choice!!" << endl ; break ;
		
		// want to perform more actions
		cout << "\n Do you want to perform more operations?" ;
		cin >> chs ;
		if (chs == 'Y' || chs == 'y' || chs == '1') { 
			system("CLS") ;
			user_menu() ; 
		}
		else if(chs == 'N' || chs == 'n' || chs == '0') {
			exit(0) ;
		}
		else {
			cout << "\n Invalid choice!!!" ;
			cout << "\n Exiting the module" ; exit(0) ;
		}
	}
}

int main(int argc, char* argv)
{
	user_menu() ;
	return 0;
}
