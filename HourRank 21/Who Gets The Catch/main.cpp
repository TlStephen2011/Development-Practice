#include <bits/stdc++.h>

using namespace std;

int whoGetsTheCatch(int n, int x, vector<int> X, vector<int> V) {
  // find the position of the fastest catcher to the catch.
  int posOfFastest = 0;
  int fastestTime = (abs(X[0] - x)) / V[0];
  for (int i = 1; i < X.size(); ++i) {
    int timeNext = (abs(X[i] - x)) / V[i];
    if (timeNext < fastestTime) {
      fastestTime = timeNext;
      posOfFastest = i;
    }
  }
  // check if fastestTime occurs more than once.
  for (int i = 0; i < X.size(); ++i) {
    int timeNext = (abs(X[i] - x)) / V[i];
    if (fastestTime == timeNext && posOfFastest != i) {
      return -1;
    }
  }

  return posOfFastest;
}

int main() {
  //  Return the index of the catcher who gets the catch, or -1 if no one gets
  //  the catch.
  int n;
  int x;
  cin >> n >> x;
  vector<int> X(n);
  for (int X_i = 0; X_i < n; X_i++) {
    cin >> X[X_i];
  }
  vector<int> V(n);
  for (int V_i = 0; V_i < n; V_i++) {
    cin >> V[V_i];
  }
  int result = whoGetsTheCatch(n, x, X, V);
  cout << result << endl;
  return 0;
}
