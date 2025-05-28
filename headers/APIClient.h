#ifndef CALLER_H
#define CALLER_H

#include <vector>
#include <string>
#include "httplib.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

class APIClient
{
private:
    static std::string url;

public:
    static std::string get_contact(const json &jsonPayload);
    static std::string get_tour(const json &jsonPayload);
    static std::string get_member(const json &jsonPayload);
    static std::string get_membership_enrollment_form(const json &jsonPayload);
    static std::string get_medical_history_form(const json &jsonPayload);
    static std::string get_incident_report(const json &jsonPayload);
    static std::string get_evaluation(const json &jsonPayload);
    static std::string get_transportation_information(const json &jsonPayload);
    static std::string get_caregiver(const json &jsonPayload);
    static std::string get_attending_caregiver(const json &jsonPayload);
    static std::string get_emergency_contact(const json &jsonPayload);
    static std::string get_volunteer(const json &jsonPayload);
    static std::string get_applications(const json &jsonPayload);
    static std::string get_outreach(const json &jsonPayload);

    static int update_contact(const json &jsonPayload);
    static int update_tour(const json &jsonPayload);
    static int update_member(const json &jsonPayload);
    static int update_membership_enrollment_form(const json &jsonPayload);
    static int update_medical_history_form(const json &jsonPayload);
    static int update_incident_report(const json &jsonPayload);
    static int update_evaluation(const json &jsonPayload);
    static int update_transportation_information(const json &jsonPayload);
    static int update_caregiver(const json &jsonPayload);
    static int update_attending_caregiver(const json &jsonPayload);
    static int update_emergency_contact(const json &jsonPayload);
    static int update_volunteer(const json &jsonPayload);
    static int update_applications(const json &jsonPayload);
    static int update_outreach(const json &jsonPayload);

    static std::string create_contact(const json &jsonPayload);
    static std::string create_tour(const json &jsonPayload);
    static std::string create_member(const json &jsonPayload);
    static std::string create_membership_enrollment_form(const json &jsonPayload);
    static std::string create_medical_history_form(const json &jsonPayload);
    static std::string create_incident_report(const json &jsonPayload);
    static std::string create_evaluation(const json &jsonPayload);
    static std::string create_transportation_information(const json &jsonPayload);
    static std::string create_caregiver(const json &jsonPayload);
    static std::string create_attending_caregiver(const json &jsonPayload);
    static std::string create_emergency_contact(const json &jsonPayload);
    static std::string create_volunteer(const json &jsonPayload);
    static std::string create_applications(const json &jsonPayload);
    static std::string create_outreach(const json &jsonPayload);
};

#endif // CALLER_H
