// Exception.h - Basic exception support.
// Version: 0.0.0.2
// Written by Xiaoxuan4096. All rights reserved.

#pragma once

#include <string>

#include <Windows.h>

namespace Xiaoxuan4096 {
	namespace Basic {
		namespace Exception {
			class Exception {
			private:
				std::wstring detail = L"Warning: An error occurred.";
				SYSTEMTIME time;
			public:
				Exception(std::wstring exceptionDetail); // Time data will be added automatically.

				std::wstring getExceptionDetail();
				SYSTEMTIME getExceptionTime();
			};

			std::wstring what(Exception exception);
		}
	}
}