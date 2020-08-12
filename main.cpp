#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cpr/cpr.h>

int main()
{
	std::cout << "hi and welcome to c++ steam discussion grabber. \n";
	std::cout << "enter steamapp number then press enter. \n";
	std::string app;
	std::cin >> app;
	std::cout << "enter discussion number then press enter. \n";
	std::string discussion;
	std::cin >> discussion;
	std::cout << "enter amount of pages in the discussion. (you can enter less if you only want pages 1 to x) \n";
	int pages;
	std::cin >> pages;
	std::cout << "downloading.... \n";
	// run checks or something idk lazy ass >:(
	std::ostringstream url;
	url << "https://steamcommunity.com/app/" << app << "/discussions/0/" << discussion;
	std::ostringstream filename;
	filename << app << "-" << discussion;
	// page number logic goes here
	for (int i = 1; i <= pages; i++) {
		if (pages > 1 && i > 1) {
			url.str(std::string());
			url << "https://steamcommunity.com/app/" << app << "/discussions/0/" << discussion << "?ctp=" << i;
		}
		if (i != 1) {
			filename.str(std::string());
			filename << app << "-" << discussion;
		}
		cpr::Response request = cpr::Get(cpr::Url{ url.str() });
		filename << "-page" << i << ".html";
		std::ofstream output(filename.str());
		output << request.text;
		output.close();
	}
	return 0;
}
