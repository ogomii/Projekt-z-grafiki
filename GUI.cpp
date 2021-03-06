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

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer(wxVERTICAL);

	m_textCtrl1 = new wxStaticText(this, wxID_ANY, wxT("EXIF Info"), wxDefaultPosition, wxDefaultSize, 0);
	m_textCtrl1->Wrap(-1);
	bSizer8->Add(m_textCtrl1, 0, wxALL, 5);
	
	bSizer7->Add(bSizer8, 1, wxEXPAND, 5);

	


	


	bSizer4->Add(bSizer7, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer(wxVERTICAL);

	reset = new wxButton(this, wxID_ANY, wxT("Resetuj dane IPTC"), wxDefaultPosition, wxSize(130, -1), 0);
	bSizer9->Add(reset, 0, wxALIGN_CENTER | wxALL, 5);

	w_IPTC = new wxButton(this, wxID_ANY, wxT("Zapisz IPTC"), wxDefaultPosition, wxSize(130, -1), 0);
	bSizer9->Add(w_IPTC, 0, wxALIGN_CENTER | wxALL, 5);

	A = new wxButton(this, wxID_ANY, wxT("Zapisz tekst wszedzie"), wxDefaultPosition, wxSize(130, -1), 0);
	bSizer9->Add(A, 0, wxALIGN_CENTER | wxALL, 5);

	B = new wxButton(this, wxID_ANY, wxT("Zapisz tekst"), wxDefaultPosition, wxSize(130, -1), 0);
	bSizer9->Add(B, 0, wxALIGN_CENTER | wxALL, 5);

	E = new wxButton(this, wxID_ANY, wxT("Zapisz dane"), wxDefaultPosition, wxSize(130, -1), 0);
	bSizer9->Add(E, 0, wxALIGN_CENTER | wxALL, 5);

	D = new wxButton(this, wxID_ANY, wxT("Wczytaj folder"), wxDefaultPosition, wxSize(130, -1), 0);
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
	B->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::WriteDataOnPic), NULL, this);
	A->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::GenerateTextOnAll), NULL, this);
	w_IPTC->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::WriteInIPTCData), NULL, this);
	E->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::WriteDataToFile), NULL, this);
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	this->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MyFrame1::window_update));
	D->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::LoadImgOnClick), NULL, this);
	reset->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::IPTCReset), NULL, this);
	B->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::WriteDataOnPic), NULL, this);
	A->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::GenerateTextOnAll), NULL, this);
	w_IPTC->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::WriteInIPTCData), NULL, this);
	E->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::WriteDataToFile), NULL, this);
}
