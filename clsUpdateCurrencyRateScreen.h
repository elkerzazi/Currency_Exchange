#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsString.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"


using namespace std;

class clsUpdateCurrencyRateScreen  : protected clsScreen
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

	static float _ReadRate()
	{
		cout << "\nEnter New Rate: ";
		float NewRate = 0;

		NewRate = clsInputValidate::ReadFloatNumber();
		return NewRate;
	}

public:

	static void ShowUpdateCurrencyRateScreen()
	{
		string Title = "\t Update Currency Screen";

		_DrawScreenHeader(Title);

		cout << "Please Enter Currency Code? ";
		string CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency Code is not found, choose another one? ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		_PrintCurrencyCard(Currency);

		char Answer = 'Y';
		cout << "\nAre you sure you want to Update the rate of this currency Y/N? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			cout << "\n Update Currency Card:\n";
			cout << "_______________________________________\n";

			Currency.UpdateRate(_ReadRate());

			cout << "\nCurrency Rate Updated is Successfully -:)\n";

			_PrintCurrencyCard(Currency);
		}
	}
};

