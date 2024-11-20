#include <pybind11/pybind11.h>
#include <pybind11/embed.h>
#include <pybind11/stl.h>
#include <wx/wx.h>
#include <wx/log.h>
#include <wx/xml/xml.h>
#include <string>
#include <tuple>
#include <vector>
#include <fstream>
#include <filesystem>

namespace py = pybind11;
namespace fs = std::filesystem;

// Function to log messages to a file
void LogToFile(const std::string &message)
{
    std::ofstream log_file("logs.txt", std::ios_base::app); // Open file in append mode
    if (log_file.is_open())
    {
        log_file << message << std::endl; // Write message to the log file
        log_file.close();                 // Close the file after writing
    }
    else
    {
        std::cerr << "Failed to open log file!" << std::endl;
    }
}

// Function to call Python's get_caller method and return a vector of tuples
std::vector<std::tuple<std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string>> call_get_caller(
    const std::string &staff_name = "",
    const std::string &caller_name = "",
    const std::string &caller_email = "",
    const std::string &call_date = "",
    const std::string &phone = "",
    const std::string &referral_type = "",
    const bool tour_scheduled = true,
    const std::string &follow_up_date = "")
{
    try
    {
        // Log the parameters being passed to the Python function
        std::string parameters = "staff_name: " + staff_name + ", caller_name: " + caller_name + ", caller_email: " + caller_email + ", call_date: " + call_date + ", phone: " + phone + ", referral_type: " + referral_type + ", tour_scheduled: " + (tour_scheduled ? "True" : "False") + ", follow_up_date: " + follow_up_date;
        LogToFile("Calling Python function with parameters: " + parameters);

        // Add the directory containing your Python module to sys.path
        py::module sys = py::module_::import("sys");
        LogToFile("sys imported");
        std::string module_dir = "C:/Adler_Database/src"; // Path to the folder containing sql_connector.py
        sys.attr("path").attr("append")(module_dir);

        // Try to import the Python module
        py::object get_functions = py::module_::import("sql_connector").attr("get_functions");

        // Call the Python function, which will return a list of tuples
        py::object result = get_functions.attr("get_caller")(
            staff_name,
            caller_name,
            caller_email,
            call_date.empty() ? py::none() : py::str(call_date),
            phone,
            referral_type,
            tour_scheduled ? py::bool_(true) : py::none(),
            follow_up_date.empty() ? py::none() : py::str(follow_up_date));

        // Convert the returned Python list of tuples to a C++ vector of tuples
        std::vector<std::tuple<std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string>> result_list;
        for (const auto &item : result)
        {
            result_list.push_back(item.cast<std::tuple<std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string>>());
        }

        return result_list;
    }
    catch (const pybind11::error_already_set &e)
    {
        // Catch and log Python-related errors
        std::string error_message = "Python exception in call_get_caller: " + std::string(e.what());
        LogToFile(error_message); // Log Python error to file
        wxLogError(wxString::FromUTF8(error_message.c_str()));
        return {}; // Return an empty vector on error
    }
    catch (const std::exception &e)
    {
        // Catch general C++ exceptions and log them
        std::string error_message = "C++ exception in call_get_caller: " + std::string(e.what());
        LogToFile(error_message); // Log C++ error to file
        wxLogError(wxString::FromUTF8(error_message.c_str()));
        return {}; // Return an empty vector on error
    }
    catch (...)
    {
        // Catch any other unexpected errors
        std::string error_message = "Unexpected exception in call_get_caller.";
        LogToFile(error_message); // Log unexpected error to file
        wxLogError(wxString::FromUTF8(error_message.c_str()));
        return {}; // Return an empty vector on error
    }
}

class App : public wxApp
{
public:
    bool OnInit();
};

class MainFrame : public wxFrame
{
public:
    MainFrame(const wxString &title);

private:
    void OnButtonClicked(wxCommandEvent &evt);
    wxDECLARE_EVENT_TABLE();
    wxString results; // Store results here
};

bool App::OnInit()
{
    MainFrame *mainFrame = new MainFrame("C++ GUI");
    mainFrame->Show();
    return true;
}

// For event handling
enum IDs
{
    BUTTON_ID = 2,
    SLIDER_ID = 3,
    TEXT_ID = 4
};

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_BUTTON(BUTTON_ID, MainFrame::OnButtonClicked)
        wxEND_EVENT_TABLE()

            MainFrame::MainFrame(const wxString &title) : wxFrame(nullptr, wxID_ANY, title)
{
    std::cout << "Program running" << std::endl;
    wxPanel *panel = new wxPanel(this);

    // Button Example
    wxButton *button = new wxButton(panel, BUTTON_ID, "Button", wxPoint(0, 0), wxSize(200, 50));

    CreateStatusBar();
}

void MainFrame::OnButtonClicked(wxCommandEvent &evt)
{
    // Call Python function getAllEntries()
    LogToFile("Calling function");
    std::vector<std::tuple<std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string>> entries = call_get_caller();
    LogToFile("Called function");

    results.Clear(); // Clear previous results

    for (const auto &entry : entries)
    {
        results.Append("Entry: ");

        // Use a loop to get each element of the tuple and append to results
        // Tuple element access with lambda
        std::apply([&](const auto &...args)
                   { (results.Append(wxString::FromUTF8(args.c_str()) + " "), ...); }, entry);

        results.Append("\n");
    }

    // Log the results (you can also use this in other parts of your application)
    wxLogStatus(this, results);
}

wxIMPLEMENT_APP(App);
