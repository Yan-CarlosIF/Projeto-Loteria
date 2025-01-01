#ifndef PILHA_H
#define PILHA_H
#include "../Filas/fila.h" 
#include <stdbool.h>

/** Estrutura QtdTipoAposta
*
*  Armazena a quantidade de apostas de cada tipo de premio
*
* Args:
* - megaAprov (int): quantidade de apostas na Mega da Aprovacao
* - feriasMerecida (int): quantidade de apostas na Loteria das Ferias Merecidas
* - poteSurpresa (int): quantidade de apostas na Pote Surpresa de Nota Maxima
**/
typedef struct {
    int megaAprov;
    int feriasMerecida;
    int poteSurpresa;
} QtdTipoAposta;

/** Estrutura Aposta
*
*  Armazena uma aposta realizada
*
* Args:
* - cliente (Cliente *): ponteiro para o cliente que realizou a aposta
* - aposta (int *): ponteiro para guardar os numeros da aposta
* - valorApostado (float): valor apostado na aposta
* - prox (Aposta *): ponteiro para o proximo elemento da pilha
**/
typedef struct Aposta {
    Cliente *cliente;
    int *numsAposta;
    float valorApostado;
    struct Aposta *prox;
} Aposta;

/** Estrutura Pilha
*
*  Armazena uma pilha de apostas realizadas
*
* Args:
* - topo (Aposta *): ponteiro para o topo da pilha
* - qtdApostas (QtdTipoAposta): quantidade de apostas de cada tipo de premio
* - tamanho (int): quantidade de apostas na pilha
* - somaTotal (float): valor total apostado na pilha
**/
typedef struct {
    Aposta *topo;
    QtdTipoAposta qtdApostas;
    int tamanho;
    float somaTotal;
} Pilha;

// Documentação das funções no arquivo pilha.c
Pilha* initPilha();
void push(Pilha *pilha, int *aposta, float valorApostado, Cliente *cliente);
Aposta* pop(Pilha *pilha);
void mostrarAposta(Aposta *aposta);
bool isEmpty(Pilha *pilha);
#endif