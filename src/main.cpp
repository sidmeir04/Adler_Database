#include "webview.h"
#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    webview::webview w(true, nullptr);
    w.set_title("Webview GUI App");
    w.set_size(800, 600, WEBVIEW_HINT_NONE);
    w.set_html("<html><body><h1>Hello from Webview</h1></body></html>");
    w.run();
    return 0;
}
