#include "MainFrame.h"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this);
	wxButton* button1 = new wxButton(panel, wxID_ANY, "Button1", wxPoint(300, 275), wxSize(200, 50));
	wxButton* button2 = new wxButton(panel, wxID_ANY, "Button2", wxPoint(300, 350), wxSize(200, 50));
	//frame(this)->panel->button
	this->Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnClose, this);
	panel->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
	button1->Bind(wxEVT_BUTTON, &MainFrame::OnButton1Clicked, this); //if button1 have no event then it check for its parent that is panel
	button2->Bind(wxEVT_BUTTON, &MainFrame::OnButton2Clicked, this);

	CreateStatusBar();
}

void MainFrame::OnClose(wxCloseEvent& evt) {
	wxLogMessage("Before close window save your work sir!");
	evt.Skip();
}
void MainFrame::OnButtonClicked(wxCommandEvent& evt) {
	wxLogStatus("Button Clicked");
}
void MainFrame::OnButton1Clicked(wxCommandEvent& evt) {
	wxLogMessage("Button Clicked 1");
	evt.Skip(); //if we skip the event on button then after finishing its job propagaton will happen
}
void MainFrame::OnButton2Clicked(wxCommandEvent& evt) {
	wxLogMessage("Button Clicked 2");
	evt.Skip();
}