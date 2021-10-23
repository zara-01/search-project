#pragma once
#include "mooreAlgorithm.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;
#define NO_OF_CHARS 256  

class mooreAlgorithm
{
public:

	void badCharHeuristic(string list);

	bool search(string txt, string pat);

	void getSearch(string pattern);

	void getList(vector<string>list);

private:

	int patternSize;
	int listSize;
	int badchar[NO_OF_CHARS];
	int finder;
	int shifter;
	int textSize;

};

