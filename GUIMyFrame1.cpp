#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1(wxWindow* parent)
	:
	MyFrame1(parent)
{
	m_myImage = NULL;
	file_count = 0;
}

Panel2* GUIMyFrame1::currentFullDisplay = new Panel2();
int GUIMyFrame1::FDwindow_width = 700;
int GUIMyFrame1::FDwindow_height = 1200;

void GUIMyFrame1::WindowSizeChanged(wxSizeEvent& event)
{
	window_width = event.GetSize().GetWidth();
	window_height = event.GetSize().GetHeight();
	//changedwindowsize = 1;
	//repaint();
}

void GUIMyFrame1::window_update(wxUpdateUIEvent& event)
{
	//changedwindowsize = 0;
	//repaint();
	if (m_panel1->IsShown())
	{
		if (window_width != m_panel1->GetSize().GetWidth() || window_height != m_panel1->GetSize().GetHeight())
		{
			window_width = m_panel1->GetSize().GetWidth();
			window_height = m_panel1->GetSize().GetHeight();
			printBitmapButtons();
		}
	}
	else if (m_panelFullDisplay->IsShown())
	{
		if (FDwindow_width != m_panelFullDisplay->GetSize().GetWidth() || FDwindow_height != m_panelFullDisplay->GetSize().GetHeight())
		{
			FDwindow_width = m_panelFullDisplay->GetSize().GetWidth();
			FDwindow_height = m_panelFullDisplay->GetSize().GetHeight();
			currentFullDisplay->PaintFD();
		}
	}
	
}


void GUIMyFrame1::LoadImgOnClick(wxCommandEvent& event)
{

	if (path_array.GetCount() != 0)
	{
		path_array.Clear();
		imageLoaded = false;
		changedirectoryclickevent = 0;
	}
	wxString defaultPath = wxT("/");
	wxDirDialog dialog(this, wxT("Choose directory"), defaultPath, wxDD_NEW_DIR_BUTTON);
	if (dialog.ShowModal() == wxID_OK) {
		wxString path = dialog.GetPath();
		wxDir dir(dialog.GetPath());

		dir.GetAllFiles(dialog.GetPath(), &path_array, wxEmptyString, wxDIR_FILES);
		file_count = path_array.GetCount();
		imageLoaded = true;



		//wxMessageBox(_("LOADING FIELS>>>"));
		loadBitmaps();
		changedirectoryclickevent = 1;
	}
	else {
		wxMessageBox(_("Cannot open a directory"));
	}

}


void GUIMyFrame1::loadBitmaps()
{
	if (file_count > 0)
	{
		bitmapVector.clear();
		for (int i = 0; i < file_count; i++) //load images to vector
		{
			wxImage imag = wxImage(path_array[i], wxBITMAP_TYPE_ANY, -1);
			imag.Rescale(240, 180, wxIMAGE_QUALITY_NEAREST);

			wxBitmap bmpt1(imag, -1);
			bitmapVector.push_back(bmpt1);

		}
		printBitmapButtons();
	}
}


void GUIMyFrame1::printBitmapButtons() {
	if (file_count > 0)
	{
		int rows = 1;
		int cols = (window_width - 40) / 240 ;
		if(cols != 0 ) rows = file_count / cols + 1;
		if(fgSizer1) fgSizer1->Clear(true);
		fgSizer1 = new wxFlexGridSizer(rows, cols, 0, 0);

		for (int i = 0; i < file_count; i++) //load images to vector
		{
			wxString path_a = path_array[i];
			wxBitmapButton* m_bmt1 = new MyButton(fgSizer1, m_panel1, m_panelFullDisplay, EXIF, -1, bitmapVector[i], path_a);
			fgSizer1->Add(m_bmt1);
		}
		m_panel1->SetSizer(fgSizer1);
		m_panel1->FitInside();
		m_panel1->SetScrollRate(25, 25);
	}
}


void GUIMyFrame1::DisplayPic(wxPanel* parent, wxString path, wxPanel* display, wxFlexGridSizer* fgSizer)
{
	wxClientDC dc(display);
	parent->Hide();
	int w = parent->GetSize().GetWidth();			//DO NOT DELETE!
	int h = parent->GetSize().GetHeight();
	display->SetSize(w, h);
	//display->Show();
	currentFullDisplay = new Panel2(parent, path, display, fgSizer, wxSize(w, h));
}


void GUIMyFrame1::DisplayMetaData(wxGrid* EXIF, wxPanel* parent, wxPanel* display, wxString path)
{
	wxClientDC dc(parent);
	FIBITMAP* bmp;
	FIBITMAP* bitmap_free;
	bmp = FreeImage_Load(FIF_JPEG, path, JPEG_DEFAULT);
	int bip = FreeImage_GetBPP(bmp);
	bitmap_free = FreeImage_Allocate(240, 180, bip);
	bitmap_free = bmp;
	FITAG* tag = NULL;
	FIMETADATA* mdhandle = NULL;

	wxString Label;
	int i = 0;
	mdhandle = FreeImage_FindFirstMetadata(FIMD_EXIF_MAIN, bitmap_free, &tag);
	if (mdhandle)
	{
		do
		{
			const char* value = FreeImage_TagToString(FIMD_EXIF_MAIN, tag);
			if (FreeImage_GetTagValue(tag))
			{
				Label = value;
				EXIF->SetCellValue(i, 0, Label);
				i++;
			}

		} while (FreeImage_FindNextMetadata(mdhandle, &tag));

		FreeImage_FindCloseMetadata(mdhandle);
	}
}

void GUIMyFrame1::DisplayFolder(wxPanel* parent, wxPanel* display, wxString &path)
{
	display->Hide();
	parent->Show();
	//path= wxT("/");
}
