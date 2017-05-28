#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector<int *> a(2);
    int num1 = 5;
    int num2 = 10;

    a[0] = &num1;
    a[1] = &num2;

    cout << *a[0] << " " << *a[1] << endl
         << endl;

    num1 = 200;
    num2 = 1000;

    cout << *a[0] << " " << *a[1] << endl
         << endl;

    return 0;
}