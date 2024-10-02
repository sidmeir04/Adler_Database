#include <jdbc/mysql_driver.h>
#include <jdbc/mysql_connection.h>
#include <jdbc/cppconn/statement.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/exception.h>
#include <iostream>
#include "sql_connector.h"

int runQuery(void)
{
    try
    {
        int num = 0;
        // // Create a MySQL driver
        // sql::mysql::MySQL_Driver *driver = sql::mysql::get_mysql_driver_instance();

        // // Establish a connection to the database
        // std::unique_ptr<sql::Connection> con(driver->connect("tcp://127.0.0.1:3306", "root", "Aphasia_12"));

        // // Connect to the specific database
        // con->setSchema("adler_aphasia_center");

        // // Create a statement
        // std::unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement(query));

        // // Execute the query
        // std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

        // // Process the results
        // while (res->next())
        // {
        //     std::cout << "Column 1: " << res->getString(1) << std::endl; // Change the column index as needed
        // }
    }
    catch (sql::SQLException &e)
    {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}