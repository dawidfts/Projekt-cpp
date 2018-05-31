#include <cstdlib>
#include <ctime>
#include <iostream>

#include "menu_functions.cpp"

void insertionSort(long int arr[], int n)
{
    std::clock_t start;
    double duration;

    start = std::clock();
    long long int counter = 0;
    int key, j;
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
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    cout << "Parametry otrzymane dla sortowania przez wstawianie: \n" << endl;
    std::cout << "\nCzas operacji: " << duration << endl;
    cout << "Wykonano " << counter << " operacji\n"<< endl;//
}

void heapSort(long int arr_copy[], int n)
{
    std::clock_t start_h;
    double duration_h;

    start_h = std::clock();

    long long int counter_h = 0;
    int j,k,x;
    for(int i = 2; i <= n; i++){
        j = i; k = j / 2;
        x = arr_copy[i];
        while((k > 0) && (arr_copy[k] < x)){
            arr_copy[j] = arr_copy[k];
            j = k; k = j / 2;
        }
        arr_copy[j] = x;
    }
    duration_h = (std::clock() - start_h ) / (double) CLOCKS_PER_SEC;
    cout << "Parametry otrzymane dla sortowania przez kopcowanie: \n" << endl;
    std::cout << "\nCzas operacji: "<< duration_h << endl;
    cout << "Wykonano: "<< counter_h << " operacji\n" << endl;
}

long int *fill_array(long int arr[], int n)
{
    srand(time(0));
    for (int i = 0; i < n; i++){
       arr[i] = rand()%1000+1;
    }
    return arr;
}

void copy_array(long int arr[], long int arr_copy[], int n)
{
    for(int i = 0; i < n; i++){
        arr_copy[i] = arr[i];
    }
}

void printArray(long int arr[], int n)
{
   for (int i=0; i < n; i++)
        cout << arr[i] << endl;
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
    cout << "\t\t\t\t| Menu |\n\nAby przejsc do wybranego punktu z wymienionych ponizej wpisz cyfre przypisana do opisu operacji.\n"
         "\n1. Czesc teoretyczna\n2. Symulacje\n3. Autorzy\n4. Wyjscie\n\nTwoj wybor: ";
    do{
        cin >> user_choice;
        switch(user_choice){
            case 1:
                read_theory();  check = false;break;
            case 2:
                menu_sortowanie();   check = false;  break;
            case 3:
                cout << "3";    check = false;  break;
            case 4:
                return 0;   check = false;  break;
            default:
                    cout << "Wprowadzono niepoprawna cyfre. Podaj jeszcze raz: ";
    }
    }while( check == true);
    return 0;
}

int menu_sortowanie()
{
    system("cls");
    cout <<"\t\t\t\t| Menu |\n\n1. Klasyczne sortowanie \n2. \n3. \n4. \n\nTwoj wybor: ";
    int user_choice;
    bool check = true;
    do{
        cin >> user_choice;
        switch(user_choice){
            case 1:
                classic_sort();  check = false;  break;
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
    return 0;
}

int classic_sort()
{
    system("cls");
    cout << "W klasycznym sortowaniu zostana wygenerowane tablice o roznych pojemnosciach\n"
        "liczbami losowymi i posortowane obydwoma algorytmami a wyniki zostana wyswietlone"<<endl;
    int n;
    cout <<"\nPodaj pojemnosc tablicy: ";
    cin >> n;
    cout <<"\n"<<endl;

    long int arr[n], arr_copy[n];
    fill_array(arr, n);
    copy_array(arr, arr_copy, n);
    insertionSort(arr, n);
    heapSort(arr_copy, n);
    //printArray(arr, n);
    return 0;
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
