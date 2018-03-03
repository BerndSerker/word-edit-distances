#include "stdafx.h";
#include "WordEditDistance.h";
#include <string>;

class LevenshteinDistance: virtual public WordEditDistance{

	virtual size_t getDistance(string a, string b);

	virtual size_t getStepwiseDistance(size_t current, string sub_a, string sub_b);
};

