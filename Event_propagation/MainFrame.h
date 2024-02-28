#pragma once
#include <wx/wx.h>
class MainFrame:public wxFrame
{
public:
	MainFrame(const wxString& title);
	void OnButtonClicked(wxCommandEvent& evt);
	void OnButton1Clicked(wxCommandEvent& evt);
	void OnButton2Clicked(wxCommandEvent& evt);
	void OnClose(wxCloseEvent& evt);//close event
};

