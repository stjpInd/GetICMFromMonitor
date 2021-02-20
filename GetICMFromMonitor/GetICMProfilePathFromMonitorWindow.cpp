#include "GetICMProfilePathFromMonitorWindow.h"

namespace
{
    std::wstring GetICMProfilePathFromDC(HDC hDC)
    {
        // https://docs.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-geticmprofilew
        // First get the buffer size
        // If the buffer is not large enough, the function returns FALSE
        // If not, then I guess the ICM profile is empty?
        std::wstring profilePath = L"";
        DWORD bufferSize = 0;
        if (!::GetICMProfileW(hDC, &bufferSize, nullptr))
        {
            // Now that we have the buffer size, allocate space and get the profile name
            std::vector<WCHAR> buffer(bufferSize, L'\0');
            if (::GetICMProfileW(hDC, &bufferSize, buffer.data()))
            {
                profilePath = buffer.data();
            }
        }
        return profilePath;
    }
}

namespace ICMUtil
{
    std::wstring GetICMProfilePathFromWindowMonitor(HWND hWnd, DWORD monitorFlags)
    {
        std::wstring profilePath = L"";

        auto hMonitor = ::MonitorFromWindow(hWnd, monitorFlags);
        if (hMonitor == nullptr)
        {
            return profilePath;
        }

        auto monitorInfo = MONITORINFOEX{};
        monitorInfo.cbSize = sizeof(MONITORINFOEX);
        if (!::GetMonitorInfoW(hMonitor, &monitorInfo))
        { 
            return profilePath; 
        }
        
        auto hMonitorDC = ::CreateDCW(L"DISPLAY", monitorInfo.szDevice, nullptr, nullptr);
        if (hMonitorDC != nullptr)
        {
            profilePath = GetICMProfilePathFromDC(hMonitorDC);
            ::DeleteDC(hMonitorDC);
        }

        return profilePath;
    }
}