
#include <cassert>
#include <iostream>
#include <vector>
#include "Stock.h"
#include <chrono>
// timer code //stackoverflow.com/questions/23615776/measure-time-milliseconds-or-microseconds-for-windows-c
#include "mooreAlgorithm.h"

// importing libs 

using std::cin;
using std::cout;
using std::endl;

// main loop

int main(int argc, char* argv[])
{
	
	
	
	Stock smallStock; // create an object for the small stock list

	mooreAlgorithm mooreSearch; // create an object for the search algorithm

	int stockSize;
	cout << "enter the number items to display\n";
	cin >> stockSize;
	cout << "getting the stock list" << "\n\n";

	smallStock.constructList(stockSize); // create the list

	smallStock.displayList(); // display the list 

	cout << "\n\n"; // two blank lines to separate

	int inpt = -1;
	

	while (inpt != 0)
	{
		inpt = -1;

		cout << "enter 1 to search, 2 to add items, 3 to remove items, 0 to quit\n";

		cin >> inpt;

		if (inpt == 1) // searching
		{
			string item;
			cout << "enter 1 to use moore search, 2 to use karp search\n";
			cin >> inpt;

			if (inpt == 1)
			{
				cout << "\n\n"; // blank lines to separate
				cout << "search for an item (moore)\n";
				cin >> item; // get the item to search for 
				auto timerStart = std::chrono::high_resolution_clock::now();
				smallStock.MooritemSearch(item);
				auto timerEnd = std::chrono::high_resolution_clock::now() - timerStart;
				cout << "Search Time: " << timerEnd / std::chrono::milliseconds(1) << ".ms" << "\n";
				cout << "\n\n"; // blank lines to separate
			}
			else if (inpt == 2)
			{
				cout << "\n\n"; // blank lines to separate
				cout << "search for an item (karp)\n";
				cin >> item; // get the item to search for
				auto timerStart = std::chrono::high_resolution_clock::now();
				smallStock.KarpitemSearch(item);
				auto timerEnd = std::chrono::high_resolution_clock::now() - timerStart;
				cout << "\nSearch Time: " << timerEnd / std::chrono::milliseconds(1) << ".ms" << "\n";
				cout << "\n\n"; // blank lines to separate
			}

		}
		else if (inpt == 2) // adding
		{
			int add;
			cout << "enter the number of items to add\n";
			cin >> add; // get the item
			smallStock.addStock(add); //add random items
			smallStock.displayList(); // display the new list
			cout << "\n\n"; // blank lines to separate
		}
		else if (inpt == 3) // removing
		{
			int remove;
			cout << "enter the number of items to remove\n";
			cin >> remove; // get the item
			smallStock.removeStock(remove); // remove number of items
			smallStock.displayList(); // display the new list
			cout << "\n\n"; // blank lines to separate

		}
		else if (inpt == 0)
		{
			break;
		}
		else 
		{
			cout << "invalid input\n";
		}

	}


	cout << "\n All OK! Press return to exit...\n";
	cin.get();

	return 0;
}


// comment dump

//smallStock.removeStock(9); // remove nine items

	//smallStock.displayList(); // display the new list

	//cout << "\n\n\n\n"; // four blank lines to separate

	//smallStock.addStock(5); //add five random items

	//smallStock.displayList(); //display the list

	//cout << "\n\n\n\n"; // four blank lines to separate


//mooreSearch.getList(smallStock.getList()); // get the vector list's size
	//mooreSearch.getSearch(item); // get the item to search for size

	//for (int i = 0; i < smallStock.getList().size(); i++) // loop through the size of the list 
	//{
	//	mooreSearch.search(smallStock.getList()[i], item);
	//}



	////display the list
	//for (int i = 0; i < 100; i++)
	//{
	//	firstList.push_front(smallStock.stockList[i]);

	//}

	/*firstList.print();*/

	//test the list 
	/*firstList.push_front("ninos");
	firstList.push_front("hola");
	firstList.print();*/