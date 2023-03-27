/*
views::stride contains nth elments from base view. starting from zero.
It can be helpful in column order traversal.
*/

#include <iostream>
#include <ranges>
#include <vector>
#include <string_view>
using namespace std::literals;

int main() {

auto text = "Hello   World!"sv;

// Iterate over every second element:
for (auto c : text | std::views::stride(2))
    std::cout << c << " ";
std::cout << "\n";

// Same but shifted by one by dropping the first element:
for (auto c : text | std::views::drop(1) | std::views::stride(2))
    std::cout << " " << c;
std::cout << "\n";
/* Prints:
H l o   W r d 
 e l     o l !
*/

std::cout << "\n";

std::vector<int> data{1,2,3,4,5,6,7,8,9};

// Treat data as a 3x3 2D array and do column-order traversal:
for (auto column : std::views::iota(0,3)) {
    for (auto e : data | std::views::drop(column) | std::views::stride(3))
        std::cout << e << " ";
    std::cout << "\n";
}
/* Prints:
1 4 7
2 5 8
3 6 9
*/

}