/*
Usage:
	Coroutines are mainly used for
	-> Generators
	-> Asynchronous I/O
	-> Lazy computations
	-> Event driven applications
*/


#include <iostream>
#include <experimental/generator>
#include <chrono>
using namespace std;
using namespace chrono;



experimental::generator<int> GetSeqGenerator(int startval, size_t numofValue)
{
	for (int i{ startval }; i < startval + numofValue; ++i)
	{
		time_t t{ chrono::system_clock::to_time_t(system_clock::now()) };

		cout << std::ctime(&t);

		co_yield i;
	}
}
using namespace std;
int main_featur_coroutines()
{
	auto gen{ GetSeqGenerator(10,5) };

	for (const auto& value : gen)
	{
		cout << value << "press enter for next value" << endl;
		cin.ignore();
	}

	return 1;
}