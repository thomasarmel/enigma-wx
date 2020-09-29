#include "mainframe.h"

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_BUTTON(ID_BTNCHIFFRER, MainFrame::onButtonChiffrer)
    EVT_BUTTON(ID_BTNDECHIFFRER, MainFrame::onButtonDechiffrer)
END_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(500, 650), (!wxRESIZE_BORDER) | wxCAPTION | wxSYSTEM_MENU | wxCLOSE_BOX | wxMINIMIZE_BOX)
{
    carPos="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    noteBook1=new wxNotebook(this, wxID_ANY);

    pageChiffrement=new wxWindow(noteBook1, wxID_ANY);
    sizerVerticalChiffrement=new wxBoxSizer(wxVERTICAL);
    pageChiffrement->SetSizer(sizerVerticalChiffrement);
    textTexteAChiffrer=new wxStaticText(pageChiffrement, wxID_ANY, wxT("Chiffrer:"));
    sizerVerticalChiffrement->Add(textTexteAChiffrer, 1, wxALL | wxEXPAND, 1);
    champTexteAChiffrer=new wxTextCtrl(pageChiffrement, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
    sizerVerticalChiffrement->Add(champTexteAChiffrer, 5, wxALL | wxEXPAND, 1);
    zoneBoutonChiffrer=new wxPanel(pageChiffrement, wxID_ANY);
    sizerVerticalChiffrement->Add(zoneBoutonChiffrer, 1, wxALL | wxEXPAND, 1);
    champCleChiffrer=new wxTextCtrl(zoneBoutonChiffrer, wxID_ANY, wxEmptyString, wxPoint(5, 5), wxSize(200, -1));
    champCleChiffrer->SetHint(wxT("Clé"));
    boutonChiffrer=new wxButton(zoneBoutonChiffrer, ID_BTNCHIFFRER, wxT("Chiffrer"), wxPoint(250, 5));
    textTexteChiffre=new wxStaticText(pageChiffrement, wxID_ANY, wxT("Texte chiffré:"));
    sizerVerticalChiffrement->Add(textTexteChiffre, 1, wxALL | wxEXPAND, 1);
    champTexteChiffre=new wxTextCtrl(pageChiffrement, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
    sizerVerticalChiffrement->Add(champTexteChiffre, 5, wxALL | wxEXPAND, 1);

    pageDechiffrement=new wxWindow(noteBook1, wxID_ANY);
    sizerVerticalDechiffrement=new wxBoxSizer(wxVERTICAL);
    pageDechiffrement->SetSizer(sizerVerticalDechiffrement);
    textTexteADechiffrer=new wxStaticText(pageDechiffrement, wxID_ANY, wxT("Dechiffrer:"));
    sizerVerticalDechiffrement->Add(textTexteADechiffrer, 1, wxALL | wxEXPAND, 1);
    champTexteADechiffre=new wxTextCtrl(pageDechiffrement, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
    sizerVerticalDechiffrement->Add(champTexteADechiffre, 5, wxALL | wxEXPAND, 1);
    zoneBoutonDechiffrer=new wxPanel(pageDechiffrement, wxID_ANY);
    sizerVerticalDechiffrement->Add(zoneBoutonDechiffrer, 1, wxALL | wxEXPAND, 1);
    champCleDechiffrer=new wxTextCtrl(zoneBoutonDechiffrer, wxID_ANY, wxEmptyString, wxPoint(5, 5), wxSize(200, -1));
    champCleDechiffrer->SetHint(wxT("Clé"));
    boutonDechiffrer=new wxButton(zoneBoutonDechiffrer, ID_BTNDECHIFFRER, wxT("Déchiffrer"), wxPoint(250, 5));
    textTexteDechiffre=new wxStaticText(pageDechiffrement, wxID_ANY, wxT("Texte déchiffré:"));
    sizerVerticalDechiffrement->Add(textTexteDechiffre, 1, wxALL | wxEXPAND, 1);
    champTexteDechiffre=new wxTextCtrl(pageDechiffrement, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
    sizerVerticalDechiffrement->Add(champTexteDechiffre, 5, wxALL | wxEXPAND, 1);

    noteBook1->AddPage(pageChiffrement, wxT("Chiffrement"));
    noteBook1->AddPage(pageDechiffrement, wxT("Déchiffrement"));
}

MainFrame::~MainFrame()
{
}

wxString MainFrame::fChiffrer(wxString texteClair, wxString cle)
{
    wxVector<int> cleNB(cle.Length());
    wxString messageCrypte;
    int cleFound;
    for(unsigned int i(0); i<cle.Length(); i++)
    {
        cleFound=carPos.find(cle[i]);
        if(cleFound==wxNOT_FOUND)
        {
            cleNB[i]=0;
        }
        else
        {
            cleNB[i]=cleFound+1;
        }
    }
    int carFound, nbNouvelleLettre, decalageAjoute, decalageTotal(0);
    for(unsigned int i(0); i<texteClair.Length(); i++)
    {
        carFound=carPos.find(texteClair[i]);
        decalageAjoute=cleNB[i%cleNB.size()];
        decalageTotal=(decalageTotal+decalageAjoute)%carPos.Length();
        if(carFound==wxNOT_FOUND)
        {
            messageCrypte+=texteClair[i];
        }
        else
        {
            nbNouvelleLettre=carFound+decalageTotal;
            messageCrypte+=carPos[nbNouvelleLettre%(carPos.Length())];
        }
    }
    return messageCrypte;
}

wxString MainFrame::fDechiffrer(wxString textChiffre, wxString cle)
{
    wxVector<int> cleNB(cle.Length());
    wxString messageDecrypte;
    int cleFound;
    for(unsigned int i(0); i<cle.Length(); i++)
    {
        cleFound=carPos.find(cle[i]);
        if(cleFound==wxNOT_FOUND)
        {
            cleNB[i]=0;
        }
        else
        {
            cleNB[i]=cleFound+1;
        }
    }
    int carFound, nbNouvelleLettre, decalageAjoute, decalageTotal(0);
    for(unsigned int i(0); i<textChiffre.Length(); i++)
    {
        carFound=carPos.find(textChiffre[i]);
        decalageAjoute=cleNB[i%cleNB.size()];
        decalageTotal=(decalageTotal+decalageAjoute)%carPos.Length();
        if(carFound==wxNOT_FOUND)
        {
            messageDecrypte+=textChiffre[i];
        }
        else
        {
            nbNouvelleLettre=carFound-decalageTotal+carPos.Length();
            messageDecrypte+=carPos[nbNouvelleLettre%(carPos.Length())];
        }
    }
    return messageDecrypte;
}

void MainFrame::onButtonChiffrer(wxCommandEvent &event)
{
    wxString texteClair=champTexteAChiffrer->GetValue();
    wxString cle=champCleChiffrer->GetValue();
    if(texteClair!=wxEmptyString && cle!=wxEmptyString)
    {
        champTexteChiffre->Clear();
        champTexteChiffre->SetValue(fChiffrer(texteClair, cle));
    }
}

void MainFrame::onButtonDechiffrer(wxCommandEvent &event)
{
    wxString texteChiffre=champTexteADechiffre->GetValue();
    wxString cle=champCleDechiffrer->GetValue();
    if(texteChiffre!=wxEmptyString && cle!=wxEmptyString)
    {
        champTexteDechiffre->Clear();
        champTexteDechiffre->SetValue(fDechiffrer(texteChiffre, cle));
    }
}
