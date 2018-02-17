#include "stdafx.h"
#include "WordInfix.h"
#include <iostream>
#include <string>
using namespace std;

/*
* Object holding an infix of a word
*/
WordInfix::WordInfix(string infix) {
	this->infix = infix;
}

WordInfix::WordInfix(string infix, int bound, WordInfix *parent, Filter filter) {
	this->infix = infix;
	this->bound = bound;
	this->parent = parent;
	this->filter = filter;
}

string WordInfix::getInfix() {
	return infix;
}

int WordInfix::getBound() {
	return bound;
}

WordInfix * WordInfix::getParent() {
	return parent;
}

list<WordInfix*> WordInfix::getChildren() {
	return children;
}

void WordInfix::addChild(WordInfix * child) {
	this->children.push_back(child);
}

string WordInfix::print() {
	string bnd = to_string(this->getBound());
	string prnt = "Infix '" + this->getInfix() + "', bound "+bnd+", Filter: "+to_string(this->filter)+"\n";

	for (WordInfix* infix : this->getChildren()) {
		prnt += infix->print();
	}

	return prnt;
}