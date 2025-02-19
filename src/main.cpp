#include "webview.h"
#include <windows.h>
#include <filesystem>

#include "logger.h"
#include "APIClient.h"

using json = nlohmann::json;

namespace fs = std::filesystem;

const std::string BaseFilePath = "C:/Adler_Database/src";

std::string escapeForJS(const std::string &input)
{
    std::ostringstream escaped;
    escaped << '"';

    for (char c : input)
    {
        switch (c)
        {
        case '"':
            escaped << "\\\"";
            break;
        case '\'':
            escaped << "\\'";
            break;
        case '\\':
            escaped << "\\\\";
            break;
        case '\n':
            escaped << "\\n";
            break;
        case '\r':
            escaped << "\\r";
            break;
        case '\t':
            escaped << "\\t";
            break;
        default:
            escaped << c;
        }
    }

    escaped << '"'; // End with a double-quote
    return escaped.str();
}

void createBindings(webview::webview &w)
{
    // add is not called
    w.bind("loadHTMLPage", [&](const std::string &msg) -> std::string
           {
        w.navigate(BaseFilePath + "../web/" + msg + ".html");
        return ""; });

    // check navigate goes to right place
    w.bind("loadTours", [&](const std::string &msg) -> std::string
           {
        w.navigate(BaseFilePath + "../web/tours.html");
        return ""; });

    w.bind("loadCallers", [&](const std::string &msg) -> std::string
           {
        w.navigate(BaseFilePath + "../web/index.html");
        return ""; });

    // changed name could be messed up
    w.bind("getCallerData", [&](const std::string &msg) -> std::string
           {
        std::string message;
        
        json jsonPayload;
        jsonPayload["caller_name"] = "";
        std::string result = APIClient::get_caller(jsonPayload);
        w.eval("updateCallerTable(`" + result + "`);");
        return escapeForJS(result); });
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    webview::webview w(true, nullptr);
    w.set_title("Adler Database");
    w.set_size(800, 600, WEBVIEW_HINT_NONE);

    createBindings(w);

    w.navigate(BaseFilePath + "/../web/index.html");

    w.run();
    return 0;
}