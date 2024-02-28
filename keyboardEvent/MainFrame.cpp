#include "MainFrame.h"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title) :wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this);

	panel->Bind(wxEVT_KEY_DOWN, &MainFrame::OnKeyEvent, this);

	CreateStatusBar();
}

void MainFrame::OnKeyEvent(wxKeyEvent& evt) {

	wxChar keyChar = evt.GetUnicodeKey(); // which key is pressed only works for character not the special key;
	//for special key getunicodekey return none
	if (keyChar == WXK_NONE) {
		int keyCode = evt.GetKeyCode(); //get keycode of special key
		wxLogStatus("Key Event %d",keyCode);
	}
	else {
		wxLogStatus("Key Pressed %c", keyChar);
	}
}