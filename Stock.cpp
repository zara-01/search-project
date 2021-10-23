#include "Stock.h"
#include <random>
#include <ctime>


void Stock::constructList(int listSize)
{
	srand(time(0)); // seed the random

	for (int length = 0; length < listSize; length++) // loop for how large the vector should be 
	{
		string currentItem = ""; // a variable for the current item being generated
		string blank = " "; // a blank placeholder

		int randPrefix = rand() % 24 + 1; // a random generator for the prefix
		int randColour = rand() % 49 + 1; // a random generator for the colour
		int randItem = rand() % 49 + 1; // a random generator for the item 

		currentItem.append(prefix[randPrefix]); //append to the current item 
		currentItem.append(blank); // space

		currentItem.append(rainbow[randColour]); // append
		currentItem.append(blank); //space

		currentItem.append(items[randItem]); // append 

		stockList.push_back(currentItem); // add the item to the list 

	}

	size = stockList.size(); // size of the vector
}

void Stock::KarpitemSearch(string item)
{
	

	for (int i = 0; i < stockList.size(); i++)
	{
		//string txt[] = { stockList[i] };

		if (karpSearcher.search(item, stockList[i], 101) == true)
		{
			itemMatch.push(stockList[i]);
		}
	}

	if (itemMatch.size() > 0)
	{
		cout << "The searcher found these items:" << "\n";
		while (itemMatch.size() > 0)
		{
			cout <<" "<< itemMatch.front() << "\n";
			itemMatch.pop();
		}
	}
	else
	{
		cout << "\n" << "no matches were found.";
	}
}

void Stock::MooritemSearch(string item)
{
	//loop through the items

	moorSearcher.getList(stockList);
	moorSearcher.getSearch(item);

	for (int i = 0; i < stockList.size(); i++)
	{
		if (moorSearcher.search(stockList[i], item) == true)
		{
			itemMatch.push(stockList[i]);
		}
	}

	if (itemMatch.size() > 0)
	{
		cout << "The searcher found these items:" << "\n";
		while (itemMatch.size() > 0)
		{
			cout <<" "<< itemMatch.front() << "\n";
			itemMatch.pop();
		}
	}
	else
	{
		cout << "\n" << "no matches were found.";
	}
}


vector<string> Stock::getList() // just returns the list 
{
	return stockList;
}

void Stock::addStock(int toAdd) // adding items
{

	int count; // local count variable

	size += toAdd; // adds the number of items to be added to the total size of the list

	for (int i = 0; i < toAdd; i++)
	{
		string currentItem = " "; // a blank for the current item
		string blank = " "; // just a blank space

		// generating the random items
		int randPrefix = rand() % 24 + 1;
		int randColour = rand() % 49 + 1;
		int randItem = rand() % 49 + 1;

		currentItem.append(prefix[randPrefix]);
		currentItem.append(blank);

		currentItem.append(rainbow[randColour]);
		currentItem.append(blank);

		currentItem.append(items[randItem]);
		// item generated

		// if theres no more slots add the item
		if (emptyItems.size() == 0)
		{
			stockList.push_back(currentItem);
		}
		else // or assign the item to an emptied slot 
		{
			stockList[emptyItems.front()].assign(currentItem);
			emptyItems.pop();
		}
	}

}

void Stock::removeStock(int toRemove) // removing items
{

	if (toRemove > size) // if the number of items to be removed is larger than the actual size of the list 
	{
		cout << "more items to remove than in the stack. rip \n";
		return;
	}

	size -= toRemove; // take away the number of item's to be removed from the total size of the list 

	int count; //  an int to be randomised
	
	//loop for however many items are specified
	for (int i = 0; i < toRemove; i++)
	{
		// a number between 0 and the number of items - 1
		count = rand() % stockList.size();

		// if it's already been removed 
		while (stockList[count] == "")
		{
			count = rand() % stockList.size(); // cycle the random again 
		}

		// remove

		stockList[count].assign(""); //replace the item with a blank space
		emptyItems.push(count);

	}
}


// displayting the stock list 
void Stock::displayList()
{
	int count = 0; // init count

	//loop the list 
	cout << "Stock List:\n";
	while (stockList.size() != count)
	{
		if (stockList[count] != "")
		{
			cout << stockList[count] << "\n"; // display the item unless it is a blank
		}
		count++;
	}
}