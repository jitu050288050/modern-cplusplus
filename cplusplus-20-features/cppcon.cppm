export module cppcon;

namespace cppcon {
	auto getWelcomeHelper() {
		return "Welcome to cppcon 2020";
	}

	export auto GetWelcome()
	{
		return getWelcomeHelper();
	}
}
