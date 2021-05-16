///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUI_H__
#define __GUI_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/button.h>

#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/panel.h>
#include <wx/frame.h>
#include <wx/gauge.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/textctrl.h>
#include <wx/grid.h>
#include <wx/sizer.h>
#include <map>
#include <wx/scrolbar.h>


///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame
{
private:

protected:
	wxPanel* m_panel1;
	wxPanel* m_panelFullDisplay;
	wxScrollBar* m_scrollBar1;
	wxGrid* IPTC;
	wxGrid* EXIF;
	wxButton* reset;
	wxButton* A;
	wxButton* B;
	wxButton* D;
	

	// Virtual event handlers, overide them in your derived class
	virtual void window_update(wxUpdateUIEvent& event) { event.Skip(); }
	virtual void scrollbar_scroll(wxScrollEvent& event) { event.Skip(); }
	virtual void LoadImgOnClick(wxCommandEvent& event) { event.Skip(); }


public:

	MyFrame1(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(643, 478), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

	~MyFrame1();

};
#endif 
