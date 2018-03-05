#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum Filter { normal, reverse };

class WordInfix {

private:
	string infix;
	int bound = 0;
	WordInfix * parent;
	vector<WordInfix*> children = vector<WordInfix*>();
	Filter filter;

public:
	WordInfix(string infix, int bound, WordInfix* parent, Filter filter);
	WordInfix(string infix);

	string getInfix();
	int getBound();
	WordInfix getParent();

	vector<WordInfix*> getChildren();
	void addChild(WordInfix* infix);

	string print();
	bool isLeaf();
};

