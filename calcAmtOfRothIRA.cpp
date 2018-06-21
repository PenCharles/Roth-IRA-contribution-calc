#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>				
#include <cmath>				
#include <string>
using namespace std;

	//Author: James Saylor
	//Description : Program asks user a set of basic questions to determine the
	//maximum amount of money that can be invested in a ROTH IRA.

//constants
const int UNDER_FIFTY = 50;
const double SINGLE_HOH = 112000;
const double JOINT_WIDOW = 178000;
const double SEPERATE = 0;
const double LOW_DIVISION = 10000;
const double HIGH_DIVISION = 15000;
const double YOUNG_MAX = 5500;
const double OLD_MAX = 6500;
const string SINGLE = "Single";
const string MARRIED_FILING_JOINTLY = "Married, Filing Jointly";
const string HEAD_OF_HOUSEHOLD = "Head of Household";
const string QUALIFYING_WIDOWER = "Qualifying Widow(er)";
const string MARRIED_FILING_SEPERATELY = "Married, Filing Seperately";

//function
double ReducedContribution(double num1, double num2)
{
	double contributionLimit;
	
	contributionLimit = num1 - num2;
	contributionLimit = ceil(contributionLimit / 10) * 10;
	
	return contributionLimit;
}

int main ()
{
	//variables
	string livingAns;
	string filingStatus;
	int status;
	int age;
	double maxContribution;
	double grossIncome;
	double incomeLimit;
	double reducedAmount;
	double reductionAmount;
	double divisionAmount;
	double reductionPercentage;
	double contributionLimit;
	
	//output
	cout << showpoint << fixed << setprecision(2);
	cout << "Roth IRA Contribution Limit Worksheet Program" << endl << endl;
	cout << "1 - Single" << endl;
	cout << "2 - Married, Filing Jointly" << endl;
	cout << "3 - Head of Household" << endl;
	cout << "4 - Qualifying Widow(er)" << endl;
	cout << "5 - Married, Filing Separately" << endl;
	cout << "Enter your filing status from above (1-5): ";
	cin >> status;
	cout << endl;
	if(status == 5)
	{
		cout << "Have you lived with your spouse at any time during the year? ";
		cin >> livingAns;
		cout << endl;
		if(livingAns == "no")
		{
			cout << "Taxpayer may not contribute to a ROTH IRA." << endl;
			return 1;
		}
	}
	
	cout << "Enter your age: ";
	cin >> age;
	cout << endl;
	
	if(age < UNDER_FIFTY)
	{
		maxContribution = YOUNG_MAX;
	}
	else
	{
		maxContribution = OLD_MAX;
	}
	
	cout << "Enter Adjusted Gross Income for IRA purposes: ";
	cin >> grossIncome;
	cout << endl;
	
	if(status == 1 || status == 3)
	{
		incomeLimit = SINGLE_HOH;
		if(status < 3)
		{
			filingStatus = SINGLE;
		}
		else
		{
			filingStatus = HEAD_OF_HOUSEHOLD;
		}
	}
	else if(status == 2 || status == 4)
	{
		incomeLimit = JOINT_WIDOW;
		if(status < 4)
		{
			filingStatus = MARRIED_FILING_JOINTLY;
		}
		else
		{
			filingStatus = QUALIFYING_WIDOWER;
		}
	}
	else
	{
		incomeLimit = SEPERATE;
		filingStatus = MARRIED_FILING_SEPERATELY;
	}

cout << "ROTH IRA Contribution Limit Worksheet" << endl << endl;
cout << "   Filing Status:" << setw(49) << filingStatus << endl << endl;
cout << "1. Possible contribution Limit:" << setw(20) << maxContribution << endl << endl;
cout << "2. Adjusted Gross Income:" << setw(41) << grossIncome << endl;
cout << "3. Income Limit:" << setw(50) << incomeLimit << endl;

if(grossIncome <= incomeLimit)
{
	cout << endl << "9. Maximum ROTH IRA Contribution Limit:" << setw(27) << maxContribution << endl;
	return 4;
}
else
{
	reducedAmount = grossIncome - incomeLimit;
	cout << "4. Amount over Limit:" << setw(45) << reducedAmount << endl << endl;
}

if(filingStatus == SINGLE || filingStatus == HEAD_OF_HOUSEHOLD)
{
	cout << "5. Division amount:" << setw(32) << HIGH_DIVISION << endl;
	divisionAmount = HIGH_DIVISION;
}
else
{
	cout << "5. Division amount:" << setw(32) << LOW_DIVISION << endl;
	divisionAmount = LOW_DIVISION;
}

reductionPercentage = reducedAmount / divisionAmount;
if(reductionPercentage >= 1.0)
{
	cout << endl << "   Income too high - You cannot contribute to a ROTH IRA!" << endl;
	cout << endl << "9. Maximum ROTH IRA Contribution Limit:" << setw(27) << 0 << endl;
	return 6;
}
else
{
	cout << showpoint << fixed << setprecision(3);
	cout << "6. Reduction Percentage:" << setw(27) << reductionPercentage << endl;
}

cout << showpoint << fixed << setprecision(2);
reductionAmount = maxContribution * reductionPercentage;
cout << "7. Reduction Amount:" << setw(31) << reductionAmount << endl;

contributionLimit = ReducedContribution(maxContribution, reductionAmount);
cout << "8. Reduced Contribution Limit:" << setw(21) << contributionLimit << endl << endl;

if(contributionLimit > 200)
{
	cout << "9. Maximum ROTH IRA Contribution Limit:" << setw(27) << contributionLimit << endl;
}
else
{
	cout << "9. Maximum ROTH IRA Contribution Limit:" << setw(27) << 200 << endl;
}


 	cout << endl << endl;
 	return 0;
}

