#include <memory>
#include <optional>
#include <string>
#include <iostream>
using namespace std;

/*
optional class template is used when the given function may or may not return something.
At any point in time, we can check whether object contains value or not.
No dynmamic memory allocation ever takes place.
It means optional object models an object not a pointer, however * and ->
operator can be used to get the underlying object.
nullopt_t : if optional object does not contains a value.
UseCase: 
A common use case for optional is the return value of a function that may fail. 
*/
auto fn1(bool b)
{
    if(b == true)
    {
        return std::optional<string>("jitendra"); 
    }
    else
    {
        return std::optional<string>(nullopt);
    }
}

void print_val(auto val)
{
    if(val.has_value() == true)
    {
        cout<<*val<<endl;
    }
    else
    {
        cout <<"optional object does not hold any value"<<endl;
    }
}
int main() {
    bool flag = false;

    auto res = fn1(flag);
    
    print_val(res);

    //change the value of flag to set
    flag = true;
    print_val(fn1(flag));
    return 0;
}