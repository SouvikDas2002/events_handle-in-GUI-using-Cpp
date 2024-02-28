#include "MainFrame.h"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title) :wxFrame(nullptr,wxID_ANY,title) {
	wxPanel* panel = new wxPanel(this);

	//there are more mouse event right down,middle button,double click etc
	panel->Bind(wxEVT_LEFT_DOWN, &MainFrame::OnMouseLockEvent, this);
	panel->Bind(wxEVT_MOTION, &MainFrame::OnMouseEvent, this); // cursor point during movement

	//status bar is flickering when mouse motion event update again and again , so for stop this use setdoublebuffered
	wxStatusBar* statusBar= CreateStatusBar();
	statusBar->SetDoubleBuffered(true);
}

void MainFrame::OnMouseEvent(wxMouseEvent& evt) {
	wxPoint mouse = evt.GetPosition();//get mouse position
	wxString message = wxString::Format("Mouse Event Detected! (x=%d y=%d)", mouse.x, mouse.y);
	wxLogStatus(message);
}
void MainFrame::OnMouseLockEvent(wxMouseEvent& evt) {
	wxPoint mouse = evt.GetPosition();
	wxString message = wxString::Format("You lock your mouse at position (x=%d y=%d)", mouse.x, mouse.y);
	wxLogMessage(message);
}