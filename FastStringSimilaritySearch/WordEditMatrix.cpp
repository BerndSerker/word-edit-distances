#include "stdafx.h"
#include "WordEditMatrix.h"
#include <string> 
#include <iostream>
using namespace std;

void WordEditMatrix::initialize(size_t maxLength, size_t maxHeight) {
	this->matrix = vector<vector<size_t>>();

	for (size_t i = 0; i < maxHeight+1; i++) {
		vector<size_t> row = vector<size_t>();

		for (size_t j = 0; j < maxLength+1; j++) {
			row.push_back(0);
		}

		this->matrix.push_back(row);
	}

	this->maxHeight = matrix.size();
	this->maxWidth = matrix[0].size();
}

void WordEditMatrix::update(size_t newMaxLength, size_t newMaxHeight) {

	//add rows
	for (size_t i = this->matrix.size(); i < newMaxHeight; i++) {

		vector<size_t> row = vector<size_t>();
		this->matrix.push_back(row);
	}

	//add columns
	for (int y = 0; y < this->matrix.size(); y++) {
		vector<size_t> row = this->matrix[y];

		for (size_t j = row.size(); j < newMaxLength; j++) {
			row.push_back(0);
		}

		this->matrix[y] = row;

	}

	this->maxHeight = matrix.size();
	this->maxWidth = matrix[0].size();
}

size_t WordEditMatrix::getCostAt(size_t x, size_t y){
	return matrix.at(y).at(x);
}

void WordEditMatrix::setCostAt(size_t x, size_t y, size_t cost) {
	matrix[y][x] = cost;
}

size_t WordEditMatrix::getTotalCost() {
	size_t max_y = this->maxHeight-2;
	size_t max_x = this->maxWidth-2;

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