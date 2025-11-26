// Copyright Tiberiu 2025

#pragma once

#include <string>
#include <vector>

namespace tiage {

class IFileSystem {
public:

    virtual ~IFileSystem() = default;

    std::vector<std::string> getFolderChildren(const std::string& filePath,const std::string& fileExtension);

    std::string pickFolder();

    std::string pickFile(const std::string& fileExtension);

protected:

    virtual std::vector<std::string> doGetFolderChildren(const std::string& filePath, const std::string& fileExtension) = 0;

    virtual std::string doPickFolder() = 0;

    virtual std::string doPickFile(const std::string& fileExtension) = 0;

};

} // tiage
