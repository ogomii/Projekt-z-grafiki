#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1( wxWindow* parent )
:
MyFrame1( parent )
{
	m_myImage = NULL;
}

void GUIMyFrame1::WindowOnSize(wxSizeEvent& event)
{
	windowWidth = event.GetSize().GetWidth();
	windowHeight = event.GetSize().GetHeight();
	repaint();
}

void GUIMyFrame1::WindowUpdate(wxUpdateUIEvent& event)
{
}

void GUIMyFrame1::repaint()
{
	m_panel1->SetSize(windowWidth - 400, windowHeight - 45);
	wxClientDC dc(m_panel1);
	if (m_myImage)
		free(m_myImage);
	dc.Clear();
	imagesPosition.clear();
	m_fullImagesWidth = 50;
	m_fullImagesHeight = 50;
	m_imageCounter = 0;

	// open image dialog box
	if (!path_array.empty())
	{
		for (int i = 0; i < file_count; i++)
		{
			m_imageRGB = new wxImage(path_array[i], wxBITMAP_TYPE_ANY, -1); // ANY => can load many image formats
			
			m_imageRGB->Rescale(240, 180, wxIMAGE_QUALITY_NORMAL);
			m_imageWidth = m_imageRGB->GetWidth();
			m_imageHeight = m_imageRGB->GetHeight();

			wxBitmap m_imageBitmap(*m_imageRGB,-1); // ...to get the corresponding bitmap

			if (m_fullImagesWidth + m_imageWidth >= windowWidth - 450)
			{
				m_fullImagesHeight += (m_imageHeight + 30);
				m_fullImagesWidth = 50;
			}
				
			dc.DrawBitmap(m_imageBitmap, m_fullImagesWidth, m_fullImagesHeight);
			m_imageCounter++;
			imagesPosition.insert(std::make_pair(i,
				Point(m_fullImagesWidth, m_fullImagesHeight, m_fullImagesWidth + m_fullImagesWidth, m_fullImagesHeight + m_imageHeight)));

			m_fullImagesWidth += m_imageWidth + 50;
		}
	}
}

void GUIMyFrame1::LoadImgOnClick(wxCommandEvent& event)
{
	wxString defaultPath = wxT("/");
	wxDirDialog dialog(this, wxT("Choose directory"), defaultPath, wxDD_NEW_DIR_BUTTON);
	if (dialog.ShowModal() == wxID_OK) wxString path = dialog.GetPath();
	wxDir dir(dialog.GetPath());
	
	dir.GetAllFiles(dialog.GetPath(), &path_array, wxEmptyString, wxDIR_FILES);
	file_count = path_array.GetCount();
	imageLoaded = true;
	repaint();
	
}