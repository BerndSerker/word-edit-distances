#pragma once
#include <vector>
using namespace std;

class WordEditMatrix{

public:
	vector<vector<size_t>> matrix;

	size_t maxHeight;

	size_t maxWidth;

	bool initialized = false;

	void initialize(size_t maxLength, size_t maxHeight);

	void update(size_t newMaxLength, size_t newMaxHeight);

	size_t getCostAt(size_t x, size_t y);

	void setCostAt(size_t x, size_t y, size_t cost);

	size_t getTotalCost();

	string print();
};

