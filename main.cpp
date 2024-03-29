#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <cstdlib>
#include <string>
#include <cstdio>

using namespace std;

struct Uzytkownik {
    int id = 0;
    int idLogujacego = 0;
    string imie = "";
    string nazwisko = "";
    string nrTelefonu = "";
    string email = "";
    string adres = "";

};
struct Logowanie {
    int id = 1;
    string login = "" ;
    string haslo = "" ;
};
void ZaktualizujBaze(vector <Uzytkownik> &uzytkownicy) {

    Uzytkownik uzytkownik;
    bool czyJestWwektorze = false;
    int id, numerKontenera = 0;
    int numerSlowa = 0;
    string linia,tymczasoweId;
    fstream plik,plik2;
    string slowo;

    plik.open("baza.txt",ios::in);
    if ( plik.good() == false )
        ofstream plik( "baza.txt" );
    plik2.open( "baza_temp.txt",ios::out );
    if ( plik2.good() == false )
        ofstream plik2( "baza_temp.txt" );
    while(getline(plik,linia)) {
        for( int i = 0 ; i < linia.length() ; i++ ) {
            if( linia[i] != '|')
                slowo += linia[i];
            else if( linia[i] == '|' ) {
                switch (numerSlowa) {
                case 0 :
                    tymczasoweId = slowo ;
                    id = atoi(tymczasoweId.c_str());
                    uzytkownik.id = id;
                    slowo = "";
                    numerSlowa++;
                    break;
                case 1 :
                    tymczasoweId = slowo ;
                    id = atoi(tymczasoweId.c_str());
                    uzytkownik.idLogujacego = id;
                    slowo = "";
                    numerSlowa++;
                    break;
                case 2 :
                    uzytkownik.imie = slowo;
                    slowo = "";
                    numerSlowa++;
                    break;
                case 3:
                    uzytkownik.nazwisko = slowo;
                    slowo = "";
                    numerSlowa++;
                    break;
                case 4:
                    uzytkownik.nrTelefonu = slowo;
                    slowo = "";
                    numerSlowa++;
                    break;
                case 5:
                    uzytkownik.email = slowo;
                    slowo = "";
                    numerSlowa++;
                    break;
                case 6:
                    uzytkownik.adres = slowo;
                    slowo = "";
                    numerSlowa++;
                    break;
                }

            }


        }
        for (int j = 0 ; j < uzytkownicy.size(); j++) {
                if (uzytkownik.id == uzytkownicy[j].id) {
                    czyJestWwektorze = true;
                    numerKontenera = j;
                }
            }
            if ( czyJestWwektorze == true ) {

                plik2 << uzytkownicy[numerKontenera].id<< "|";
                plik2 << uzytkownicy[numerKontenera].idLogujacego<< "|";
                plik2 << uzytkownicy[numerKontenera].imie<< "|";
                plik2 << uzytkownicy[numerKontenera].nazwisko<<"|";
                plik2 << uzytkownicy[numerKontenera].nrTelefonu<<"|";
                plik2 << uzytkownicy[numerKontenera].email<<"|";
                plik2 << uzytkownicy[numerKontenera].adres<<"|"<<endl;
            } else {
                plik2 << uzytkownik.id<< "|";
                plik2 << uzytkownik.idLogujacego<< "|";
                plik2 << uzytkownik.imie<< "|";
                plik2 << uzytkownik.nazwisko<<"|";
                plik2 << uzytkownik.nrTelefonu<<"|";
                plik2 << uzytkownik.email<<"|";
                plik2 << uzytkownik.adres<<"|"<<endl;
            }
        numerSlowa = 0;
        czyJestWwektorze = false;
        numerKontenera = 0;
    }
    plik.close();
    plik2.close();
    remove( "baza.txt");
    rename("baza_temp.txt","baza.txt");
}
void UsunIZaktualizujBaze(vector <Uzytkownik> &uzytkownicy, int idUzytkownika ) {

    Uzytkownik uzytkownik;
    bool czyJestWwektorze = false;
    int id, numerKontenera = 0;
    int numerSlowa = 0;
    string linia,tymczasoweId;
    fstream plik,plik2;
    string slowo;

    plik.open("baza.txt",ios::in);
    if ( plik.good() == false )
        ofstream plik( "baza.txt" );
    plik2.open( "baza_temp.txt",ios::out );
    if ( plik2.good() == false )
        ofstream plik2( "baza_temp.txt" );
    while(getline(plik,linia)) {
        for( int i = 0 ; i < linia.length() ; i++ ) {
            if( linia[i] != '|')
                slowo += linia[i];
            else if( linia[i] == '|' ) {
                switch (numerSlowa) {
                case 0 :
                    tymczasoweId = slowo ;
                    id = atoi(tymczasoweId.c_str());
                    uzytkownik.id = id;
                    slowo = "";
                    numerSlowa++;
                    break;
                case 1 :
                    tymczasoweId = slowo ;
                    id = atoi(tymczasoweId.c_str());
                    uzytkownik.idLogujacego = id;
                    slowo = "";
                    numerSlowa++;
                    break;
                case 2 :
                    uzytkownik.imie = slowo;
                    slowo = "";
                    numerSlowa++;
                    break;
                case 3:
                    uzytkownik.nazwisko = slowo;
                    slowo = "";
                    numerSlowa++;
                    break;
                case 4:
                    uzytkownik.nrTelefonu = slowo;
                    slowo = "";
                    numerSlowa++;
                    break;
                case 5:
                    uzytkownik.email = slowo;
                    slowo = "";
                    numerSlowa++;
                    break;
                case 6:
                    uzytkownik.adres = slowo;
                    slowo = "";
                    numerSlowa++;
                    break;
                }

            }


        }
        if (uzytkownik.id != idUzytkownika) {

            plik2 << uzytkownik.id<< "|";
            plik2 << uzytkownik.idLogujacego<< "|";
            plik2 << uzytkownik.imie<< "|";
            plik2 << uzytkownik.nazwisko<<"|";
            plik2 << uzytkownik.nrTelefonu<<"|";
            plik2 << uzytkownik.email<<"|";
            plik2 << uzytkownik.adres<<"|"<<endl;
        }
        numerSlowa = 0;
    }
    plik.close();
    plik2.close();
    remove( "baza.txt");
    rename("baza_temp.txt","baza.txt");
}
void Rejestracja( vector <Logowanie> &zalogowani ){

    Logowanie logowanie;
    fstream plik;
    string linia;


    plik.open("logi.txt",ios::in);
    while(getline(plik,linia)) {
        logowanie.id ++;
    }
    plik.close();

    cout << "Panel Rejestracji: " << endl;
    cout << "-------------------\n" << endl;
    cout << "Podaj Login: " << endl;
    cin >> logowanie.login;
    cout << "Podaj haslo: " << endl;
    cin >> logowanie.haslo;

    zalogowani.push_back( logowanie );
    plik.open("logi.txt",ios::out | ios::app);

    plik << logowanie.id<<"|";
    plik << logowanie.login<<"|";
    plik << logowanie.haslo<<"|"<<endl;

    plik.close();

}
int Zaloguj(vector <Logowanie> &zalogowani, int &idZalogowanego) {

    string login, haslo;

    while(1) {
        system("cls");
        cout << "Podaj login: "<<endl;
        cin >> login;
        cout << "Podaj haslo: "<<endl;
        cin >>haslo;

        if (zalogowani.size() == 0) {
            cout << "Brak zarejestrowanych uzytkownikow. Zarejestruj sie i sprobuj ponownie."<< endl;
            Sleep(2000);
        } else {
            for ( int i = 0; i < zalogowani.size(); i++) {
                if (zalogowani[i].login == login && zalogowani[i].haslo == haslo) {
                    idZalogowanego = zalogowani[i].id;
                    cout << "Logowanie pomyslne !"<<endl;
                    Sleep(3000);
                    goto zalogowany;
                }
            }
            cout <<" Login lub haslo bledne. Wpisz poprawne dane. "<<endl;
            Sleep(3000);
        }
    }
zalogowany:
    return idZalogowanego;
}
void WczytajZalogowanych(vector <Logowanie> &zalogowani) {

    Logowanie logowanie;
    int id;
    int numerSlowa = 0;
    string linia,tymczasoweId;
    fstream plik;
    string slowo;

    plik.open("logi.txt",ios::in);
    if ( plik.good() == false )
        ofstream plik( "logi.txt" );
    while(getline(plik,linia)) {
        for( int i = 0 ; i < linia.length() ; i++ ) {
            if( linia[i] != '|')
                slowo += linia[i];
            else if( linia[i] == '|' ) {
                switch (numerSlowa) {
                case 0 :
                    tymczasoweId = slowo ;
                    id = atoi(tymczasoweId.c_str());
                    logowanie.id = id;
                    slowo = "";
                    numerSlowa++;
                    break;
                case 1 :
                    logowanie.login = slowo;
                    slowo = "";
                    numerSlowa++;
                    break;
                case 2:
                    logowanie.haslo = slowo;
                    slowo = "";
                    numerSlowa++;
                    break;
                }

            }
        }

        zalogowani.push_back( logowanie );
        numerSlowa = 0;

    }
    plik.close();
}
void WczytajUzytkownikow( vector <Uzytkownik> &uzytkownicy, int idZalogowanego ) {

    Uzytkownik uzytkownik;
    int id;
    int numerSlowa = 0;
    string linia,tymczasoweId;
    fstream plik;
    string slowo;

    uzytkownicy.clear();

    plik.open("baza.txt",ios::in);
    if ( plik.good() == false )
        ofstream plik( "baza.txt" );
    while(getline(plik,linia)) {
                for( int i = 0 ; i < linia.length() ; i++ ) {
                    if( linia[i] != '|')
                        slowo += linia[i];
                    else if( linia[i] == '|' ) {
                        switch (numerSlowa) {
                        case 0 :
                            tymczasoweId = slowo ;
                            id = atoi(tymczasoweId.c_str());
                            uzytkownik.id = id;
                            slowo = "";
                            numerSlowa++;
                            break;
                        case 1 :
                            tymczasoweId = slowo ;
                            id = atoi(tymczasoweId.c_str());
                            uzytkownik.idLogujacego = id;
                            slowo = "";
                            numerSlowa++;
                            break;
                        case 2 :
                            uzytkownik.imie = slowo;
                            slowo = "";
                            numerSlowa++;
                            break;
                        case 3:
                            uzytkownik.nazwisko = slowo;
                            slowo = "";
                            numerSlowa++;
                            break;
                        case 4:
                            uzytkownik.nrTelefonu = slowo;
                            slowo = "";
                            numerSlowa++;
                            break;
                        case 5:
                            uzytkownik.email = slowo;
                            slowo = "";
                            numerSlowa++;
                            break;
                        case 6:
                            uzytkownik.adres = slowo;
                            slowo = "";
                            numerSlowa++;
                            break;
                        }

                    }
                }

        if (uzytkownik.idLogujacego == idZalogowanego)
            uzytkownicy.push_back( uzytkownik );

        numerSlowa = 0;

    }
    plik.close();

}
void DodajUzytkownika( vector <Uzytkownik> &uzytkownicy, int idZalogowanego ) {

    Uzytkownik uzytkownik;
    fstream plik;
    string linia, tymczasoweId, slowo = "";
    int IdUzytkownika=1, id;

    plik.open("baza.txt",ios::in);
    if ( plik.good() == false )
        ofstream plik( "baza.txt" );
    while(getline(plik,linia)) {
        int numerLitery = 0;

        while ( linia[numerLitery] != '|'){
            slowo += linia[numerLitery];
            numerLitery++;
        }

        tymczasoweId = slowo ;
        id = atoi(tymczasoweId.c_str());
        slowo = "";
        if ( IdUzytkownika < id )
            IdUzytkownika = id;
    }
    plik.close();

    cout<<"Podaj imie: ";
    cin>>uzytkownik.imie;

    cout<<"Podaj nazwisko: ";
    cin>>uzytkownik.nazwisko;

    cout<<"Podaj numer telefonu: ";
    cin.sync();
    getline(cin,uzytkownik.nrTelefonu);

    cout<<"Podaj email :";
    cin>>uzytkownik.email;

    cout<<"Podaj adres: ";
    cin.sync();
    getline(cin,uzytkownik.adres);

    uzytkownik.idLogujacego = idZalogowanego;
    uzytkownik.id = ++IdUzytkownika;

    uzytkownicy.push_back( uzytkownik );


    plik.open("baza.txt",ios::out | ios::app);

    plik << uzytkownik.id<< "|";
    plik << uzytkownik.idLogujacego<<"|";
    plik << uzytkownik.imie<< "|";
    plik << uzytkownik.nazwisko<<"|";
    plik << uzytkownik.nrTelefonu<<"|";
    plik << uzytkownik.email<<"|";
    plik << uzytkownik.adres<<"|"<<endl;


    plik.close();
}
void WyswietlUzytkownika( vector <Uzytkownik> uzytkownicy, int idZalogowanego ) {

    if (uzytkownicy.size() == 0 )
        cout <<"Brak uzytkownikow\n"<<endl;
    else
        for ( int i=0; i < uzytkownicy.size() ; i++ ) {
            if (uzytkownicy[i].idLogujacego == idZalogowanego ) {
                cout<< "-------------------------" << endl;
                cout<< "Id: " << uzytkownicy[i].id << endl;
                cout<< "Imie: " << uzytkownicy[i].imie << endl;
                cout<< "Nazwisko: " << uzytkownicy[i].nazwisko << endl;
                cout<< "Numer telefonu: " << uzytkownicy[i].nrTelefonu << endl;
                cout<< "Email:" <<uzytkownicy[i].email << endl;
                cout<< "Adres: " <<uzytkownicy[i].adres << endl;
                cout<< "-------------------------" << endl;
            }
        }

}
void WyszukajUzytkownika( vector <Uzytkownik> uzytkownicy ) {
    char wybor;
    string nazwa;


    cout<<"1. Wyszukaj po imieniu"<<endl;
    cout<<"2. Wyszukaj po nazwisku"<<endl;
    cout<<"9. Cofnij"<<endl;

    cin>>wybor;

    switch(wybor) {
    case '1':

        cout<<"Podaj imie (z duzej litery): ";
        cin>>nazwa;
        for(int i=0; i<uzytkownicy.size(); i++) {
            if (uzytkownicy[i].imie==nazwa) {
                cout<<"-------------------------"<<endl;
                cout<<uzytkownicy[i].imie<<endl;
                cout<<uzytkownicy[i].nazwisko<<endl;
                cout<<uzytkownicy[i].nrTelefonu<<endl;
                cout<<uzytkownicy[i].email<<endl;
                cout<<uzytkownicy[i].adres<<endl;
                cout<<"-------------------------"<<endl;
            }

        }
        system("pause");
        break;
    case '2':

        cout<<"Podaj nazwisko (z duzej litery): ";
        cin>>nazwa;
        for(int i=0; i<uzytkownicy.size(); i++) {
            if (uzytkownicy[i].nazwisko==nazwa) {
                cout<<"-------------------------"<<endl;
                cout<<uzytkownicy[i].imie<<endl;
                cout<<uzytkownicy[i].nazwisko<<endl;
                cout<<uzytkownicy[i].nrTelefonu<<endl;
                cout<<uzytkownicy[i].email<<endl;
                cout<<uzytkownicy[i].adres<<endl;
                cout<<"-------------------------"<<endl;
            }

        }
        system("pause");
        break;
    case '9':
        break;
    }
}
void EdytujUzytkownika ( vector <Uzytkownik> &uzytkownicy ){
    char wybor,wyborZMenu;
    int idUzytkownika;
    string nowaWartosc;

    cout << "Podaj id uzytkownika : ";
    cin >> idUzytkownika;
    for (int i = 0; i < uzytkownicy.size(); i++){
        if ( idUzytkownika == uzytkownicy[i].id ){
            cout << "1.Imie" <<endl;
            cout << "2.Nazwisko" <<endl;
            cout << "3.Numer telefonu" <<endl;
            cout << "4.Email" <<endl;
            cout << "5.Adres" <<endl;
            cout << "9.Powrot do menu" <<endl;
            cout << "Ktore dane chcesz edytowac (wpisz odpowiednia liczbe): ";
            cin >> wyborZMenu;

            switch ( wyborZMenu ){
            case '1':
                {
                cout << "Obecna wartosc : "<< uzytkownicy[i].imie <<endl;
                cout << "Podaj nowa wartosc: ";
                cin.ignore();
                getline(cin,nowaWartosc);
                uzytkownicy[ i ].imie = nowaWartosc;
                ZaktualizujBaze( uzytkownicy );
                break;
                }
            case '2':
                {
                cout << "Obecna wartosc : "<< uzytkownicy[i].nazwisko <<endl;
                cout << "Podaj nowa wartosc: ";
                cin.ignore();
                getline(cin,nowaWartosc);
                uzytkownicy[ i ].nazwisko = nowaWartosc;
                ZaktualizujBaze( uzytkownicy );
                break;
                }
            case '3':
                {
                cout << "Obecna wartosc : "<< uzytkownicy[i].nrTelefonu <<endl;
                cout << "Podaj nowa wartosc: ";
                cin.ignore();
                getline(cin,nowaWartosc);
                uzytkownicy[ i ].nrTelefonu = nowaWartosc;
                ZaktualizujBaze( uzytkownicy );
                break;
                }
            case '4':
                {
                cout << "Obecna wartosc : "<< uzytkownicy[i].email <<endl;
                cout << "Podaj nowa wartosc: ";
                cin.ignore();
                getline(cin,nowaWartosc);
                uzytkownicy[ i ].email = nowaWartosc;
                ZaktualizujBaze( uzytkownicy );
                break;
                }
            case '5':
                {
                cout << "Obecna wartosc : "<< uzytkownicy[i].adres <<endl;
                cout << "Podaj nowa wartosc: ";
                cin.ignore();
                getline(cin,nowaWartosc);
                uzytkownicy[ i ].adres = nowaWartosc;
                ZaktualizujBaze( uzytkownicy );
                break;
                }
            case '9':
                break;
            }
        }
    }
}
void UsunUzytkownika (vector <Uzytkownik> &uzytkownicy, int idZalogowanego) {

    int idUzytkownika;
    char wybor;
    bool czyNalezyDoAdresowZalogowanego = false;

    cout << "Podaj id uzytkownika, ktorego chcesz usunac : ";
    cin >> idUzytkownika;
    cout << "Wybrales/as uzytkownika o id "<< idUzytkownika << ". Czy na pewno chcesz usunac dane o tej osobie ?"<<endl;
    cout << "(Jesli tak, wpisz 't'. Wpisujac cos innego zostaniesz przeniesiony do menu glownego"<<endl;
    cin >> wybor;
    if ( wybor == 't' ) {
        for ( int i = 0; i < uzytkownicy.size(); i++ ) {
            if ( uzytkownicy[i].id == idUzytkownika ) {
                if ( uzytkownicy[i].idLogujacego == idZalogowanego ) {
                    uzytkownicy.erase (uzytkownicy.begin() + i);
                    UsunIZaktualizujBaze( uzytkownicy, idUzytkownika);
                } else {
                    cout<< "Nie mozna usunac uzytkownika o wybranym id. Dane naleza do innego loginu" << endl;
                    system("pause");
                }
            }
        }

    }

}

int main() {

    char wybor;
    vector <Uzytkownik> uzytkownicy;
    vector <Logowanie> zalogowani;
    int idZalogowanego = 0;


    WczytajZalogowanych( zalogowani);
    wylogowanie:
    while(1) {
        system( "cls");
        cout<<"System logowania v.0.0.1"<<endl;
        cout<<"-------------------------"<<endl;
        cout<<"1. Logowanie"<<endl;
        cout<<"2. Rejestracja"<<endl;
        cout<<"9. Zamknij program"<<endl;

        cin >> wybor;

        switch(wybor) {
        case '1':
            system("cls");
            Zaloguj(zalogowani, idZalogowanego);
            goto doMenuKsiazkiAdresowej;
            break;
        case '2':
            system("cls");
            Rejestracja(zalogowani);
            system("pause");
            break;
        case '9':
            exit(0);
        }
    }
    doMenuKsiazkiAdresowej:
    WczytajUzytkownikow(uzytkownicy, idZalogowanego );

    while(1) {
        system("cls");
        cout<<"Ksiazka adresowa v.0.0.4"<<endl;
        cout<<"-------------------------"<<endl;
        cout<<"1. Dodaj uzytkownika"<<endl;
        cout<<"2. Wyswietl uzytkownikow"<<endl;
        cout<<"3. Wyszukaj uzytkownika"<<endl;
        cout<<"4. Edytuj uzytkownika"<<endl;
        cout<<"5. Usun uzytkownika"<<endl;
        cout<<"6. Wyloguj"<<endl;
        cout<<"9. Zakoncz\n"<<endl;


        cin>>wybor;

        switch(wybor) {
        case '1':
            system("cls");
            DodajUzytkownika( uzytkownicy, idZalogowanego );
            break;
        case '2':
            system("cls");
            WyswietlUzytkownika( uzytkownicy, idZalogowanego );
            system("pause");
            break;
        case '3':
            system("cls");
            WyszukajUzytkownika( uzytkownicy );
            break;
        case '4':
            system("cls");
            EdytujUzytkownika( uzytkownicy );
            break;
        case '5':
            system("cls");
            UsunUzytkownika( uzytkownicy, idZalogowanego );
            break;
         case '6':
            system("cls");
            goto wylogowanie;
            break;
        case '9':
            exit(0);
        }
    }
    return 0;
}
