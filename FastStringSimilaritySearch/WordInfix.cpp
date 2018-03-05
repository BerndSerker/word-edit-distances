#include "stdafx.h"
#include "WordInfix.h"
#include <iostream>
#include <string>
using namespace std;

WordInfix::WordInfix(string infix) {
	this->infix = infix;
	this->bound = 0;
	this->parent = nullptr;
	this->filter = Filter::normal;
}

WordInfix::WordInfix(string infix, int bound, WordInfix* parent, Filter filter) {
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

WordInfix WordInfix::getParent() {
	return *parent;
}

vector<WordInfix*> WordInfix::getChildren() {
	return children;
}

bool WordInfix::isLeaf() {
	return this->getChildren().empty();
}

void WordInfix::addChild(WordInfix* child) {
	this->children.push_back(child);
}

string WordInfix::print() {
	string prnt = "";

	try {
		string bnd = to_string(this->getBound());
		string infix = this->getInfix();
		prnt = "Infix '" + infix + "', bound " + bnd + ", Filter: " + to_string(this->filter) + "\n";

		for (WordInfix* infix : this->getChildren()) {
			prnt += infix->print();
		}

	}catch (const std::exception& e) {
		cout << e.what();
	}

	return prnt;
}