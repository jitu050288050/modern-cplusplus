#include <iostream>
#include <string>
using namespace std;


void before_feature()
{
	int x = 5;
	if (x == 5)
	{
		//do one job
	}
	else
	{
		//do another job
	}
}

template <typename T>
auto func(T const& value)
{
	if constexpr (is_integral<T>::value)
	{
		cout << "template type is integer" << endl;
		return value;
	}
	else
	{
		cout << "template type is not integer" << endl;
		return value.length();
	}
}
void after_feature()
{
	int x = 10;
	func<int>(x);

	string a("apple");
	func<string> (a);
}
int main_if_constexpr()
{
	before_feature();
	after_feature();
	return 1;
}