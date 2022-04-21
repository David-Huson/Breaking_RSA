#include "utils.hpp"
#include <iostream>

using namespace std;

int main() {

  Utilities utils;
  long n;
  long c;
  int e;

  // get the private key pair (n, e) from the user and the cypher text c
  cout << "Enter n: ";
  cin >> n;
  cout << endl;
  cout << "Enter e: ";
  cin >> e;
  cout << endl;
  cout << "Enter the cypher text: ";
  cin >> c;
  cout << endl;
  
  // factor n into its prime factors n = p * q
  long int p = utils.primeFactor(n);
  int q = n / p;
  
  // calculate the totient phi
  long int phi = (p-1) * (q-1);

  // calculate the private key d
  long int d = utils.modularInverse(e, phi);

  cout << "The private key, d: " << d << endl;
  // now lets break this thing
  // feed the cypher text, private key, and public key n into the fastExpMod function do decrypt
  cout << utils.fastExpMod(c,d,n) << endl;
  return EXIT_SUCCESS;
}