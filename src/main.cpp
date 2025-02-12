#include "webview.h"
#include <windows.h>
#include <filesystem>

#include "logger.h"
#include "APIClient.h"

using json = nlohmann::json;

namespace fs = std::filesystem;

std::string vectorToString(const std::vector<std::vector<std::string>> &data, const std::string &rowDelimiter = "\n", const std::string &colDelimiter = ", ")
{
    std::string result;

    for (const auto &row : data)
    {
        for (size_t i = 0; i < row.size(); ++i)
        {
            result += row[i];
            if (i < row.size() - 1)
            {
                result += colDelimiter; // Add column delimiter if not last element
            }
        }
        result += rowDelimiter; // Add row delimiter
    }

    return result;
}

std::string escapeForJS(const std::string &input)
{
    std::ostringstream escaped;
    escaped << '"'; // Start with a double-quote for JavaScript

    for (char c : input)
    {
        switch (c)
        {
        case '"':
            escaped << "\\\"";
            break; // Escape double quotes
        case '\'':
            escaped << "\\'";
            break; // Escape single quotes
        case '\\':
            escaped << "\\\\";
            break; // Escape backslashes
        case '\n':
            escaped << "\\n";
            break; // Escape newlines
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
    w.bind("loadNewPage", [&](const std::string &msg) -> std::string
           {
        w.navigate("C:/Adler_Database/web/tours.html"); // Replace with actual path
        return ""; });

    // Function to switch back to Page 1
    w.bind("goBack", [&](const std::string &msg) -> std::string
           {
        w.navigate("C:/Adler_Database/web/index.html"); // Replace with actual path
        return ""; });

    w.bind("requestMessageFromCpp", [&](const std::string &msg) -> std::string
           {
        std::string message = "Hello from C++!";
        
        json jsonPayload;
        jsonPayload["caller_name"] = "";
        try
        {
            std::vector<std::vector<std::string>> result = APIClient::get_caller(jsonPayload);
            w.eval("updateMessageFromCpp('" + escapeForJS(vectorToString(result)) + "');");
        }
        catch(const std::exception& e)
        {
            LogToFile(e.what());
        }

        return ""; });
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    webview::webview w(true, nullptr);
    w.set_title("Adler Database");
    w.set_size(800, 600, WEBVIEW_HINT_NONE);

    createBindings(w);

    w.navigate("C:/Adler_Database/web/index.html");

    w.run();
    return 0;
}