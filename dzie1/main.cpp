#include <iostream>

using namespace std;

class Osoby
{
	public:		
		Osoby()
		{
			cout << "Dane Ucznia" << endl;
		}
		Osoby(string n) : nr_ucznia(n)
		{
			cout << "Kamil Kowalski" << endl;
			cout << "Numer w dzienniku: " << nr_ucznia << endl;
		}
		void funkcjaNauczyciel()
		{
			cout << "Nauczyciel: Piotr Kowalski" << endl;
		}

	private:
		string nr_ucznia;
};

class Uczen : public Osoby
{
	public:
		Uczen()
		{
			cout << "Personalne klasa" << endl;
		}
		Uczen(string n) : Osoby(n)
		{
			cout << "Klasa: 2pi" << endl;
		}
};



int main(int argc, char** argv) 
{
	Osoby a;
	Uczen nr("3") ;
	a.funkcjaNauczyciel();
	return 0;
}

