#pragma once

#include <iostream>
#include "clsCurrency.h"
#include "clsScreen.h"
#include <iomanip>
#include <vector>

using namespace std;

class clsCurrenciesListScreen : protected clsScreen
{

private:

	static void PrintCurrencyRecordLine(clsCurrency Currency)
	{
		cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
		cout << "| " << setw(8) << left << Currency.CurrencyCode();
		cout << "| " << setw(45) << left << Currency.CurrencyName();
		cout << "| " << setw(10) << left << Currency.Rate();
		cout << "|";
	}

public:

	static void ShowCurrenciesListScreen()
	{
		vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();

		string Title = "\t Currencies List Screen";

		string SubTitle = "\t (" + to_string(vCurrencies.size()) + ") Currency(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(8) << "Code";
		cout << "| " << left << setw(45) << "Name";
		cout << "| " << left << setw(10) << "Rate/(1$)";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;

		if (vCurrencies.size() == 0)
		{
			cout << "\t\t\tNo Clients Availabe In The System!";
		}
		else
		{
			for (clsCurrency& Currency : vCurrencies)
			{
				PrintCurrencyRecordLine(Currency);
				cout << endl;
			}
		}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;
	}

};

