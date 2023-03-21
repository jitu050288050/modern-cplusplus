#include <iostream>
#include <string>
#include <map>
using namespace std;

class structural_binding
{
private:
	map<string, string> fav_lang = {
		{"john","java"},
		{"caren","cplusplus"},
		{"peter","python"}
	};
public:
	void before_feature()
	{
		//using tuple
		int a, b, c;
		std::tie(a, b, c) = std::make_tuple(1, 2, 3);
	}
	void after_feature()
	{
		auto res = fav_lang.insert({ "gimmy","golang" }); // previously we need to check second value to verify the insertion.

		auto [position, success] = fav_lang.insert({ "pamela","pascal" });

		if (success)
		{
			cout << "insertion is successful" << endl;
		}
		else
		{
			cout << "insertion not successful" << endl;
		}
	}
	//more readibility because of structural binding of variables
	void iterate_over_map()
	{
		for (const auto& [name, lang] : fav_lang)
		{
			cout << "person " << name << " favorite language " << lang << "." << endl;
		}
	}
};




int main_structural_binding()
{
	structural_binding sb;
	sb.before_feature();
	sb.after_feature();
	sb.iterate_over_map();
	return 1;
}