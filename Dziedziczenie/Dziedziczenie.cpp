#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Osoba
{

        string imie;
        string nazwisko;
public:
    Osoba(string i="",string n="")
    {
        imie=i;
        nazwisko=n;
    }

    void wypisz() 
    {
        cout <<"Imie: " <<imie <<"\n"<< "Nazwisko: " << nazwisko;
    }
};

class Ksiazka
{
    string tytul;
    Osoba autor;

public:
    Ksiazka(string t,Osoba a)
    {   
        tytul =t;
        autor = a;
    }
    
    void wypisz()
    {
       cout << "Tytul ksiazki: " << tytul <<endl<<endl ;
       cout << "...Autor... " << endl;
       autor.wypisz();
    }
};

class Czytelnik: public Osoba
{
public:
    vector<Ksiazka> listaksiazek;

    Czytelnik(string im, string na) :Osoba(im, na)
    {
    }

   void wypiszKsiazki()
   {
       Osoba::wypisz();
       cout <<"\nZostaly przeczytane: "<< listaksiazek.size()<<" ksiazki\n";
       for (auto a = 0; a < 3; a++)
       {
           cout << endl;
           listaksiazek[a].wypisz();
           cout << endl;
       }
       
   }


};

int main()
{
    cout << "Program Dziedziczenie!\n";

    Osoba a1("Boleslaw", "Chrobry");
    Osoba a2("Czeslaw", "Czapka");
    Osoba a3("Antoni", "Macierewicz");

    Ksiazka k1("Ogniem i Mieczem", a1);
    Ksiazka k2("Harry Poter", a2);
    Ksiazka k3("Olimp w Ogniu", a1);
    Ksiazka k4("Oculus", a2);
    Ksiazka k5("Jak zakupilem F-16", a3);

    Czytelnik c1("Ziemowit", "Trabka");
    Czytelnik c2("Andzrej", "Duda");
    Czytelnik c3("Slawomir", "Nitras");

    c1.listaksiazek.push_back(k2);
    c1.listaksiazek.push_back(k5);
    c1.listaksiazek.push_back(k1);

    c2.listaksiazek.push_back(k3);
    c2.listaksiazek.push_back(k1);
    c2.listaksiazek.push_back(k2);

    c3.listaksiazek.push_back(k4);
    c3.listaksiazek.push_back(k3);
    c3.listaksiazek.push_back(k1);

    cout << "+++++++++++++++++++++++++++++++++++++++"<< endl;

    c1.wypiszKsiazki();

    cout << "+++++++++++++++++++++++++++++++++++++++"<< endl;

    c2.wypiszKsiazki();

    cout << "+++++++++++++++++++++++++++++++++++++++"<< endl;

    c3.wypiszKsiazki();

   
}
