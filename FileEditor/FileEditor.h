// FileEditor - File operation.
// Version: 0.0.0.4
// Written by Xiaoxuan4096.

#pragma once

#include <string>
#include <vector>

#include "../BasicSupport/ObjectUniqueIdentityString/ObjectUniqueIdentityString.h"

namespace Xiaoxuan4096 {
	namespace File {
		enum class FileOption {Overwrite, Skip};

		class FileEditor {
		private:
			std::wstring fileDirectory = L"", fileName = L"", cacheDirectory = L""; // Empty cache directory path means that cache files will not be used.
			FileOption option = FileOption::Skip; // Skip mode will not overwrite file.
			std::vector<std::wstring> fileContent; // A storage for reading file. Note that some cache files will be created when reading if you choose to use cache files.
			Basic::Identity::ObjectUniqueIdnetityString ouids{32, L"0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ+-"};
			size_t maxContentSizeForOneReadAndWrite = 1048576; // Determine whether to use cache files(if enabled). If the content is shorter than it, cache files won't be created. By default, it is 1048576 Bytes(1MiB).
		private:
			void createCacheDirectory();
			void deleteCacheDirectory();
		public:
			FileEditor();
			FileEditor(std::wstring fileDirectory, std::wstring fileName, std::wstring cacheDirectory = L"");
			void setAndLinkWithUniqueCacheDirectory();
			void linkWithFile(std::wstring fileDirectory, std::wstring fileName);
			void unlinkWithFile();
			std::wstring getLinkedFileName();
			void linkWithCacheDirectory(std::wstring cacheDirectory = L"");
			void unlinkWithCacheDirectory();
			std::wstring getLinkedCacheDirectoryName();
			std::wstring getObjectUniqueIdentityString();
			
			// All these functions may throw exceptions.
			void createFile();
			void renameFile(std::wstring newFileName);
			void deleteFile();

			void createDirectory();
			void renameDirectory(std::wstring newFileDirectory);
			void deleteDirectory();

			void append(std::wstring content);
			void rewrite(std::wstring content);
			
			std::wstring read();
		};
	}
}