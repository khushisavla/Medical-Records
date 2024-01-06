/*
Author: Khushi Savla
*/
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include <vector>

using namespace std;

class person
{
	private:
		string name, doctor = "no doctor", password;
		int age = 0;
		bool password_set = false, records_bool = false;
	public:
		class condition
		{
			
			public:	
				string Cname, treatment, medication;
				int severity;	
			
		
				condition()
				{
					Cname = "no condition";
					severity  = 0;
				}
				condition(string Cname1, int severity1, string treatment1, string medication1)
				{
					Cname = Cname1;
					severity = severity1;
					treatment = treatment1;
					medication = medication1;
				}
		};
		class Node {
  			public:
    			condition value;
    			Node* next_node;

    		Node(condition initial_value) 
			{
      		value = initial_value;
      		next_node = nullptr;
    		}
		};

		Node* conditions_head  = nullptr;
		person()
		{
			name = "no name";
			doctor = "no doctor assigned";
			age = 0;
			condition set();
			//add the thing
		}
		
		person(string name1, int age1)
		{
			name =  name1;
			age  = age1;
		}
		void add_doctor(string doctor1)
		{
			doctor = doctor1;
		}
		string get_name()
		{
			return name;
		}
		void add_record(string name, int severity1, string treatment1, string medication1 )
		{
			condition new_condition(name, severity1, treatment1, medication1);
			Node* new_node = new Node(new_condition);
			new_node -> next_node = conditions_head;
			conditions_head = new_node;
		}
		
		void output(ofstream &fout)
		{
 			Node* current_node = conditions_head;
  			while( current_node != nullptr)
  			{
    			cout<< "name: " << current_node -> value.Cname << endl << "Severity: " << current_node -> value.severity<< endl 
					<<"Treatment: "<<current_node -> value.treatment << endl<< "Medication: " << current_node -> value.medication;
    			current_node = current_node-> next_node;
 				 
			}
		}
		bool allow(string password1)
		{
			if(password1== password)
			{
				return true;
			}
			
			return false;
		}
		void change_password()
		{
				if(password_set == true)
				{	int continue_attempts = 1;
					bool works = false;
					do
					{
					if (continue_attempts > 1)
					{
						cout<< "incorrect password, please retry" << endl;
					}
					else if(continue_attempts ==3)
					{
						cout<< "too many failed attempts, please try again later";
						return;
					}
					
					cout<< "Please Enter Password: ";
					string password1;
					cin >> password1;
					cout<<endl;
					if(password1 == password)
					{
						works == true;
					}
					continue_attempts ++;
				}while(works == false && continue_attempts <= 3);
				}
				
				string password1, confirm;
				bool works_new = false;
				int inform = 0;
				
				do
				{
					if (inform > 0)
					{
						cout<<"Passwords do not match, please retry" << endl;
					}
					
					cout<< "Please Enter Password: ";
					cin >> password1;
					cout<<"Confirm Password: ";
					cin >> confirm;
					cout<<endl;
					if(password1 == confirm)
					{
						works_new = true;
					}
					inform ++;
				}while(works_new == false);
				password = password1;
				password_set = true;
				cout << "password set"<<endl;
				return;
			
		}		
};
//completed an excerise on  strcuty.com and applied it for syntax in this program
class Node {
  public:
    person value;
    Node* next_node;

    Node(person initial_value) {
      value = initial_value;
      next_node = nullptr;
    }
};
person find_value(Node* head, string target_value) {
  // todo
  Node* current_node = head;
  while( current_node != nullptr)
  {
    if(current_node-> value.get_name() == target_value)
    {
      return current_node -> value;
    }
    current_node = current_node-> next_node;
  }
  
  person no_exist("does not exist", 0);
  return no_exist;
}

int main()
{
	//linked lists for different cities
	Node* calgary_head = nullptr;
	string password_calgary = "calg";
	Node* fortmac_head = nullptr;
	string password_fortmac = "mcMoney";
	Node* edmonton_head = nullptr;
	string password_edmonton = "tonmon";
	
	//where program interacts with user
	string response = "Yes";
	string city;
	do
	{
		//choosing and accessing city
		bool correct = false;
		int attempt_num = 1;
		do{ 
		cout<< "please enter city: ";
		cin>> city;
		cout<< "Please enter password ("<< attempt_num << "): ";
		string attempt;
		cin>> attempt;
		//choosing action 
		if(city == "Calgary" && attempt == password_calgary)
		{
			correct =true;
		}
		else if(city == "Fort McMurray" && attempt == password_fortmac)
		{
			correct = true;
		}
		else if(city == "Edmonton" && attempt == password_edmonton)
		{
			correct = true;
		}
		else if(attempt_num == 3)
		{
			cout << "Too many failed attempts" << endl;
			//release data
			return EXIT_FAILURE;
		}
		else
		{
			cout<< "city does not exist/incorrect password"<< endl<<endl;
		}
		attempt_num++;
		//need the attempt
		}while(correct == false && attempt_num <=3);
		
		cout<< endl << "Welcome" << endl << "Are you registering a new patient or working with an exisiting patient"<< endl;
		string action;
		cin >> action;
		
		if(action == "new")
		{
			cout << "Please enter name and age:" << endl << "Name: ";
			string name;
			int age = 0;
			cin>> name;
			cout<< "Age: ";
			cin >> age;
			person new_person(name, age);
			cout<< endl << endl << "Hello, " << name<<endl;
			new_person.change_password();
			
			//if statements for city
			if (city == "Calgary")
			{
				Node* new_node = new Node(new_person);
				new_node -> next_node = calgary_head;
				calgary_head = new_node;
			}
			else if(city == "Fort McMurray")
			{
				Node* new_node = new Node(new_person);
				new_node -> next_node = fortmac_head;
				fortmac_head = new_node;
			}
			else
			{
				Node* new_node = new Node(new_person);
				new_node -> next_node = edmonton_head;
				edmonton_head = new_node;
			}
		}
		else if(action == "existing")
		{
			cout<< "please enter patient name: ";
			string user_name;
			cin >> user_name;
			person exist;
			
			if (city == "Calgary")
			{
				exist = find_value(calgary_head, user_name);
			}
			else if(city == "Fort McMurray")
			{
				exist = find_value(fortmac_head, user_name);
			}
			else
			{
				exist = find_value(edmonton_head, user_name);
			}
			bool exist_bool = true;
			if (exist.get_name() == "does not exist")
			{
				exist_bool = false;
			}
			if (exist_bool)
			{
				cout<< "Enter password: "<< endl;
				string password_enter;
				cin >> password_enter;
				bool allowed = exist.allow(password_enter);
				if(allowed)
				{
					cout<<"which action would you like to proceed with: "<< endl;
					string action_exist;
					cin >> action_exist;
					cout<<endl;
				
					if(action_exist == "change_password")
					{
						exist.change_password();
					}
					else if(action_exist == "add_record")
					{
						string condition1, treatment, medication;
						int severity;
						cout<<endl<<"please enter condition: ";
						cin >> condition1;
						cout<<"please enter severity: ";
						cin >> severity;
						cout<<"please enter treatment: ";
						cin >> treatment;
						cout<<"please enter prescribed medication: ";
						cin >> medication;
						exist.add_record(condition1, severity, treatment, medication);
					}
					else if(action_exist == "print_records")
					{
						ofstream fout("report.txt");
						exist.output(fout);
						fout.close();
					}
					else if(action_exist == "add_doctor")
					{
						cout<< "please enter doctor name: ";
						string doctor;
						cin >> doctor;
						exist.add_doctor(doctor);
					}
					else
					{
						cout<< "action does not exist" << endl << "please try again"<<endl;
					}
				}
				else
				{
					cout<<"incorrect password";
				}
			}
			else
			{
				cout<< "user does not exist"<< endl<< "please ensure there are no typing mistakes or register the new patient"<< endl;
			}
		
			
		}
		else
		{
			cout<< "action does not exist"<< endl;
		}
		
		cout<< endl;
		cout<< "Would you like to continue using the system?"<< endl << "Response: ";
		cin>> response;
		cout<<endl;
	}while(response == "Yes" || response == "yes");
	cout << "Thank you";
	return EXIT_SUCCESS;
}

