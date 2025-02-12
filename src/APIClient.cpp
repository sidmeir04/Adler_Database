#include <iostream>
#include <vector>
#include <string>
#include "APIClient.h"
#include "httplib.h"         // HTTP client library
#include "nlohmann/json.hpp" // JSON parsing library

using json = nlohmann::json;

std::vector<std::vector<std::string>> APIClient::get_caller(const json &jsonPayload)
{
    std::vector<std::vector<std::string>> results;

    std::string jsonBody = jsonPayload.dump();

    auto post_response = client.Post("/get_caller", jsonBody, "application/json");

    if (post_response && post_response->status == 200)
    {
        json response_json = json::parse(post_response->body);

        for (const auto &inner_list : response_json)
        {
            std::vector<std::string> temp_list;
            for (const auto &str : inner_list)
            {
                temp_list.push_back(str.get<std::string>());
            }
            results.push_back(temp_list);
        }
    }

    return results;
}

std::vector<std::vector<std::string>> APIClient::get_tour(const json &jsonPayload)
{
    std::vector<std::vector<std::string>> results;

    std::string jsonBody = jsonPayload.dump();

    auto post_response = client.Post("/get_tour", jsonBody, "application/json");

    if (post_response && post_response->status == 200)
    {
        json response_json = json::parse(post_response->body);

        for (const auto &inner_list : response_json)
        {
            std::vector<std::string> temp_list;
            for (const auto &str : inner_list)
            {
                temp_list.push_back(str.get<std::string>());
            }
            results.push_back(temp_list);
        }
    }

    return results;
}

std::vector<std::vector<std::string>> APIClient::get_member(const json &jsonPayload)
{
    std::vector<std::vector<std::string>> results;

    std::string jsonBody = jsonPayload.dump();

    auto post_response = client.Post("/get_member", jsonBody, "application/json");

    if (post_response && post_response->status == 200)
    {
        json response_json = json::parse(post_response->body);

        for (const auto &inner_list : response_json)
        {
            std::vector<std::string> temp_list;
            for (const auto &str : inner_list)
            {
                temp_list.push_back(str.get<std::string>());
            }
            results.push_back(temp_list);
        }
    }

    return results;
}

std::vector<std::vector<std::string>> APIClient::get_membership_enrollment_form(const json &jsonPayload)
{
    std::vector<std::vector<std::string>> results;

    std::string jsonBody = jsonPayload.dump();

    auto post_response = client.Post("/get_membership_enrollment_form", jsonBody, "application/json");

    if (post_response && post_response->status == 200)
    {
        json response_json = json::parse(post_response->body);

        for (const auto &inner_list : response_json)
        {
            std::vector<std::string> temp_list;
            for (const auto &str : inner_list)
            {
                temp_list.push_back(str.get<std::string>());
            }
            results.push_back(temp_list);
        }
    }

    return results;
}

std::vector<std::vector<std::string>> APIClient::get_medical_history_form(const json &jsonPayload)
{
    std::vector<std::vector<std::string>> results;

    std::string jsonBody = jsonPayload.dump();

    auto post_response = client.Post("/get_medical_history_form", jsonBody, "application/json");

    if (post_response && post_response->status == 200)
    {
        json response_json = json::parse(post_response->body);

        for (const auto &inner_list : response_json)
        {
            std::vector<std::string> temp_list;
            for (const auto &str : inner_list)
            {
                temp_list.push_back(str.get<std::string>());
            }
            results.push_back(temp_list);
        }
    }

    return results;
}

std::vector<std::vector<std::string>> APIClient::get_incident_report(const json &jsonPayload)
{
    std::vector<std::vector<std::string>> results;

    std::string jsonBody = jsonPayload.dump();

    auto post_response = client.Post("/get_incident_report", jsonBody, "application/json");

    if (post_response && post_response->status == 200)
    {
        json response_json = json::parse(post_response->body);

        for (const auto &inner_list : response_json)
        {
            std::vector<std::string> temp_list;
            for (const auto &str : inner_list)
            {
                temp_list.push_back(str.get<std::string>());
            }
            results.push_back(temp_list);
        }
    }

    return results;
}

std::vector<std::vector<std::string>> APIClient::get_evaluation(const json &jsonPayload)
{
    std::vector<std::vector<std::string>> results;

    std::string jsonBody = jsonPayload.dump();

    auto post_response = client.Post("/get_evaluation", jsonBody, "application/json");

    if (post_response && post_response->status == 200)
    {
        json response_json = json::parse(post_response->body);

        for (const auto &inner_list : response_json)
        {
            std::vector<std::string> temp_list;
            for (const auto &str : inner_list)
            {
                temp_list.push_back(str.get<std::string>());
            }
            results.push_back(temp_list);
        }
    }

    return results;
}

std::vector<std::vector<std::string>> APIClient::get_transport_information(const json &jsonPayload)
{
    std::vector<std::vector<std::string>> results;

    std::string jsonBody = jsonPayload.dump();

    auto post_response = client.Post("/get_transport_information", jsonBody, "application/json");

    if (post_response && post_response->status == 200)
    {
        json response_json = json::parse(post_response->body);

        for (const auto &inner_list : response_json)
        {
            std::vector<std::string> temp_list;
            for (const auto &str : inner_list)
            {
                temp_list.push_back(str.get<std::string>());
            }
            results.push_back(temp_list);
        }
    }

    return results;
}

std::vector<std::vector<std::string>> APIClient::get_caregiver(const json &jsonPayload)
{
    std::vector<std::vector<std::string>> results;

    std::string jsonBody = jsonPayload.dump();

    auto post_response = client.Post("/get_caregiver", jsonBody, "application/json");

    if (post_response && post_response->status == 200)
    {
        json response_json = json::parse(post_response->body);

        for (const auto &inner_list : response_json)
        {
            std::vector<std::string> temp_list;
            for (const auto &str : inner_list)
            {
                temp_list.push_back(str.get<std::string>());
            }
            results.push_back(temp_list);
        }
    }

    return results;
}

std::vector<std::vector<std::string>> APIClient::get_attending_caregiver(const json &jsonPayload)
{
    std::vector<std::vector<std::string>> results;

    std::string jsonBody = jsonPayload.dump();

    auto post_response = client.Post("/get_attending_caregiver", jsonBody, "application/json");

    if (post_response && post_response->status == 200)
    {
        json response_json = json::parse(post_response->body);

        for (const auto &inner_list : response_json)
        {
            std::vector<std::string> temp_list;
            for (const auto &str : inner_list)
            {
                temp_list.push_back(str.get<std::string>());
            }
            results.push_back(temp_list);
        }
    }

    return results;
}

std::vector<std::vector<std::string>> APIClient::get_emergency_contact(const json &jsonPayload)
{
    std::vector<std::vector<std::string>> results;

    std::string jsonBody = jsonPayload.dump();

    auto post_response = client.Post("/get_emergency_contact", jsonBody, "application/json");

    if (post_response && post_response->status == 200)
    {
        json response_json = json::parse(post_response->body);

        for (const auto &inner_list : response_json)
        {
            std::vector<std::string> temp_list;
            for (const auto &str : inner_list)
            {
                temp_list.push_back(str.get<std::string>());
            }
            results.push_back(temp_list);
        }
    }

    return results;
}

std::vector<std::vector<std::string>> APIClient::get_volunteer(const json &jsonPayload)
{
    std::vector<std::vector<std::string>> results;

    std::string jsonBody = jsonPayload.dump();

    auto post_response = client.Post("/get_volunteer", jsonBody, "application/json");

    if (post_response && post_response->status == 200)
    {
        json response_json = json::parse(post_response->body);

        for (const auto &inner_list : response_json)
        {
            std::vector<std::string> temp_list;
            for (const auto &str : inner_list)
            {
                temp_list.push_back(str.get<std::string>());
            }
            results.push_back(temp_list);
        }
    }

    return results;
}

std::vector<std::vector<std::string>> APIClient::get_applications(const json &jsonPayload)
{
    std::vector<std::vector<std::string>> results;

    std::string jsonBody = jsonPayload.dump();

    auto post_response = client.Post("/get_applications", jsonBody, "application/json");

    if (post_response && post_response->status == 200)
    {
        json response_json = json::parse(post_response->body);

        for (const auto &inner_list : response_json)
        {
            std::vector<std::string> temp_list;
            for (const auto &str : inner_list)
            {
                temp_list.push_back(str.get<std::string>());
            }
            results.push_back(temp_list);
        }
    }

    return results;
}

std::vector<std::vector<std::string>> APIClient::get_outreach(const json &jsonPayload)
{
    std::vector<std::vector<std::string>> results;

    std::string jsonBody = jsonPayload.dump();

    auto post_response = client.Post("/get_outreach", jsonBody, "application/json");

    if (post_response && post_response->status == 200)
    {
        json response_json = json::parse(post_response->body);

        for (const auto &inner_list : response_json)
        {
            std::vector<std::string> temp_list;
            for (const auto &str : inner_list)
            {
                temp_list.push_back(str.get<std::string>());
            }
            results.push_back(temp_list);
        }
    }

    return results;
}

int APIClient::update_caller(const json &jsonPayload)
{
    std::string jsonBody = jsonPayload.dump();
    auto post_response = client.Post("/update_caller", jsonBody, "application/json");
    return 1;
}

int APIClient::update_tour(const json &jsonPayload)
{
    std::string jsonBody = jsonPayload.dump();
    auto post_response = client.Post("/update_tour", jsonBody, "application/json");
    return 1;
}

int APIClient::update_member(const json &jsonPayload)
{
    std::string jsonBody = jsonPayload.dump();
    auto post_response = client.Post("/update_member", jsonBody, "application/json");
    return 1;
}

int APIClient::update_membership_enrollment_form(const json &jsonPayload)
{
    std::string jsonBody = jsonPayload.dump();
    auto post_response = client.Post("/update_membership_enrollment_form", jsonBody, "application/json");
    return 1;
}

int APIClient::update_medical_history_form(const json &jsonPayload)
{
    std::string jsonBody = jsonPayload.dump();
    auto post_response = client.Post("/update_medical_history_form", jsonBody, "application/json");
    return 1;
}

int APIClient::update_incident_report(const json &jsonPayload)
{
    std::string jsonBody = jsonPayload.dump();
    auto post_response = client.Post("/update_incident_report", jsonBody, "application/json");
    return 1;
}

int APIClient::update_evaluation(const json &jsonPayload)
{
    std::string jsonBody = jsonPayload.dump();
    auto post_response = client.Post("/update_evaluation", jsonBody, "application/json");
    return 1;
}

int APIClient::update_transport_information(const json &jsonPayload)
{
    std::string jsonBody = jsonPayload.dump();
    auto post_response = client.Post("/update_transport_information", jsonBody, "application/json");
    return 1;
}

int APIClient::update_caregiver(const json &jsonPayload)
{
    std::string jsonBody = jsonPayload.dump();
    auto post_response = client.Post("/update_caregiver", jsonBody, "application/json");
    return 1;
}

int APIClient::update_attending_caregiver(const json &jsonPayload)
{
    std::string jsonBody = jsonPayload.dump();
    auto post_response = client.Post("/update_attending_caregiver", jsonBody, "application/json");
    return 1;
}

int APIClient::update_emergency_contact(const json &jsonPayload)
{
    std::string jsonBody = jsonPayload.dump();
    auto post_response = client.Post("/update_emergency_contact", jsonBody, "application/json");
    return 1;
}

int APIClient::update_volunteer(const json &jsonPayload)
{
    std::string jsonBody = jsonPayload.dump();
    auto post_response = client.Post("/update_volunteer", jsonBody, "application/json");
    return 1;
}

int APIClient::update_applications(const json &jsonPayload)
{
    std::string jsonBody = jsonPayload.dump();
    auto post_response = client.Post("/update_applications", jsonBody, "application/json");
    return 1;
}

int APIClient::update_outreach(const json &jsonPayload)
{
    std::string jsonBody = jsonPayload.dump();
    auto post_response = client.Post("/update_outreach", jsonBody, "application/json");
    return 1;
}

int APIClient::create_caller(const json &jsonPayload)
{
    std::string jsonBody = jsonPayload.dump();
    auto post_response = client.Post("/create_caller", jsonBody, "application/json");
    return 1;
}

int APIClient::create_tour(const json &jsonPayload)
{
    std::string jsonBody = jsonPayload.dump();
    auto post_response = client.Post("/create_tour", jsonBody, "application/json");
    return 1;
}

int APIClient::create_member(const json &jsonPayload)
{
    std::string jsonBody = jsonPayload.dump();
    auto post_response = client.Post("/create_member", jsonBody, "application/json");
    return 1;
}

int APIClient::create_membership_enrollment_form(const json &jsonPayload)
{
    std::string jsonBody = jsonPayload.dump();
    auto post_response = client.Post("/create_membership_enrollment_form", jsonBody, "application/json");
    return 1;
}

int APIClient::create_medical_history_form(const json &jsonPayload)
{
    std::string jsonBody = jsonPayload.dump();
    auto post_response = client.Post("/create_medical_history_form", jsonBody, "application/json");
    return 1;
}

int APIClient::create_incident_report(const json &jsonPayload)
{
    std::string jsonBody = jsonPayload.dump();
    auto post_response = client.Post("/create_incident_report", jsonBody, "application/json");
    return 1;
}

int APIClient::create_evaluation(const json &jsonPayload)
{
    std::string jsonBody = jsonPayload.dump();
    auto post_response = client.Post("/create_evaluation", jsonBody, "application/json");
    return 1;
}

int APIClient::create_transport_information(const json &jsonPayload)
{
    std::string jsonBody = jsonPayload.dump();
    auto post_response = client.Post("/create_transport_information", jsonBody, "application/json");
    return 1;
}

int APIClient::create_caregiver(const json &jsonPayload)
{
    std::string jsonBody = jsonPayload.dump();
    auto post_response = client.Post("/create_caregiver", jsonBody, "application/json");
    return 1;
}

int APIClient::create_attending_caregiver(const json &jsonPayload)
{
    std::string jsonBody = jsonPayload.dump();
    auto post_response = client.Post("/create_attending_caregiver", jsonBody, "application/json");
    return 1;
}

int APIClient::create_emergency_contact(const json &jsonPayload)
{
    std::string jsonBody = jsonPayload.dump();
    auto post_response = client.Post("/create_emergency_contact", jsonBody, "application/json");
    return 1;
}

int APIClient::create_volunteer(const json &jsonPayload)
{
    std::string jsonBody = jsonPayload.dump();
    auto post_response = client.Post("/create_volunteer", jsonBody, "application/json");
    return 1;
}

int APIClient::create_applications(const json &jsonPayload)
{
    std::string jsonBody = jsonPayload.dump();
    auto post_response = client.Post("/create_applications", jsonBody, "application/json");
    return 1;
}

int APIClient::create_outreach(const json &jsonPayload)
{
    std::string jsonBody = jsonPayload.dump();
    auto post_response = client.Post("/create_outreach", jsonBody, "application/json");
    return 1;
}