#include <iostream>
using namespace std;

/*
	Type Deduction:
		in c++98:
			Template has 2 type deduction rules:
				T -> by value
				(&T/T*) -> by reference or pointer

		c++11:
			added one more
				T&& -> universal reference.
			decltype

		c++14:
			decltype(auto)
			lambda init capture
	Universal reference -> either l-value reference or r-value reference based on how they are initialized
	-> If expr is l-value with deduced type E, T deduced as E&
	-> Reference collapsing yields type E& for param.
				
*/
template <typename T>
void f(T&& param)
{
}

/*
* pass by value : since function has its own copy. So it does not bother about constness of passed parameter or reference of passed paramter
*					it only worried about the type of passed paramter.
*/

template< typename T>
void f1(T param)
{

}
/*
* Auto never deduced to be a reference.
* It must be manually added.
*
*/


//Auto Type deduction is always the same except with braced initilizers.
/*
* Template type deduction fails.
* auto deduces std::initializer_list
*/
template <typename T>
void f2(T param)
{

}

int main_type_deduction()
{
	int x = 22;
	const int cx = x;
	const int& rx = x;

	auto& v1 = x;	// ? type of v1 and auto  @20-03-2023
	auto& v2 = cx;  // ? type of v1 and auto   @20-03-2023
	auto& v3 = rx;  // ? type of v1 and auto  @20-03-2023

	const auto& v4 = x;	// ? type of v4 and auto   @20-03-2023
	const auto& v5 = cx;  // ? type of v5 and auto  @20-03-2023
	const auto& v6 = rx;  // ? type of v6 and auto  @20-03-2023


	//universal reference
	f(x);  // @20-03-2023 what will be x = int(l-value), T = int& (l-value-ref) and param_type= int& (l-value-ref)
	f(cx); // @20-03-2023 what will be x , T and param-type
	f(rx); // @20-03-2023 what will be x , T and param-type
	f(22); // @20-03-2023 what will be x , T and param-type


	//pass by value
	f1(x);
	f1(cx);
	f1(rx);
	f1(22);


	//Non-reference Non-Pointer autos
	//complete independent copy
	// identical with Template deduction
	auto v7 = x;	// @20-03-2023 what will be type of ?
	auto v8 = cx;   // @20-03-2023 what will be type of ?
	auto v9 = rx;   // @20-03-2023 what will be type of ?



	//If present, use by reference rulesets. if you want reference in Auto
	auto v10 = x;
	auto& v11 = cx;
	auto&& v12 = rx;

	//Auto Type deduction is always the same except with braced initilizers.
	/*
	* Template type deduction fails.
	* auto deduces std::initializer_list
	*/

	//f2({ 1,2,3 }); // will give you error. Template type deduction fails, 
	//braced initialization does not have a type.
	//auto x1{ 1,2,3 }; //gives you error according to the law N3922


	//always prefer copy list initialization (with '=') for stability and predictibility.
	auto x2 = { 1,2,3 }; // x2 will be of std::initializer list.
	auto x3{ 17 }; // x3 will of int type
	auto x4 = { 17 }; // x4 will be of initilizer list.


	//Names as L value Expressions
	/*
	* Names are l-values, but decltype(name) rule beats decltype(expr) rule:
	*/
	int y;
	decltype(y); // here y is l-value name so decltype(y) will be int

	decltype((y)); // "(y)" is not a l-value name its a l-value expression so decltype(y) will be int&

	//Session -2 started
	// function Retun Type deduction
	/*
	* Deduced return type specifiers:
	* 
	* auto -> follows Template type deduction rules.
	* decltype(auto) -> follows decltype  type deduction rules.
	* 
	*/

	/*
	* Thumb Rule
	* use auto if a reference type would never be correct.
	* use declytype(auto) only if a reference type could be correct. "Perfect returning"
	*/


	return 1;
}