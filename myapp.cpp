#include "myapp.h"

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    MainFrame *frm=new MainFrame(_T("Chiffrement Enigma"));
    frm->Show();
    return true;
}
