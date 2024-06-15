#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
int main()
{
int a,b ;
int n;
int C;						//NATIONAL UNIVERSITY OF COMPUTER AND EMERGING SCIENCES 
string query;                                     //FAST-NUCES HELPLINE 
						
					//--------------------------------------------------------------//	
						cout<<"Welcome to FAST-NUCES!"<<endl;
						cout<<"......................."<<endl;
						cout<<"Press 1 for Islamabad campus"<<endl;
						cout<<"Press 2 for Lahore campus"<<endl;
						cout<<"Press 3 for Karachi campus"<<endl;
						cout<<"Press 4 for Peshawar campus"<<endl;
						cout<<"Press 5 for Faisalabad campus"<<endl;
						cin>>a;
						
			switch(a)			   //ISLAMABAD CAMPUS
			{
			case 1:
						cout<<"Welcome to Islamabad Campus of FAST NUCES"<<endl;
						cout<<"Press 1 for admission related queries."<<endl;
						cout<<"Press 2 for academics related queries."<<endl;
						cout<<"Press 3 for accounts and fees related queries."<<endl;
						cout<<"Press 4 for information technology related queries."<<endl;
						cout<<"Press 5 for sports related queries"<<endl;
						cout<<"Press 0 to talk to a representative"<<endl;
						cin>>b;
			switch(b)
			{
			case 1:
						cout<<"Press 1 for admission in school of computing"<<endl;                 //For admission in school of computing
						cout<<"Press 2 for admission in school of electrical engineering"<<endl;    //For admission in school of electrical engineering
						cout<<"Press 3 for admission in school of management sciences"<<endl;       //For admission in school of management science
		                               cin>>n;
		                               cout<<"Please enter your query:"<<endl;
						cin>>query;
						cout<<"Your query is registered. We will get back to you soon."<<endl;
						break;
						
			case 2:
						cout<<"Press 1 to apply for a degree/transcript generation "<<endl;   //Press1 
						cout<<"Press 2 to freeze your semester"<<endl;			//Prees 2
						cout<<"Press 3 to add/drop courses	"<<endl;			//Press 3
						cin>>n;
						cout<<"Please enter your query:"<<endl;
						cin>>query;								//Input query here
						cout<<"Your query is registered. We will get back to you soon."<<endl;
						break;
						
			case 3:
			 			cout<<"Press 1 for queries related to fee challan generation"<<endl; // press 1
						cout<<"Press 2 to apply for financial aid"<<endl;			//press 2
						cout<<"Press 3 apply for a scholarship"<<endl;			//press 3
						cin>>n;						
						cout<<"Please enter your query:"<<endl;
						cin>>query;								//Input query here
						cout<<"Your query is registered. We will get back to you soon."<<endl;
						break;
			case 4:		
						cout<<"Press 1 to apply for an email id generation"<<endl;           //press 1
						cout<<"Press 0 to talk to an IT expert"<<endl;                       //press 0
						cin>>n;
						if(n==1)                                                               //when (n=1) input query else not.
						{
						cout<<"Please enter your query:"<<endl;
						cin>>query;
						cout<<"Your query is registered. We will get back to you soon."<<endl;
						}
						else if(n==0)
						{
						cout<<"Please Wait"<<endl;
						}
						break;
						
			case 5:
					       cout<<"Press 1 to get a sports venue booked "<<endl;      //press 1
				               cout<<"Press 0 to talk to a representative "<<endl;       //press 0
				               cin>>n;				
				               if(n==1)
						{
						cout<<"Please enter your query:"<<endl;
						cin>>query;
						cout<<"Your query is registered. We will get back to you soon."<<endl;
						}
						else if(n==0)
						{
						cout<<"Please Wait"<<endl;
						}
						break;
				}
				break;
				
		  
		  
		                                  		  //LAHORE CAMPUS 
		                                    
		  	 case 2:               cout<<"Welcome to Lahore Campus of FAST NUCES"<<endl;
						cout<<"Press 1 for admission related queries."<<endl;
						cout<<"Press 2 for academics related queries."<<endl;
						cout<<"Press 3 for accounts and fees related queries."<<endl;
						cout<<"Press 4 for admission in school of civil engineering"<<endl;
						cout<<"Press 5 for admission in school of science and humanities"<<endl;
						cout<<"Press 0 to talk to a representative"<<endl;
						cin>>b;
		    switch(b)
		    {
		    
		    
		    case 1:
		    
						
						cout<<"Press 1 for admission in school of computing"<<endl;			//Admission in school of computing
						cout<<"Press 2 for admission in school of electrical engineering"<<endl;     //Admission in school of electrical engineering
						cout<<"Press 3 for admission in school of management sciences"<<endl;	//Admission in school of management sciences
						cout<<"Press 4 for admission in school of civil engineering"<<endl;		//Admission in school of civil engineering
						cout<<"Press 5 for admission in school of science and humanities"<<endl;	//Admission in school of science and humanities
						cin>>n;
						cout<<"Please enter your query:"<<endl;
						cin>>query;
						cout<<"Your query is registered. We will get back to you soon."<<endl;
						break;
						
		 case 2:
		                               cout<<"Press 1 to apply for a degree/transcript generation "<<endl; 		//press1
						cout<<"Press 2 to freeze your semester"<<endl;				//press2
						cout<<"Press 3 to add/drop courses	"<<endl;
						cin>>n;				
						cout<<"Please enter your query:"<<endl;
					        cin>>query;
					        cout<<"Your query is registered. We will get back to you soon."<<endl;
						 break;
				
						
						
				
		case 3:		
						cout<<"Press 1 for queries related to fee challan generation"<<endl;  
						cout<<"Press 2 to apply for financial aid"<<endl;
						cout<<"Press 3 apply for a scholarship"<<endl;
						cin>>n;
				               cout<<"Please enter your query:"<<endl;					//Input Your Query
					        cin>>query;
					        cout<<"Your query is registered. We will get back to you soon."<<endl;
						 break;
				
				
				
		case 4:	
					        cout<<" Press 1 to apply for an email id generation"<<endl;			//press 1
						cout<<"Press 0 to talk to an IT expert"<<endl;				//press 0
						cin>>n;
						if(n==1)
						{
						cout<<"Please enter your query:"<<endl;
						cin>>query;
						cout<<"Your query is registered. We will get back to you soon."<<endl;
						}
						else if(n==0)
						{
						cout<<"Please Wait"<<endl;
						}
						break;		
					       
				
				
				
		case 5:    
				   		cout<<"    Press 1 to get a sports venue booked "<<endl;                     //press1
					      cout<<"	Press 0 to talk to a representative  "<<endl;				//press 0
					      cin>>n;		
					      cout<<"Please enter your query:"<<endl;
						cin>>query;
						if(n==1)
						{
						cout<<"Please enter your query:"<<endl;
						cin>>query;
						cout<<"Your query is registered. We will get back to you soon."<<endl;
						}
						else if(n==0)
						{
						cout<<"Please Wait"<<endl;
						}
						break;
				
			}
			break;
				
				
	case 3:
								//KARACHI CAMPUS	
						cout<<"Welcome to KARACHI CAMPUS of FAST NUCES"<<endl;
						cout<<"Press 1 for admission related queries."<<endl;
						cout<<"Press 2 for academics related queries."<<endl;
						cout<<"Press 3 for accounts and fees related queries."<<endl;
						cout<<"Press 4 for information technology related queries."<<endl;
						cout<<"Press 5 for sports related queries"<<endl;
						cout<<"Press 0 to talk to a representative"<<endl;
						cin>>b;
						
		                 
		switch(b)
		{ 
		
				case 1:
				               cout<<"Press 1 for admission in school of computing"<<endl;			//Admission in school of management sciences
					        cout<<"Press 2 for admission in school of electrical engineering"<<endl;     //Admission in school of electrical engineering
						cout<<"Press 3 for admission in school of management sciences"<<endl;	//Admission in school of management sciences
						cin>>n;
				               cout<<"Please enter your query:"<<endl;
						cin>>query;
						cout<<"Your query is registered. We will get back to you soon."<<endl;
						break;
				case 2:
				               
				               cout<<"Press 1 to apply for a degree/transcript generation "<<endl;		//Press 1
						cout<<"Press 2 to freeze your semester"<<endl;				//Press 2
						cout<<"Press 3 to add/drop courses	"<<endl;				//Press 3
						cin>>n;
				               cout<<"Please enter your query:"<<endl;
						cin>>query;
						cout<<"Your query is registered. We will get back to you soon."<<endl;
						break;
				
				case 3:
				               cout<<"Press 1 for queries related to fee challan generation"<<endl;
						cout<<"Press 2 to apply for financial aid"<<endl;
						cout<<"Press 3 apply for a scholarship"<<endl;
						cin>>n;
						cout<<"Please enter your query:"<<endl;					//Input your query
						cin>>query;
						cout<<"Your query is registered. We will get back to you soon."<<endl;
						break;
						
				case 4:
						cout<<"Press 1 to apply for an email id generation"<<endl;	//Press 1
					        cout<<"Press 0 to talk to an IT expert"<<endl;		//Press 0
					        cin>>n;
					        if(n==1)
						{
						cout<<"Please enter your query:"<<endl;
						cin>>query;
						cout<<"Your query is registered. We will get back to you soon."<<endl;
						}
						else if(n==0)
						{
						cout<<"Please Wait"<<endl;
						}
						break;
				
					        
					        
					        
					        
				case 5:	
				               cout<<"    Press 1 to get a sports venue booked "<<endl;	//Press 1
				               cout<<"	Press 0 to talk to a representative  "<<endl;		//Press 0
				               
				               cin>>n; 
				               if(n==1)
						{
						cout<<"Please enter your query:"<<endl;
						cin>>query;
						cout<<"Your query is registered. We will get back to you soon."<<endl;
						}
						else if(n==0)
						{
						cout<<"Please Wait"<<endl;
						}
						break;
				}
				break; 	        		
				
				
				
				
				 			//PESHAWAR CAMPUS
		case 4:
					        cout<<"Welcome to PESHAWAR CAMPUS of FAST NUCES"<<endl;
						cout<<"Press 1 for admission related queries."<<endl;
						cout<<"Press 2 for academics related queries."<<endl;
						cout<<"Press 3 for accounts and fees related queries."<<endl;
						cout<<"Press 4 for information technology related queries."<<endl;
						cout<<"Press 5 for sports related queries"<<endl;
						cout<<"Press 0 to talk to a representative"<<endl;
						cin>>b;
				
		switch(b)
		{
		
		
		
		
		        case 1:
		                               cout<<"Press 1 for admission in school of computing"<<endl;			//Admission in school of computing
						cout<<"Press 2 for admission in school of electrical engineering"<<endl;	//Admission in school of electrical engineerin
						cout<<"Press 3 for admission in school of management sciences"<<endl;	//Admission in school of management science
						cin>>n;
						cout<<"Please enter your query:"<<endl;
						cin>>query;						
						cout<<"Your query is registered. We will get back to you soon."<<endl;
						break;
			case 2:
						
						cout<<"Press 1 to apply for a degree/transcript generation "<<endl;		//Press1
						cout<<"Press 2 to freeze your semester"<<endl;				//Press2
						cout<<"Press 3 to add/drop courses	"<<endl;				//Press3
						cin>>n;
						cout<<"Please enter your query:"<<endl;
						cin>>query;						
						cout<<"Your query is registered. We will get back to you soon."<<endl;
						break;
			case 3:
						cout<<"Press 1 for queries related to fee challan generation"<<endl;			//for queries
						cout<<"Press 2 to apply for financial aid"<<endl;					//apply for financial aid
						cout<<"Press 3 apply for a scholarship"<<endl;					//apply for financial aid
						cin>>n;
						cout<<"Please enter your query:"<<endl;
						cin>>query;						
						cout<<"Your query is registered. We will get back to you soon."<<endl;
						break;
			case 4:
						cout<<" Press 1 to apply for an email id generation"<<endl;			//press1
						cout<<"Press 0 to talk to an IT exper	"<<endl;				//press0
						cin>>n;
						if(n==1)
						{
						cout<<"Please enter your query:"<<endl;
						cin>>query;									//Input your query
						cout<<"Your query is registered. We will get back to you soon."<<endl;
						}
						else if(n==0)
						{
						cout<<"Please Wait"<<endl;
						}
						break;		
			
			
			
			
			
			case 5:
						cout<<"    Press 1 to get a sports venue booked "<<endl;			//press1
						cout<<"	Press 0 to talk to a representative  "<<endl;			//press0
						cin>>n;
						if(n==1)
						{
						cout<<"Please enter your query:"<<endl;
						cin>>query;
						cout<<"Your query is registered. We will get back to you soon."<<endl;
						}
						else if(n==0)
						{
						cout<<"Please Wait"<<endl;
						}
						break;		
			
			
			}
			break;									
				
				
				
			case 5:
					       		//FAISALABAD CAMPUS
					        cout<<"Welcome to Faisalabad Campus of FAST NUCES"<<endl;
						cout<<"Press 1 for admission related queries."<<endl;
						cout<<"Press 2 for academics related queries."<<endl;
						cout<<"Press 3 for accounts and fees related queries."<<endl;
						cout<<"Press 4 for admission in school of civil engineering"<<endl;
						cout<<"Press 5 for admission in school of science and humanities"<<endl;
						cout<<"Press 0 to talk to a representative"<<endl;
						cin>>b;
						 
				switch(b)
				{
				
				
				
				case 1:
					        cout<<"Press 1 for admission in school of computing"<<endl;			//admission in school of computing
						cout<<"Press 2 for admission in school of electrical engineering"<<endl;	//admission in school of electricalengineering
						cout<<"Press 3 for admission in school of management sciences"<<endl;	//admission in school of management sciences
						cout<<"Press 4 for admission in school of civil engineering"<<endl;		//admission in school of civil engineering
						cout<<"Press 5 for admission in school of science and humanities"<<endl;	//admission in school of science andhumanities
						cin>>n;
						cout<<"Please enter your query:"<<endl;
						cin>>query;
						cout<<"Your query is registered. We will get back to you soon."<<endl;
						break;
						
			     case 2:
						cout<<"Press 1 to apply for a degree/transcript generation "<<endl;		//press1
						cout<<"Press 2 to freeze your semester"<<endl;				//press2
						cout<<"Press 3 to add/drop courses	"<<endl;				//press3
						cin>>n;		       
					        cout<<"Please enter your query:"<<endl;
						cin>>query;
						cout<<"Your query is registered. We will get back to you soon."<<endl;
						break;
						
			    case 3:
						cout<<"Press 1 for queries related to fee challan generation"<<endl;		//press1
						cout<<"Press 2 to apply for financial aid"<<endl;				//press2
						cout<<"Press 3 apply for a scholarship"<<endl;				//press3
						cin>>n;
						 cout<<"Please enter your query:"<<endl;
						cin>>query;
						cout<<"Your query is registered. We will get back to you soon."<<endl;
						break;
			
			   case 4:
			   			cout<<"Press 1 to apply for an email id generation"<<endl;			
						cout<<"Press 0 to talk to an IT expert"<<endl;
						cin>>n;
						if(n==1)
						{
						cout<<"Please enter your query:"<<endl;
						cin>>query;									//Input your Query
						cout<<"Your query is registered. We will get back to you soon."<<endl;
						}
						else if(n==0)
						{
						cout<<"Please Wait"<<endl;
						}
						break;		
					
				
				
				
			   case 5:  
			   			 cout<<"Press 1 to get a sports venue booked "<<endl;			//Press1
				                 cout<<"Press 0 to talk to a representative  "<<endl;			//Press0
				                 cin>>n;
				                 if(n==1)
						{
						cout<<"Please enter your query:"<<endl;
						cin>>query;
						cout<<"Your query is registered. We will get back to you soon."<<endl;
						}
						else if(n==0)
						{
						cout<<"Please Wait"<<endl;
						}
						break;		
			}
			break;
			
									
				}
				return 0;
				}
