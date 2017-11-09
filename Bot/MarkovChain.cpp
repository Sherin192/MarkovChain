#include "MarkovChain.h"

void MarkovChain::addString(std::string str)
{
	std::stringstream ss(str.c_str());				//this holds the whole string 
	std::string word{};
	std::vector<std::string> index = {"", ""};
	ss >> word;


	auto compareString = [&](std::string s) { return s == word; };


	if (std::find_if(vocabulary[index].begin(), vocabulary[index].end(), compareString) == vocabulary[index].end())
		vocabulary[index].push_back(word);

	do
	{
		std::string next = word;
		ss >> word;
		
		index[0] = index[1];
		index[1] = next;

		std::vector<std::string>::iterator it = std::find_if(vocabulary[index].begin(), vocabulary[index].end(), compareString);

		if (it == vocabulary[index].end())
			vocabulary[index].push_back(word);

	} while (!ss.eof());
}

std::string MarkovChain::getSentence()
{
	std::vector<std::string> i {"", ""};
	std::string res {};

	while (true)
	{
		unsigned int index = 0;
		if (vocabulary[i].size() > 1)
		{
			std::uniform_int_distribution<int> uid(0, vocabulary[i].size() - 1);
			index = uid(engine);
		}

		if (!vocabulary[i].empty())
		{
			
				
			res == ""? res += vocabulary[i][index] : res += " " + vocabulary[i][index];

			if (vocabulary[i][index].find('.') != std::string::npos || vocabulary[i][index].find('?') != std::string::npos || vocabulary[i][index].find('!') != std::string::npos) break;

			std::string next = vocabulary[i][index];
			i[0] = i[1];
			i[1] = next;
		}
		else
			break;

	}
	return res;
}

void MarkovChain::addFile(char * path)
{
	std::ifstream in(path);
	std::string str;
	std::stringstream ss;
	std::string word;
	std::vector<std::string> index {"", ""};

	while (!in.eof())
	{
		#ifdef DEBUG
		if (!in.good())
			std::cout << "Wrong path th file: " << path << '\n';
		#endif

		index[0] = "";
		index[1] = "";
		std::getline(in, str);

		#ifdef DEBUG
			std::cout << "str: " << str<< '\n';
		#endif

		ss.clear();
		word = "";
		ss.str(str.c_str());

		ss >> word;

		auto compareString = [&](std::string s) { return s == word; };

		if (std::find_if(vocabulary[index].begin(), vocabulary[index].end(), compareString) == vocabulary[index].end())
			vocabulary[index].push_back(word);

		do
		{
			std::string next = word;
			ss >> word;
			
				index[0] = index[1];
				index[1] = next;
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
void MarkovChain::displayMap()
{
	for (auto it = vocabulary.begin(); it != vocabulary.end(); it++)
	{
		#ifdef DEBUG
		std::cout << "(" <<(*it).first[0] << ", " << (*it).first[1] << "): ";
		#endif	
		for (auto itr = (*it).second.begin(); itr != (*it).second.end(); itr++)
		{
			#ifdef DEBUG
				std::cout << *itr << ", ";
			#endif
		}
		#ifdef DEBUG
			std::cout << '\n';
		#endif	
	}
}