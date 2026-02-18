// Copyright Tiberiu 2025

#pragma once

#include <vector>
#include <stdexcept>
#include <tiage/Vec2.h>

namespace tiage {

template<typename T>
class Matrix {
public:

    static_assert(
        std::is_default_constructible_v<T>,
        "Matrix<T> requires T to be default-constructible"
        );

    Matrix(const Vec2<size_t>& size = {1,1}) {
        if (!size.x() || !size.y()) {
            throw std::runtime_error("invalid matrix dimensions");
        }

        data_.resize(size.y());
        for (auto& row : data_) {
            row.resize(size.x());
        }
    }

    const T& get(Vec2<size_t> pos) const {
        checkBounds(pos);
        return data_[pos.y()][pos.x()];
    }

    T& get(Vec2<size_t> pos) {
        checkBounds(pos);
        return data_[pos.y()][pos.x()];
    }

    void set(const T& val) {
        for (size_t i = 0; i < nRows(); i++) {
            for (size_t j = 0; j < nCols(); j++) {
                data_[i][j] = val;
            }
        }
    }

    void set(Vec2<size_t> pos, const T& val) {
        checkBounds(pos);
        data_[pos.y()][pos.x()] = val;
    }

    void set(Vec2<size_t> pos, T&& val) {
        checkBounds(pos);
        data_[pos.y()][pos.x()] = std::move(val);
    }

    size_t nRows() const {
        return data_.size();
    }

    size_t nCols() const {
        return data_[0].size();
    }

private:

    void checkBounds(Vec2<size_t> pos) const {
        if (pos.x() >= nCols() || pos.y() >= nRows() ) {
            throw std::out_of_range("Matrix index out of range");
        }
    }

    std::vector<std::vector<T>> data_;
};

} // tiage
