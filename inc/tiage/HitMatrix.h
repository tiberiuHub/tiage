// Copyright Tiberiu 2025

#pragma once

#include <tiage/Vec2.h>
#include <string>
#include <tiage/Matrix.h>

namespace tiage {

class HitMatrix {
public:

	HitMatrix(const Vec2<size_t>& size = {1,1});

	Vec2<size_t> size() const;

	void resize(const Vec2<size_t>& newSize);

	void parseFromFile(const std::string& path);//move function

	bool get(const Vec2<size_t>& pos) const;

	void set(const Vec2<size_t>& pos, bool state);

private:

	Matrix<bool>data_;

};

} // tiage
