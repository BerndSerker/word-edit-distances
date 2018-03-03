#include "stdafx.h"
#include "WordEditMatrix.h"
#include <string> 

void WordEditMatrix::initialize(size_t maxLength, size_t maxHeight) {
	this->matrix = vector<vector<size_t>>();

	for (size_t i = 0; i < maxHeight+1; i++) {
		vector<size_t> row = vector<size_t>();

		for (size_t j = 0; j < maxLength+1; j++) {
			row.push_back(0);
		}

		this->matrix.push_back(row);
	}
}

void WordEditMatrix::update(size_t newMaxLength, size_t newMaxHeight) {
	for (size_t i = this->matrix.size(); i < newMaxHeight; i++) {
		vector<size_t> row = vector<size_t>();

		for (size_t j = this->matrix[0].size(); j < newMaxLength; j++) {
			row.push_back(0);
		}

		this->matrix.push_back(row);
	}
}

size_t WordEditMatrix::getCostAt(size_t x, size_t y){
	return matrix.at(y).at(x);
}

void WordEditMatrix::setCostAt(size_t x, size_t y, size_t cost) {
	matrix[y][x] = cost;
}

size_t WordEditMatrix::getTotalCost() {
	// minus two TODO
	size_t max_y = matrix.size()-2;
	size_t max_x = matrix[0].size()-2;

	return this->getCostAt(max_x, max_y);
}

string WordEditMatrix::print() {
	string print = "\n ";

	for (int i = 0; i < this->matrix.size(); i++) {
		for (int j = 0; j < this->matrix[0].size(); j++) {
			print += " " + to_string(this->matrix[i][j]);
		}

		print += "\n";
	}

	return print;
}