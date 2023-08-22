#include <stdio.h>
#include <stdlib.h>

struct Item {
	int info;
	struct Item* prox;
};

typedef struct Item No;

int tamanho_lista(No* p) {
    int tam = 0;
    No* aux = p;
    
    while (aux != NULL) {
        tam++;
        aux = aux->prox;
    }
    
    return tam;
}

int indice_de(No* p, int valor) {
    int i = 0;
    No* aux = p;
    
    while (aux != NULL) {
        if (aux->info == valor) return i;
        aux = aux->prox;
        i++;
    }
    
    return -1;
}

No* insere_inicio(No* p, int valor) {
    No* novo_item = (No*)malloc(sizeof(No));
    novo_item->info = valor;
    novo_item->prox = p;
    
    return novo_item;
}

No* insere_fim(No* p, int valor) {
    No* aux = p;
    No* novo_item = insere_inicio(NULL, valor);
    
    if (aux == NULL) {
        return novo_item;
    }
    
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    
    aux->prox = novo_item;
    
    return p;
}

No* insere_depois_indice(No* p, int valor, int indice) {
    int tamanho = tamanho_lista(p);
    No* aux = p;
    No* novo_item = insere_inicio(NULL, valor);
    
    if (tamanho == 0) return novo_item;
    
    int i = 0;
    while (i != indice) {
        i++;
        aux = aux->prox;
    }
    
    novo_item->prox = aux->prox;
    aux->prox = novo_item;
    
    return p;
}

void exibir_lista(No* p) {
    No* aux = p;
    
    printf("[");
    while (aux != NULL) {
        printf("%d, ", aux->info);
        aux = aux->prox;
    }
    printf("]\n");
}

void limpar_lista(No* p) {
    No* aux = p;
    
    while (aux != NULL) {
        No* temp = aux->prox;
        free(aux);
        aux = temp;
    }
}

int main(int argc, char *argv[]) {
	int buff;
	No* p = NULL;
	exibir_lista(p);
	
	printf("Que valor deseja colocar no início ?\n");
	scanf("%d", &buff);
	p = insere_inicio(p, buff);
	exibir_lista(p);
	
	printf("Digite mais um valor para colocar no inicio: \n");
	scanf("%d", &buff);
	p = insere_inicio(p, buff);
	exibir_lista(p);
	
	printf("Digite um valor para colocar no fim: \n");
	scanf("%d", &buff);
	p = insere_fim(p, buff);
	exibir_lista(p);
	
	printf("Depois de qual número deseja inserir um novo número ?\n");
	scanf("%d", &buff);
	int indice_item = indice_de(p, buff);
	
	if (indice_item == -1) {
	    printf("Valor não encontrado\n");
	} else {
	    printf("Qual valor deseja inserir ?\n");
	    scanf("%d", &buff);
	    p = insere_depois_indice(p, buff, 1);
	}
	exibir_lista(p);

    limpar_lista(p);
	return 0;
}