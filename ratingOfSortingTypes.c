#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZE 20000

// тут мы определяем функции сортировки
void bubbleSort(int arr[], int n);
void cocktailSort(int arr[], int n);
void gnomeSort(int arr[], int n);
void quickSort(int arr[], int low, int high);
void heapSort(int arr[], int n);

void swap(int* a, int* b);
int partition(int arr[], int low, int high);
void heapify(int arr[], int n, int i);

// Определение структуры "Sort", которая содержит имя метода сортировки и время его выполнения
typedef struct {
    char name[20]; // массив символов для хранения имени метода сортировки
    int time; // переменная для хранения времени выполнения сортировки
} Sort;

int compare(const void* a, const void* b) {
    return ((Sort*)a)->time - ((Sort*)b)->time;
}

// Функция для замера времени выполнения сортировки
void measureSortingTime(char *name, void (*sortFunc)(int *, int), int arr[], int backup[], int n, Sort *sortStruct) {
    memcpy(arr, backup, sizeof(int) * n);
    clock_t start = clock();
    sortFunc(arr, n);
    clock_t end = clock();
    sortStruct->time = (int)(((double)(end - start)) / CLOCKS_PER_SEC * 1000);
    printf("Time of %s: %d milliseconds\n", name, sortStruct->time);
    strcpy(sortStruct->name, name);
}

void quickSortWrapper(int* arr, int n) {
    quickSort(arr, 0, n - 1);
}

int main()
{
    int arr[SIZE], backup[SIZE];
    Sort sorts[5];
    srand(time(0));

    printf("Size of array: %d\n", SIZE);

    // Заполнение массива случайными числами и создание резервной копии
    for (int i = 0; i < SIZE; i++) {
        backup[i] = arr[i] = rand() % 1000;
    }

    // замер времени для различных сортировок
    measureSortingTime("BubbleSort", bubbleSort, arr, backup, SIZE, &sorts[0]);
    measureSortingTime("CocktailSort", cocktailSort, arr, backup, SIZE, &sorts[1]);
    measureSortingTime("GnomeSort", gnomeSort, arr, backup, SIZE, &sorts[2]);
    measureSortingTime("QuickSort", quickSortWrapper, arr, backup, SIZE, &sorts[3]);
    measureSortingTime("HeapSort", heapSort, arr, backup, SIZE, &sorts[4]);

    // Сортировка методов по времени выполнения
    qsort(sorts, 5, sizeof(Sort), compare);

    // Вывод таблицы
    for (int i = 0; i < 5; i++)
        printf("%d. %s - (time of sort: %d milliseconds)\n", i+1, sorts[i].name, sorts[i].time);

    return 0;
}

void bubbleSort(int arr[], int n) 
{
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void cocktailSort(int arr[], int n) 
{
    int start = 0, end = n - 1, i;
    while (start < end) {
        for (i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(&arr[i], &arr[i + 1]);
            }
        }
        end--;
        for (i = end; i > start; i--) {
            if (arr[i] < arr[i - 1]) {
                swap(&arr[i], &arr[i - 1]);
            }
        }
        start++;
    }
}

void gnomeSort(int arr[], int n) 
{
    int i = 0;
    while (i < n) {
        if (i == 0 || arr[i - 1] <= arr[i]) {
            i++;
        }
        else {
            swap(&arr[i], &arr[i - 1]);
            i--;
        }
    }
}

void quickSort(int arr[], int low, int high) 
{
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void heapSort(int arr[], int n) 
{
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) 
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void heapify(int arr[], int n, int i) 
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}
