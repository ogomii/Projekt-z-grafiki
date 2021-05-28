#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1(wxWindow* parent)
	:
	MyFrame1(parent)
{
	m_myImage = NULL;
	file_count = 0;
	fgSizer1 = new wxFlexGridSizer(1, 0, 0, 0);
}

Panel2* GUIMyFrame1::currentFullDisplay = new Panel2();
int GUIMyFrame1::FDwindow_width = 700;
int GUIMyFrame1::FDwindow_height = 1200;
MyButton* GUIMyFrame1::currentPic = new MyButton();

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

	path_array.Clear();
	imageLoaded = false;
	changedirectoryclickevent = 0;
	//if (fgSizer1) fgSizer1->Clear(true);
	fgSizer1 = nullptr;
	bitmapVector.clear();
	file_count = 0;
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
	wxClientDC dc(m_panel1);
	dc.SetPen(*wxBLACK_PEN);
	wxString text = "LOADING IMAGES...";
	dc.SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, "Calibri"));
	dc.DrawText(text, wxPoint(dc.GetSize().GetWidth() / 2 - 150, dc.GetSize().GetHeight() / 2));


	if (file_count > 0)
	{
		for (int i = 0; i < file_count; i++) //load images to vector
		{
			wxImage imag = wxImage(path_array[i], wxBITMAP_TYPE_ANY, -1);
			imag.Rescale(240, 180, wxIMAGE_QUALITY_NEAREST);

			wxBitmap bmpt1(imag, -1);
			bitmapVector.push_back(bmpt1);

		}
		dc.Clear();
		printBitmapButtons();
	}
}


void GUIMyFrame1::printBitmapButtons() {
	if (file_count > 0)
	{
		int rows = 1;
		int cols = (window_width - 40) / 240;
		if (cols != 0) rows = file_count / cols + 1;
		if (fgSizer1) fgSizer1->Clear(true);
		fgSizer1 = new wxFlexGridSizer(rows, cols, 0, 0);

		for (int i = 0; i < file_count; i++) //load images to vector
		{
			wxString path_a = path_array[i];
			wxBitmapButton* m_bmt1 = new MyButton(fgSizer1, m_panel1, m_panelFullDisplay, EXIF, IPTC, -1, bitmapVector[i], wxPoint(m_fullImagesHeight, m_fullImagesWidth), path_a);
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


void GUIMyFrame1::DisplayMetaData(wxGrid* EXIF, wxGrid* IPTC, wxPanel* parent, wxPanel* display, wxString path)
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
	int z = 0;
	mdhandle = FreeImage_FindFirstMetadata(FIMD_EXIF_MAIN, bitmap_free, &tag);

	if (mdhandle)
	{
		z = 1;
		do
		{
			const char* value = FreeImage_TagToString(FIMD_EXIF_MAIN, tag);

			if (FreeImage_GetTagValue(tag))
			{
				Label = value;
				EXIF->SetCellValue(i, 0, Label);
				i++;
			}

		} while (FreeImage_FindNextMetadata(mdhandle, &tag) && i < 16);

		FreeImage_FindCloseMetadata(mdhandle);
	}


	if (!z) {
		for (int k = 0; k < 16; k++) {
			EXIF->SetCellValue(k, 0, "");
		}
	}


	//INSERTING META DATA
	//FreeImage_SetMetadataKeyValue(FIMD_IPTC, bmp, "By-lineTitle", "]]]]]]]]]");							//IMPORTANT - how to insert metadata into jpeg!!!!!!!
	//FreeImage_Save(FIF_JPEG, bitmap_free, path, 0);


	tag = NULL;
	FreeImage_GetMetadata(FIMD_IPTC, bitmap_free, "By-lineTitle", &tag);
	if (tag != NULL) {
		const char* value = (char*)FreeImage_GetTagValue(tag);
		Label = value;
		IPTC->SetCellValue(0, 0, value);
	}
	else {
		IPTC->SetCellValue(0, 0, "");
	}
	tag = NULL;
	FreeImage_GetMetadata(FIMD_IPTC, bitmap_free, "DateCreated", &tag);
	if (tag != NULL) {
		const char* value = (char*)FreeImage_GetTagValue(tag);
		Label = value;
		IPTC->SetCellValue(1, 0, value);
	}
	else {
		IPTC->SetCellValue(1, 0, "");
	}
	tag = NULL;
	FreeImage_GetMetadata(FIMD_IPTC, bitmap_free, "City", &tag);
	if (tag != NULL) {
		const char* value = (char*)FreeImage_GetTagValue(tag);
		Label = value;
		IPTC->SetCellValue(2, 0, value);
	}
	else {
		IPTC->SetCellValue(2, 0, "");
	}
	tag = NULL;
	FreeImage_GetMetadata(FIMD_IPTC, bitmap_free, "Country-PrimaryLocationName", &tag);
	if (tag != NULL) {
		const char* value = (char*)FreeImage_GetTagValue(tag);
		Label = value;
		IPTC->SetCellValue(3, 0, value);
	}
	else {
		IPTC->SetCellValue(3, 0, "");
	}
	tag = NULL;
	FreeImage_GetMetadata(FIMD_IPTC, bitmap_free, "By-line", &tag);
	if (tag != NULL) {
		const char* value = (char*)FreeImage_GetTagValue(tag);
		Label = value;
		IPTC->SetCellValue(4, 0, value);
	}
	else {
		IPTC->SetCellValue(4, 0, "");
	}
	tag = NULL;
	FreeImage_GetMetadata(FIMD_IPTC, bitmap_free, "Keywords", &tag);
	if (tag != NULL) {
		const char* value = (char*)FreeImage_GetTagValue(tag);
		Label = value;
		IPTC->SetCellValue(5, 0, value);
	}
	else {
		IPTC->SetCellValue(5, 0, "");
	}



}

void GUIMyFrame1::DisplayFolder(wxPanel* parent, wxPanel* display, wxString& path)
{
	display->Hide();
	parent->Show();
}


wxString GUIMyFrame1::getDataOnBitmap(wxString path)
{
	FIBITMAP* bmp;
	FIBITMAP* bitmap_free;
	bmp = FreeImage_Load(FIF_JPEG, path, JPEG_DEFAULT);
	int bip = FreeImage_GetBPP(bmp);
	bitmap_free = FreeImage_Allocate(240, 180, bip);
	bitmap_free = bmp;
	FITAG* tag = NULL;
	FIMETADATA* mdhandle = NULL;

	wxString dataOnBitmap = "";
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
				dataOnBitmap += Label + "\n";
				i++;
			}

		} while (FreeImage_FindNextMetadata(mdhandle, &tag) && i < 5);

		FreeImage_FindCloseMetadata(mdhandle);
	}
	return dataOnBitmap;
}

void GUIMyFrame1::WriteDataOnPic(wxCommandEvent& event)
{
	if (!m_panelFullDisplay->IsShown())
	{
		wxMessageBox(_("No image opened"));
		return;
	}
	wxString currPath = currentFullDisplay->getPath();
	wxImage im = wxImage(currPath, wxBITMAP_TYPE_ANY, -1);
	wxBitmap b1(im, -1);
	wxMemoryDC mem(b1);

	wxString dataOnBitmap = getDataOnBitmap(currPath);
	mem.DrawText(dataOnBitmap, wxPoint(0, 0));

	const wxImage image = b1.ConvertToImage();
	wxInitAllImageHandlers();
	wxFileDialog saveFileDialog(this, _("Save PNG file"), "", "",
		"PNG files (*.png)|*.png", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	if (saveFileDialog.ShowModal() == wxID_OK)
	{
		wxFileName my_file(saveFileDialog.GetPath());
		wxString my_file_ext = my_file.GetExt().Lower();

		if (my_file_ext == wxT("png")) image.SaveFile(saveFileDialog.GetPath(), wxBITMAP_TYPE_PNG);

		else wxMessageBox(wxT("Extension ERROR"), wxT("ERROR"));
	}
}


void GUIMyFrame1::GenerateTextOnAll(wxCommandEvent& event)
{
	if (path_array.empty())
	{
		wxMessageBox(wxT("No files to write"));
		return;
	}
	wxFileDialog saveFileDialog(this, _("Save PNG file"), "", "",
		"PNG files (*.png)|*.png", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	if (saveFileDialog.ShowModal() == wxID_OK)
	{
		wxFileName my_file(saveFileDialog.GetPath());
		wxString my_file_ext = my_file.GetExt().Lower();
		if (!(my_file_ext == wxT("png"))) return;
	}
	wxString dataOnBitmap = "";
	for (int i = 0; i < file_count; i++)
	{
		wxString fileName = saveFileDialog.GetPath().erase(saveFileDialog.GetPath().Length() - 4) + wxString::Format(wxT("%i"), i) + wxString(".png");
		dataOnBitmap = getDataOnBitmap(path_array[i]);
		wxImage im = wxImage(path_array[i], wxBITMAP_TYPE_ANY, -1);
		wxBitmap b1(im, -1);
		wxMemoryDC mem(b1);
		mem.DrawText(dataOnBitmap, wxPoint(0, 0));
		const wxImage image = b1.ConvertToImage();
		image.SaveFile(fileName, wxBITMAP_TYPE_PNG);
	}
}

void GUIMyFrame1::IPTCReset(wxCommandEvent& event) {
	FIBITMAP* bmp;
	FIBITMAP* bitmap_free;
	bmp = FreeImage_Load(FIF_JPEG, GUIMyFrame1::currentPic->GetPathFromClick(), JPEG_DEFAULT);
	int bip = FreeImage_GetBPP(bmp);
	bitmap_free = FreeImage_Allocate(240, 180, bip);
	bitmap_free = bmp;
	FITAG* tag = NULL;
	FIMETADATA* mdhandle = NULL;


	//----------------------------------------------
			/*int k = 0;
			mdhandle = FreeImage_FindFirstMetadata(FIMD_EXIF_MAIN, bitmap_free, &tag);
			if (mdhandle)
			{
				do
				{
					const char* value = FreeImage_TagToString(FIMD_EXIF_MAIN, tag);
					if (FreeImage_GetTagValue(tag))
					{
						//FreeImage_SetMetadataKeyValue(FIMD_EXIF_MAIN, bitmap_free, FreeImage, "");
						EXIF->SetCellValue(i, 0, " ");
						k++;
					}
				} while (FreeImage_FindNextMetadata(mdhandle, &tag) && k < 16);
				FreeImage_FindCloseMetadata(mdhandle);
			}*/
			//-------------------------------------------------
					//const char *
	FreeImage_SetMetadataKeyValue(FIMD_IPTC, bitmap_free, "By-lineTitle", "");
	FreeImage_SetMetadataKeyValue(FIMD_IPTC, bitmap_free, "DateCreated", "");
	FreeImage_SetMetadataKeyValue(FIMD_IPTC, bitmap_free, "City", "");
	FreeImage_SetMetadataKeyValue(FIMD_IPTC, bitmap_free, "Country-PrimaryLocationName", "");
	FreeImage_SetMetadataKeyValue(FIMD_IPTC, bitmap_free, "By-line", "");
	FreeImage_SetMetadataKeyValue(FIMD_IPTC, bitmap_free, "Keywords", "");
	IPTC->SetCellValue(0, 0, " ");
	IPTC->SetCellValue(1, 0, " ");
	IPTC->SetCellValue(2, 0, " ");
	IPTC->SetCellValue(3, 0, " ");
	IPTC->SetCellValue(4, 0, " ");
	IPTC->SetCellValue(5, 0, " ");

	FreeImage_Save(FIF_JPEG, bitmap_free, GUIMyFrame1::currentPic->GetPathFromClick(), 0);

}


void GUIMyFrame1::WriteInIPTCData(wxCommandEvent& event) {
	FIBITMAP* bmp;
	FIBITMAP* bitmap_free;
	bmp = FreeImage_Load(FIF_JPEG, GUIMyFrame1::currentPic->GetPathFromClick(), JPEG_DEFAULT);
	int bip = FreeImage_GetBPP(bmp);
	bitmap_free = FreeImage_Allocate(240, 180, bip);
	bitmap_free = bmp;
	FITAG* tag = NULL;
	FIMETADATA* mdhandle = NULL;


	wxString t(IPTC->GetCellValue(0, 0));
	FreeImage_SetMetadataKeyValue(FIMD_IPTC, bmp, "By-lineTitle", t);
	t = IPTC->GetCellValue(1, 0);
	FreeImage_SetMetadataKeyValue(FIMD_IPTC, bmp, "DateCreated", t);
	t = IPTC->GetCellValue(2, 0);
	FreeImage_SetMetadataKeyValue(FIMD_IPTC, bmp, "City", t);
	t = IPTC->GetCellValue(3, 0);
	FreeImage_SetMetadataKeyValue(FIMD_IPTC, bmp, "Country-PrimaryLocationName", t);
	t = IPTC->GetCellValue(4, 0);
	FreeImage_SetMetadataKeyValue(FIMD_IPTC, bmp, "By-line", t);
	t = IPTC->GetCellValue(5, 0);
	FreeImage_SetMetadataKeyValue(FIMD_IPTC, bmp, "Keywords", t);
	FreeImage_Save(FIF_JPEG, bitmap_free, GUIMyFrame1::currentPic->GetPathFromClick(), 0);

}
