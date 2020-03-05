//==========================================================
//
// Title:      Fundamental Structures Lab 7
// Course:     CSC 1501
// Lab Number: Lab 7
// Author:     Austin Murad (gh9591)
// Date:       3/5/2020
// Description:
//   this program will:
// 1) Find the factors of a number.
// 2) Evaluate polynomials with a number given.
// 3) Find congruence between 3 inputs
//==========================================================

#include <iostream> //For cin and cout and system
#include <iomanip> //For formating output
#include <string> //For string data type
#include <cstdlib> //For several general purpose functions
#include <fstream> //For file handling
#include <cstdio> //For % assist functions
#include <cmath> //For math functions
using namespace std; //To use cin and cout without std::

//create a class that holds all functions and variables
class Lab7
{
public:
    void factorsOfNumbers(int facNum);
    //Function to find the factors of an integer entered
    //Postcondition:
    void polyEval(int polEv[], int poly, int size);
    //Function to crate a polynomial and then find the value of the second num added
    //Postcondition:
    bool Congruent(int conA, int conB, int conM);
    //Function to find congruence between % of three numbers
    //Postcondition:
private:
    int factNum;
    int conA;
    int conB;
    int conM;
    int poly;
    int polEv[];
};

//implement the Factors Of Numbers function
void Lab7::factorsOfNumbers(int x)
{
    //run a loop to loop through the number given
    printf("The factors of %d are: ", x);
    for (int i = 1; i <= x; ++i)
    {
        //finding the mod of the number prompted by the number of iterations of
        //the loop will give the factors of the number
        if (x % i == 0)
            cout << " " << i;
    }
}

//implement the Polynomial evaluation function
void Lab7::polyEval(int arr[], int x, int size)
{
    //create the equation and get the answer
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i] * pow(x, i);
    }
    
    //print results
    cout << "The answer to the polynomial is: " << sum;
}

//implement Congruent function
bool Lab7::Congruent(int a, int b, int m)
{
    if ((a % m) == (b % m))
        return true;
    else
        return false;
}


int main()
{
    //create an object of class lab7
    Lab7 objectVariable;
    //create variables for parameters
    int factNum;
    int size = 0;
    int polEv[size];
    int poly;
    int conA;
    int conB;
    int conM;
    
    //prompt user for a value to get the factors of
    cout << "Enter a number you would like to get the factors of: ";
    cin >> factNum;
    
    //call the factors of number function
    objectVariable.factorsOfNumbers(factNum);
    
    //prompt for how big the user wants the polynomial
    cout << "\n\nEnter how big you want the polynomial?: ";
    cin >> size;

    //get the numbers for the polynomial equation
    //use a for loop to loop through the elements of the array with size "size"
    cout << "Enter coefficients for the polynomial in this format(x x x): ";
    for (int i = 0; i < size; i++)
    {
        //prompt for numbers
        cin >> polEv[i];
    }
    
    //prompt for and get the secod parameter
    cout << "Enter a digit you would like to evaluate: ";
    cin >> poly;
    
    //call polynomial evaluation library
    objectVariable.polyEval(polEv, poly, size);
    
    //promopt user for and get inputs for 3 integers from user
    cout << "\n\nEnter two integers in this format (x x): ";
    cin >> conA >> conB;
    //prompt for and get the final variable to mod the rest
    cout << "\nEnter a positive integer to mod the others with: ";
    cin >> conM;
    while (conM < 0)
    {
        cout << "Interger entered is not positive." << endl;
        cout << "Enter a positive integer to mod the others with: ";
        cin >> conM;
    }
    
    //call congruent function
    cout << "The statement evaluated is " << boolalpha <<
    objectVariable.Congruent(conA, conB, conM) << endl;
    //using boolalpha to return a true instead of a 1, or a false instead of a 0.
    
    return 0;
}
