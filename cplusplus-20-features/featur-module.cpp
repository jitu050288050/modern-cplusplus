// cplusplus-20-features.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 1. Modules
/*
* Advantages:
*   ->fast compilation time because modules are build only once.
*   ->gives better encapusation because in the exported module only function signature are exported not body however in case of headder file
*     if we give def of function inside header file than that is also given which requires to compile all the files.
*   -> order of importing module does not matter unlikely header files.
*   -> if you write your own modules and export them then Macros are not exported. However if you import STL bigger modules like version then Macros are also imported.
*/


#include <iostream>
using namespace std;
import cppcon;
int main_featur_module()
{
    string s = cppcon::GetWelcome();
    cout << s << endl;
    return 1;
}


