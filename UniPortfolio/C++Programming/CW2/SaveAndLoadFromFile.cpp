/*
Programme: SaveAndLoadFromFile.cpp
Written by: Tim Binding
Written on: 09/12/2016
Description: A programme that takes input from a file called 'sales.txt', 
then after reading the file, it will output a simple graph onto a textfile 
called 'graph.txt' based on the input.
*/

#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>

#define LOADDATAFROMFILE
#define SAVEBARCHARTFILE

using namespace std;

class SaleData
{
private:
	ifstream inputfile;
	ofstream outputfile;
	vector<int> salesrecords;

public:
	void loadDataFromFile(string filename);
	void saveBarChartToFile(string filename);
};

void SaleData::loadDataFromFile(string filename)
{
	int record; 
	/*
    This is the variable used to store the inputted infomation to be used to 
    store the infomation into the vector.
	*/
	inputfile.open(filename);

	if (!inputfile) throw "'sales.txt' cannot be found"; 
    //If the data does not load correctly an error message will appear and say "'sales.txt' cannot be found"

	while (inputfile >> record)
	{
		salesrecords.push_back (record); 
        //Pushes everything into the 'salesrecords' vector that had been stored in the variable 'record'
    }
	inputfile.close(); //Closes the file that has been opened to avoid memory leaks
    /*
    The function 'loadDataFromFile' opens the 'sales.txt' file and then inputs everything to an integer 
	called 'record' then uses 'push_back' to store the data into the 'salesrecords' vector.
    */
}

void SaleData::saveBarChartToFile(string filename)
{
	outputfile.open(filename);
	
	if (!outputfile) throw "'graph.txt' cannot be found";

	outputfile << "		SALES BAR CHART" << endl;
	outputfile << "(each asterisk represents £100 of sales)" << endl;
	for (int loopInteger = 0; loopInteger < salesrecords.size(); loopInteger++)
	{
		outputfile << "Store " << loopInteger + 1 << ": "; 
		//Puts Store and a number that increases each time
	
		int numberOfAsterisk = salesrecords[loopInteger] / 100; 
		//Works out how many asterisks are needed as part of the graph
		
		for (int loopStore = 0; loopStore < numberOfAsterisk; loopStore++)
		{
			outputfile << "*";
			//Places the asterisks using a loop depending on how many asterisks are needed
		}
		outputfile << endl;
	}
	outputfile.close();
    /*
    The function 'saveBarChartToFile' outputs data from the 'sales.txt' 
    and creates a graph based on those numbers using asterisks.
	*/
}
void programme(void)
{
	SaleData filename;

	filename.loadDataFromFile("E:\\Computer Science year 1\\C++ Programming\\Assignments\\Assignment 2\\Programme 1\\sales.txt");
	filename.saveBarChartToFile("E:\\Computer Science year 1\\C++ Programming\\Assignments\\Assignment 2\\Programme 1\\graph.txt");

	/*
	The 'programme' function is used for the calling of all these functions so 
    they don't have to be put in the main.
    
	The two functions are checking the directory for their files so they can be loaded in.
	
    loadDataFromFile - read from sales
	saveBarChartToFile - Write to graph
	*/
}

int main()
{
	programme();
	cin.ignore();
	cin.get(); //Stops the screen from closing down.
	return 0;
}
