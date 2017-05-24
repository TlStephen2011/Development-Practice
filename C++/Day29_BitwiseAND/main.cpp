#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string convertToBinary(int val) {
  int rem = 0;
  string binary;
  while (val != 0) {
    rem = val % 2;
    stringstream stm;
    stm << rem;
    binary += stm.str();
    val /= 2;
  }

  reverse(binary.begin(), binary.end());
  return binary;
}

class Value {
public:
  string bin_a;
  string bin_b;
  Value(int a, int b) {
    bin_a = convertToBinary(a);
    bin_b = convertToBinary(b);
  }
  int bitwiseAnd() {
    // determine which bin number is largest
    string *largest;
    string *smallest;
    if (bin_a.length() > bin_b.length()) {
      largest = &bin_a;
      smallest = &bin_b;
    } else {
      largest = &bin_b;
      smallest = &bin_a;
    }
    // add leading 0's to smallest to make it equal
    string temp = *smallest;
    (*smallest) = "";
    while ((*smallest).length() + temp.length() <= (*largest).length()) {
      (*smallest) += "0";
    }
    (*smallest) += temp;
    //add up number of true answers
    int counter = 0;
    for (int i = 0; i < bin_a.length(); i++) {
      if (bin_a[i] == bin_b[i] && bin_a[i] == '1') {
        counter++;
      }
    }
    return counter;
  }
};

int main() {

  int T, N, K;
  cin >> T;
  vector<int> answers;
  vector<Value*> combinations;
  for (int a_ = 0; a_ < T; a_++) {
    cin >> N >> K;
    // make a new value object for each combo
    for (int i = 1; i < N; i++) {
      for (int j = i + 1; j <= N; j++) {
        int arr[2] = {i, j};
        Value *values = new Value(i, j);
        combinations.push_back(values);
      }
    }
    int max = 0;
    for(int i = 0; i < combinations.size(); i++){
      int temp = combinations[i]->bitwiseAnd();
      if(temp > max && temp < K){
        max = temp;
      }
    }

    answers.push_back(N);
    answers.push_back(K);
    answers.push_back(max);
  }
  return 0;
}
