#include <sstream>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;


int main(){
    string S;
    cin >> S;
    int num;
    try{
        num = stoi(S); //stoi doesnt work in minGw
        cout << num << endl;
    } catch(...){
        cout << "Bad String" << endl;
    }


    return 0;
}
