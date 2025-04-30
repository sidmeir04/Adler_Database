#include "webview.h"
#include <windows.h>
#include <filesystem>
#include <future>
#include <string>
#include <iostream>
#include <iomanip>

#include "logger.h"
#include "APIClient.h"

using json = nlohmann::json;

char buffer[MAX_PATH];
DWORD length = GetModuleFileNameA(NULL, buffer, MAX_PATH);
std::string fullPath(buffer);
size_t pos = fullPath.find_last_of("\\/");
std::string BaseFilePath = fullPath.substr(0, pos) + '/';

std::string
escape_json_for_js(const std::string &json)
{
    std::ostringstream escaped;
    escaped << std::quoted(json);
    return escaped.str();
}

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
        LogToFile(msg);
        if (msg != ""){
            try {
                LogToFile("Getting member data");
            
                json jsonPayload;
                jsonPayload["id"] = msg.substr(2, msg.size() - 4);
                std::string userData = APIClient::get_member(jsonPayload);
                json userJSON = json::parse(userData);
            
                std::future<std::string> getEnrollmentData;
                std::future<std::string> getMedicalData;
                std::future<std::string> getEmergencyOne;
                std::future<std::string> getEmergencyTwo;

                LogToFile("Member data retrieved successfully");
                LogToFile("User JSON: " + userJSON.dump(4));
            
                if ((userJSON["enrollment_form"] != "None") && (userJSON["enrollment_form"].size() > 0)) {
                    getEnrollmentData = std::async(std::launch::async, [=]() {
                        json localPayload = jsonPayload;
                        localPayload["id"] = userJSON["enrollment_form"][0];
                        return APIClient::get_membership_enrollment_form(localPayload);
                    });
                }
            
                if ((userJSON["medical_history"] != "None") && (userJSON["medical_history"].size() > 0)) {
                    getMedicalData = std::async(std::launch::async, [=]() {
                        json localPayload = jsonPayload;
                        localPayload["id"] = userJSON["medical_history"][0];
                        return APIClient::get_medical_history_form(localPayload);
                    });
                }
            
                if ((userJSON["emergency_contact_one"] != "None") && (userJSON["emergency_contact_one"].size() > 0)) {
                    getEmergencyOne = std::async(std::launch::async, [=]() {
                        json localPayload = jsonPayload;
                        localPayload["id"] = userJSON["emergency_contact_one"][0];
                        return APIClient::get_emergency_contact(localPayload);
                    });
                }
            
                if ((userJSON["emergency_contact_two"] != "None") && (userJSON["emergency_contact_two"].size() > 0)) {
                    getEmergencyTwo = std::async(std::launch::async, [=]() {
                        json localPayload = jsonPayload;
                        localPayload["id"] = userJSON["emergency_contact_two"][0];
                        return APIClient::get_emergency_contact(localPayload);
                    });
                }
            
                std::string enrollmentData = "None";
                std::string medicalData = "None";
                std::string ec1Data = "None";
                std::string ec2Data = "None";
            
                if (getEnrollmentData.valid()) enrollmentData = getEnrollmentData.get();
                if (getMedicalData.valid()) medicalData = getMedicalData.get();
                if (getEmergencyOne.valid()) ec1Data = getEmergencyOne.get();
                if (getEmergencyTwo.valid()) ec2Data = getEmergencyTwo.get();
            
                json combinedData;
                combinedData["userData"] = json::parse(userData);
                combinedData["enrollmentData"] = json::parse(enrollmentData);
                combinedData["medicalData"] = json::parse(medicalData);
                combinedData["emergencyContactOne"] = json::parse(ec1Data);
                combinedData["emergencyContactTwo"] = json::parse(ec2Data);
            
                std::string combinedDataString = combinedData.dump();
                std::string safeJson = escape_json_for_js(combinedDataString);
                LogToFile(safeJson);
                w.eval("document.addEventListener('DOMContentLoaded', function() { initializeFormData(" + safeJson + "); });");
            
            } catch (const std::exception& e) {
                LogToFile(std::string("Exception: ") + e.what());
            } catch (...) {
                LogToFile("Unknown error occurred while getting and processing member data.");
            }
        }
        return ""; });

    w.bind("loadCaregiverForm", [&](const std::string &msg) -> std::string
           {
        w.navigate(BaseFilePath + "../web/addCaregiver.html");
        LogToFile(msg);
        if (msg != ""){
            try {
                LogToFile("Getting caregiver data");
            
                json jsonPayload;
                jsonPayload["id"] = msg.substr(2, msg.size() - 4);
                std::string userData = APIClient::get_caregiver(jsonPayload);
                json userJSON = json::parse(userData);
            
                std::future<std::string> getEnrollmentData;
                std::future<std::string> getMedicalData;
                std::future<std::string> getEmergencyOne;
                std::future<std::string> getEmergencyTwo;

                LogToFile("Caregiver data retrieved successfully");
                LogToFile("User JSON: " + userJSON.dump(4));
            
                if ((userJSON["enrollment_form"] != "None") && (userJSON["enrollment_form"].size() > 0)) {
                    getEnrollmentData = std::async(std::launch::async, [=]() {
                        json localPayload = jsonPayload;
                        localPayload["id"] = userJSON["enrollment_form"][0];
                        return APIClient::get_membership_enrollment_form(localPayload);
                    });
                }
            
                if ((userJSON["medical_history"] != "None") && (userJSON["medical_history"].size() > 0)) {
                    getMedicalData = std::async(std::launch::async, [=]() {
                        json localPayload = jsonPayload;
                        localPayload["id"] = userJSON["medical_history"][0];
                        return APIClient::get_medical_history_form(localPayload);
                    });
                }
            
                if ((userJSON["emergency_contact_one"] != "None") && (userJSON["emergency_contact_one"].size() > 0)) {
                    getEmergencyOne = std::async(std::launch::async, [=]() {
                        json localPayload = jsonPayload;
                        localPayload["id"] = userJSON["emergency_contact_one"][0];
                        return APIClient::get_emergency_contact(localPayload);
                    });
                }
            
                if ((userJSON["emergency_contact_two"] != "None") && (userJSON["emergency_contact_two"].size() > 0)) {
                    getEmergencyTwo = std::async(std::launch::async, [=]() {
                        json localPayload = jsonPayload;
                        localPayload["id"] = userJSON["emergency_contact_two"][0];
                        return APIClient::get_emergency_contact(localPayload);
                    });
                }
            
                std::string enrollmentData = "None";
                std::string medicalData = "None";
                std::string ec1Data = "None";
                std::string ec2Data = "None";
            
                if (getEnrollmentData.valid()) enrollmentData = getEnrollmentData.get();
                if (getMedicalData.valid()) medicalData = getMedicalData.get();
                if (getEmergencyOne.valid()) ec1Data = getEmergencyOne.get();
                if (getEmergencyTwo.valid()) ec2Data = getEmergencyTwo.get();
            
                json combinedData;
                combinedData["userData"] = json::parse(userData);
                combinedData["enrollmentData"] = json::parse(enrollmentData);
                combinedData["medicalData"] = json::parse(medicalData);
                combinedData["emergencyContactOne"] = json::parse(ec1Data);
                combinedData["emergencyContactTwo"] = json::parse(ec2Data);
            
                std::string combinedDataString = combinedData.dump();
                std::string safeJson = escape_json_for_js(combinedDataString);
                LogToFile(safeJson);
                w.eval("document.addEventListener('DOMContentLoaded', function() { initializeFormData(" + safeJson + "); });");
            
            } catch (const std::exception& e) {
                LogToFile(std::string("Exception: ") + e.what());
            } catch (...) {
                LogToFile("Unknown error occurred while getting and processing member data.");
            }
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
        
        auto getCaregivers = std::async(std::launch::async, [=]() {
            json localPayload = jsonPayload;
            localPayload["member_id"] = userJSON["id"][0];
            return APIClient::get_caregiver(localPayload);
        });
        
        std::string enrollmentData = getEnrollmentData.get();
        std::string medicalData = getMedicalData.get();
        std::string emergency_one = getEmergencyOne.get();
        std::string emergency_two = getEmergencyTwo.get();
        std::string caregivers = getCaregivers.get();
        std::string safeEnrollmentData = escape_json_for_js(enrollmentData);
        safeEnrollmentData = safeEnrollmentData.substr(1, safeEnrollmentData.length() - 2);
        std::string safeMedicalData = escape_json_for_js(medicalData);
        safeMedicalData = safeMedicalData.substr(1, safeMedicalData.length() - 2);
        w.eval("memberModal(`" + userData + "`,`" + safeEnrollmentData + "`,`" + safeMedicalData + "`,`" + emergency_one +  + "`,`" + emergency_two + "`,`" + caregivers + "`);");
        return ""; });

    w.bind("addMember", [&](const std::string &msg) -> std::string
           {
        json jsonPayload = json::parse(msg);
        std::string result = APIClient::create_member(jsonPayload);
        LogToFile("Member created with ID: " + result);
        return result; });

    w.bind("updateMember", [&](const std::string &msg) -> std::string
           {
        json jsonPayload = json::parse(msg);
        int result = APIClient::update_member(jsonPayload);
        return ""; });

    w.bind("addCaregiver", [&](const std::string &msg) -> std::string
           {
            json jsonPayload = json::parse(msg);
            std::string result = APIClient::create_caregiver(jsonPayload);
            LogToFile("Caregiver created with ID: " + result);
            return result; });

    w.bind("updateCaregiver", [&](const std::string &msg) -> std::string
           {
            json jsonPayload = json::parse(msg);
            int result = APIClient::update_caregiver(jsonPayload);
            return ""; });

    w.bind("addMedicalHistory", [&](const std::string &msg) -> std::string
           {
        json jsonPayload = json::parse(msg);
        std::string result = APIClient::create_medical_history_form(jsonPayload);
        return result; });

    w.bind("updateMedicalHistory", [&](const std::string &msg) -> std::string
           {
        json jsonPayload = json::parse(msg);
        int result = APIClient::update_medical_history_form(jsonPayload);
        return ""; });

    w.bind("addEnrollmentForm", [&](const std::string &msg) -> std::string
           {
        json jsonPayload = json::parse(msg);
        std::string result = APIClient::create_membership_enrollment_form(jsonPayload);
        return result; });

    w.bind("updateEnrollmentForm", [&](const std::string &msg) -> std::string
           {
        json jsonPayload = json::parse(msg);
        int result = APIClient::update_membership_enrollment_form(jsonPayload);
        return ""; });

    w.bind("addEC", [&](const std::string &msg) -> std::string
           {
        json jsonPayload = json::parse(msg);
        std::string result = APIClient::create_emergency_contact(jsonPayload);
        return result; });

    w.bind("updateEC", [&](const std::string &msg) -> std::string
           {
        json jsonPayload = json::parse(msg);
        int result = APIClient::update_emergency_contact(jsonPayload);
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