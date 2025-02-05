#ifndef CALLER_H
#define CALLER_H

#include <vector>
#include <string>
#include "httplib.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

class APIClient
{
public:
    static std::vector<std::vector<std::string>> get_caller(const json &jsonPayload);
    static std::vector<std::vector<std::string>> get_tour(const json &jsonPayload);
    static std::vector<std::vector<std::string>> get_member(const json &jsonPayload);
    static std::vector<std::vector<std::string>> get_membership_enrollment_form(const json &jsonPayload);
    static std::vector<std::vector<std::string>> get_medical_history_form(const json &jsonPayload);
    static std::vector<std::vector<std::string>> get_incident_report(const json &jsonPayload);
    static std::vector<std::vector<std::string>> get_evaluation(const json &jsonPayload);
    static std::vector<std::vector<std::string>> get_transport_information(const json &jsonPayload);
    static std::vector<std::vector<std::string>> get_caregiver(const json &jsonPayload);
    static std::vector<std::vector<std::string>> get_attending_caregiver(const json &jsonPayload);
    static std::vector<std::vector<std::string>> get_emergency_contact(const json &jsonPayload);
    static std::vector<std::vector<std::string>> get_volunteer(const json &jsonPayload);
    static std::vector<std::vector<std::string>> get_applications(const json &jsonPayload);
    static std::vector<std::vector<std::string>> get_outreach(const json &jsonPayload);

    static int update_caller(const json &jsonPayload);
    static int update_tour(const json &jsonPayload);
    static int update_member(const json &jsonPayload);
    static int update_membership_enrollment_form(const json &jsonPayload);
    static int update_medical_history_form(const json &jsonPayload);
    static int update_incident_report(const json &jsonPayload);
    static int update_evaluation(const json &jsonPayload);
    static int update_transport_information(const json &jsonPayload);
    static int update_caregiver(const json &jsonPayload);
    static int update_attending_caregiver(const json &jsonPayload);
    static int update_emergency_contact(const json &jsonPayload);
    static int update_volunteer(const json &jsonPayload);
    static int update_applications(const json &jsonPayload);
    static int update_outreach(const json &jsonPayload);

    static int create_caller(const json &jsonPayload);
    static int create_tour(const json &jsonPayload);
    static int create_member(const json &jsonPayload);
    static int create_membership_enrollment_form(const json &jsonPayload);
    static int create_medical_history_form(const json &jsonPayload);
    static int create_incident_report(const json &jsonPayload);
    static int create_evaluation(const json &jsonPayload);
    static int create_transport_information(const json &jsonPayload);
    static int create_caregiver(const json &jsonPayload);
    static int create_attending_caregiver(const json &jsonPayload);
    static int create_emergency_contact(const json &jsonPayload);
    static int create_volunteer(const json &jsonPayload);
    static int create_applications(const json &jsonPayload);
    static int create_outreach(const json &jsonPayload);
};

#endif // CALLER_H
