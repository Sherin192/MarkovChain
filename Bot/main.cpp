#include <iostream>
#include <string>
#include <sstream>
#include <random>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include "MarkovChain.h"

int main()
{
	MarkovChain chain;
	std::string s, res;

	chain.addFile("Alice.txt");					//your text file
	int i = 0;

	chain.displayMap();
	std::cout << "--------------------------------------------------------------------- \n";
	while (i < 5)
	{
		//std::getline(std::cin, s);

		//chain.addString(s);
		//chain.displayMap();
		res = chain.getSentence();

		std::cout << res << '\n';
		i++;
	}

	std::cin.get();
	return 0;
}