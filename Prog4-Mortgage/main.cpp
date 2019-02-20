// =====================================================
// Joseph Karch
// Due Feb. 20, 2019
// Programming Assignment #4
// Description: Mortgage
// =====================================================

#include<iostream>
#include"Mortgage.h"
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

bool parseInt(string sval, int& val);
bool parseDouble(string sval, double& val);


int main()
{
	Mortgage exampleMortgage;	// holds data from user input
	string input;				// string to hold input for validation
	int inputInt;				// input that is an int is returned here from validation function
	double inputDouble;			// input that is a double is returned here from validation function
	double holdsDouble;			// when the mortgage class returns the getPayment or getTotal it is stored here
	bool validInput;			// bool to switch on and off depending if the validation function says it is ok
	bool done = false;			// bool to switch on and off when you want to get out of the loop
	
	while (!done)
	{
		// ask for loan amount
		cout << "Mortgage calculator: " << endl;
		cout << "Input the total loan amount (minus the dollar sign): ";
		getline(cin, input);

		// validate input
		validInput = parseDouble(input, inputDouble);

		while (!validInput)
		{
			cout << "That was bad input. Try again." << endl;
			cout << " Input the total loan amount (minus the dollar sign): ";
			getline(cin, input);
			validInput = parseDouble(input, inputDouble);
		}

		// send input to be processed / stored in the class
		exampleMortgage.setLoan(inputDouble);

		// ask for interest rate input
		cout << "Input the interest rate as a decimal value: ";
		getline(cin, input);

		// validate interest rate
		validInput = parseDouble(input, inputDouble);

		while (!validInput)
		{
			cout << "That was bad input. Try again." << endl;
			cout << "Input the interest rate as a decimal value: ";
			getline(cin, input);
			validInput = parseDouble(input, inputDouble);
		}

		// send input to be processed / stored in the class
		exampleMortgage.setRate(inputDouble);


		// ask for length of loan in years
		cout << "Input the length of the loan in years: ";
		getline(cin, input);

		// validate input of the years
		validInput = parseInt(input, inputInt);

		while (!validInput)
		{
			cout << "That was bad input. Try again." << endl;
			cout << "Input the length of the loan in years: ";
			getline(cin, input);
			validInput = parseInt(input, inputInt);
		}

		// send input to be processed / stored in the class
		exampleMortgage.setYears(inputInt);

		// call for class functions to display the final output
		cout << endl;
		cout << endl;
		cout << "Mortgage payment info: " << endl;
		cout << "---------------------- " << endl;
		holdsDouble = exampleMortgage.getPayment();
		cout << "This is your monthly payment: $" << setprecision(2) << fixed << holdsDouble << endl;
		holdsDouble = exampleMortgage.getTotal();
		cout << "This is the total amount paid to the bank: $" << setprecision(2) << fixed << holdsDouble << endl;

		// end menu options and validation of input
		cout << "Would you like to exit? Press 1 to exit. Press any other key to continue: ";
		getline(cin, input);
		validInput = parseInt(input, inputInt);

		if (inputInt == 1)
		{
			done = true;
		}
	}
	
	return 0;
}

//= ==============================================================================
// parseDouble: send a function a string, convert string into double and pass back to variable 
// by reference, if the string isn't an int then return a false
// parameters: string and double
// return type: bool, reference variable(double)
//================================================================================
bool parseDouble(string sval, double& val)
{
	double num;
	bool success = true;
	try
	{
		num = stod(sval);   // or use stof for string-to-double
		val = num;
	}
	catch (const std::exception&)
	{
		success = false;
	}

	if (val < 0)
	{
		success = false;
	}

	return success;
}

//= ==============================================================================
// parseInt: send a function a string, convert string into integer and pass back to variable 
// by reference, if the string isn't an int then return a false
// parameters: string and int
// return type: bool and reference variable (int)
//================================================================================

bool parseInt(string sval, int& val)
{
	int num;
	bool success = true;
	try
	{
		num = stoi(sval);   // or use stof for string-to-float
		val = num;
	}
	catch (const std::exception&)
	{
		success = false;
	}

	if (val < 0)
	{
		success = false;
	}

	return success;
}
