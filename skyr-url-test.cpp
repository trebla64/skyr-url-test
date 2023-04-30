// skyr-url-test.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <skyr/url.hpp>
#include <skyr/percent_encoding/percent_decode.hpp>

using namespace std;

int main()
{
	using namespace skyr::literals;

	auto url =
		"http://sub.example.إختبار:8090/\xcf\x80?a=1&c=2&b=\xe2\x80\x8d\xf0\x9f\x8c\x88"_url;

	std::cout << "Protocol: " << url.protocol() << std::endl;

	std::cout << "Domain?   " << std::boolalpha << url.is_domain() << std::endl;
	std::cout << "Domain:   " << url.hostname() << std::endl;
	std::cout << "Domain:   " << url.u8domain().value() << std::endl;

	std::cout << "Port:     " << url.port<std::uint16_t>().value() << std::endl;

	std::cout << "Pathname: "
			  << skyr::percent_decode(url.pathname()).value() << std::endl;

	std::cout << "Search parameters:" << std::endl;
	const auto &search = url.search_parameters();
	for (const auto &[key, value] : search)
	{
		std::cout << "  "
				  << "key: " << key << ", value = " << value << std::endl;
	}

	return 0;
}
