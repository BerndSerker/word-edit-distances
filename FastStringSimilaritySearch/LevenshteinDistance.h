#include "stdafx.h";
#include "WordEditDistance.h";
#include "WordEditMatrix.h";
#include <string>;
using namespace std;

class LevenshteinDistance: virtual public WordEditDistance{

	virtual size_t getDistance(string a, string b);

	virtual size_t getStepwiseDistance(size_t current, string sub_a, string sub_b);

public:
	WordEditMatrix* stepwiseDistance(WordEditMatrix* matrix, string sub_a, string sub_b);

	WordEditMatrix* initializeStepwise();
};

