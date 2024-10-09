#include <wx/wx.h>
#include <wx/xml/xml.h>
#include <string>
#include "sql_connector.h"

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
};

bool App::OnInit()
{
    MainFrame *mainFrame = new MainFrame("C++ GUI");
    mainFrame->Show();
    return true;
};

// for event handling
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
    // -----------------------------------------   Button Example ---------------------------------------- //
    std::string buttonText = "example button";
    wxButton *button1 = new wxButton(panel, wxID_ANY, buttonText, wxPoint(150, 50), wxSize(100, 35));
    //                                                           Strat Pos        Size
    // -----------------------------------------   Button Example End ----------------------------------=- //

    // -----------------------------------------   CheckBox Example ---------------------------------------- //
    wxCheckBox *checkBox = new wxCheckBox(panel, wxID_ANY, "CheckBox", wxPoint(550, 50));
    //                                                                   Strat Pos        Size - If no size then default size is used
    // -----------------------------------------   CheckBox Example End ----------------------------------=- //

    wxStaticText *staticText = new wxStaticText(panel, wxID_ANY, "StaticText - NOT editable", wxPoint(120, 150));
    wxTextCtrl *textCtrl = new wxTextCtrl(panel, wxID_ANY, "TextCTRL - editable", wxPoint(500, 145), wxSize(200, -1));
    // Others
    // wxSlider
    // wxGauge
    // wsChoice
    // wxListBox
    // wxRadioBox

    // -----------------------------------------   Styles   ------------------------------------ //
    // Similar to bootstrap classes
    // www.wxwidgets.org/stable/class{{classname (wx_button)}}
    // to combine styles use | (or operator)

    // -----------------------------------------   Events   ------------------------------------ //
    wxButton *button = new wxButton(panel, BUTTON_ID, "Button", wxPoint(300, 275), wxSize(200, 50));

    CreateStatusBar();
};

void MainFrame::OnButtonClicked(wxCommandEvent &evt)
{
    std::vector<std::string> entries = getAllEntries("Testing");

    wxString statusMessage;
    for (const auto &entry : entries)
    {
        statusMessage.Append(entry + "\n"); // Append each entry followed by a newline
    }

    // Log the status
    wxLogStatus(this, statusMessage);
};

wxIMPLEMENT_APP(App);