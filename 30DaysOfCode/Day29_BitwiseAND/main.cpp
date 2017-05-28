#include <bitset>
#include <iostream>
#include <vector>
// need to use actual bits...
using namespace std;

int main() {

  int T, N, K;
  cin >> T;
  vector<int> answer;
  for (int a_ = 0; a_ < T; a_++) {
    cin >> N >> K;
    vector<int> a;
    vector<int> b;
    // make 2 vectors that store all combos of a and b.
    for (int i = 1; i < N; i++) {
      for (int j = i + 1; j <= N; j++) {
        a.push_back(i);
        b.push_back(j);
      }
    }
    // for each value of a and b convert to bitset and check bitwise&.
    bitset<32> convertedMax;
    int max = 0;
    for (int i = 0; i < a.size(); i++) {
      bitset<32> bin_a = a[i];
      bitset<32> bin_b = b[i];
      // loop through the bitset
      for (int j = 0; j < 32; j++) {
        if (bin_a[j] == bin_b[j] && bin_a[j] == 1) {
          convertedMax[j] = 1;
        } else {
          convertedMax[j] = 0;
        }
      }
      int temp = (int)(convertedMax.to_ulong());
      if (temp > max && temp < K) {
        max = temp;
      }
    }
    answer.push_back(max);
  }

  for (int i = 0; i < answer.size(); i++) {
    cout << answer[i] << endl;
  }
  return 0;
}
