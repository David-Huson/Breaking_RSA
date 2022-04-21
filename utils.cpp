#include "utils.hpp"
#include <cmath>
#include <iostream>
#include <stdint.h>
#include <climits>

using namespace std;

// initialize the values of the 
Utilities::Utilities(): primeFactors(N + 1), listOfPrimes(){
  sieve(N);  
}

// getter for the list of primes
const vector<int> & Utilities::getPrimes() const {
  return this->listOfPrimes;
}

// linear sieveing function
void Utilities::sieve(int n){

  for (int i = 2; i <= n; i++) {
    if (primeFactors[i] == 0) {
      primeFactors[i] = i;
      listOfPrimes.push_back(i);
    }

    for (int j = 0; j < (int)listOfPrimes.size() && listOfPrimes[j] <= primeFactors[i] && i * listOfPrimes[j] <= n; j++)
      primeFactors[i * listOfPrimes[j]] = listOfPrimes[j];
    
  }
}

int Utilities::primeFactor(long int n) {
  int lim = sqrt(n);
  for (int i = 0; listOfPrimes.at(i) <= lim; i++) {
    if (n % listOfPrimes.at(i) == 0)
      return listOfPrimes.at(i);
  }
  return n;
}

long int Utilities::modularInverse(int e, long int phi) {
  long int x;
  long int y;
  int gcd = xgcd(e, phi, x, y);

  return x % phi;
}

int Utilities::xgcd(long int a, long int b, long int & x, long int & y) {
  if(b == 0){
    x = 1;
    y = 0;
    return a;
  }

  long int x1;
  long int y1;
  int gcd = xgcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return gcd;
}

int Utilities::fastExpMod(ll base, long exp, ll m) {
  ll result = 1;

  base = base % m; 

  if (base == 0) return 0;

  while (exp > 0) {
    // Square and Multiply binary exponentiation
    
    // here we are essectially checking the bit representation of the exp and seeing if its MSB is a 1
    if (exp & 1)
        result = modularMultiply(result, base, m);
    
    // bitshift
    exp >>= 1; // y = y/2
    base = modularMultiply(base, base, m);
    // cout << result << endl;
  }

  // cout << endl;
  return result;
}

ll Utilities::modularMultiply(ll a, ll b, ll mod) {
	ll res = 0; // Initialize result
	a = a % mod;
	while (b > 0)
	{
		// If b is odd, add 'a' to result
		if (b & 1)
			res = (res + a) % mod;

		// Multiply 'a' with 2
		a = (a * 2) % mod;

		// Divide b by 2
		b >>= 1;
	}

	// Return result
	return res % mod;
}

bool Utilities::willOverflow(ll a, ll b)
{
	// Check if either of them is zero
	if (a == 0 || b == 0)
		return false;
	
	ll result = a * b;
	if (a == result / b)
		return false;
	else
		return true;
}