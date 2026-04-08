#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsCurrenciesListScreen.h"

using namespace std;

class clsMainScreen : protected clsScreen
{

private:

	enum enCurrenciesMainMenueOptions {
		eListCurrencies = 1, eFindCurrency = 2, eUpdateCurrencyRate = 3,
		eCurrencyCalculator = 4, eExit = 5
	};

	static short _ReadMainMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number Between 1 to 5 ? ");
		return Choice;
	}

	static void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowMainMenue();
	}

	static void _ShowCurrenciesListScreen()
	{
		//cout << "\nCurrencies List Screen Will be here...\n";
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
		
	}

	static void _ShowFindCurrencyScreen()
	{
		cout << "\nFind Currency Screen Will be here...\n";
		
	}

	static void _ShowUpdateRateScreen()
	{
		cout << "\nUpdate Rate Screen Will be here...\n";
	}

	static void _ShowCurrencyCalculator()
	{
		cout << "\nCurrency Calculator Screen Will be here...\n";
	}

	static void _Logout()
	{
		//cout << "\nEnd Screen Will be here...\n";

	}

	static void _PerfromCurrenciesMainMenueOption(enCurrenciesMainMenueOptions CurrenciesMainMenueOption)
	{
		switch (CurrenciesMainMenueOption)
		{
		case enCurrenciesMainMenueOptions::eListCurrencies:
		{
			system("cls");
			_ShowCurrenciesListScreen();
			_GoBackToMainMenue();
			break;
		}
		case enCurrenciesMainMenueOptions::eFindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToMainMenue();
			break;
		}
		case enCurrenciesMainMenueOptions::eUpdateCurrencyRate:
		{
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToMainMenue();
			break;
		}
		case enCurrenciesMainMenueOptions::eCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculator();
			_GoBackToMainMenue();
			break;
		}
		case enCurrenciesMainMenueOptions::eExit:
		{
			system("cls");
			_Logout();
			break;
		}
		}
	}

public:

	static void ShowMainMenue()
	{
		system("cls");
		_DrawScreenHeader("Main Screen of Currency Exchange");

		cout << setw(37) << left << "" << "===========================================\n\n";
		cout << setw(37) << left << "" << "\t\tCurrency Exchange Menue\n\n";
		cout << setw(37) << left << "" << "===========================================\n\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Logout.\n\n";
		cout << setw(37) << left << "" << "===========================================\n\n";

		_PerfromCurrenciesMainMenueOption((enCurrenciesMainMenueOptions)_ReadMainMenueOption());

	}

};

