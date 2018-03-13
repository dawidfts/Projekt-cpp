#include <iostream>
#include <cstdlib>

using namespace std;

void wstep();
void sortowanie();
void autorzy();
void exite();

int main()
{
    int chois;
    while(true){
        cout << "***** Sortowanie Liczb całkowitych poprzez wybieranie i przez kopcowanie  *****" << endl;
        cout << "1. Wstep" << endl;
        cout << "2. Sortowanie" << endl;
        cout << "3. Autorzy" << endl;
        cout << "4. Wyjscie" << endl;

        cin>>chois;

        switch(chois){
            case 1: wstep();        break;
            case 2: sortowanie();   break;
            case 3: autorzy();      break;
            case 4: exite();        break;
            default: cout<<"Nie poprawna komenda"<< endl;
        }
    }

    return 0;
}

void wstep()
{

}

void sortowanie()
{

}

void autorzy()
{

}

void exite()
{
    exit(0);
}
