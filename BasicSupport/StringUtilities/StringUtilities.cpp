// StringUtilities.cpp - Useful functions of string.
// Version: 0.0.0.0
// Written by Xiaoxuan4096. All rights reserved.

#include "StringUtilities.h"

template <typename T> std::wstring Xiaoxuan4096::Utilities::String::convertToWstring(T content) {
	std::wstringstream ss;
	std::wstring str;

	ss << content;
	ss >> str;

	return str;
}