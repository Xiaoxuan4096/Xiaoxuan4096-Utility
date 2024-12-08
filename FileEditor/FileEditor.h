// FileEditor - File operation.
// Version: 0.0.0.0
// Written by Xiaoxuan4096.

#pragma once

#include <string>
#include <vector>

namespace Xiaoxuan4096 {
	namespace File {
		enum class FileEditorCategory {File, folder};

		class FileEditor {
		private:
			std::wstring fileDirectory = L"", fileName = L"", cacheDirectory = L""; // Empty cache file path means that cache file will not be used.
			FileEditorCategory category = FileEditorCategory::File;
			std::vector<std::wstring> fileContent; // A storage for reading file. Note that some cache files will be created when reading if you choose to use cache files.
		public:
			FileEditor(std::wstring fileDirectory, std::wstring fileName, std::wstring cacheDirectory = L"", FileEditorCategory category = FileEditorCategory::File);
			void linkWithFile(std::wstring fileDirectory, std::wstring fileName);
			void unlinkWithFile();
			std::wstring getLinkedFileName();
			void linkWithCacheDirectory(std::wstring cacheDirectory = L"");
			void unlinkWithCacheDirectory();
			std::wstring getLinkedCacheDirectoryName();

			void createFile();

			void append(std::wstring content);
			void rewrite(std::wstring content);
		};
	}
}