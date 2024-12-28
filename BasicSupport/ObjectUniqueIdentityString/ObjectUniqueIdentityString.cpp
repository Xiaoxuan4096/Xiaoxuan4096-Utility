// ObjectUniqueIdentityString.cpp - Tool for identifying objects.
// Version: 0.0.0.2
// Written by Xiaoxuan4096.

#include "ObjectUniqueIdentityString.h"

#include <random>

Xiaoxuan4096::Basic::Identity::ObjectUniqueIdnetityString::ObjectUniqueIdnetityString() {
	ObjectUniqueIdnetityString(DefaultOUIDSLength, DefaultOUIDSCharacters);
	return;
}
Xiaoxuan4096::Basic::Identity::ObjectUniqueIdnetityString::ObjectUniqueIdnetityString(size_t length, std::wstring chars) {
	if (ouids != L"")
		return;
	std::random_device rd;
	std::uniform_int_distribution<size_t> uid(0, chars.size() - 1);
	for (size_t i = 0; i < length; i++)
		ouids += chars[uid(rd)];
	return;
}

inline std::wstring Xiaoxuan4096::Basic::Identity::ObjectUniqueIdnetityString::getObjectUniqueIdentityString() {
	return ouids;
}