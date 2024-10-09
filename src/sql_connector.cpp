#include <mysql/jdbc.h>
#include <iostream>
#include <vector>
#include <string>

// Function to get all entries from the specified table
std::vector<std::string> getAllEntries(const std::string &tableName)
{
    std::string dbUrl = "tcp://127.0.0.1:3306"; // Change to your database URL
    std::string user = "Admin";                 // Replace with your MySQL username
    std::string password = "Aphasia_12";        // Replace with your MySQL password
    std::vector<std::string> entries;           // To store the result entries

    try
    {
        // Get the driver instance
        sql::mysql::MySQL_Driver *driver = sql::mysql::get_driver_instance();

        // Create a connection
        std::unique_ptr<sql::Connection> con(driver->connect("tcp://127.0.0.1:3306", user, password));

        // Create a statement to execute the query
        std::unique_ptr<sql::Statement> stmt(con->createStatement());

        // Execute a query to get all entries from the specified table
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT temp_text FROM " + tableName));

        // Process the result set
        while (res->next())
        {
            // Assuming you want to fetch the first column's string value; adjust as needed
            entries.push_back(res->getString("temp_text"));
        }
    }
    catch (sql::SQLException &e)
    {
        entries.push_back(e.what());
    }

    return entries; // Return the list of entries
}

// int main()
// {
//     // Example parameters
//     std::string dbUrl = "tcp://127.0.0.1:3306"; // Change to your database URL
//     std::string user = "username";              // Replace with your MySQL username
//     std::string password = "password";          // Replace with your MySQL password
//     std::string tableName = "your_table_name";  // Replace with your table name

//     // Call the function and get all entries from the specified table
//     std::vector<std::string> entries = getAllEntries(dbUrl, user, password, tableName);

//     // Print the entries
//     for (const auto &entry : entries)
//     {
//         std::cout << entry << std::endl; // Adjust as needed to display entries
//     }

//     return 0;
// }
