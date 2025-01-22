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
    static inline httplib::Client client{"localhost", 8080};

public:
    // Static function to fetch a list of lists of strings
    static std::vector<std::vector<std::string>> fetchData(const std::string &endpoint)
    {
        std::vector<std::vector<std::string>> results;

        // Perform a GET request
        auto get_response = client.Get(endpoint.c_str());
        if (get_response && get_response->status == 200)
        {
            // Parse the JSON response
            json response_json = json::parse(get_response->body);

            // Extract data into a list of lists of strings
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
    // Call the static method from the APIClient class
    std::vector<std::vector<std::string>> data = APIClient::fetchData("/api/v1/get-data");

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
