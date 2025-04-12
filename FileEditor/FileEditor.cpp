// FileEditor.cpp - File operation.
// Version: 0.0.0.4
// Written by Xiaoxuan4096.

#include <exception>

#include "FileEditor.h"
#include "../BasicSupport/FileBase/FileBase.h"
#include "../BasicSupport/StringUtilities/StringUtilities.h"

void Xiaoxuan4096::File::FileEditor::createCacheDirectory() {
	Basic::File::createEmptyDirectory(cacheDirectory);
	return;
}
void Xiaoxuan4096::File::FileEditor::deleteCacheDirectory() {
	Basic::File::removeDirectoryAndAllContents(cacheDirectory);
	return;
}

Xiaoxuan4096::File::FileEditor::FileEditor() {
	return;
}
Xiaoxuan4096::File::FileEditor::FileEditor(std::wstring fileDirectory, std::wstring fileName, std::wstring cacheDirectory) {
	this->fileDirectory = fileDirectory;
	this->fileName = fileName;
	this->cacheDirectory = cacheDirectory;
	fileContent.clear();
	return;
}

void Xiaoxuan4096::File::FileEditor::setAndLinkWithUniqueCacheDirectory() {
	cacheDirectory = L"FileEditorCache" + ouids.getObjectUniqueIdentityString();
	return;
}
void Xiaoxuan4096::File::FileEditor::linkWithFile(std::wstring fileDirectory, std::wstring fileName) {
	this->fileDirectory = fileDirectory;
	this->fileName = fileName;
	fileContent.clear();

	return;
}
void Xiaoxuan4096::File::FileEditor::unlinkWithFile() {
	fileDirectory = L"";
	fileName = L"";
	fileContent.clear();

	if (cacheDirectory != L"")
		Basic::File::removeDirectoryAndAllContents(cacheDirectory);

	return;
}
std::wstring Xiaoxuan4096::File::FileEditor::getLinkedFileName() {
	return fileName;
}
void Xiaoxuan4096::File::FileEditor::linkWithCacheDirectory(std::wstring cacheDirectory) {
	if (cacheDirectory != L"")
		Basic::File::copyDirectoryAndAllContents(this->cacheDirectory, cacheDirectory);
	else
		Basic::File::removeDirectoryAndAllContents(this->cacheDirectory);
	this->cacheDirectory = cacheDirectory;

	return;
}
void Xiaoxuan4096::File::FileEditor::unlinkWithCacheDirectory() {
	if (cacheDirectory != L"")
		Basic::File::removeDirectoryAndAllContents(cacheDirectory);
	cacheDirectory = L"";

	return;
}
std::wstring Xiaoxuan4096::File::FileEditor::getLinkedCacheDirectoryName() {
	return cacheDirectory;
}
std::wstring Xiaoxuan4096::File::FileEditor::getObjectUniqueIdentityString() {
	return ouids.getObjectUniqueIdentityString();
}

void Xiaoxuan4096::File::FileEditor::createFile() {
	if (Basic::File::exist(fileDirectory + fileName)) {
		throw std::exception("Error when creating file: the file has already existed.");
		return;
	}

	Basic::File::createFile(fileDirectory + fileName);

	return;
}
void Xiaoxuan4096::File::FileEditor::renameFile(std::wstring newFileName) {
	if (option == FileOption::Skip && Basic::File::exist(fileDirectory + newFileName)) {
		throw std::exception("Error when renaming file: file with same name exists.");
		return;
	}

	std::wstring oldFileName = fileName;
	fileName = newFileName;
	createFile();
	
	Basic::File::copySingleFile(fileDirectory + oldFileName, fileDirectory + fileName);
	Basic::File::deleteFile(fileDirectory + oldFileName);

	return;
}
void Xiaoxuan4096::File::FileEditor::deleteFile() {
	if (!Basic::File::exist(fileDirectory + fileName)) {
		throw std::exception("Error when deleting file: no such file.");
		return;
	}

	Basic::File::deleteFile(fileDirectory + fileName);

	return;
}

void Xiaoxuan4096::File::FileEditor::createDirectory() {
	if (Basic::File::exist(fileDirectory)) {
		throw std::exception("Error when creating directory: the directory has already existed.");
		return;
	}

	Basic::File::createEmptyDirectory(fileDirectory);

	return;
}
void Xiaoxuan4096::File::FileEditor::renameDirectory(std::wstring newFileDirectory) {
	if (option == FileOption::Skip && Basic::File::exist(newFileDirectory)) {
		throw std::exception("Error when renaming directory: directory with same name exists.");
		return;
	}

	std::wstring oldDirectoryName = fileDirectory;
	fileDirectory = newFileDirectory;
	createDirectory();

	Basic::File::copyDirectoryAndAllContents(oldDirectoryName, fileDirectory);
	Basic::File::removeDirectoryAndAllContents(oldDirectoryName);

	return;
}
void Xiaoxuan4096::File::FileEditor::deleteDirectory() {
	if (!Basic::File::exist(fileDirectory)) {
		throw std::exception("Error when deleting directory: no such directory.");
		return;
	}

	Basic::File::removeDirectoryAndAllContents(fileDirectory);

	return;
}

void Xiaoxuan4096::File::FileEditor::append(std::wstring content) {
	if (content.size() > maxContentSizeForOneReadAndWrite && cacheDirectory != L"") {
		createCacheDirectory();
		for (size_t i = 0; i < content.size(); i += maxContentSizeForOneReadAndWrite) {
			std::wstring tmpCacheFile = cacheDirectory + L"AppendCache" + Utilities::String::convertToWstring(i / maxContentSizeForOneReadAndWrite);
			Basic::File::createFile(tmpCacheFile);
			Basic::File::rewriteFile(tmpCacheFile, content.substr(i, maxContentSizeForOneReadAndWrite));
		}
		for (size_t i = 0; i < content.size(); i += maxContentSizeForOneReadAndWrite) {
			std::wstring tmp = Basic::File::readFile(cacheDirectory + L"AppendCache" + Utilities::String::convertToWstring(i / maxContentSizeForOneReadAndWrite));
			Basic::File::appendFile(fileDirectory + fileName, tmp);
		}
		deleteCacheDirectory();
	}
	else
		Basic::File::appendFile(fileDirectory + fileName, content);

	return;
}
void Xiaoxuan4096::File::FileEditor::rewrite(std::wstring content) {
	Basic::File::rewriteFile(fileDirectory + fileName, content);

	return;
}

std::wstring Xiaoxuan4096::File::FileEditor::read() {
	return Basic::File::readFile(fileDirectory + fileName);
}
