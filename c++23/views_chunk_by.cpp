#include <iostream>
#include <algorithm>
#include <ranges>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    std::vector<int> data{1,2,-4,-2,-1,8,7,3,4,-5,-5};

    auto lambda = [](const int& x, const int&y){
        return std::signbit(x) == std::signbit(y);
    };
    
    //views::chunk_by splits the data based on given binary predicate.
    // like here we are creating new chunk as soon as sign changes.
    for (auto res : data | std::views::chunk_by(lambda))
    {
        std::ranges::copy(res , std::ostream_iterator<int>(std::cout," "));
        std::cout<<"next chunk value"<<endl;
    }
    
}
/*
output
1 2 next chunk value
-4 -2 -1 next chunk value
8 7 3 4 next chunk value
-5 -5 next chunk value
*/
