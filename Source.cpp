//																								Alec McDaugale
//
//This program contains a recursive function to detect weather or not a word entered is a palindrome. It also includes 
//the main method wich accepts the users input and prints the results for the user to view.

//This program requires string functions to accept the word entered and io functions to accept user input and to output
#include <string>
#include <iostream>

using namespace std;

//recursive function to detect a palindrome
int palindrome(string str, int min, int max);

//main method
int main()
{
	//string to store the input word for processing
	string str;
	//int to store the max index of the word
	int max;
	//int to store the first index of the word, i initialized this to 0 since all arrays start at 0
	int min = 0;

	//boolean value to store the results of the palindrome function
	bool results;

	//prompt user to input a word to check
	cout << "please enter a word to check if its a palindrome" << endl;
	//accept the input string
	cin >> str;
	cout << endl;

	//the max is equal to the length of the string, this line is alot like Java
	max = str.length();
	//subtract one from the index so that the index is in range
	max -= 1;

	//test line to check if value is acurate
	//cout << str[max];

	//the results are equal to the int returned by the palindrome function
	results = palindrome(str, min, max);

	//if the results are true print that it is a palindrome
	if (results == true)
	{
		cout << str << " is a palindrome" << endl;
	}
	//else if they are false then its not a palindrome
	else// if (results == false)
	{
		cout << str << " is not a palindrome" << endl;
	}

	//pause the program before program termination
	system("pause");
	//system exit
	return 0;


}
//recursive palindrome function
int palindrome(string str, int min, int max)
{
	
	//debug line
	//cout << min << " " << max << endl;

	//base case
	//if the value of min is greater than or equal to max
	if (min >= max)
	{
		//if the values of the letters are equal 
		if (str[min] == str[max])
		{
			//return true, is a palindrome
			return 1;
		}
		else
		{ 
			//otherwise its false, not a palindrome
			return 0;
		}
			
	}
	//general case
	//as long as min is less than max
	else if (min < max)
	{
		//if the first and last letters are the same
		if (str[min] == str[max])
		{
			//recall this function making this a direct recursive function
			palindrome(str, min + 1, max - 1);
		}
		else
		{
			//if not return false
			return 0;
		}
	}
	
}
