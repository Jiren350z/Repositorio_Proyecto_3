#ifdef _WIN32
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
#include <limits>
#include <ratio>
#include <chrono>
#include <set>
using namespace std;
using namespace chrono;
using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::chrono::duration_cast;


/*
//////////////
//BORRAR
vector<int> Conjunto(int rangoMin, int rangoMax)
{
    vector<int> conjunto;
    srand(time(0)); //Inicializar la semilla aleatoria

    for (int i = rangoMin; i <= rangoMax; i++)
    {
        conjunto.push_back(i);
    }

                                            
    for (int i = 0; i < conjunto.size(); i++)//Mezclar el conjunto de forma aleatoria
    {
        int randomIndex = std::rand() % conjunto.size();
        swap(conjunto[i], conjunto[randomIndex]);
    }

    return conjunto;
}
//BORRAR
vector<int> conjunto(int rangoMin, int rangoMax)
{
    vector<int> conjunto;
    for(int i = rangoMin; i <= rangoMax; i++)
    {
        conjunto.push_back(i);
    }
    return conjunto;
}
//BORRAR
vector<int> generarConjuntoAleatorio(int rangoMin, int rangoMax) //generar un conjunto aleatorio basado en rangos
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 1000000); //numeros que van al tamaño
    uniform_int_distribution<int> dis2(rangoMin,rangoMax); //generador de tamaño

    //int tamano = dis(gen);
    int tamano = dis2(gen);
    vector<int> conjunto;

    for(int i = 0; i < tamano; i++)
    {
        
        int elemento = dis(gen);
        conjunto.push_back(elemento);
        
    }

    return conjunto;
}
//BORRAR
bool compare(int a, int b) //comparacion de dos elementos para orden descendente
{
    return a > b;  // Orden descendente
}
//BORRAR
void seleccion(vector<int>& arr, int op)//seleccion de ordenamiento
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
//////////////
*/

//NO BORRAR
/*
void Ordenado(vector<int>& arr, int rangoMin, int rangoMax)
{
    for(int i = rangoMin; i <= rangoMax; i++)
    {
        arr.push_back(i);
    }
}

void InversamenteOrdenado(vector<int>& arr, int rangoMin, int rangoMax)
{
    for(int i = rangoMax; i >= rangoMin; i--)
    {
        arr.push_back(i);
    }
}

vector<int> Conjuntos(int rangoMin, int rangoMax, int op)
{
    vector<int> conjunto;
    if(op == 1)//modo ascendente
    {
        InversamenteOrdenado(conjunto,rangoMin,rangoMax);//se entrega el conjunto contrario
    }
    if(op == 2)//modo descendente
    {
        Ordenado(conjunto,rangoMin,rangoMax);//se entrega el conjunto contrario
    }
    return conjunto;
}
*/

/*
//////////////
//BORRAR
void aleatorio(vector<int>& arr) //set de datos ordenado aleatoriamente
{
    random_device rd;
    mt19937 gen(rd());
    shuffle(arr.begin(), arr.end(), gen);
}
//BORRAR
void aleatorioSinDuplicar(vector<int>& arr)//set de datos ordenado aleatoriamente sin duplicados
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
//BORRAR
void ordenado(vector<int>& arr, int op)//set de datos ordenado
{
    if(op == 2)
    {
        sort(arr.begin(), arr.end()); // Ordenar de forma ascendente
    }
    else if (op == 1)
    {

    }
}
//BORRAR
void inversamenteOrdenado(vector<int>& arr, int op)//set de datos inversamente ordenado
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
//////////////
*/
vector<int> Ordenado(int rangoMin, int rangoMax)
{
    vector<int> conjunto;
    for(int i = rangoMin; i <= rangoMax; i++)
    {
        conjunto.push_back(i);
    }
    return conjunto;
}

vector<int> InversamenteOrdenado(int rangoMin, int rangoMax)
{
    vector<int> conjunto;
    for(int i = rangoMax; i >= rangoMin; i--)
    {
        conjunto.push_back(i);
    }
    return conjunto;
}

vector<int> Aleatorio(int rangoMin, int rangoMax)//generar un conjunto aleatorio basado en rangos
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

vector<int> AleatorioSinDuplicar(int rangoMin, int rangoMax)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(rangoMin, rangoMax);

    int tamano = dis(gen);
    vector<int> conjunto;

    set<int> elementos_unicos;
    for(int i = rangoMin; i <= rangoMax; i++)
    {
        elementos_unicos.insert(i);
    }

    // Verificar si el tamaño total de elementos únicos es menor que el tamaño especificado
    if (elementos_unicos.size() < tamano)
    {
        // Puedes ajustar el tamaño para que sea igual al tamaño de elementos_unicos
        tamano = elementos_unicos.size();
    }

    // Tomar el tamaño de elementos aleatorios del conjunto de elementos únicos.
    while(conjunto.size() < tamano)
    {
        int elemento = *next(elementos_unicos.begin(),dis(gen) % elementos_unicos.size());
        conjunto.push_back(elemento);
        elementos_unicos.erase(elemento);
    }

    // Mezclar los elementos del conjunto para obtener un conjunto aleatorio sin duplicados
    shuffle(conjunto.begin(), conjunto.end(), gen);
    //shuffle(conjunto.begin(),conjunto.end(),gen);

    return conjunto;
    
}

/*
vector<int> AleatorioSinDuplicar(int rangoMin, int rangoMax)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(rangoMin, rangoMax);

    int tamano = dis(gen);
    vector<int> conjunto;

    // Utilizamos un conjunto para verificar la unicidad de los elementos generados.
    set<int> elementos_generados;

    for (int i = 0; i < tamano; i++)
    {
        int elemento = dis(gen);

        while (elementos_generados.find(elemento) != elementos_generados.end())
        {
            elemento = dis(gen);
        }

        conjunto.push_back(elemento);
        elementos_generados.insert(elemento);
    }

    

    return conjunto;
}
*/

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
    int i, key, j;
    for (i = 1; i < n; i++) 
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    /*
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
    */
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

void merge(vector<int>& arr, int left, int middle, int right) //Función para combinar dos subarreglos ordenados en un solo arreglo ordenado
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

void MergeSort(vector<int>& arr, int left = 0, int right = -1) //Función recursiva para dividir y ordenar el arreglo en subarreglos más pequeños
{
    if (right == -1) 
    {
        right = arr.size() - 1;
    }
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

int partition(vector<int>& arr, int start, int end)
{
 
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) 
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
            
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) 
    {
 
        while (arr[i] <= pivot) 
        {
            i++;
        }
 
        while (arr[j] > pivot) 
        {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) 
        {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}

void quickSort(vector<int>& arr, int start, int end)
{
 
    // base case
    if (start >= end)
    {
        return;
    }
    // partitioning the array
    int p = partition(arr, start, end);
 
    // Sorting the left part
    quickSort(arr, start, p - 1);
 
    // Sorting the right part
    quickSort(arr, p + 1, end);
}

void siftDown(vector<int>& arr, int n, int i) //Función para realizar el ajuste descendente (sift-down) en un subárbol
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

void heapSort(vector<int>& arr) //Función para ordenar el arreglo utilizando Heap Sort
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

int Partition(vector<int>& arr, int start, int end)
{
    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    // Giving pivot element its correct position
    int pivotIndex = start + count;
    std::swap(arr[pivotIndex], arr[start]);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i] <= pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            std::swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}
 
void QuickSort(vector<int>& arr, int start, int end)
{
    // base case
    if (start >= end)
        return;

    // partitioning the array
    int p = Partition(arr, start, end);

    // Sorting the left part
    QuickSort(arr, start, p - 1);

    // Sorting the right part
    QuickSort(arr, p + 1, end);
}

void ejecutarCarreraAlgoritmos(const vector<int>& arr)//Función para ejecutar una carrera de algoritmos en un conjunto de datos
{
    //IMPORTANTE: parte que se encarga de los resultados
    unordered_map<string, double> results;
    
   //Selection
   vector <int> arr1(arr.begin(),arr.end());
   high_resolution_clock::time_point t1s = high_resolution_clock::now();
   SelectionSort(arr1);
   high_resolution_clock::time_point t2s = high_resolution_clock::now();
   duration<double> time_spans = duration_cast<duration<double>>(t2s - t1s);
   //cout << "Selection: " << time_spans.count() << " seconds."<<endl;
   results["Selection Sort"] = time_spans.count();
   cout << "Prueba: ";
    for (int al : arr1) 
    {
        cout << al << "Selection Sort";
    }
    cout << endl; 
   arr1.clear();
   //Bubble 
   vector <int> arr2(arr.begin(),arr.end());
   high_resolution_clock::time_point t1b = high_resolution_clock::now();
   BubbleSort(arr2);
   high_resolution_clock::time_point t2b = high_resolution_clock::now();
   duration<double> time_spanb = duration_cast<duration<double>>(t2b - t1b);
   //cout << "Bubble: " << time_spanb.count() << " seconds."<<endl;
   results["Bubble Sort"] = time_spanb.count();
    for (int al : arr2) 
    {
        cout << al << "Bubble Sort ";
    }
    cout << endl; 
   arr2.clear();
   //Insertion 
   vector <int> arr3(arr.begin(),arr.end());
   high_resolution_clock::time_point t1i = high_resolution_clock::now();
   InsertionSort(arr3);    
   high_resolution_clock::time_point t2i = high_resolution_clock::now();
   duration<double> time_spani = duration_cast<duration<double>>(t2i - t1i);
   //cout << "Insertion: " << time_spani.count() << " seconds."<<endl;
   results["Insertion Sort"] = time_spani.count();
    for (int al : arr3) 
    {
        cout << al << "Insertion Sort ";
    }
    cout << endl; 
   arr3.clear();
   //Shell
   vector <int> arr4(arr.begin(),arr.end());
   high_resolution_clock::time_point t1sh = high_resolution_clock::now();
   shellSort(arr4);
   high_resolution_clock::time_point t2sh = high_resolution_clock::now();
   duration<double> time_spansh = duration_cast<duration<double>>(t2sh - t1sh);
   //cout << "Shell: " << time_spansh.count() << " seconds."<<endl;
   results["Shell Sort"] = time_spansh.count();
    for (int al : arr4) 
    {
        cout << al << "Shell Sort ";
    }
    cout << endl; 
   arr4.clear();
   //Merge 
   vector <int> arr5(arr.begin(),arr.end());
   high_resolution_clock::time_point t1m = high_resolution_clock::now();
   MergeSort(arr5);
   high_resolution_clock::time_point t2m = high_resolution_clock::now();
   duration<double> time_spanm = duration_cast<duration<double>>(t2m - t1m);
   //cout << "Merge: " << time_spanm.count() << " seconds."<<endl;
   results["Merge Sort"] = time_spanm.count();
    for (int al : arr5) 
    {
        cout << al << "Merge Sort ";
    }
    cout << endl; 
   arr5.clear();
   //Quick
   /*
   vector <int> arr6(arr.begin(),arr.end());
   int n = arr6.size();
   high_resolution_clock::time_point t1q = high_resolution_clock::now();
   QuickSort(arr6,0,n-1);
   high_resolution_clock::time_point t2q = high_resolution_clock::now();
   duration<double> time_spanq = duration_cast<duration<double>>(t2q - t1q);
   //cout << "Quick: " << time_spanq.count() << " seconds."<<endl;
   results["Quick Sort"] = time_spanq.count();
    for (int al : arr6) 
    {
        cout << al << "Quick Sort ";
    }
    cout << endl; 
   arr6.clear();
   */
   //Heap
   vector <int> arr7(arr.begin(),arr.end());
   high_resolution_clock::time_point t1h = high_resolution_clock::now();
   heapSort(arr7);
   high_resolution_clock::time_point t2h = high_resolution_clock::now();
   duration<double> time_spanh = duration_cast<duration<double>>(t2h - t1h);
   //cout << "Heap: " << time_spanh.count() << " seconds."<<endl;
   results["Heap Sort"] = time_spanh.count();
    for (int al : arr7) 
    {
        cout << al << "Heap Sort ";
    }
    cout << endl; 
   arr7.clear();
   int id = 1;
   double minTime = numeric_limits<double>::max();
   string winnerAlgorithm;

   // Resultados del algoritmo en cuanto al tiempo
    for (const auto& pair : results) 
    {
        const string& key = pair.first;
        double value = pair.second;

        if (value < minTime) 
        {
            minTime = value;
            winnerAlgorithm = key;
        }
        cout << id << ". " << key << ", " << fixed << setprecision(7) << value << endl;
        id++;
    }

    cout << "El algoritmo ganador es: " << winnerAlgorithm << endl; 
    

}

void ejecutarCarreras()//Función principal para ejecutar todas las carreras de algoritmos en diferentes modos y rangos
{
    int rangoMin = 1;
    int rangoMax = 100000;
    int op;
    //string modo;
    //vector<int> arr = generarConjuntoAleatorio(rangoMin, rangoMax); 
    //vector<int> arr = Conjunto(rangoMin,rangoMax);
    cout << "Carreras de algoritmos" << endl;
    cout << "1. Ascendente." << endl;
    cout << "2. Descendente." << endl;
    cout<<"Opcion elegida:"<<endl;
    cin >> op;
    /*
    switch (op)
    {
        case 1:
            modo = "Inversamente Ordenado";
        break;
        case 2:
            modo = "Ordenado";
        break;
    }
    */
    cout<<"Carrera por el tablero:"<<endl;

    //Modo 1: Ordenado
    //cout<<"Modo 1: "<<modo<<endl;
    //vector<int> arrOrd_or_Inv = Conjuntos(rangoMin,rangoMax,op);

    cout<<"Modo 1: Ordenado"<<endl;
    vector<int> arrOrd = Ordenado(rangoMin,rangoMax);
    //ejecutarCarreraAlgoritmos(arrOrd);
    arrOrd.clear();

    //Modo 2: Inversamente Ordenado
    cout<<"Modo 2: Inversamente Ordenado"<<endl;
    vector<int> arrInvOrd = InversamenteOrdenado(rangoMin,rangoMax);
    //ejecutarCarreraAlgoritmos(arrInvOrd);
    arrInvOrd.clear();

    //Modo 3: Aleatorio
    cout<<"Modo 3: Aleatorio"<<endl;
    vector<int> arrRand = Aleatorio(rangoMin,rangoMax);
    //ejecutarCarreraAlgoritmos(arrRand);
    arrRand.clear();

    //Modo 4: Aleatorio Sin Duplicar
    cout<<"Modo 4: Aleatorio Sin Duplicar"<<endl;
    vector<int> arrRandSinD = AleatorioSinDuplicar(rangoMin,rangoMax);
    //ejecutarCarreraAlgoritmos(arrRandSinD);
    arrRandSinD.clear();


    /*
    vector<int> arrOrdenado;
    Ordenado(arrOrdenado,op);
    cout << "Prueba: ";
    ejecutarCarreraAlgoritmos(arrOrdenado);
    arrOrdenado.clear();
    //Modo 2: Inversamente Ordenado
    cout<<"Modo 2: Inversamente Ordenado"<<endl;
    vector<int> arrInverso(arr);
    InversamenteOrdenado(arrInverso,op);
    ejecutarCarreraAlgoritmos(arrInverso);
    arrInverso.clear();
    //Modo 3: Aleatorio
    cout<<"Modo 3: Aleatorio"<<endl;
    vector<int> arrAleatorio(arr);
    Aleatorio(arrAleatorio);
    ejecutarCarreraAlgoritmos(arrAleatorio);
    arrAleatorio.clear();
    //Modo 4: Aleatorio Sin Duplicar
    cout<<"Modo 4: Aleatorio Sin Duplicar"<<endl;
    vector<int> arrAleatorioSinDuplicar(arr);
    AleatorioSinDuplicar(arrAleatorioSinDuplicar);
    ejecutarCarreraAlgoritmos(arrAleatorioSinDuplicar);
    */
    //////////////////////////////////////////

    /*
    int rango2min = 1;
    int rango2max = 70000;
    vector<int> arr2 = Conjunto(rango2min,rango2max);
    //vector<int> arr2 = generarConjuntoAleatorio(rango2min,rango2max);
    seleccion(arr2,op);
    cout<<"Carrera por los Caminos"<<endl;
    //Modo 1: Ordenado
    cout<<"Modo 1: Ordenado"<<endl;
    vector<int> arrOrdenado2(arr2);
    Ordenado(arrOrdenado2,op);
    ejecutarCarreraAlgoritmos(arrOrdenado2);
    //Modo 2: Inversamente Ordenado
    cout<<"Modo 2: Inversamente Ordenado"<<endl;
    vector<int> arrInverso2(arr2);
    InversamenteOrdenado(arrInverso2,op);
    ejecutarCarreraAlgoritmos(arrInverso2);
    //Modo 3: Aleatorio
    cout<<"Modo 3: Aleatorio"<<endl;
    vector<int> arrAleatorio2(arr2);
    Aleatorio(arrAleatorio2);
    ejecutarCarreraAlgoritmos(arrAleatorio2);
    //Modo 4: Aleatorio Sin Duplicar
    cout<<"Modo 4: Aleatorio Sin Duplicar"<<endl;
    vector<int> arrAleatorioSinDuplicar2(arr2);
    AleatorioSinDuplicar(arrAleatorioSinDuplicar2);
    ejecutarCarreraAlgoritmos(arrAleatorioSinDuplicar2);
    //////////////////////////////////////////
    int rango3min = 1;
    int rango3max = 15000;
    vector<int>arr3(arr);
    */

}

int main()
{

    ejecutarCarreras();


    //impresion para prueba
    /*
    cout << "Prueba: ";
    for (int al : arr) 
    {
        cout << al << " ";
    }
    cout << endl; 
    */
    return 0;
}


