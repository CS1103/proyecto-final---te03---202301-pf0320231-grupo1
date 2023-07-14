// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <wx/bitmap.h>
#include <wx/statbmp.h>
#include <wx/filedlg.h>
#include <wx/stdpaths.h>
#include <wx/image.h>
#include <wx/filename.h>
#include <Python.h>
#endif

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size);

private:
    wxStaticBitmap *m_bitmap1;
    void OpenImage(wxCommandEvent &event);
    void OnExit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);
    wxDECLARE_EVENT_TABLE();
};
enum
{
    ID_OPEN_FILE = 1
};
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(ID_OPEN_FILE, MyFrame::OpenImage)
        EVT_MENU(wxID_EXIT, MyFrame::OnExit)
            EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
                wxEND_EVENT_TABLE()
                    wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{

    wxInitAllImageHandlers();
    MyFrame *frame = new MyFrame("AI - IMAGE RECOGNITION", wxPoint(50, 50), wxSize(640, 640));
    frame->Show(true);
    return true;
}

MyFrame::MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_OPEN_FILE, "&Load image...\tCtrl-O",
                     "Loads image for recognition");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    SetMenuBar(menuBar);
    CreateStatusBar();
    SetStatusText("READY.");

    wxString executablePath = wxStandardPaths::Get().GetExecutablePath();
    wxString basePath = wxFileName(executablePath).GetPath();
    wxString imagePath = basePath + wxT("/default.png");

    wxBitmap bitmap(imagePath, wxBITMAP_TYPE_ANY);
    m_bitmap1 = new wxStaticBitmap(this, wxID_ANY, bitmap, wxPoint(0, 0), wxSize(100, 100));
}
void MyFrame::OnExit(wxCommandEvent &event)
{
    Close(true);
}
void MyFrame::OnAbout(wxCommandEvent &event)
{
    wxMessageBox("This is a wxWidgets' Hello world sample",
                 "About Hello World", wxOK | wxICON_WARNING);
}
void MyFrame::OpenImage(wxCommandEvent &event)
{
    wxFileDialog openFileDialog(this, "Open Image", "", "",
                                "Image files (*.bmp;*.png;*.jpg)|*.bmp;*.png;*.jpg",
                                wxFD_OPEN | wxFD_FILE_MUST_EXIST);
    if (openFileDialog.ShowModal() == wxID_CANCEL)
        return;

    wxString filePath = openFileDialog.GetPath();
    wxImage bitmap(filePath, wxBITMAP_TYPE_ANY);
    wxImage imagesScaled = bitmap.Rescale(256, 256, wxIMAGE_QUALITY_HIGH);

    struct Pixel {
        unsigned int r, g, b;
    };

    Pixel **pixelMatrix = new Pixel *[256];
    for (int i = 0; i < 256; i++) {
        pixelMatrix[i] = new Pixel[256];
        for (int j = 0; j < 256; j++) {
            pixelMatrix[i][j].r = imagesScaled.GetRed(i, j);
            pixelMatrix[i][j].g = imagesScaled.GetGreen(i, j);
            pixelMatrix[i][j].b = imagesScaled.GetBlue(i, j);
        }
    }

    // put the matrix in a string (for python)
    std::string scriptString =  "import numpy as np\n"
                                "import tensorflow as tf\n"
                                "from tensorflow.keras.models import load_model\n"
                                "matrix = [";
    for (int i = 0; i < 256; i++) {
        scriptString += "[";
        for (int j = 0; j < 256; j++)
        {
            scriptString += "[";
            scriptString += std::to_string(float(pixelMatrix[i][j].r)/255.0);
            scriptString += ",";
            scriptString += std::to_string(float(pixelMatrix[i][j].g)/255.0);
            scriptString += ",";
            scriptString += std::to_string(float(pixelMatrix[i][j].b)/255.0);
            scriptString += "]";
            if (j != 255)
                scriptString += ",";
        }
        scriptString += "]";
        if (i != 255)
            scriptString += ",";
    }
    scriptString += "]\n"
                    "matrix = np.expand_dims(matrix, axis=0)\n"
                    "model = load_model('model2.h5')\n"
                    "yhat = model.predict(matrix)*255\n"
                    "print('Predicted: ', yhat)\n"
                    "if yhat > 0.5:\n"
                    "    print('Vehículo')\n"
                    "else:\n"
                    "    print('No vehículo')\n";
    std::cout << scriptString << std::endl;

    // python script
    // import numpy as np
    // from tensorflow.keras.models import load_model
    // matrix = // read from cpp string
    // model = load_model('model.h5')
    // model.predict(np.expand_dims(matrix/255, 0))
    Py_Initialize();
    PyRun_SimpleString(scriptString.c_str());
    Py_Finalize();



    wxBitmap dataScaled(imagesScaled);
    m_bitmap1->SetBitmap(dataScaled);

    int controlWidth, controlHeight;
    m_bitmap1->GetSize(&controlWidth, &controlHeight);

    int imageWidth = imagesScaled.GetWidth();
    int imageHeight = imagesScaled.GetHeight();

    int xOffset = (controlWidth - imageWidth) / 2;
    int yOffset = (controlHeight - imageHeight) / 2;

    m_bitmap1->SetPosition(wxPoint(xOffset, yOffset));
}
