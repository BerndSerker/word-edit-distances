#include "stdafx.h"
#include <iostream>
#include <vector>
#include "WordSplitter.h"
#include <algorithm>
using namespace std;

WordSplitter::WordSplitter() {
}


WordInfix* WordSplitter::split(string word, int bound) {
	if (bound < word.length() && bound > 0) {
		WordInfix* infix = new WordInfix(word, bound, nullptr, normal);

		//split the infix until bound + 1 leaves are created
		this->splitInfix(word, bound, infix);

		return infix;
	}
	return new WordInfix(word);
}

bool WordSplitter::isEven(int bound) {
	return (bound % 2 == 0);
}

void WordSplitter::splitInfix(string infix, int bound, WordInfix *parent) {
	vector<string> parts = this->halfInfix(infix);

	//check if we are deep enough in the tree to stop splitting
	if (bound >= 0 && parts.size() > 1) {
		bool even = this->isEven(bound);

		bound = (bound / 2);

		bool leaf = bound == 0;

		//first branch
		WordInfix* child = new WordInfix(parts[0], bound, parent, Filter::normal);
		parent->addChild(child);

		if (!leaf) {
			this->splitInfix(parts[0], bound, child);
		}

		//decrease bound so that b1 + b2 + 1 = b
		if (even) {
			bound -= 1;
		}

		//second branch
		child = new WordInfix(parts[1], bound, parent, Filter::reverse);
		parent->addChild(child);

		if (!leaf) {
			this->splitInfix(parts[1], bound, child);
		}

	}
}

vector<string> WordSplitter::halfInfix(string infix) {
	vector<string> infixes;

	if (infix.length() > 1) {
		size_t half = infix.length() / 2 + (infix.length() % 2);

		infixes.push_back(infix.substr(0, half));
		infixes.push_back(infix.substr(half, infix.length()));
	}
	else {
		infixes.push_back(infix);
	}

	return infixes;
}
