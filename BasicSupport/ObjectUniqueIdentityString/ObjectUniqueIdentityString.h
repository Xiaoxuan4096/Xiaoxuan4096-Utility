// ObjectUniqueIdentityString - Tool for identifying objects.
// Version: 0.0.0.3
// Written by Xiaoxuan4096.

// Note that a UniqueIdentityString can only be generated once and will not change.

#pragma once

#include <string>

namespace Xiaoxuan4096 {
	namespace Basic {
		namespace Identity {
			class ObjectUniqueIdnetityString {
			private:
				std::wstring ouids = L"";
			public:
				ObjectUniqueIdnetityString();
				ObjectUniqueIdnetityString(size_t length, std::wstring chars);
				inline std::wstring getObjectUniqueIdentityString();
			};
		}
	}
}