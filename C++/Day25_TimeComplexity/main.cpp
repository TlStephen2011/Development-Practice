#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    cin >> T;
    vector<int> data;
    for (int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        data.push_back(n);
    }

    for (int i = 0; i < data.size(); i++)
    {
        bool isPrime = true;
        if (data[i] != 1)
        {
            for (int j = 2; j <= sqrt(data[i]); j++)
            {
                if (data[i] % j == 0)
                {
                    isPrime = false;
                    break;
                }
            }
        }
        else
        {
            isPrime = false;
        }

        if (isPrime)
        {
            cout << "Prime" << endl;
        }
        else
        {
            cout << "Not prime" << endl;
        }
    }
    return 0;
}