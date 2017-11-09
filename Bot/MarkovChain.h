#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
#include <random>
//#define DEBUG
#ifdef DEBUG
#include <iostream>
#endif
static std::random_device r_dev;
static std::mt19937 engine(r_dev());

class MarkovChain
{
	std::map< std::vector<std::string>, std::vector<std::string> > vocabulary;
	int order;
public:
	MarkovChain() {}
	MarkovChain(std::string str, int order) : order(order) { addString(str); }

	void addFile(char*);
	void addString(std::string);

	std::string getSentence();

	void displayMap();
	
};