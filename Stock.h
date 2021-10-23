#pragma once
//includes //
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "mooreAlgorithm.h"
#include "karpAlgorithm.h"

using namespace std;

class Stock
{
public:

	void constructList(int listSize);

	void displayList();

	vector<string> getList();

	vector<string>stockList;

	void removeStock(int toRemove);

	void addStock(int toAdd);

	void MooritemSearch(string item);

	void KarpitemSearch(string item);

	int size;

	queue<int>emptyItems;

	queue<string>itemMatch;
	

private:

	
	mooreAlgorithm moorSearcher;
	karpAlgorithm karpSearcher;

	// generators

	//colours
	string rainbow[25] =
	{ "red", "orange", "yellow", "green", "blue", //5
	"indigo", "violet", "black", "white", "pink", //10
	"teal", "turqoise", "aquamarine", "magenta", "emerald", //15
	"ruby", "grey", "gunmetal", "sapphire", "crimson", //20
	"gold", "maroon", "brown", "ivory", "ebony" }; //25

	//prefixes
	string prefix[50] =
	{
		"strange", "alluring", "ludicrous", "dull", "dry", "ancient", "narrow", "puzzling","noncholant","troubled",
		"special","tall","stimulating","perpetual","optimal","feeble","incredible","dramatic","obnoxious","damp",
		"mysterious","faulty","imported","exclusive","annoyed","cbd infused","invincible","scrawny","faded","enraged",
		"enchanted", "romantic","whiny","nondescript","unwieldy","nostalgic","lopsided","troubled","interesting","cagey",
		"doubtful","soft","grateful","unsettling","innocent","expensive","living", "mourning", "ignorant", "unhinged" 
	};

	string items[50] =
	{
		"food","tire","swing","zipper","bottle","ipod","hair tie","mop","bag","sponge",
		"house","air freshener","desk","packing peanuts","tomato","money","window","newspaper","toe ring","greeting card",
		"soap","headphones","tooth picks","blouse","sailboat","beef","chair","sun glasses","sharpie","toothpaste",
		"perfume","candy wrapper","phone","stockings","USB drive","shoes","boom box","glow stick","toilet","rubber duck",
		"video game","shawl","credit card","bookmark","piano","remote", "monitor", "chocolate","flowers", "bottle cap" };

};

