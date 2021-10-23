// code referenced from, but edited and altered substantially 
//www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/

#include "karpAlgorithm.h"
using namespace std;

bool karpAlgorithm::search(string pattern, string text, int prime)
{
	/*patternLength = strlen(pattern);
	textLength = strlen(text);*/

	patternLength = pattern.size();
	textLength = text.size();

	hashP = 0;
	hashT = 0;
	h = 1;

	for (i = 0; i < patternLength - 1; i++)
	{
		h = (h * 256) % prime;
	}

	if (patternLength > textLength)
	{
		return false;
	}

	// calculate the hash of the pattern first bit of text

	for (i = 0; i < patternLength; i++)
	{
		hashP = (256 * hashP + pattern[i]) % prime;
		hashT = (256 * hashT + text[i]) % prime;
	}

	for (i = 0; i <= textLength - patternLength; i++)
	{

		// if hash values match then check individual characters
		if (hashP == hashT)
		{
			//check individual chars
			for (j = 0; j < patternLength; j++)
			{
				if (text[i + j] != pattern[j])
				{
					break;
				}
			}

			if (j == patternLength)
			{
				cout << "Item Found." << "\n";
				return true;
			}
		}
			

		// calculate hash for next bit of text by and remove leading and trail digit 
		if (i < textLength - patternLength)
		{
			hashT = (256 * (hashT - text[i] * h) + text[i + patternLength]) % prime;
			// t could be negative so need to convert to positive 
			if (hashT < 0)
			{
				hashT = (hashT + prime);
			}
		}

	}

	return false;

}