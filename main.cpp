#include "utils.hpp"
#include <iostream>
#include <cmath>
#include <cassert>
#include <climits>

using namespace std;

int main() {

  Utilities utils;
  long n;
  long c;
  int e;

  cout << "Enter n: ";
  cin >> n;
  cout << endl;
  cout << "Enter e: ";
  cin >> e;
  cout << endl;
  cout << "Enter the cypher text: ";
  cin >> c;
  cout << endl;
  

  long int p = utils.primeFactor(n);
  int q = n / p;
  
  cout << "factored: " << n << " = " << p << " * " << q << endl;

  // calculate the totient phi
  long int phi = (p-1) * (q-1);
  cout << "Totient: " << phi << endl;
  long int d = utils.modularInverse(e, phi);
  cout << "Private key \'d\': " << d << endl;
  cout << utils.fastExpMod(c,d,n) << endl;
  return EXIT_SUCCESS;
}