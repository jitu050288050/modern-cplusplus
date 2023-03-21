/*

*/

#include <iostream>
using namespace std;


template<typename T>
concept Incrementatble = requires(T x) { x++; ++x; };


//Type -1
template <Incrementatble T>
void Foo(T t)
{
}


//Type -2
template <typename T> requires Incrementatble<T>
void Foo1(T t)
{

}

//Type -3
template <typename T>
void Foo2(Incrementatble auto t)
{

}

/*
* Compound requirement
* 1. requires a non-throwing swap() method
* 2. requires size() method returning a size_t
*/

template <typename T>
concept C = requires (T & x, T & y) {
	//1. requires a non - throwing swap() method
	{x.swap(y)} noexcept;
	//2. requires size() method returning a size_t
	{x.size()} -> std::convertible_to<std::size_t>;
};


/* Combine existing concepts
*/

//Type -1
template <typename T> requires incrementable<T> && sortable<T> 
	void Foo3(T t)
	{

	}

//Type -2
	template <typename T> 
	concept C1 = incrementable<T> && sortable<T>;
	void Foo4(C1 auto t)
	{

	}
class Bar
{

};
int main()
{
	Bar b;
	//Foo3<Bar>(b); // gives you compile time error.
	return 1;
}