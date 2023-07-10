#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <unordered_map>
using namespace std;


void SelectionSort(vector<int>& arr) 
{
    int n = arr.size();
    for (int i = 0; i < n ; ++i) 
    {
        for (int j = i; j < n ; ++j) 
        {
            if (arr[j] < arr[i]) 
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void BubbleSort(vector<int>& arr)
{
    int n = arr.size();
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void InsertionSort(vector<int>& arr)
{
    int n = arr.size();
    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


void shellSort(std::vector<int>& arr) 
{
    int n = arr.size();
    int gap = n / 2;

    while (gap > 0) 
    {
        for (int i = gap; i < n; i++) 
        {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) 
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
        gap /= 2;
    }
}

// Función para combinar dos subarreglos ordenados en un solo arreglo ordenado
void merge(vector<int>& arr, int left, int middle, int right) 
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    //Crear arreglos temporales para los subarreglos izquierdo y derecho
    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    //Copiar los elementos a los arreglos temporales
    for (int i = 0; i < n1; i++) 
    {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) 
    {
        rightArr[j] = arr[middle + 1 + j];
    }

                        //Combinar los arreglos temporales en uno solo en orden ascendente
    int i = 0;         //indice inicial del subarreglo izquierdo
    int j = 0;        //indice inicial del subarreglo derecho
    int k = left;   //indice inicial del subarreglo combinado

    while (i < n1 && j < n2) 
    {
        if (leftArr[i] <= rightArr[j]) 
        {
            arr[k] = leftArr[i];
            i++;
        } 
        else 
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    //Copiar los elementos restantes del subarreglo izquierdo (si los hay)
    while (i < n1) 
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    //Copiar los elementos restantes del subarreglo derecho (si los hay)
    while (j < n2) 
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Función recursiva para dividir y ordenar el arreglo en subarreglos más pequeños
void MergeSort(vector<int>& arr, int left, int right) 
{
    if (left < right) 
    {
        int middle = left + (right - left) / 2;

        // Ordenar el subarreglo izquierdo
        MergeSort(arr, left, middle);

        // Ordenar el subarreglo derecho
        MergeSort(arr, middle + 1, right);

        // Combinar los subarreglos ordenados
        merge(arr, left, middle, right);
    }
}

// Función para colocar el pivote en su posición correcta
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Función recursiva para ordenar el arreglo utilizando Quick Sort
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        // Ordenar los elementos antes y después del pivote
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

//determina el resultado en tiempo de los algoritmos de ordenamiento
double getResultFromAlg(vector<int>& arr,int option) 
{
    time_t start, end;
    double time_taken;
    time(&start);
    ios_base::sync_with_stdio(false);
    //llamar a los 7 algoritmos de ordenamiento
    time(&end);
    time_taken = double(end - start);
    return time_taken;
}

int main()
{

    unordered_map<string, double> results;

    cout << "Generando set de datos: " << endl;

    vector <int> puntaje;
    random_device random;
    mt19937 gen(random());
    uniform_int_distribution<int> dis(90000, 100000);


    vector<int> arr = {9, 5, 1, 4, 3, 2, 8, 7, 6};
    BubbleSort(arr);
    cout << "Array ordenado bublesort: ";
    for (int num : arr) 
    {
        cout << num << " ";
    }
    cout << std::endl;

   /* resultados del algoritmo
   for (const auto& pair : results) 
   {
        const string& key = pair.first;
        double value = pair.second;
        cout << id << ". " << key << ", " << fixed << value << setprecision(5)
        << endl;
        id++;
   }
    */

    return 0;
}