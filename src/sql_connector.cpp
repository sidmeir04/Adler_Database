#include <mysql/jdbc.h>
#include <iostream>
#include <vector>
#include <string>

// Function to get all entries from the specified table
std::vector<std::string> getAllEntries(const std::string &tableName)
{
    std::string dbUrl = "tcp://localhost:3306"; // Change to your database URL
    std::string user = "connector";             // Replace with your MySQL username
    std::string password = "password";          // Replace with your MySQL password
    std::vector<std::string> entries;           // To store the result entries
    try
    {
        // Get the driver instance
        sql::mysql::MySQL_Driver *driver = sql::mysql::get_driver_instance();

        // Create a connection
        std::unique_ptr<sql::Connection> con(driver->connect(dbUrl, user, password));

        // Create a statement to execute the query
        std::unique_ptr<sql::Statement> stmt(con->createStatement());

        // Execute a query to get all entries from the specified table
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT temp_text FROM " + tableName));

        // Process the result set
        while (res->next())
        {
            entries.push_back(res->getString("temp_text"));
        }
    }
    catch (sql::SQLException &e)
    {
        entries.push_back(e.what());
    }

    return entries; // Return the list of entries
}