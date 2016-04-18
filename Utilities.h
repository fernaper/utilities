/*
 *	External library: Utilities.h
 *	______________________________
 *
 *	By: TheCorPlay
 *	E-Mail: thecorplay@gmail.com
 *	Current version: v0.1.0
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

//#include <iostream>

/// Operator string == char []
/// O = n;
bool operator== (const std::string &text, const char list[])
{
	unsigned int i = 0;
	while (list[i] != '\0' && i < text.length()) {
		if (text[i] != list[i])
			return false;
		i++;
	}
	
	if ((list[i] != '\0' && text[i] == '\0') || (list[i] == '\0' && text[i] != '\0'))
		return false;
		
	if (i == text.length())
		return true;
	
	return false;
}

/// Operator string != char []
/// O = n;
bool operator!= (const std::string &text, const char list[])
{
	unsigned int i = 0;
	while (list[i] != '\0' && i < text.length()) {
		if (text[i] != list[i])
			return true;
		i++;
	}
	
	if (i != text.length())
		return true;
	
	if ((list[i] != '\0' && text[i] == '\0') || (list[i] == '\0' && text[i] != '\0'))
		return true;
	
	return false;
}

/// Given a number return the how many digits have this number
/// O = n; // n = number of digits;
int u_digits (int number)
{
	int digits = 0;
	
	if (number < 0)
		number = -number;
	
	while (number > 0) {
		number /= 10;
		digits++;
	}
	
	return digits;
}

/// Given a number return its square root.
/// O = n;
double u_sqrt (int number)
{
	double radical = number, total = 0;
    while (total != radical)
    {
        total = radical;
        radical = (number/radical+radical)/2;
    }
	
	return radical;
}

/// Returns if a given integer number its prime or not.
/// O = n; // n = log(n)
bool u_prime (int p) {
	if (p < 0)
		p = -p;
	
	if(p<2)
		return false; 
		
	for(int i=2;i<=u_sqrt(p);i++)
		if(p%i == 0)
			return false; 
			
	return true;
}

/// Given two integers (the base and the exponent) returns a to the power of b.
/// O = n;  // n = b
long int u_exponents(int a, int b)
{
	if (b <= 0)
		return 1;
	else
		return a*u_exponents(a,b-1);
}

/// Given a string, return if is a digit or not.
/** Warning:	If you want co convert from string to int, you don't need to use this method if you use u_cstoi
 * 				Also you could use u_isDigit and then, if it returns true u_cstoi, but the result will not be
 *				the same: 	u_cstoi("a1b2c3d") returns and int with 123
 *							if (u_isDigit("a1b2c3d")) u_stoi ("a1b2c3d") u_isDigit returns
 *							false therefore does not execute the conversion.
 **/
/// O = n; n = string.length ()
bool u_isDigit (std::string text)
{
	unsigned int i = 0;
	if (text.length() == 0)
		return false;
	
	while (i < text.length()) {
		if (text[i] > 57 || text[i] < 48)
			return false;
		i++;
	}
	
	return true;
}

/// Given a string and an array of chars, it modifies the array con todo el string. (STOC = String to char)
/// It may fail with error if the array is smaller than the text.
/// O = n; // n = text.length ()
void u_stoc (std::string text, char list [])
{
	for (unsigned int i = 0; i <= text.length(); i++)
		list[i] = text[i];
}

/// Given a string returns an integer ignoring any other character. (CSTOI = Controlled string to int)
/// O = n; // n = string.length ()
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
/// O = n; // n = string.length ()
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
/// O = n; // n = string.length()
unsigned int u_stui (const std::string &text)
{
	unsigned int i = 0, sol = 0;

	while (i++ < text.length())
		if (text [i-1] <= 57 && text [i-1] >= 48)
			sol = sol * 10 + text[i-1] - 48;
	
	return sol;
}

/// Given a string and a char (that char means with what symbol start the decimal part)
/// returns the equivalents double. (STOD = Controlled string to double)
/// O = n; // n = string.length()
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
/// O = n + n + n = 3n = n;
std::string u_itostr (int number)
{
	int digits = u_digits(number);
	bool positive = true;
	
	if (number < 0) {
		positive = false;
		number = -number;
		digits++;
	}
	
	char text [digits];
	
	int i = digits - 1;
	while (number != 0) {
		unsigned int digit = number %10;
		number = number/10;
		text[i] = (char)(digit+48);
		i--;
	}
	text[digits] = '\0';
	
	if (!positive)
		text[0] = '-';
	std::string sol(text);
	
	return sol;
}

/// Given a string and a separator, erase from the string all the aparitions of the separator.
/// O = n;
std::string u_eraseAll (const std::string &text, const char separator)
{
	char list [text.length()+1];
	unsigned int count = 0;
	for (unsigned int i = 0; text[i] != '\0'; i++) {
		if (text[i] != separator) {
			list[count] = text[i];
			count++;
		}
	}
	list[count] = '\0';
	
	std::string sol(list);
	
	return sol;
}

/// Given a string and a character, return a substring from the first (SUBSTOC = Substring to character)
/// position (included) to the character (excluded).
/// O = n;
std::string u_substoc (const std::string &text, const char character)
{
	char list [text.length()+1];
	unsigned int i = 0;
	
	while (text[i] != '\0') {
		if (text[i] == character) {
			list[i] = '\0';
			break;
		}
		else {
			list[i] = text[i];
			i++;
		}
	}
		
	std::string sol (list);
	
	return sol;
}

/// Given a text and a character, returns the number of times that the character appears. (COUNTC = Count Characters)
/// O = n; // n = string.length()
unsigned int u_countChar (const std::string &text, const char separator)
{
	unsigned int count = 0;
	
	for (unsigned int i = 0; i < text.length(); i++)
		if (text[i] == separator) count++;
		
	return count;
}

/// Given a text and a separator, returns the number of words separeted by the separator. (WORDS = Number of Words)
/// If comes an string with only the separator it will return 2 (becouse exist two empty sides)
/// O = n; // n = string.length()
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
/// O = n;
/**
	I'm not sure that the current complexity is of order n.
	If anyone really knows the complexity tell me.
	I will explain my question:
	Although there are two nested loops, each execution makes the inner loop, the outer loop makes an execution less.
	So far this method converts the linearly.
	But the construction of string is linear order and is within a loop, however, in the worst case all characters are the separator.
	Therefore, the construction is constant order (because you only have 1 character)

	Everything leads me to believe that the complexity of the method is of order n, despite seeing a loop within another and a linear method within a loop.
*/
unsigned int u_split (std::string array[], std::string text, const unsigned int words, const char separator)
{
	unsigned int countText = 0, countArray = 0;
	
	while (countArray < words && text[countText] != '\0') {
		char list [text.length() - countText + 1];
		unsigned int countList = 0;
		
		while (countText <= text.length() && text[countText] != separator) {
			list[countList] = text[countText];
			countList++;
			countText++;
		}
		
		list[countList] = '\0';
		array[countArray] = std::string(list);
		countText++;
		countArray++;
	}
	if (!countArray && text[0] != '\0')
		array[0] = text;
	
	return countArray;
}

/// Given an empty array of strings, a text, and the separator, it will give you an array with one word in each position.
/// Also it will return the number of words that he use.
/// O = n;
unsigned int u_split (std::string array[], std::string text, const char separator)
{
	unsigned int countText = 0, countArray = 0, words = u_words (text, separator);
	
	while (countArray < words && text[countText] != '\0') {
		char list [text.length() - countText + 1];
		unsigned int countList = 0;
		
		while (countText <= text.length() && text[countText] != separator) {
			list[countList] = text[countText];
			countList++;
			countText++;
		}
		
		list[countList] = '\0';
		array[countArray] = std::string(list);
		countText++;
		countArray++;
	}
	if (!countArray && text[0] != '\0')
		array[0] = text;
	
	return countArray;
}

/// Given an empty array of strings, a text, it will give you an array with one word in each position separated by ' '.
/// Also it will return the number of words that he use.
/// O = n;
unsigned int u_split (std::string array[], std::string text)
{
	return u_split (array, text, ' ');
}

/// Given an array of strings, the number of words of the array and a separator.
/// It will return a string with all the array concatenated and separated by the separator.
/// O = n + n + n = 3n = n; // n = Length of the final text
std::string u_dsplit (std::string array[], unsigned int count, const char separator)
{
	if (count == 0)
		return "";

	unsigned int length = 0, countList = 0;
	for (unsigned int i = 0; i < count; i++)
		length += array[i].length() + 1;
	
	char list [length+count];
	for (unsigned int i = 0; i < count; i++) {
		for (unsigned int auxI = 0; auxI < array[i].length(); auxI++) {
			list[countList] = array[i][auxI];
			countList++;
		}
		if (countList < (length+count))
			list[countList] = separator; countList++;
	}
	
	list[countList] = '\0';
	std::string text (list);
	return text;
}

/// Given an array of strings and the number of words of the array.
/// It will return a string with all the array concatenated and separated by the default separator ' '.
/// O = n^2;
std::string u_dsplit (std::string array[], unsigned int count)
{
	return u_dsplit (array, count, ' ');
}

/// Given an array of any type, something that you are searching on the array (Binary Search), the space who we search and an empty postion.
/// The variable pos returns the position where it is or should be if not found.
/// The method returns if you found it or not
/// O = log(n);
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
			
		std::cout << "Problem 1: " << op << '\n';
	}
	// Problem 2: Obtain the position of a value in a generic array.
	{
		unsigned int count = 10;
		int array [count];
		
		for (unsigned int i = 0; i < count; i++)
			array[i] = i*3; // [ 0 3 6 9 12 15 18 21 24 27]
		
		int pos;
		if (u_search (array, 9, count, pos)) { // We search for the position of the number 9
			std:: cout << "Problem 2 (a): " << array[pos] << " in the position " << pos << '\n';
		}
		
		if (u_search (array, 17, count, pos)) { // We search for the position of the number 17
			std:: cout << "Problem 2 (b): " << array[pos] << " in the position " << pos << '\n';
		}
	}
	// Problem 3: Split the text into an array and then convert the array to the same string
	{
		std::string text = "Whats your name?";
		unsigned int words = u_words (text, ' ');
		std::string array[words];
		
		u_split (array,text,words,' ');
			
		std::cout << "Problem 3: " << u_dsplit(array,words) << '\n';
	}
	// Problem 4: Erase all the '_'
	{
		std::string text = "_A_l_l_ _r_e_a_d_y_ _a_n_d_ _w_o_r_k_i_n_g_"; // Means "All ready and working"
		text = u_eraseAll(text, '_');
		std::cout << "Problem 4: " << text << '\n';
	}
	// Problem 5: Given a string, split into strings, parse to numbers and if its no prime show the Square Root of its number
	{
		std::string text = "1, 2, 3, 4, 5, 6, 7, 8, 9, 10"; // Primes: 2, 3, 5, 7
		unsigned int words = u_words (text, ' ');
		std::string array [words];
		
		u_split (array,text,' ');
		
		std::cout << "Problem 5: " << '\n';
		
		for (unsigned int i = 0; i < words; i++) {
			int number = u_cstoi(array[i]);
			if (!u_prime(number))
				std::cout << "	   sqrt(" << number << ") = " << u_sqrt(number) << '\n';
		}
		
		std::cout << "\n";
	}
	// Problem 6: Given a string, obtain the substring from 0, to the first ',' (if exists), then change from string to an array char
	// 			  shows the array.
	{
		std::string text = "Hello everybody, hi to everyone";
		std::string subText = u_substoc (text, ',');
		char list [subText.length()+1];
		
		u_stoc (subText, list);
		
		std::cout << "Problem 6: ";
		
		for (unsigned int i = 0; list[i] != '\0'; i++) {
			std::cout << list[i];
		}
		std::cout << '\n';
	}
	
	return 0;
}*/

#endif
