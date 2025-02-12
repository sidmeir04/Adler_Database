#include "webview.h"
#include <windows.h>
#include <filesystem>

#include "caller.h"
#include "logger.h"

namespace fs = std::filesystem;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    webview::webview w(true, nullptr);
    w.set_title("Adler Database");
    w.set_size(800, 600, WEBVIEW_HINT_NONE);

    w.bind("loadNewPage", [&](const std::string &msg) -> std::string
           {
            LogToFile("loadNewPage called with message: " + msg);
        w.navigate("C:/Adler_Database/web/tours.html"); // Replace with actual path
        return ""; });

    // Function to switch back to Page 1
    w.bind("goBack", [&](const std::string &msg) -> std::string
           {
        w.navigate("C:/Adler_Database/web/index.html"); // Replace with actual path
        return ""; });

    w.navigate("C:/Adler_Database/web/index.html");

    w.run();
    return 0;
}
