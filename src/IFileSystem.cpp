// Copyright Tiberiu 2025

#pragma once

#include "tiage/IFileSystem.h"

namespace tiage {

// --------------------------------------------------------------------------------------------------

std::vector<std::string>
IFileSystem::getFolderChildren(const std::string& filePath, const std::string& fileExtension) {
	return doGetFolderChildren(filePath,fileExtension);
}

// --------------------------------------------------------------------------------------------------

std::string
IFileSystem::pickFolder() {
	return doPickFolder();
}

// --------------------------------------------------------------------------------------------------

std::string
IFileSystem::pickFile(const std::string& fileExtension) {
	return doPickFile(fileExtension);
}

// -------------------------------------------------------------------------------------------------

} // tiage

