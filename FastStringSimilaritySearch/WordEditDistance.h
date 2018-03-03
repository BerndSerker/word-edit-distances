#pragma once
#include <string>
#include <iostream>
using namespace std;

class WordEditDistance
{
public:

	virtual size_t getDistance(string a, string b) = 0;

	virtual size_t getStepwiseDistance(size_t current, string sub_a, string sub_b) = 0;
};

