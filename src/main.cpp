#include "webview.h"
#include <windows.h>
#include <filesystem>

#include "caller.h"

namespace fs = std::filesystem;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    webview::webview w(true, nullptr);
    w.set_title("Webview with Relative Path");

    // Get the absolute path to the copied HTML file
    std::string html_path = (fs::current_path() / "../web/index.html").string();

    // Ensure correct path format for Windows (replace \ with /)
    for (auto &ch : html_path)
    {
        if (ch == '\\')
            ch = '/';
    }

    std::string file_url = "file:///" + html_path;
    w.navigate(file_url);

    w.run();
    return 0;
}
