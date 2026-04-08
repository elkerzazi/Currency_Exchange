#pragma once
#include <iostream>
#include <string>
//#include "clsUser.h"
//#include "Global.h"
#include "clsDate.h"

using namespace std;

class clsScreen
{

protected:

	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
		cout << "\t\t\t\t\t______________________________________";
		cout << "\n\n\t\t\t\t\t  " << Title;

		if (SubTitle != "")
		{
			cout << "\n\n\t\t\t\t\t  " << SubTitle;
		}

		cout << "\n\t\t\t\t\t______________________________________\n\n";

		// --- Extension 1 Additions ---
		// Accessing CurrentUser and clsDate

		//cout << "\t\t\t\t\tUser: " << CurrentUser.UserName;
		cout << "\t\t\t\t\tDate: " << clsDate::DateToString(clsDate()) << "\n";
	}

};

