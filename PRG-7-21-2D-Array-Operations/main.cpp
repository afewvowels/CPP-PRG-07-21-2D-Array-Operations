//
//  main.cpp
//  PRG-7-21-2D-Array-Operations
//
//  Created by Keith Smith on 10/8/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Write a program that creates a two-dimensional array initialize with test data. Use
//  any data type you wish. The program should have the following functions:
//
//  * getTotal - This function should accept a two-dimensional array as its argument
//    and return the total of all the values in the array.
//  * getAverage - This function should accept a two-dimensional array as its argument
//    and return the average of all the values in the array.
//  * getRowTotal - This function should accept a two-dimensional array as its first
//    argument and an integer as its second argument. The second argument should be
//    the subscipt of a row in the array. The function should return the total of the values
//    in the specified row of the array.
//  * getColumnTotal - This function should accept a two-dimensional array as its first
//    argument and an integer as its second argument. The second argument should be
//    the subscipt of a column in the array. The function should return the total of the values
//    in the specified column of the array.
//  * getRowTotal - This function should accept a two-dimensional array as its first
//    argument and an integer as its second argument. The second argument should be
//    the subscipt of a row in the array. The function should return the lowest value in
//    in the specified row of the array.
//
//  Demonstrate each of the functions in this program

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int INT_ROWS = 3;
const int INT_COLS = 3;

int setHighestNumber();
int generateRandomNumber(int);
void drawArray(const int [][INT_COLS]);
void getTotal(const int [][INT_COLS]);
void getAverage(const int [][INT_COLS]);
void getRowTotal(const int [][INT_COLS]);
void getColumnTotal(const int [][INT_COLS]);
void getHighestInRow(const int [][INT_COLS]);
void getLowestInRow(const int [][INT_COLS], const int);


int main()
{
    int intHighestValue;
    
    int intArray[INT_ROWS][INT_COLS];
    
    intHighestValue = setHighestNumber();
    
    cout << "Please wait while we populate the array...\n";
    
    for(int rows = 0 ; rows < INT_ROWS ; rows++)
    {
        for(int cols = 0 ; cols < INT_COLS ; cols++)
        {
            do
            {
                intArray[rows][cols] = generateRandomNumber(intHighestValue);
            } while(intArray[rows][cols] > intHighestValue);
        }
    }
    
    drawArray(intArray);
    
    
    getTotal(intArray);
    getAverage(intArray);
    getRowTotal(intArray);
    getColumnTotal(intArray);
    getHighestInRow(intArray);
    getLowestInRow(intArray, intHighestValue);
    
    return 0;
}

int setHighestNumber()
{
    int intNumber;
    
    cout << "Please enter the highest integer value\n"
    << "you would like to use for this array: ";
    cin >> intNumber;
    while(!cin || intNumber < 0 || intNumber > 100)
    {
        cout << "Please choose a number between\n"
        << "0 and 100: ";
        cin.clear();
        cin.ignore();
        cin >> intNumber;
    }
    
    return intNumber;
}

int generateRandomNumber(int high)
{
    int intResult;
    int intTempTime;
    
    float fltClock;
    
    intTempTime = time(0);
    
    //Test when intTempTime is the same as time(0)
    //It is sometimes false and falls through
    //With no returned value
    while(intTempTime == time(0))
    {
        while(intTempTime != time(0))
        {
            fltClock = time(0);
            
            unsigned seed = time(0);
            
            srand(seed);
            
            intResult = rand() % high;
            
            return intResult + 1;
        }
    }
    return 0;
}

void drawArray(const int intArray[][INT_COLS])
{
    for(int rows = 0 ; rows < INT_ROWS ; rows++)
    {
        for(int cols = 0 ; cols < INT_COLS ; cols++)
        {
            cout << setw(4);
            cout << " " << intArray[rows][cols] << " ";
        }
        cout << endl;
    }
}


void getTotal(const int intArray[][INT_COLS])
{
    int intTotal;
    
    intTotal = 0;
    
    for(int rows = 0 ; rows < INT_ROWS ; rows++)
    {
        for(int cols = 0 ; cols < INT_COLS ; cols++)
        {
            intTotal += intArray[rows][cols];
        }
    }
    
    cout << "The sum total value of\n"
    << "all numbers in the array is: " << intTotal << endl;
}

void getAverage(const int intArray[][INT_COLS])
{
    int intTotal;
    
    float fltAverage;
    
    intTotal = 0;
    
    for(int rows = 0 ; rows < INT_ROWS ; rows++)
    {
        for(int cols = 0 ; cols < INT_COLS ; cols++)
        {
            intTotal += intArray[rows][cols];
        }
    }
    
    fltAverage = static_cast<float>(intTotal) / (INT_ROWS * INT_COLS);
    
    cout << setprecision(3);
    cout << "The sum total average of\n"
    << "all number in the array is: " << fltAverage << endl;
}

void getRowTotal(const int intArray[][INT_COLS])
{
    int intChoice;
    int intSumTotal;
    
    intSumTotal = 0;
    
    cout << "Please select a row using 1 to " << INT_ROWS << ": ";
    cin >> intChoice;
    while(!cin || intChoice < 1 || intChoice > INT_ROWS)
    {
        cout << "Please select an integer between 1 and " << INT_ROWS << ": ";
        cin.clear();
        cin.ignore();
        cin >> intChoice;
    }
    
    intChoice -= 1;
    
    for(int rows = intChoice ; rows == intChoice ; rows++)
    {
        for(int cols = 0 ; cols < INT_COLS ; cols++)
        {
            intSumTotal += intArray[intChoice][cols];
            cout << intSumTotal << endl;
        }
    }
    
    cout << "The sum total for row " << intChoice << " is: " << intSumTotal << endl;
}

void getColumnTotal(const int intArray[][INT_COLS])
{
    int intChoice;
    int intSumTotal;
    
    intSumTotal = 0;
    
    cout << "Please select a column using 1 to " << INT_COLS << ": ";
    cin >> intChoice;
    while(!cin || intChoice < 1 || intChoice > INT_COLS)
    {
        cout << "Please select an integer between 1 and " << INT_COLS << ": ";
        cin.clear();
        cin.ignore();
        cin >> intChoice;
    }
    
    intChoice -= 1;
    
    for(int rows = 0 ; rows < INT_ROWS ; rows++)
    {
        for(int cols = intChoice ; cols == intChoice ; cols++)
        {
            intSumTotal += intArray[rows][intChoice];
            cout << intSumTotal << endl;
        }
    }
    cout << "The sum total for column " << intChoice << " is: " << intSumTotal << endl;
}

void getHighestInRow(const int intArray[][INT_COLS])
{
    int intChoice;
    int intSumTotal;
    int intHighest;
    
    intSumTotal = 0;
    intHighest = 0;
    
    cout << "Please select a row using 1 to " << INT_ROWS << ": ";
    cin >> intChoice;
    while(!cin || intChoice < 1 || intChoice > INT_ROWS)
    {
        cout << "Please select an integer between 1 and " << INT_ROWS << ": ";
        cin.clear();
        cin.ignore();
        cin >> intChoice;
    }
    
    intChoice -= 1;
    
    for(int rows = intChoice ; rows == intChoice ; rows++)
    {
        for(int cols = 0 ; cols < INT_COLS ; cols++)
        {
            if(intArray[rows][cols] > intHighest)
            {
                intHighest = intArray[rows][cols];
            }
        }
    }
    
    cout << "The highest number in row " << (intChoice + 1) << " is: " << intHighest << endl;
}

void getLowestInRow(const int intArray[][INT_COLS], int highestNumber)
{
    int intChoice;
    int intSumTotal;
    int intLowest;
    
    intSumTotal = 0;
    intLowest = highestNumber;
    
    cout << "Please select a column using 1 to " << INT_COLS << ": ";
    cin >> intChoice;
    while(!cin || intChoice < 1 || intChoice > INT_COLS)
    {
        cout << "Please select an integer between 1 and " << INT_COLS << ": ";
        cin.clear();
        cin.ignore();
        cin >> intChoice;
    }
    
    intChoice -= 1;
    
    for(int rows = intChoice ; rows == intChoice ; rows++)
    {
        for(int cols = 0 ; cols < INT_COLS ; cols++)
        {
            if(intArray[rows][cols] < intLowest)
            {
                intLowest = intArray[rows][cols];
            }
        }
    }
    
    cout << "The lowest number in row " << (intChoice + 1) << " is: " << intLowest << endl;
}

