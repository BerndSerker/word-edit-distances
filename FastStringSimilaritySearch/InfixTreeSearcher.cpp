#include "stdafx.h"
#include "InfixTreeSearcher.h"
#include "FuzzySearchResult.h"
#include <iostream>

vector<string> InfixTreeSearcher::search(WordInfix* root, size_t maxResults) {
	vector<string> results;

	//collect all leaves for exact search
	vector<WordInfix*> leafes = this->collectLeafes(root);

	//do excat search and extend fuzzy
	vector<FuzzySearchResult> fuzzyResults = vector<FuzzySearchResult>();
	for (WordInfix* leaf : leafes) {
		vector<FuzzySearchResult> subResults = this->subsearch(leaf);
		fuzzyResults.insert(fuzzyResults.end(), subResults.begin(), subResults.end());
	}

	//take all results and rank them (by default on the distance)
	results = this->rankAndCompact(fuzzyResults, maxResults);

	return results;
}

vector<string> InfixTreeSearcher::rankAndCompact(vector<FuzzySearchResult> fuzzyResults, size_t maxResults) {
	vector<string> results = vector<string>();



	return results;
}

vector<FuzzySearchResult> InfixTreeSearcher::subsearch(WordInfix* root) {
	vector<FuzzySearchResult> results = vector<FuzzySearchResult>();

	//do subsearch

	return results;
}

vector<WordInfix*> InfixTreeSearcher::collectLeafes(WordInfix* root) {
	vector<WordInfix*> allLeafes = vector<WordInfix*>();

	//iterate over all child nodes
	vector<WordInfix*> children = root->getChildren();
	for (WordInfix* infix : children) {
		
		//all leaf nodes have no children
		if ( infix->isLeaf()) {
			allLeafes.push_back(infix);

		}else {
			vector<WordInfix*> leafes = this->collectLeafes(infix);

			for (WordInfix* leaf : leafes) {
				allLeafes.push_back(leaf);
			}
		}
	}

	return allLeafes;
}