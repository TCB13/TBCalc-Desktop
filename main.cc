#include "webview.h"
#include <windows.h> 
#include <filesystem>

/*
Convert SVG icon to .ICO:
https://redketchup.io/icon-converter

Compile with: 
.\script\build.bat
 */

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // Create the webview
    webview::webview w(false, nullptr);
    w.set_title("TBCalc - v1.1");

    // Version function
    w.bind("appversion", [](std::string s) -> std::string {
        return "1.1.0";
    });

    // Get executable path
    wchar_t rawPathName[MAX_PATH] = { 0 };
    GetModuleFileNameW(NULL, rawPathName, MAX_PATH);
    std::string executablePath = std::filesystem::path(rawPathName).parent_path().string();

    // Load local app
    w.navigate(executablePath + "\\tbcalc\\index.html");
    w.run();

    return 0;
}
