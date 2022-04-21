#include "utils.hpp"
#include <cmath>
#include <iostream>

using namespace std;

/**
 * @brief Construct a new Utilities object and initialize all instance variables.
 *        Call the sieve function and pass the constant N set in the utils.h file
 */
Utilities::Utilities(): primeFactors(N + 1), listOfPrimes(){
  sieve(N);  
}

// linear sieveing function runs in O(n), similar concept to the SoE
void Utilities::sieve(int n){

  // loop through the indecies array
  for (int i = 2; i <= n; i++) {
    // if a prime number is found
    if (primeFactors.at(i) == 0) {
      primeFactors.at(i) = i;   // set the indecie to the prime number
      listOfPrimes.push_back(i);  // add the prime number to the list of primes
    }
    
    // loop through the rest of the prime factors array and set all the factors of the prime to != 0 (a.k.a not prime)
    for (int j = 0; j < (int)listOfPrimes.size() && listOfPrimes.at(j) <= primeFactors.at(i) && i * listOfPrimes.at(j) <= n; j++)
      primeFactors[i * listOfPrimes.at(j)] = listOfPrimes.at(j);
    
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
  long int s;
  long int t;
  int gcd = xgcd(e, phi, s, t);

  return s % phi;
}

/**
 * @brief Recursive Extended Euclidean algorithm. returns the bezout coefficienst such that as + bt = g
 * 
 * @param a the first number
 * @param b the second number
 * @param s the first bezout coefficient
 * @param t the second bezout coefficient
 * @return int g the gcd
 */
int Utilities::xgcd(long int a, long int b, long int & s, long int & t) {

  // base case
  if(b == 0){
    s = 1;
    t = 0;
    return a;
  }

  // teporary variables for recursive call
  long int x1;
  long int y1;
  int gcd = xgcd(b, a % b, x1, y1);
  s = y1;
  t = x1 - (a / b) * y1;
  return gcd;
}

/**
 * @brief Square and multiply algorithm for binary exponentiation.
 * This algorithm essentially checks every bit of the binary representation of the exponent from MSB (most significant bit)
 * to LSB (least significant bit). If the bit is a 1, the base is squared AND multiplied. If the bit is a 0, the base is ONLY squared.
 * A more detailed explanation can be found here: https://www.youtube.com/watch?v=cbGB__V8MNk.
 * 
 * @param base the base in the expontntiation functoin 'a'
 * @param exp the exponent 'b'
 * @param m the modulus 'm'
 * @return result of a^b mod m 
 */
int Utilities::fastExpMod(ll base, long exp, ll m) {
  // initialize the result
  ll result = 1;

  // basic edge case
  if (base == 0)
    return 0;

  // loop until we reduce the exponent to 0 or less
  while (exp > 0) {
    
    // bitwise and with 1 is equivalent to exp % 2 == 0 only faster to compute
    if (exp & 1)
      result = modularMultiply(result, base, m);  // Multiply
    
    // bitshift right is the same as division by 2 only faster to compute
    exp >>= 1;
    base = modularMultiply(base, base, m);  // Squaring operation
  }

  return result;
}

/**
 * @brief a method to compute a * b mod m (a*b % m). This allows the program to compute large multiplications where both a and b 
 * are smaller than the modulus m, and thus cannot be reduced using the formula: (a*b % m) = ((a%m) * (b%m)) % m.
 * 
 * @param a first number to be multiplied with
 * @param b the second number to be multiplied with
 * @param mod the mudulus
 * @return ll a long long int value containting the result of the multiplication
 */
ll Utilities::modularMultiply(ll a, ll b, ll mod) {
	ll res = 0; // Initialize result

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
