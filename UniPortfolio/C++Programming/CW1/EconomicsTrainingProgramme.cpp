/*
Programme: EconomicsTrainingProgramme.cpp
Written by: Tim Binding
Written on: 19/10/2016
Description: This is a stock programme design to calculate shares purchased and
sold then workout the profit.
*/

#include<iostream>
#include<string>
using namespace std;

/*
Display's the title and infomation that details
*/
void titleText(void)
{
	cout << "			Economics training programme\n\n"
	<< "Please enter the appropriate details of the trade when asked below" << endl << endl;
}

/*
The 'buyShareVal' function asks for user input and assigns those inputs to the variables
I have passed these values by reference because it will allow me to call them 
later for the other functions
*/
void buyShareVal(string& sharename, double& valueofsharebrought, double& buycommission, int& numberpurchased)
{
	cout << "Name of the share: ";
	getline(cin, sharename);

	cout << "Number of shares purchased: ";
	cin >> numberpurchased;
	
	cout << "Value per share purchased: ";
	cin >> valueofsharebrought;

	cout << "Percentage commission to be paid to the broker (expressed as decimal): ";
	cin >> buycommission;
	cout << endl << endl;
}

/*
The 'soldShareValues' function asks for user input and assigns those inputs to the variables
I have passed these values by reference because it will allow me to call them 
later for the other funictions
*/
void soldShareValues(double& valueofsharesold, double& salecommission, int& numbersold)
{
	cout << "Number of shares sold: ";
	cin >> numbersold;

	cout << "Value per share sold: ";
	cin >> valueofsharesold;

	cout << "Percentage commission to be paid to the broker (expressed as decimal): ";
	cin >> salecommission;
	cout << endl << endl;
}

/*
The 'displayResults' function shows the result onto the console, displays all of the infomation that was implemented
I used const because I don't want these values being changed
*/
void displayResults(const string sharename, const double valueofsharebrought, const double buycommission,
	const int numberpurchased, const double valueofsharesold, const double salecommission, const int numbersold)
{
	cout << "The share name = " << sharename 

		 << endl << "The value per share = "			<< valueofsharebrought 
		 << endl << "Percentage buy commission = "		<< buycommission 
		 << endl << "The number of shares purchased = " << numberpurchased 
		 << "\n\nTotal amount paid = "			        << numberpurchased * valueofsharebrought * (1 + buycommission)

		 << endl << "The value per share sold = "  << valueofsharesold 
		 << "\n\n% sale commission = "	           << salecommission 
		 << endl << "The number of shares sold = " << numbersold 
		 //amount sold multiplied by the value of the share multiply the sale commission take away 1
         << endl << "Total amount gained = "	   << numbersold * valueofsharesold * (1 - salecommission) 
         
         //total amount sold - commission to buy - price to buy - commission to sell
		 << endl << "The profit = " << numbersold - buycommission - valueofsharebrought - salecommission 
		 << endl << endl;
	system("pause");
}

/*
The 'ecoTrainingProgramme' calls all of the function for the programme and runs 
them to the console.
*/
void ecoTrainingProgramme(void)
{
	string sharename;
	double valueofsharebrought, valueofsharesold;
	double buycommission, salecommission;
	int numberpurchased, numbersold;
	
	titleText(); //Print the header
	buyShareVal(sharename, valueofsharebrought, buycommission, numberpurchased); 
    //Gets all of the infomation about buying the shares from the user

	soldShareValues(valueofsharesold, salecommission, numbersold); 
    //Gets all of the infomation about sold the shares from the user

	displayResults(sharename, valueofsharebrought, buycommission, numberpurchased, valueofsharesold, salecommission, numbersold);
	//Calculates the inputted infomation and displays the results
}

int main(void) //Entry point for programme
{
	ecoTrainingProgramme();
	cin.get();
	return 0;
}
