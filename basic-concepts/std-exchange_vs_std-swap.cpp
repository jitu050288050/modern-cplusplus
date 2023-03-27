/******************************************************************************
difference between std::swap and std::Exchange ( present in utility header file)
*******************************************************************************/

#include <iostream>
#include <utility>  // for std::exchange

using namespace std;

int main()
{
    int a = 5;
    int b = 10;
    int c = 0;
    //here a -> b and c -> a
    cout <<"before calling std::exchange a : "<<a <<" b: "<<b <<" c: "<<c <<endl;
    c = std::exchange(a,b);
    
    cout <<"after calling std::exchange a : "<<a <<" b: "<<b <<" c: "<<c <<endl;
    
    a = 5;
    b = 10;
    cout <<"before calling std::Swap a : "<<a <<" b: "<<b <<" c: "<<c <<endl;
    std::swap(a,b);
    
    cout <<"after calling std::swap a : "<<a <<" b: "<<b <<" c: "<<c <<endl;
    
    return 0;
}
