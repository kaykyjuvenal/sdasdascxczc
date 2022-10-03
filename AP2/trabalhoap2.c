#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabalhoap2.h"//arquivo na mesma pasta ""

void limpaBuffer()
{
    while (getchar() != '\n');
}
void cadastrarData(aluno * vetorAlunos, int *posicao){
    int diaNascimento;
    int mesNascimento;
    int anoNascimento;;

    while(1 > diaNascimento || diaNascimento > 31){
        printf("Digite o dia da data de nascimento do aluno: ");
        scanf("%d", diaNascimento);
        limpaBuffer();
        if (1 > diaNascimento || diaNascimento > 31){
        printf("dia invalido: %d, digite outra data.", diaNascimento);
        }
        diaNascimento = &vetorAlunos[*posicao].datanascimento.dia;
    }
    while(mesNascimento > 12 || mesNascimento < 1){
        printf("Digite o mes da data de nascimento do aluno: ");
        scanf("%d", mesNascimento);
        limpaBuffer();
        if (mesNascimento > 12 || mesNascimento < 1 ){//ou é ||
            printf("O Mes digitado é inválido - %d", mesNascimento);
        }
        mesNascimento = &vetorAlunos[*posicao].datanascimento.mes;  
    }
    while(anoNascimento < 1900 ||  anoNascimento >2022){
        printf("digite o ano de nascimento do aluno: ");
        scanf("%d", anoNascimento);
        limpaBuffer();
        if ( anoNascimento < 1900 || anoNascimento > 2022){
            printf("Esta ano  é inválida- %d",  anoNascimento);
        }
        anoNascimento = &vetorAlunos[*posicao].datanascimento.ano;
    }    
    printf("A data foi cadastrada com sucesso - %d/%d/%d", diaNascimento, mesNascimento, anoNascimento); 
}
void cadastrarAluno(aluno *vetorAlunos, int *posicao){
    printf("Digite o prontuario do aluno: ");
    scanf("%d", &vetorAlunos[*posicao].prontuario);
    limpaBuffer();
    printf("Digite o nome do aluno:");
    scanf("%s", &vetorAlunos[*posicao].nome);
    limpaBuffer();                                  
    printf("Digite o sobrenome do aluno:");
    scanf("%s", &vetorAlunos[*posicao].sobrenome);
    limpaBuffer();
    cadastrarData(&vetorAlunos, *posicao);
    printf("Digite o curso do aluno: ");
    scanf("%s", &vetorAlunos[*posicao].curso);
    limpaBuffer();
    (*posicao)++;
}

void salvaArquivo(aluno *vetorAlunos, int nAlunos)
{
    FILE *arquivo;
    int i, result;

    arquivo = fopen("alunos.dat", "wb");
    if (arquivo == NULL)
    {
        printf("Erro na abertura do arquivo.\n");
        return;
    }
    for (i = 0; i < nAlunos; i++)
    {
        result = fwrite(&vetorAlunos[i], sizeof(aluno), 1, arquivo);
        if (result != 1)
        {
            printf("Erro de escrita no arquivo. \n");
        }
    }
    fclose(arquivo);
}

int lerArquivo(aluno *vetorAlunos)
{
    FILE *arquivo;
    int i, result;
    arquivo = fopen("alunos.dat", "rb");
    if (arquivo == NULL)
    {
        printf("Erro na abertura do arquivo.\n");
        return -1;
    }
    for (i = 0; i<MAXALUNOS; i++) {
        result = fread(&vetorAlunos[i], sizeof(aluno), 1, arquivo);
        if (result != 1) {
            if (feof(arquivo)) {
                return i;
            } else {
                printf("Erro na leitura do arquivo.\n");
                return -1;
            }
        }
    }
}
int getMenu() {
    int i;
    printf ("===MENU===\n0 - Sair\n1 - Cadastrar Dados\n2 - Imprimir Dados \n3 - Salvar Arquivo\n4 - Carregar Arquivo \n 5- Busca Especifica\n 6- Ordenação\nDigite uma  opção: ");
    scanf("%d",&i);
    limpaBuffer();
    return i;
}

void imprimeAlunos(aluno *vetorAlunos, int nAlunos) {
    int i;
    for (i=0; i<nAlunos; i++) {
        printf("Prontuario: %d\n", vetorAlunos[i].prontuario);
        printf("Nome do aluno: %s\n", vetorAlunos[i].nome);
        printf("Sobrenome do aluno: %s\n", vetorAlunos[i].sobrenome);
        printf("Curso: %s\n", vetorAlunos[i].curso);
        printf("Data De nascimento: %d\n", vetorAlunos[i].datanascimento);
    }
}
void imprimeAluno(aluno *vetorAlunos,int i)
{

        printf("Prontuario: %d\n", vetorAlunos[i].prontuario);
        printf("Nome do aluno: %s\n", vetorAlunos[i].nome);
        printf("Sobrenome do aluno: %s\n", vetorAlunos[i].sobrenome);
        printf("Curso: %s\n", vetorAlunos[i].curso);
        printf("Data De nascimento: %d\n", vetorAlunos[i].datanascimento);
}
void buscaEspecificaPorNome(aluno *vetorAlunos, int nAlunos, char *procurado)
{
    int i;
    for(i = 0; i < nAlunos; i++)
    {
        if(strcmp(procurado, vetorAlunos[i].nome) == 0)
        {
            imprimeAluno(&vetorAlunos[i], i);
        }
    }
}
void buscaEspecificaPorSobrenome(aluno *vetorAlunos, int nAlunos, char *procurado)
{
    int i;
    for(i = 0; i < nAlunos; i++)
    {
        if(strcmp(procurado, vetorAlunos[i].sobrenome) == 0)
        {
            imprimeAluno(&vetorAlunos[i],i);
        }
    }
}
void buscaEspecificaCurso(aluno *vetorAlunos, int nAlunos, char *procurado)
{
    int i;
    for(i = 0; i < nAlunos; i++)
    {
        if(strcmp(procurado, vetorAlunos[i].nome) == 0)
        {
            imprimeAluno(&vetorAlunos[i], i);
        }
    }
}
void buscaEspecificaPorNomeeSobrenome(aluno *vetorAlunos, int nAlunos, char *procurado1, char *procurado2)
{
    int i;
    for(i = 0; i < nAlunos; i++)
    {
        if(strcmp(procurado1, vetorAlunos[i].nome) == 0)
        {
            if (strcmp(procurado2, vetorAlunos[i].sobrenome) == 0)
            {
                imprimeAluno(&vetorAlunos[i], i);
            }
            
        }
    }
}
void buscaEspecificaPorProntuario(aluno *vetorAlunos, int nAlunos, int procurado)
{
    int i;
    for ( i = 0; i < nAlunos; i++)
    {
        if (procurado == vetorAlunos[i].prontuario)
        {
            imprimeAluno(&vetorAlunos[i], i);
        }
        
    }
    
}
void buscaEspecificaPorData(aluno *vetorAlunos, int nAlunos, data procurado)
{
    int i;
    for (i = 0; i< nAlunos; i++)
    {
        if (procurado.dia  == vetorAlunos[i].datanascimento.dia)
        {
            if (procurado.mes == vetorAlunos[i].datanascimento.mes)
            {
                if (procurado.ano == vetorAlunos[i].datanascimento.ano)
                {
                    imprimeAluno(&vetorAlunos[i], i);
                }
            }
        }
    }
}
void ordenacao()
{

}
int getMenu2() {
    int i;
    printf ("===Menu De Busca: ===\n1 - Nome e Sobrenome\n2 - Nome\n3 - Sobrenome \n4 - Curso\n5 - Data de nascimento \n 6- Prontuario\n Digite uma  opção: ");
    scanf("%d",&i);
    limpaBuffer();
    return i;
}
int main()
{
    aluno alunos[MAXALUNOS];
    int numAlunos = 0;
    int menu;
    int menubusca; 
    do {
        menu = getMenu();
        switch(menu) {
            case 1: cadastraAluno(alunos, &numAlunos);
                    break;
            case 2: imprimeAluno(alunos, numAlunos);
                    break;
            case 3: salvaArquivo(alunos, numAlunos);
                    break;
            case 4: numAlunos = lerArquivo(alunos);
                    break;
            case 5:  
                    menubusca = getmenu2();
                    switch(menubusca){
                        case 1: char nomec;
                                char sobrenomec;
                                printf("Digite um nome: ");
                                scanf("%s", &nomec);
                                printf("Digite um sobrenome: ");
                                scanf("%s", &sobrenomec);
                                buscaEspecificaPorNomeeSobrenome(alunos,&numAlunos,nomec,sobrenomec);
                                break;
                        case 2: char nomec;
                                printf("Digite o nome a ser prcurado: ");
                                scanf("%s", &nomec);
                                buscaEspecificaPorNome(alunos,&numAlunos,nomec);
                                break;
                        case 3: char sobrenomec;
                                printf("Digite o sobrenome: ");
                                scanf("%s", &sobrenomec);
                                buscaEspecificaPorSobrenome(alunos,&numAlunos,sobrenomec);
                                break;
                        case 4: char cursoc;
                                printf("Digite o curso: ");
                                scanf("%s",&cursoc);
                                buscaEspecificaCurso(alunos,&numAlunos,cursoc);
                                break;
                        case 5: data datanascimentoc;
                                printf("Digite o dia da data de nascimento: ");
                                scanf("%d",&datanascimentoc.dia);
                                printf("Digite o mes da data de nascimento: ");
                                scanf("%d",&datanascimentoc.mes);
                                printf("Digite o ano da data de nascimento: ");
                                scanf("%d",&datanascimentoc.ano);
                                buscaEspecificaPorData(alunos,&numAlunos,datanascimentoc);
                                break;
                        case 6: int prontuarioc;
                                printf("Digite o prontuario: ");
                                scanf("%d", prontuarioc);
                                buscaEspecificaPorProntuario(alunos,&numAlunos,prontuarioc);
                        } while (menubusca != 0);
                    
            case 6: ordenacao();                  
        }       
    } while (menu != 0);   
}
