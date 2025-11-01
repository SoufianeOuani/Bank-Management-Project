#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsCurrencyCalculatorScreen : protected clsScreen
{

private:

	static void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Card:")
	{
		cout << "\n" << Title << "\n";
		cout << "\n____________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();
		cout << "\n____________________\n";
	}

	static float _ReadAmount()
	{
		cout << "\nEnter Amount To Exchange: ";
		float Amount = 0;

		Amount = clsInputValidate::ReadNumber<float>();
		return Amount;
	}

	static clsCurrency _GetCurrency(string Message) 
	{
		string CurrencyCode;

		cout << Message << endl;
		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode)) 
		{
			cout << "\nCurrency is not found, choose another one: ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return Currency;
	}

	static void _PrintCalculationsResults(float Amount, clsCurrency Currency1, clsCurrency Currency2) 
	{
		_PrintCurrencyCard(Currency1, "convert From");

		float AmountInUSD = Currency1.ConvertToUSD(Amount);

		cout << Amount << " " << Currency1.CurrencyCode()
			<< " = " << AmountInUSD << " USD\n";

		if (Currency2.CurrencyCode() == "USD")
		{
			return;
		}

		cout << "\nConverting from USd to:\n";

		_PrintCurrencyCard(Currency2, "To");

		float AmountInCurrency2 = Currency1.ConvertToAnotherCurrency(Amount, Currency2);

		cout << Amount << " " << Currency1.CurrencyCode()
			<< " = " << AmountInCurrency2 << " " << Currency2.CurrencyCode();
	}

public:

	static void ShowCurrencyCalculatorScreen() 
	{
		char PerformAgain = 'y';

		while (PerformAgain == 'Y' || PerformAgain == 'y') 
		{
			system("cls");

			_DrawScreenHeader("\tCurrency Calculator Screen");

			clsCurrency CurrencyFrom = _GetCurrency("\nPlease enter currency1 code: ");
			clsCurrency CurrencyTo = _GetCurrency("\nPlease enter currency2 code: ");
			float Amount = _ReadAmount();

			_PrintCalculationsResults(Amount, CurrencyFrom, CurrencyTo);

			cout << "\nDo you want to perform another calculation? (Y/N)? ";
			cin >> PerformAgain;
		}

	}
};

