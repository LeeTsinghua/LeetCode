#include <string>
#include <iostream>

int main()
{
	std::string foo("quuuux");
	std::string bar;
	foo.copy(bar, sizeof bar);
	bar[6] = '\0';
	std::cout << bar << '\n';
}