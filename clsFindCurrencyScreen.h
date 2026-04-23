#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"

using namespace std;

class clsFindCurrencyScreen : protected clsScreen
{

private:

	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		
		cout << "\nCurrency Card:\n";
		cout << "_______________________________________\n";
		cout << "Country      : " << Currency.Country() << endl;
		cout << "Currency Code: " << Currency.CurrencyCode() << endl;
		cout << "Currency Name: " << Currency.CurrencyName() << endl;
		cout << "Rate/(1$)    : " << Currency.Rate() << endl;
		cout << "_______________________________________\n";
	}

	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found\n";
			_PrintCurrencyCard(Currency);
		}
		else
		{
			cout << "\nCurrency Was not found in the system\n";
		}
	}


public:

	static void ShowFindCurrencyScreen()
	{
		string Title = "\t Find Currency Screen";

		_DrawScreenHeader(Title);

		cout << "Find By: [1] Code or [2] Country ? ";

		short Choice = clsInputValidate::ReadIntNumberBetween(1, 2);

		if (Choice == 1)
		{
			cout << "\nPlease Enter CurrencyCode: ";
			string CurrencyCode = clsInputValidate::ReadString();

			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

			_ShowResults(Currency);
		}
		else
		{
			cout << "\nPlease Enter CountryName: ";
			string CountryName = clsInputValidate::ReadString();

			clsCurrency Currency = clsCurrency::FindByCountry(CountryName);

			_ShowResults(Currency);
		}
		


		

	}
};

