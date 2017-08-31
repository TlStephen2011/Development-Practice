#include <bits/stdc++.h>

using namespace std;

int countSolutions(int a, int b, int c, int d) {
  int x;
  int y;
  int counter = 0;
  for (int i = 1; i <= c; i++) {
    for (int j = 1; j <= d; j++) {
      x = i;
      y = j;

      long long LHS = x * x + y * y;
      long long RHS = (x * a) + (y * b);
      if (LHS == RHS) {
        counter++;
      }
    }
  }

  return counter;
}

int main() {
  int q;
  cin >> q;
  for (int a0 = 0; a0 < q; a0++) {
    int a;
    int b;
    int c;
    int d;
    cin >> a >> b >> c >> d;
    int result = countSolutions(a, b, c, d);
    cout << result << endl;
  }
  return 0;
}
