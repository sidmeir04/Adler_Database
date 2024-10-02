#include <wx/wx.h>
#include <wx/xml/xml.h>
#include "sql_connector.h"

// Define a custom wxFrame (window) class
class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString &title);

    // Function to be called when the button is clicked
    void OnButtonClicked(wxCommandEvent &event);

private:
    wxButton *m_button; // Button widget
};

// Define a custom wxApp class
class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame("wxWidgets and MySQL Example");
    frame->Show(true); // Show the window
    return true;
}

MyFrame::MyFrame(const wxString &title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(300, 200))
{
    // Create a button widget
    m_button = new wxButton(this, wxID_ANY, "Click to Query MySQL", wxPoint(100, 50), wxSize(150, 30));

    // Bind the button click event to the function
    Bind(wxEVT_BUTTON, &MyFrame::OnButtonClicked, this, m_button->GetId());
}

// The function to be called when the button is clicked
void MyFrame::OnButtonClicked(wxCommandEvent &event)
{
    int num = runQuery();
    wxLogMessage("num");

    // Call the MySQL query function
}