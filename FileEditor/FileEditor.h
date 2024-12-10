// FileEditor - File operation.
// Version: 0.0.0.2
// Written by Xiaoxuan4096.

#pragma once

#include <string>
#include <vector>

namespace Xiaoxuan4096 {
	namespace File {
		enum class FileEditorCategory {File, folder};
		const wchar_t uniqueIdentityStringChars[17] = L"0123456789abcdef";
		const size_t uniqueIdentityStringLength = 16;

		class FileEditor {
		private:
			std::wstring fileDirectory = L"", fileName = L"", cacheDirectory = L""; // Empty cache directory path means that cache file will not be used.
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