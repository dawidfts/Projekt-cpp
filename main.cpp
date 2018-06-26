#include <cstdlib>
#include <ctime>
#include <iostream>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "menu_functions.cpp"

long long int counter;

void insertionSort(long int arr[], int n, int m)
{
    int mode = m;
    std::clock_t start;
    double duration;
    start = std::clock();
    //long long int counter = 0;

    int key, j;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j-1;
            counter++;
            if(mode == 1)
            {
                system("cls");
                cout<<">> Algorytm przez wstawianie:\n"<<endl;
                printArray(arr,n);
                ///Sleep(1500);
            }
        }
        arr[j+1] = key;
    }
    if(mode == 0)
    {
        duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
        cout << "\nParametry otrzymane dla sortowania przez wstawianie:" << endl;
        std::cout << "- Czas operacji: " << duration << endl;
        cout << "- Wykonano " << counter << " operacji\n"<< endl;
        Sleep(1500);
    }
}

long int heapify (long int *tab, int heap_size, int i)
{
    int largest, temp;
    int l=2*i, r=(2*i)+1;
    if (l<=heap_size && tab[l]>tab[i])
        largest=l;
    else largest=i;
    if (r<=heap_size && tab[r]>tab[largest])
        largest=r;
    if (largest!=i){
        temp=tab[largest];
        tab[largest]=tab[i];
        tab[i]=temp;
        counter++;
        heapify(tab,heap_size,largest);
    }
    return 0;
}

void heap_sort(long int *tab, int rozmiar)
{
    std::clock_t start;
    double duration;
    start = std::clock();

    ///budowanie kopca
    for (int i=rozmiar/2; i>0; i--)
        heapify(tab,rozmiar, i);

    int temp;
    for (int i=rozmiar; i>1; i--){
        temp=tab[i];
        tab[i]=tab[1];
        tab[1]=temp;
        rozmiar--;
        counter++;
        heapify(tab,rozmiar,1);
    }
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    cout << "Parametry otrzymane dla sortowania przez heap-sort:" << endl;
    std::cout << "- Czas operacji: " << duration << endl;
    cout<<"- Wykonano " << counter <<" operacji"<<endl;
}

long int *fill_array(long int arr[], int n, int range)
{
    srand(time(0));
    std::fstream tab;

    tab.open("random.txt", ios :: out);
    if(tab.good() == true){
        ///cout <<"Dostep do pliku losujacego elementy" << endl;
        for (int i = 0; i < n; i++){
            arr[i] = rand()%range + 1;
            tab << arr[i] <<"\n";
        }
        return arr;

    }
    else{
        cout <<"Blad zwiazany z plikiem losujacym elementy" << endl;
        tab.close();
        return 0;
    }
}

void copy_array(long int arr[], long int arr_copy[], int n)
{
    for(int i = 0; i < n; i++)
        arr_copy[i] = arr[i];
    cout << endl;
}

int main(void)
{
    menu();
    return 0;
}

int menu()
{
    bool check = true;
    int user_choice;
    do{
        system("cls");
        cout << "\t\t\t\t| Menu |\n";
        cout << "Aby przejsc do wybranego punktu z wymienionych ponizej wpisz cyfre przypisana do opisu operacji.\n"<<endl;
        cout << "1. Symulacje\n";
        cout << "2. Autorzy\n";
        cout << "3. Wyjscie\n\n";
        cout << "Twoj wybor: ";
        cin >> user_choice;
        switch(user_choice)
        {
        case 1:
            menu_sortowanie();
            check = false;
            break;

        case 2:
            authors();
            check = true;
            break;
        case 3:
            return 0;
            check = false;
            break;
        default:
            cout << "Wprowadzono niepoprawna cyfre. Podaj jeszcze raz: ";
        }
    }
    while( check == true);
    return 0;
}

int menu_sortowanie()
{
    system("cls");
    cout <<"\t\t\t\t| Menu |\n\n";
    cout << "1. Klasyczne sortowanie \n";
    cout << "2. Symulacja krok po kroku\n";
    cout << "3. \n";
    cout << "4. \n\n";
    cout << "Twoj wybor: ";
    int user_choice;
    bool check = true;
    do{
        cin >> user_choice;
        switch(user_choice){
            case 1:
                classic_sort();
                check = false;
                break;
            case 2:
                ///step_by_step();
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
    }
    while( check == true);
    return 0;
}

int classic_sort()
{
    system("cls");
    cout << "W klasycznym sortowaniu zostana wygenerowane tablice o roznych pojemnosciach\n";
    cout << "liczbami losowymi i posortowane obydwoma algorytmami a wyniki zostana wyswietlone" << endl;
    int n;
    cout <<"\nPodaj pojemnosc tablicy: ";
    cin >> n;
    cout <<"\n"<<endl;

    long int *arr = new long int[n];
    long int *arr_copy = new long int[n];

    fill_array(arr, n, 1000);
    copy_array(arr, arr_copy, n+1);

    counter = 0;
    heap_sort (arr_copy, n);

    counter = 0;
    insertionSort(arr, n, 0);
    //delete[] arr;
    //delete[] arr_copy;
    return 0;
}
/*
void step_by_step()
{
    long int arr[10];
    fill_array(arr, 10, 100);
    system("cls");
    cout<<"Animacja algorytmow sortowania na tablicach o 10 elementach.\n"<<endl;
    printArray(arr, 10);
    system("pause");
    system("cls");
    cout<<">> Algorytm przez wstawienie:\n"<<endl;
    insertionSort(arr, 10, 1);

    system("pause");

    fill_array(arr, 10, 100);
    system("cls");
    cout<<">> Algorytm Hip - Sort:\n"<<endl;
    printArray(arr, 10);
    system("pause");
    system("cls");
    cout<<">> Algorytm przez wstawienie:\n"<<endl;
    sortowanie(arr, 10);

}
*/
void authors()
{
    system("cls");
    cout <<"Algorytmy i struktury danych"<<endl;
    cout <<"Projekt"<<endl;
    cout <<"Temat: Sortwanie przez wstawianie i kopcowanie"<<endl;
    cout <<"Autorzy: Dawid Grzelczyk, Katarzyna Dawiec"<<endl;
    cout <<"Kielce, 2018"<<endl;
    system("pause");
}

void printArray(long int arr[], int n)
{
    for (int i=0; i < n; i++)
        cout<<arr[i] << " ";
    cout <<  endl ;
}
