#include <wx/wx.h>
#include <wx/xml/xml.h>
#include <wx/listctrl.h>
#include "logger.h"

void resizeObject(wxWindow *object, double percentage)
{
    LogToFile("resizing object");
    try
    {
        // Ensure percentage is within a valid range (0.0 to 1.0)
        if (percentage < 0.0 || percentage > 1.0)
        {
            LogToFile("Error: Percentage must be between 0.0 and 1.0");
            return;
        }

        // Get the screen size
        wxSize screenSize = wxGetDisplaySize();

        // Calculate the new size based on the percentage
        int newWidth = static_cast<int>(screenSize.GetWidth() * percentage);
        int newHeight = static_cast<int>(screenSize.GetHeight() * percentage);

        // Set the size of the object
        object->SetSize(newWidth, newHeight);

        // Optionally center the object on the screen
        object->Centre();
    }
    catch (const std::exception &e)
    {
        LogToFile(std::string("Exception in resizeObject: ") + e.what());
    }
}

class MyFrame : public wxFrame
{
public:
    MyFrame() : wxFrame(nullptr, wxID_ANY, "XML Table Viewer", wxDefaultPosition, wxSize(600, 400))
    {
        LogToFile("Starting MyFrame");
        try
        {
            wxPanel *panel = new wxPanel(this, wxID_ANY);

            // Create a wxTextCtrl for the search bar (centered in the middle of the screen)
            wxTextCtrl *searchBar = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(400, 30));
            searchBar->Bind(wxEVT_TEXT, &MyFrame::OnSearch, this); // Bind the search event

            // Create a wxListCtrl to show filtered results in three columns (Title, Author, Year)
            resultList = new wxListCtrl(panel, wxID_ANY, wxDefaultPosition, wxSize(580, 200),
                                        wxLC_REPORT | wxLC_SINGLE_SEL);

            // Add columns to the wxListCtrl
            resultList->InsertColumn(0, "Title", wxLIST_FORMAT_LEFT, 200);
            resultList->InsertColumn(1, "Author", wxLIST_FORMAT_LEFT, 200);
            resultList->InsertColumn(2, "Year", wxLIST_FORMAT_LEFT, 100);

            // Load XML file and populate the list of results
            wxXmlDocument xmlDoc;
            if (xmlDoc.Load("example.xml"))
            {
                wxXmlNode *rootNode = xmlDoc.GetRoot();
                PopulateResultsList(rootNode);
            }
            else
            {
                LogToFile("Error: Could not load the XML file.");
            }

            // Layout
            wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
            sizer->Add(searchBar, 0, wxALIGN_CENTER | wxALL, 10); // Add search bar, centered
            sizer->Add(resultList, 1, wxEXPAND | wxALL, 10);      // Add the list box for results
            panel->SetSizer(sizer);
        }
        catch (const std::exception &e)
        {
            LogToFile(std::string("Exception in MyFrame constructor: ") + e.what());
        }
    }

private:
    wxListCtrl *resultList;

    // Method to handle search event
    void OnSearch(wxCommandEvent &event)
    {
        wxString searchTerm = event.GetString().Lower();
        FilterResults(searchTerm);
    }

    // Method to filter the results based on the search term
    void FilterResults(const wxString &searchTerm)
    {
        resultList->DeleteAllItems(); // Clear current results

        // Loop through the list and filter based on the search term
        wxXmlDocument xmlDoc;
        if (xmlDoc.Load("example.xml"))
        {
            wxXmlNode *rootNode = xmlDoc.GetRoot();
            wxXmlNode *bookNode = rootNode->GetChildren();

            while (bookNode)
            {
                if (bookNode->GetName() == "Book")
                {
                    wxString title = GetChildNodeValue(bookNode, "Title");
                    wxString author = GetChildNodeValue(bookNode, "Author");
                    wxString year = GetChildNodeValue(bookNode, "Year");

                    // Construct a display string and add it to the list if it matches the search term
                    wxString displayString = title + " - " + author + " (" + year + ")";
                    if (title.Lower().Contains(searchTerm) ||
                        author.Lower().Contains(searchTerm) ||
                        year.Lower().Contains(searchTerm))
                    {
                        // Add matching result to the list
                        long index = resultList->InsertItem(resultList->GetItemCount(), title);
                        resultList->SetItem(index, 1, author);
                        resultList->SetItem(index, 2, year);
                    }
                }
                bookNode = bookNode->GetNext(); // Move to the next book node
            }
        }
        else
        {
            LogToFile("Error: Could not load the XML file.");
        }
    }

    // Helper function to get the value of a child node
    wxString GetChildNodeValue(wxXmlNode *parent, const wxString &childName)
    {
        try
        {
            wxXmlNode *child = parent->GetChildren();
            while (child)
            {
                if (child->GetName() == childName)
                {
                    return child->GetNodeContent();
                }
                child = child->GetNext();
            }
            return "Unknown"; // Default if the child node isn't found
        }
        catch (const std::exception &e)
        {
            LogToFile(std::string("Exception in GetChildNodeValue: ") + e.what());
            return "Unknown";
        }
    }

    // Populate the list with books from the XML
    void PopulateResultsList(wxXmlNode *rootNode)
    {
        wxXmlNode *bookNode = rootNode->GetChildren();
        while (bookNode)
        {
            if (bookNode->GetName() == "Book")
            {
                wxString title = GetChildNodeValue(bookNode, "Title");
                wxString author = GetChildNodeValue(bookNode, "Author");
                wxString year = GetChildNodeValue(bookNode, "Year");

                // Add book to the list
                long index = resultList->InsertItem(resultList->GetItemCount(), title);
                resultList->SetItem(index, 1, author);
                resultList->SetItem(index, 2, year);
            }
            bookNode = bookNode->GetNext(); // Move to the next book node
        }
    }
};

class MyApp : public wxApp
{
public:
    virtual bool OnInit()
    {
        try
        {
            MyFrame *frame = new MyFrame();
            frame->Show(true);
            return true;
        }
        catch (const std::exception &e)
        {
            LogToFile(std::string("Exception in MyApp::OnInit: ") + e.what());
            return false;
        }
    }
};

wxIMPLEMENT_APP(MyApp);
