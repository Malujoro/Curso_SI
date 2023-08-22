#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ALUNOS 100

void cadastrarAluno(int qtdAlunos, int maxAlunos);
void buscarAluno(int qtdAlunos);
void exibirAluno();
void gerarRelatorio(int qtdAlunos);

struct Aluno {
    int matricula;
    char nome[50];
    int idade;
    char turma;
    int ano;
}aluno[MAX_ALUNOS];

int maxAlunos=0;

void cadastrarAluno(int qtdAlunos, int maxAlunos) {
    if (qtdAlunos < maxAlunos) {
        int matricula;
        int idade;
        
        do {
            printf("Digite a matricula do aluno (1 a 100): ");
            scanf("%d", &matricula);
            setbuf(stdin,NULL);
            if (matricula < 1 || matricula > 100) {
                printf("Matricula invalida. O sistema suporta apenas os valores de 1 a 100 para matriculas.\n");
                printf("Digite novamente !\n");
            }
        } while (matricula < 1 || matricula > 100);
        aluno[qtdAlunos].matricula = matricula;

        printf("Digite o nome do aluno: ");
        scanf(" %[^\n]s", aluno[qtdAlunos].nome);
        setbuf(stdin,NULL);

        do{
        printf("Digite a idade do aluno (1 a 120): ");
        scanf("%d", &idade);
        setbuf(stdin,NULL);
            if (idade < 1 || idade > 120)
            {
            printf("Idade invalida. O sistema suporta apenas os valores de 1 a 120 para idades.\n");
            printf("Digite novamente !\n");
            }
        
        } while (idade < 1 || idade > 120);
        aluno[qtdAlunos].idade = idade;

        do {
            printf("Digite a turma do aluno (A, B, C): ");
            scanf(" %c", &aluno[qtdAlunos].turma);
            setbuf(stdin,NULL);
            if (aluno[qtdAlunos].turma != 'A' && aluno[qtdAlunos].turma != 'B' && aluno[qtdAlunos].turma != 'C') {
                printf("Turma invalida. O sistema possui apenas as turmas A, B e C.\n");
                printf("Digite novamente !\n");
            }
        } while (aluno[qtdAlunos].turma != 'A' && aluno[qtdAlunos].turma != 'B' && aluno[qtdAlunos].turma != 'C');

        printf("Digite o ano do aluno (1 a 9 ano): ");
        scanf("%d", &aluno[qtdAlunos].ano);
        setbuf(stdin,NULL);
        while (aluno[qtdAlunos].ano < 1 || aluno[qtdAlunos].ano > 9) {
        printf("Ano invalido. O sistema possui apenas os anos 1 ao 9:\n");
        printf("Digite novamente !\n");
        scanf("%d", &aluno[qtdAlunos].ano);
        setbuf(stdin,NULL);
        }
        printf("Aluno cadastrado com sucesso!\n");
        
    } else {
        printf("Limite de alunos atingido.\n");
    }
}

void buscarAluno(int qtdAlunos) {
    int buscaMatricula;
    int indiceAluno = -1;  

    exibirAluno();

    printf("Digite a matricula do aluno para buscar: ");
    scanf("%d", &buscaMatricula);
    setbuf(stdin,NULL);

    for (int i = 0; i < qtdAlunos; i++) {
        if (aluno[i].matricula == buscaMatricula) {
            indiceAluno = i; 
            break;  
        }
    }

    if (indiceAluno != -1) {
        int idade;
        
       
        printf("Aluno encontrado:\n");
        printf("Matricula: %d\n", aluno[indiceAluno].matricula);
        printf("Nome: %s\n", aluno[indiceAluno].nome);
        printf("Idade: %d\n", aluno[indiceAluno].idade);
        printf("Turma: %c\n", aluno[indiceAluno].turma);
        printf("Ano: %d\n", aluno[indiceAluno].ano);
        printf("--------------------------\n");
        printf("Digite a atualizacao do nome do aluno: ");
        scanf(" %[^\n]s", aluno[indiceAluno].nome);
        
        do{
        printf("Digite a atualizacao da nova idade do aluno: ");
        scanf("%d", &idade);
        setbuf(stdin,NULL);
            if (idade < 1 || idade > 120)
            {
            printf("Idade invalida. O sistema suporta apenas os valores de 1 a 120 para idades.\n");
            printf("Digite a atualizacao da nova idade do aluno: ");
            }
        
        } while (idade < 1 || idade > 120);
        aluno[indiceAluno].idade = idade;

       
        do {
            printf("Digite a atualizacao da turma do aluno (A, B, C): ");
            scanf(" %c", &aluno[indiceAluno].turma);
            setbuf(stdin,NULL);
            if (aluno[indiceAluno].turma != 'A' && aluno[indiceAluno].turma != 'B' && aluno[indiceAluno].turma != 'C') {
                printf("Turma invalida. O sistema possui apenas as turmas A, B e C.\n");
                printf("Digite a atualizacao da turma do aluno (A, B, C): ");
            }
        } while (aluno[indiceAluno].turma != 'A' && aluno[indiceAluno].turma != 'B' && aluno[indiceAluno].turma != 'C');

       
        printf("Digite a atualizacao ano do aluno (1 a 9 ano): ");
        scanf("%d", &aluno[indiceAluno].ano);
        setbuf(stdin,NULL);
        while (aluno[indiceAluno].ano < 1 || aluno[indiceAluno].ano > 9) {
        printf("Ano invalido. O sistema possui apenas os anos 1 ao 9:\n");
        printf("Digite a atuaizacao do ano do aluno (1 a 9 ano): ");
        scanf("%d", &aluno[indiceAluno].ano);
        setbuf(stdin,NULL);
        }
        printf("Dados do aluno atualizados!\n");
    } else {
        printf("Aluno não encontrado.\n");
    }
}

void exibirAluno() {
    for(int i=0; i < maxAlunos; i++){
        printf("Matricula: %d\n", aluno[i].matricula);
        printf("Nome: %s\n", aluno[i].nome);
        printf("Idade: %d\n", aluno[i].idade);
        printf("Turma: %c\n", aluno[i].turma);
        printf("Ano: %d\n", aluno[i].ano);
        printf("--------------------------\n");
    }
}

void gerarRelatorio(int qtdAlunos) {
    int alunoMaisVelho = 0;
    int alunoMaisNovo = 0,op;
    int alunoAnoMaisAlto = 0;
    int alunoAnoMaisBaixo = 0;
    char buscaTurma;
    int encontrado = 0;
    int buscaMatriculas;
    int encontradoMatricula = 0;
    int buscaAno;
    int encontradoAno = 0; 

    printf("Menu \n");
    printf("1 - Aluno mais velho\n");
    printf("2 - Aluno mais novo\n");
    printf("3 - Buscar aluno no maior ano\n");
    printf("4 - Buscar aluno no menor ano\n");
    printf("5 - Buscar aluno por turma\n");
    printf("6 - Buscar aluno por matricula\n");
    printf("7 - Buscar aluno por ano\n");
    printf("Digite a opcao desejada:\n");
    scanf(" %d", &op);
    setbuf(stdin, NULL);


    switch(op){
        case 1:
            for (int i = 1; i < qtdAlunos; i++) {
                if (aluno[i].idade > aluno[alunoMaisVelho].idade) {
                    alunoMaisVelho = i;
                }
            }
            printf("Aluno mais velho:\n");
            printf("Matricula: %d\n", aluno[alunoMaisVelho].matricula);
            printf("Nome: %s\n", aluno[alunoMaisVelho].nome);
            printf("Idade: %d\n", aluno[alunoMaisVelho].idade);
            printf("Turma: %c\n", aluno[alunoMaisVelho].turma);
            printf("Ano: %d\n", aluno[alunoMaisVelho].ano);
            printf("--------------------------\n");
            
            break;
        case 2: for (int i = 1; i < qtdAlunos; i++) {
            if (aluno[i].idade < aluno[alunoMaisNovo].idade) {
                    alunoMaisNovo = i;
                }
                
            }
            printf("Aluno mais novo:\n");
            printf("Matricula: %d\n", aluno[alunoMaisNovo].matricula);
            printf("Nome: %s\n", aluno[alunoMaisNovo].nome);
            printf("Idade: %d\n", aluno[alunoMaisNovo].idade);
            printf("Turma: %c\n", aluno[alunoMaisNovo].turma);
            printf("Ano: %d\n", aluno[alunoMaisNovo].ano);
            printf("--------------------------\n");
            break;

        case 3:
            for (int i = 1; i < qtdAlunos; i++) {
                if (aluno[i].ano > aluno[alunoAnoMaisAlto].ano) {
                    alunoAnoMaisAlto = i;
                }
            }
            printf("Aluno no maior ano:\n");
            printf("Matricula: %d\n", aluno[alunoAnoMaisAlto].matricula);
            printf("Nome: %s\n", aluno[alunoAnoMaisAlto].nome);
            printf("Idade: %d\n", aluno[alunoAnoMaisAlto].idade);
            printf("Turma: %c\n", aluno[alunoAnoMaisAlto].turma);
            printf("Ano: %d\n", aluno[alunoAnoMaisAlto].ano);
            printf("--------------------------\n");
            break;
        
         case 4:
            for (int i = 1; i < qtdAlunos; i++) {
                if (aluno[i].ano < aluno[alunoAnoMaisBaixo].ano) {
                    alunoAnoMaisBaixo = i;
                }
            }
            printf("Aluno no maior ano:\n");
            printf("Matricula: %d\n", aluno[alunoAnoMaisBaixo].matricula);
            printf("Nome: %s\n", aluno[alunoAnoMaisBaixo].nome);
            printf("Idade: %d\n", aluno[alunoAnoMaisBaixo].idade);
            printf("Turma: %c\n", aluno[alunoAnoMaisBaixo].turma);
            printf("Ano: %d\n", aluno[alunoAnoMaisBaixo].ano);
            printf("--------------------------\n");  
            break;
        case 5: 
             

            printf("Digite a turma que deseja buscar (A, B, C): ");
            scanf(" %c", &buscaTurma);
            setbuf(stdin, NULL);

            printf("Alunos na turma %c:\n", buscaTurma);
            for (int i = 0; i < qtdAlunos; i++) {
                if (aluno[i].turma == buscaTurma) {
                    printf("Matricula: %d\n", aluno[i].matricula);
                    printf("Nome: %s\n", aluno[i].nome);
                    printf("Idade: %d\n", aluno[i].idade);
                    printf("Turma: %c\n", aluno[i].turma);
                    printf("Ano: %d\n", aluno[i].ano);
                    printf("--------------------------\n");
                    encontrado = 1; 
                }
            }

            if (!encontrado) {
                printf("Nenhum aluno encontrado na turma %c.\n", buscaTurma);
            }
            break;
        case 6:
           
            printf("Digite a matricula que deseja buscar: ");
            scanf("%d", &buscaMatriculas);
            setbuf(stdin, NULL);

            for (int i = 0; i < qtdAlunos; i++) {
                if (aluno[i].matricula == buscaMatriculas) {
                    printf("Aluno encontrado:\n");
                    printf("Matricula: %d\n", aluno[i].matricula);
                    printf("Nome: %s\n", aluno[i].nome);
                    printf("Idade: %d\n", aluno[i].idade);
                    printf("Turma: %c\n", aluno[i].turma);
                    printf("Ano: %d\n", aluno[i].ano);
                    printf("--------------------------\n");
                    encontradoMatricula = 1; 
                    break; 
                }
            }

            if (!encontradoMatricula) {
                printf("Nenhum aluno encontrado com a matricula %d.\n", buscaMatriculas);
            }
            break;
        case 7:

            printf("Digite o ano que deseja buscar (1 a 9): ");
            scanf("%d", &buscaAno);
            setbuf(stdin, NULL);

            printf("Alunos no ano %d:\n", buscaAno);
            for (int i = 0; i < qtdAlunos; i++) {
                if (aluno[i].ano == buscaAno) {
                    printf("Matricula: %d\n", aluno[i].matricula);
                    printf("Nome: %s\n", aluno[i].nome);
                    printf("Idade: %d\n", aluno[i].idade);
                    printf("Turma: %c\n", aluno[i].turma);
                    printf("Ano: %d\n", aluno[i].ano);
                    printf("--------------------------\n");
                    encontradoAno = 1; 
                }
            }

            if (!encontradoAno) {
                printf("Nenhum aluno encontrado no ano %d.\n", buscaAno);
            }
            break;
        default :
            printf("Opcao invalida");
        break;

    }
        
}

int main() {
    int qtdAlunos = 0,quantidadeCadastro;
    char opcao;


    do {
        printf("\nMenu de Opcoes:\n");
        printf("1 - Insira a quantidade de alunos que devem ser cadastrados no sistema\n");
        printf("2 - Cadastrar alunos no sistema\n");
        printf("3 - Apresente os dados armazenados de cada aluno no sistema\n");
        printf("4 - Gerar relatorios por palavras chave\n");
        printf("5 - Atualizacao de algum dado de cadastro\n");
        printf("6 - Mostrar a quantidade total de dados armazenados no sistema\n");
        printf("0 - Finalizar a aplicacao\n");
        printf("Escolha uma opcao: ");
        scanf(" %c", &opcao);
        setbuf(stdin, NULL);
        

        switch (opcao) {
            case '1':

                printf("Digite a quantidade de alunos que voce deseja cadastrar no sistema: ");
                scanf("%d", &quantidadeCadastro);
                fflush(stdin);
            maxAlunos += quantidadeCadastro;
            break;
            case '2':
                while (qtdAlunos<maxAlunos) {
                    printf("Insira os dados do aluno %d:\n", qtdAlunos + 1);
                    cadastrarAluno(qtdAlunos, maxAlunos);
                    qtdAlunos++;
                }
            break;
            case '3':
                exibirAluno();
            break;
            case '4':
                gerarRelatorio(qtdAlunos);
                break;
            case '5':
                buscarAluno(qtdAlunos);
                break;
            case '6':
                printf("Quantidade de alunos cadastrados no sistema: %d\n", qtdAlunos);
                break;
            case '0':
                printf("Finalizando a aplicacao...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
            }
            system("PAUSE"); // caso queira executar no terminal do propio vs code remova o system pause e cls//
            system("cls");
        }while (opcao != '0'); 
    
    return 0;

}