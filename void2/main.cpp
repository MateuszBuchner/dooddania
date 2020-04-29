#include <iostream>
#include <vector>
#include <fstream>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

struct uczen
{
        string imie, nazwisko, adres, pesel;
        int numer;
};


void menu()
    {
    	cout<<"\n1.Wprowadz\n";
    	cout<<"2.Wypisz\n";
    	cout<<"3.Zapisz do pliku \n";
    	cout<<"4.Wczytaj z pliku \n";
}

class klasa
{
                vector <struct uczen> spis;
       
        public:
                void wprowadz();
                void wypisz();
                void zapiszDoPliku(const char *);
                void wczytajZPliku(const char *);                
};

void klasa::wprowadz()
{
        int iloscUczniow;
        struct uczen wprowadzany;
        cout << "Ilosc uczniow: ";
        cin  >> iloscUczniow;
        for (int i=0; i<iloscUczniow; i++)
        {
                cout << "Nr Imie Nazwisko Adres Pesel: ";
                cin >> wprowadzany.numer
                        >> wprowadzany.imie
                        >> wprowadzany.nazwisko
                        >> wprowadzany.adres
                        >> wprowadzany.pesel;
                spis.push_back(wprowadzany); //TU WSTAW do tablicy nowy rekord
        }
}


void klasa::wypisz()
{
        for (vector<struct uczen>::iterator it = spis.begin(); it != spis.end(); ++it)
        {
                cout
						 << it->numer << " "
                         << it->imie << " "
                         << it->nazwisko << " "
						 << it->adres << " "
						 << it->pesel << "\n";
        }
}



void klasa::zapiszDoPliku(const char *nazwa)
{
        ofstream plik;
        plik.open(nazwa);
        for (vector<struct uczen>::iterator it = spis.begin(); it != spis.end(); ++it)
        {
                plik
						 << it->numer << " "
                         << it->imie << " "
                         << it->nazwisko << " "
						 << it->adres << " "
						 << it->pesel << "\n";
        }
        plik.close();  
}


void klasa::wczytajZPliku(const char *nazwa)
{
    fstream plik("plik.txt", ios::in | ios::out);
    string dane;
    getline(plik, dane);
    cout<<endl<<dane;
}



int main(int argc, char** argv) {
	
	
        klasa TI;
        int wybor;
        do
        {
            menu();
            cin >> wybor;
            switch(wybor)
            {
                case 1:
        			TI.wprowadz();
                break;
                case 2:
        			TI.wypisz();
                break;
                case 3:
        			TI.zapiszDoPliku("plik.txt");
                    break;
                case 4:
        			TI.wczytajZPliku("plik.txt");
                break;

                case 0:
                    return 0;
                break;
            }
        }while(wybor!=0);
        
        
        return 0;
	
	
}


