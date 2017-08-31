#include <bits/stdc++.h>

using namespace std;

long long modularPow(long long base, long long exponent, long long modulus) {
  long long result = 1;
  while (exponent > 0) {
    if (exponent % 2 == 1)
      result = (result * base) % modulus;
    exponent = exponent >> 1;
    base = (base * base) % modulus;
  }
  return result;
}

long long towerColoring(long long n) {
  // application of Fermats Little Theorem
  long long temp = modularPow(3, n, pow(10, 9) + 7 - 1);
  return modularPow(3, temp, pow(10, 9) + 7);
}

int main() {
  long long n;
  cin >> n;
  long long result = towerColoring(n);
  cout << result << endl;
  return 0;
}
