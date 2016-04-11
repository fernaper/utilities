/*
 *	External library: Utilities.h
 *	______________________________
 *
 *	By: TheCorPlay
 *	E-Mail: thecorplay@gmail.com
 *	Current version: v0.0.5
 *	______________________________
 *	
 *	COPYRIGHT ©
 *
 *	This file has copyright assigned.
 *	It is free to use, but give credit used.
 * 	
 *	Example of minimum credits:
 *	Library Utilities.h made by TheCorPlay
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
 *	 +	Various types of generic searches (Binary done).
 *	 +	New u_eraseAll() but with an String (not only a char).
 *
*/
#ifndef _UTILITIES_H_
#define _UTILITIES_H

#include <string>
#include <iostream>

/// Given two integers (the base and the exponent) returns a to the power of b.
long int u_exponents(int a, int b)
{
	if (b <= 0)
		return 1;
	else
		return a*u_exponents(a,b-1);
}

/// Given a string returns an integer ignoring any other character. (CSTOI = Controlled string to int)
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

/// Given a string returns an integer. (STOI = String to int)
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

/// Given a string returns an unsigned integer ignoring any other character. (STUI = Controlled string to unsigned int)
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

/// Given a string and a separator, erase from the string all the aparitions of the separator.
void u_eraseAll (std::string &text, const char separator)
{
	for (unsigned int i = 0; i < text.length(); i++)
		if (text[i] == separator) text.erase(i,1);
}

/// Given a text and a character, returns the number of times that the character appears. (COUNTC = Count Characters)
unsigned int u_countChar (const std::string &text, const char separator)
{
	unsigned int count = 0;
	
	for (unsigned int i = 0; i < text.length(); i++)
		if (text[i] == separator) count++;
		
	return count;
}

/// Given a text and a separator, returns the number of words separeted by the separator. (WORDS = Number of Words)
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

/// Given an empty array of strings, a text, it will give you an array with one word in each position separated by ' '.
/// Also it will return the number of words that he use.
unsigned int u_split (std::string array[], std::string text)
{
	return u_split (array, text, ' ');
}

/// Given an array of strings, the number of words of the array and a separator.
/// It will return a string with all the array concatenated and separated by the separator.
std::string u_dsplit (std::string array[], unsigned int count, const char separator)
{
	std::string text = array[0];
	
	for (unsigned int i = 1; i < count; i++)
		text = text + separator + array [i];
	
	return text;
}

/// Given an array of strings and the number of words of the array.
/// It will return a string with all the array concatenated and separated by the default separator ' '.
std::string u_dsplit (std::string array[], unsigned int count)
{
	return u_dsplit (array, count, ' ');
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

int main ()
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
	// Problem 3: Split the text into an array and then convert the array to the same string
	{
		std::string text = "Whats your name?";
		unsigned int words = u_words (text, ' ');
		std::string array[words];
		
		u_split (array,text,words,' ');
			
		std::cout << "Problem 3: " << u_dsplit(array,words) << "\n";
	}
	// Problem 4: Erase all the '_'
	{
		std::string text = "_A_l_l_ _r_e_a_d_y_ _a_n_d_ _w_o_r_k_i_n_g_"; // Means "All ready and working"
		u_eraseAll(text, '_');
		std::cout << "Problem 4: " << text << "\n";
	}
	
	return 0;
}

#endif
