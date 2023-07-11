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
#include <ctime>
#include <iomanip>
#include <set>
#include<random>
using namespace std;

//comparacion de dos elementos para orden descendente
bool compare(int a, int b) 
{
    return a > b;  // Orden descendente
}

//seleccion de ordenamiento
void seleccion(vector<int>& arr, int op)
{
    switch (op)
    {
        case 1:
            //ordenado de forma ascendente
            sort(arr.begin(), arr.end()); 
        break;
        case 2:
            //ordenado de forma descendente
            sort(arr.begin(), arr.end(), compare);
        break;
            
    }
}
//generar un conjunto aleatorio basado en rangos
vector<int> generarConjuntoAleatorio(int rangoMin, int rangoMax) 
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(rangoMin, rangoMax);

    int tamano = dis(gen);
    vector<int> conjunto;

    for(int i = 0; i < tamano; i++)
    {
        int elemento = dis(gen);
        conjunto.push_back(elemento);
    }

    return conjunto;
}
//set de datos ordenado aleatoriamente
void Aleatorio(vector<int>& arr) 
{
    random_device rd;
    mt19937 gen(rd());
    shuffle(arr.begin(), arr.end(), gen);
}
//set de datos ordenado aleatoriamente sin duplicados
void AleatorioSinDuplicar(vector<int>& arr)
{
    random_device rd;
    mt19937 gen(rd());

    set<int> elementos;
    vector<int> resultado;
    
    for (int i = arr.size() - 1; i >= 0; --i) 
    {
        uniform_int_distribution<int> dis(0, i);
        int j = dis(gen);
        swap(arr[i], arr[j]);
        elementos.insert(arr[i]);
    }
    for (int elemento : arr) 
    {
        if (elementos.count(elemento) > 0) 
        {
            resultado.push_back(elemento);
            elementos.erase(elemento);
        }
    }
    arr = resultado;
    
}
//set de datos ordenado
void Ordenado(vector<int>& arr, int op)
{
    if(op == 2)
    {
        sort(arr.begin(), arr.end()); // Ordenar de forma ascendente
    }
    else
    {
        sort(arr.begin(), arr.end()); // Ordenar de forma descendente
    }
    
}
//set de datos inversamente ordenado
void InversamenteOrdenado(vector<int>& arr, int op)
{
    if(op == 1)
    {
        sort(arr.rbegin(),arr.rend());// Ordenar de forma descendente
    }
    else
    {
        sort(arr.rbegin(),arr.rend());// Ordenar de forma descendente
    }
}

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
int partition(vector<int>& arr, int low, int high) 
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) 
    {
        if (arr[j] < pivot) 
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
// Función recursiva para ordenar el arreglo utilizando Quick Sort
void quickSort(vector<int>& arr, int low, int high) 
{
    if (low < high) 
    {
        int pivotIndex = partition(arr, low, high);

        //Ordenar los elementos antes y después del pivote
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
// Función para realizar el ajuste descendente (sift-down) en un subárbol
void siftDown(vector<int>& arr, int n, int i) 
{
    int largest = i;            //inicialmente, asumimos que el nodo actual es el más grande
    int left = 2 * i + 1;      //indice del hijo izquierdo
    int right = 2 * i + 2;    //indice del hijo derecho

    //Si el hijo izquierdo es más grande que la raíz
    if (left < n && arr[left] > arr[largest]) 
    {
        largest = left;
    }

    // Si el hijo derecho es más grande que el más grande encontrado hasta ahora
    if (right < n && arr[right] > arr[largest]) 
    {
        largest = right;
    }

    // Si el más grande no es la raíz actual, realizar el intercambio y continuar ajustando descendente
    if (largest != i) 
    {
        swap(arr[i], arr[largest]);
        siftDown(arr, n, largest);
    }
}
// Función para ordenar el arreglo utilizando Heap Sort
void heapSort(vector<int>& arr) 
{
    int n = arr.size();

    // Construir el heap (reorganizar el arreglo)
    for (int i = n / 2 - 1; i >= 0; i--) 
    {
        siftDown(arr, n, i);
    }

    // Extraer elementos uno por uno desde el heap y colocarlos al final del arreglo ordenado
    for (int i = n - 1; i > 0; i--) 
    {
        swap(arr[0], arr[i]);
        siftDown(arr, i, 0);
    }
}

//determina el resultado en tiempo de los algoritmos de ordenamiento
double getResultFromAlg(vector<int>& arr/*,int option*/) 
{
    time_t start, end;
    double time_taken;
    time(&start);
    ios_base::sync_with_stdio(false);
    //llamar a los 7 algoritmos de ordenamiento
    vector <int> arr1(arr.begin(),arr.end());
    SelectionSort(arr1);
    vector <int> arr2(arr.begin(),arr.end());
    BubbleSort(arr2);
    vector <int> arr3(arr.begin(),arr.end());
    InsertionSort(arr3);
    cout << endl;
    time(&end);
    time_taken = double(end - start);
    return time_taken;
}


int main()
{
    int op;
    //string opc;

    int rangoMin=1;
    int rangoMax = 9000;
    //int tamanio = 10; 

    //vector<int> arr = AleatorioUnico(rangoMin,rangoMax,tamanio);
    //int n = arr.size();
    vector<int> arr = generarConjuntoAleatorio(rangoMin,rangoMax);
    cout<<"Carreras de algoritmos"<<endl;
    cout<<"1.Ascendente."<<endl;
    cout<<"2.Descendente."<<endl;
    cin>>op;
    seleccion(arr,op);
    /*
    if(op==1)
    {
        opc = "Ascendente";
    }
    else if(op == 2)
    {
        opc = "Descendente";
    }
    */
    cout<<"Opcion elegida:"<<op<</*<<opc<<*/endl;

    /*
    cout << "Conjunto aleatorio generado: ";
    for (int elemento : arr) 
    {
        cout << elemento << " ";
    }
    cout << endl;
    */

    //prueba aleatorio
    Aleatorio(arr);
    /*
    cout << "Conjunto ordenado aleatoriamente: ";
    for (int al : arr) 
    {
        cout << al << " ";
    }
    cout << endl; 
    */


    /* 
    //prueba aleatorio sin duplicar
    AleatorioSinDuplicar(arr);
    cout << "Conjunto ordenado aleatoriamente sin duplicar: ";
    for (int alsind : arr) 
    {
        cout << alsind << " ";
    }
    cout << endl;
    //prueba ordenado
    cout << "Conjunto ordenado: ";
    Ordenado(arr,op);
    for (int ord : arr) 
    {
        cout << ord << " ";
    }
    cout << endl;
    cout << "Conjunto inversamente ordenado: ";
    InversamenteOrdenado(arr,op);
    for (int invord : arr) 
    {
        cout << invord << " ";
    }
    cout << endl;
    */
    //SelectionSort(arr); 
    //BubbleSort(arr);
    //InsertionSort(arr);
    //shellSort(arr);
    //MergeSort(arr, 0, n - 1);
    //quickSort(arr,0,n - 1);
    //heapSort(arr);

    ///////////////////////
    
    //IMPORTANTE: parte que se encarga de los resultados
    unordered_map<string, double> results;
    vector <int> arr1(arr.begin(),arr.end());
    //SelectionSort(arr1);
    /*
    cout<<"Prueba Selection"<<endl;
    for (int num : arr1) 
    {
        cout << num << " ";
    }
    cout << endl; 
    */
    results["SeleciontSort"] = getResultFromAlg(arr1);

    vector<int> arr2(arr.begin(), arr.end());
    //BubbleSort(arr2);
    /*
    cout<<"Prueba Bubble"<<endl;
    for (int num : arr2) 
    {
        cout << num << " ";
    }
    cout << endl;
    */ 
    results["BubbleSort"] = getResultFromAlg(arr2);

    vector<int> arr3(arr.begin(), arr.end());
    //InsertionSort(arr3);
    /*
    cout<<"Prueba insertion"<<endl;
    for (int num : arr3) 
    {
        cout << num << " ";
    }
    cout << endl;
    */
    results["InsertionSort"] = getResultFromAlg(arr3);
    //vector<int> arr1,arr2,arr3; 
    //arr1.assign(arr.begin(), arr.end());
    //arr2.assign(arr.begin(), arr.end());
    //arr3.assign(arr.begin(), arr.end());
    int id = 1;
    
    /*
    //probando si el algoritmo los ordena
    for (int num : arr) 
    {
        cout<<"entro"<<endl;
        cout << num << " ";
    }
    cout << endl;
    */

   //resultados del algoritmo en cuanto al tiempo
   for (const auto& pair : results) 
   {
        const string& key = pair.first;
        double value = pair.second;
        cout << id << ". " << key << ", " << fixed << value << setprecision(5)
        << endl;
        id++;
   }
       

    return 0;
}


