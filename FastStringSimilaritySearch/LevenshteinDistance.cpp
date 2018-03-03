
#include "stdafx.h";
#include "LevenshteinDistance.h";
#include "WordEditMatrix.h";
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


size_t LevenshteinDistance::getStepwiseDistance(size_t current, string sub_a, string sub_b) {
	return 0;
}

// using optimized dynamic programming
size_t LevenshteinDistance::getDistance(string a, string b){
	size_t distance = 0;

	// add empty space to strings
	a = " " + a;
	b = " " + b;

	// create and initialize a matrix
	WordEditMatrix matrix = WordEditMatrix();
	matrix.initialize(b.size()+1, a.size()+1);

	// step by step calculation
	int xPos = 1;
	int yPos = 1;

	for (int i = 0; i < a.size(); i++) {
		char ac = a.at(i);
		char bc;

		for (int j = 0; j < b.size(); j++) {
			bc = b.at(j);

			size_t newCost;

			// if the characters are equal, cost is 0
			if (ac == bc) {
				newCost = matrix.getCostAt(xPos-1,yPos-1); 
				matrix.setCostAt(xPos, yPos, newCost);

			}else {
				//calculate costs for operations
				int deletion = matrix.getCostAt(xPos, yPos - 1) + 1;
				int insertion = matrix.getCostAt(xPos - 1, yPos) + 1;
				int substitution = matrix.getCostAt(xPos - 1, yPos - 1) + 1;

				int newCost = min(deletion, min(insertion, substitution));
				matrix.setCostAt(xPos, yPos, newCost);

			}

			xPos += 1;
		}

		// reset x
		xPos = 1;
		yPos += 1;
	}

	// for debug 
	cout << matrix.print();

	// add the word distance 
	distance += matrix.getTotalCost();

	// add the length distance
	// int lenDiff = a.size() - b.size();
	// size_t lenDist = abs(lenDiff);

	return distance;// + lenDist;
}

