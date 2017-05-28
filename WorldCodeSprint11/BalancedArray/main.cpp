#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> a) {
  int n = a.size();
  // get sum of left half
  int sum_left = 0;
  for (int i = 0; i < n / 2; i++) {
    sum_left += a[i];
  }
  // get sum of right half
  int sum_right = 0;
  for (int i = n / 2; i < n; i++) {
    sum_right += a[i];
  }

  // return absolute value of difference
  return abs(sum_left - sum_right);
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int a_i = 0; a_i < n; a_i++) {
    cin >> a[a_i];
  }
  int result = solve(a);
  cout << result << endl;
  return 0;
}
