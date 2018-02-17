#pragma once
#include <iostream>
#include <list>
#include <vector>
#include "WordInfix.h"
using namespace std;

class WordSplitter{
public:
	WordSplitter();
	WordInfix* split(string word, int bound);

private:
	void splitInfix(string infix, int bound, WordInfix *parent);
	vector<string> halfInfix(string infix);
	bool isEven(int bound);
};

