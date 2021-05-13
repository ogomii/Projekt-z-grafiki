#include <wx/wx.h>
#include "GUIMyFrame1.h"


class MyApp : public wxApp {
    wxFrame* frame;
public:

	virtual bool OnInit();
	virtual int OnExit() { return 0; }

};

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	//support all available image formats
	wxInitAllImageHandlers();

	GUIMyFrame1* mainFrame = new GUIMyFrame1(NULL);
	mainFrame->Show(true);
	SetTopWindow(mainFrame);
	return true;

}