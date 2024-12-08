// FileBase - Basic file operation support.
// Version: 0.0.0.5
// Written by Xiaoxuan4096. All rights reserved.

#pragma once

#include <string>

namespace Xiaoxuan4096 {
	namespace Basic {
		namespace File {
			void createFile(std::wstring path);
			void deleteFile(std::wstring path);

			void appendFile(std::wstring path, std::wstring content);
			void rewriteFile(std::wstring path, std::wstring content);

			void createEmptyDirectory(std::wstring path);
			void removeEmptyDirectory(std::wstring path);
			void removeDirectoryAndAllContents(std::wstring path);

			void copySingleFile(std::wstring location, std::wstring destination) noexcept;
			void copyDirectoryAndAllContents(std::wstring location, std::wstring destination) noexcept;

			std::wstring readFile(std::wstring path); // Using it directly to deal with LARGE files is NOT RECOMMENDED!!!
		}
	}
}