#pragma once

#include "framework.h"

namespace ICMUtil
{
    /// <summary>
    /// Gets the path of the default ICM profile for the monitor the given window is on (based on whatever MONITOR_FROM_WINDOW reports).
    /// </summary>
    /// <param name="hWnd">Handle to the window</param>
    /// <param name="monitorFlags">Flags to determine which monitor to use when it can not be determined from the window, as per https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-monitorfromwindow .</param>
    /// <returns>The path of the ICM profile, or an empty string if it could not be determined.</returns>
    std::wstring GetICMProfilePathFromWindowMonitor(HWND hWnd, DWORD monitorFlags = MONITOR_DEFAULTTONEAREST);
}
