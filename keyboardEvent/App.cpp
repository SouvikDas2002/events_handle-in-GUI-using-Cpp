#include "App.h"
#include "MainFrame.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(App); //create a instance of App and calll onInit()method

bool App::OnInit() {
	MainFrame* mainFrame = new MainFrame("C++ GUI"); //instance of MainFrame
	mainFrame->SetClientSize(800, 600); //define window size
	mainFrame->Center(); //define position
	mainFrame->Show();
	return true; //telling wxwindow that process should ontinue
}