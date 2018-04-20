#include <cstdlib>
#include <ctime>
#include <iostream>

#include "menu_functions.cpp"

int sortowanie();
int classic();

int print_headers(void)
{
    int user_choice;
    cout << "Menu\nAby przejsc do wybranego punktu z wymienionych ponizej wpisz cyfre przypisana do opisu operacji.\n"
         "1. Czesc teoretyczna\n2. Symulacje\n3. Autorzy\n4. Wyjscie\n\nTwoj wybor: ";
    return user_choice;
}

void insertionSort(int arr[], int n)
{
   int key, j, counter = 0;
   for (int i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
       while (j >= 0 && arr[j] > key){
           arr[j+1] = arr[j];
           j = j-1;
           counter++;
       }
       arr[j+1] = key;
   }
   cout<<"\nWykonano "<<counter<<" operacji"<<endl;
}

int *fill_array(int arr[], int n)
{
    srand(time(0));
    for (int i = 0; i < n; i++)
   {
       arr[i] = rand()%1000+1;
   }
   return arr;
}

void printArray(int arr[], int n)
{
   int i;
   for (i=0; i < n; i++)
        cout << arr[i] << endl;
}

void read_theory()
{
    fstream theory;
    theory.open("theory.txt", ios :: in);
    if(theory.good() == true){
        cout << "dostep do pliku\n";
        string text;
        getline(theory,text);
        cout << text;
    }
    else{
        cout << "blad dostepu do pliku";
    }
}

int operation(int user_choice)
{
    bool check = true;
    do{
        cin >> user_choice;
        switch(user_choice){
        case 1:
            read_theory();
            check = false;
            break;
        case 2:
            sortowanie();
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
                cout << "Wprowadzono niepoprawna cyfre. Podaj jeszcze raz: ";
    }
    }while( check == true);
}

int main(void)
{
    operation(print_headers());
    return 0;
}

int sortowanie()
{
    cout <<"1. Klasyczne sortowanie \n2. \n3. \n4. \n\nTwoj wybor: "<<endl;
    int user_choice;
    bool check = true;
    do{
        cin >> user_choice;
        switch(user_choice){
        case 1:
            classic();
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
                cout << "Wprowadzono niepoprawna cyfre. Podaj jeszcze raz: ";
    }
    }while( check == true);
}

int classic()
{
    int arr[100];
    fill_array(arr, 100);
    cout <<"Wygenerowana tablica\n"<<endl;
    printArray(arr, 100);
    insertionSort(arr, 100);
    cout <<"Posortowana tablica\n"<<endl; //test2
    printArray(arr, 100);
}
