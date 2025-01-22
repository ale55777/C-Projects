#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
struct student
{
	string name;
	int roll_no;
	int monthly_income;
};
static int counter=0;
student s[100];
void display();
	int main()
	{	
		int option;
		char opt;
		int check;
		int i,ch,n=1,b;	
		ofstream file;
		ifstream file1;
	
		file1.open("student.txt");                      // reading data from file
		while(file1>>s[counter].name>>s[counter].roll_no>>s[counter].monthly_income)
				counter++;

	
		cout<< "\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::::"<<endl;    
		cout<<"\t\t\t\t\t SCHOLARSHIP MANAGEMENT SYSTEM"<<endl;
		cout<<"\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::::\n\n\n";;
	
		file1.close();
		do{
		
			cout<<"\n\t\t\t\t MAIN-MENUE\n  ";
			cout<<"\t\t\t\t ----------\n   Choose number: \n";
				cout<<"\t1)> Manage data. \n\t2)> Search. \n\t3)> Reports.\n\t4)> Exit.\n\n";
		
			cout<<" Your choice :";
			cin>>option;
			if(option==1)
			{
				do{
				
					cout<<"\n\t\t\t\t DATA-MENUE \n  ";
					cout<<"\t\t\t\t ----------\n   Choose alphabet: \n";
					
					cout<<"\ta)> Add data\n\tb)> Update data\n\tc)> Delete data\n\td)> Display data\n\te)> Exit\n\n Your choice :";
					cin>>opt;
					
			//		Adding data
			
			
					if(opt=='a')
					
					{
						cout<<"Enter the name and IDs of students to be added \n\n"; 
					file.open("student.txt");
					do
					{
					cout<<")>Name : ";
					cin>>s[counter].name;
			
					cout<<")>ID of student : ";
					cin>>s[counter].roll_no;
					
					cout<<")>Monthly income :";
					cin>>s[counter].monthly_income;
					
					counter++;
					cout<<"press 1 to continue otherwise press 0 : ";
					cin>>ch;
				
				}while(ch==1);
				
				// sending data to the file
				for(int i=0;i<counter;i++)
				{
					file<<s[i].name<<" ";    
			        file<<s[i].roll_no<<" ";    
					file<<s[i].monthly_income<<" ";
				}
				file.close();
			}
			
			
			//		update
			
			
			    if(opt=='b')
			   {
			   	char chk2;
			   	cout<<"\nPress N to update name or R to update rollno.  (N/R): ";
			 	cin>>chk2;
			  	if(chk2=='n'||chk2=='N')
			   	{
				   	int roln;
			  		cout<<"Enter the rollno. of student whose name is to be updated :\n ";
					cin>>roln;	        
					int q=0;             
					for(int i=0;i<counter;i++)
					{	
			    		if(s[i].roll_no==roln)
					  		{
					   			string nam;
					   			cout<<"enter the updated name of student :\n";
					   			cin>>nam;
					   			s[i].name=nam;
					   			q=1;
					  		}
					    }
						if(q==0)
							cout<<"\nRollno. not found.....";
						else
			  			{
							cout<<"\nUpdated list of students is:\n ";
				  			display();
						}
			
					}
					
					if (chk2=='r'||chk2=='R')
					{
						string na;
						cout<<"\n Enter the name of student whose Rollno. is to be updated :";
						cin>>na;
						for(int i=0;i<counter;i++)
						{	
							if(s[i].name==na)	    
					  		{
					   			int rol;
					   			cout<<"Enter new rollno. of student :\n";
					   			cin>>rol;
					   			s[i].roll_no=rol;	
					  		}
						}
						if(i==counter)
					  		cout<<"\nName not found.....";
					  	else
				  		{
							cout<<"\nUpdated list of students is:\n ";
				  			display();
						}		
					}
				}
				    
				    
			//    		delete
			
			
			    if(opt=='c')
			    {
			   		cout<<"\nEnter the Roll.no of student to be deleted : ";
			   		int rol;
				    cin>>rol;
			   		for(i=0;i<counter;i++)
				   	{
				   		if(s[i].roll_no==rol)
						break;
				    }
			   		if(i==counter)
			  	 		cout<<"Rollno.not found... \n";
			   		else
			   		{
				   		for(int j=i;j<counter;j++)
				   		{
				   		s[j].name=s[j+1].name;
				   		s[j].roll_no=s[j+1].roll_no;
				   		s[j].monthly_income=s[j+1].monthly_income;
						counter--;
			  			}
			    	cout<<"Remaining students :\n";
					display();
			   		}
				}
			   
			   
			   
			//   display
			
			
			
			 	if(opt=='d')
				{
			   		cout<<" All the students who have applied for scholarships are: \n";
			  		display(); 
				}
			    
				if(opt=='e')
			     {
			     	cout<<"\nExited from data-menue...";
			     	break;
				 }
				 cout<<"\n\t\t\t\tPress 1 to return to DATA-MENUE otherwise press 0:  ";
				 cin>>b;
			}while(b==1);
		}
		
	//	search
	
	
		if(option==2)
		{
			int chk,chk3;
			do
			{
				cout<<"\n\t\t\t\t SEARCH-MENUE\n";
				cout<<"\t\t\t\t ------------\n";
				cout<<"   Choose nmuber : \n\t1)>By Roll.no \n\t2)>By name\n\t3)>Exit  \n\n Your choice :\n";
				cin>>chk;
//				int a;
				if(chk==1)
				{
					cout<<"Enter Roll.no to search: \n";
					int id;
					cin>>id;
					for(int i=0;i<counter;i++)
					{	
						if(id==s[i].roll_no)
							break;
					}
					if(i==counter)
						cout<<"\n!!You have entered wrong Roll.no ";
					else
					{
						cout<<" Name)> "<<s[i].name<<"\n";
						cout<<" Monthly-income)> "<<s[i].monthly_income<<"\n\n";
					}
				}
		
				else if(chk==2)
				{
					cout<<"Enter a name of student you want to search :";
					string text;
					cin>>text;
					for( i=0;i<counter;i++)
					{
						if(s[i].name==text)	
							break;
					}
					if(i==counter)
						cout<<"\n!!You have entered wrong name ";
					else
						cout<<"\nStudent id)> "<<s[i].roll_no<<"\n"<<"Monthly income)>"<<s[i].monthly_income;
				}
				
				if(chk==3)
				{
					cout<<"\nExited from search-menue...";
					break;
				}
				cout<<"\n\t\t\t\tPress 1 to return to SEARCH-MENUE otherwise press 0:  ";
				cin>>chk3;
				
			}while(chk3==1);
		}
		
		
		
		//		Report
		
		
			if(option==3)
			{
				char opt3;
				cout<<"\nDo you wnat to check details about packages? (Y/N): ";
				cin>>opt3;
				if(opt3=='y'||opt3=='Y')
				{	
					cout<<"\n\nAnnouncement:\tEvery student whose monthly-income is less than 45000 will be given package accordingly.";
					cout<<"\n------------";
					int income1;
					int check1;
					do{
						cout<<"\nEnter your monthly-income :";
						cin>>income1;
						
						if(income1<=15000)
							cout<<"amount of scholarship will be : "<<45000-15000<<"\n";
		
						if(income1>15000&&income1<=25000)
							cout<<"amount of scholarship will be : "<<45000-20000<<"\n";
		 
						if(income1>25000&&income1<=35000)
		 					cout<<"amount of scholarship will be : "<<45000-30000<<"\n";
		 
						if(income1>35000&&income1<=40000)
							cout<<"amount of scholarship will be : "<<10000<<"\n\n";
		
						if(income1>40000)
							cout<<"no scholarship :\n";
		
						cout<<"\n\t\t\t\tpress 1 to check again otherwise 0: ";
						cin>>check1;
					}while(check1==1);
				}
		
		 
		 		cout<<"\t\t\t**********REPORT OF STUDENTS ON THE BASIS OF SCHOLARSHIP**********\n\n\n ";
		 		cout<<"Names\t\t\tAmount\n";
				cout<<" -----\t\t\t------\n";
		 
				for(int i=0;i<counter;i++)
				{
					if(s[i].monthly_income<=15000)
						cout<<" "<<s[i].name<<"\t\t:\t "<<45000-15000<<"\n";
			
					else if(s[i].monthly_income>15000&&s[i].monthly_income<=25000)
						cout<<""<<s[i].name<<"\t\t:\t  "<<45000-20000<<"\n";
				
					else if(s[i].monthly_income>25000&&s[i].monthly_income<=35000)
						cout<<" "<<s[i].name<<"\t\t:\t  "<<45000-30000<<"\n";
			
					else if(s[i].monthly_income>35000&&s[i].monthly_income<=45000)
						cout<<" "<<s[i].name<<"\t\t:\t  "<<10000<<"\n";
					
					if (s[i].monthly_income>45000)
						cout<<s[i].name<<"(^_^) \t\t\tNo scholarship"<<"\n";
		
				}
			}
			
			if(option==4)
			{
				cout<<"\n Exited from project...";
				break;
			}
	
			cout<<"\n\t\t\t\tPress 1 to return to MAIN-MENUE otherwise press 0:  ";
			cin>>b;
		}while(b!=0);
	}

void display()
{
	cout<<"\nNames\tRoll.numbers\tmonthly_income\n";
	cout<<"-----\t-------------\t--------------\n";
	for(int i=0;i<counter;i++)
   		cout<<s[i].name<<"\t"<<s[i].roll_no<<"\t\t"<<s[i].monthly_income<<"\n";  
}






