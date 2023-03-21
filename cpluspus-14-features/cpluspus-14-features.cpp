// cpluspus-14-features.cpp : This file contains the 'main' function. Program execution begins and ends there.
// URL : youtube cppnuts c++14 features
// 1. Digit Separator : for better readibility using Singal Quatation Mark (SQM), there is no SQM apply rule
// 2. Binary Literals : Now we can write Binary numbers directly in form of 0 and 1.
// 3. Deprecated Attribute: If you want to deprecate some variable or function or class then you can do it via [[Deprecated]] syntax, compiler with give compile time error or warning.
// 4. Variable Template : Just like class template and function template in c++14 we can have template variable as well.
// 5. Generic lambdas : in c++14, auto keyword is allowed with lambda function as well.
//


#include <iostream>
#include <complex>
#include <string>
using namespace std;

void featur_digit_separator()
{
    auto x = 1'000'000;
    cout << x << endl;
}

void featur_binary_literal()
{
    int b1 = 0xFF; //Binary
    cout << b1 << endl;


    //Now withc c++14 we can directly write binary number followed by either '0b' or '0B'
    int b2 = 0b11111111;
    cout << b2 << endl;

}

//[[deprecated("this function will not be present in future release. So Stop using it.")]]
int featur_deprecated_attribute(int x, int y)
{
    return x + y;
}

//variable template 
template <typename T>
T pi = T(3.1412345678976);

auto featur_generic_lambda()
{
    auto s = [](auto x, auto y) { return x + y; };
    return s;
}


void test_featur_digit_separator()
{
    featur_digit_separator();
}
void test_featur_binary_literal()
{
    featur_binary_literal();
}

void test_featur_deprecated_attribute()
{
    featur_deprecated_attribute(2,3);
}

void test_featur_generic_lambda()
{
    auto x = featur_generic_lambda();
    cout << x(3, 4)<<endl;
    string s1 = "jitendra";
    string s2 = " persistent";
    cout << x(s1,s2) << endl;

    //cout << x(s1, 13) << endl; //gives you compile time error

    cout << x('a', 'b') << endl;
}

void test_featur_variable_template()
{
    pi<char> = 'a'; //template specialization
    cout.precision(std::numeric_limits<long double>::max_digits10);
    cout << pi<int> << endl; // will display 3
    cout << pi<float> << endl; 
    cout << pi<double> << endl; 
    cout << pi<long double> << endl; 
    cout << pi<char> << endl;
}

int main()
{
    test_featur_digit_separator();
    test_featur_binary_literal();
    //test_featur_deprecated_attribute(); --please read this feature as well
    test_featur_variable_template();
    test_featur_generic_lambda();
    return 1;
}


