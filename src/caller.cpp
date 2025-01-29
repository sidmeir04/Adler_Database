#include <iostream>
#include <vector>
#include <string>
#include "httplib.h"         // HTTP client library
#include "nlohmann/json.hpp" // JSON parsing library

using json = nlohmann::json;

class APIClient
{
private:
    // Static HTTP client connection
    // Should be changed to a function that creates the connection
    // Start each function with a check of the connection and call the function if not found
    static inline httplib::Client client{"localhost", 5000};

public:
    static std::vector<std::vector<std::string>> get_caller(const json &jsonPayload)
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

    static std::vector<std::vector<std::string>> get_tour(const json &jsonPayload)
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

    static std::vector<std::vector<std::string>> get_member(const json &jsonPayload)
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

    static std::vector<std::vector<std::string>> get_membership_enrollment_form(const json &jsonPayload)
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

    static std::vector<std::vector<std::string>> get_medical_history_form(const json &jsonPayload)
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

    static std::vector<std::vector<std::string>> get_incident_report(const json &jsonPayload)
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

    static std::vector<std::vector<std::string>> get_evaluation(const json &jsonPayload)
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

    static std::vector<std::vector<std::string>> get_transport_information(const json &jsonPayload)
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

    static std::vector<std::vector<std::string>> get_caregiver(const json &jsonPayload)
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

    static std::vector<std::vector<std::string>> get_attending_caregiver(const json &jsonPayload)
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

    static std::vector<std::vector<std::string>> get_emergency_contact(const json &jsonPayload)
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

    static std::vector<std::vector<std::string>> get_volunteer(const json &jsonPayload)
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

    static std::vector<std::vector<std::string>> get_applications(const json &jsonPayload)
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

    static std::vector<std::vector<std::string>> get_outreach(const json &jsonPayload)
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

    static int update_caller(const json &jsonPayload)
    {
        std::string jsonBody = jsonPayload.dump();
        auto post_response = client.Post("/update_caller", jsonBody, "application/json");
        return 1;
    }

    static int update_tour(const json &jsonPayload)
    {
        std::string jsonBody = jsonPayload.dump();
        auto post_response = client.Post("/update_tour", jsonBody, "application/json");
        return 1;
    }

    static int update_member(const json &jsonPayload)
    {
        std::string jsonBody = jsonPayload.dump();
        auto post_response = client.Post("/update_member", jsonBody, "application/json");
        return 1;
    }

    static int update_membership_enrollment_form(const json &jsonPayload)
    {
        std::string jsonBody = jsonPayload.dump();
        auto post_response = client.Post("/update_membership_enrollment_form", jsonBody, "application/json");
        return 1;
    }

    static int update_medical_history_form(const json &jsonPayload)
    {
        std::string jsonBody = jsonPayload.dump();
        auto post_response = client.Post("/update_medical_history_form", jsonBody, "application/json");
        return 1;
    }

    static int update_incident_report(const json &jsonPayload)
    {
        std::string jsonBody = jsonPayload.dump();
        auto post_response = client.Post("/update_incident_report", jsonBody, "application/json");
        return 1;
    }

    static int update_evaluation(const json &jsonPayload)
    {
        std::string jsonBody = jsonPayload.dump();
        auto post_response = client.Post("/update_evaluation", jsonBody, "application/json");
        return 1;
    }

    static int update_transport_information(const json &jsonPayload)
    {
        std::string jsonBody = jsonPayload.dump();
        auto post_response = client.Post("/update_transport_information", jsonBody, "application/json");
        return 1;
    }

    static int update_caregiver(const json &jsonPayload)
    {
        std::string jsonBody = jsonPayload.dump();
        auto post_response = client.Post("/update_caregiver", jsonBody, "application/json");
        return 1;
    }

    static int update_attending_caregiver(const json &jsonPayload)
    {
        std::string jsonBody = jsonPayload.dump();
        auto post_response = client.Post("/update_attending_caregiver", jsonBody, "application/json");
        return 1;
    }

    static int update_emergency_contact(const json &jsonPayload)
    {
        std::string jsonBody = jsonPayload.dump();
        auto post_response = client.Post("/update_emergency_contact", jsonBody, "application/json");
        return 1;
    }

    static int update_volunteer(const json &jsonPayload)
    {
        std::string jsonBody = jsonPayload.dump();
        auto post_response = client.Post("/update_volunteer", jsonBody, "application/json");
        return 1;
    }

    static int update_applications(const json &jsonPayload)
    {
        std::string jsonBody = jsonPayload.dump();
        auto post_response = client.Post("/update_applications", jsonBody, "application/json");
        return 1;
    }

    static int update_outreach(const json &jsonPayload)
    {
        std::string jsonBody = jsonPayload.dump();
        auto post_response = client.Post("/update_outreach", jsonBody, "application/json");
        return 1;
    }

    static int create_caller(const json &jsonPayload)
    {
        std::string jsonBody = jsonPayload.dump();
        auto post_response = client.Post("/create_caller", jsonBody, "application/json");
        return 1;
    }

    static int create_tour(const json &jsonPayload)
    {
        std::string jsonBody = jsonPayload.dump();
        auto post_response = client.Post("/create_tour", jsonBody, "application/json");
        return 1;
    }

    static int create_member(const json &jsonPayload)
    {
        std::string jsonBody = jsonPayload.dump();
        auto post_response = client.Post("/create_member", jsonBody, "application/json");
        return 1;
    }

    static int create_membership_enrollment_form(const json &jsonPayload)
    {
        std::string jsonBody = jsonPayload.dump();
        auto post_response = client.Post("/create_membership_enrollment_form", jsonBody, "application/json");
        return 1;
    }

    static int create_medical_history_form(const json &jsonPayload)
    {
        std::string jsonBody = jsonPayload.dump();
        auto post_response = client.Post("/create_medical_history_form", jsonBody, "application/json");
        return 1;
    }

    static int create_incident_report(const json &jsonPayload)
    {
        std::string jsonBody = jsonPayload.dump();
        auto post_response = client.Post("/create_incident_report", jsonBody, "application/json");
        return 1;
    }

    static int create_evaluation(const json &jsonPayload)
    {
        std::string jsonBody = jsonPayload.dump();
        auto post_response = client.Post("/create_evaluation", jsonBody, "application/json");
        return 1;
    }

    static int create_transport_information(const json &jsonPayload)
    {
        std::string jsonBody = jsonPayload.dump();
        auto post_response = client.Post("/create_transport_information", jsonBody, "application/json");
        return 1;
    }

    static int create_caregiver(const json &jsonPayload)
    {
        std::string jsonBody = jsonPayload.dump();
        auto post_response = client.Post("/create_caregiver", jsonBody, "application/json");
        return 1;
    }

    static int create_attending_caregiver(const json &jsonPayload)
    {
        std::string jsonBody = jsonPayload.dump();
        auto post_response = client.Post("/create_attending_caregiver", jsonBody, "application/json");
        return 1;
    }

    static int create_emergency_contact(const json &jsonPayload)
    {
        std::string jsonBody = jsonPayload.dump();
        auto post_response = client.Post("/create_emergency_contact", jsonBody, "application/json");
        return 1;
    }

    static int create_volunteer(const json &jsonPayload)
    {
        std::string jsonBody = jsonPayload.dump();
        auto post_response = client.Post("/create_volunteer", jsonBody, "application/json");
        return 1;
    }

    static int create_applications(const json &jsonPayload)
    {
        std::string jsonBody = jsonPayload.dump();
        auto post_response = client.Post("/create_applications", jsonBody, "application/json");
        return 1;
    }

    static int create_outreach(const json &jsonPayload)
    {
        std::string jsonBody = jsonPayload.dump();
        auto post_response = client.Post("/create_outreach", jsonBody, "application/json");
        return 1;
    }
};