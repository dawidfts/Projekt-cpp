#include <cstdlib>
#include <ctime>
#include <iostream>

#include "menu_functions.cpp"

#define HOW_MANY_ELEMENTS_TO_PRINT 30

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
    cout << "Wykonano " << counter << " operacji\n"<< endl;
}

void heapSort(long int arr_copy[], int n)
{
    std::clock_t start_h;
    double duration_h;

    start_h = std::clock();

    long long int counter_h = 0;
    int j,k,x;
    cout << arr_copy[n] << endl;
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
       /// cout << arr_copy[i] << endl;
    }
    cout << endl;
}

void printArray(long int arr[], int n)
{
   for (int i=0; i < n; i++)
   {
        cout << arr[i] << " ";
   }
    cout <<  endl ;
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
    cout << "\t\t\t\t| Menu |\n";
    cout << "Aby przejsc do wybranego punktu z wymienionych ponizej wpisz cyfre przypisana do opisu operacji.\n";
    cout << "1. Czesc teoretyczna\n";
    cout << "2. Symulacje\n";
    cout << "3. Autorzy\n";
    cout << "4. Wyjscie\n\n";
    cout << "Twoj wybor: ";
    do{
        cin >> user_choice;
        switch(user_choice){
            case 1:
                read_theory();
                check = false;
                break;

            case 2:
                menu_sortowanie();
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
    return 0;
}

int menu_sortowanie()
{
    system("cls");
    cout <<"\t\t\t\t| Menu |\n\n";
    cout << "1. Klasyczne sortowanie \n";
    cout << "2. \n";
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
    return 0;
}
void print_before(int n, long int *arr)
{
    if(n <= HOW_MANY_ELEMENTS_TO_PRINT)
    {
        cout << "Zawartosc tablicy przed posortowaniem: " << endl;
        cout << endl;
        printArray(arr, n);
        cout << endl;
        cout << endl;
    }
}
void print_after(int n, long int *arr)
{
    if(n <= HOW_MANY_ELEMENTS_TO_PRINT)
    {
        cout << "Zawartosc tablicy po posortowaniu: " << endl;
        cout << endl;
        printArray(arr, n);
    }
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

    long int arr[n], arr_copy[n];
    fill_array(arr, n);
    copy_array(arr, arr_copy, n);
    //print_before(n, arr);
    insertionSort(arr, n);
    heapSort(arr_copy, n);
   // print_after(n, arr);
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
