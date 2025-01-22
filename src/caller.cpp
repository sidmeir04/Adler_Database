#include <iostream>
#include <vector>
#include <string>
#include "httplib.h"         // HTTP client library
#include "nlohmann/json.hpp" // JSON parsing library

using namespace std::chrono;

using json = nlohmann::json;

class APIClient
{
private:
    // Static HTTP client connection
    static inline httplib::Client client{"localhost", 5000};

public:
    // Static function to fetch a list of lists of strings with a JSON body
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
};

int main()
{
    // Create a JSON variable to hold the payload
    json jsonPayload = {{"name", "john"}};

    // Call the static method from the APIClient class

    std::vector<std::vector<std::string>> data = APIClient::get_caller(jsonPayload);

    // Print the results
    for (const auto &list : data)
    {
        for (const auto &str : list)
        {
            std::cout << str << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
