#pragma once
#include "clsCurrency.h"

class clsFindCurrencyScreen : protected clsScreen
{

private:

	enum enSeachForCurrencyOptions { Code = 1, Country = 2 };

	static short _ReadSearchOption() 
	{
		cout << "Find By [1]: Code Or [2]: Country ? " << endl;
		short Choice = clsInputValidate::ReadNumberBetween<short>(1, 2, "Find By [1]: Code Or [2]: Country ? ");
		return Choice;
	}

	static void _PrintCurrencyCard(clsCurrency Currency) 
	{
		cout << "\n____________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();
		cout << "\n____________________\n";
	}

	static void _showResults(clsCurrency Currency) 
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
		}
		else
		{
			cout << "\nCurrency Was not Found :-(\n";
		}
	}

	static void _FindCurrencyByCode() 
	{
		string CurrencyCode;

		cout << "\nPlease Enter Currency Code: ";
		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency Code is not found, choose another one: ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		_showResults(Currency);

		_PrintCurrencyCard(Currency);
	}

	static void _FindCurrencyByCountry() 
	{
		string CurrencyCountry;

		cout << "\nPlease Enter Currency Country: ";
		CurrencyCountry = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExistByCountry(CurrencyCountry))
		{
			cout << "\nCurrency Country is not found, choose another one: ";
			CurrencyCountry = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCountry(CurrencyCountry);

		_showResults(Currency);

		_PrintCurrencyCard(Currency);
	}


	static void _PerformSearchForCurrencyMenu(enSeachForCurrencyOptions Choice) 
	{
		switch (Choice) 
		{
		case enSeachForCurrencyOptions::Code:
		{
			_FindCurrencyByCode();
			break;
		}
		case enSeachForCurrencyOptions::Country:
		{
			_FindCurrencyByCountry();
			break;
		}
		}
	}

	static void _FindCurrencyMenu() 
	{
		cout << "Find Currency By: " << endl;
		cout << "[1] Currency Code." << endl;
		cout << "[2] Currency Country." << endl;

		_PerformSearchForCurrencyMenu((enSeachForCurrencyOptions)_ReadSearchOption());

	}



public:

	static void ShowFindCurrencyScreen() 
	{

		_DrawScreenHeader("\tFind Currency Screen");

		_FindCurrencyMenu();

	}

};

