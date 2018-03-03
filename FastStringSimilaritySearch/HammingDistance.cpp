#include "stdafx.h"
#include "HammingDistance.h"
#include <cmath>


size_t HammingDistance::getDistance(string a, string b) {
	size_t distance = 0;

	for (int i = 0; i < a.size(); i++) {
		char ac = a.at(i);

		if (i < b.size()) {
			char bc = b.at(i);
			distance = this->getStepwiseDistance(distance, string(1, ac), string(1, bc));
		}else {
			break;
		}
	}

	int lenDist = a.size() - b.size();

	distance += abs(lenDist);

	return distance;
}

size_t HammingDistance::getStepwiseDistance(size_t current, string sub_a, string sub_b) {
	if (sub_a.compare(sub_b) != 0) {
		return current+1;
	}

	return current;
}