// FastStringSimilaritySearch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WordSplitter.h"
#include "HammingDistance.h"
#include "InfixTreeSearcher.h"
#include <iostream>
#include <string>
using namespace std;

int main(){

	string a = "le";
	string b = "el";

	WordSplitter splitter = WordSplitter();
	WordInfix infixRoot = splitter.split(b, 3);

	cout << infixRoot.print();

	cout << "Splitting finished!";

	//delete infixRoot;

	cout << "Calculating Hamming Distance";
	HammingDistance hdist = HammingDistance();
	WordEditDistance* dist = (WordEditDistance*) &hdist;

	
	cout << "\n Distance between " + a + " and " + b + " = " << dist->getDistance(a, b) << "\n";

	cout << "Calculating Levenshtein Distance";
	LevenshteinDistance ldist = LevenshteinDistance();
	WordEditDistance* dist2 = (WordEditDistance*)&ldist;

	cout << "\n Distance between " + a + " and " + b + " = " << dist2->getDistance(a, b);

	a = "ab";
	b = "ba";

	cout << "\nCalculating Levenshtein Distance (Stepwise)";
	LevenshteinDistance levdist = LevenshteinDistance();
	WordEditMatrix* matrix = levdist.initializeStepwise();

	for (int i = 0; i < a.size(); i++) {
		string sub_a = a.substr(i, i + 1);
		string sub_b = " ";

		if (i < b.size()) {
			sub_b = b.substr(i, i + 1);
		}

		levdist.stepwiseDistance(matrix, sub_a, sub_b);
	}

	cout << "\n Distance between " + a + " and " + b + " = " << matrix->getTotalCost();

	InfixTreeSearcher searcher = InfixTreeSearcher();
	searcher.search(&infixRoot,10);

	string input;
	std::getline(std::cin, input);

    return 0;
}

