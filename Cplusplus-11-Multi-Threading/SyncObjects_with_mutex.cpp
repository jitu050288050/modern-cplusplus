#include <iostream>
#include <thread>
#include <list>
#include <algorithm>
#include<mutex>


using namespace std;

// a global variable
std::list<int> myList_with_mutex;

std::mutex m;

void addToList_with_mutex(int max, int interval)
{
	std::lock_guard<std::mutex> gaurd(m);
	for (int i = 0; i < max; i++) {
		if ((i % interval) == 0) myList_with_mutex.push_back(i);
	}
}

void printList_with_mutex()
{
	std::lock_guard<std::mutex> gaurd(m);
	for (auto itr = myList_with_mutex.begin(), end_itr = myList_with_mutex.end(); itr != end_itr; ++itr) {
		cout << *itr << ",";
	}
}

int main()
{
	int max = 100;

	std::thread t1(addToList_with_mutex, max, 1);
	std::thread t2(addToList_with_mutex, max, 10);
	std::thread t3(printList_with_mutex);

	t1.join();
	t2.join();
	t3.join();

	return 0;
}
