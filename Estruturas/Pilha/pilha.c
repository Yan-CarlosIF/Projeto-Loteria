#include <stdlib.h>
#include <string.h>
#include "pilha.h"

/** Função initPilha
*
*  Inicializa uma nova pilha
*
* Args:
* 
* Return: o endereço da pilha criada
**/
Pilha* initPilha() {
    // Aloca memoria para uma nova pilha
    Pilha *novaPilha = (Pilha*)malloc(sizeof(Pilha));
    if (novaPilha == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }

    // Inicia os atributos da pilha com seus respectivos valores iniciais
    novaPilha->qtdApostas.feriasMerecida = 0;
    novaPilha->qtdApostas.megaAprov = 0;
    novaPilha->qtdApostas.poteSurpresa = 0;

    novaPilha->somaTotal = 0;
    novaPilha->tamanho = 0;
    novaPilha->topo = NULL;

    return novaPilha;
}

/** Função push
*
*  Insere um novo elemento na pilha
*
* Args:
* - pilha (Pilha *): ponteiro para a pilha
* - aposta (int *): ponteiro para os numeros da aposta
* - valorApostado (float): valor apostado na aposta
* - cliente (Cliente *): ponteiro para o cliente que realizou a aposta
*
**/
void push(Pilha *pilha, int *aposta, float valorApostado, Cliente *cliente) {
    // Aloca memoria para uma nova aposta
    Aposta *novaAposta = (Aposta*)malloc(sizeof(Aposta));
    if (novaAposta == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }

    // Adicionando os parametros aos atributos do novo cliente
    novaAposta->numsAposta = aposta;
    novaAposta->valorApostado = valorApostado;
    novaAposta->cliente = cliente;
    novaAposta->prox = pilha->topo;

    // Aumenta a quantidade de apostas de acordo com o premio
    if (cliente->premio == 1) {
        pilha->qtdApostas.megaAprov++;
    } else if (cliente->premio == 2) {
        pilha->qtdApostas.feriasMerecida++;
    } else {
        pilha->qtdApostas.poteSurpresa++;
    }

    // Atualiza os atributos da pilha
    pilha->somaTotal += valorApostado;
    pilha->topo = novaAposta;
    pilha->tamanho++;
}

/** Função pop
*
*  Remove um elemento da pilha
*
* Args:
* - pilha (Pilha *): ponteiro para a pilha
*
* Return: ponteiro para o elemento retirado da pilha
**/
Aposta* pop(Pilha *pilha) {
    // Se a pilha estiver vazia retorna NULL
    if (isEmpty(pilha)) {
        return NULL;
    }
    
    // Variavel para armazenar o elemento retirado
    Aposta *apostaRetirada = pilha->topo;
    pilha->topo = pilha->topo->prox;
    pilha->tamanho--;

    return apostaRetirada;
}

/** Função mostrarAposta
*
*  Mostra os numeros da aposta
*
* Args:
* - aposta (Aposta *): ponteiro para a aposta
*
**/
void mostrarAposta(Aposta *aposta) {
    // Percore o array com os numeros da aposta e imprime no console
    printf("Numeros da Aposta: ");
    for (int i = 0; i < 6; i++) printf("%02d ", aposta->numsAposta[i]);
    printf("\n\n");
}

/** Função isEmpty
*
*  Verifica se a pilha esta vazia
*
* Args:
* - pilha (Pilha *): ponteiro para a pilha
*
* Return: retorna se o tamanho da pilha é igual ou não a 0
**/
bool isEmpty(Pilha *pilha) {
    return pilha->tamanho == 0;
}