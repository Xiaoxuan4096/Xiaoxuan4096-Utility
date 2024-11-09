// Exception.h - Basic exception support.
// Version: 0.0.0.0
// Written by Xiaoxuan4096. All rights reserved.

#pragma once

#include <string>

#include <Windows.h>

namespace Xiaoxuan4096 {
	namespace Exception {
		class Exception {
		private:
			std::wstring detail = L"Warning: An error occurred.";
			SYSTEMTIME time;
		public:
			Exception();
			std::wstring getDetail();
		};
	}
}