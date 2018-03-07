#pragma once
#include "WordInfix.h"
#include "FuzzySearchResult.h"
#include "WordEditDistance.h"
#include "LevenshteinDistance.h"
#include <vector>
#include <string>
using namespace std;

class InfixTreeSearcher{
private:
	LevenshteinDistance editDistance;

public:

	vector<string> search(WordInfix* root, size_t maxResults);

	vector<FuzzySearchResult> subsearch(WordInfix* root);

	vector<string> rankAndCompact(vector<FuzzySearchResult> fuzzyResults, size_t maxResults);

	vector<WordInfix*> collectLeafes(WordInfix* root);
};

