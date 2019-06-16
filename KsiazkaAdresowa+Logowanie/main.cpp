#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

struct Uzytkownik {
    int id = 0;
    int idLogujacego;
    string imie = "";
    string nazwisko = "";
    string nrTelefonu = "";
    string email = "";
    string adres = "";
};
struct Logowanie {
    int id = 0;
    string login = "" ;
    string haslo = "" ;
};
void Rejestracja( vector <Logowanie> &zalogowani ){

    Logowanie logowanie;
    fstream plik;
    string linia;

    plik.open("logi.txt",ios::in);
    if ( plik.good() == false )
        ofstream plik( "logi.txt" );
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
int Zaloguj(vector <Logowanie> zalogowani, int idZalogowanego){

    string login, haslo;

    while(1){
    system("cls");
    cout << "Podaj login: "<<endl;
    cin >> login;
    cout << "Podaj haslo: "<<endl;
    cin >>haslo;

    if (zalogowani.size() == 0){
        cout << "Brak zarejestrowanych uzytkownikow. Zarejestruj sie i sprobuj ponownie."<< endl;
        Sleep(2000);
    }
    else {
        for ( int i = 0; i < zalogowani.size(); i++) {
            if (zalogowani[i].login == login && zalogowani[i].haslo == haslo) {
                cout << "Logowanie pomyslne !"<<endl;
                Sleep(5000);
                goto zalogowany;
            } else
                cout <<" Login lub haslo bledne. Wpisz poprawne dane "<<endl;
            }
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
void WczytajUzytkownikow( vector <Uzytkownik> &uzytkownicy ) {

    Uzytkownik uzytkownik;
    int id;
    int numerSlowa = 0;
    string linia,tymczasoweId;
    fstream plik;
    string slowo;

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
                    uzytkownik.imie = slowo;
                    slowo = "";
                    numerSlowa++;
                    break;
                case 2:
                    uzytkownik.nazwisko = slowo;
                    slowo = "";
                    numerSlowa++;
                    break;
                case 3:
                    uzytkownik.nrTelefonu = slowo;
                    slowo = "";
                    numerSlowa++;
                    break;
                case 4:
                    uzytkownik.email = slowo;
                    slowo = "";
                    numerSlowa++;
                    break;
                case 5:
                    uzytkownik.adres = slowo;
                    slowo = "";
                    numerSlowa++;
                    break;
                }

            }
        }

        uzytkownicy.push_back( uzytkownik );
        numerSlowa = 0;

    }
    plik.close();

}
void DodajUzytkownika( vector <Uzytkownik> &uzytkownicy ) {

    Uzytkownik uzytkownik;

    if (uzytkownicy.size() == 0 ){
        uzytkownik.id = 1;
    }
    else{
        uzytkownik.id = uzytkownicy.size() + 1;
        for (int i = 0; i < uzytkownicy.size(); i++){
            if (uzytkownik.id < uzytkownicy[i].id){
                uzytkownik.id = uzytkownicy[i].id;
                uzytkownik.id++;
            }
        }
    }
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

    uzytkownicy.push_back( uzytkownik );

    fstream plik;
    plik.open("baza.txt",ios::out | ios::app);

    plik << uzytkownik.id<< "|";
    plik << uzytkownik.imie<< "|";
    plik << uzytkownik.nazwisko<<"|";
    plik << uzytkownik.nrTelefonu<<"|";
    plik << uzytkownik.email<<"|";
    plik << uzytkownik.adres<<"|"<<endl;

    plik.close();
}
void WyswietlUzytkownika( vector <Uzytkownik> uzytkownicy ) {
    if (uzytkownicy.size() == 0 )
        cout <<"Brak uzytkownikow\n"<<endl;
    else
        for ( int i=0; i < uzytkownicy.size() ; i++ ) {

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
                fstream plik;
                plik.open( "baza.txt",ios::out );

                for (int j = 0; j < uzytkownicy.size(); j++) {
                    plik << uzytkownicy[j].id<< "|";
                    plik << uzytkownicy[j].imie<< "|";
                    plik << uzytkownicy[j].nazwisko<<"|";
                    plik << uzytkownicy[j].nrTelefonu<<"|";
                    plik << uzytkownicy[j].email<<"|";
                    plik << uzytkownicy[j].adres<<"|"<<endl;
                }
                plik.close();
                break;
                }
            case '2':
                {
                cout << "Obecna wartosc : "<< uzytkownicy[i].nazwisko <<endl;
                cout << "Podaj nowa wartosc: ";
                cin.ignore();
                getline(cin,nowaWartosc);
                uzytkownicy[ i ].nazwisko = nowaWartosc;
                fstream plik;
                plik.open( "baza.txt",ios::out );

                for (int j = 0; j < uzytkownicy.size(); j++) {
                    plik << uzytkownicy[j].id<< "|";
                    plik << uzytkownicy[j].imie<< "|";
                    plik << uzytkownicy[j].nazwisko<<"|";
                    plik << uzytkownicy[j].nrTelefonu<<"|";
                    plik << uzytkownicy[j].email<<"|";
                    plik << uzytkownicy[j].adres<<"|"<<endl;
                }
                plik.close();
                break;
                }
            case '3':
                {
                cout << "Obecna wartosc : "<< uzytkownicy[i].nrTelefonu <<endl;
                cout << "Podaj nowa wartosc: ";
                cin.ignore();
                getline(cin,nowaWartosc);
                uzytkownicy[ i ].nrTelefonu = nowaWartosc;
                fstream plik;
                plik.open( "baza.txt",ios::out );

                for (int j = 0; j < uzytkownicy.size(); j++) {
                    plik << uzytkownicy[j].id<< "|";
                    plik << uzytkownicy[j].imie<< "|";
                    plik << uzytkownicy[j].nazwisko<<"|";
                    plik << uzytkownicy[j].nrTelefonu<<"|";
                    plik << uzytkownicy[j].email<<"|";
                    plik << uzytkownicy[j].adres<<"|"<<endl;
                }
                plik.close();
                break;
                }
            case '4':
                {
                cout << "Obecna wartosc : "<< uzytkownicy[i].email <<endl;
                cout << "Podaj nowa wartosc: ";
                cin.ignore();
                getline(cin,nowaWartosc);
                uzytkownicy[ i ].email = nowaWartosc;
                fstream plik;
                plik.open( "baza.txt",ios::out );

                for (int j = 0; j < uzytkownicy.size(); j++) {
                    plik << uzytkownicy[j].id<< "|";
                    plik << uzytkownicy[j].imie<< "|";
                    plik << uzytkownicy[j].nazwisko<<"|";
                    plik << uzytkownicy[j].nrTelefonu<<"|";
                    plik << uzytkownicy[j].email<<"|";
                    plik << uzytkownicy[j].adres<<"|"<<endl;
                }
                plik.close();
                break;
                }
            case '5':
                {
                cout << "Obecna wartosc : "<< uzytkownicy[i].adres <<endl;
                cout << "Podaj nowa wartosc: ";
                cin.ignore();
                getline(cin,nowaWartosc);
                uzytkownicy[ i ].adres = nowaWartosc;
                fstream plik;
                plik.open( "baza.txt",ios::out );

                for (int j = 0; j < uzytkownicy.size(); j++) {
                    plik << uzytkownicy[j].id<< "|";
                    plik << uzytkownicy[j].imie<< "|";
                    plik << uzytkownicy[j].nazwisko<<"|";
                    plik << uzytkownicy[j].nrTelefonu<<"|";
                    plik << uzytkownicy[j].email<<"|";
                    plik << uzytkownicy[j].adres<<"|"<<endl;
                }
                plik.close();
                break;
                }
            case '9':
                break;
            }
        }
    }
}
void UsunUzytkownika (vector <Uzytkownik> &uzytkownicy){

    int idUzytkownika;
    char wybor;

    cout << "Podaj id uzytkownika, ktorego chcesz usunac : ";
    cin >> idUzytkownika;
    cout << "Wybrales/as uzytkownika o id "<< idUzytkownika << ". Czy na pewno chcesz usunac dane o tej osobie ?"<<endl;
    cout << "(Jesli tak, wpisz 't'. Wpisujac cos innego zostaniesz przeniesiony do menu glownego"<<endl;
    cin >> wybor;
    if ( wybor == 't' ){
        for ( int i = 0; i < uzytkownicy.size(); i++ ){
            if ( uzytkownicy[i].id == idUzytkownika ){
               uzytkownicy.erase (uzytkownicy.begin() + i);
            }
        }
      fstream plik;
                plik.open( "baza.txt",ios::out );

                for (int j = 0; j < uzytkownicy.size(); j++) {
                    plik << uzytkownicy[j].id<< "|";
                    plik << uzytkownicy[j].imie<< "|";
                    plik << uzytkownicy[j].nazwisko<<"|";
                    plik << uzytkownicy[j].nrTelefonu<<"|";
                    plik << uzytkownicy[j].email<<"|";
                    plik << uzytkownicy[j].adres<<"|"<<endl;
                }
                plik.close();
    }

}
int main() {

    char wybor;
    vector <Uzytkownik> uzytkownicy;
    vector <Logowanie> zalogowani;
    int idZalogowanego;

    WczytajUzytkownikow(uzytkownicy);
    while(1) {
        system("cls");
        cout<<"Ksiazka adresowa v.0.0.3"<<endl;
        cout<<"-------------------------"<<endl;
        cout<<"1. Dodaj uzytkownika"<<endl;
        cout<<"2. Wyswietl uzytkownikow"<<endl;
        cout<<"3. Wyszukaj uzytkownika"<<endl;
        cout<<"4. Edytuj uzytkownika"<<endl;
        cout<<"5. Usun uzytkownika"<<endl;
        cout<<"9. Zakoncz\n"<<endl;


        cin>>wybor;

        switch(wybor) {
        case '1':
            system("cls");
            DodajUzytkownika(uzytkownicy);
            break;
        case '2':
            system("cls");
            WyswietlUzytkownika(uzytkownicy);
            system("pause");
            break;
        case '3':
            system("cls");
            WyszukajUzytkownika(uzytkownicy);
            break;
        case '4':
            system("cls");
            EdytujUzytkownika(uzytkownicy);
            break;
        case '5':
            system("cls");
            UsunUzytkownika(uzytkownicy);
            break;
        case '9':
            exit(0);
        }
    }
    return 0;
}
