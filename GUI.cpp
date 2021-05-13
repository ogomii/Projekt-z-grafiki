///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"


///////////////////////////////////////////////////////////////////////////

MyFrame1::MyFrame1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) 
	: wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer(wxVERTICAL);

	//Changes here ---------------------------
	m_panel1 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	m_panel1->SetBackgroundColour(wxColour(255, 255, 255));

	bSizer2->Add(m_panel1, 1, wxALL | wxEXPAND | wxRESERVE_SPACE_EVEN_IF_HIDDEN, 5);
	//Changes ---------------------------


	bSizer1->Add(bSizer2, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer(wxHORIZONTAL);

	EXIF1 = new wxGrid(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0);

	// Grid
	EXIF1->CreateGrid(5, 1);
	EXIF1->EnableEditing(true);
	EXIF1->EnableGridLines(true);
	EXIF1->EnableDragGridSize(false);
	EXIF1->SetMargins(0, 0);

	// Columns
	EXIF1->SetColSize(0, 242);
	EXIF1->EnableDragColMove(false);
	EXIF1->EnableDragColSize(false);
	EXIF1->SetColLabelSize(0);
	EXIF1->SetColLabelValue(0, wxT("Values"));
	EXIF1->SetColLabelAlignment(wxALIGN_CENTER, wxALIGN_CENTER);

	// Rows
	EXIF1->AutoSizeRows();
	EXIF1->EnableDragRowSize(true);
	EXIF1->SetRowLabelSize(110);
	EXIF1->SetRowLabelValue(0, wxT("Title"));
	EXIF1->SetRowLabelValue(1, wxT("Date created"));
	EXIF1->SetRowLabelValue(2, wxT("City"));
	EXIF1->SetRowLabelValue(3, wxT("Country"));
	EXIF1->SetRowLabelValue(4, wxT("Creator"));
	EXIF1->SetRowLabelAlignment(wxALIGN_CENTER, wxALIGN_CENTER);

	// Label Appearance

	// Cell Defaults
	EXIF1->SetDefaultCellAlignment(wxALIGN_CENTER, wxALIGN_TOP);
	bSizer11->Add(EXIF1, 0, wxALIGN_TOP | wxALL, 5);


	bSizer7->Add(bSizer11, 0, wxEXPAND, 5);

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer(wxHORIZONTAL);

	EXIF = new wxGrid(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0);

	// Grid
	EXIF->CreateGrid(16, 1);
	EXIF->EnableEditing(false);
	EXIF->EnableGridLines(true);
	EXIF->EnableDragGridSize(false);
	EXIF->SetMargins(0, 0);

	// Columns
	EXIF->SetColSize(0, 242);
	EXIF->EnableDragColMove(false);
	EXIF->EnableDragColSize(false);
	EXIF->SetColLabelSize(0);
	EXIF->SetColLabelValue(0, wxT("Values"));
	EXIF->SetColLabelAlignment(wxALIGN_CENTER, wxALIGN_CENTER);

	// Rows
	EXIF->AutoSizeRows();
	EXIF->EnableDragRowSize(true);
	EXIF->SetRowLabelSize(110);
	EXIF->SetRowLabelValue(0, wxT("Camera make"));
	EXIF->SetRowLabelValue(1, wxT("Camera model"));
	EXIF->SetRowLabelValue(2, wxT("Data/Time"));
	EXIF->SetRowLabelValue(3, wxT("Exif version"));
	EXIF->SetRowLabelValue(4, wxT("Width x Height"));
	EXIF->SetRowLabelValue(5, wxT("X resolution [dpi]"));
	EXIF->SetRowLabelValue(6, wxT("Y resolution [dpi]"));
	EXIF->SetRowLabelValue(7, wxT("Flash used"));
	EXIF->SetRowLabelValue(8, wxT("Focal length"));
	EXIF->SetRowLabelValue(9, wxT("CCD width"));
	EXIF->SetRowLabelValue(10, wxT("Brightness"));
	EXIF->SetRowLabelValue(11, wxT("Aperture"));
	EXIF->SetRowLabelValue(12, wxT("ISO equiv."));
	EXIF->SetRowLabelValue(13, wxT("Matering Mode"));
	EXIF->SetRowLabelValue(14, wxT("Exposure"));
	EXIF->SetRowLabelValue(15, wxT("Encoding"));
	EXIF->SetRowLabelValue(16, wxEmptyString);
	EXIF->SetRowLabelValue(17, wxT("Exposure time"));
	EXIF->SetRowLabelValue(18, wxT("Y resolution [dpi]"));
	EXIF->SetRowLabelValue(19, wxEmptyString);
	EXIF->SetRowLabelAlignment(wxALIGN_CENTER, wxALIGN_CENTER);

	// Label Appearance

	// Cell Defaults
	EXIF->SetDefaultCellAlignment(wxALIGN_CENTER, wxALIGN_TOP);
	bSizer10->Add(EXIF, 0, wxALL, 5);


	bSizer7->Add(bSizer10, 1, wxEXPAND, 5);


	bSizer4->Add(bSizer7, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer(wxVERTICAL);

	A = new wxButton(this, wxID_ANY, wxT("Wygeneruj plik"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer9->Add(A, 0, wxALIGN_CENTER | wxALL, 5);

	B = new wxButton(this, wxID_ANY, wxT("Zapisz tekst"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer9->Add(B, 0, wxALIGN_CENTER | wxALL, 5);

	D = new wxButton(this, wxID_ANY, wxT("Wczytaj plik"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer9->Add(D, 0, wxALIGN_CENTER | wxALL, 5);


	bSizer4->Add(bSizer9, 0, wxALIGN_CENTER, 5);


	bSizer1->Add(bSizer4, 0, wxEXPAND, 5);


	this->SetSizer(bSizer1);
	this->Layout();

	this->Centre(wxBOTH);

	this->Centre( wxBOTH );
	this->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MyFrame1::WindowUpdate));
	D->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::LoadImgOnClick), NULL, this);
	this->Connect(wxEVT_SIZE, wxSizeEventHandler(MyFrame1::WindowOnSize));

}

MyFrame1::~MyFrame1()
{
	this->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MyFrame1::WindowUpdate));
	D->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::LoadImgOnClick), NULL, this);
	this->Disconnect(wxEVT_SIZE, wxSizeEventHandler(MyFrame1::WindowOnSize));
	
}
