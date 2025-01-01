#ifndef FILA_H
#define FILA_H
#include <stdbool.h>

/** Estrutura Cliente
*
*  Instacia um Cliente
*
* Args:
* - nome (char[]): array de 50 posições para guardar o nome do cliente
* - premio (int): um numero inteiro para guardar o premio que o cliente se registrou
* - senha (int): um numero inteiro para guardar a senha (posição na fila) do cliente
* - prioridade (int): um numero inteiro para guardar a prioridade do cliente
* - next (Cliente *) aponta para o proximo cliente da fila
**/
typedef struct Cliente {
    char nome[50];
    int premio;
    int senha;
    int prioridade;
    struct Cliente *next;
} Cliente;

/** Estrutura Queue
*
*  Instacia um Fila
*
* Args:
* - head (Cliente *) aponta para o primeiro cliente da fila
* - tail (Cliente *) aponta para o ultimo cliente da fila
* - size (int): um numero inteiro para guardar o tamanho da fila
**/
typedef struct {
    Cliente *head;
    Cliente *tail;
    int size;
} Queue;

// Documentação das funções no arquivo fila.c
Queue* initQueue();
void enqueue(Queue *queue, char *nome, int premio, int senha);
void enqueuePriority(Queue *queue, Cliente *client);
bool empty(Queue *queue);
void dequeue(Queue *queue);
int len(Queue *queue);
void freeQueue(Queue *queue);
void displayQueue(Queue *queue);
#endif