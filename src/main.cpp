#include "webview.h"
#include <windows.h>
#include <filesystem>
#include <future>
#include <string>

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

    w.bind("loadMemberForm", [&](const std::string &msg) -> std::string
           {
        w.navigate(BaseFilePath + "../web/addMember.html");
        if (msg != ""){
            w.eval("updateMemberID(`" + msg + "`);");
        }
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

    w.bind("createMemberModal", [&](const std::string &msg) -> std::string
           {
        json jsonPayload;
        jsonPayload["id"] = "1";
        std::string userData = APIClient::get_member(jsonPayload);
        json userJSON = json::parse(userData);
        auto getEnrollmentData = std::async(std::launch::async, [=]() { // Capture by value
            json localPayload = jsonPayload; // Make a local copy
            localPayload["id"] = userJSON["enrollment_form"][0];
            return APIClient::get_membership_enrollment_form(localPayload);
        });
        
        auto getMedicalData = std::async(std::launch::async, [=]() {
            json localPayload = jsonPayload;
            localPayload["id"] = userJSON["medical_history"][0];
            return APIClient::get_medical_history_form(localPayload);
        });
        
        auto getEmergencyOne = std::async(std::launch::async, [=]() {
            json localPayload = jsonPayload;
            localPayload["id"] = userJSON["emergency_contact_one"][0];
            return APIClient::get_emergency_contact(localPayload);
        });
        
        auto getEmergencyTwo = std::async(std::launch::async, [=]() {
            json localPayload = jsonPayload;
            localPayload["id"] = userJSON["emergency_contact_two"][0];
            return APIClient::get_emergency_contact(localPayload);
        });
        

        std::string enrollmentData = getEnrollmentData.get();
        std::string medicalData = getMedicalData.get();
        std::string emergency_one = getEmergencyOne.get();
        std::string emergency_two = getEmergencyTwo.get();
        w.eval("memberModal(`" + userData + "`,`" + enrollmentData + "`,`" + medicalData + "`,`" + emergency_one +  + "`,`" + emergency_two + "`);");
        return ""; });

    w.bind("addMember", [&](const std::string &msg) -> std::string
           {
        json jsonPayload = json::parse(msg);
        int result = APIClient::create_member(jsonPayload);
        return std::to_string(result); });

    w.bind("updateMember", [&](const std::string &msg) -> std::string
           {
        json jsonPayload = json::parse(msg);
        int result = APIClient::update_member(jsonPayload);
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