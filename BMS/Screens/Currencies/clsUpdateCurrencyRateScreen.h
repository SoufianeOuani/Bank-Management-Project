#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsUpdateCurrencyRateScreen : protected clsScreen
{

private:
	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "\n____________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();
		cout << "\n____________________\n";
	}

	static float _ReadRate()
	{
		cout << "\nEnter New Rate: ";
		float NewRate = 0;

		NewRate = clsInputValidate::ReadNumber<float>();
		return NewRate;
	}


public:

	static void ShowUpdateCurrencyRateScreen() 
	{
		_DrawScreenHeader("\tUpdate Currency Rate Screen");

		string CurrencyCode = "";

		cout << "\nPlease Enter Currency Code: ";
		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency code is not found, choose another one: ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		_PrintCurrencyCard(Currency);

		cout << "\nAre you sure you want to update this currency rate y/n? ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{

			cout << "\n\nUpdate Currency Rate:";
			cout << "\n____________________\n";


			Currency.UpdateRate(_ReadRate());

			cout << "\nCurrency Rate Updated Succefully :-)" << endl;

			_PrintCurrencyCard(Currency);
		}
		else
		{
			cout << "\nCurrency updating cancelled" << endl;
		}
	}
};

