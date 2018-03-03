#include "stdafx.h"
#include "WordEditDistance.h"


WordEditDistance::WordEditDistance()
{
}


WordEditDistance::~WordEditDistance()
{
}

virtual int WordEditDistance::getDistance(string a, string b) = 0;

virtual int WordEditDistance::getStepwiseDistance(int current, string sub_a, string sub_b) = 0;
