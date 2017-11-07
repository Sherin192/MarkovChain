#include <iostream>
#include <string>
#include <sstream>
#include <random>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include "MarkovChain.h"

//static std::random_device r_dev;
//static std::mt19937 engine(r_dev());




int main()
{
	MarkovChain chain;
	std::string s, res;

	chain.addFile("Alice.txt");
	int i = 0;
	while (i < 10)
	{
		//std::getline(std::cin, s);

		//chain.addString(s);

		res = chain.getSentence();

		std::cout << res << '\n';
		i++;
	}
	//std::string str;

	//std::getline(std::cin, str);

	//std::stringstream ss(str.c_str());

	//std::string world {};

	//std::map< std::string, std::vector<std::string> > vocabulary;
	//ss >> world;
	//std::string index = "";
	//vocabulary[index].push_back(world);
	//
	//do
	//{
	//	if (world.find('.') != std::string::npos)
	//		index = "";
	//	else
	//		index = world;
	//	ss >> world;
	//	std::vector<std::string>::iterator it = std::find_if(vocabulary[index].begin(), vocabulary[index].end(), [&](std::string s) { return s == world; });

	//	if (it == vocabulary[index].end())
	//		vocabulary[index].push_back(world);

	//	//vocabulary[index].push_back(ss >> world ? std::find_if(vocabulary[index].begin(), vocabulary[index].end(), [=](std::string s) {return s == world; })!= vocabulary[index].end()? "" : vocabulary[index].push_back(world) : "");
	//} while (!ss.eof());
	// 
	//
	//for (std::pair<std::string, std::vector<std::string>> p : vocabulary)
	//{
	//	int index = 0;
	//	/*if (p.second.size() > 1)
	//	{
	//		std::default_random_engine generator;
	//		std::uniform_int_distribution<int> distribution(0, p.second.size() - 1);
	//		index = distribution(generator);
	//	}*/
	//	for (std::string s : p.second)
	//	{
	//		std::cout << p.first << " -> " << s << '\n';
	//	}	
	//}
	////std::cout << world << '\n';

	//
	//for (int j = 0; j < 4; ++j)
	//{
	//	std::string i = "";
	//
	//while (true)
	//{	
	//	unsigned int index = 0;
	//	if (vocabulary[i].size() > 1)
	//	{
	//		//std::cout << "vocabulary[" << i << "] has size: " << vocabulary[i].size() << '\n';
	//		//std::default_random_engine generator;
	//		//std::uniform_int_distribution<int> distribution(0, vocabulary[i].size() - 1);
	//		//std::cout << "vocabulary[ "<< i << " ].size() :" << vocabulary[i].size() << '\n';
	//		std::uniform_int_distribution<int> uid(0, vocabulary[i].size() - 1);
	//		index = uid(engine);
	//		//std::cout << "index: " << index << '\n';
	//	}
	//	if (!vocabulary[i].empty())
	//	{
	//		std::cout << vocabulary[i][index] << " ";

	//		if (vocabulary[i][index].find('.') != std::string::npos) break;
	//		
	//		i = vocabulary[i][index];
	//	}
	//	else
	//		break;
	//	
	//	if (i == "")
	//		break;
	//}
	//}
	//std::cout << "End \n";
	//std::cin.get();
	//
	std::cin.get();
	return 0;
}