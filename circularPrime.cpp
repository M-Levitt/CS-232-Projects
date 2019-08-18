#include<iostream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;

//function prototypes
bool isPrime(int numPar);
bool isCircularPrime(int primePar);

int main() {
	//declarations
	vector<int>intPrimes; //original copy
	vector<int>intPrimesCopy; //copy of primes, must make this because original primes are changed to 0s in code
	vector<int>digitsOfPrimes; //contains all the digits of the primes in primes copy
	vector<int>circularPrimes; // all circular primes
	int userNum; 
	int baseOfNumbers = 10; // I'm using base 10, so this value will equal 10
	int resultOfPrimeDividedByBase = 0; 
	int numberOfDigits = 0; // gives number of digits for a prime num
	int reverseOfUserNum = 0; //new rotation of a prime
	int quotient = 0; //quotient of what you're dividing
	int firstCounter = 0; // check if this is equal to the number of digits so it can be a circular prime
	int exponent = 0;
	int countOfIntPrimesCopy = 0; //tells where you're at in int primes copy
	int numberOfTimesToRotatePrime = 1; // must be put to 1 because first rotation has already been done

	//get user input
	cout << "How many circular primes are below: ";
	cin >> userNum;

	//calculations

	//check if number is prime
	for (int i = 0; i <= userNum; i++) {
		if (i == 0 || i == 1) {
			cout << "";
		}
		else {
			if (isPrime(i) == true) {
				intPrimes.push_back(i);
				intPrimesCopy.push_back(i);
			}
		}
	}
	//getting the number of digits
	for (int i = 0; i < intPrimes.size(); i++) {
		while (resultOfPrimeDividedByBase != 1) {
			numberOfDigits++;
			resultOfPrimeDividedByBase = (intPrimes.at(i) /= baseOfNumbers) + 1;
		}
		resultOfPrimeDividedByBase = 0;
		digitsOfPrimes.push_back(numberOfDigits);
		numberOfDigits = 0;
	}
	
	//check if prime is circular prime
	for (countOfIntPrimesCopy; countOfIntPrimesCopy < intPrimesCopy.size(); countOfIntPrimesCopy++) {
		if (countOfIntPrimesCopy < 4) {
			circularPrimes.push_back(intPrimesCopy.at((countOfIntPrimesCopy)));
		}
		else {
			//rotation function
			for (countOfIntPrimesCopy; countOfIntPrimesCopy < digitsOfPrimes.size(); countOfIntPrimesCopy++) {
				for (int j = 0; j < 1; j++) {
					exponent = pow(10, (digitsOfPrimes.at(countOfIntPrimesCopy) - 1));
					// this rotates the first number to the end of the number
					// ex 123 now becomes 231
					reverseOfUserNum = intPrimesCopy.at(countOfIntPrimesCopy) % exponent;
					quotient = intPrimesCopy.at(countOfIntPrimesCopy) / exponent;
					reverseOfUserNum = (reverseOfUserNum * 10) + quotient;
					firstCounter++;
					if (isCircularPrime(reverseOfUserNum) == true) {
						if (digitsOfPrimes.at(countOfIntPrimesCopy) > 1 && isCircularPrime(reverseOfUserNum) == true
							&& isPrime(reverseOfUserNum) == true) {
							for (numberOfTimesToRotatePrime; numberOfTimesToRotatePrime < digitsOfPrimes.at(countOfIntPrimesCopy); numberOfTimesToRotatePrime++) {
								firstCounter++;
								quotient = reverseOfUserNum / exponent;
								reverseOfUserNum = reverseOfUserNum % exponent;
								reverseOfUserNum = (reverseOfUserNum * 10) + quotient;
								if (isCircularPrime(reverseOfUserNum) == false) {
									numberOfTimesToRotatePrime = numberOfTimesToRotatePrime + digitsOfPrimes.at(countOfIntPrimesCopy);
								}
							}
						}
					}
				}
				if (firstCounter == digitsOfPrimes.at(countOfIntPrimesCopy)) {
					circularPrimes.push_back(intPrimesCopy.at(countOfIntPrimesCopy));
				}
				firstCounter = 0;
				numberOfTimesToRotatePrime = 1;
			}
		}
	}

	//output
	cout << circularPrimes.size() << ": ";
	for (int i = 0; i < circularPrimes.size(); i++) {
		if (i == circularPrimes.size() - 1) {
			cout << circularPrimes.at(i); // for the final circular prime, so no comma
		}
		else {
			cout << circularPrimes.at(i) << ", "; // for the rest of the primes, so comma
		}
	}

	cout << endl;

	system("pause");
	return 0;
}


bool isPrime(int numPar) {
	if (numPar == 2 || numPar == 3 || numPar == 5 || numPar == 7 || numPar == 11 || 
		numPar == 13 || numPar == 17 || numPar == 31 || numPar == 71) {
		return true;
	}
	else if (numPar % 2 != 0 && numPar % 3 != 0 && numPar % 4 != 0 && numPar % 5 != 0 &&
		numPar % 6 != 0 && numPar % 7 != 0 && numPar % 8 != 0 && numPar % 9 != 0 &&
		numPar % 11 != 0 && numPar % 13 != 0 && numPar % 17 != 0 && numPar % 19 != 0 && numPar % 23 != 0) {
		return true;
	}
	else {
		return false;
	}
}

bool isCircularPrime(int primePar) {
	if (primePar == 2 || primePar == 3 || primePar == 5 || primePar == 7 || primePar == 11 ||
		primePar == 13 || primePar == 17 || primePar == 31 || primePar == 71) {
		return true;
	}
	else if (primePar % 2 != 0 && primePar % 3 != 0 && primePar % 4 != 0 && primePar % 5 != 0 &&
		primePar % 6 != 0 && primePar % 7 != 0 && primePar % 8 != 0 && primePar % 9 != 0 &&
		primePar % 11 != 0 && primePar % 13 != 0 && primePar % 17 != 0 && primePar % 19 != 0 && primePar % 23 != 0) {
		return true;
	}
	else {
		return false;
	}
}

