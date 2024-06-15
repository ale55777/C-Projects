#include <iostream>

#include<string>

									//HMS

using namespace std;

void mainMenu();//main menu of HMS

void login();//function for login

void adminAccount();//function for admin to control/modify Doctor's info

void patientMenu();//function for patient menu

void patientReg();//function for patient registration

void patientInfo();//displaying Patient's info

void appointment();//function for taking appointment

void doctorInfo();//function for displaying doctor's Doctor info

void AddDoctorsManually();//add doctors hard coded

void initializeAppointmentArray();//initialize doctors appointmentArray with-100

void initializeAppointmentArrayByIndex(int index);//initializing Doctor's Appointment Array By giving index to -100 So Easy To Check Appointment Time Slot

void createDoctors();//function for creating list of doctors

void doctorName();//function for changing doctor's name

void doctorFee();//function for changing doctor's fee

void doctorWorkingHours();//function for changing doctor's working hours

void doctorTask();//function for changing doctor's task/specialization

bool CheckName(string value);//funtion for checking name Format

bool CheckNIC(string value);//function for checking NIC format

bool CheckCellNo(string value);//function for checking Cell No format

bool CheckInteger(string value);//function for checking integer or not

bool CheckSpecialization(string value);//function for checking Doctor's Specialization/Task Format

bool CheckWorkingHours(string value);//Function for checking working hours format and limit

bool CheckHoursToFrom(string value);//Function for checking working hours to and from format

////////////////////////////////////Main Menu Variable & constants//////////////////////////////

const int SizeDoctor=5;//doctor size

const int SizePatient=50;//patient size

const int IDpatient=1000;//generating patient id

const int IDdoctor = 2000;//generating DOCTOR'S id


////////////////////////////////////signin variables///////////////////////////////////////////

string username = "laraib", password = "laraib";


////////////////////////////////////credit card variable///////////////////////////////////////////

const int sizeCreditCard = 10;
string creditCard[sizeCreditCard] = { "1111", "2222", "3333", "4444", "5555", "6666", "7777", "8888", "9999", "0000" };
float creditBal[sizeCreditCard] = { 3000, 5000, 3200, 1230, 6000, 4000, 3600, 2300, 2500, 9000 };

///////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////PatientReg Variable//////////////////////////////////////

struct Patient{
	string fatherName, NIC, cell, medicalHistory
		, medicines, name, appointmentTime[SizeDoctor], appointmentDocName[SizeDoctor];
	int ID, appointmentID[SizeDoctor], appointmentIdDoctor[SizeDoctor];//appointment id and doc id;
	int appointmentIndex = 0;
};
Patient patient[SizePatient];
int patientRegloop=0;

//////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////Appointment Function Variables////////////////////////////////

int  appointmentCounter=0;
float profit=0,totalprofit=0;

///////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////Doctor's Variables//////////////////////////////////////

struct Doctor
{
	string name, specialization, startingHr, EndingHr;
	static const int timeSize=9;
	string timeSlot[timeSize];
	int workingHours = 0, Fee = 0, ID = 0, timeIndex = 0, appointmentArray[timeSize], appointmentIndex = 0;
};
Doctor doctors[SizeDoctor];
int doctorRegloop = 0;

///////////////////////////////////////////////////////////////////////////////////////////////


int main()//main program
{
	AddDoctorsManually();
	initializeAppointmentArray();
	mainMenu();
	return 0;

}//end of main

void mainMenu()//Main Menu Of HMS
{
	char MainMenuchoice;
	system("color 2E");

	cout << "\n\n";
	cout << "\t---------------------------------------------------------\n";
	cout << "\t|*******************************************************|\n";
	cout << "\t---------------------------------------------------------\n";
	cout << "\t|\t\t\t\t\t\t\t|\n";
	cout << "\t|\t` WELLCOME TO HOSPITAL MANAGEMENT SYSTEM'\t|\n";
	cout << "\t|\t\t\t\t\t\t\t|\n";
	cout << "\t_______________\t\t\t\t_________________\n";
	cout << "\t|\t_______\t\t\t\t_______\t\t|\n";
	cout << "\t|\t| | | |\t\t\t\t| | | |\t\t|\n";
	cout << "\t|\t```````\t\t\t\t```````\t\t|\n";
	cout << "\t|\t\t\t\t\t\t\t|\n";
	cout << "\t|\t\t\t\t\t\t\t|\n";
	cout << "\t|\t\t\t__________\t\t\t|\n";
	cout << "\t|\t\t\t|        |\t\t\t|\n";
	cout << "\t|\t\t\t|        |\t\t\t|\n";
	cout << "\t_______________\t\t|        |\t_________________\n";
	cout << "\t|\t_______\t\t|        |\t_______\t\t|\n";
	cout << "\t|\t| | | |\t\t|        |\t| | | |\t\t|\n";
	cout << "\t|\t```````\t\t|        |\t```````\t\t|\n";
	cout << "\t|\t\t\t|        |\t\t\t|\n";
	cout << "\t|\t\t\t|        |\t\t\t|\n";
	cout << "\t|_______________________________________________________|\n";

	while (true)
	{
		cout << "\n\n\t\t\t1. Administrator Login" << endl
			<< "\n\n\t\t\t2. Patient Menu" << endl
			<< "\n\n\t\t\t3. Exit Program\n";
		cout << "\n\n\t\t\t";
		cin >> MainMenuchoice;
		if (isalpha(MainMenuchoice))
		{
			cout << "\n\n\t\t\tPlease Enter A Digit";
			cout << "\n\n\n\t\t\t";
			system("pause");
			system("cls");
			mainMenu();
		}//if(isalpha(choice))
		system("color 5E");
		switch (MainMenuchoice)
		{
		case '1':
		{
			login();
			break;
		}
		case '2':
		{
			patientMenu();
			break;
		}
		case '3':
		{
			system("cls");
			system("color 5E");
			cout << "\n\n*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^**";
			cout << "\n\n*^*^*^*^*^*^*^*^*^*^*^** ALLAH HAFIZ TAKE CARE FROM LARAIB **^*^*^*^*^*^*^*^*^**";
			cout << "\n\n*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^**";
			cout << "\n\n\n\t\t\t";
			system("pause");
			exit(1);
			break;
		}
		default:
		{
			cout << "\n\n\t\t\tInvalid Option" << endl;
			cout << "\n\n\n\t\t\t";
			system("pause");
			system("cls");
			mainMenu();
			break;
		}
		}//switch(choice)
		cout << "\n\n\n\t\t\t";
		system("pause");
		system("cls");
	}//while(true)
}// end ofmainMenu

void patientMenu()//Main Patient Menu
{
	system("color E");
	char patientMenuChoice;
	system("cls");
	cout << "\n\n*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^**";
	cout << "\n\n*^*^*^*^*^*^*^*^*^*^*^*^*  WELLCOME TO PATIENTS MENU  *^*^*^*^*^*^*^*^*^*^*^*^**";
	cout << "\n\n*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^**";
	while (true)
	{
		cout << "\n\n\t\t\t1. Register Patient" << endl
			<< "\n\n\t\t\t2. Doctors Information" << endl
			<< "\n\n\t\t\t3. Take AppointMent" << endl
			<< "\n\n\t\t\t4. Main Menu\n";
		cout << "\n\n\n\t\t\t";
		cin >> patientMenuChoice;
		if (isalpha(patientMenuChoice))
		{
			cout << "\n\n\t\t\tPlease Enter A Digit";
			cout << "\n\n\n\t\t\t";
			system("pause");
			system("cls");
			patientMenu();
		}//if(isalpha(patientMenuChoice))
		system("cls");
		system("color 2E");
		switch (patientMenuChoice)
		{
		case '1':
		{
			patientReg();
			break;
		}
		case '2':
		{
			doctorInfo();
			break;
		}
		case '3':
		{
			appointment();
			break;
		}
		case '4':
		{
			mainMenu();
			break;
		}
		default:
		{
			cout << "\n\n\t\t\tInvalid Option" << endl;
			break;
		}
		}//switch (patientMenuChoice)
		cout << "\n\n\t\t\t";
		system("pause");
		system("cls");
		patientMenu();
	}//while(true)
}//end of void patientMenu()

void login()//Function for checking login and password
{
	string user, pass;
	system("cls");
	system("color E4");
	cout << "\n\n\t\t\tEnter Username: ";
	cin >> user;
	cout << "\n\n\t\t\tEnter Password: ";
	cin>>pass;
	if (user == username)
	{
		if (pass == password)
		{
			cout << "\n\n\n\t\t\tLogin Successfully" << endl;
			cout << "\n\n\n\t\t\t";
			system("pause");
			system("cls");
			adminAccount();
		}//if(pass==password)
		else
		{
			cout << "\n\n\t\t\tInvalid Password" << endl;
			cout << "\n\n\n\t\t\t";
			system("pause");
			system("cls");
			mainMenu();

		}//inner else
	}//if(user==username)
	else
	{
		cout << "\n\n\t\t\tInvalid Username And Password" << endl;
		cout << "\n\n\n\t\t\t";
		system("pause");
		system("cls");
		mainMenu();
	}//outer else
}//end of void login()

void adminAccount()//Functions For Displaying Admin Account To Modify Doctor's Info
{
	char adminAccountChoice;//input from user for menu
	system("cls");
	while (true)
	{
		cout << "\n\n*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^**";
		cout << "\n\n*^*^*^*^*^*^*^*^*^*^*^*  WELLCOME TO ADMINISTRATOR MENU  *^*^*^*^*^*^*^*^*^*^*^*";
		cout << "\n\n*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^**";
		cout << "\n\t\t\t\tWelcome, " << username;
		system("color 5E");
		cout << "\n\n\t\t\t1. Create A list of doctors"
			<< "\n\n\t\t\t2. Change Name of doctor"
			<< "\n\n\t\t\t3. Change Fee of doctor"
			<< "\n\n\t\t\t4. Change Working Hours"
			<< "\n\n\t\t\t5. Change Doctor Task"
			<< "\n\n\t\t\t6. List Of Patients"
			<< "\n\n\t\t\t7. Doctor's Info"
			<< "\n\n\t\t\t8. Profit We Have"
			<< "\n\n\t\t\t9. Log Out";
		cout << "\n\n\n\t\t\t";
		cin >> adminAccountChoice;
		if (isalpha(adminAccountChoice))
		{
			cout << "\n\n\t\t\tPlease Enter A Digit";
			cout << "\n\n\n\t\t\t";
			system("pause");
			system("cls");
			adminAccount();
		} // if (isalpha(adminAccountChoice))
		system("cls");
		system("color 4E");
		switch (adminAccountChoice)
		{
			case '1':
			{
				createDoctors();
				break;
			}
			case '2':
			{
				doctorName();
				break;
			}
			case '3':
			{
				doctorFee();
				break;
			}
			case '4':
			{
				doctorWorkingHours();
				break;
			}
			case '5':
			{
				doctorTask();
				break;
			}
			case '6':
			{
				patientInfo();
				break;
			}
			case '7':
			{
				doctorInfo();
				break;
			}
			case '8':
			{
				cout << "\n\n\t\t\t Total Appointmets We Have : " << appointmentCounter << endl;
				cout << "\n\n\t\t\t Total Profit We Have : " << totalprofit << endl;
				cout << "\n\n\t\t\t";
				break;
			}
			case '9':
			{
				mainMenu();
				break;
			}
			default:
			{
				cout << "\n\n\t\t\tInvalid Option" << endl;
			}
		} //switch (adminAccountChoice)
		cout << "\n\n\t\t\t";
		system("pause");
		system("cls");
	}//while(true)
}//end of void adminAccount

bool CheckName(string value)//Checking Name Format if Correct Return True Else False
{
	bool check = false;
	if (value.length()> 25 || value.length()<4)
	{
		cout << "\n\n\t\tSorry Invalid Name Entered Its Length Must Be B/w 4 & 25\n";
		cout << "\n\n\n\t\t\t";
		system("pause");
		system("cls");
		return false;
	}//if (value.length()> 25 || value.length()<4)
	for (int i = 0; i < value.length(); i++)
	{
		if ((value[i] >= 'a') && (value[i] <= 'z') || (value[i] <= ' ') || (value[i] >= 'A') && (value[i] <= 'Z') || (value[i] <= ' '))
		{
			check = true;
		}//if ((value[i] >= 'a') && (value[i] <= 'z') || (value[i] <= ' ') || (value[i] >= 'A') && (value[i] <= 'Z') || (value[i] <= ' '))
		else
		{
			check = false;
			break;
		}//else
	}//for (int i = 0; i < value.length(); i++)
	if (check == true)
	{
		return true;
	}//if (check == true)
	if (check == false)
	{
		cout << "\n\n\t\tSorry Invalid Name Typed It Must Be Of Characters\n";
		cout << "\n\n\n\t\t\t";
		system("pause");
		system("cls");
		return false;
	}//if (check == false)
	return false;
}//ending bool CheckName(string value)

bool CheckNIC(string value)//function for checking NIC format if Correct Return True Else False
{
	bool right = false;
	if (value.length()> 13 || value.length()<13)
	{
		cout << "\n\n\t\tSorry Invalid NIC No Entered It Length Must Be 13\n";
		cout << "\n\n\n\t\t\t";
		system("pause");
		system("cls");
		return false;
	}//if (value.length()> 13 || value.length()<13)
	for (int i = 0; i < value.length(); i++)
	{
		if ((value[i] >= '0') && (value[i] <= '9'))
		{
			right = true;
		}//if ((value[i] >= '0') && (value[i] <= '9'))
		else
		{
			right = false;
			break;
		}//else
	}//for (int i = 0; i < value.length(); i++)
	if (right == true)
	{
		return true;
	}//if (right == true)
	if (right == false)
	{
		cout << "\n\n\t\tSorry Invalid NIC No Typed It Must Be Of Digits\n";
		cout << "\n\n\n\t\t\t";
		system("pause");
		system("cls");
	}//if (right == false)
	return false;
}//ending bool CheckNIC(string value);//function for checking NIC format

bool CheckCellNo(string value)//function for checking Cell No format if Correct Return True Else False
{
	bool Cell = false;
	if (value.length()> 13 || value.length()<11)
	{
		cout << "\n\n\t\tSorry Invalid Cell No Entered Length Must Be B/w 11 & 13\n";
		cout << "\n\n\n\t\t\t";
		system("pause");
		system("cls");
		return false;
	}//if (value.length()> 13 || value.length()<11)
	for (int i = 0; i < value.length(); i++)
	{
		if ((value[i] >= '0') && (value[i] <= '9'))
		{
			Cell = true;
		}//if ((value[i] >= '0') && (value[i] <= '9'))
		else
		{
			Cell = false;
			break;
		}//else
	}//for (int i = 0; i < value.length(); i++)
	if (Cell == true)
	{
		return true;
	}//if (Cell == true)
	if (Cell == false)
	{
		cout << "\n\n\t\tSorry Invalid Time Slot No Typed It Must Be Of Digits\n";
		cout << "\n\n\n\t\t\t";
		system("pause");
		system("cls");
		return false;
	}//if (Cell == false)
	return false;
}//ending bool CheckCellNo(string value);//function for checking Cell No format

bool CheckInteger(string value)//function for checking integer if Correct Return True Else False
{
	bool right = false;
	for (int i = 0; i < value.length(); i++)
	{
		if ((value[i] >= '0') && (value[i] <= '9'))
		{
			right = true;
		}//if ((value[i] >= '0') && (value[i] <= '9'))
		else
		{
			right = false;
			break;
		}//else
	}//for (int i = 0; i < value.length(); i++)
	if (right == false)
	{
		cout << "\n\n\t\tSorry Invalid Typed It Must Be Of Digits\n";
		cout << "\n\n\n\t\t\t";
		system("pause");
		system("cls");
		return false;
	}//if (right == false)
	if (right == true)
	{
		return true;
	}//if (right == true)
	return false;
}//ending bool CheckInteger(string value);//function for checking integer or not

bool CheckSpecialization(string value)//function for checking Doctor's Specialization/Task Format
{
	bool Spec = false;
	if (value.length()<3)
	{
		cout << "\n\n\tSorry Invalid Task Entered Its Length Must Be 3 Or Greater than 3\n";
		cout << "\n\n\n\t\t\t";
		system("pause");
		system("cls");
		return false;
	}//if (value.length()<3)
	for (int i = 0; i < value.length(); i++)
	{
		if ((value[i] >= 'a') && (value[i] <= 'z') || (value[i] <= ' ') || (value[i] >= 'A') && (value[i] <= 'Z') || (value[i] <= ' '))
		{
			Spec = true;
		}//if ((value[i] >= 'a') && (value[i] <= 'z') || (value[i] <= ' ') || (value[i] >= 'A') && (value[i] <= 'Z') || (value[i] <= ' '))
		else
		{
			Spec = false;
			break;
		}//else
	}//for (int i = 0; i < value.length(); i++)
	if (Spec == false)
	{
		cout << "\n\n\t\tSorry Invalid Specialization Typed It Must Be Of Characters\n";
		cout << "\n\n\t\t\t";
		system("pause");
		system("cls");
		return false;
	}//if (Spec == false)
	if (Spec == true)
	{
		return true;
	}//if (Spec == true)
	return false;
}//ending bool CheckSpecialization(string value)//function for checking Doctor's Specialization/Task Format

bool CheckWorkingHours(string value)//Function for checking working hours format and limit
{
	bool WHr = false;
	if ((value[0] > '0') && (value[0] <= '3'))
	{
		WHr = true;
	}//if ((value[i] > '0') && (value[i] <= '3'))
	else
	{
		WHr = false;
	}//else
	if (WHr == false)
	{
		cout << "\n\n\t\tSorry Invalid Hours Typed It Must Be Of Digits Or Less Than 3\n";
		cout << "\n\n\t\t\t";
		system("pause");
		system("cls");
		return false;
	}//if (WHr == false)
	if (WHr == true)
	{
		return true;
	}//if (WHr == true)
	return false;
}//ending bool CheckWorkingHours(string value)//Function for checking working hours format and limit

bool CheckHoursToFrom(string value)//Function for checking working hours to and from format
{
	bool SHr = false;
	int length = value.length();
	if (length == 4)
	{
		if (((value[0] >= '0') && (value[0] <= '1')) && ((value[1] >= '0') && (value[1] <= '9')) && ((value[2] == 'a') || (value[2] == 'A') || (value[2] == 'p') || (value[2] == 'P')) && ((value[3] == 'm') || (value[3] == 'M')))
		{
			SHr = true;
		}//if (((value[0] >= '0') && (value[0] <= '1')) && ((value[1] >= '0') && (value[1] <= '9')) && ((value[2] == 'a') || (value[2] == 'A') || (value[2] == 'p') || (value[2] == 'P')) && ((value[3] == 'm') || (value[3] == 'M')))
		else
		{
			SHr = false;
		}//else
	}//if (length == 4)
	if (length == 3)
	{
		if (((value[0] > '0') && (value[0] <= '9')) && ((value[1] == 'a') || (value[1] == 'A') || (value[1] == 'p') || (value[1] == 'P')) && ((value[2] == 'm') || (value[2] == 'M')))
		{
			SHr = true;
		}//if (((value[0] > '0') && (value[0] <= '9')) && ((value[1] == 'a') || (value[1] == 'A') || (value[1] == 'p') || (value[1] == 'P')) && ((value[2] == 'm') || (value[2] == 'M')))
		else
		{
			SHr = false;
		}//else
	}//if (length == 3)
	if (SHr == false)
	{
		cout << "\n\n\tSorry Invalid Enter Working Hours It Must Be A Integer & am or pm \n";
		cout << "\n\n\t\t\t";
		system("pause");
		system("cls");
		return false;
	}//if (SHr == false)
	if (SHr == true)
	{
		return true;
	}//if (SHr == true)
	return false;
}//ending bool CheckHoursToFrom(string value)//Function for checking working hours to and from format

void patientReg()//Function For Registering Pateint
{
	string tempName, tempFname, tempNIC, tempCell;//temp variables for storing data from user
	bool Name = false, Fname = false, NIC = false, Cell = false;// bool variables for checking entered data is in correct format or not
	system("cls");
	if(patientRegloop<SizePatient)
	{
		cout<<"\n\n\t\t* Tip : Enter Full Name\n";
		cout<<"\n\nPlease Enter Name OF Patient "<<patientRegloop+1<<": ";
		cin.ignore(); // skip over end-of-line character
		getline(cin, tempName);
		Name = CheckName(tempName);
		if (Name == false)
		{
			patientMenu();
		}//if (Name == false)
		cout<<"\n\nPlease Enter Father Name OF Patient "<<patientRegloop+1<<": ";
		getline(cin, tempFname);
		Fname = CheckName(tempFname);
		if (Fname == false)
		{
			patientMenu();
		}//if (Fname == false)
		cout << "\n\n\t\t* Tip : Enter 13 Digit NIC No Without ' - '\n";
		cout<<"\n\nPlease Enter NIC OF Patient "<<patientRegloop+1<<": ";
		cin >> tempNIC;
		NIC = CheckNIC(tempNIC);
		if (NIC == false)
		{
			patientMenu();
		}//if (right == false)
		cout << "\n\n\t\t* Tip : Enter Cell No With Or Without Country Code\n";
		cout<<"\n\nPlease Enter Cell No OF Patient "<<patientRegloop+1<<": ";
		cin >> tempCell;
		Cell = CheckCellNo(tempCell);
		if (Cell == false)
		{
			patientMenu();
		}//if (Cell == false)
		if (Cell == true && NIC== true && Name== true && Fname==true)
		{
			patient[patientRegloop].name = tempName;
			patient[patientRegloop].NIC = tempNIC;
			patient[patientRegloop].fatherName = tempFname;
			patient[patientRegloop].cell  = tempCell;
		}//if (Cell == true && NIC== true && Name== true && Fname==true)
		cout << "\n\n\t\t* Tip : Just Enter If Want To Leave Blank\n";
		cout<<"\n\nPlease Enter Previous Medical history OF Patient "<<patientRegloop+1<<": ";
		cin.ignore(); // skip over end-of-line character
		getline(cin, patient[patientRegloop].medicalHistory);
		cout << "\n\n\t\t* Tip : Just Enter If Want To Leave Blank\n";
		cout<<"\n\nPlease Enter List of medicine as per medical history Of Patient "<<patientRegloop+1<<": ";
		getline(cin, patient[patientRegloop].medicines);
		patient[patientRegloop].ID = IDpatient + (patientRegloop + 1);
		cout << "\n\n\t\tYour Patient ID Is : " << patient[patientRegloop].ID << endl;
		patientRegloop++;
	}//if(patientRegloop<SizePatient)
	else
	{
		cout<<"\n\n\t\t\tNo More Patient Could Be Registered ";
		cout<<"\n\n\t\t\t";
		system("pause");
		system("cls");
		patientMenu();
	}//else
	cout<<"\n\n\t\t\t";
}//end of void patientReg()

void appointment()//Function For Taking Doctor's Appointment
{
	bool right = false;//variable for checking correct entered format
	int AppointmentNoFromPatient = 0, AppointmentNoloop = 0, PatientTempID=0, Appointmentloop = 0, timeFromUser = -100;
	int found = 0, pateintIndex = 0, balance = 0, cardIndex = 0;//other varaibles for getting input from user
	float credit;
	string cardNo, userTempData;
	cout << "\n\n\t\t* Tip : Enter ID In Integers\n";
	cout<<"\n\n\t\t\tEnter your ID number: ";
	cin >> userTempData;
	right = CheckInteger(userTempData);
	if (right == false)
	{
		patientMenu();
	}//if (right == false)
	if (right == true)
	{
		PatientTempID = atoi(userTempData.c_str());// convert string into intgr 
	}//if (right == true)
	for(Appointmentloop=0;Appointmentloop<patientRegloop;Appointmentloop++)//jitni reg hoai hain
	{
		if (PatientTempID == patient[Appointmentloop].ID)
		{
			pateintIndex = Appointmentloop;
			found=1;
			int tempIndex = patient[AppointmentNoloop].appointmentIndex;
			if (tempIndex >= SizeDoctor)
			{
				cout << "\n\n\t\t\tSorry You Can Take 5 Appointments A Day";
				cout << "\n\n\n\t\t\t";
				system("pause");
				patientMenu();
			}//if (tempIndex >= SizeDoctor)
			doctorInfo();
			cout << "\n\n\t\t* Tip : Enter In Integers\n";
			cout<<"\n\n\t\tYou Want To Take Appointment From Doctor : ";
			cin >> userTempData;
			right = CheckInteger(userTempData);
			if (right == false)
			{
				patientMenu();
			}//if (right == false)
			if (right == true)
			{
				AppointmentNoFromPatient = atoi(userTempData.c_str());//cnvrt it into intgr
			}//	if (right == true)
			if (AppointmentNoFromPatient > 0 && AppointmentNoFromPatient <= SizeDoctor)
			{
				AppointmentNoFromPatient = AppointmentNoFromPatient - 1;//(2-1)
				cout << "\n\n\t\t* Tip : Enter In Integers\n";
				cout << "\n\n\t\tEnter Appointment Slot Of Doctor : ";
				cin >> userTempData;
				right = CheckInteger(userTempData);
				if (right == false)
				{
					patientMenu();
				}//	if (right == false)
				if (right == true)
				{
					timeFromUser = atoi(userTempData.c_str());
				}//if (right == true)
				timeFromUser = timeFromUser - 1;
				if (timeFromUser < 0 || timeFromUser > (doctors[AppointmentNoFromPatient].timeIndex))
				{
					cout << "\n\n\t\tSorry You Enter A Wrong Appointment Time Slot ";
					cout << "\n\n\n\t\t\t";
					system("pause");
					system("cls");
					patientMenu();
				}//if (timeFromUser < 0 || timeFromUser > (doctors[AppointmentNoFromPatient].timeIndex))
				for (int i = 0; i <= doctors[AppointmentNoFromPatient].timeIndex; i++)
				{
					if (timeFromUser == (doctors[AppointmentNoFromPatient].appointmentArray[i]))
					{
						cout << "\n\n\t\tSorry This Time Slot Is Already Appointed";
						cout << "\n\n\n\t\t\t";
						system("pause");
						system("cls");
						patientMenu();
					}//if (timeFromUser == (doctors[AppointmentNoFromPatient].appointmentArray[i]))
				}//for (int i = 0; i <= doctors[AppointmentNoFromPatient].timeIndex; i++)
				cout << "\n\n\t\t\tPlease Enter Your Credit Card No : ";
				cin >> cardNo;
				int found = 0;//for finding card if 1 means found
				for (int i = 0; i < sizeCreditCard; i++)
				{
					if (cardNo == creditCard[i])
					{
						credit = creditBal[i];
						cardIndex = i;
						found = 1;
						break;
					}//if (cardNo == creditCard[i])
				}//for (int i = 0; i < sizeCreditCard; i++)
				if (found==0)
				{
					cout << "\n\n\t\t\tSorry Invalid Card No";
					cout << "\n\n\n\t\t\t";
					system("pause");
					system("cls");
					patientMenu();
				}//if (found==0)
			}//if (AppointmentNoFromPatient >= 0 && AppointmentNoFromPatient <= SizeDoctor)
			else
			{
				cout<<"\n\n\t\t\tYou Enter A Wrong Doctor No ";
				cout<<"\n\n\n\t\t\t";
				system("pause");
				system("cls");
				patientMenu();
			}//inner else
			if(credit>=doctors[AppointmentNoFromPatient].Fee)
			{
				balance = credit - doctors[AppointmentNoFromPatient].Fee;
				profit=credit-balance;
				cout<<"\n\t\t\tYou Are Charged Amount : "<<profit;
				cout<<"\n\n\t\t\tYour Remaining Balance Is : "<<balance;
				creditBal[cardIndex] = balance;
				totalprofit = profit + totalprofit;
				patient[pateintIndex].appointmentID[tempIndex] = appointmentCounter + 1;
				patient[pateintIndex].appointmentDocName[tempIndex] = doctors[AppointmentNoFromPatient].name;
				patient[pateintIndex].appointmentIdDoctor[tempIndex] = doctors[AppointmentNoFromPatient].ID;
				patient[pateintIndex].appointmentTime[tempIndex] = doctors[AppointmentNoFromPatient].timeSlot[timeFromUser];
				cout << "\n\n\t\t\tYour appointment number is: " << patient[pateintIndex].appointmentID[tempIndex] << endl;
				patient[pateintIndex].appointmentIndex++;
				appointmentCounter++;
				int temp = doctors[AppointmentNoFromPatient].appointmentIndex;
				doctors[AppointmentNoFromPatient].appointmentArray[temp] = timeFromUser;
				doctors[AppointmentNoFromPatient].appointmentIndex++;		
			}//if(credit>=doctors[AppointmentNoFromPatient].Fee)
			else
			{
				cout<<"\n\n\t\t\tYou Have Low Balance";
			}//outer else
			break;
		}//if (PatientTempID == patient[Appointmentloop].ID)
	}//for(Appointmentloop=0;Appointmentloop<patientRegloop;Appointmentloop++)
	if(found==0)
	{
		cout<<"\n\n\t\t\tSorry You Are Not Registered ";
		cout<<"\n\n\n\t\t\t";
		system("pause");
		patientMenu();
	}//if(found==0)
}//end of void appointment()

void patientInfo()//function For Displaying Patient's Info
{
	system("color 2E");
	int  PatientInfoloopSecond = 0;
	cout<<"\n\n\t\t\tPatients Record Is : "<<endl;
	for (PatientInfoloopSecond = 0; PatientInfoloopSecond<patientRegloop; PatientInfoloopSecond++)
	{
			cout<<"\n\nPatient ID Number Is: "<<patient[PatientInfoloopSecond].ID<<endl;
			cout << "\n\nName Of Patient " << PatientInfoloopSecond + 1 << " Is : " << patient[PatientInfoloopSecond].name;
			cout << "\n\nFather Name Of Pateint " << PatientInfoloopSecond + 1 << " Is : " << patient[PatientInfoloopSecond].fatherName;
			cout << "\n\nNIC Of Patient  " << PatientInfoloopSecond + 1 << " Is : " << patient[PatientInfoloopSecond].NIC;
			cout << "\n\nCell No OF Patient  " << PatientInfoloopSecond + 1 << " Is : " << patient[PatientInfoloopSecond].cell;
			cout << "\n\nMedical History Of Patient  " << PatientInfoloopSecond + 1 << " Is : " << patient[PatientInfoloopSecond].medicalHistory;
			cout << "\n\nList of medicine as per medical history Of Patient  " << PatientInfoloopSecond + 1 << " Is : " << patient[PatientInfoloopSecond].medicines;
			cout << "\n\nAppointment Details Are :" << endl;
			cout << "\n\n--------------------------------------------------------------------------------";
			for (int PatientInfoloop = 0; PatientInfoloop< patient[PatientInfoloopSecond].appointmentIndex; PatientInfoloop++)
			{
				cout << "\n\nPatient Appointment Doctor Name Is: " << patient[PatientInfoloopSecond].appointmentDocName[PatientInfoloop];
				cout << "\n\nPatient Appointment Number Is: " << patient[PatientInfoloopSecond].appointmentID[PatientInfoloop];
				cout << "\n\nPatient Appointment Time Is: " << patient[PatientInfoloopSecond].appointmentTime[PatientInfoloop];
				cout << "\n\n------------------------------------------------";
			}//for(int PatientInfoloop=0;PatientInfoloop<SizeDoctor;PatientInfoloop++)
			cout<<"\n\n--------------------------------------------------------------------------------";
	}//for(PatientInfoloopSecond=0;PatientInfoloopSecond<SizeDoctor;PatientInfoloopSecond++)
	cout<<"\n\n\n\t\t\t";
	system("pause");
	adminAccount();
}//end of void patientInfo()

void createDoctors()//Function For Creating/Adding Doctor's Info
{
	string tempName, tempSpec, tempFee, tempWHr, tempSHr, tempEHr, temptimeSlot, tempTime;//temp variables for holding data from user
	int finalFee = 0, finalWHr = 0, HrStr = 0, HrEnd = 0, result = 0, timeIndex = 0;//temp variables for holding data from user
	bool Name = false, Spec = false, Fee = false, WHr = false, SHr = false, EHr = false, timeSlot = false;//temp variables for checking correct format of data from user
	system("cls");
	if (doctorRegloop<SizeDoctor)
	{
		cout << "\n\n\t\t* Tip : Enter Complete Doctor's Info\n";
		cout << "\n\nPlease Enter Full Name OF Doctor " << doctorRegloop + 1 << ": ";
		cin.ignore(); // skip over end-of-line character
		getline(cin, tempName);
		Name = CheckName(tempName);
		if (Name == false)
		{
			adminAccount();
		}//if (Name == false)
		cout << "\n\n\t\t* Tip : Enter Specialization Of Doctor In Characters\n";
		cout << "\n\nPlease Enter Specialization OF Doctor " << doctorRegloop + 1 << ": ";
		cin >> tempSpec;
		Spec = CheckSpecialization(tempSpec);
		if (Spec == false)
		{
			adminAccount();
		}//if (Spec == false)
		cout << "\n\n\t\t* Tip : Enter Fee Of Doctor In Digits\n";
		cout << "\n\nPlease Enter Fee OF Doctor " << doctorRegloop + 1 << ": ";
		cin >> tempFee;
		Fee = CheckInteger(tempFee);
		if (Fee == false)
		{
			adminAccount();
		}//if (Fee == false)
		cout << "\n\n\t\t* Tip : Enter Working Hours In Integer Less Than Equal To 3\n";
		cout << "\n\nPlease Enter Total Working Hours OF Doctor " << doctorRegloop + 1 << ": ";
		cin >> tempWHr;
		WHr = CheckWorkingHours(tempWHr);
		if (WHr == false)
		{
			adminAccount();
		}//if (WHr == false)
		cout << "\n\n\t\t* Tip :Now Enter Working Hours With A Integer & am or pm \n";
		cout << "\n\nPlease Enter Working Hours OF Doctor " << doctorRegloop + 1 << "\n\n\t\t\tFrom: ";
		cin >> tempSHr;
		SHr = CheckHoursToFrom(tempSHr);
		if (SHr == false)
		{
			adminAccount();
		}//if (SHr == false)
		cout << "\t\t\tTo : ";
		cin >> tempEHr;
		EHr = CheckHoursToFrom(tempEHr);
		if (EHr == false)
		{
			adminAccount();
		}//if (EHr == false)
		finalWHr = atoi(tempWHr.c_str());//2
		HrStr = atoi(tempSHr.c_str());
		HrEnd = atoi(tempEHr.c_str());
		if (HrEnd > HrStr)//2pm to 4pm
		{
			result = HrEnd - HrStr;
		}//if (HrEnd > HrStr)
		if (HrStr == 12)//12pm to 2pm
		{
			result = (HrEnd + HrStr) - HrStr;
		}//if (HrStr == 12)
		if (result > finalWHr || result < finalWHr)
		{
			cout << "\n\n\t\tYou Entered Total : " << finalWHr << " Working Hours\n";
			cout << "\n\n\tBut Entered Time Period Is Either Greater Or Less Than Working Hours\n";
			cout << "\n\n\n\t\t\t";
			system("pause");
			system("cls");
			adminAccount();
		}//if (result > tempHour || result < tempHour)
		cout << "\n\n\t\t* Tip :Enter Time Slots Not More Than 9\n";
		cout << "\n\n\tPlease Enter How Many Time Slots You Want To Create : ";
		cin >> temptimeSlot;
		timeSlot = CheckInteger(temptimeSlot);
		if (timeSlot == false)
		{
			adminAccount();
		}//if (timeSlot == false)
		if (timeSlot == true)
		{
			timeIndex = atoi(temptimeSlot.c_str());
		}//if (timeSlot == true)
		const int size = doctors[doctorRegloop].timeSize;
		string Array[size];
		timeIndex = timeIndex - 1;
		cout << "\n\n\t\t* Tip :Enter Time Slots Like 12:00pm - 12:20pm\n";
		cin.ignore();
		for (int i = 0; i <= timeIndex; i++)
		{
			cout << "\n\t\t\tEnter Time Slots : " << i + 1 << " : ";
			getline(cin, tempTime);
			if (tempTime.length() > 17 || tempTime.length() < 15)
			{
				cout << "\n\n\t\tSorry Invalid Enter Time Slot Entered\n";
				cout << "\n\n\t\t\t";
				system("pause");
				system("cls");
				adminAccount();
			}//if (tempIndex.length() > 17 || tempIndex.length() < 15)
			Array[i] = tempTime;
		}//for (int i = 0; i <= timeIndex; i++)
		if (Spec == true && Fee == true && Name == true && WHr == true && SHr == true && EHr == true && timeSlot == true)
		{
			finalFee = atoi(tempFee.c_str());
			finalWHr = atoi(tempWHr.c_str());
			doctors[doctorRegloop].name = tempName;
			doctors[doctorRegloop].specialization = tempSpec;
			doctors[doctorRegloop].Fee = finalFee;
			doctors[doctorRegloop].workingHours = finalWHr;
			doctors[doctorRegloop].startingHr = tempSHr;
			doctors[doctorRegloop].EndingHr = tempEHr;
			doctors[doctorRegloop].timeIndex = timeIndex;
			for (int i = 0; i <= timeIndex; i++)
			{
				doctors[doctorRegloop].timeSlot[i] = Array[i];
			}//for (int i = 0; i <= timeIndex; i++)
			initializeAppointmentArrayByIndex(doctorRegloop);//dobra sa app lany k lia -100 sa initliz krwaya ha
			doctors[doctorRegloop].ID = IDdoctor + (doctorRegloop + 1);
			cout << "\n\n\t\t\tYour Doctor ID Is : " << doctors[doctorRegloop].ID << endl;
			doctorRegloop++;
		}//if (Spec == true && Fee == true && Name == true && WHr == true && SHr == true && EHr == true && timeSlot == true)
	}//if (doctorRegloop<SizeDoctor)
	else
	{
		cout << "\n\n\t\t\tNo More Doctor Could Be Registered ";
		cout << "\n\n\t\t\t";
		system("pause");
		system("cls");
		adminAccount();
	}//else
	cout << "\n\n\t\t\t";
}//ending of void createDoctors()

void initializeAppointmentArray()//initializing Doctor's Appointment Array to -100 So Easy To Check Appointment Time Slot
{
	for (int i = 0; i < SizeDoctor; i++)
	{
		for (int j = 0; j < doctors[0].timeSize; j++)
		{
			doctors[i].appointmentArray[j] = -100;
		}//for (int j = 0; j < doctors[0].timeSize; j++)
		doctors[i].appointmentIndex = 0;
		//Initlize 5 dr ki array
	}//for (int i = 0; i < SizeDoctor; i++)
}// ending void initializeAppointmentArray()//initializing Doctor's Appointment Array to -100 So Easy To Check Appointment Time Slot

void initializeAppointmentArrayByIndex(int index)//initializing Doctor's Appointment Array By giving index to -100 So Easy To Check Appointment Time Slot
{
	for (int j = 0; j < doctors[index].timeSize; j++)
	{
		doctors[index].appointmentArray[j] = -100;
	}//for (int j = 0; j < doctors[0].timeSize; j++)
	doctors[index].appointmentIndex = 0;
	//ya 
}//ending initializeAppointmentArrayByIndex(int index)//initializing Doctor's Appointment Array By giving index  to -100 So Easy To Check Appointment Time Slot

void AddDoctorsManually()//Adding Doctors Manually
{
	doctors[0].name = "Laraib";
	doctors[0].specialization = "Dentist";
	doctors[0].startingHr = "12pm";
	doctors[0].EndingHr = "3pm";
	doctors[0].workingHours = 3;
	doctors[0].timeSlot[0] = "12:00pm - 12:20pm";
	doctors[0].timeSlot[1] = "12:20pm - 12:40pm";
	doctors[0].timeSlot[2] = "12:40pm - 1:00pm";
	doctors[0].timeSlot[3] = "1:00pm - 1:20pm";
	doctors[0].timeSlot[4] = "1:20pm - 1:40pm";
	doctors[0].timeSlot[5] = "1:40pm - 2:00pm";
	doctors[0].timeSlot[6] = "2:00pm - 2:20pm";
	doctors[0].timeSlot[7] = "2:20pm - 2:40pm";
	doctors[0].timeSlot[8] = "2:40pm - 3:00pm";
	doctors[0].timeIndex = 8;
	doctors[0].Fee = 500;
	doctors[0].ID = 2001;

	doctors[1].name = "Maryam";
	doctors[1].specialization = "Children Specialist";
	doctors[1].startingHr = "2pm";
	doctors[1].EndingHr = "4pm";
	doctors[1].workingHours = 2;
	doctors[1].timeSlot[0] = "2:00pm - 2:20pm";
	doctors[1].timeSlot[1] = "2:20pm - 2:40pm";
	doctors[1].timeSlot[2] = "2:40pm - 3:00pm";
	doctors[1].timeSlot[3] = "3:00pm - 3:20pm";
	doctors[1].timeSlot[4] = "3:20pm - 3:40pm";
	doctors[1].timeSlot[5] = "3:40pm - 4:00pm";
	doctors[1].timeIndex = 5;
	doctors[1].Fee = 500;
	doctors[1].ID = 2002;

	doctors[2].name = "Zoya";
	doctors[2].specialization = "Eye Specialist";
	doctors[2].startingHr = "3pm";
	doctors[2].EndingHr = "6pm";
	doctors[2].workingHours = 3;
	doctors[2].timeSlot[0] = "3:00pm - 3:20pm";
	doctors[2].timeSlot[1] = "3:20pm - 3:40pm";
	doctors[2].timeSlot[2] = "3:40pm - 4:00pm";
	doctors[2].timeSlot[3] = "4:00pm - 4:20pm";
	doctors[2].timeSlot[4] = "4:20pm - 4:40pm";
	doctors[2].timeSlot[5] = "4:40pm - 5:00pm";
	doctors[2].timeSlot[6] = "5:00pm - 5:20pm";
	doctors[2].timeSlot[7] = "5:20pm - 5:40pm";
	doctors[2].timeSlot[8] = "5:40pm - 6:00pm";
	doctors[2].timeIndex = 8;
	doctors[2].Fee = 600;
	doctors[2].ID = 2003;

	doctors[3].name = "Rameen";
	doctors[3].specialization = "ENT";
	doctors[3].startingHr = "5pm";
	doctors[3].EndingHr = "7pm";
	doctors[3].workingHours = 2;
	doctors[3].timeSlot[0] = "5:00pm - 5:20pm";
	doctors[3].timeSlot[1] = "5:20pm - 5:40pm";
	doctors[3].timeSlot[2] = "5:40pm - 6:00pm";
	doctors[3].timeSlot[3] = "6:00pm - 6:20pm";
	doctors[3].timeSlot[4] = "6:20pm - 6:40pm";
	doctors[3].timeSlot[5] = "6:40pm - 4:00pm";
	doctors[3].timeIndex = 5;
	doctors[3].Fee = 400;
	doctors[3].ID = 2004;

	doctors[4].name = "Ramsha";
	doctors[4].specialization = "Ear Specialist";
	doctors[4].startingHr = "6pm";
	doctors[4].EndingHr = "9pm";
	doctors[4].workingHours = 3;
	doctors[4].timeSlot[0] = "6:00pm - 6:20pm";
	doctors[4].timeSlot[1] = "6:20pm - 6:40pm";
	doctors[4].timeSlot[2] = "6:40pm - 7:00pm";
	doctors[4].timeSlot[3] = "7:00pm - 7:20pm";
	doctors[4].timeSlot[4] = "7:20pm - 7:40pm";
	doctors[4].timeSlot[5] = "7:40pm - 8:00pm";
	doctors[4].timeSlot[6] = "8:00pm - 8:20pm";
	doctors[4].timeSlot[7] = "8:20pm - 8:40pm";
	doctors[4].timeSlot[8] = "8:40pm - 9:00pm";
	doctors[4].timeIndex = 8;
	doctors[4].Fee = 300;
	doctors[4].ID = 2005;
}// ending void AddDoctorsManually()

void doctorInfo()//Function For Displaying Doctor's Info
{
	int  DoctorInfoloop = 0;
	cout << "\n\n\t\t\tDoctor Info Is : " << endl;
	for (DoctorInfoloop = 0; DoctorInfoloop<SizeDoctor; DoctorInfoloop++)
	{
		cout << "\n\n\t\t\tInfo Of Doctor No : " << DoctorInfoloop + 1 << " is :\n";
		cout << "\n\nName OF Doctor " << " : " << doctors[DoctorInfoloop].name;
		cout << "\n\nFee For Doctor " << doctors[DoctorInfoloop].name << ": " << doctors[DoctorInfoloop].Fee;
		cout << "\n\nWorking Hours For Doctor " << doctors[DoctorInfoloop].name << ": " << doctors[DoctorInfoloop].workingHours;
		cout << "\n\nWorking Hours For Doctor " << doctors[DoctorInfoloop].name << "\n\nFrom : " << doctors[DoctorInfoloop].startingHr << "  to : " << doctors[DoctorInfoloop].EndingHr;
		cout << "\n\nSpecializing of Doctor " << doctors[DoctorInfoloop].name << ": " << doctors[DoctorInfoloop].specialization;
		cout << "\n\nAvailable Appointment Timings Are :\n\n";
		for (int i = 0; i <= doctors[DoctorInfoloop].timeIndex; i++)
		{
			cout << "\t" << i + 1 << " : " << doctors[DoctorInfoloop].timeSlot[i] << "\t\t";
		}//for (int i = 0; i <= doctors[DoctorInfoloop].timeIndex; i++)
		cout << "\n\n\n--------------------------------------------------------------------------------";
	}//for(DoctorInfoloop=0;DoctorInfoloop<SizeDoctor;DoctorInfoloop++)
}//end of void doctorInfo()

void doctorName()//Function for changing Doctor's Name
{
	int index = 0;
	string name;
	bool right = false;
	doctorInfo();
	system("color E0");
	cout << "\n\n\t\t* Tip : Enter In Integers\n";
	cout << "\n\nPlease Select From Doctor List Whom You Want To Change The Name : ";
	cin >> name;
	right = CheckInteger(name);
	if (right == false)
	{
		adminAccount();
	}
	if (right == true)
	{
		index = atoi(name.c_str());
	}
	if (index > 0 && index <= SizeDoctor)
	{
		index = index - 1;
		cout << "\n\n\t\t* Tip : Enter Doctor Name\n";
		cout << "\n\n\t\tChange Name OF Doctor " << doctors[index].name << " To : ";
		cin.ignore(); // skip over end-of-line character
		getline(cin, name);
		right = CheckName(name);
		if (right == true)
		{
			doctors[index].name=name;
		}
		if (right == false)
		{
			adminAccount();
		}
	}
	else
	{
		cout << "\n\n\t\t\tSorry Invalid Option\n";
		cout << "\n\n\t\t\t";
	}
}//void doctorName()

void doctorFee()
{
	int index = 0;
	string name;
	bool right = false;
	doctorInfo();
	system("color E0");
	cout << "\n\n\t\t* Tip : Enter In Integers\n";
	cout << "\n\n\tPlease Select From Doctor List Whom You Want To Change The Fee : ";
	cin >> name;
	right = CheckInteger(name);
	if (right == false)
	{
		adminAccount();
	}
	if (right == true)
	{
		index = atoi(name.c_str());
	}
	if (index > 0 && index <= SizeDoctor)
	{
		index = index - 1;
		cout << "\n\n\t\t* Tip : Enter Fee In Integer Value \n";
		cout << "\n\n\t\tChange Fee OF Doctor " << doctors[index].name << ": "<< doctors[index].Fee << " To : ";
		cin>>name;
		right = CheckInteger(name);
		if (right == true)
		{
			doctors[index].Fee = atoi(name.c_str());
		}
		if (right == false)
		{
			adminAccount();
		}
	}
	else
	{
		cout << "\n\n\t\t\tSorry Invalid Option\n";
		cout << "\n\n\t\t\t";
	}
}//void doctorFee()

void doctorWorkingHours()//function for changing Doctors Working Hours And Starting And Ending Time
{
	int index = 0, tempHour=0,timeIndex=0, HrStr=0, HrEnd=0, result=0;
	string tempIndex,tempWrhour,tempStrHr,tempEndHr,temptimeSlot;
	bool right = false, Wrhour = false, StrHr = false, EndHr=false , timeSlot = false;
	doctorInfo();
	system("color E0");
	cout << "\n\n\t\t* Tip : Enter In Integers\n";
	cout << "\n\nPlease Select From Doctor List Whom You Want To Change The Working Hours : ";
	cin >> tempIndex;
	right = CheckInteger(tempIndex);
	if (right == false)
	{
		adminAccount();
	}//if (right == false)
	if (right == true)
	{
		index = atoi(tempIndex.c_str());
	}//if (right == true)
	if (index > 0 && index <= SizeDoctor)
	{
		index = index - 1;
		cout << "\n\n\t\t* Tip : Enter Working Hours In Integer Less Than Equal To 3\n";
		cout << "\n\n\t\tChange Working Hour OF Doctor " << doctors[index].name << ": " << doctors[index].workingHours << " To : ";
		cin >> tempWrhour;
		Wrhour = CheckWorkingHours(tempWrhour);
		if (Wrhour == true)
		{
			tempHour = atoi(tempWrhour.c_str());
		}//if (right == true)
		if (Wrhour == false)
		{
			adminAccount();
		}//if (right == false)
		cout << "\n\n\t\t* Tip :Now Enter Working Hours With A Integer & am or pm \n";
		cout << "\n\n\t\tWorking Hours For Doctor " << doctors[index].name << "\n\n\t\t\tFrom: ";
		cin >> tempStrHr;
		StrHr = CheckHoursToFrom(tempStrHr);
		if (StrHr == false)
		{
			adminAccount();
		}//if (hour == false)
		cout << "\t\t\tTo : ";
		cin >> tempEndHr;
		EndHr = CheckHoursToFrom(tempEndHr);
		if (EndHr == false)
		{
			adminAccount();
		}//if (end == false)
		HrStr = atoi(tempStrHr.c_str());
		HrEnd = atoi(tempEndHr.c_str());
		if (HrEnd > HrStr)
		{
			result = HrEnd - HrStr;
		}//if (HrEnd > HrStr)
		if (HrStr==12)
		{
			result = (HrEnd + HrStr) - HrStr;
		}//if (HrStr==12)
		if (result > tempHour || result < tempHour)
		{
			cout << "\n\n\t\tYou Entered Total : " << tempHour << " Working Hours\n";
			cout << "\n\n\tBut Entered Time Period Is Either Greater Or Less Than Working Hours\n";
			cout << "\n\n\n\t\t\t";
			system("pause");
			system("cls");
			adminAccount();
		}//if (result > tempHour || result < tempHour)
		cout << "\n\n\t\t* Tip :Enter Time Slots Not More Than 9\n";
		cout << "\n\n\tPlease Enter How Many Time Slots You Want To Create : ";
		cin >> temptimeSlot;
		timeSlot = CheckInteger(temptimeSlot);
		if (timeSlot == false)
		{
			adminAccount();
		}//if (timeSlot == false)
		if (timeSlot == true)
		{
			timeIndex = atoi(temptimeSlot.c_str());
		}//if (timeSlot == true)
		const int size = doctors[index].timeSize;
		string Array[size];
		timeIndex = timeIndex - 1;
		cout << "\n\n\t\t* Tip :Enter Time Slots Like 12:00pm - 12:20pm\n";
		cin.ignore();
		for (int i = 0; i <= timeIndex; i++)
		{
			cout << "\n\t\t\tEnter Time Slots : "<<i+1<<" : ";
			getline(cin, tempIndex);
			if (tempIndex.length() > 17 || tempIndex.length() < 15)
			{
				cout << "\n\n\t\tSorry Invalid Enter Time Slot Entered\n";
				cout << "\n\n\t\t\t";
				system("pause");
				system("cls");
				adminAccount();
			}//if (tempIndex.length() > 17 || tempIndex.length() < 15)
			Array[i] = tempIndex;
		}//for (int i = 0; i <= timeIndex; i++)
		if (Wrhour == true && StrHr == true && EndHr == true && timeSlot == true)
		{
			doctors[index].workingHours = tempHour;
			doctors[index].startingHr = tempStrHr;
			doctors[index].EndingHr = tempEndHr;
			doctors[index].timeIndex = timeIndex;
			for (int i = 0; i <= timeIndex; i++)
			{
				doctors[index].timeSlot[i] = Array[i];
			}//for (int i = 0; i <= timeIndex; i++)
			initializeAppointmentArrayByIndex(index);
		}//if (Wrhour == true && StrHr == true && EndHr == true && timeSlot == true)
	}//if (index <= SizeDoctor)
	else
	{
		cout << "\n\n\t\t\tSorry Invalid Option\n";
		cout << "\n\n\t\t\t";
	}//else
}//void doctorWorkingHours()

void doctorTask()
{
	int index = 0;
	string name;
	bool right = false;
	doctorInfo();
	system("color 2E");
	cout << "\n\n\t\t* Tip : Enter In Integers\n";
	cout << "\n\nPlease Select From Doctor List Whom You Want To Change The Task : ";
	cin >> name;
	right = CheckInteger(name);
	if (right == false)
	{
		adminAccount();
	}//if (right == false)
	if (right == true)
	{
		index = atoi(name.c_str());
	}//if (right == true)
	if (index > 0 && index <= SizeDoctor)
	{
		index = index - 1;
		cout << "\n\n\t\t* Tip : Enter Task/Specialization Of Doctor In Characters\n";
		cout << "\n\nPlease Enter Scheduling Task For Doctor " << doctors[index].name << " To : ";
		cin.ignore(); // skip over end-of-line character
		getline(cin, name);
		right = CheckSpecialization(name);
		if (right == true)
		{
			doctors[index].specialization = name;
		}//if (right == true)
		if (right == false)
		{
			adminAccount();
		}//if (right == false)
	}//if (index > 0 && index <= SizeDoctor)
	else
	{
		cout << "\n\n\t\t\tSorry Invalid Option\n";
		cout << "\n\n\t\t\t";
	}//else
}//void doctorTask()
