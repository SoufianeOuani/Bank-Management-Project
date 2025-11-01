#pragma once
#include <iostream>
#include <string>
#include <limits>
#include "clsString.h"
#include "clsDate.h"

using namespace std;

class clsInputValidate
{
public:

    // Check if number is in range
    template <typename T>
    static bool IsNumberBetween(T Number, T From, T To)
    {
        return (Number >= From && Number <= To);
    }

    // Check if date is in range (reversed range supported)
    static bool IsDateBetween(const clsDate& Date, const clsDate& From, const clsDate& To)
    {
        return
            (
                (clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)) &&
                (clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
                )
            ||
            (
                (clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)) &&
                (clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
                );
    }

    // Read number of any type
    template <typename T>
    static T ReadNumber(const string& ErrorMessage = "Invalid Number, Enter again:\n")
    {
        T Number;
        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
        }
        return Number;
    }

    // Read number in a range
    template <typename T>
    static T ReadNumberBetween(T From, T To, const string& ErrorMessage = "Number is not within range, Enter again:\n")
    {
        T Number = ReadNumber<T>();
        while (!IsNumberBetween(Number, From, To))
        {
            cout << ErrorMessage;
            Number = ReadNumber<T>();
        }
        return Number;
    }

    // Check if date is valid
    static bool IsValidDate(const clsDate& Date)
    {
        return clsDate::IsValidDate(Date);
    }

    // Read a full string line
    static string ReadString(const string& Message = "")
    {
        if (!Message.empty()) cout << Message;
        string S;
        getline(cin >> ws, S);
        return S;
    }

};
