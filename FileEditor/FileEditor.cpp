// FileEditor.cpp - File operation.
// Version: 0.0.0.0
// Written by Xiaoxuan4096.

#include "FileEditor.h"
#include "../BasicSupport/FileBase/FileBase.h"

Xiaoxuan4096::File::FileEditor::FileEditor(std::wstring fileDirectory, std::wstring fileName, std::wstring cacheDirectory, FileEditorCategory category) {
	this->fileDirectory = fileDirectory;
	this->fileName = fileName;
	this->cacheDirectory = cacheDirectory;
	this->category = category;
	content.clear();
	return;
}
void Xiaoxuan4096::File::FileEditor::linkWithFile(std::wstring fileDirectory, std::wstring fileName) {
	this->fileDirectory = fileDirectory;
	this->fileName = fileName;
	content.clear();
	return;
}
void Xiaoxuan4096::File::FileEditor::unlinkWithFile() { // Lack of code for deleting cache files. Need improvement.
	fileDirectory = L"";
	fileName = L"";
	content.clear();
	return;
}
std::wstring Xiaoxuan4096::File::FileEditor::getLinkedFileName() {
	return fileName;
}
void Xiaoxuan4096::File::FileEditor::linkWithCacheDirectory(std::wstring cacheDirectory) { // Lack of code for deleting old cache files. Need improvement.
	this->cacheDirectory = cacheDirectory;
	return;
}
void Xiaoxuan4096::File::FileEditor::unlinkWithCacheDirectory() { // Lack of code for deleting cache files. Need improvement.
	cacheDirectory = L"";
	return;
}
std::wstring Xiaoxuan4096::File::FileEditor::getLinkedCacheDirectoryName() {
	return cacheDirectory;
}
