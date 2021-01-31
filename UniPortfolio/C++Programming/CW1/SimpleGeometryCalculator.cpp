/*
Programme: SimpleGeometryCalculator.cpp
Written by: Tim Binding
Written on: 19/10/2016
Description: This is a programme that does geometry calculations 
such as calculations of the area of a circle, triangle and a rectangle
*/

#include <iostream> 
using namespace std; 

struct CalVaribles
{
      double num1, num2, area; 
	  //These are the variables that will be called in the other functions for calculation
};

/*
The 'onScreenMenu' function is responsible for displaying the menu to the console
'\n' Starts a new line when the programme is complied 
'\' Allows the continuation of the text on the line in the text editor
*/
void onScreenMenu(void)
{
     cout << "        Geometry Calculator \n\n\
1. Calculate the Area of a Circle \n\
2. Calculate the Area of a Rectangle \n\
3. Calculate the Area of a Triangle \n\
4. Quit \n\n\
Enter your choice (1-4):"  << endl;
}

/*
The 'calAreaCir' function's role is to calculate the area of a circle
The calculation that is required to do this is 'Pi R squared'
It prints the sum and area to the screen
num1 is radius
*/
void calAreaCir(CalVaribles cirVar) 
{
	const double PI = 3.141592653589793238462643383279502884197;
	/*
	Originally the PI variable was assigned to 3.14 but decided to change it after
	testing the calculation the answer that was displaying was inaccurate
	*/
    
	cirVar.area = PI * (cirVar.num1 * cirVar.num1); //area = Pi x (radius x radius)
    
	cout << PI << " x " << "(" << cirVar.num1 << " x " << cirVar.num1 << ") = " << cirVar.area
		 << "\n\nThe area of the circle is " << cirVar.area << "." << endl;
		 //Display the output to the console the area of a circle
}

/*
The 'calAreaRec' function does the calculation of the area of a rectangle by 
multiplying width and length together
It prints the sum and result to the screen
*/
void calAreaRec(CalVaribles recVar)
{
	recVar.area = recVar.num1 * recVar.num2; //area = length x width 
    
	cout << recVar.num1 << " x " << recVar.num2 << " = " << recVar.area
		 << "\n\nThe area of the rectangle is: " << recVar.area << "." << endl << endl;
		 //Display the output to the console the area of a rectangle
}

/*
The 'calAreaTri' function is responsible for the calculation of the area of a triangle
It prints the base multiplied by the height and the result to the screen
*/
void calAreaTri(CalVaribles triVar)
{
	triVar.area = (triVar.num1 * triVar.num2) / 2; //area = (base x height) / 2
    
	cout << triVar.num1 << " x " << triVar.num2 << " / 2 = " << triVar.area
		 << "\n\nThe area of the triangle is: " << triVar.area << "." << endl; 
		 //Display the output to the console the area of a triangle
}

/* 
The 'runGeoCalProgramme' function sorts through the choices and calls the 
functions depending on the choices inputted
 
*/
void runGeoCalProgramme(void) 
{
	int choice = 0;
	CalVaribles geoCalVar;

	while (true) //This loop will continue indefinitely
	{
		onScreenMenu(); //Calls the function that regards displaying text
		cin >> choice; //Asks user for the choice

		cout << endl;

		if (choice > 0 && choice < 4)
			/*
			This if statement asks: if the choice that the user has chosen to input into the console
			is greater than 0 and is less than 4 then it can continue with the code in the brackets 
			*/
		{
			switch (choice)
			{
			case 1: 
				cout << endl << "Enter the radius of the circle: ";
				cin >> geoCalVar.num1;
				calAreaCir(geoCalVar); 
				break;

			case 2: 
				cout << endl << "Enter the length: ";
				cin >> geoCalVar.num1;
				cout << endl << "Enter the width: ";
				cin >> geoCalVar.num2; //Get two choices from user for calculation
				calAreaRec(geoCalVar); 
				break;

			case 3: 
				cout << endl << "Enter the base: ";
				cin >> geoCalVar.num1;
				cout << endl << "Enter the height: ";
				cin >> geoCalVar.num2; 
				calAreaTri(geoCalVar); 
				break;
			/*
			The three choices will be picked depending on the three possible 
			numbers that were inputted then a function will be called so that 
			*/
			} 
			cout << endl;
		}
		else if (choice == 4) //If the user has inputted number four into the console
		{
			cout << "This programme will now end..." << endl;
			break; 
			/*
            The 'break' event causes the programme to end and the line above 
            it will bring up a message to display before it ends
            */
		}
		else cout << "Please only enter a number between 1 - 4 " << endl << endl;
		//Message appears to tell user to enter a correct number
	}
}

int main(void) //Entry point for programme
{
	runGeoCalProgramme();
	return 0;
}
