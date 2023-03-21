// Cplusplus-17-features.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//feature 1 ---nested namespace
namespace Country::State::City
{
    class Address
    {
    public:
        Address()
        {
            cout << "Address ctor called" << endl;
        }

    };
    
};
using namespace Country::State::City;
//feature 2 : if-else and Switch case along with Init Condition
void feature_if_with_init()
{
    string s("Hello");

    if (auto it = s.find('o'); it != s.npos)
    {
        cout << "element found" << endl;
    }
    else
    {
        cout << "not element found" << endl;
    }
    //cout << it << endl; ---gives you error

}

void feature_GCD_LCM()
{
    int x = 12;
    int y = 18;
}

void feature_string_view()
{
    string s("Hello world");
    /* this operation will not take any additional memory. It means s2 provides you a view (read only) of string s.
    * here all methods of s can be accessed or used by s2
    * */
    string_view s2 = s; 
    string_view s3 = s.substr(0, 3);

    cout << s2 << endl;
    cout << s3 << endl;
}


int main_all_features()
{
    //feature 1 ---nested namespace
    Address a;
    
    //feature 2 : if-else and Switch case along with Init Condition
    feature_if_with_init();

    //feature 3 : string_view
    feature_string_view();

    string x("hello");
    string y("world");
    return 1;

}


