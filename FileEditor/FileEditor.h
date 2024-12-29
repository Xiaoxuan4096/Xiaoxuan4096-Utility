// FileEditor - File operation.
// Version: 0.0.0.3
// Written by Xiaoxuan4096.

#pragma once

#include <string>
#include <vector>

#include "../BasicSupport/ObjectUniqueIdentityString/ObjectUniqueIdentityString.h"

namespace Xiaoxuan4096 {
	namespace File {
		enum class FileEditorCategory {File, Folder};

		class FileEditor {
		private:
			std::wstring fileDirectory = L"", fileName = L"", cacheDirectory = L""; // Empty cache directory path means that cache files will not be used.
			FileEditorCategory category = FileEditorCategory::File;
			std::vector<std::wstring> fileContent; // A storage for reading file. Note that some cache files will be created when reading if you choose to use cache files.
		public:	
			Basic::Identity::ObjectUniqueIdnetityString ouid;
		public:
			FileEditor();
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