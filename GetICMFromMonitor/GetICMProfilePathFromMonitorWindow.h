#pragma once

#include "framework.h"

namespace ICMUtil
{
    std::wstring GetICMProfilePathFromWindowMonitor(HWND hWnd, DWORD monitorFlags = MONITOR_DEFAULTTONEAREST);
}
