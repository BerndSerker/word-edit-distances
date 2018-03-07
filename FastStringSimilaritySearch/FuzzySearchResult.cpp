#include "stdafx.h"
#include "FuzzySearchResult.h"


FuzzySearchResult::FuzzySearchResult(int distance, string word){
	this->distance = distance;
	this->word = word;
}

bool FuzzySearchResult::operator>(FuzzySearchResult result) {
	return this->getDistance() < result.getDistance();
}

bool FuzzySearchResult::operator<(FuzzySearchResult result) {
	return this->getDistance() > result.getDistance();
}

string FuzzySearchResult::getWord() {
	return this->word;
}

int FuzzySearchResult::getDistance() {
	return this->distance;
}

