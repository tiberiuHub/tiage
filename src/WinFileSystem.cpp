// Copyright Tiberiu 2025

#pragma once

#include <shlobj.h>
#include "tiage/WinFileSystem.h"
#include <filesystem>

namespace tiage {

// --------------------------------------------------------------------------------------------------

std::vector<std::string>
WinFileSystem::doGetFolderChildren(const std::string& folderPath, const std::string& fileExtension) {
	std::vector<std::string> children;
	for (const auto& entry : std::filesystem::directory_iterator(folderPath)) {
		if (entry.is_regular_file() && entry.path().extension() == fileExtension) {
			children.push_back(entry.path().filename().string());
		}
	}
	return children;
}

// --------------------------------------------------------------------------------------------------

std::string
WinFileSystem::doPickFolder() {
	SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2);
	std::string folderPath;
	HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
	if (FAILED(hr)) return "";

	IFileDialog* pFileDialog = nullptr;
	hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL, IID_PPV_ARGS(&pFileDialog));
	if (SUCCEEDED(hr)) {
		DWORD options;
		if (SUCCEEDED(pFileDialog->GetOptions(&options))) {
			pFileDialog->SetOptions(options | FOS_PICKFOLDERS | FOS_PATHMUSTEXIST);
		}

		if (SUCCEEDED(pFileDialog->Show(NULL))) {
			IShellItem* pItem = nullptr;
			if (SUCCEEDED(pFileDialog->GetResult(&pItem))) {
				PWSTR pszFolderPath = nullptr;
				if (SUCCEEDED(pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFolderPath))) {
					std::wstring ws(pszFolderPath);
					int size_needed = WideCharToMultiByte(CP_UTF8, 0, ws.c_str(), (int)ws.size(), NULL, 0, NULL, NULL);
					folderPath.resize(size_needed);
					WideCharToMultiByte(CP_UTF8, 0, ws.c_str(), (int)ws.size(), &folderPath[0], size_needed, NULL, NULL);

					CoTaskMemFree(pszFolderPath);
				}
				pItem->Release();
			}
		}
		pFileDialog->Release();
	}

	CoUninitialize();
	return folderPath;

}

// --------------------------------------------------------------------------------------------------

std::string
WinFileSystem::doPickFile(const std::string& fileExtension) {
	SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2);
	OPENFILENAMEA ofn;
	char szFile[MAX_PATH] = { 0 };

	std::vector<char> filter = { 'F','i','l','e','(','*','.' };
	filter.insert(filter.end(), fileExtension.begin(), fileExtension.end());
	filter.push_back(')');
	filter.push_back('\0');
	std::string filterPart = "*.";
	filter.insert(filter.end(), filterPart.begin(), filterPart.end());
	filter.insert(filter.end(), fileExtension.begin(), fileExtension.end());
	filter.push_back('\0');
	filter.push_back('\0');//building filter, this can probably be done easier	

	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;
	ofn.lpstrFile = szFile;
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = filter.data();
	ofn.nFilterIndex = 1;
	ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;

	if (GetOpenFileNameA(&ofn)) {
		return std::string(ofn.lpstrFile);
	}
	return "";
}

// --------------------------------------------------------------------------------------------------

} // tiage

