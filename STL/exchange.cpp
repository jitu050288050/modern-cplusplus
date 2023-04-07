#include <utility>
#include <iostream>
struct EraseOnMove
{
    int _val;
    //parameterized ctor
    EraseOnMove(int val):_val(val)
    {

    }
    //move ctor
    // std::exchange as helper for move semantics
    EraseOnMove(EraseOnMove&& em):_val(std::exchange(em._val,0))
    {

    }
    //move assignment operator
    EraseOnMove& operator=(EraseOnMove &&em) 
    {
        _val = std::exchange(em._val,0);
        return *this;
    }
};

int main()
{
    EraseOnMove em1(5);
    EraseOnMove em2(std::move(em1));
    EraseOnMove em3(10);
    em3 = std::move(em2);
    return 0;
}