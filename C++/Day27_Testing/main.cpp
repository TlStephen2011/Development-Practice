#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class TestCase
{
  public:
    int n, k;
    vector<int> times;
    void chooseStudents()
    {
        n = rand() % 5 + 3;
    }
    void chooseThreshold()
    {
        k = rand() % n + 1;
    }
    void buildTimes()
    {
        bool isZero = false, isPos = false, isNeg = false;
        for (int i = 0; i < n; i++)
        {
            int r = rand() % 20 - 10;
            times.push_back(r);
        }

        for (int i = 0; i < times.size(); i++)
        {
            if (times[i] == 0)
            {
                isZero = true;
            }
            if (times[i] < 0)
            {
                isNeg = true;
            }
            if (times[i] > 0)
            {
                isPos = true;
            }
        }

        if (!isZero)
        {
            int r = rand() % n;
            times[r] = 0;
        }
        if (!isPos)
        {
            int r = rand() % n;
            times[r] = rand() % 10000 + 1;
        }
        if (!isNeg)
        {
            int r = rand() % n;
            times[r] = rand() % 10000 - 10000;
        }
    }
};

bool isDistinct(vector<TestCase> cases, int &pos)
{
    for (int i = 0; i < cases.size(); i++)
    {
        for (int j = 0; j < cases.size(); j++)
        {
            if (i != j && cases[i].n == cases[j].n)
            {
                pos = i;
                cout << "Is not distinct...replacing" << endl;
                return false;
            }
        }
    }

    return true;
}

void displayCases(vector<TestCase> t)
{
    for (int i = 0; i < t.size(); i++)
    {
        cout << t[i].n << " " << t[i].k << endl;
        for (int j = 0; j < t[i].times.size(); j++)
        {
            cout << t[i].times[j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    srand(time(0));
    int t = rand() % 5 + 1;
    t = 5;
    cout << t << endl;
    vector<TestCase> cases;
    for (int i = 0; i < t; i++)
    {
        TestCase x;
        x.chooseStudents();
        x.chooseThreshold();
        x.buildTimes();
        cases.push_back(x);
    }

    int index = -1;
    while (!isDistinct(cases, index))
    {
        TestCase replacement;
        replacement.chooseStudents();
        replacement.chooseThreshold();
        replacement.buildTimes();
        cases[index] = replacement;
    }

    displayCases(cases);

    return 0;
}
