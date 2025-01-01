#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "fila.h"

/** Função initQueue
*
* Inicializa uma fila
*
* Args:
*
* Return: o endereço da fila criada
*/
Queue* initQueue() {
    // Aloca memoria para uma nova fila
    Queue *newQueue = (Queue*)malloc(sizeof(Queue));
    if (newQueue == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }

    // Inicia os atributos da fila com seus respectivos valores iniciais
    newQueue->head = NULL;
    newQueue->tail = NULL;
    newQueue->size = 0;

    return newQueue;
}

/** Função empty
*
* verifica se a fila está vazia
*
* Args:
* - queue (Queue *): fila que deseja verificar
*
* Return: retorna se o tamanho da fila é igual ou não a 0
*/
bool empty(Queue *queue) {
    return queue->size == 0;
}

/** Função enqueue
*
* Adiciona um cliente a fila
*
* Args:
* - queue (Queue *): a fila que deseja adicionar o cliente
* - nome (char *): nome do cliente
* - premio (int): ID do premio que o cliente esta participando
* - senha (int): senha do cliente
*
*/
void enqueue(Queue *queue, char *nome, int premio, int senha) {
    // Alocar memoria para novo cliente
    Cliente *newClient = (Cliente*)malloc(sizeof(Cliente));
    if (newClient == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }

    // Função para copiar string para o atributo nome do cliente
    strcpy(newClient->nome, nome);
    // Adicionando os parametros aos atributos do novo cliente
    newClient->senha = senha;
    newClient->premio = premio;
    newClient->prioridade = 0;
    newClient->next = NULL;

    // Se a fila estiver vazia o inicio e o fim serão iguais!
    if (empty(queue)) {
        queue->head = newClient;
        queue->tail = newClient;
    // Se não, adicionará o cliente ao final da fila
    } else { 
        queue->tail->next = newClient;
        queue->tail = newClient;
    }

    // Aumenta tamanho da fila
    queue->size++;
}

/** Função enqueuePriority
*
* Adiciona um cliente a fila com prioridade
*
* Args:
* - queue (Queue *): a fila que deseja adicionar o cliente
* - client (Cliente *): o cliente que deseja adicionar
*
*/
void enqueuePriority(Queue *queue, Cliente *client) {
    // se a fila estiver vazia o inicio e o fim serão iguais!
    if (empty(queue)) {
        queue->head = client;
        queue->tail = client;
    // se o head tiver prioridade menor que o cliente adiciona no inicio
    } else if (queue->head->prioridade < client->prioridade) { 
        client->next = queue->head;
        queue->head = client;
    // procurar a posicao correta para adicionar o cliente
    } else { 
        Cliente *current = queue->head;

        // loop para encontrar a posicao correta para adicionar o cliente
        while (current->next != NULL && current->next->prioridade >= client->prioridade)
            current = current->next;

        client->next = current->next;
        current->next = client;

        // se o cliente for o ultimo da fila, atualizar o tail
        if (client->next == NULL) {
            queue->tail = client;
        }
    }

    // aumenta tamanho da fila
    queue->size++;
}

/** Função len
*
* retorna o tamanho da fila
*
* Args:
* - queue (Queue *): a fila que deseja saber o tamanho
*
* Return: O tamanho da fila
*/
int len(Queue *queue) {
    return queue->size;
}

/** Função freeLista
*
* percorre a fila liberando a memoria dos clientes alocados!
*
* Args:
* - queue (Queue *): a fila que deseja liberar memoria
*
*/
void freeQueue(Queue *queue) {
    // Verifica se a fila estiver vazia
    if (empty(queue)) {
        return;
    }
    
    // Varivavel temporaria para percorrer a fila
    Cliente *temp = queue->head;

    // loop para percorrer até a variavel ser Nula
    while (temp != NULL) {
        // Variavel para armazenar o cliente a ser liberado
        Cliente *clienteLiberado = temp;
        temp = temp->next;
        // libera a memoria do cliente
        free(clienteLiberado);
    }

    // libera a memoria da fila
    free(queue);
}

/** Função displayQueue
*
* exibe todos os clientes da fila
*
* Args:
* - queue (Queue *): a fila que deseja exibir
*
*/
void displayQueue(Queue *queue) {
    // Variavel para iterar os clientes
    int i = 1; 
    // Varivavel temporaria para percorrer a fila
    Cliente *temp = queue->head;

    // loop para percorrer até a variavel ser Nula
    while (temp != NULL) {
        printf("%d - Cliente '%s'\n", i++, temp->nome);
        temp = temp->next;
    }
    printf("\n");
}