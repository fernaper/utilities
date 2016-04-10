/*
 *	External library: Utilities.h
 *	______________________________
 *
 *	By: TheCorPlay
 *	E-Mail: thecorplay@gmail.com
 *	Current version: v0.0.4
 *	______________________________
 *	
 *	COPYRIGHT ©
 *
 *	This file has copyright assigned.
 *	It is free to use, but give credit used.
 * 	
 *	Example of minimum credits:
 *	Library Utilities.h made by Kramez
 *	you can find this and more done
 *	for him here:
 *
 *	https://github.com/TheCorPlay
 *	______________________________
 *	
 *	FUTURE UPDATES
 *	
 *	 +	Conversions of all possible
 *		standard types in both directions.
 *	 +	Various types of generic searches.
 *
*/
#ifndef _UTILITIES_H_
#define _UTILITIES_H

#include <string>
//#include <iostream>

/// Given two integers (the base and the exponent) returns a to the power of b
long int u_exponents(int a, int b)
{
	if (b <= 0)
		return 1;
	else
		return a*u_exponents(a,b-1);
}

/// Given a string returns an integer ignoring any other character (CSTOI = Controlled string to int)
int u_cstoi (const std::string &text)
{
	unsigned int i = 0;
	bool positive = true;
	int sol = 0;
	
	while (positive && i < text.length() && (text[i] > 57 || text[i] < 48 || text[i] == '-')) {
		if (text[i] == '-')
			positive = false;
		i++;
	}
	
	while (i++ <= text.length())
		if (text [i-1] <= 57 && text [i-1] >= 48)
			sol = sol * 10 + text[i-1] - 48;
			
	if (!positive)
		sol = - sol;
	
	return sol;
}

/// Given a string returns an integer (STOI = String to int)
int u_stoi (const std::string &text)
{
	unsigned int i;
	bool positive = true;
	int sol = 0;
	
	i = (text[0] == '-');
	positive = !i;
	
	while (i++ < text.length())
			sol = sol * 10 + text[i-1] - 48;
	
	if (!positive)
		return - sol;
	
	return sol;
}

/// Given a string returns an unsigned integer ignoring any other character (STUI = Controlled string to unsigned int)
unsigned int u_stui (const std::string &text)
{
	unsigned int i = 0, sol = 0;

	while (i++ < text.length())
		if (text [i-1] <= 57 && text [i-1] >= 48)
			sol = sol * 10 + text[i-1] - 48;
	
	return sol;
}

/// Given a string and a char (that char means with what symbol start the decimal part) returns the equivalents double. (STOD = Controlled string to double)
double u_stod (const std::string &text, const char decimal)
{
	unsigned int i = 0, iaux;
	double sol = 0;
	bool positive = true;
	
	while (positive && i < text.length() && (text[i] > 57 || text[i] < 48 || text[i] == '-') && text[i-1] != decimal) {
		if (text[i] == '-')
			positive = false;
		i++;
	}
	
	while (i++ < text.length() && text[i-1] != decimal)
		if (text [i-1] <= 57 && text [i-1] >= 48)
			sol = sol * 10 + text[i-1] - 48;
	
	iaux = i;
	
	int dec = 0;
	while (i++ < text.length())
		if (text [i-1] <= 57 && text [i-1] >= 48)
			dec = dec * 10 + text[i-1] - 48;
		else
			iaux++;
	 
	sol = sol + (dec /(float) u_exponents(10,i - 1 - iaux));
	
	if (!positive)
		sol = - sol;
	
	return sol;
}

/// Given an integer, return the equivalent string. (ITOSTR = Integer to string)
std::string u_itostr (int number)
{
	std::string sol = "";
	bool positive = true;
	
	if (number < 0) {
		positive = false;
		number = -number;
	}
	
	while (number != 0) {
		unsigned int digit = number %10;
		number = number/10;
		sol = (char)(digit+48) + sol;
	}
	
	if (!positive)
		sol = '-' + sol;
	
	return sol;
}

/// Given a text and a separator, returns the number of words separeted by the separator.
/// If comes an string with only the separator it will return 2 (becouse exist two empty sides)
unsigned int u_words (const std::string &text, const char separator)
{
	unsigned int num = 0, i = 0;
	
	while (i++ <= text.length())
		if (text[i-1] == separator)
			num++;
			
	if (num != 0)
		num++;

	return num;
}

/// Given an empty array of strings, a text, the maximum number of words, and the separator, it will give ou an array with one word in each position.
/// Also it will return the number of words that he use.
unsigned int u_split (std::string array[], std::string text, const unsigned int words, const char separator)
{
	unsigned int count = 0;
	std::size_t found;

	do {
		found = text.find(separator);
		array[count] = text.substr (0,found);
		text.erase(0, found+1);
		count++;		
	} while (found != std::string::npos && count < words);
	
	return count;
}

/// Given an empty array of strings, a text, and the separator, it will give you an array with one word in each position.
/// Also it will return the number of words that he use.
unsigned int u_split (std::string array[], std::string text, const char separator)
{
	unsigned int count = 0;
	unsigned int words = u_words (text, separator);
	std::size_t found;

	do {
		found = text.find(separator);
		array[count] = text.substr (0,found);
		text.erase(0, found+1);
		count++;		
	} while (found != std::string::npos && count < words);
	
	return words;
}

/// Given an array of any type, something that you are searching on the array (Binary Search), the space who we search and an empty postion.
/// The variable pos returns the position where it is or should be if not found.
/// The method returns if you found it or not
template <class TYPE>
bool u_search(TYPE list[], TYPE search, int count, int &pos) {
  int start = 0, end = count - 1, half;
  bool found = false;

	while ((start <= end) && !found) {
		half = (start + end) / 2;
		if (search == list[half])
			found = true;
		else if (search < list[half])
			end = half - 1;
		else
			start = half + 1;
	}
	
	if (found)
		pos = half;
	else
		pos = start;
		
	return found;
}


/*int main ()
{
	// Problem 1: Obtain the addition of all values separated by a specific symbol (not the others).
	{
		std::string text = "a1b2+c5d+e2f3g"; // It means: "12+5+23" = 40
		unsigned int words = u_words (text, '+');
		std::string array[words];
		
		u_split (array,text,words,'+');
		
		int op = 0;
		
		for (unsigned int i = 0; i < words; i++)
			op = op + u_cstoi (array[i]);
			
		std::cout << "Problem 1: " << op << "\n";
	}
	// Problem 2: Obtain the position of a value in a generic array.
	{
		unsigned int count = 10;
		int array [count];
		
		for (unsigned int i = 0; i < count; i++)
			array[i] = i*3; // [ 0 3 6 9 12 15 18 21 24 27]
		
		int pos;
		if (u_search (array, 9, count, pos)) { // We search for the position of the number 9
			std:: cout << "Problem 2 (a): " << array[pos] << " in the position " << pos << "\n";
		}
		
		if (u_search (array, 17, count, pos)) { // We search for the position of the number 17
			std:: cout << "Problem 2 (b): " << array[pos] << " in the position " << pos << "\n";
		}
	}
	
	return 0;
}*/

#endif
