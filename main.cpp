#include <cstdlib>
#include <ctime>
#include <iostream>

#include "menu_functions.cpp"

void insertionSort(int arr[], int n)
{
   int key, j, counter = 0;
   for (int i = 1; i < n; i++){
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

/*void heapSort(int d[], int n)
{
    int j,k,x;
    for(int i = 2; i <= n; i++){
        j = i; k = j / 2;
        x = d[i];
        while((k > 0) && (d[k] < x)){
            d[j] = d[k];
            j = k; k = j / 2;
        }
        d[j] = x;
    }
}*/

int *fill_array(int arr[], int n)
{
    srand(time(0));
    for (int i = 0; i < n; i++){
       arr[i] = rand()%1000+1;
    }
    return arr;
}

void copy_array(int arr[], int arr_copy[], int n)
{
    for(int i = 0; i < n; i++){
        arr_copy[i] = arr[i];
    }
}

void printArray(int arr[], int n)
{
   for (int i=0; i < n; i++)
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

int operation()
{
    bool check = true;
    int user_choice;
    cout << "Menu\nAby przejsc do wybranego punktu z wymienionych ponizej wpisz cyfre przypisana do opisu operacji.\n"
         "1. Czesc teoretyczna\n2. Symulacje\n3. Autorzy\n4. Wyjscie\n\nTwoj wybor: ";
    do{
        cin >> user_choice;
        switch(user_choice){
            case 1:
                read_theory();  check = false;break;
            case 2:
                sortowanie();   check = false;  break;
            case 3:
                cout << "3";    check = false;  break;
            case 4:
                return 0;   check = false;  break;
            default:
                    cout << "Wprowadzono niepoprawna cyfre. Podaj jeszcze raz: ";
    }
    }while( check == true);
}

int main(void)
{
    operation();
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
                classic();  check = false;  break;
            case 2:
                cout << "2";    check = false;  break;
            case 3:
                cout << "3";    check = false;  break;
            case 4:
                return 0;   check = false;  break;
            default:
                    cout << "Wprowadzono niepoprawna cyfre. Podaj jeszcze raz: ";
    }
    }while( check == true);
}

int classic()
{
    cout << "W klasycznym sortowaniu zostan¹ wygenerowane tablice o roznych pojemnosciach liczbami losowymi\n"
        "i posortowane oby dwoma algorytmami a winiki zostana wyswietlone"<<endl;
    int n = 100;
    int arr[n]; //arr_copy[n];
    fill_array(arr, n);
    //copy_array(arr, arr_copy, n);
    cout <<"Tablica o wielkosci 100 elementow zostala wypelniona...\n"<<endl;
    //insertionSort(arr, n);
    //printArray(arr_copy, 100);
    //heapSort(arr_copy, n);
    cout <<"Posortowana tablica\n"<<endl;
    //printArray(arr_copy, 100);
    return 0;
}
