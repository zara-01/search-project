#pragma once
#include <string>
#include <iostream>
#include <math.h>

using namespace std;

class karpAlgorithm
{
public: 

	bool search(string pattern, string text, int prime);
	/*void setPatternHash(string pattern[]);*/

private:
	int patternLength; // length of the pattern
	int textLength; // length of the text
	int i, j; // indexes
	int hashP; // hash value for the pattern
	int hashT; // hash value for the text
	int h;
	int patternHash;

};

