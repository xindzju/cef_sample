#include "cef_sample_client.h"

#include <windows.h>
#include <string>

#include "include/cef_browser.h"

void CefSampleClient::PlatformTitleChange(CefRefPtr<CefBrowser> browser,
    const CefString& title) {
    CefWindowHandle hwnd = browser->GetHost()->GetWindowHandle();
    if (hwnd)
        SetWindowTextW(hwnd, std::wstring(title).c_str());
}