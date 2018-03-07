#pragma once
#include <string>
using namespace std;

class FuzzySearchResult{
private:
	int distance;
	string word;

public:
	FuzzySearchResult(int distance, string word);

	bool operator>(FuzzySearchResult result);

	bool operator<(FuzzySearchResult result);

	string getWord();

	int getDistance();
};

