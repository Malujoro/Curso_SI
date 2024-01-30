#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

#define LINHA 45

int EXISTE, ESCOLHA;

// ------------------- FUNÇÕES GERAIS ----------------------

bool Verifica_Escolha(int Maximo, int Minimo, int Esc)
{
    while (getchar() != '\n');

    if(Esc > Maximo || Esc < Minimo)
    {
        printf("\nNúmero inválido! Tente novamente!\n");
        return false;
    }
    
    return true;
}

bool Verifica_Numeros(char *string) 
{
    int i = 0, j = 0;
    while (string[i]) 
    {
        if (isdigit(string[i])) 
            string[j++] = string[i];
        else {printf("inválido, tente novamente!\n"); return false;}
        i++;
    }
    string[j] = '\0';

    return true;
}

void Remover_NaoAlfabetico(char *palavra) 
{
    int i = 0, j = 0;
    while (palavra[i]) 
    {
        if (isalpha(palavra[i])) 
            palavra[j++] = palavra[i];
        i++;
    }
    palavra[j] = '\0';
}

//------------- QUARTOS -------------------------

typedef struct
{
    int Num;
    char Tipo[30];
    char Status[30];
    float Diaria;
} S_Quarto;
void linha(int quantidade)
{
    for(int i = 0; i < quantidade; i++)
        printf("_");
    printf("\n");
}

void Mostrar_Informacoes(S_Quarto *quarto)
{
    printf("\n___________INFORMAÇÃO DOS QUARTOS___________\n");
    printf("Número do quarto\t%d°\n", quarto->Num);
    printf("Disponibiliade  \t%s\n", quarto->Status);
    printf("Tipo de quarto  \t%s\n", quarto->Tipo);
    printf("Valor da diária \tR$%.2f\n", quarto->Diaria);
    linha(LINHA - 1);
}

void Exibir_Quartos()
{
    FILE *Exibir_Quarto = fopen("Quartos.txt", "r");
    S_Quarto quarto;

    if(!Exibir_Quarto)
    {
        printf("\nERRO ao abrir o arquivo!\n");
        exit(EXIT_FAILURE);
    }

    printf("\n___________QUARTOS E INFORMAÇÕES___________\n");
    while(fscanf(Exibir_Quarto, "%d %s %s %f\n",
    &quarto.Num, quarto.Tipo, quarto.Status, &quarto.Diaria) == 4) 
    {
        printf("Número do quarto\t%d°\n", quarto.Num);
        printf("Disponibiliade  \t%s\n", quarto.Status);
        printf("Tipo de quarto  \t%s\n", quarto.Tipo);
        printf("Valor da diária \tR$%.2f\n", quarto.Diaria);
        printf("--------------------------------------------\n");
    }
    linha(LINHA);
      
}

// Determinar o tipo de quarto pela escolha do usuario
void Tipo(S_Quarto *quarto)
{
    do{
        printf("[1] - Simples\n[2] - Duplo\n[3] - Suíte\n");
        printf("Sua escolha -> "), scanf("%d", &ESCOLHA); 
    } 
    while(!Verifica_Escolha(3, 1, ESCOLHA));
    
    switch(ESCOLHA)
    {
        case 1:
            strcpy(quarto->Tipo, "Simples");
            break;
        case 2:
            strcpy(quarto->Tipo, "Duplo");
            break;
        case 3:
            strcpy(quarto->Tipo, "Suíte");
            break;
    }
}

// Determinar a disponibilidade do quarto
void Status(S_Quarto *quarto)
{
    do{
        printf("[1] - Livre\n[2] - Reservado\n[3] - Ocupado\n");
        printf("Sua escolha -> "), scanf("%d", &ESCOLHA);  
    } 
    while(!Verifica_Escolha(3, 1, ESCOLHA));
    
    switch(ESCOLHA)
    {
        case 1:
            strcpy(quarto->Status, "Livre");
            break;
        case 2:
            strcpy(quarto->Status, "Reservado");
            break;
        case 3:
            strcpy(quarto->Status, "Ocupado");
            break;
        default:
            break;
    }
}

// verifica qual o valor minimo e máxaimo de quartos
bool Verifica_Maximo(float Quarto)
{
    while (getchar() != '\n');
    
    if (Quarto < 1) {printf("\nNúmero de quarto inválido!\n"); return false;} 

    else if(Quarto > 100) 
    { 
        printf("\nO prédio não tem capacidade para além de 100 quartos!\n");
        return false;
    }

    return true;
}

// Verifica se o preco dado pelo usuario atende os requisitos minimos
bool Verifica_Preco(float preco)
{
    while (getchar() != '\n');

    if(preco < 15) { printf("\npreço muito baixo ou inválido!\n"); return false; }

    else if(preco > 250) { printf("\nPreço muito alto!\n"); return false; }

    return true;
}

// Verifica se existe um quarto com o numero dado pelo user 
bool Verificar_Quarto(int num)
{
    FILE *Verifica_Quarto = fopen("Quartos.txt", "r");

    if(Verifica_Quarto == NULL)
    {
        printf("\nERRO ao abrir o arquivo!\n");
        exit(EXIT_FAILURE);
    }

    S_Quarto quarto_T;

    while(fscanf(Verifica_Quarto, "%d %s %s %f\n",
    &quarto_T.Num, quarto_T.Tipo, quarto_T.Status, &quarto_T.Diaria) == 4) 
    {
        if(quarto_T.Num == num)
        {
            printf("\nEsse número de quarto já existe!\n");
            fclose(Verifica_Quarto);
            return false;
        }
    }
    fclose(Verifica_Quarto);
    return true;
}

bool Verificar_Numero(int num)
{
    while(getchar() != '\n');

    FILE *Verifica_Quarto = fopen("Quartos.txt", "r");

    if(Verifica_Quarto == NULL)
    {
        printf("\nERRO ao abrir o arquivo!\n");
        exit(EXIT_FAILURE);
    }

    S_Quarto quarto_T;

    while(fscanf(Verifica_Quarto, "%d %s %s %f\n",
    &quarto_T.Num, quarto_T.Tipo, quarto_T.Status, &quarto_T.Diaria) == 4) 
    {
        if(quarto_T.Num == num)
        {
            fclose(Verifica_Quarto);
            return true;
        }
    }

    printf("\nEsse quarto não existe!\n");

    fclose(Verifica_Quarto);
    return false;
}

// pode ser reservado ? 
bool Verificar_Hospedagem(int num)
{
    while(getchar() != '\n');

    FILE *Verifica_Quarto2 = fopen("Quartos.txt", "r");

    if(Verifica_Quarto2 == NULL)
    {
        printf("\nERRO ao abrir o arquivo!\n");
        exit(EXIT_FAILURE);
    }

    S_Quarto quarto_T;

    while(fscanf(Verifica_Quarto2, "%d %s %s %f\n",
    &quarto_T.Num, quarto_T.Tipo, quarto_T.Status, &quarto_T.Diaria) == 4) 
    {
        if(quarto_T.Num == num)
        {
            return true;
        }
    }

    printf("\nEsse quarto não existe!\n");
    fclose(Verifica_Quarto2);
    return false;
}

//  quardado os dados do quarto no arquivo 
void Cadastrar_Quarto()
{
    S_Quarto quarto; 

    FILE *Alojamento = fopen("Quartos.txt", "a");

    if(Alojamento == NULL)
    {
        printf("\nERRO ao abrir o arquivo!\n");
        exit(EXIT_FAILURE);
    }

    do{
        do{
            printf("\nNúmero do novo quarto -> ");
            scanf("%d", &quarto.Num);
        } 
        while(!Verifica_Maximo(quarto.Num));
    } 
    while(!Verificar_Quarto(quarto.Num));
    
    Tipo(&quarto);

    strcpy(quarto.Status, "Livre");

    do{
        printf("Valor da diária -> R$");
        scanf("%f", &quarto.Diaria);
    } 
    while(!Verifica_Preco(quarto.Diaria));

    fprintf(Alojamento, "%d %s %s %.2f\n", quarto.Num, quarto.Tipo, quarto.Status, quarto.Diaria);

    fclose(Alojamento);
}

// Menu de consulta
int Menu_Consultar_Quarto()
{
    do{
        printf("\n_______COMO FAZER A CONSULTA_______\n");
        printf("[1] - Número do quarto\n");
        printf("[2] - Tipo\n");
        printf("[3] - Status\n");
        printf("[4] - Preço\n");
        linha(LINHA - 10);
        printf("Sua escolha -> "), scanf("%d", &ESCOLHA);  
    } 
    while(!Verifica_Escolha(4, 1, ESCOLHA));

    return ESCOLHA;
}

// Printar os dados quardados no arquivo de Quartos.txt, como base na escolha do usuario no menu
void Consultar_Quarto(int modo)
{
    S_Quarto quarto;
    S_Quarto quarto_temp;
    EXISTE = 0;

    FILE *Consulta_Alojamento = fopen("Quartos.txt", "r");

    if(Consulta_Alojamento == NULL)
    {
        printf("Não há quartos para consultar\n");
        fclose(Consulta_Alojamento);
        return;
    }

    switch(modo)
    {
    case 1:

        do{
            printf("Número do quarto -> ");
            scanf("%d", &quarto.Num);
        } 
        while(!Verifica_Maximo(quarto.Num));
        
        while(fscanf(Consulta_Alojamento, "%d %s %s %f\n",
        &quarto_temp.Num, quarto_temp.Tipo, quarto_temp.Status, &quarto_temp.Diaria) == 4) 
        {
            if(quarto.Num == quarto_temp.Num)
            {
                Mostrar_Informacoes(&quarto_temp);
                EXISTE = 1;
                break;
            }
        }

        if(EXISTE == 0) printf("\nNão há nenhum quarto com esse número!\n");
        break;
    
    case 2: 

        Tipo(&quarto);

        while(fscanf(Consulta_Alojamento,  "%d %s %s %f\n",
        &quarto_temp.Num, quarto_temp.Tipo, quarto_temp.Status, &quarto_temp.Diaria) == 4) 
        {
            if(strstr(quarto.Tipo, quarto_temp.Tipo) != NULL)
            {
                Mostrar_Informacoes(&quarto_temp);
                EXISTE = 1;
            }
        }

        if(EXISTE == 0) printf("\nNão há nenhum quarto do tipo %s no momento!\n", quarto.Tipo);
        break;

    case 3: 

        Status(&quarto);

        while(fscanf(Consulta_Alojamento, "%d %s %s %f\n",
        &quarto_temp.Num, quarto_temp.Tipo, quarto_temp.Status, &quarto_temp.Diaria) == 4) 
        {
            if(strstr(quarto.Status, quarto_temp.Status) != NULL)
            {
                Mostrar_Informacoes(&quarto_temp);
                EXISTE = 1;
            }
        }

        if(EXISTE == 0) printf("\nNão há nenhum quarto %s no momento!\n", quarto.Status);
        break; 
    
    case 4:

        do{
            printf("Valor (aproximado) -> ");
            scanf("%f", &quarto.Diaria);
        } 
        while(!Verifica_Preco(quarto.Diaria));

        while(fscanf(Consulta_Alojamento, "%d %s %s %f\n",
        &quarto_temp.Num, quarto_temp.Tipo, quarto_temp.Status, &quarto_temp.Diaria) == 4) 
        {
            int valor = quarto_temp.Diaria - quarto.Diaria;
            if(abs(valor) < 30)
            {
                printf("\n__________QUARTO COM VALOR PROXIMO__________\n");
                printf("Número do quarto: \t%d\n", quarto_temp.Num);
                printf("Disponibiliade: \t%s\n", quarto_temp.Status);
                printf("Tipo de quarto: \t%s\n", quarto_temp.Tipo);
                printf("Valor da diária: \tR$%.2f\n", quarto_temp.Diaria);
                linha(LINHA);
                EXISTE = 1;
            }
        }

        if(EXISTE == 0) printf("\nNão há nenhum quarto proximo a esse preco!\n");
        break;
    }
}

void Editar_Reserva(int num)
{
    FILE *Editar_Alojamento = fopen("Quartos.txt", "r");
    FILE *Editar_Alojamento_Temp = fopen("Quartos_temp.txt", "a");

    if(!Editar_Alojamento)
    {
        printf("\nERRO ao abrir o arquivo!\n");
        exit(EXIT_FAILURE);
    }
    else if(!Editar_Alojamento_Temp)
    {
        printf("\nERRO ao abrir o arquivo!\n");
        exit(EXIT_FAILURE);
    }

    S_Quarto quarto_T; 

    while(fscanf(Editar_Alojamento, "%d %s %s %f\n", &quarto_T.Num, quarto_T.Tipo, quarto_T.Status, &quarto_T.Diaria) == 4) 
    {
        if(num != quarto_T.Num)
        {
            fprintf(Editar_Alojamento_Temp, "%d %s %s %.2f\n", quarto_T.Num, quarto_T.Tipo, quarto_T.Status, quarto_T.Diaria);
        }
        else
        {
            strcpy(quarto_T.Status, "Reservado");
            fprintf(Editar_Alojamento_Temp, "%d %s %s %.2f\n", num, quarto_T.Tipo, quarto_T.Status, quarto_T.Diaria);
        }
    }

    fclose(Editar_Alojamento);
    fclose(Editar_Alojamento_Temp);

    remove("Quartos.txt");
    rename("Quartos_temp.txt", "Quartos.txt");

}

// Modificar a disponibilidade ou diaria se o quarto estiver livre
void Editar_Quarto()
{   
    FILE *Editar_Alojamento = fopen("Quartos.txt", "r+");
    FILE *Editar_Alojamento_Temp = fopen("Quartos_temp.txt", "a");

    if(Editar_Alojamento == NULL)
    {
        printf("\nERRO ao abrir o arquivo!\n");
        exit(EXIT_FAILURE);
    }
    else if(Editar_Alojamento_Temp == NULL)
    {
        printf("\nERRO ao abrir o arquivo!\n");
        exit(EXIT_FAILURE);
    }

    S_Quarto quarto; 
    S_Quarto quarto_T;

    do{
        do{
        
            printf("Número do quarto para modficar: ");
            scanf("%d", &quarto.Num);
        } 
        while(!Verificar_Numero(quarto.Num));

        while(fscanf(Editar_Alojamento,  "%d %s %s %f\n",
        &quarto_T.Num, quarto.Tipo, quarto_T.Status, &quarto.Diaria) == 4) 
        {
            if(quarto.Num == quarto_T.Num)
            {
                if(strstr(quarto_T.Status, "Livre") == NULL)
                {
                    printf("Quarto só pode ser modificado ao ficar livre!\n");
                    break;
                }

                linha(LINHA - 10);
                printf("Número do quarto: \t%d\n", quarto_T.Num);
                printf("Disponibiliade: \t%s\n", quarto_T.Status);
                printf("Tipo de quarto: \t%s\n", quarto.Tipo);
                printf("Valor da diária: \tR$%.2f\n", quarto.Diaria);
                linha(LINHA - 10);
                break;
            }
        }
    } 
    while(strstr(quarto_T.Status, "Livre") == NULL);
    
    do{
        printf("____O QUE MUDAR NO QUARTO N°%d_____\n", quarto.Num);
        printf("[0] - Voltar\n");
        printf("[1] - Tipo\n");
        printf("[2] - Diaria\n");
        linha(LINHA - 10);
        printf("Sua escolha -> "), scanf("%d", &ESCOLHA);
    } 
    while(!Verifica_Escolha(2, 0, ESCOLHA));
    
    if(ESCOLHA == 0) return;

    switch(ESCOLHA)
    {
    case 1:

        printf("____TROCAR O TIPO [%s] PARA____\n", quarto.Tipo);
        Tipo(&quarto);
        break;

    case 2: 

        do{
            printf("Trocar a diária de %f para -> $", quarto.Diaria);
            scanf("%f", &quarto.Diaria);
        }
        while(!Verifica_Preco(quarto.Diaria));
        
        break;
    }

    // serve para deixar ler o arquivo novamente 
    rewind(Editar_Alojamento);

    while(fscanf(Editar_Alojamento,  "%d %s %s %f\n",
    &quarto_T.Num, quarto_T.Tipo, quarto_T.Status, &quarto_T.Diaria) == 4) 
    {
        if(quarto.Num != quarto_T.Num)
        {
            fprintf(Editar_Alojamento_Temp, "%d %s %s %.2f\n",
            quarto_T.Num, quarto_T.Tipo, quarto_T.Status, quarto_T.Diaria);
        }
        else
        {
            fprintf(Editar_Alojamento_Temp, "%d %s %s %.2f\n",
            quarto.Num, quarto.Tipo, quarto_T.Status, quarto.Diaria);
        }
    }

    fclose(Editar_Alojamento);
    fclose(Editar_Alojamento_Temp);

    remove("Quartos.txt");
    rename("Quartos_temp.txt", "Quartos.txt");

}

// se o quarto estiver livre, fará a exclusão dele do arquivo
void Excluir_Quarto()
{
    FILE *Excluir_Alojamento = fopen("Quartos.txt", "r");
    FILE *Excluir_Alojamento_Temp = fopen("Quartos_temp.txt", "a");

    if(Excluir_Alojamento == NULL)
    {
        printf("\nERRO ao abrir o arquivo!\n");
        exit(EXIT_FAILURE);
    }
    else if(Excluir_Alojamento_Temp == NULL)
    {
        printf("\nERRO ao abrir o arquivo!\n");
        exit(EXIT_FAILURE);
    }

    S_Quarto quarto;
    S_Quarto quarto_T;

    do{
        printf("\nNúmero do quarto para excluir -> ");
        scanf("%d", &quarto.Num);
    }
    while(!Verificar_Numero(quarto.Num));

    while(fscanf(Excluir_Alojamento, "%d %s %s %f\n",
    &quarto_T.Num, quarto_T.Tipo, quarto_T.Status, &quarto_T.Diaria) == 4) 
    {
        if(quarto.Num != quarto_T.Num)
        {
            fprintf(Excluir_Alojamento_Temp, "%d %s %s %.2f\n", quarto_T.Num, quarto_T.Tipo, quarto_T.Status, quarto_T.Diaria);
        }
        else
        {
            if(strstr(quarto_T.Status, "Livre") == NULL)
            {
                printf("Atualmente o quarto está %s, não é possivel fazer sua exclusão!\n", quarto_T.Status);
                fprintf(Excluir_Alojamento_Temp, "%d %s %s %.2f\n", quarto_T.Num, quarto_T.Tipo, quarto_T.Status, quarto_T.Diaria);
            }
        }
    }

    fclose(Excluir_Alojamento);
    fclose(Excluir_Alojamento_Temp);

    remove("Quartos.txt");
    rename("Quartos_temp.txt", "Quartos.txt");
}


//------------- CLIENTE -------------------------

typedef struct 
{
    char CPF[17];
    char RG[17];
    char Telefone[17];
    char Email[100];
    char Nome[50];
} S_Cliente;

bool CPF_Valido(char *CPF)
{
    int i = 0, j = 0;
    while (CPF[i]) 
    {
        if (isdigit(CPF[i])) 
            CPF[j++] = CPF[i];

        else { printf("\nCPF inválido! Tente novamente!\n"); return false; }
        i++;
    }
    CPF[j] = '\0';

    if(strstr(CPF, "00000000000") != NULL) { printf("\nCPF inválido! Tente novamente!\n"); return false; }

    if(strlen(CPF) != 11)
    {
        printf("\nTamanho de CPF inválido!\n");
        return false;
    }

    return true;
}

bool RG_Valido(char *RG)
{
    int i = 0, j = 0;
    while (RG[i]) 
    {
        if(isdigit(RG[i])) 
            RG[j++] = RG[i];

        else { printf("\nRG inválido! Tente novamente!\n"); return false; }
        i++;
    }
    RG[j] = '\0';

    if(strstr(RG, "0000000") != NULL) { printf("\nRG inválido! Tente novamente!\n"); return false; }

    if(strlen(RG) != 7)
    {
        printf("\nTamanho de RG inválido!\n");
        return false;
    }

    return true;
}

bool Telefone_Valido(char *Telefone)
{
    int i = 0, j = 0;
    while (Telefone[i]) 
    {
        if(isdigit(Telefone[i])) 
            Telefone[j++] = Telefone[i];

        else { printf("\nTelefone inválido! Tente novamente!\n"); return false; }
        i++;
    }
    Telefone[j] = '\0';

    if(strstr(Telefone, "00000000000") != NULL)
    { 
        printf("\nTelefone inválido! Tente novamente!\n"); 
        return false; 
    }

    if(strlen(Telefone) != 11)
    {
        printf("\nTamanho de Telefone inválido!\n");
        return false;
    }

    return true;
}

bool Email_valido(char *email) {

    int tamanho = strlen(email);

    if(tamanho < 5 || tamanho > 50) 
    {
        printf("\nTamanho de Email inválido!\n");
        return false;
    }

    int contagemArroba = 0;
    for (int i = 0; i < tamanho; i++) {
        if(email[i] == '@') {
            contagemArroba++;
        }
    }

    if (contagemArroba != 1) 
    {
        printf("\nEmail inválido! Tente novamente!\n");
        return false;
    }

    for (int i = 0; i < tamanho; i++) 
    {
        if(email[i] == '.' && email[i + 1] == '@') 
        {
            printf("\nEmail inválido! Tente novamente!\n");
            return false;
        }
    }

    int indiceArroba = -1;
    int indicePonto = -1;

    for (int i = 0; i < tamanho; i++) 
    {
        if(email[i] == '@') 
        {
            indiceArroba = i;
        } 
        else if (email[i] == '.' && indiceArroba != -1) {
            indicePonto = i;
            break;
        }
    }

    if (indiceArroba == -1 || indicePonto == -1 || indicePonto < indiceArroba) 
    {
        printf("\nEmail inválido! Tente novamente!\n");
        return false;
    }

    for (int i = 0; i < tamanho - 1; i++) 
    {
        if(email[i] == '.' && email[i + 1] == '.') 
        {
            printf("\nEmail inválido! Tente novamente!\n");
            return false;
        }
    }

    for (int i = 0; i < tamanho; i++) 
    {
        if(!((email[i] >= 'a' && email[i] <= 'z') || (email[i] >= 'A' && email[i] <= 'Z') ||
        (email[i] >= '0' && email[i] <= '9') || email[i] == '.' || email[i] == '@' ||
        email[i] == '-' || email[i] == '_')) 
        {
            printf("\nEmail inválido! Tente novamente!\n");
            return false;
        }
    }

    return true;
}

bool Nome_Valido(char *Nome)
{
    int tamanho = strlen(Nome);

    if(true) 
    {
        if(tamanho > 50) { printf("\nNome muito grande!\n"); return false; }

        else if(tamanho < 3) { printf("\nNome muito curto!\n"); return false; }
    }
    
    for (int i = 0; i < tamanho; i++) 
    {
        if(!((Nome[i] >= 'a' && Nome[i] <= 'z') || (Nome[i] >= 'A' && Nome[i] <= 'Z') || (Nome[i] == ' '))) 
        {
            printf("\nNome inválido! Tente novamente!\n");
            return false;
        }
    }

    return true;
}

void Cadastrar_Cliente()
{
    S_Cliente cliente;

    FILE *Cadastrar_Hospede = fopen("Clientes.txt", "a");
    
    if(Cadastrar_Hospede == NULL)
    {
        printf("\nERRO ao abrir arquivo!\n");
        exit(EXIT_FAILURE);
    }

    do{
        printf("\nCPF do cliente -> "); 
        setbuf(stdin, NULL); 
        scanf("%[^\n]", cliente.CPF);
    } 
    while(!CPF_Valido(cliente.CPF));
    
    do{
        printf("\nRG do cliente -> ");
        setbuf(stdin, NULL);
        scanf("%[^\n]", cliente.RG); 
    } 
    while(!RG_Valido(cliente.RG));

    do{
        printf("\nTelefone do cliente -> ");
        setbuf(stdin, NULL); 
        scanf("%[^\n]", cliente.Telefone);
    } 
    while(!Telefone_Valido(cliente.Telefone));
    
    do{
        printf("\nEmail do cliente -> ");
        setbuf(stdin, NULL);
        scanf("%[^\n]", cliente.Email);
    } 
    while(!Email_valido(cliente.Email));
    
    do{
        printf("\nNome do cliente -> ");
        setbuf(stdin, NULL);
        scanf("%[^\n]", cliente.Nome);
    } 
    while(!Nome_Valido(cliente.Nome));

    fprintf(Cadastrar_Hospede, "%s %s %s %s %s\n",
    cliente.CPF, cliente.RG, cliente.Telefone, cliente.Email, cliente.Nome);

    fclose(Cadastrar_Hospede);

}

void Consultar_Cliente()
{
    S_Cliente cliente; int esc; 
    S_Cliente T_cliente;
    EXISTE = 0;

    FILE *Consultar_Hospede = fopen("Clientes.txt", "r");

    if(Consultar_Hospede == NULL)
    {
        printf("Não há clientes para consultar\n");
        return;
    }

    do{
        printf("\n_______COMO FAZER A CONSULTA_______\n");
        printf("[1] - Nome\n");
        printf("[2] - Telefone\n");
        printf("[3] - Email\n");
        printf("[4] - CPF\n");
        linha(LINHA - 10);
        printf("Sua escolha -> "), scanf("%d", &esc);  
    } 
    while(!Verifica_Escolha(4, 1, esc));

    switch(esc)
    {
    case 1:

        do{
            printf("\nNome do cliente -> ");
            setbuf(stdin, NULL);
            scanf("%[^\n]", cliente.Nome);
        } 
        while(!Nome_Valido(cliente.Nome));

        while(fscanf(Consultar_Hospede, "%s %s %s %s %39[^\n]",
        T_cliente.CPF, T_cliente.RG, T_cliente.Telefone, T_cliente.Email, T_cliente.Nome) == 5)
        {
            if(strstr(T_cliente.Nome, cliente.Nome) != NULL)
            {
                printf("\n______INFORMAÇÕES DO CLIENTE_____\n");
                printf("Nome     \t%s\n", T_cliente.Nome);
                printf("CPF      \t%s\n", T_cliente.CPF);
                printf("RG       \t%s\n", T_cliente.RG);
                printf("Telefone \t%s\n", T_cliente.Telefone);
                printf("Email    \t%s\n", T_cliente.Email);
                linha(LINHA - 10);
                EXISTE = 1;
                break;
            }
        }

        if(EXISTE == 0) printf("\nNome digitado errado ou não cadastrado!\n");
        break;

    case 2: 

        EXISTE = 0;

        do{
            printf("\nTelefone do cliente -> ");
            setbuf(stdin, NULL); 
            scanf("%[^\n]", cliente.Telefone);
        } 
        while(!Telefone_Valido(cliente.Telefone));
    
        while(fscanf(Consultar_Hospede, "%s %s %s %s %39[^\n]",
        T_cliente.CPF, T_cliente.RG, T_cliente.Telefone, cliente.Email, cliente.Nome) == 5)
        {
            if(strstr(T_cliente.Telefone, cliente.Telefone) != NULL)
            {
                printf("\n______INFORMAÇÕES DO CLIENTE_____\n");
                printf("Nome     \t%s\n", T_cliente.Nome);
                printf("CPF      \t%s\n", T_cliente.CPF);
                printf("RG       \t%s\n", T_cliente.RG);
                printf("Telefone \t%s\n", T_cliente.Telefone);
                printf("Email    \t%s\n", T_cliente.Email);
                linha(LINHA - 10);
                EXISTE = 1;
                break;
            }
        }
        if(EXISTE == 0) printf("\nTelefone digitado errado ou não cadastrado!\n");
        break;

    case 3: 

        do{
            printf("\nEmail do cliente -> ");
            setbuf(stdin, NULL);
            scanf("%[^\n]", cliente.Email);
        } 
        while(!Email_valido(cliente.Email));

        while(fscanf(Consultar_Hospede, "%s %s %s %s %[^\n]",
        T_cliente.CPF, T_cliente.RG, T_cliente.Telefone, T_cliente.Email, T_cliente.Nome) == 5)
        {
            if(strstr(T_cliente.Email, cliente.Email) != NULL)
            {
                printf("\n_______INFORMAÇÕES DO CLIENTE_______\n");
                printf("Nome     \t%s\n", T_cliente.Nome);
                printf("CPF      \t%s\n", T_cliente.CPF);
                printf("RG       \t%s\n", T_cliente.RG);
                printf("Telefone \t%s\n", T_cliente.Telefone);
                printf("Email    \t%s\n", T_cliente.Email);
                linha(LINHA - 10);
                EXISTE = 1;
                break;
            }
        }
        if(EXISTE == 0) printf("\nEmail digitado errado ou não cadastrado!\n");
        break;
    
    case 4: 

        do{
            printf("\nCPF do cliente -> "); 
            setbuf(stdin, NULL); 
            scanf("%[^\n]", cliente.CPF);
        } 
        while(!CPF_Valido(cliente.CPF));

        while(fscanf(Consultar_Hospede, "%s %s %s %s %[^\n]",
        T_cliente.CPF, T_cliente.RG, T_cliente.Telefone, T_cliente.Email, T_cliente.Nome) == 5)
        {
            if(strstr(T_cliente.CPF, cliente.CPF) != NULL)
            {
                printf("\n_______INFORMAÇÕES DO CLIENTE_______\n");
                printf("Nome     \t%s\n", T_cliente.Nome);
                printf("CPF      \t%s\n", T_cliente.CPF);
                printf("RG       \t%s\n", T_cliente.RG);
                printf("Telefone \t%s\n", T_cliente.Telefone);
                printf("Email    \t%s\n", T_cliente.Email);
                linha(LINHA - 10);
                EXISTE = 1;
                break;
            }
        }
        if(EXISTE == 0) printf("\nCPF digitado errado ou não cadastrado!\n");
        break;
    }
    
    fclose(Consultar_Hospede);
}

void Editar_Cliente()
{
    S_Cliente cliente;
    S_Cliente T_cliente;

    FILE *Editar_Hospede = fopen("Clientes.txt", "r");
    FILE *Editar_Temp = fopen("Clientes_temp.txt", "a");

    if(Editar_Hospede == NULL)
    {
        printf("\nERRO ao abrir arquivo!\n");
        exit(EXIT_FAILURE);
    }
    else if(Editar_Temp == NULL)
    {
        printf("\nERRO ao abrir arquivo!\n");
        exit(EXIT_FAILURE);
    }

    do{
        printf("\n[0] - Voltar\n");
        printf("[1] - Telefone\n");
        printf("[2] - Email\n");
        printf("Sua escolha -> "), scanf("%d", &ESCOLHA);  
    } 
    while(!Verifica_Escolha(2, 0, ESCOLHA));

    if(ESCOLHA == 0) return;

    do{
        printf("\nCPF do cliente para modificar -> "); 
        setbuf(stdin, NULL); 
        scanf("%[^\n]", cliente.CPF);
    } 
    while(!CPF_Valido(cliente.CPF));
    
    switch(ESCOLHA)
    {
    case 1:

        do{
            printf("\nNovo telefone do cliente -> ");
            setbuf(stdin, NULL); 
            scanf("%[^\n]", cliente.Telefone);
        } 
        while(!Telefone_Valido(cliente.Telefone));

        while(fscanf(Editar_Hospede, "%s %s %s %s %[^\n]",
        T_cliente.CPF, T_cliente.RG, T_cliente.Telefone, T_cliente.Email, T_cliente.Nome) == 5)
        {
            if(strstr(T_cliente.CPF, cliente.CPF) == NULL)
            {
                fprintf(Editar_Temp, "%s %s %s %s %s\n", T_cliente.CPF, T_cliente.RG, T_cliente.Telefone, T_cliente.Email, T_cliente.Nome);
            }
            else 
            {
                fprintf(Editar_Temp, "%s %s %s %s %s\n", T_cliente.CPF, T_cliente.RG, cliente.Telefone, T_cliente.Email, T_cliente.Nome);
            }
        }
        break;

    case 2: 

        do{
            printf("\nNovo email do cliente -> ");
            setbuf(stdin, NULL);
            scanf("%[^\n]", cliente.Email);
        } 
        while(!Email_valido(cliente.Email));

        while(fscanf(Editar_Hospede, "%s %s %s %s %[^\n]",
        T_cliente.CPF, T_cliente.RG, T_cliente.Telefone, T_cliente.Email, T_cliente.Nome) == 5)
        {
            if(strstr(T_cliente.CPF, cliente.CPF) == NULL)
            {
                fprintf(Editar_Temp, "%s %s %s %s %s\n", T_cliente.CPF, T_cliente.RG, T_cliente.Telefone, T_cliente.Email, T_cliente.Nome);
            }
            else 
            {
                fprintf(Editar_Temp, "%s %s %s %s %s\n", T_cliente.CPF, T_cliente.RG, T_cliente.Telefone, cliente.Email, T_cliente.Nome);
            }
        }
        break;
    }

    fclose(Editar_Hospede);
    fclose(Editar_Temp);

    remove("Clientes.txt");
    rename("Clientes_temp.txt", "Clientes.txt");
}

//_______________________________________
// ------------ FINANÇAS ----------------
//_______________________________________

typedef struct {
    int Dia;
    int Mes;
    int Ano;
    char hora_entrada[12];
    char hora_saida[12];
    long int juliana_Entrada;
    long int juliana_Saida;
} Data;

typedef struct 
{
    int Quarto;
    char CPF[17];
    float Valor;
    char Pagamento[20];
    char Data_Entrada[12];
    char Data_Saida[12];
    int codigo;
    char Nome[40];
} S_Financas;

typedef struct {
    int hora;
    int minuto;
} Horario;

Horario Hora_Atual()
{
    Horario horario;
    
    time_t t;
    struct tm *info;

    time(&t);
    info = localtime(&t);

    horario.hora = info->tm_hour;
    horario.minuto = info->tm_min;

    return horario;
}

bool Validar_Dias(int dia)
{
    while(getchar() != '\n');   

    if(dia < 1) 
    {
        printf("\nQuantidade invalida!\n");
        return false;
    }

    return true;
}

//1- dia / 2 - mes / 3 - ano 
bool Validar_DiaMesANo(int DiaMesAno, int modo)
{
    Data hoje;

    time_t t; struct tm *now;
    time(&t); now = localtime(&t);

    hoje.Ano = now->tm_year + 1900; 

    if(modo == 1)
    {
        if(DiaMesAno < 1 || DiaMesAno > 31)
        {
            printf("\nDia inválido! Tente novamente!\n");
            return false;
        }
    }
    else if(modo == 2)
    {
        if(DiaMesAno < 1 || DiaMesAno > 12) 
        {
            printf("\nMês inválido! Tente novamente!\n");
            return false;
        }
    }
    else if(modo == 3)
    {
        if(DiaMesAno < hoje.Ano) 
        {
            printf("\nEsse ano já passou! Tente novamente!\n");
            return false;
        }

        else if(DiaMesAno >= hoje.Ano + 2)
        {
            printf("\nSó realizamos até dezembro de %d", hoje.Ano + 1);
            return false;
        }
    }
    else if(modo == 4)
    {
        if(DiaMesAno < 2010)
        {
            printf("\nAno inválido! Só temos dados até 2010\n");
            return false;
        }
    }

    return true;
}

bool DiaMesAnoGETCHAR(int DiaMesAno, int modo)
{
    Data hoje;

    time_t t; struct tm *now;
    time(&t); now = localtime(&t);

    hoje.Ano = now->tm_year + 1900; 
    
    while(getchar() != '\n');

    if(modo == 1)
    {
        if(DiaMesAno < 1 || DiaMesAno > 31)
        {
            printf("\nDia inválido! Tente novamente!\n");
            return false;
        }
    }
    else if(modo == 2)
    {
        if(DiaMesAno < 1 || DiaMesAno > 12) 
        {
            printf("\nMês inválido! Tente novamente!\n");
            return false;
        }
    }
    else if(modo == 3)
    {
        if(DiaMesAno < hoje.Ano) 
        {
            printf("\nEsse ano já passou! Tente novamente!\n");
            return false;
        }

        else if(DiaMesAno >= hoje.Ano + 2)
        {
            printf("\nSó realizamos até dezembro de %d", hoje.Ano + 1);
            return false;
        }
    }
    else if(modo == 4)
    {
        if(DiaMesAno < 2010)
        {
            printf("\nAno inválido! Só temos dados até 2010\n");
            return false;
        }
    }

    return true;
}

// gregoriana -> juliana
int gregoriana_juliana(int dia, int mes, int ano)
{
	int juliana;

	juliana = (1461 * (ano + 4800 + (mes - 14) / 12)) / 4 + (367 * (mes - 2 - 12 * ((mes - 14) / 12))) / 12 - (3 * ((ano + 4900 + (mes - 14) / 12) / 100)) / 4 + dia - 32075;
	
	return juliana;
}

// juliana -> gregoriana 
void juliana_para_gregoriana(long int juliana, Data *data) 
{
    int b, n, k, j;

    b = juliana + 68569;
    n = (4 * b) / 146097;
    b = b - ((146097 * n + 3) / 4);
    k = 4000 * (b + 1) / 1461001;
    b = b - (1461 * k) / 4 + 31;
    j = (80 * b) / 2447;
    data->Dia = b - (2447 * j) / 80;
    b = (j / 11);
    data->Mes = j + 2 - (12 * b);
    data->Ano = 100 * (n - 49) + k + b;
}

void Formatar_Data(Data *data, S_Financas *financa, int modo)
{ 
    if(modo == 1)
    {
        juliana_para_gregoriana(data->juliana_Entrada, data);
        sprintf(financa->Data_Entrada,"%d/%d/%d", data->Dia, data->Mes, data->Ano);

        juliana_para_gregoriana(data->juliana_Saida, data);
        sprintf(financa->Data_Saida,"%d/%d/%d",data->Dia, data->Mes, data->Ano);

    }
}

// Conseguir a data juliana
// 1 - hoje / 2 - manual
Data obterDataAtual(int q_dias, int modo)
{
    Data dataAtual = {0};
    int ano, dia, mes;
    time_t timer; struct tm *agora;
    time_t t; struct tm *momento;

    switch(modo)
    {
    case 1:
        
        time(&timer); agora = localtime(&timer);

        long int juliana;

        dia = agora->tm_mday;
        mes = agora->tm_mon + 1; 
        ano = agora->tm_year + 1900; 

        juliana = gregoriana_juliana(dia, mes, ano);

        dataAtual.juliana_Entrada = juliana; 

        dataAtual.juliana_Saida = juliana + q_dias;

        return dataAtual;
        break;

    case 2: 

        time(&t); momento = localtime(&t);

        long int juliana_user;
        long int juliana_hoje;

        dia = momento->tm_mday;
        mes = momento->tm_mon + 1; 
        ano = momento->tm_year + 1900; 

        while(true)
        {

            do{
                printf("\nDIA -> ");
                scanf("%d", &dataAtual.Dia);
            }
            while(!DiaMesAnoGETCHAR(dataAtual.Dia, 1));

            do{
                printf("\nMÊS -> ");
                scanf("%d", &dataAtual.Mes);
            }
            while(!DiaMesAnoGETCHAR(dataAtual.Mes, 2));

            do{
                printf("\nANO -> ");
                scanf("%d", &dataAtual.Ano);
            }
            while(!DiaMesAnoGETCHAR(dataAtual.Ano, 3)); 

            juliana_hoje = gregoriana_juliana(dia, mes, ano);
            juliana_user = gregoriana_juliana(dataAtual.Dia, dataAtual.Mes, dataAtual.Ano);

            if(juliana_hoje > juliana_user)
                printf("\nDATA INVÁLIDA! TENTE NOVAMENTE!\n");
            else
                break;
        }
        
        do{
            printf("\nQuantos dias de estadia -> ");
            scanf("%d", &q_dias);
        } 
        while(!Validar_Dias(q_dias));
        
        dataAtual.Dia = q_dias;
        dataAtual.juliana_Entrada = juliana_user; 
        dataAtual.juliana_Saida = juliana_user + q_dias;

        return dataAtual;
        break;
    
    default:
        break;
    }

    return dataAtual;
}

int Gerar_Cod() 
{
    srand(time(NULL));
    return rand() % 10000;
}

// modo 1 - valida a formatação 2 - Valida cliente 3 - Gerar novo codigo
bool Validar_Codigo(int codigo, int modo)
{
    FILE *Fluxo_Cod = fopen("Fluxo.txt", "r");

    if(Fluxo_Cod == NULL)
    {
        printf("\nERRO ao abrir arquivo!\n");
        exit(EXIT_FAILURE);
    }

    S_Financas financa;
    Data data;

    if(modo == 1)
    {
        while(getchar() != '\n');

        if(codigo < 0)
        {
            printf("CODIGO INVÁLIDO! TENTE NOVAMENTE");
            return false;
        }

        return true;
    }
    else if(modo == 2)
    {
        while(fscanf(Fluxo_Cod, "%d %d %s %f %ld %ld %s %s %s %[^\n]",
        &financa.codigo, &financa.Quarto, financa.CPF, &financa.Valor, &data.juliana_Entrada, &data.juliana_Saida, data.hora_entrada, data.hora_saida,financa.Pagamento, financa.Nome) == 10)
        {
            if(financa.codigo == codigo)
            {
                fclose(Fluxo_Cod);
                return true;
            }
        }

        printf("\nNÃO EXISTE CLIENTE COM ESTE CODIGO!\n");
        fclose(Fluxo_Cod);
        return false;
    }
    else if(modo == 3) 
    {
        rewind(Fluxo_Cod);

        while(fscanf(Fluxo_Cod, "%d %d %s %f %ld %ld %s %s %s %[^\n]",
        &financa.codigo, &financa.Quarto, financa.CPF, &financa.Valor, &data.juliana_Entrada, &data.juliana_Saida, data.hora_entrada, data.hora_saida,financa.Pagamento, financa.Nome) == 10)
        {
            if(financa.codigo == codigo && (strstr(financa.Pagamento, "Pendente") != NULL))
            {
                fclose(Fluxo_Cod);
                return false;
            }
        }

        fclose(Fluxo_Cod);
        return true;
    }

    fclose(Fluxo_Cod);
    return false;
}

// 1 - Definir entrada / 2 - Definir saida / 3 - Indefinido
void Converter_Horario(Data *data, Horario *horario, int modo)
{
    *horario = Hora_Atual(); 

    switch(modo)
    {
    case 1:
        sprintf(data->hora_entrada, "%02d:%02d", horario->hora, horario->minuto);
        strcpy(data->hora_saida, "INDEFINIDO");
        break;
    case 2: 
        sprintf(data->hora_saida, "%02d:%02d", horario->hora, horario->minuto);
        break;
    
    case 3:
        strcpy(data->hora_entrada, "INDEFINIDO");
        strcpy(data->hora_saida, "INDEFINIDO");
        break;
    }
}

void Excluir_Cliente()
{
    S_Cliente cliente;
    S_Cliente T_cliente;
    S_Financas financa;
    Data data;

    FILE *Excluir_Fluxo = fopen("Fluxo.txt", "r");

    if(Excluir_Fluxo == NULL)
    {
        printf("\nERRO ao abrir arquivo!\n");
        exit(EXIT_FAILURE);
    }

    do{
        printf("\nCPF do cliente para excluir -> ");
        setbuf(stdin, NULL);
        scanf("%[^\n]", cliente.CPF);
    } 
    while(!CPF_Valido(cliente.CPF));

    while(fscanf(Excluir_Fluxo, "%d %d %s %f %ld %ld %s %s %s %[^\n]",
    &financa.codigo, &financa.Quarto, financa.CPF, &financa.Valor, &data.juliana_Entrada, &data.juliana_Saida, data.hora_entrada, data.hora_saida,financa.Pagamento, financa.Nome) == 10)
    {
        if((strstr(cliente.CPF,financa.CPF) != NULL) && (strstr(financa.Pagamento, "Pendente") != NULL))
        {
            printf("\nO cliente tem uma reserva pendente, não pode ser excluido!\n");
            fclose(Excluir_Fluxo);
            return;
        }
    }

    FILE *Excluir_Hospede = fopen("Clientes.txt", "r");
    FILE *Excluir_Temp = fopen("Clientes_temp.txt", "a");

    while(fscanf(Excluir_Hospede, "%s %s %s %s %[^\n]",
    T_cliente.CPF, T_cliente.RG, T_cliente.Telefone, T_cliente.Email, T_cliente.Nome) == 5)
    {
        if(strstr(T_cliente.CPF, cliente.CPF) == NULL)
        {
            fprintf(Excluir_Temp, "%s %s %s %s %s\n",
            T_cliente.CPF, T_cliente.RG, T_cliente.Telefone, T_cliente.Email, T_cliente.Nome);
        }
    }
   
    fclose(Excluir_Hospede);
    fclose(Excluir_Temp);
    fclose(Excluir_Fluxo);

    remove("Clientes.txt");
    rename("Clientes_temp.txt", "Clientes.txt");
}

// Verifica se o cliente tem uma reserva a ser paga, não podendo fazer outra
int Verifica_Reserva(char *CPF)
{      
    FILE *Fluxo_CPF = fopen("Fluxo.txt", "r");

    if(Fluxo_CPF == NULL)
    {
        printf("\nERRO ao abrir arquivo!\n");
        exit(EXIT_FAILURE);
    }

    S_Financas financa;
    Data data;

    while(fscanf(Fluxo_CPF, "%d %d %s %f %ld %ld %s %s %s %[^\n]",
    &financa.codigo, &financa.Quarto, financa.CPF, &financa.Valor, &data.juliana_Entrada, &data.juliana_Saida, data.hora_entrada, data.hora_saida,financa.Pagamento, financa.Nome) == 10)
    {
        if((strstr(CPF, financa.CPF) != NULL) && (strstr(financa.Pagamento, "Pendente") != NULL))
        {
            printf("\nCliente ainda tem uma reserva pendente!\n");
            fclose(Fluxo_CPF);
            return 2;
        }
    }

    fclose(Fluxo_CPF);
    return 0;
}

bool Verifica_Disponibilidade(S_Financas *usuario, Data *julia)
{
    FILE *Fluxo_Disponivel = fopen("Fluxo.txt", "r");

    if(Fluxo_Disponivel == NULL)
    {
        printf("\nERRO ao abrir arquivo!\n");
        exit(EXIT_FAILURE);
    }

    S_Financas financa;
    Data data;

    while(fscanf(Fluxo_Disponivel, "%d %d %s %f %ld %ld %s %s %s %[^\n]",
    &financa.codigo, &financa.Quarto, financa.CPF, &financa.Valor, &data.juliana_Entrada, &data.juliana_Saida, data.hora_entrada, data.hora_saida,financa.Pagamento, financa.Nome) == 10)
    {
        if((usuario->Quarto == financa.Quarto) && (strstr(financa.Pagamento, "Pendente") != 0))
        {
            if((julia->juliana_Entrada <=  data.juliana_Entrada) && (data.juliana_Entrada <= julia->juliana_Saida))
            {
                printf("\nA data que você escolheu já está reservada!\n");
                fclose(Fluxo_Disponivel);
                return false;
            }
            else if((julia->juliana_Entrada <= data.juliana_Saida) && (data.juliana_Saida) <= julia->juliana_Saida)
            {
                printf("\nA data que você escolheu já está reservada!\n");
                fclose(Fluxo_Disponivel);
                return false;
            }
            else if((julia->juliana_Entrada < data.juliana_Entrada) &&
            (julia->juliana_Saida > data.juliana_Saida))
            {
                printf("\nO intervalo entre sua reserva já está ocupado!\n");
                fclose(Fluxo_Disponivel);
                return false;
            }
        }
    }

    return true;
}

void Realizar_Reserva()
{
    FILE *Fluxo_Reserva = fopen("Fluxo.txt", "a");
    FILE *Cliente_Reserva = fopen("Clientes.txt", "r");
    FILE *Quartos_Reserva = fopen("Quartos.txt", "r");

    if(Fluxo_Reserva == NULL)
    {
        printf("\nERRO ao abrir arquivo!\n");
        exit(EXIT_FAILURE);
    }
    else if(Cliente_Reserva == NULL)
    {
        printf("\nERRO ao abrir arquivo!\n");
        exit(EXIT_FAILURE);
    }
    else if(Quartos_Reserva == NULL)
    {
        printf("\nERRO ao abrir arquivo!\n");
        exit(EXIT_FAILURE);
    }

    S_Cliente T_cliente; 
    S_Financas financa; 
    S_Quarto quarto_T; 
    Horario horario;
    Data data;
    int q_dias;

    do{
        printf("\nEscolha o número do quarto -> ");
        scanf("%d", &financa.Quarto);
    }
    while(!Verificar_Hospedagem(financa.Quarto));

    do{
        Exibir_Quartos();

        do{
            printf("\n___DEFINIR DATA DE RESERVA___\n");
            printf("[1] - Definir para hoje\n");
            printf("[2] - Definir manualmente\n");
            linha(LINHA - 16);
            printf("Sua escolha -> ");
            scanf("%d", &ESCOLHA);
        }
        while(!Verifica_Escolha(2, 1, ESCOLHA));

        if(ESCOLHA == 1)
        {
            do{
                printf("\nQuantos dias de estadia -> ");
                scanf("%d", &q_dias);
            }
            while(!Validar_Dias(q_dias));

            data = obterDataAtual(q_dias, 1);
        }
        else
        {
            data = obterDataAtual(q_dias, 2);
            q_dias = data.Dia;
        }
    }
    while(!Verifica_Disponibilidade(&financa, &data));


    while(fscanf(Quartos_Reserva, "%d %s %s %f\n",
    &quarto_T.Num, quarto_T.Tipo, quarto_T.Status, &quarto_T.Diaria) == 4) 
    {
        if(financa.Quarto == quarto_T.Num)
        {
            financa.Valor = quarto_T.Diaria;
            break;
        } 
    }

    printf("\nO valor da estadia será de $%.2f\n", financa.Valor * q_dias);
    
    do{
        EXISTE = 0;

        rewind(Cliente_Reserva);

        do{
            printf("\nCPF do Cliente -> ");
            setbuf(stdin, NULL);
            scanf("%[^\n]", financa.CPF);
        } 
        while(!CPF_Valido(financa.CPF));

        while(fscanf(Cliente_Reserva, "%s %s %s %s %[^\n]",
        T_cliente.CPF, T_cliente.RG, T_cliente.Telefone, T_cliente.Email, T_cliente.Nome) == 5)
        {
            if(strstr(T_cliente.CPF, financa.CPF) != NULL)
            {
                EXISTE = Verifica_Reserva(financa.CPF);

                if(EXISTE == 2) 
                    break;

                strcpy(financa.Nome, T_cliente.Nome);
                strcpy(financa.Pagamento, "Pendente");
    
                EXISTE = 1;
                break;
            }
        }

        if(EXISTE == 0) printf("\nCPF não cadastrado!\n");
    } 
    while (EXISTE != 1);

    do{
        financa.codigo = Gerar_Cod();
    } 
    while(!Validar_Codigo(financa.codigo, 3));

    printf("\n------------------------------------------------\n");
    printf("           SEU CODIGO DE RESERVA É [%d]          \n", financa.codigo);
    printf("------------------------------------------------\n");


    Converter_Horario(&data, &horario, 3);

    fprintf(Fluxo_Reserva, "%d %d %s %.2f %ld %ld %s %s %s %s\n",
    financa.codigo, financa.Quarto, financa.CPF, financa.Valor, data.juliana_Entrada, data.juliana_Saida, data.hora_entrada, data.hora_saida,financa.Pagamento, financa.Nome);

    Editar_Reserva(financa.Quarto);

    fclose(Fluxo_Reserva);
    fclose(Cliente_Reserva);
    fclose(Quartos_Reserva);
}

void Consultar_Reserva()
{
    FILE *Fluxo_Consultar = fopen("Fluxo.txt", "r");

    if(Fluxo_Consultar == NULL)
    {
        printf("\nERRO ao abrir arquivo!\n");
        exit(EXIT_FAILURE);
    }

    S_Financas financa, F_temp;
    Data data; 
    EXISTE = 0;

    do{
        printf("\n_______COMO REALIZAR CONSULTA______\n");
        printf("[1] - CPF\n");
        printf("[2] - Codigo de reserva\n");
        printf("Sua escolha -> ");
        linha(LINHA - 10);
        scanf("%d", &ESCOLHA);
    } while(!Verifica_Escolha(2, 1, ESCOLHA));

    switch(ESCOLHA)
    {
    case 1:

        do{
            printf("\nCPF do cliente -> ");
            setbuf(stdin, NULL);
            scanf("%[^\n]", F_temp.CPF);
        }
        while(!CPF_Valido(F_temp.CPF));

        while(fscanf(Fluxo_Consultar, "%d %d %s %f %ld %ld %s %s %s %[^\n]",
        &financa.codigo, &financa.Quarto, financa.CPF, &financa.Valor, &data.juliana_Entrada, &data.juliana_Saida, data.hora_entrada, data.hora_saida,financa.Pagamento, financa.Nome) == 10)
        {
            if(strstr(F_temp.CPF, financa.CPF) != NULL)
            {

                Formatar_Data(&data, &financa, 1);

                printf("\n__________INFORMAÇÕES DO HOSPEDE__________\n");
                printf("Nome do hospede         %s\n", financa.Nome);
                printf("Codigo de reserva       %d\n", financa.codigo);
                printf("Número do quarto        %d\n", financa.Quarto);
                printf("CPF do hospede          %s\n", financa.CPF);
                printf("Valor da reserva        %.2f\n", financa.Valor);
                printf("Data de reserva         %s\n", financa.Data_Entrada);
                printf("Data de saida           %s\n", financa.Data_Saida);
                printf("Status de pagamento     %s\n", financa.Pagamento);
                printf("Hora de check-in        %s\n", data.hora_entrada);
                printf("Hora de ckeck-out       %s\n", data.hora_saida);
                linha(LINHA);
                EXISTE = 1;
                break;
            }
        }

        if(EXISTE == 0) printf("Não cadastrado!\n");
        break;
    
    case 2: 

        do{
            printf("Codigo do cliente -> ");
            scanf("%d", &F_temp.codigo);

            while(getchar() != '\n');
        }
        while(F_temp.codigo < 0);
        
        while(fscanf(Fluxo_Consultar, "%d %d %s %f %ld %ld %s %s %s %[^\n]",
        &financa.codigo, &financa.Quarto, financa.CPF, &financa.Valor, &data.juliana_Entrada, &data.juliana_Saida, data.hora_entrada, data.hora_saida,financa.Pagamento, financa.Nome) == 10)
        {
            if(F_temp.codigo == financa.codigo)
            {
                Formatar_Data(&data, &financa, 1);

                printf("\n__________INFORMAÇÕES DO HOSPEDE__________\n");
                printf("Nome do hospede         %s\n", financa.Nome);
                printf("Codigo de reserva       %d\n", financa.codigo);
                printf("Número do quarto        %d\n", financa.Quarto);
                printf("CPF do hospede          %s\n", financa.CPF);
                printf("Valor da reserva        %.2f\n", financa.Valor);
                printf("Data de reserva         %s\n", financa.Data_Entrada);
                printf("Data de saida           %s\n", financa.Data_Saida);
                printf("Status de pagamento     %s\n", financa.Pagamento);
                printf("Hora de check-in        %s\n", data.hora_entrada);
                printf("Hora de ckeck-out       %s\n", data.hora_saida);
                linha(LINHA);
                EXISTE = 1;
                break;
            }
        }

        if(EXISTE == 0) printf("Não há reserva com esse codigo!\n");
        break;
    
    default:
        break;
    }

    fclose(Fluxo_Consultar);
}

bool Existe_Reserva(int codigo, char *CPF,int modo)
{
    while(getchar() != '\n');

    FILE *Fluxo_Check = fopen("Fluxo.txt", "r");

    if(Fluxo_Check == NULL)
    {
        printf("\nERRO ao abrir o arquivo!\n");
        exit(EXIT_FAILURE);
    }

    S_Financas financa;
    Data data; 

    if(modo == 1)
    {
        while(fscanf(Fluxo_Check, "%d %d %s %f %ld %ld %s %s %s %[^\n]",
        &financa.codigo, &financa.Quarto, financa.CPF, &financa.Valor, &data.juliana_Entrada, &data.juliana_Saida, data.hora_entrada, data.hora_saida,financa.Pagamento, financa.Nome) == 10)
        {
            if(codigo == financa.codigo && strstr(financa.Pagamento, "Pago") == NULL)
            {
                if(strstr(data.hora_entrada, "INDEFINIDO") == NULL)
                {
                    printf("\nCliente já fez o check-in\n");
                    return false;
                }

                fclose(Fluxo_Check);
                return true;
            }
        }

        printf("Codigo inexistente!\n");

        fclose(Fluxo_Check);

        return false;
    }
    else if(modo == 2)
    {
        while(fscanf(Fluxo_Check, "%d %d %s %f %ld %ld %s %s %s %[^\n]",
        &financa.codigo, &financa.Quarto, financa.CPF, &financa.Valor, &data.juliana_Entrada, &data.juliana_Saida, data.hora_entrada, data.hora_saida,financa.Pagamento, financa.Nome) == 10)
        {

            if((codigo == financa.Quarto) && (strstr(financa.Pagamento, "Pendente")) != NULL && strstr(CPF, financa.CPF) == NULL)
            {
                fclose(Fluxo_Check);
                return true;
            }
        }

        fclose(Fluxo_Check);
    }

    return false;
}

void Exit(FILE *file)
{
    if(file == NULL)
    {
        printf("\nERRO ao abrir arquivo!\n");
        exit(EXIT_FAILURE);
    }
}

void Realizar_Pagamento(int modo, int cod)
{
    FILE *Fluxo_Excluir = fopen("Fluxo.txt", "r");
    FILE *Fluxo_Temp = fopen("Fluxo_temp.txt", "a");

    FILE *Quartos_SemReserva = fopen("Quartos.txt", "r");
    FILE *Quartos_Temp = fopen("Quartos_temp.txt", "a");

    Exit(Fluxo_Excluir);
    Exit(Fluxo_Temp);
    Exit(Quartos_SemReserva);
    Exit(Quartos_Temp);

    S_Financas financa, F_temp;
    S_Quarto quarto_T;
    Horario horario;
    Data data; 
    char CPF[15];
    int num;

    switch(modo)
    {
    case 1:

        do{
            printf("\nCodigo do cliente -> ");
            scanf("%d", &F_temp.codigo);
        }
        while(!Validar_Codigo(F_temp.codigo, 2));

        while(fscanf(Fluxo_Excluir, "%d %d %s %f %ld %ld %s %s %s %[^\n]",
        &financa.codigo, &financa.Quarto, financa.CPF, &financa.Valor, &data.juliana_Entrada, &data.juliana_Saida, data.hora_entrada, data.hora_saida,financa.Pagamento, financa.Nome) == 10)
        {
            if(F_temp.codigo != financa.codigo)
            {
                fprintf(Fluxo_Temp, "%d %d %s %.2f %ld %ld %s %s %s %s\n",
                financa.codigo, financa.Quarto, financa.CPF, financa.Valor, data.juliana_Entrada, data.juliana_Saida, data.hora_entrada, data.hora_saida,financa.Pagamento, financa.Nome);
            }
            else if(strstr(financa.Pagamento, "Pago") == NULL)
            {
                if(strstr(data.hora_entrada, "INDEFINIDO") != NULL)
                {
                    printf("\nCliente não realizou o check-in!\n");
                    return;
                }

                Data hoje = obterDataAtual(0, 1);

                hoje.Dia = data.juliana_Saida - data.juliana_Entrada;
                hoje.Mes = data.juliana_Saida - hoje.juliana_Entrada;
                int pagamento = abs(hoje.Dia - hoje.Mes);

                financa.Valor *= pagamento + 1;

                printf("O valor total a ser pago é de $%.2f\n", financa.Valor);

                num = financa.Quarto;
                strcpy(CPF, financa.CPF);
                strcpy(financa.Pagamento, "Pago");

                Converter_Horario(&data, &horario, 2);

                fprintf(Fluxo_Temp, "%d %d %s %.2f %ld %ld %s %s %s %s\n",
                financa.codigo, financa.Quarto, financa.CPF, financa.Valor, data.juliana_Entrada, hoje.juliana_Saida, data.hora_entrada, data.hora_saida,financa.Pagamento, financa.Nome);
            }
            else
            {
                printf("\nPagamento já foi realizado!\n");
                return;
            }
        }

        while(fscanf(Quartos_SemReserva, "%d %s %s %f\n",
        &quarto_T.Num, quarto_T.Tipo, quarto_T.Status, &quarto_T.Diaria) == 4)
        {
            if(num == quarto_T.Num)
            {
                if(Existe_Reserva(num, CPF, 2)) 
                    strcpy(quarto_T.Status, "Reservado");
                else
                    strcpy(quarto_T.Status, "Livre");

                fprintf(Quartos_Temp, "%d %s %s %.2f\n",
                quarto_T.Num, quarto_T.Tipo, quarto_T.Status, quarto_T.Diaria);
            }
            else
            {
                fprintf(Quartos_Temp, "%d %s %s %.2f\n",
                quarto_T.Num, quarto_T.Tipo, quarto_T.Status, quarto_T.Diaria);
            }
        }

        break;
    
    case 2: 

        F_temp.codigo = cod;

        while(fscanf(Fluxo_Excluir, "%d %d %s %f %ld %ld %s %s %s %[^\n]",
        &financa.codigo, &financa.Quarto, financa.CPF, &financa.Valor, &data.juliana_Entrada, &data.juliana_Saida, data.hora_entrada, data.hora_saida,financa.Pagamento, financa.Nome) == 10)
        {
            if(F_temp.codigo != financa.codigo)
            {
                fprintf(Fluxo_Temp, "%d %d %s %.2f %ld %ld %s %s %s %s\n",
                financa.codigo, financa.Quarto, financa.CPF, financa.Valor, data.juliana_Entrada, data.juliana_Saida, data.hora_entrada, data.hora_saida,financa.Pagamento, financa.Nome);
            }
            else
            {
                int pagamento = data.juliana_Saida - data.juliana_Entrada;

                financa.Valor *= pagamento + 1;
                num = financa.Quarto;

                strcpy(CPF, financa.CPF);
                strcpy(financa.Pagamento, "Pago");

                Converter_Horario(&data, &horario, 2);

                fprintf(Fluxo_Temp, "%d %d %s %.2f %ld %ld %s %s %s %s\n",
                financa.codigo, financa.Quarto, financa.CPF, financa.Valor, data.juliana_Entrada, data.juliana_Saida, data.hora_entrada, data.hora_saida,financa.Pagamento, financa.Nome);
            } 
        }

        while(fscanf(Quartos_SemReserva, "%d %s %s %f\n",
        &quarto_T.Num, quarto_T.Tipo, quarto_T.Status, &quarto_T.Diaria) == 4)
        {
            if(num == quarto_T.Num)
            {
                if(Existe_Reserva(num, CPF, 2)) 
                    strcpy(quarto_T.Status, "Reservado");
                else
                    strcpy(quarto_T.Status, "Livre");

                fprintf(Quartos_Temp, "%d %s %s %.2f\n",
                quarto_T.Num, quarto_T.Tipo, quarto_T.Status, quarto_T.Diaria);
            }
            else
            {
                fprintf(Quartos_Temp, "%d %s %s %.2f\n",
                quarto_T.Num, quarto_T.Tipo, quarto_T.Status, quarto_T.Diaria);
            }
        }
        break;
    }
    
    fclose(Quartos_SemReserva);
    fclose(Quartos_Temp);
    fclose(Fluxo_Excluir);
    fclose(Fluxo_Temp);

    remove("Quartos.txt");
    rename("Quartos_temp.txt", "Quartos.txt");

    remove("Fluxo.txt");
    rename("Fluxo_temp.txt", "Fluxo.txt");

}

void Check_in_Reserva()
{
    FILE *Fluxo_Check = fopen("Fluxo.txt", "r");
    FILE *Fluxo_Temp = fopen("Fluxo_temp.txt", "a");
    
    FILE *Quartos_Check = fopen("Quartos.txt", "r");
    FILE *Quartos_Temp = fopen("Quartos_Temp.txt", "a");

    Exit(Fluxo_Check);
    Exit(Fluxo_Temp);
    Exit(Quartos_Check);
    Exit(Quartos_Temp);

    S_Financas financa, F_temp;
    S_Quarto quarto_T;
    Horario horario;
    Data data;

    do{
        printf("\nSeu codigo de reserva -> ");
        scanf("%d", &F_temp.codigo);
    } 
    while(!Existe_Reserva(F_temp.codigo, NULL,1));

    while(fscanf(Fluxo_Check, "%d %d %s %f %ld %ld %s %s %s %[^\n]",
    &financa.codigo, &financa.Quarto, financa.CPF, &financa.Valor, &data.juliana_Entrada, &data.juliana_Saida, data.hora_entrada, data.hora_saida,financa.Pagamento, financa.Nome) == 10)
    {
        if(financa.codigo == F_temp.codigo)
        {
            Data hoje = obterDataAtual(0, 1);

            if(hoje.juliana_Entrada < data.juliana_Entrada)
            {
                printf("\nAinda não é o dia de check-in!\n");
                return;
            }
            else if(hoje.juliana_Entrada > data.juliana_Saida)
            {
                printf("\nO dia de check-in já passou, deverá ser efetuado o pagamento pela reserva!\n");
                Realizar_Pagamento(2, financa.codigo);
            }

            Converter_Horario(&data, &horario, 1);

            fprintf(Fluxo_Temp, "%d %d %s %.2f %ld %ld %s %s %s %s\n", financa.codigo, financa.Quarto, financa.CPF, financa.Valor, data.juliana_Entrada, data.juliana_Saida, data.hora_entrada, data.hora_saida,financa.Pagamento, financa.Nome);

            while(fscanf(Quartos_Check, "%d %s %s %f\n",
            &quarto_T.Num, quarto_T.Tipo, quarto_T.Status, &quarto_T.Diaria) == 4) 
            {
                if(financa.Quarto != quarto_T.Num)
                {
                    fprintf(Quartos_Temp, "%d %s %s %.2f\n",
                    quarto_T.Num, quarto_T.Tipo, quarto_T.Status, quarto_T.Diaria);
                }
                else
                {
                    strcpy(quarto_T.Status, "Ocupado");
                    fprintf(Quartos_Temp, "%d %s %s %.2f\n",
                    quarto_T.Num, quarto_T.Tipo, quarto_T.Status, quarto_T.Diaria);
                }
            }
        }
        else
        {
            fprintf(Fluxo_Temp, "%d %d %s %.2f %ld %ld %s %s %s %s\n", financa.codigo, financa.Quarto, financa.CPF, financa.Valor, data.juliana_Entrada, data.juliana_Saida, data.hora_entrada, data.hora_saida,financa.Pagamento, financa.Nome);
        }
    }
 
    fclose(Fluxo_Check);
    fclose(Fluxo_Temp);

    fclose(Quartos_Check);
    fclose(Quartos_Temp);

    remove("Fluxo.txt");
    rename("Fluxo_temp.txt", "Fluxo.txt");

    remove("Quartos.txt");
    rename("Quartos_Temp.txt", "Quartos.txt");
}

void Excluir_Reserva()
{
    FILE *Fluxo_Excluir = fopen("Fluxo.txt", "r");
    FILE *Fluxo_Temp = fopen("Fluxo_temp.txt", "a");

    FILE *Quartos_SemReserva = fopen("Quartos.txt", "r");
    FILE *Quartos_Temp = fopen("Quartos_temp.txt", "a");

    if(Fluxo_Excluir == NULL)
    {
        printf("\nERRO ao abrir arquivo!\n");
        exit(EXIT_FAILURE);
    }
    else if(Fluxo_Temp == NULL)
    {
        printf("\nERRO ao abrir arquivo!\n");
        exit(EXIT_FAILURE);
    }
    else if(Quartos_SemReserva == NULL)
    {
        printf("\nERRO ao abrir arquivo!\n");
        exit(EXIT_FAILURE);
    }
    else if(Quartos_Temp == NULL)
    {
        printf("\nERRO ao abrir arquivo!\n");
        exit(EXIT_FAILURE);
    }

    S_Financas financa, F_temp;
    S_Quarto quarto_T;
    Data data; int num;
    EXISTE = 0;

    do{
        printf("\n_______EXCLUIR RESERVA______\n");
        printf("[1] - CPF\n");
        printf("[2] - Codigo de reserva\n");
        linha(LINHA - 15);
        printf("Sua escolha -> ");
        scanf("%d", &ESCOLHA);
    } 
    while(!Verifica_Escolha(2, 1, ESCOLHA));

    switch(ESCOLHA)
    {
    case 1:

        do{
            printf("\nCPF do cliente -> ");
            setbuf(stdin, NULL);
            scanf("%[^\n]", F_temp.CPF);
        }
        while(!CPF_Valido(F_temp.CPF));

        while(fscanf(Fluxo_Excluir, "%d %d %s %f %ld %ld %s %s %s %[^\n]",
        &financa.codigo, &financa.Quarto, financa.CPF, &financa.Valor, &data.juliana_Entrada, &data.juliana_Saida, data.hora_entrada, data.hora_saida,financa.Pagamento, financa.Nome) == 10)
        {
            if(strstr(F_temp.CPF, financa.CPF) == NULL)
            {
                fprintf(Fluxo_Temp, "%d %d %s %.2f %ld %ld %s %s %s %s\n",
                financa.codigo, financa.Quarto, financa.CPF, financa.Valor, data.juliana_Entrada, data.juliana_Saida, data.hora_entrada, data.hora_saida,financa.Pagamento, financa.Nome);
            }
            else if(strstr(data.hora_entrada, "INDEFINIDO") == NULL)
            {
                if(strstr(data.hora_saida, "INDEFINIDO") != NULL)
                    printf("\nCliente já está no hotel! Não pode ser excluido!\n");

                fprintf(Fluxo_Temp, "%d %d %s %.2f %ld %ld %s %s %s %s\n",
                financa.codigo, financa.Quarto, financa.CPF, financa.Valor, data.juliana_Entrada, data.juliana_Saida, data.hora_entrada, data.hora_saida,financa.Pagamento, financa.Nome);
                EXISTE = 2;
            }
            else
            {
                strcpy(F_temp.CPF, financa.CPF); 
                num = financa.Quarto;
                EXISTE = 1;
            } 
        }

        if(EXISTE == 0)
        {
            printf("\nNão há reserva com esse CPF!\n");
            break;
        } 

        while(fscanf(Quartos_SemReserva, "%d %s %s %f\n",
        &quarto_T.Num, quarto_T.Tipo, quarto_T.Status, &quarto_T.Diaria) == 4)
        {
            if(num == quarto_T.Num)
            {
                if(Existe_Reserva(num, F_temp.CPF, 2)) 
                    strcpy(quarto_T.Status, "Reservado");
                else
                    strcpy(quarto_T.Status, "Livre");

                fprintf(Quartos_Temp, "%d %s %s %.2f\n",
                quarto_T.Num, quarto_T.Tipo, quarto_T.Status, quarto_T.Diaria);
            }
            else
            {
                fprintf(Quartos_Temp, "%d %s %s %.2f\n",
                quarto_T.Num, quarto_T.Tipo, quarto_T.Status, quarto_T.Diaria);
            }
        }
        
        break;
    
    case 2: 

        do{
            printf("\nCodigo do cliente -> ");
            scanf("%d", &F_temp.codigo);   
        } 
        while(!Validar_Codigo(F_temp.codigo, 2));
        
        while(fscanf(Fluxo_Excluir, "%d %d %s %f %ld %ld %s %s %s %[^\n]",
        &financa.codigo, &financa.Quarto, financa.CPF, &financa.Valor, &data.juliana_Entrada, &data.juliana_Saida, data.hora_entrada, data.hora_saida,financa.Pagamento, financa.Nome) == 10)
        {
            if(F_temp.codigo != financa.codigo)
            {
                fprintf(Fluxo_Temp, "%d %d %s %.2f %ld %ld %s %s %s %s\n", financa.codigo, financa.Quarto, financa.CPF, financa.Valor, data.juliana_Entrada, data.juliana_Saida, data.hora_entrada, data.hora_saida,financa.Pagamento, financa.Nome);
            }
            else if(strstr(data.hora_entrada, "INDEFINIDO") == NULL)
            {
                if(strstr(data.hora_saida, "INDEFINIDO") != NULL)
                    printf("\nCliente já está no hotel! Não pode ser excluido!\n");

                fprintf(Fluxo_Temp, "%d %d %s %.2f %ld %ld %s %s %s %s\n",
                financa.codigo, financa.Quarto, financa.CPF, financa.Valor, data.juliana_Entrada, data.juliana_Saida, data.hora_entrada, data.hora_saida,financa.Pagamento, financa.Nome);
                EXISTE = 2;
            }
            else
            {
                num = financa.Quarto;
                strcpy(F_temp.CPF, financa.CPF); 
            } 
        }

        while(fscanf(Quartos_SemReserva, "%d %s %s %f\n",
        &quarto_T.Num, quarto_T.Tipo, quarto_T.Status, &quarto_T.Diaria) == 4)
        {
            if(num == quarto_T.Num)
            {
                if(Existe_Reserva(num, F_temp.CPF, 2)) 
                    strcpy(quarto_T.Status, "Reservado");
                else
                    strcpy(quarto_T.Status, "Livre");

                fprintf(Quartos_Temp, "%d %s %s %.2f\n",
                quarto_T.Num, quarto_T.Tipo, quarto_T.Status, quarto_T.Diaria);
            }
            else
            {
                fprintf(Quartos_Temp, "%d %s %s %.2f\n", 
                quarto_T.Num, quarto_T.Tipo, quarto_T.Status, quarto_T.Diaria);
            }
        }
        break;
    }

    fclose(Quartos_SemReserva);
    fclose(Quartos_Temp);
    fclose(Fluxo_Excluir);
    fclose(Fluxo_Temp);

    remove("Quartos.txt");
    rename("Quartos_temp.txt", "Quartos.txt");

    remove("Fluxo.txt");
    rename("Fluxo_temp.txt", "Fluxo.txt");
}

// Validar a data recebida em Valores_Recebidos
bool Validar_Valores(char *data, Data *dados, int modo)
{
    if(strlen(data) != 10)
    {
        printf("\nEntrada inválida! Tente novamente!\n");
        return false;
    }

    for (size_t i = 0; i < strlen(data); i++)
    {
        if(((i == 2 ) && (data[i] != '/')) || ((i == 5) && (data[i] != '/')))
        {
            printf("\nEntrada inválida! Tente novamente!\n");
            return false;
        }
    }

    for (size_t i = 0; i < strlen(data); i++)
    {
        if(!(((data[i] >= '0' && data[i] <= '9') || data[i] == '/')))
        {
            printf("\nEntrada inválida! Tente novamente!\n");
            return false;
        }
    }

    if(modo == 1)
    {
        sscanf(data, "%d/%d/%d", &dados->Dia, &dados->Mes, &dados->Ano);

        if(!Validar_DiaMesANo(dados->Dia, 1)) return false;
        else if(!Validar_DiaMesANo(dados->Mes, 2)) return false;
        else if(!Validar_DiaMesANo(dados->Ano, 4)) return false;

        dados->juliana_Entrada = gregoriana_juliana(dados->Dia, dados->Mes, dados->Ano);

        return true;
    }
    else if(modo == 2)
    {
        sscanf(data, "%d/%d/%d", &dados->Dia, &dados->Mes, &dados->Ano);

        if(!Validar_DiaMesANo(dados->Dia, 1)) return false;
        else if(!Validar_DiaMesANo(dados->Mes, 2)) return false;
        else if(!Validar_DiaMesANo(dados->Ano, 4)) return false;

        dados->juliana_Saida = gregoriana_juliana(dados->Dia, dados->Mes, dados->Ano);

    }

    return true;
}

void Valores_Recebidos()
{
    FILE *Valores_Fluxo = fopen("Fluxo.txt", "r");

    if(Valores_Fluxo == NULL) 
    { 
        printf("\nERRO ao abrir arquivo!\n");
        exit(EXIT_FAILURE);
    }

    S_Financas user_financa, financa;
    Data user_data, momento;
    EXISTE = 0;
    
    while(true)
    {
        do{
            printf("\nEscreva a data inicial ( DD/MM/AAAA ) -> ");
            setbuf(stdin, NULL);
            scanf("%[^\n]", user_financa.Data_Entrada);
        }
        while(!Validar_Valores(user_financa.Data_Entrada, &user_data, 1));

        do{
            printf("\nEscreva a data final ( DD/MM/AAAA ) -> ");
            setbuf(stdin, NULL);
            scanf("%[^\n]", user_financa.Data_Saida);
        }
        while(!Validar_Valores(user_financa.Data_Saida, &user_data, 2));

        if(user_data.juliana_Entrada > user_data.juliana_Saida)
        {
            printf("Data final menor que a data inicial!\n");
            continue;
        }

        break;
    }

    printf("\n__________PAGAMENTOS REALIZADOS__________\n");

    while(fscanf(Valores_Fluxo, "%d %d %s %f %ld %ld %s %s %s %[^\n]",
    &financa.codigo, &financa.Quarto, financa.CPF, &financa.Valor, &momento.juliana_Entrada, &momento.juliana_Saida, momento.hora_entrada, momento.hora_saida,financa.Pagamento, financa.Nome) == 10)
    {
        if((momento.juliana_Saida >= user_data.juliana_Entrada) && (strstr(financa.Pagamento, "Pago") != NULL))
        {
            Formatar_Data(&momento, &financa, 1);

            printf("Nome do hospede         %s\n", financa.Nome);
            printf("Valor pago              $%.2f\n", financa.Valor);
            printf("Periodo de entrada   |  Periodo de saida\n");
            printf("   %s                 %s         \n", financa.Data_Entrada, financa.Data_Saida);
            printf("-----------------------------------------\n");
            EXISTE = 1;
        }
    }

    if(EXISTE == 0) printf("NÃO HÁ NENHUM PAGAMENTO REGISTRADO NESSE INTERVALO!\n");

    linha(LINHA - 4);

}

//_______________________________________
// ------------ PRINCIPAL ---------------
//_______________________________________

int menu()
{
    do{
        printf("\n___________MENU PRINCIPAL__________\n");
        printf("[1] - Gestão de quartos\n");
        printf("[2] - Gestão de clientes\n");
        printf("[3] - Gestão de financeira\n");
        printf("[4] - SAIR DO PROGRAMA\n");
        linha(LINHA - 10);
        printf("Sua escolha -> "), scanf("%d", &ESCOLHA);
    }
    while(!Verifica_Escolha(4, 1, ESCOLHA));
    
    return ESCOLHA;
    
}

void Quartos()
{
    int modo;
    do{
        printf("\n__________MENU DE QUARTOS__________\n");
        printf("[0] - Voltar\n");
        printf("[1] - Cadastrar quarto\n");
        printf("[2] - Consultar quarto\n");
        printf("[3] - Editar quarto\n");
        printf("[4] - Excluir quarto\n");
        linha(LINHA - 10);
        printf("Sua escolha -> ");
        scanf("%d", &ESCOLHA);

    }while(!Verifica_Escolha(4, 0, ESCOLHA));
    
    switch(ESCOLHA)
    {
    case 1:
        Cadastrar_Quarto(); break;
    case 2:
        modo = Menu_Consultar_Quarto();
        Consultar_Quarto(modo);
        break;
    case 3:
        Editar_Quarto(); 
        break;

    case 4:
        Excluir_Quarto();
        break;
    }
    
}

void Clientes()
{
    do{
        printf("\n__________MENU DO CLIENTE__________\n");
        printf("[0] - Voltar\n");
        printf("[1] - Cadastrar cliente\n");
        printf("[2] - Consultar cliente\n");
        printf("[3] - Editar cliente\n");
        printf("[4] - Excluir cliente\n");
        linha(LINHA - 10);
        printf("Sua escolha -> ");
        scanf("%d", &ESCOLHA);
    }
    while(!Verifica_Escolha(4, 0, ESCOLHA));
    
    switch (ESCOLHA)
    {
    case 1:
        Cadastrar_Cliente();
        break;
    
    case 2: 
        Consultar_Cliente();
        break;
    
    case 3:
        Editar_Cliente(); 
        break;

    case 4:
        Excluir_Cliente();
        break;
    
    default:
        break;
    }
    
}

void Financas()
{
    do{
        printf("\n__________MENU FINANCEIRO__________\n");
        printf("[0] - Voltar\n");
        printf("[1] - Realizar reserva\n");
        printf("[2] - Consultar reserva\n");
        printf("[3] - Realizar check-in\n");
        printf("[4] - Excluir reserva\n");
        printf("[5] - Realizar pagamentos\n");
        printf("[6] - Valores recebidos\n");
        linha(LINHA - 10);
        printf("Sua escolha -> "), scanf("%d", &ESCOLHA);
    }
    while(!Verifica_Escolha(6, 0, ESCOLHA));
    
    switch(ESCOLHA)
    {
    case 1:
        Realizar_Reserva();
        break;
    
    case 2:
        Consultar_Reserva(); 
        break;
    
    case 3: 
        Check_in_Reserva();
        break;

    case 4:
        Excluir_Reserva();
        break;
    
    case 5:
        Realizar_Pagamento(1, 0); 
        break;
    case 6:
        Valores_Recebidos();
        break;

    default:
        break;
    }
    
}

int main()
{
    do{
        ESCOLHA = menu();
        switch(ESCOLHA)
        {
        case 1:
            Quartos();
            break;
        case 2: 
            Clientes();
            break;
        case 3: 
            Financas();
            break;
        case 4:
            break;
        }
    } 
    while(ESCOLHA != 4);
    
    printf("\nFECHANDO O PROGRAMA......\n");

    return 0;
}