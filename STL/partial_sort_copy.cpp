/*

Source URL:
Concept:

TakeAways:

*/



#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

int main() {
    std::vector<int> top_five(5);
    std::vector<int> v{2,5,1,7,9,13,11,43};
    std::partial_sort_copy(v.begin(),v.end(),top_five.begin(), top_five.end(),std::less<int>{});

    for(auto x : top_five)
    {
        std::cout <<x<<std::endl;
    }
 
}