#include "MainFrame.h"
#include <wx/wx.h>

//for dynamic event handling dont need event table or ids
/*
enum IDs{
	BUTTON_ID=2,
	SLIDER_ID=3,
	TEXT_ID=4
};
*/

/*
wxBEGIN_EVENT_TABLE(MainFrame, wxFrame) //event table start
EVT_BUTTON(BUTTON_ID,MainFrame::OnButtonClicked)
EVT_SLIDER(SLIDER_ID,MainFrame::OnSliderChanged)
EVT_TEXT(TEXT_ID,MainFrame::OnTextChanged)
wxEND_EVENT_TABLE() //event table end
*/
MainFrame::MainFrame(const wxString& title) :wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this);
	/*
	wxButton* button = new wxButton(panel, BUTTON_ID, "Button", wxPoint(300, 275), wxSize(200, 50));
	wxSlider* slider = new wxSlider(panel, SLIDER_ID,0,0,100, wxPoint(300, 200), wxSize(200, -1));
	wxTextCtrl* textCtrl = new wxTextCtrl(panel, TEXT_ID, "", wxPoint(300, 375), wxSize(200, -1));
	*/
	wxButton* button = new wxButton(panel,wxID_ANY, "Button", wxPoint(300, 275), wxSize(200, 50));
	wxSlider* slider = new wxSlider(panel, wxID_ANY, 0, 0, 100, wxPoint(300, 200), wxSize(200, -1));
	wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(300, 375), wxSize(200, -1));

	button->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
	slider->Bind(wxEVT_SLIDER, &MainFrame::OnSliderChanged, this);
	textCtrl->Bind(wxEVT_TEXT, &MainFrame::OnTextChanged, this);

	//for unbind any event
	button->Unbind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);

	CreateStatusBar(); //create status bar
}

void MainFrame::OnButtonClicked(wxCommandEvent& evt) {
	wxLogStatus("Button clicked"); //log in status bar
}
void MainFrame::OnSliderChanged(wxCommandEvent& evt) {
	wxString str = wxString::Format("Slider Value: %d", evt.GetInt());
	wxLogStatus(str);
}
void MainFrame::OnTextChanged(wxCommandEvent& evt) {
	wxString str = wxString::Format("text: %s",evt.GetString());
	wxLogStatus(str);
}