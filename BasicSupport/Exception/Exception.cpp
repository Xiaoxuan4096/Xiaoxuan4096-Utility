// Exception.cpp - Basic exception support.
// Version: 0.0.0.2
// Written by Xiaoxuan4096. All rights reserved.

#include "Exception.h"

#include "../StringUtilities/StringUtilities.h"

Xiaoxuan4096::Basic::Exception::Exception::Exception(std::wstring exceptionDetail) {
	detail = exceptionDetail;
	GetLocalTime(&time);
	return;
}

std::wstring Xiaoxuan4096::Basic::Exception::Exception::getExceptionDetail() {
	return detail;
}
SYSTEMTIME Xiaoxuan4096::Basic::Exception::Exception::getExceptionTime() {
	return time;
}

std::wstring Xiaoxuan4096::Basic::Exception::what(Exception exception) {
	SYSTEMTIME time = exception.getExceptionTime();
	std::wstring what = L"[ " + Utilities::String::convertToWstring(time.wYear) + L" / " + Utilities::String::convertToWstring(time.wMonth) + L" / " + Utilities::String::convertToWstring(time.wDay) + L" | " + Utilities::String::convertToWstring(time.wHour) + L" : " + Utilities::String::convertToWstring(time.wMinute) + L" : " + Utilities::String::convertToWstring(time.wSecond) + L" . " + Utilities::String::convertToWstring(time.wMilliseconds) + L" ] " + exception.getExceptionDetail();
	return what;
}