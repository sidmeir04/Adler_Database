#include <wx/wx.h>
#include <wx/xml/xml.h>

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString &title);

    void LoadXML();
};

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame("wxWidgets XML Example");
    frame->Show(true);
    return true;
}

MyFrame::MyFrame(const wxString &title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(400, 300))
{
    LoadXML();
}

void MyFrame::LoadXML()
{
    wxXmlDocument xmlDoc;
    if (xmlDoc.Load("example.xml"))
    {
        wxXmlNode *root = xmlDoc.GetRoot();
        if (root)
        {
            wxLogMessage("Root node: %s", root->GetName());

            wxXmlNode *child = root->GetChildren();
            while (child)
            {
                wxLogMessage("Child node: %s", child->GetName());
                child = child->GetNext();
            }

            // Modify some XML data
            if (root->GetChildren())
            {
                root->GetChildren()->SetContent("Modified Content");
            }

            // Save the modified document
            if (xmlDoc.Save("output.xml"))
            {
                wxLogMessage("XML file saved as 'output.xml'");
            }
        }
    }
    else
    {
        wxLogError("Failed to load the XML file.");
    }
}
