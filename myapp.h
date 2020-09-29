#ifndef MYAPP_H_INCLUDED
#define MYAPP_H_INCLUDED

#include <wx/wx.h>
#include <wx/notebook.h>

#include "mainframe.h"

class MyApp : public wxApp
{
    public:
        virtual bool OnInit();
};

DECLARE_APP(MyApp);

#endif // MYAPP_H_INCLUDED
