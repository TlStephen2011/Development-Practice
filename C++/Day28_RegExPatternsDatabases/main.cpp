#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
//started using atom editor
using namespace std;

class Details {
 public:
  string firstName;
  string emailID;
  Details(string a, string b) {
    firstName = a;
    emailID = b;
  }
};

Details *lowerOf(Details *d1, Details *d2) {
  if (d1->firstName.size() > d2->firstName.size()) {
    for (int i = 0; i < d2->firstName.size(); i++) {
      int a = int(d1->firstName[i]);
      int b = int(d2->firstName[i]);
      if (a < b) {
        return d1;
      } else if (a > b) {
        return d2;
      }
    }
  } else {
    for (int i = 0; i < d1->firstName.size(); i++) {
      int a = int(d1->firstName[i]);
      int b = int(d2->firstName[i]);
      if (a < b) {
        return d1;
      } else if (a > b) {
        return d2;
      }
    }
  }
  return d1->firstName.size() > d2->firstName.size() ? d2 : d1;
}

int main() {
  int N;
  cin >> N;
  vector<Details *> database;
  for (int a0 = 0; a0 < N; a0++) {
    string firstName;
    string emailID;
    cin >> firstName >> emailID;
    Details *d = new Details(firstName, emailID);
    database.push_back(d);
  }

  for (int i = database.size() - 1; i >= 0; i--) {
    int pos = database[i]->emailID.find("@");
    string host = database[i]->emailID.substr(pos + 1);
    if (host != "gmail.com") {
      database.erase(database.begin() + i);
    }
  }

  while (database.size() > 0)  // might be no need for while
  {
    // find the lowest database member
    Details *d = database[database.size() - 1];
    int pos = database.size() - 1;
    for (int i = database.size() - 1; i >= 0; i--) {
      // maybe try use a bubble sort using lowerOf function to sort the vector.
    }
    // display it
    cout << d->firstName << endl;  // use loop to display sorted vector.
    // erase it
    database.erase(database.begin() +
                   pos);  // dont need to erase if vector is sorted.
  }

  return 0;
}
