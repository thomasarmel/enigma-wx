#ifndef MAINFRAME_H_INCLUDED
#define MAINFRAME_H_INCLUDED

#include "myapp.h"

class MainFrame : public wxFrame
{
    public:
        MainFrame(const wxString& title);
        virtual ~MainFrame();
    private:
        wxString fChiffrer(wxString cle, wxString textClair);
        wxString fDechiffrer(wxString textChiffre, wxString cle);
        void onButtonChiffrer(wxCommandEvent &event);
        void onButtonDechiffrer(wxCommandEvent &event);
        DECLARE_EVENT_TABLE()

        wxNotebook *noteBook1;
        wxWindow *pageChiffrement, *pageDechiffrement;
        wxBoxSizer *sizerVerticalChiffrement, *sizerVerticalDechiffrement;
        wxTextCtrl *champTexteAChiffrer, *champTexteChiffre, *champTexteADechiffre, *champTexteDechiffre;
        wxStaticText *textTexteAChiffrer, *textTexteChiffre, *textTexteADechiffrer, *textTexteDechiffre;
        wxPanel *zoneBoutonChiffrer, *zoneBoutonDechiffrer;
        wxButton *boutonChiffrer, *boutonDechiffrer;
        wxTextCtrl *champCleChiffrer, *champCleDechiffrer;
        wxString carPos;

        enum
        {
            ID_BTNCHIFFRER=wxID_HIGHEST+1,
            ID_BTNDECHIFFRER
        };
};


#endif // MAINFRAME_H_INCLUDED
