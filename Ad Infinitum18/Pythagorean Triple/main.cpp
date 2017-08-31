#include <bits/stdc++.h>

using namespace std;

vector<long long> pythagoreanTriple(int a) {
  bool isOdd = a % 2;
  vector<long long> triple;
  long long m, n, k, b, c;

  if (!isOdd) {
    m = a / 2;
    b = m * m - 1;
    c = m * m + 1;
  } else {
    k = (a - 1) / 2;
    m = k + 1;
    n = k;
    b = 2 * m * n;
    c = m * m + n * n;
  }

  triple.push_back(a);
  triple.push_back(b);
  triple.push_back(c);

  return triple;
}

int main() {
  int a;
  cin >> a;
  vector<long long> triple = pythagoreanTriple(a);
  for (ssize_t i = 0; i < triple.size(); i++) {
    cout << triple[i] << (i != triple.size() - 1 ? " " : "");
  }
  cout << endl;

  return 0;
}
