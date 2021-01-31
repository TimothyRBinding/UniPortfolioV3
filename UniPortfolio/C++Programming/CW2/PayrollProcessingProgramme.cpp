/*
Programme: PayrollProcessingProgramme.cpp
Written by: Tim Binding
Written on: 14/12/2016
Description: This programme gathers data from three text files, then loads 
them into a function that sorts by people with salary higher than the one 
that was inputted. The programme then displays the name, address, 
department, salary to the screen.
*/

#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

class OrganisationRecord
{
private:

public:
	string name;
	string occupation;
	string department;
};

class HRRecord
{
private:

public:
	string address;
	string phonenumber;
	string ninumber;
};

class PayrollRecord
{
private:

public:
	string ninumber;
	double salary;
};

class PayrollProcessing
{
private:
	ifstream inputfile;
	ofstream outputfile;
	vector<OrganisationRecord> OrganisationRecords;
	vector<HRRecord> HRRecords;
	vector<PayrollRecord> PayrollRecords;
public:
	void loadOrganisationRecords(string filename);
	void loadHRRecords(string filename);
	void loadPayrollRecords(string filename);
	void displayEmployeeOfSalaryGTE(double salary);
};

void PayrollProcessing::loadOrganisationRecords(string filename)
{
	string employeenumber;
	OrganisationRecord newOrganRecords; //New Organistation record

    inputfile.open(filename);

	if (!inputfile) throw "'organisation.txt' cannot be found";
     	
	while (getline(inputfile, employeenumber))
    {
		getline(inputfile, newOrganRecords.name);
		getline(inputfile, newOrganRecords.occupation);
		getline(inputfile, newOrganRecords.department);
		/*
        In this section I used 'getline (inputfile, newOrganRecords.name)' instead 
        of the standard 'inputfile >> newOrganRecords.name' because as it would 
        not show the entire input when displayed on the screen.
        */

		OrganisationRecords.push_back(newOrganRecords);
		//Puts the infomation from newOrganRecords and puts it in the vector 
        //'OrganisationRecords'
    }
    inputfile.close();
	/*
	The function 'loadOrganisationRecords' loads in data from 'organisation.txt' 
    and stores it in newOrganRecords then uses the push_back method to store 
    that data into the vector newOrganRecords using a while loop. If the file 
    can't be found then it will use the 'throw' statement and display some text 
    explaining the problem.
	*/
}

void PayrollProcessing::loadHRRecords(string filename)
{
	string employeenumber;
	HRRecord newHRRecords; //New Human Resource Records 
     
	inputfile.open(filename);

	if (!inputfile) throw "'hr.txt' cannot be found";
     	
	while (getline(inputfile, employeenumber))
	{
		getline(inputfile, newHRRecords.address);
		inputfile >> newHRRecords.phonenumber;
		inputfile >> newHRRecords.ninumber;
		/*
		I used the stardard input file method here in this section as they 
        consists of only one line and no spaces.
        */
		HRRecords.push_back(newHRRecords);
    }
    inputfile.close();
	/*
	The function 'loadHRRecords' loads in data from 'hr.txt' and stores it in 
    newHRRecords then uses the push_back method to put that data into the 
    vector HRRecords using a while loop.
	*/
}

void PayrollProcessing::loadPayrollRecords(string filename)
{
	int employeenumber; 
	PayrollRecord newPayrollRecords; //New Payroll Records
    
    inputfile.open(filename);

    if (!inputfile) throw "'payroll.txt' cannot be found";
     	
    while (inputfile >> employeenumber)
    {
		inputfile >> newPayrollRecords.ninumber;
		inputfile >> newPayrollRecords.salary;
        
		PayrollRecords.push_back(newPayrollRecords);
    }
    inputfile.close();
	/*
	The function 'loadPayrollRecords' loads in data from 'payroll.txt' and stores it in newPayrollRecords  
	then uses the push_back method to put that data into the vector newPayrollRecords using a while loop.
	*/
}

void PayrollProcessing::displayEmployeeOfSalaryGTE(double salary)
{
	for (int loopInteger = 0; loopInteger < OrganisationRecords.size(); loopInteger++)
	{
		if (salary <= PayrollRecords[loopInteger].salary) 
		{
			cout << "Name: " << OrganisationRecords[loopInteger].name << endl;
			cout << "Address: " << HRRecords[loopInteger].address << endl;
			cout << "Department: " << OrganisationRecords[loopInteger].department << endl;
			cout << "Salary: " << PayrollRecords[loopInteger].salary << endl;
			cout << endl;
		}
	}
	/*
	The for loop will loop through the code depending on how much is in the 
    'OrganisationRecords' vector. The programme will then check within 'PayrollRecord' 
	for the amount salary using an if statement to check through the salary to find 
	the ones containing more than the inputted amount.
	*/
}

void displayToScreen(void)
{
	cout << "		Logistics Ltd employee record" << endl;
	cout << "This programme allows you to sort through a record of employees and" << endl;
	cout << "find the salary larger than the inputted number." << endl << endl;
	cout << "Employees whose salary is greater than: ";
	/*
	This is the display screen that puts text to the screen, the text consists 
    of a title then a description of the programme.
	*/
}

void programme(void)
{
	double salary;
	PayrollProcessing filename;

	displayToScreen();
	cin >> salary;
	cout << endl; 
	/*
	'cout << endl;' Creates a new line so that the text on this line does not get bunched 
    up together, for the user this divides the first part of the text with text about the 
	employees whose salary is greater than the inputted amount.
	*/

	filename.loadOrganisationRecords("E:\\Computer Science year 1\\C++ Programming\\Assignments\\Assignment 2\\Programme 2\\organisation.txt");
	filename.loadHRRecords("E:\\Computer Science year 1\\C++ Programming\\Assignments\\Assignment 2\\Programme 2\\hr.txt");
	filename.loadPayrollRecords("E:\\Computer Science year 1\\C++ Programming\\Assignments\\Assignment 2\\Programme 2\\payroll.txt");

	filename.displayEmployeeOfSalaryGTE(salary);

	/*
	The function called programme is where all of function calls are placed, 
    this also where the user is prompted for input so it doesn't need to be in 
    the main. It is important that the user is prompt for input after display 
    screen function so that it would both be on the same line and be able to be 
    assigned and used later in the function.
	*/
}

int main()
{
	programme();
	cin.ignore();
	cin.get(); //Stops the screen from closing down when salary is entered
	return 0;
}
