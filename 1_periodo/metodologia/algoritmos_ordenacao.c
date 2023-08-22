//Bibliotecas:
#include <stdio.h>    // Básica
#include <stdlib.h>   // Valor de RAND_MAX, Função rand() e srand()
#include <time.h>     // Função time(), clock() e Tipo clock_t


// Procedimento que modifica um vetor com números gerados aleatóriamente
// Recebe o vetor utilizado, a quantidade de números e o número da execução (para aleatorizar mais)
void gerar_numeros(int *vetor, int tam, int rodada) 
{
    int i=0; // Define o contador

    // Inicializa o gerador de números aleatórios
    //srand(time(NULL)+rodada);    
    srand(rodada);

    //Gera uma quantidade de números aleatórios e coloca no vetor
    while (i < tam)
    {
        vetor[i] = rand() % 10001;
        i++;
    }
}


// Função que calcula o tempo de execução do programa (em milissegundos)
// Recebe o Tempo de início e o tempo do fim
double calcula_tempo(long int inicio, long int fim)
{
    return (double)(fim - inicio) / (double)(CLOCKS_PER_SEC/1000);
}


// Função que divide o vetor e retorna a posição do pivô do quicksort
// Recebe o vetor, a posição de início e a de fim
int particiona_quick(int *vetor, int inicio, int fim)
{
    int esq, dir, pivo, aux;

    esq = inicio;
    dir = fim;
    pivo = vetor[inicio];
    // Repete até a posição esquerda passar da direita
    while (esq < dir)
    {
        // Busca a posição de um valor maior que o pivô, para ser colocado na direita
        while ((vetor[esq] <= pivo) && (esq <= fim))
        {
            esq++;
        }
        // Busca a posição de um valor menor que o pivô, para ser colocado na esquerda
        while ((vetor[dir] > pivo) && (dir > inicio))
        {
            dir--;
        }
        // Troca os valores encontrados de posição
        if (esq < dir)
        {
            aux = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = aux;
        }
    }
    // Coloca o pivô no seu devido lugar, trocando com o outro número
    vetor[inicio] = vetor[dir];
    vetor[dir] = pivo;
    return dir;
}

// Método de ordenação que utiliza o conceito "dividir pra conquistar"
// Recebe o vetor, a posição de início e a de fim
void quick_sort(int *vetor, int inicio, int fim)
{
    // Seleciona um número como "pivô", coloca na sua posição "certa" e divide o vetor em outros 2 menores
    // (Geralmente o pivô escolhido é o primeiro número do vetor)
    // à esquerda do pivô ficam os números menores que ele, e à direita os maiores

    int pos_pivo;

    if (fim > inicio)
    {
        pos_pivo = particiona_quick(vetor, inicio, fim);
        // Utilizando-se de recursão, o método repete a si para ordenar as outras partes dos vetores
        quick_sort(vetor, inicio, pos_pivo-1);
        quick_sort(vetor, pos_pivo+1, fim);
    }
}


// Método de ordenação semelhante ao Insertion, como se fosse uma "versão melhorada"
// Compara o valor com outro a H posições de distância
// Recebe o vetor e o tamanho dele
void shell_sort(int *vetor, int tam)
{
    int i, pos, valor;
    int h = 1;
    
    // Calcula o número de h, que vai ser o intervalo das comparações
    // Ex: h = 3, compara os números nos índices: (0, 3); (1,4)...
    while (h < tam/3)
    {
        h = (3 * h) + 1;
    }
    while (h > 0)
    {
        // Executa as comparações
        for (i = h; i < tam; i++)
        {
            valor = vetor[i];
            pos = i;
            // Executa as trocas
            while (pos >= h && valor < vetor[pos - h])
            {
                vetor[pos] = vetor[pos-h];
                pos -= h;
            }
            vetor[pos] = valor;
        }
        // Diminui o valor de h com uma divisão inteira, até se tornar 0
        h /= 3;
    }

}


// Cria uma Heap / "Árvore binária", com o maior vetor ("pai") sempre no topo/acima dos "filhos"
// Recebe o vetor, o início e o fim
void cria_heap(int *vetor, int inicio, int fim)
{
    int aux = vetor[inicio]; // Esse valor do vetor é o "pai", e "inicio" é a sua posição
    int pos_filho = inicio * 2 + 1; // A posição do outro "filho" é "inicio * 2 + 2"
    while (pos_filho <= fim)
    {
        // Se for menor, quer dizer que tem outro filho
        if (pos_filho < fim)
        {
            // Caso o pai tenha dois filhos, verifica qual dos dois é o maior
            if (vetor[pos_filho] < vetor[pos_filho + 1])
                pos_filho+= 1;
        }
        // Caso o filho seja maior que o pai, trocam de posição
        if (aux < vetor[pos_filho])
        {
            vetor[inicio] = vetor[pos_filho];
            inicio = pos_filho;
            pos_filho = 2 * inicio + 1;
        }
        // Senão, quer dizer que o pai está na posição "correta"
        else
        {
            pos_filho = fim + 1;
        }
    }   
    // O antigo pai ocupa o lugar do último filho analisado
    vetor[inicio] = aux;
}

// Método de ordenação que simula uma árvore binária
// Recebe o vetor e o tamanho dele
void heap_sort(int *vetor, int tam)
{
    int i, aux;
    // Cria uma Heap a partir dos dados, e coloca o maior valor no topo
    for (i = (tam-1) / 2; i >= 0; i--)
    {
        cria_heap(vetor, i, tam-1);
    }
    
    for (i = tam-1; i >= 1; i--)
    {
        // Pega o maior elemento da Heap e coloca na sua posição correspondente no vetor
        aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;
        // Vai reconstruir a Heap, sem contar com o maior valor antigo
        cria_heap(vetor, 0, i-1);
    }
}


void print_vetor(int *vetor, int tam)
{
    int i;
    for (i=0; i < tam; i++)
    {   
        printf("\nNúmero %d: %d\n", i+1, vetor[i]);
    }
}


// Programa principal
int main(void)
{    
    int tamanho_vetor=1000000; // Define o tamanho dos vetores
    int quant_exec=30; // Define quantas vezes vai "rodar" as execuções
    
    int vetor[tamanho_vetor]; // Declara o vetor com a quantidade total de números
    
    int num_exec; // Declara a variável de controle (número de execução do programa)

    clock_t comeco, fim; // Declara as variáveis utilizadas para o controle do tempo
    
    double tempo, soma_quick=0, soma_shell=0, soma_heap=0; // Declara as somas dos tempos

    // Repete o código "quant_exec" vezes
    for (num_exec=1; num_exec <= quant_exec; num_exec++)
    {
        printf("\n==================================================");
        printf("\n%dª Execução:\n", num_exec);

        // Algoritmo de ordenação QUICK SORT
        gerar_numeros(vetor, tamanho_vetor, num_exec);

        comeco = clock(); // Coleta o "tempo de início"
        quick_sort(vetor, 0, tamanho_vetor-1);
        fim = clock(); // Coleta o "tempo final"

        tempo = calcula_tempo(comeco, fim);
        soma_quick += tempo;

        printf("Tempo de execução [Quick Sort]: %.3f milissegundos\n", tempo);
        //printf("Tempo de execução [Quick Sort]: %f milissegundos\n", calcula_tempo(comeco, fim));
                
        // Algoritmo de ordenação SHELL SORT
        gerar_numeros(vetor, tamanho_vetor, num_exec);

        comeco = clock(); // Coleta o "tempo de início"
        shell_sort(vetor, tamanho_vetor);
        fim = clock(); // Coleta o "tempo final"

        tempo = calcula_tempo(comeco, fim);
        soma_shell += tempo;

        printf("Tempo de execução [Shell Sort]: %.3f milissegundos\n", tempo);
        //printf("Tempo de execução [Shell Sort]: %f milissegundos\n", calcula_tempo(comeco, fim));

        // Algoritmo de ordenação HEAP SORT
        gerar_numeros(vetor, tamanho_vetor, num_exec);

        comeco = clock(); // Coleta o "tempo de início"
        heap_sort(vetor, tamanho_vetor);
        fim = clock(); // Coleta o "tempo final"

        tempo = calcula_tempo(comeco, fim);
        soma_heap += tempo;

        printf("Tempo de execução [Heap  Sort]: %.3f milissegundos", tempo);
        //printf("Tempo de execução [Heap  Sort]: %f milissegundos", calcula_tempo(comeco, fim));
    }
    printf("\n==================================================\n");
    printf("\nSoma  do Quick Sort: %.3f", soma_quick);
    printf("\nSoma  do Shell Sort: %.3f", soma_shell);
    printf("\nSoma  do Heap  Sort: %.3f\n\n", soma_heap);
    
    printf("\nMédia do Quick Sort: %.3f", soma_quick/quant_exec);
    printf("\nMédia do Shell Sort: %.3f", soma_shell/quant_exec);
    printf("\nMédia do Heap  Sort: %.3f\n\n", soma_heap/quant_exec);
    return 0;
}
