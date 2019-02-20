// implementation file for Mortgage class

#include<iostream>
#include"Mortgage.h"
#include<cmath>
#include <iomanip>
#include <string>

using namespace std;

Mortgage::Mortgage()
{
	payment = 0.0;
	loan = 0.0;
	rate = 0.0;
	term = 0.0;
	years = 0;
	total = 0;
}
void Mortgage::calculatePayment()
{
	payment = (loan * (rate / 12.0) * term) / (term - 1);
}

void Mortgage::calculateTerm()
{
	term = pow((1 + (rate / 12)), (12 * years));
}

void Mortgage::calculateTotal()
{
	total = payment * 12 * years;
}

void Mortgage::setLoan(double loanAmount)
{
	loan = loanAmount;
	calculateTerm();
	calculatePayment();
	calculateTotal();
}

void Mortgage::setRate(double rateAmount)
{
	rate = rateAmount;
	calculateTerm();
	calculatePayment();
	calculateTotal();
}

void Mortgage::setYears(int yearsAmount)
{
	years = yearsAmount;
	calculateTerm();
	calculatePayment();
	calculateTotal();
}

double Mortgage::getPayment()
{
	return payment;
}

double Mortgage::getTotal()
{
	return total;
}