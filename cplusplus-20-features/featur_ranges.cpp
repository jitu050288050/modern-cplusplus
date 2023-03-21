
/*
Adv:
	->provides nice and easier to read syntax.
	->eliminate the chances of mismatch begin/end iterators.

Bullet points:
	Range
	Range Based Algo
	Projection
	Views
	Range Factories
	Pipelining :- all this happens in lazy loading. You can work with infinite range as well.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
#include <string>

using namespace std;

struct fn
{
	bool operator()(const auto& x)
	{
		return x % 2 == 0;
	}
};

int main_featur_ranges()
{
	vector v{ 1,4,7,9,2,3,8 ,14,0};
	vector v2(v);
	sort(v.begin(), v.end()); // user can pass end or begin iterator of some other container as well. Compiler will not complain
	ranges::sort(v2);

	//pipelining
	auto result{ v
		| views::filter([](const auto& value) {return value % 2 == 0; }) //filters out odd values  --
		| views::transform([](const auto& value) {return value * 2.0; }) // multiplies remaining values by 2.0
		| views::drop(2) // drops the first two values
		| views::reverse
		| views::transform([](int i) { return to_string(i); })
	
	
	
	};

	//for_each(result.begin(), result.end(), [](const& int val) { cout << val << endl; });

	//working with infinite range

	//auto result1{ view::ints(10)
	//	| views::filter([](const auto& value) {return value % 2 == 0; }) //filters out odd values  --
	//	| views::transform([](const auto& value) {return value * 2.0; }) // multiplies remaining values by 2.0
	//	| views::drop(2) // drops the first two values
	//	| views::reverse
	//	| views::transform([](int i) { return to_string(i); })



	//};

	return 1;
}