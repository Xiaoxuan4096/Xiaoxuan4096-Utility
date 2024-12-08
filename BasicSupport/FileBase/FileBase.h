// FileBase - Basic file operation support.
// Version: 0.0.0.4
// Written by Xiaoxuan4096. All rights reserved.

#pragma once

#include <string>
#include <vector>

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

			std::wstring readFile(std::wstring path); // USING IT to deal with LARGE files is NOT RECOMMENDED!!!
			std::vector<std::wstring> readFileByLines(std::wstring path); // DO NOT USE IT to deal with VERY LARGE files!!!
		}
	}
}