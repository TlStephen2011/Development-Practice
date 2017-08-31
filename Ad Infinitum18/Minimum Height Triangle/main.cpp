#include <bits/stdc++.h>

using namespace std;

int main() {
  int area, base;
  cin >> base >> area;

  int height;
  height = ceil(2.0 * area / base);
  cout << height << endl;

  return 0;
}
