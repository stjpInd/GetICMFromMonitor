# GetICMFromMonitor
Win32 sample that gets the path of the (default) ICM profile for whatever monitor the window is (mostly) on. The important code is in [GetICMProfilePathFromMonitorWindow.cpp](https://github.com/stjpInd/GetICMFromMonitor/blob/master/GetICMFromMonitor/GetICMProfilePathFromMonitorWindow.cpp).

Created with Visual Studio Community 2019 using the C++ Windows Desktop Application template.

# Using the application

Drag the window to any monitor and the path of the default ICM profile for that monitor (based on whatever monitor [MonitorFromWindow](https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-monitorfromwindow) returns) will be displayed.
