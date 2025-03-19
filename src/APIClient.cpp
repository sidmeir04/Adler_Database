#include <iostream>
#include <vector>
#include <string>
#include "APIClient.h"
#include "httplib.h"         // HTTP client library
#include "nlohmann/json.hpp" // JSON parsing library

using json = nlohmann::json;

std::string APIClient::get_caller(const json &jsonPayload)
{
    httplib::Client localClient("localhost", 5000);
    std::string jsonBody = jsonPayload.dump();

    auto post_response = localClient.Post("/get_caller", jsonBody, "application/json");

    return post_response->body;
}

std::string APIClient::get_tour(const json &jsonPayload)
{
    httplib::Client localClient("localhost", 5000);
    std::string jsonBody = jsonPayload.dump();

    auto post_response = localClient.Post("/get_tour", jsonBody, "application/json");

    return post_response->body;
}

std::string APIClient::get_member(const json &jsonPayload)
{
    httplib::Client localClient("localhost", 5000);
    std::string jsonBody = jsonPayload.dump();

    auto post_response = localClient.Post("/get_member", jsonBody, "application/json");

    return post_response->body;
}

std::string APIClient::get_membership_enrollment_form(const json &jsonPayload)
{
    httplib::Client localClient("localhost", 5000);
    std::string jsonBody = jsonPayload.dump();

    auto post_response = localClient.Post("/get_membership_enrollment_form", jsonBody, "application/json");

    return post_response->body;
}

std::string APIClient::get_medical_history_form(const json &jsonPayload)
{
    httplib::Client localClient("localhost", 5000);
    std::string jsonBody = jsonPayload.dump();

    auto post_response = localClient.Post("/get_medical_history_form", jsonBody, "application/json");

    return post_response->body;
}

std::string APIClient::get_incident_report(const json &jsonPayload)
{
    httplib::Client localClient("localhost", 5000);
    std::string jsonBody = jsonPayload.dump();

    auto post_response = localClient.Post("/get_incident_report", jsonBody, "application/json");

    return post_response->body;
}

std::string APIClient::get_evaluation(const json &jsonPayload)
{
    httplib::Client localClient("localhost", 5000);
    std::string jsonBody = jsonPayload.dump();

    auto post_response = localClient.Post("/get_evaluation", jsonBody, "application/json");

    return post_response->body;
}

std::string APIClient::get_transport_information(const json &jsonPayload)
{
    httplib::Client localClient("localhost", 5000);
    std::string jsonBody = jsonPayload.dump();

    auto post_response = localClient.Post("/get_transport_information", jsonBody, "application/json");

    return post_response->body;
}

std::string APIClient::get_caregiver(const json &jsonPayload)
{
    httplib::Client localClient("localhost", 5000);
    std::string jsonBody = jsonPayload.dump();

    auto post_response = localClient.Post("/get_caregiver", jsonBody, "application/json");

    return post_response->body;
}

std::string APIClient::get_attending_caregiver(const json &jsonPayload)
{
    httplib::Client localClient("localhost", 5000);
    std::string jsonBody = jsonPayload.dump();

    auto post_response = localClient.Post("/get_attending_caregiver", jsonBody, "application/json");

    return post_response->body;
}

std::string APIClient::get_emergency_contact(const json &jsonPayload)
{
    httplib::Client localClient("localhost", 5000);
    std::string jsonBody = jsonPayload.dump();

    auto post_response = localClient.Post("/get_emergency_contact", jsonBody, "application/json");

    return post_response->body;
}

std::string APIClient::get_volunteer(const json &jsonPayload)
{
    httplib::Client localClient("localhost", 5000);
    std::string jsonBody = jsonPayload.dump();

    auto post_response = localClient.Post("/get_volunteer", jsonBody, "application/json");

    return post_response->body;
}

std::string APIClient::get_applications(const json &jsonPayload)
{
    httplib::Client localClient("localhost", 5000);
    std::string jsonBody = jsonPayload.dump();

    auto post_response = localClient.Post("/get_applications", jsonBody, "application/json");

    return post_response->body;
}

std::string APIClient::get_outreach(const json &jsonPayload)
{
    httplib::Client localClient("localhost", 5000);
    std::string jsonBody = jsonPayload.dump();

    auto post_response = localClient.Post("/get_outreach", jsonBody, "application/json");

    return post_response->body;
}

int APIClient::update_caller(const json &jsonPayload)
{
    httplib::Client localClient("localhost", 5000);
    std::string jsonBody = jsonPayload.dump();
    auto post_response = localClient.Post("/update_caller", jsonBody, "application/json");
    return 1;
}

int APIClient::update_tour(const json &jsonPayload)
{
    httplib::Client localClient("localhost", 5000);
    std::string jsonBody = jsonPayload.dump();
    auto post_response = localClient.Post("/update_tour", jsonBody, "application/json");
    return 1;
}

int APIClient::update_member(const json &jsonPayload)
{
    httplib::Client localClient("localhost", 5000);
    std::string jsonBody = jsonPayload.dump();
    auto post_response = localClient.Post("/update_member", jsonBody, "application/json");
    return 1;
}

int APIClient::update_membership_enrollment_form(const json &jsonPayload)
{
    httplib::Client localClient("localhost", 5000);
    std::string jsonBody = jsonPayload.dump();
    auto post_response = localClient.Post("/update_membership_enrollment_form", jsonBody, "application/json");
    return 1;
}

int APIClient::update_medical_history_form(const json &jsonPayload)
{
    httplib::Client localClient("localhost", 5000);
    std::string jsonBody = jsonPayload.dump();
    auto post_response = localClient.Post("/update_medical_history_form", jsonBody, "application/json");
    return 1;
}

int APIClient::update_incident_report(const json &jsonPayload)
{
    httplib::Client localClient("localhost", 5000);
    std::string jsonBody = jsonPayload.dump();
    auto post_response = localClient.Post("/update_incident_report", jsonBody, "application/json");
    return 1;
}

int APIClient::update_evaluation(const json &jsonPayload)
{
    httplib::Client localClient("localhost", 5000);
    std::string jsonBody = jsonPayload.dump();
    auto post_response = localClient.Post("/update_evaluation", jsonBody, "application/json");
    return 1;
}

int APIClient::update_transport_information(const json &jsonPayload)
{
    httplib::Client localClient("localhost", 5000);
    std::string jsonBody = jsonPayload.dump();
    auto post_response = localClient.Post("/update_transport_information", jsonBody, "application/json");
    return 1;
}

int APIClient::update_caregiver(const json &jsonPayload)
{
    httplib::Client localClient("localhost", 5000);
    std::string jsonBody = jsonPayload.dump();
    auto post_response = localClient.Post("/update_caregiver", jsonBody, "application/json");
    return 1;
}

int APIClient::update_attending_caregiver(const json &jsonPayload)
{
    httplib::Client localClient("localhost", 5000);
    std::string jsonBody = jsonPayload.dump();
    auto post_response = localClient.Post("/update_attending_caregiver", jsonBody, "application/json");
    return 1;
}

int APIClient::update_emergency_contact(const json &jsonPayload)
{
    httplib::Client localClient("localhost", 5000);
    std::string jsonBody = jsonPayload.dump();
    auto post_response = localClient.Post("/update_emergency_contact", jsonBody, "application/json");
    return 1;
}

int APIClient::update_volunteer(const json &jsonPayload)
{
    httplib::Client localClient("localhost", 5000);
    std::string jsonBody = jsonPayload.dump();
    auto post_response = localClient.Post("/update_volunteer", jsonBody, "application/json");
    return 1;
}

int APIClient::update_applications(const json &jsonPayload)
{
    httplib::Client localClient("localhost", 5000);
    std::string jsonBody = jsonPayload.dump();
    auto post_response = localClient.Post("/update_applications", jsonBody, "application/json");
    return 1;
}

int APIClient::update_outreach(const json &jsonPayload)
{
    httplib::Client localClient("localhost", 5000);
    std::string jsonBody = jsonPayload.dump();
    auto post_response = localClient.Post("/update_outreach", jsonBody, "application/json");
    return 1;
}

std::string APIClient::create_caller(const json &jsonPayload)
{
    httplib::Client localClient("localhost", 5000);
    std::string jsonBody = jsonPayload.dump();
    auto post_response = localClient.Post("/insert_caller", jsonBody, "application/json");
    return post_response->body;
}

std::string APIClient::create_tour(const json &jsonPayload)
{
    httplib::Client localClient("localhost", 5000);
    std::string jsonBody = jsonPayload.dump();
    auto post_response = localClient.Post("/insert_tour", jsonBody, "application/json");
    return post_response->body;
}

std::string APIClient::create_member(const json &jsonPayload)
{
    httplib::Client localClient("localhost", 5000);
    std::string jsonBody = jsonPayload.dump();
    auto post_response = localClient.Post("/insert_member", jsonBody, "application/json");
    return post_response->body;
}

std::string APIClient::create_membership_enrollment_form(const json &jsonPayload)
{
    httplib::Client localClient("localhost", 5000);
    std::string jsonBody = jsonPayload.dump();
    auto post_response = localClient.Post("/insert_membership_enrollment_form", jsonBody, "application/json");
    return post_response->body;
}

std::string APIClient::create_medical_history_form(const json &jsonPayload)
{
    httplib::Client localClient("localhost", 5000);
    std::string jsonBody = jsonPayload.dump();
    auto post_response = localClient.Post("/insert_medical_history_form", jsonBody, "application/json");
    return post_response->body;
}

std::string APIClient::create_incident_report(const json &jsonPayload)
{
    httplib::Client localClient("localhost", 5000);
    std::string jsonBody = jsonPayload.dump();
    auto post_response = localClient.Post("/insert_incident_report", jsonBody, "application/json");
    return post_response->body;
}

std::string APIClient::create_evaluation(const json &jsonPayload)
{
    httplib::Client localClient("localhost", 5000);
    std::string jsonBody = jsonPayload.dump();
    auto post_response = localClient.Post("/insert_evaluation", jsonBody, "application/json");
    return post_response->body;
}

std::string APIClient::create_transport_information(const json &jsonPayload)
{
    httplib::Client localClient("localhost", 5000);
    std::string jsonBody = jsonPayload.dump();
    auto post_response = localClient.Post("/insert_transport_information", jsonBody, "application/json");
    return post_response->body;
}

std::string APIClient::create_caregiver(const json &jsonPayload)
{
    httplib::Client localClient("localhost", 5000);
    std::string jsonBody = jsonPayload.dump();
    auto post_response = localClient.Post("/insert_caregiver", jsonBody, "application/json");
    return post_response->body;
}

std::string APIClient::create_attending_caregiver(const json &jsonPayload)
{
    httplib::Client localClient("localhost", 5000);
    std::string jsonBody = jsonPayload.dump();
    auto post_response = localClient.Post("/insert_attending_caregiver", jsonBody, "application/json");
    return post_response->body;
}

std::string APIClient::create_emergency_contact(const json &jsonPayload)
{
    httplib::Client localClient("localhost", 5000);
    std::string jsonBody = jsonPayload.dump();
    auto post_response = localClient.Post("/insert_emergency_contact", jsonBody, "application/json");
    return post_response->body;
}

std::string APIClient::create_volunteer(const json &jsonPayload)
{
    httplib::Client localClient("localhost", 5000);
    std::string jsonBody = jsonPayload.dump();
    auto post_response = localClient.Post("/insert_volunteer", jsonBody, "application/json");
    return post_response->body;
}

std::string APIClient::create_applications(const json &jsonPayload)
{
    httplib::Client localClient("localhost", 5000);
    std::string jsonBody = jsonPayload.dump();
    auto post_response = localClient.Post("/insert_applications", jsonBody, "application/json");
    return post_response->body;
}

std::string APIClient::create_outreach(const json &jsonPayload)
{
    httplib::Client localClient("localhost", 5000);
    std::string jsonBody = jsonPayload.dump();
    auto post_response = localClient.Post("/insert_outreach", jsonBody, "application/json");
    return post_response->body;
}