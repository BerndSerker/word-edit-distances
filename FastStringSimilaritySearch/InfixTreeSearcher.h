#pragma once
#include "WordInfix.h"
#include "FuzzySearchResult.h"
#include <vector>
#include <string>

class InfixTreeSearcher
{
public:

	vector<string> search(WordInfix* root, size_t maxResults);

	vector<FuzzySearchResult> subsearch(WordInfix* root);

	vector<string> rankAndCompact(vector<FuzzySearchResult> fuzzyResults, size_t maxResults);

	vector<WordInfix*> collectLeafes(WordInfix* root);
};

