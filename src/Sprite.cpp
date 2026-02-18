// Copyright Tiberiu 2025

#include "tiage/Sprite.h"
#include "tiage/Matrix.h"
#include "fstream"
#include "sstream"
#include <unordered_map>

namespace tiage {

// -------------------------------------------------------------------------------------------------

Vec2<size_t>
Sprite::getSize() const {
	return {data_.nCols(),data_.nRows()};
}

// -------------------------------------------------------------------------------------------------

void 
Sprite::setSize(Vec2<size_t> newSize) {
	data_ = Matrix<DrawableChar>(newSize);
}

// -------------------------------------------------------------------------------------------------

void 
Sprite::parseFromFile(const std::string& path) {
	std::ifstream file(path);
	if (!file) {
		throw std::runtime_error("Failed to open hitbox file");
	}
	std::vector<std::string> lines;
	std::string line;
	std::unordered_map <char, DrawableChar> palette;
	size_t lineCount = 0;
	size_t rowCount = 0;

	while (std::getline(file, line)) {
		if (line == "//") {
			break;
		}
		std::stringstream stream(line);
		char symbol = 'c';
		std::string chrString = "c";
		std::string fgColor;
		std::string bgColor;

		if (!(stream >> symbol >> chrString >> fgColor >> bgColor)) {
			throw std::runtime_error("Invalid palette line in sprite file");
		}

		char chr;

		if (chrString.size() == 1) {
			chr = chrString[0];
		} else if (chrString == "space") {
			chr = ' ';
		} else {
			throw std::runtime_error("character can be space string that turns into space char or a single character");
		}

		DrawableChar definedChar(chr,colFromString(fgColor),colFromString(bgColor));
		palette[symbol] = definedChar ;
	}
	while (std::getline(file, line)) {
		lineCount++;
		lines.push_back(line);
		if (lineCount == 1) {
			rowCount = line.size();
		}
		if (line.size() != rowCount) {
			throw std::runtime_error("Sprite drawing must be a rectangular matrix, all row lengths must be equal");
		}
	}
	if (lines.empty()) {
		throw std::runtime_error("Sprite file contains no canvas");
	}
	tiage::Matrix<DrawableChar> result({ rowCount, lineCount });
	for (size_t i = 0; i < lines.size(); i++) {
		for (size_t j = 0; j < lines[0].size(); j++) {
			const char& chr = lines[i][j];
			auto it = palette.find(chr);
			if (it != palette.end()) {
				result.set({ j,i }, it->second);
			} else if (chr == ' ') {
				result.set({ j,i }, DrawableChar::kDefault);
			} else {
				throw std::runtime_error("Symbol not found in palette");
			}
		}
	}
	data_ = std::move(result);
}

// -------------------------------------------------------------------------------------------------

DrawableChar 
Sprite::getChar(Vec2<size_t> pos) const {
	return data_.get(pos);
}

// -------------------------------------------------------------------------------------------------

void 
Sprite::setChar(Vec2<size_t> pos, const DrawableChar& c) {
	data_.set(pos, c);
}

// -------------------------------------------------------------------------------------------------

} // tiage

