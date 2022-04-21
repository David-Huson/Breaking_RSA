#ifndef UTILS_HPP
#define UTILS_HPP

typedef long long ll;

#include <vector>

class Utilities {
  // private
  // list of primes
  const int N = 500000;
  std::vector<int>  primeFactors;
  std::vector<int> listOfPrimes;
  void sieve(int size);
  int xgcd(long a, long b, long & x, long & y);
  bool willOverflow(ll a, ll b);

  public:
  Utilities();
  std::vector<int> primes;
  const std::vector<int> & getPrimes() const;
  int primeFactor(long int n);
  long modularInverse(int e, long phi);
  int fastExpMod(ll x, long y, ll m);
  int recMod(ll a, ll b, ll m);
  ll modularMultiply(ll a, ll b, ll mod);

};

#endif  // UTLS_HPP