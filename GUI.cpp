///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"


///////////////////////////////////////////////////////////////////////////

MyFrame1::MyFrame1(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxSize(800, 600), wxDefaultSize);

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer(wxHORIZONTAL);

	m_panel1 = new wxScrolledWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	m_panel1->SetBackgroundColour(wxColour(255, 255, 255));
	m_panel1->Layout();
	bSizer2->Add(m_panel1, 1, wxALL | wxEXPAND, 5);


	//panel full dsplay
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer(wxHORIZONTAL);
	m_panelFullDisplay = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	m_panelFullDisplay->SetBackgroundColour(wxColour(255, 255, 255));
	m_panelFullDisplay->Layout();
	bSizer3->Add(m_panelFullDisplay, 1, wxALL | wxEXPAND, 5);
	m_panelFullDisplay->Hide();



	bSizer1->Add(bSizer2, 1, wxEXPAND, 5);
	bSizer1->Add(bSizer3, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer(wxHORIZONTAL);

	IPTC = new wxGrid(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0);

	// Grid
	IPTC->CreateGrid(6, 1);
	IPTC->EnableEditing(true);
	IPTC->EnableGridLines(true);
	IPTC->EnableDragGridSize(false);
	IPTC->SetMargins(0, 0);

	// Columns
	IPTC->SetColSize(0, 242);
	IPTC->EnableDragColMove(false);
	IPTC->EnableDragColSize(false);
	IPTC->SetColLabelSize(0);
	IPTC->SetColLabelValue(0, wxT("Values"));
	IPTC->SetColLabelAlignment(wxALIGN_CENTER, wxALIGN_CENTER);

	// Rows
	IPTC->AutoSizeRows();
	IPTC->EnableDragRowSize(true);
	IPTC->SetRowLabelSize(130);
	IPTC->SetRowLabelValue(0, wxT("Title"));
	IPTC->SetRowLabelValue(1, wxT("ReleaseDate"));
	IPTC->SetRowLabelValue(2, wxT("City"));
	IPTC->SetRowLabelValue(3, wxT("Country"));
	IPTC->SetRowLabelValue(4, wxT("Author"));
	IPTC->SetRowLabelValue(5, wxT("Keywords"));
	IPTC->SetRowLabelAlignment(wxALIGN_CENTER, wxALIGN_CENTER);

	// Label Appearance

	// Cell Defaults
	IPTC->SetDefaultCellAlignment(wxALIGN_CENTER, wxALIGN_TOP);
	bSizer11->Add(IPTC, 0, wxALIGN_TOP | wxALL, 5);


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
	EXIF->SetRowLabelSize(130);
	EXIF->SetRowLabelValue(0, wxT("Camera make"));
	EXIF->SetRowLabelValue(1, wxT("Camera model"));
	EXIF->SetRowLabelValue(2, wxT("Date/Time"));
	EXIF->SetRowLabelValue(3, wxT("Image description"));
	EXIF->SetRowLabelValue(4, wxT("Orientation"));
	EXIF->SetRowLabelValue(5, wxT("X resolution [dpi]"));
	EXIF->SetRowLabelValue(6, wxT("Y resolution [dpi]"));
	EXIF->SetRowLabelValue(7, wxT("Resolution unit"));
	EXIF->SetRowLabelValue(8, wxT("Software"));
	EXIF->SetRowLabelValue(9, wxT("White point"));
	EXIF->SetRowLabelValue(10, wxT("Primary Chomaticities"));
	EXIF->SetRowLabelValue(11, wxT("YCbCr Coefficients"));
	EXIF->SetRowLabelValue(12, wxT("YCbCr Positioning"));
	EXIF->SetRowLabelValue(13, wxT("Reference BlackWhite"));
	EXIF->SetRowLabelValue(14, wxT("Copyright"));
	EXIF->SetRowLabelValue(15, wxT("Exif Offset"));
	EXIF->SetRowLabelAlignment(wxALIGN_CENTER, wxALIGN_CENTER);

	// Label Appearance

	// Cell Defaults
	EXIF->SetDefaultCellAlignment(wxALIGN_CENTER, wxALIGN_TOP);
	bSizer10->Add(EXIF, 0, wxALL, 5);


	bSizer7->Add(bSizer10, 1, wxEXPAND, 5);


	bSizer4->Add(bSizer7, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer(wxVERTICAL);

	reset = new wxButton(this, wxID_ANY, wxT("Resetuj dane IPTC"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer9->Add(reset, 0, wxALIGN_CENTER | wxALL, 5);

	A = new wxButton(this, wxID_ANY, wxT("Wygeneruj plik"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer9->Add(A, 0, wxALIGN_CENTER | wxALL, 5);

	B = new wxButton(this, wxID_ANY, wxT("Zapisz tekst"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer9->Add(B, 0, wxALIGN_CENTER | wxALL, 5);

	D = new wxButton(this, wxID_ANY, wxT("Wczytaj folder"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer9->Add(D, 0, wxALIGN_CENTER | wxALL, 5);


	bSizer4->Add(bSizer9, 0, wxALIGN_CENTER, 5);


	bSizer1->Add(bSizer4, 0, wxEXPAND, 5);


	this->SetSizer(bSizer1);
	this->Layout();

	this->Centre(wxBOTH);

	// Connect Events
	this->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MyFrame1::window_update));
	D->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::LoadImgOnClick), NULL, this);
	reset->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::IPTCReset), NULL, this);

}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	this->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MyFrame1::window_update));
	D->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::LoadImgOnClick), NULL, this);
	reset->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::IPTCReset), NULL, this);

}
