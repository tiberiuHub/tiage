// Copyright Tiberiu 2025

#pragma once

#include <tiage/IFileSystem.h>
#include <Windows.h>

namespace tiage {

class WinFileSystem : public IFileSystem {
public:

	WinFileSystem() = default;

private:

	std::vector<std::string> doGetFolderChildren(const std::string& filePath, const std::string& fileExtension) override;

	std::string doPickFolder() override;

	std::string doPickFile(const std::string& fileExtension) override;

};

} // tiage
