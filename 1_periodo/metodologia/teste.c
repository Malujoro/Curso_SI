#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para trocar dois elementos de posição
void swap(int* xp, int* yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Algoritmo Bubble Sort para ordenar um array
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

// Função para mesclar dois subarrays de arr[]
// Primeiro subarray é arr[l..m]
// Segundo subarray é arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Criar subarrays temporários
    int L[n1], R[n2];

    // Copiar dados para os subarrays temporários L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Mesclar os subarrays temporários de volta em arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar os elementos restantes de L[], se houver algum
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar os elementos restantes de R[], se houver algum
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função principal do Merge Sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Encontrar o ponto médio
        int m = l + (r - l) / 2;

        // Chamar recursivamente a função mergeSort() para os dois subarrays
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Mesclar os dois subarrays ordenados
        merge(arr, l, m, r);
    }
}

// Função que escolhe o último elemento como pivô e coloca
// o elemento pivô em sua posição correta no array ordenado
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // escolhe o último elemento como pivô
    int i = (low - 1);  // índice do menor elemento

    for (int j = low; j <= high - 1; j++) {
        // Se o elemento atual for menor ou igual ao pivô
        if (arr[j] <= pivot) {
            i++;  // incrementa o índice do menor elemento
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Função principal do Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi é o índice de divisão, arr[p] está em sua posição correta
        int pi = partition(arr, low, high);

        // Separadamente classifica os elementos antes e depois da partição
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    // Tamanho do array
    int n = 100000;
    
    printf("\n Digite a base de números a ser utilizada: ");
    scanf("%d", &n);

    // Criação do array com números aleatórios
    int arr[n];

    // Executar cada algoritmo 30 vezes e coletar os resultados
    clock_t start, end;
    double cpu_time_used;
    int i, j;

    // Bubble Sort
    printf("Bubble Sort:\n");
    for (i = 0; i < 30; i++) {
        // Gerar um novo conjunto de números aleatórios
        srand(time(0) + i);
        for (j = 0; j < n; j++) {
            arr[j] = rand();
        }

        start = clock();
        bubbleSort(arr, n);
        end = clock();

        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Tempo de ordenação %d: %f segundos\n", i + 1, cpu_time_used);
    }

    printf("\n");

    // Merge Sort
    printf("Merge Sort:\n");
    for (i = 0; i < 30; i++) {
        // Gerar um novo conjunto de números aleatórios
        srand(time(0) + i);
        for (j = 0; j < n; j++) {
            arr[j] = rand();
        }

        start = clock();
        mergeSort(arr, 0, n - 1);
        end = clock();

        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Tempo de ordenação %d: %f segundos\n", i + 1, cpu_time_used);
    }

    printf("\n");

    // Quick Sort
    printf("Quick Sort:\n");
    for (i = 0; i < 30; i++) {
        // Gerar um novo conjunto de números aleatórios
        srand(time(0) + i);
        for (j = 0; j < n; j++) {
            arr[j] = rand();
        }

        start = clock();
        quickSort(arr, 0, n - 1);
        end = clock();

        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Tempo de ordenação %d: %f segundos\n", i + 1, cpu_time_used);
    }

    return 0;
}