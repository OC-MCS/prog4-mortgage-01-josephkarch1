#pragma once
// header file for Mortgage class

class Mortgage
{
	private:
		double payment;
		double loan;
		double rate;
		double term;
		double total;
		int years;
		void calculatePayment();
		void calculateTerm();
		void calculateTotal();

	public:
		Mortgage();
		void setLoan(double loanAmount);
		void setRate(double rateAmount);
		void setYears(int yearsAmount);
		double getPayment();
		double getTotal();
};
