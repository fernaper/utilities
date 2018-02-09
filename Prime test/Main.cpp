#include <iostream>
#include <iomanip> 
#include "UtilitiesV.h"
#include <string>

using namespace std;

void nPrimesAttempts (int n) {
	for (int i = 1; i < n; i++) {
		if (u_prime(i))
			cout << i << setw(12-u_digits(i));
		else if (i/6.0 != i/6)
			cout << "-" << setw(11);
		else
			cout << "\n";
	}
}

void nPrimes (int n) {
	int i = 1;
	while (n > 0) {
		if (u_prime(i)) {
			cout << i << setw(12-u_digits(i));
			n--;
		} else if (i/6.0 != i/6)
			cout << "-" << setw(11);
		else
			cout << "\n";
		
		i++;
	}
}

int main (int argc, char **argv) {
	if (argc < 2)
		return -1;
	
	if (argc == 3 && argv[1][0] == 'a') {
		nPrimesAttempts(atoi(argv[2]));
	} else {
		nPrimes(atoi(argv[1]));
	}

	return 0;
}