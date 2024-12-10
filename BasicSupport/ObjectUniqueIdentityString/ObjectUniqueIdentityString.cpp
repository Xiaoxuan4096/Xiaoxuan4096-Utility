// ObjectUniqueIdentityString.cpp - Tool for identifying objects.
// Version: 0.0.0.1
// Written by Xiaoxuan4096.

#include "ObjectUniqueIdentityString.h"

#include <random>

Xiaoxuan4096::Basic::Identity::ObjectUniqueIdnetityString::ObjectUniqueIdnetityString() {
	ObjectUniqueIdnetityString(Xiaoxuan4096::Basic::Identity::DefaultOUIDSLength, Xiaoxuan4096::Basic::Identity::DefaultOUIDSCharacters);
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

std::wstring Xiaoxuan4096::Basic::Identity::ObjectUniqueIdnetityString::getObjectUniqueIdentityString() {
	return ouids;
}