// FileEditor.cpp - File operation.
// Version: 0.0.0.3
// Written by Xiaoxuan4096.

#include <exception>

#include "FileEditor.h"
#include "../BasicSupport/FileBase/FileBase.h"

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
		Xiaoxuan4096::Basic::File::removeDirectoryAndAllContents(cacheDirectory);

	return;
}
std::wstring Xiaoxuan4096::File::FileEditor::getLinkedFileName() {
	return fileName;
}
void Xiaoxuan4096::File::FileEditor::linkWithCacheDirectory(std::wstring cacheDirectory) {
	if (cacheDirectory != L"")
		Xiaoxuan4096::Basic::File::copyDirectoryAndAllContents(this->cacheDirectory, cacheDirectory);
	else
		Xiaoxuan4096::Basic::File::removeDirectoryAndAllContents(this->cacheDirectory);
	this->cacheDirectory = cacheDirectory;

	return;
}
void Xiaoxuan4096::File::FileEditor::unlinkWithCacheDirectory() {
	if (cacheDirectory != L"")
		Xiaoxuan4096::Basic::File::removeDirectoryAndAllContents(cacheDirectory);
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
	if (Xiaoxuan4096::Basic::File::exist(fileDirectory + fileName)) {
		throw std::exception("Error when creating file: the file has already existed.");
		return;
	}

	Xiaoxuan4096::Basic::File::createFile(fileDirectory + fileName);

	return;
}
void Xiaoxuan4096::File::FileEditor::renameFile(std::wstring newFileName) {
	if (option == FileOption::Skip && Xiaoxuan4096::Basic::File::exist(fileDirectory + newFileName)) {
		throw std::exception("Error when renaming file: file with same name exists.");
		return;
	}

	std::wstring oldFileName = fileName;
	fileName = newFileName;
	createFile();
	
	Xiaoxuan4096::Basic::File::copySingleFile(fileDirectory + oldFileName, fileDirectory + fileName);
	Xiaoxuan4096::Basic::File::deleteFile(fileDirectory + oldFileName);

	return;
}
void Xiaoxuan4096::File::FileEditor::deleteFile() {
	if (!Xiaoxuan4096::Basic::File::exist(fileDirectory + fileName)) {
		throw std::exception("Error when deleting file: no such file.");
		return;
	}

	Xiaoxuan4096::Basic::File::deleteFile(fileDirectory + fileName);

	return;
}

void Xiaoxuan4096::File::FileEditor::createDirectory() {
	if (Xiaoxuan4096::Basic::File::exist(fileDirectory)) {
		throw std::exception("Error when creating directory: the directory has already existed.");
		return;
	}

	Xiaoxuan4096::Basic::File::createEmptyDirectory(fileDirectory);

	return;
}
void Xiaoxuan4096::File::FileEditor::renameDirectory(std::wstring newFileDirectory) {
	if (option == FileOption::Skip && Xiaoxuan4096::Basic::File::exist(newFileDirectory)) {
		throw std::exception("Error when renaming directory: directory with same name exists.");
		return;
	}

	std::wstring oldDirectoryName = fileDirectory;
	fileDirectory = newFileDirectory;
	createDirectory();

	Xiaoxuan4096::Basic::File::copyDirectoryAndAllContents(oldDirectoryName, fileDirectory);
	Xiaoxuan4096::Basic::File::removeDirectoryAndAllContents(oldDirectoryName);

	return;
}
void Xiaoxuan4096::File::FileEditor::deleteDirectory() {
	if (!Xiaoxuan4096::Basic::File::exist(fileDirectory)) {
		throw std::exception("Error when deleting directory: no such directory.");
		return;
	}

	Xiaoxuan4096::Basic::File::removeDirectoryAndAllContents(fileDirectory);

	return;
}

void Xiaoxuan4096::File::FileEditor::append(std::wstring content) {
	Xiaoxuan4096::Basic::File::appendFile(fileDirectory + fileName, content);

	return;
}
void Xiaoxuan4096::File::FileEditor::rewrite(std::wstring content) {
	Xiaoxuan4096::Basic::File::rewriteFile(fileDirectory + fileName, content);

	return;
}

std::wstring Xiaoxuan4096::File::FileEditor::read() {
	return std::wstring();
}
