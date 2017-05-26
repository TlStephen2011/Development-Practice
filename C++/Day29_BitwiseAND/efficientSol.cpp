#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

int main() {

  int T, N, K;
  cin >> T;
  vector<int> answers;
  for (int a_ = 0; a_ < T; a_++) {
    cin >> N >> K;
    // if k-1 is even, then the answer is always k-1 because
    //(k-1)&(k-1+1) = k-1 ... i.e the valid combination of
    // a=k-1 and b=k (valid b/c N<=K)...therefore a&b = k-1
    // which is the highest attainable bitwise& less than K.
    // Now k-1 is odd, so we need to check if bit(k-1|k) <= N.
    // If true then answer is k-1 otherwise answer is k-2.
    bitset<32> x = K - 1;
    bitset<32> y = K;
    bitset<32> xORy;
    for (int i = 1; i <= 32; i++) {
      if (x[i] == 1 || y[i] == 1) {
        xORy[i] = 1;
      } else {
        xORy[i] = 0;
      }
    }
    int x_y = (int)(xORy.to_ulong());

    if (x_y <= N) {
      answers.push_back(K - 1);
    } else {
      answers.push_back(K - 2);
    }
  }

  for (int i = 0; i < answers.size(); i++) {
    cout << answers[i] << endl;
  }
  return 0;
}
