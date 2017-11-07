#include "MarkovChain.h"

void MarkovChain::addString(std::string str)
{
	std::stringstream ss(str.c_str());				//this holds the whole string 
	std::string word{};
	std::string index = "";
	ss >> word;

	auto compareString = [&](std::string s) { return s == word; };

	if (std::find_if(vocabulary[index].begin(), vocabulary[index].end(), compareString) == vocabulary[index].end())
		vocabulary[index].push_back(word);

	do
	{
		if (word.find('.') != std::string::npos)
			index = "";
		else
			index = word;

		ss >> word;
		std::vector<std::string>::iterator it = std::find_if(vocabulary[index].begin(), vocabulary[index].end(), compareString);

		if (it == vocabulary[index].end())
			vocabulary[index].push_back(word);

	} while (!ss.eof());
}

std::string MarkovChain::getSentence()
{

	std::string i {};
	std::string res {};

	while (true)
	{
		unsigned int index = 0;
		if (vocabulary[i].size() > 1)
		{
			//std::cout << "vocabulary[" << i << "] has size: " << vocabulary[i].size() << '\n';
			//std::default_random_engine generator;
			//std::uniform_int_distribution<int> distribution(0, vocabulary[i].size() - 1);
			//std::cout << "vocabulary[ "<< i << " ].size() :" << vocabulary[i].size() << '\n';
			std::uniform_int_distribution<int> uid(0, vocabulary[i].size() - 1);
			index = uid(engine);
			//std::cout << "index: " << index << '\n';
		}
		if (!vocabulary[i].empty())
		{
			if (res == "")
				res += vocabulary[i][index];
			else
				res += " " + vocabulary[i][index];
			//res == ""? res += vocabulary[i][index] : res += " " + vocabulary[i][index];

			if (vocabulary[i][index].find('.') != std::string::npos) break;

			i = vocabulary[i][index];
		}
		else
			break;

		if (i == "")
			break;
	}
	return res;
}

void MarkovChain::addFile(char * path)
{
	std::ifstream in(path);
	std::string str;
	std::stringstream ss;				
	std::string word{};
	std::string index = "";

	while (!in.eof())
	{
		#ifdef DEBUG
		if (!in.good())
			std::cout << "Wrong path th file: " << path << '\n';
		#endif

		std::getline(in, str);
		#ifdef DEBUG

			std::cout << "str: " << str<< '\n';
		#endif
		ss.clear();
		ss.str(str.c_str());
		ss >> word;

		auto compareString = [&](std::string s) { return s == word; };

		if (std::find_if(vocabulary[index].begin(), vocabulary[index].end(), compareString) == vocabulary[index].end())
			vocabulary[index].push_back(word);

		do
		{
			if (word.find('.') != std::string::npos)
				index = "";
			else
				index = word;

			ss >> word;
			#ifdef DEBUG

				std::cout << "Word: " << word << '\n';
			#endif
			std::vector<std::string>::iterator it = std::find_if(vocabulary[index].begin(), vocabulary[index].end(), compareString);

			if (it == vocabulary[index].end())
				vocabulary[index].push_back(word);

		} while (!ss.eof());

	}
	in.close();
}