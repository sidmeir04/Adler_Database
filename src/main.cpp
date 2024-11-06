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

std::vector<std::string> CallPythonGetAllEntries(const std::string &arg)
{
    std::vector<std::string> resultEntries;

    return resultEntries;
}

void MainFrame::OnButtonClicked(wxCommandEvent &evt)
{
    // Call Python function getAllEntries()
    std::vector<std::string> entries = CallPythonGetAllEntries("Testing");

    results.Clear(); // Clear previous results
    for (const auto &entry : entries)
    {
        results.Append(entry + "\n"); // Append each entry followed by a newline
    }

    // Log the results (you can also use this in other parts of your application)
    wxLogStatus(this, results);
}

wxIMPLEMENT_APP(App);
