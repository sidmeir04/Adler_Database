#include <mysql/jdbc.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::vector<std::string> getAllEntries(const std::string &tableName)
{
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;
    std::vector<std::string> entries;
    try
    {
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("mysql://127.0.0.1:3306/?user=connector", "connector", "password");
        entries.push_back("con created");
        con->setSchema("adler_aphasia_center");
        entries.push_back("schema set");
        sql::Statement *stmt = con->createStatement();
        entries.push_back("stmt got");
        sql::ResultSet *res = stmt->executeQuery("select * from " + tableName);
        while (res->next())
        {
            entries.push_back(res->getString("name"));
        }
        delete stmt;
        delete con;
    }
    catch (sql::SQLException &e)
    {
        entries.push_back(e.what());
    }

    return entries; // Return the list of entries
}