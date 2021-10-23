// code referenced from, but edited and altered substantially 
// www.geeksforgeeks.org/boyer-moore-algorithm-good-suffix-heuristic/?ref=rp
//www.geeksforgeeks.org/boyer-moore-algorithm-for-pattern-searching/


#include "mooreAlgorithm.h"
#include <string>
#include <iostream>
#include <vector>
#include "math.h";

using namespace std;

  

void mooreAlgorithm::getSearch(string pattern) // size of the patter we're looking for 
{
	patternSize = pattern.size();
}

void mooreAlgorithm::getList(vector<string>list) //  size of the list we're searching through
{
	listSize = list.size();
}


// The preprocessing function for Boyer Moore's  
// bad character heuristic  
void mooreAlgorithm:: badCharHeuristic(string text)
{
	int i;

	// Initialize all occurrences as -1  
	for (i = 0; i < NO_OF_CHARS; i++)
		badchar[i] = -1;

	// Fill the actual value of last occurrence of a character  
	for (i = 0; i < text.size(); i++)
		badchar[(int)text[i]] = i; // replacing with the ascii value 
}


// search algorithm

bool mooreAlgorithm:: search(string txt, string pat) // pass in the text and the pattern
{
	//int patternSize = pat.size();
	textSize = txt.size();

	

	// filling the ' bad char ' array by calling the function
	badCharHeuristic(pat);

	if (patternSize > textSize)
	{
		//cout << "too big" << "\n";
		return false;
	}

	shifter = 0; // a shift of the pattern relative to the text 

	while (shifter <= (textSize - patternSize))
	{
		finder = patternSize - 1;

		// reduces the index of patter while the characters of the pattern and text are matching at this shift
		while (finder >= 0 && pat[finder] == txt[shifter + finder])
		{
			finder--;
		}
		
		// if pattern is there at current shift, finder becomes -1
		if (finder < 0) // found the pattern 
		{
			cout << "Item Found."<< "\n"; //pattern found

			return true;
		}
		else 
		{
			//cout << "pattern has not been found yet"<<"\n"; // pattern not found
			shifter += sqrt((finder - badchar[txt[shifter + finder]]) * (finder - badchar[txt[shifter + finder]]));
			
		}
			
	}
}
