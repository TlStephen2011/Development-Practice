#include <bits/stdc++.h>
using namespace std;

long long modularPow(long long base, long long exponent, int modulus) {
  long long result = 1;
  while (exponent > 0) {
    if (exponent % 2 == 1)
      result = (result * base) % modulus;
    exponent = exponent >> 1;
    base = (base * base) % modulus;
  }
  return result;
}

// function to calculate the modulo of the substring by using
// the components of the conversion to decimal.
int moduloSub(string substr_, int m, int b) {
  int sum = 0;
  int start = substr_.length() - 1;
  int power = 0;
  while (start >= 0) {
    stringstream stm;
    stm << substr_[start];
    unsigned long long val;
    stm >> val;
    if (val != 0) {
      val = (val % m) * (modularPow(b, power, m)) % m;
      sum += val;
    }
    power++;
    start--;
  }
  return sum % m;
}

int getMagicNumber(string s, int k, int b, int m) {
  int sum = 0;
  int pos = 0;
  while (pos + k <= s.length()) {
    string sub = s.substr(pos, k);
    sum += moduloSub(sub, m, b);
    pos++;
  }
  return sum;
}

int main() {
  string s;
  cin >> s;
  int k;
  int b;
  int m;
  cin >> k >> b >> m;
  int result = getMagicNumber(s, k, b, m);
  cout << result << endl;
  return 0;
}
