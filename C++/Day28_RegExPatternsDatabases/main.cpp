#include <iostream>
#include <string>
#include <vector>
// started using atom editor
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

  // deleting elements of database if they do no have host == @gmail.com
  for (int i = database.size() - 1; i >= 0; i--) {
    int pos = database[i]->emailID.find("@");
    string host = database[i]->emailID.substr(pos + 1);
    if (host != "gmail.com") {
      database.erase(database.begin() + i);
    }
  }

  // sort database using bubblesort
  for (int i = 0; i < database.size(); i++) {
    int numberOfSwaps = 0;

    for (int j = 0; j < database.size() - 1; j++) {
      Details *lower = lowerOf(database[j], database[j + 1]);
      if (lower->emailID == database[j + 1]->emailID) {
        Details *temp = database[j];
        database[j] = database[j + 1];
        database[j + 1] = temp;
        numberOfSwaps++;
      }
    }

    if (numberOfSwaps == 0) {
      break;
    }
  }

  // displaying firstNames from database
  for (int i = 0; i < database.size(); i++) {
    cout << database[i]->firstName << endl;
  }

  return 0;
}
