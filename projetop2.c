#include <stdio.h>
#include <stdlib.h>

struct livro {
    char titulo_livros[250];
    int ano_l;
    int quantidade;
    int codigo;
};

void buscar_livro(int codigo,struct livro livros[],int total) {

    for(int i = 0; i < total; i++) {
        if(livros[i].codigo == codigo) {
            printf("livro encontrado\n");
            printf("Titulo: %s\n",livros[i].titulo_livros);
            printf("Ano: %d\n",livros[i].ano_l);
            printf("Quantidade disponivel: %d\n",livros[i].quantidade);
            printf("codigo: %d\n", livros[i].codigo);
            return;
        }
    }
    printf("livro nao encontrado!");
}
void imprimir_livros(int total, struct livro livros[]) {

    for(int i = 0; i < total; i++) {
        printf("Titulo: %s| Ano: %d| Quantidade: %d| Codigo: %d\n",
               livros[i].titulo_livros,livros[i].ano_l,livros[i].quantidade,livros[i].codigo);
    }

}
void ordenar_ano_i(struct livro livros[], int total) {
    struct livro temp;
    printf("Ordenando....\n");
    for(int i = 0; i < total - 1; i++) {
        for(int j = 0; j < total - 1 - i; j++ ) {
            if(livros[j].ano_l > livros[j+ 1].ano_l) {
                temp = livros[j];
                livros[j] = livros[j+ 1];
                livros[j + 1] = temp;
            }
        }
    }
    printf("Ordenado!\n");
    for(int i = 0; i < total; i++) {
        printf("Titulo: %s| Ano: %d| Quantidade: %d| Codigo: %d\n",
               livros[i].titulo_livros,livros[i].ano_l,livros[i].quantidade,livros[i].codigo);
    }

}

int main() {

    struct livro p1; //apenas para usar a struct
    struct livro livros[50]; //vetor para a funcao buscar livro
    int total = 0;
    int temp; // variável temporária para o Bubble sort

    FILE *arquivo;
    arquivo = fopen("livros.txt","r");
    if(arquivo == NULL) { // de der erro para abrir o arquivo ele imprime NULL
        printf("ERROR\n");
    }
    else {
        while(fscanf(arquivo, "%d %s %d %d", &livros[total].codigo,livros[total].titulo_livros,&livros[total].ano_l,&livros[total].quantidade) == 4) {
            total ++;
        }
         fclose(arquivo);
    }

    int options;
    printf("=== Escolha uma Opcao do menu ===\n");
    printf("1 = Adicionar Livro\n");                           //menu já funcionando
    printf("2 = Buscar Livro\n");
    printf("3 = Imprimir Livros\n");
    printf("4 = Ordenar por Ano e Imprimir\n");
    printf("5 = Sair\n");
    scanf("%d", &options);

    switch(options) {
    case 1: //adicionar livros

        printf("Escreva o codigo do livro:\n");
        scanf("%d", &p1.codigo);

        printf("Escreva o titulo do livro:\n");
        scanf("%s", p1.titulo_livros);

        printf("Escreva o ano do livro:\n");
        scanf("%d", &p1.ano_l);

        printf("Escreva a quantidade de livros:\n");
        scanf("%d", &p1.quantidade);

        arquivo = fopen("livros.txt", "a");
        if(arquivo == NULL) { // de der erro para abrir o arquivo ele imprime NULL
            printf("ERROR\n");
        }
        else {
            fprintf(arquivo, "%d %s %d %d\n", p1.codigo, p1.titulo_livros,p1.ano_l,p1.quantidade);
            fclose(arquivo);
        }

        livros[total] = p1;
        total ++;
        break;

    case 2://aqui chama a função buscar livros
        int cod_l;
        printf("Escreva o codigo do livro:\n");
        scanf("%d", &cod_l);
        buscar_livro(cod_l, livros, total);
        break;

    case 3:
        imprimir_livros(total, livros);
        break;

    case 4:
        ordenar_ano_i(livros, total);
        break;

    case 5://aqui é simplesmente saindo
        printf("Salvando e Saindo....\n");
        break;

    default:
        printf("Escolha uma opcao existente no menu!\n"); //se o usuário tentar digitar qualquer opçaque não exista no menu.
        break;
    }
    return 0;
}
