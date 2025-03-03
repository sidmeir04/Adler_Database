#include "webview.h"
#include <windows.h>
#include <filesystem>

#include "logger.h"
#include "APIClient.h"

using json = nlohmann::json;

// const std::string BaseFilePath = std::filesystem::current_path().string();
const std::string BaseFilePath = "C:/Adler_Database/src/";

void createBindings(webview::webview &w)
{
    // is not called
    w.bind("loadHTMLPage", [&](const std::string &msg) -> std::string
           {
        w.navigate(BaseFilePath + "../web/" + msg + ".html");
        return ""; });

    w.bind("loadTours", [&](const std::string &msg) -> std::string
           {
        w.navigate(BaseFilePath + "../web/tours.html");
        return ""; });

    w.bind("loadMembers", [&](const std::string &msg) -> std::string
           {
        w.navigate(BaseFilePath + "../web/members.html");
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
        return ""; });

    w.bind("getMemberData", [&](const std::string &msg) -> std::string
           {
        std::string message;
        
        json jsonPayload;
        jsonPayload["name"] = "";
        std::string result = APIClient::get_member(jsonPayload);
        w.eval("updateMembers(`" + result + "`);");
        return ""; });
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    webview::webview w(true, nullptr);
    w.set_title("Adler Database");
    w.set_size(800, 600, WEBVIEW_HINT_NONE);

    createBindings(w);

    w.navigate(BaseFilePath + "../web/members.html");

    w.run();
    return 0;
}