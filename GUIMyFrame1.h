#ifndef __GUIMyFrame1__
#define __GUIMyFrame1__

/**
@file
Subclass of MyFrame1, which is generated by wxFormBuilder.
*/


#include "GUI.h"

#include <vector>
#include <string>
#include <wx/msgdlg.h>
#include <wx/dcmemory.h>
#include <wx/dcclient.h>
#include <wx/dcbuffer.h>
#include <wx/msgdlg.h>
#include "wx/dirdlg.h"
#include <wx/dir.h>
#include <wx/stattext.h>
#include <wx/bmpbuttn.h>
#include <wx/bitmap.h>
#include "FreeImage.h"
//// end generated include
#include "wx/custombgwin.h"
#include "wx/wx.h"
#include <iostream>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/sizer.h>



/** Implementing MyFrame1 */
class GUIMyFrame1 : public MyFrame1
{
	friend class MyButton;
	friend class Panel2;
public:
	/** Constructor */
	GUIMyFrame1(wxWindow* parent);
	wxArrayString path_array;
	size_t file_count;
	wxImage* m_imageRGB;
	wxBitmap m_imageBitmap;
	int window_width;
	int window_height;
	int m_imageWidth;
	int m_imageHeight;
	int m_imageCounter;
	int m_fullImagesWidth;
	int m_fullImagesHeight;
	static int FDwindow_width; //for FullDisplay panel
	static int FDwindow_height;
	static Panel2* currentFullDisplay;
	static MyButton* currentPic;
	bool imageLoaded;
	unsigned char* m_myImage;

	wxFlexGridSizer* fgSizer1;
	//// end generated class members
	int panel_width;
	int panel_height;
	//two vectors - not necessary in final version
	std::vector<wxBitmap> bitmap;
	std::vector<wxBitmapButton> bu;
	wxBitmapButton m_bmt;
	wxBitmap* bmpt;
	wxImage* image;
	wxImage sourceImage;
	int changedirectoryclickevent = 0;
	int changedwindowsize = 0;
	std::vector<wxBitmap> bitmapVector;
	void printBitmapButtons();
	void loadBitmaps();
	wxString getDataOnBitmap(wxString path);
	//static methods for displaying data
	static void DisplayPic(wxPanel* parent, wxString path, wxPanel* display, wxFlexGridSizer* fgSizer);
	static void DisplayMetaData(wxGrid* EXIF,wxGrid* IPTC, wxPanel* parent, wxPanel* display, wxString path);
	static void DisplayFolder(wxPanel* parent, wxPanel* display, wxString& path);
	//FreeImage
	void OnPanelClick(wxMouseEvent& event)
	{
		event.Skip();
	}
protected:

	void window_update(wxUpdateUIEvent& event);
	void LoadImgOnClick(wxCommandEvent& event);
	void WindowSizeChanged(wxSizeEvent& event);
	void scrollbar_scroll(wxScrollEvent& event);
	
	void WriteDataOnPic(wxCommandEvent& event);
	void GenerateTextOnAll(wxCommandEvent& event);
	void IPTCReset(wxCommandEvent& event);
	void WriteInIPTCData(wxCommandEvent& event);
};


class PanelBOX :public wxPanel {
public: 
	PanelBOX(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxTAB_TRAVERSAL, const wxString& name = wxPanelNameStr) {
		t = new wxStaticText(this, wxID_ANY,_("LOADING IMAGES"));
	}
private:
	wxStaticText* t;
};

class Panel2 : public wxPanel {
	friend class MyButton;
	friend class GUIMyFrame1;
	friend class MyCanvas;
public:
	Panel2() = default;
	Panel2(wxPanel* parent, wxString path, wxPanel* display, wxFlexGridSizer* fgSizer, const wxSize& pos = wxDefaultSize) :wxPanel(display, -1, wxPoint(0, 0), pos), _parent(parent), _path(path), _DisplayPanel(display), _fgSizer(fgSizer)
	{
		Connect(wxEVT_LEFT_DCLICK, wxMouseEventHandler(Panel2::OnPanelDoubleDown));
		display->Show();
		PaintFD();
	}
private:
	wxPanel* _parent;
	wxString _path;
	wxPanel* _DisplayPanel;
	wxFlexGridSizer* _fgSizer;
	wxString getPath() const { return _path; }

	void OnPanelDoubleDown(wxMouseEvent& event)
	{
		GUIMyFrame1::DisplayFolder(_parent, _DisplayPanel, _path);
	}
	void PaintFD()
	{
		wxImage im = wxImage(_path, wxBITMAP_TYPE_ANY, -1);
		int w = _DisplayPanel->GetSize().GetWidth();
		int h = _DisplayPanel->GetSize().GetHeight();
		int w_i = im.GetWidth();
		int h_i = im.GetHeight();
		double x1 = (double)h / h_i;
		double x2 = (double)w / w_i;
		if (w_i > w || h_i > h)
		{
			if (x1 < x2)
			{
				im.Rescale(floor(x1 * w_i), floor(h_i * x1), wxIMAGE_QUALITY_NEAREST);
			}
			else
			{
				im.Rescale(floor(w_i * x2), floor(h_i * x2), wxIMAGE_QUALITY_NEAREST);
			}
		}
		wxBitmap b1(im, -1);
		this->SetSize(_DisplayPanel->GetSize().GetWidth(), _DisplayPanel->GetSize().GetHeight());
		_parent->SetSize(_DisplayPanel->GetSize().GetWidth(), _DisplayPanel->GetSize().GetHeight());
		
		wxClientDC dc(this);
		dc.Clear();
		dc.DrawBitmap(b1, (w - im.GetWidth()) / 2, (h - im.GetHeight()) / 2, false);
	}
};

class MyButton : public wxBitmapButton
{
	friend class GUIMyFrame1;
	friend class Panel2;
public:
	MyButton()=default;
	MyButton(wxFlexGridSizer* fgSizer1, wxPanel* parent, wxPanel* displaypanel, wxGrid* EXIF,wxGrid* IPTC, wxWindowID id, const wxBitmap& bitmap, const wxPoint& pos = wxDefaultPosition, wxString path_array = 'a') : wxBitmapButton(parent, -1, bitmap, pos)
	{
		Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(MyButton::OnMouseLeftDown));
		Connect(wxEVT_LEFT_DCLICK, wxMouseEventHandler(MyButton::OnMouseDoubleDown));
		//Connect(wxEVT_LEFT_DCLICK, wxMouseEventHandler(MyButton::OnMouseLeftUp)); //need double-click action
		path = path_array;
		parent1 = parent;
		EXIF1 = EXIF;
		IPTC1 = IPTC;
		fgSizer = fgSizer1;
		DisplayPanel = displaypanel;
	}
private:
	wxString path;
	wxPanel* parent1;
	wxGrid* EXIF1;
	wxGrid* IPTC1;
	wxFlexGridSizer* fgSizer;
	wxPanel* DisplayPanel;
	void OnMouseLeftDown(wxMouseEvent& event)
	{
		GUIMyFrame1::DisplayMetaData(EXIF1,IPTC1, parent1, DisplayPanel, path);

	}

	void OnMouseDoubleDown(wxMouseEvent& event)
	{
		GUIMyFrame1::DisplayPic(parent1, path, DisplayPanel, fgSizer);
	}
	wxString GetPathFromClick() {
		return path;
	}
};



#endif // __GUIMyFrame1__
