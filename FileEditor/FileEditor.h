// FileEditor - File operation.
// Version: 0.0.0.0
// Written by Xiaoxuan4096.

#pragma once

#include <string>
#include <vector>

namespace Xiaoxuan4096 {
	namespace File {
		enum class FileEditorCategory {file, folder};

		class FileEditor {
		private:
			std::wstring filePath, cacheDirectoryPath = L""; // Empty cache file path means that cache file will not be used.
			FileEditorCategory category;
			std::vector<std::wstring> content; // A storage for reading file.
		public:
			FileEditor(std::wstring filePath, std::wstring cacheDirectoryPath = L"", FileEditorCategory category);
			void linkWithFile(std::wstring filePath);
			void unlinkWithFile();
			void linkWithCacheDirectory(std::wstring cacheDirectoryPath = L"");
			void unlinkWithCacheDirectory();
		};
	}
}