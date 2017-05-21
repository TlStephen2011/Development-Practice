#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Details
{
  public:
    string firstName;
    string emailID;
    Details(string a, string b)
    {
        firstName = a;
        emailID = b;
    }

    bool operator<=(const Details &d)
    {
        string smallerName;
        if (this->firstName.size() > d.firstName.size())
        {
            smallerName = d.firstName;
        }
        else
        {
            smallerName = this->firstName;
        }

        for (int i = 0; i < smallerName.size(); i++)
        {
            int a = this->firstName[i];
            int b = d.firstName[i];

            if (a < b)
            {
                return true;
            }
            else if (a > b)
            {
                return false;
            }
        }

        if (this->firstName.size() == d.firstName.size())
        {
            return true;
        }
        else if (this->firstName.size() > d.firstName.size())
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};

int main()
{
    int N;
    cin >> N;
    vector<Details *> database;
    for (int a0 = 0; a0 < N; a0++)
    {
        string firstName;
        string emailID;
        cin >> firstName >> emailID;
        Details *d = new Details(firstName, emailID);
        database.push_back(d);
    }

    for (int i = database.size() - 1; i >= 0; i--)
    {
        int pos = database[i]->emailID.find("@");
        string host = database[i]->emailID.substr(pos + 1);
        if (host != "gmail.com")
        {
            database.erase(database.begin() + i);
        }
    }

    while (database.size() > 0)
    {
        //find the lowest database member
        Details *d = database[database.size() - 1];
        int pos = database.size() - 1;
        for (int i = database.size() - 1; i >= 0; i--)
        {
            if (database[i] <= d) //this i believe is returning true all the time
            {
                d = database[i];
                pos = i;
            }
        }
        //display it
        cout << d->firstName << endl;
        //erase it
        database.erase(database.begin() + pos);
    }

    return 0;
}
