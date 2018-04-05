#include <iostream>
#include <cstdio>
#include <string>

#include "menu_functions.cpp"

int print_headers(void)
{
    int user_choice;
    cout << "Menu\nAby przejsc do wybranego punktu z wymienionych ponizej wpisz cyfre przypisana do opisu operacji.\n"
         "1. Czesc teoretyczna\n2. Symulacje\n3. Autorzy\n4. Wyjscie\n\nTwoj wybor: ";
    cin >> user_choice;
    return user_choice;
}

void read_theory()
{
    fstream theory;
    theory.open("theory.txt", ios :: in);
    if(theory.good() == true)
    {
        cout << "dostep do pliku\n";
        string text;
        getline(theory,text);
        cout << text;
    }
    else
    {
        cout << "blad dostepu do pliku";
    }


}

int operation(int user_choice)
{
    bool check = true;
    while( check == true)
    {
        switch(user_choice)
        {
        case 1:
            read_theory();
            check = false;
            break;
        case 2:
            cout << "2";
            check = false;
            break;
        case 3:
            cout << "3";
            check = false;
            break;
        case 4:
            return 0;
            check = false;
            break;
        default:
            do
            {
                cout << "Wprowadzono niepoprawna cyfre. Podaj jeszcze raz: ";
                cin >> user_choice;
                if(user_choice < 5)
                {
                    check = true;
                }
            }
            while(user_choice > 4);
        }
    }
}



int main(void)
{
    operation(print_headers());
    return 0;
}
