// Copyright Tiberiu 2025

#include "tiage/HitMatrix.h"
#include "fstream"
#include "string"
#include <tiage/Matrix.h>


namespace tiage {

// -------------------------------------------------------------------------------------------------

HitMatrix::HitMatrix(const Vec2<size_t>& size)
	: data_(size)
{}

// -------------------------------------------------------------------------------------------------

Vec2<size_t>
HitMatrix::size() const {
	return { data_.nCols(),data_.nRows() };
}

// -------------------------------------------------------------------------------------------------

void 
HitMatrix::resize(const Vec2<size_t>& newSize) {
	data_ = Matrix<bool>(newSize);
}

// -------------------------------------------------------------------------------------------------

void 
HitMatrix::parseFromFile(const std::string& path) {
	std::ifstream file(path);
	if (!file) {
		throw std::runtime_error("Failed to open hitbox file");
	}
	std::vector<std::string> lines;
	std::string line;
	size_t lineCount = 0;
	size_t rowCount = 0;
	while (std::getline(file, line)) {
		lineCount++;
		lines.push_back(line);
		if (lineCount == 1) {
			rowCount = line.size();
		}
		if (line.size() != rowCount) {
			throw std::runtime_error("Hitbox must be a rectangular matrix, all row lengths must be equal");
		}
	}
	tiage::Matrix<bool> result({ rowCount, lineCount });
	for (size_t i = 0; i < lines.size(); i++) {
		for (size_t j = 0; j < lines[0].size(); j++) {
			const char& chr = lines[i][j];
			if (chr == '0') {
				result.set({ i,j }, 0);
			} else if (chr == '1') {
				result.set({ i,j }, 1);
			} else {
				throw std::runtime_error("Hitbox file can only contain 0 and 1");
			}
		}
	}
	data_ = std::move(result);
}

// -------------------------------------------------------------------------------------------------

bool
HitMatrix::get(const Vec2<size_t>& pos) const {
	return data_.get(pos);
}

// -------------------------------------------------------------------------------------------------

void 
HitMatrix::set(const Vec2<size_t>& pos, bool state) {
	data_.set(pos, state);
}

// -------------------------------------------------------------------------------------------------

} // tiage

