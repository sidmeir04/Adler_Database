#include <pybind11/pybind11.h>
#include <pybind11/embed.h>

#include <wx/wx.h>
#include <wx/xml/xml.h>
#include <string>
#include <vector>

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

std::tuple<std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string> call_get_caller(
    const std::string &staff_name = "",
    const std::string &caller_name = "",
    const std::string &caller_email = "",
    const std::string &call_date = "",
    const std::string &phone = "",
    const std::string &referral_type = "",
    const bool tour_scheduled = false,
    const std::string &follow_up_date = "")
{
    py::object get_functions = py::module_::import("get_functions").attr("get_functions");
    py::object result = get_functions.attr("get_caller")(
        staff_name,
        caller_name,
        caller_email,
        call_date.empty() ? py::none() : py::str(call_date),
        phone,
        referral_type,
        tour_scheduled ? py::bool_(true) : py::none(),
        follow_up_date.empty() ? py::none() : py::str(follow_up_date));

    return result.cast<std::tuple<std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string>>();
}

void MainFrame::OnButtonClicked(wxCommandEvent &evt)
{
    // Call Python function getAllEntries()
    std::vector<std::string> entries = call_get_caller();

    results.Clear(); // Clear previous results
    for (const auto &entry : entries)
    {
        results.Append(entry + "\n"); // Append each entry followed by a newline
    }

    // Log the results (you can also use this in other parts of your application)
    wxLogStatus(this, results);
}

wxIMPLEMENT_APP(App);
