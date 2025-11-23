// Copyright Tiberiu 2025

#pragma once

#include <vector>
#include <stdexcept>

namespace tiage {

template<typename T>
class Matrix {
public:

	Matrix(size_t nRows, size_t nCols) {
		if (!nRows || !nCols) {
			throw std::runtime_error("invalid matrix dimensions");
		}

		rows_ = nRows;
		cols_ = nCols;

		data_.resize(rows_);
		for (auto& row : data_) {
			row.resize(cols_);
		}
	}

	Matrix() {
<<<<<<< HEAD
		rows_ = 0;
		cols_ = 0;
=======
		

		rows_ = 0;
		cols_ = 0;

		
>>>>>>> 52bba59006d4bfb396856dd09f18bb45e4a35ef1
	}

	const T& get(size_t x, size_t y) const {
		checkBounds(x, y);
		return data_[y][x];  // outer = row = y, inner = col = x
	}

	T& get(size_t x, size_t y) {
		checkBounds(x, y);
		return data_[y][x];
	}

	void set(const T& val) {
		for (int i = 0; i < rows_; i++) {
			for (int j = 0; j < cols_; j++) {
				data_[i][j] = val;
			}
		}
	}

	void set(size_t x, size_t y, const T& val) {
		checkBounds(x, y);
		data_[y][x] = val;
	}

	void set(size_t x, size_t y, T&& val) {
		checkBounds(x, y);
		data_[y][x] = std::move(val);
	}

	void set(const T& val) {
		for (int i = 0; i < rows_; i++) {
			for (int j = 0; j < cols_; j++) {
				data_[i][j] = val;
			}
		}
	}

	size_t nRows() const {
		return rows_;
	}

	size_t nCols() const {
		return cols_;
	}

private:

	void checkBounds(size_t x, size_t y) const {
		if (x >= cols_ || y >= rows_) {
			throw std::out_of_range("Matrix index out of range");
		}
	}

	std::vector<std::vector<T>> data_;

	size_t rows_;

	size_t cols_;
};

} // tiage
