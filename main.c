#include "Estruturas/funcoes.c" // Inclui as funções e estruturas e bibliotecas usadas no programa

int main() {
    Queue *megaAprov = initQueue();  // Fila da Mega da Aprovacao
    Queue *feriasMerecida = initQueue(); // Fila Loteria das Ferias Merecidas
    Queue *poteSurpresa = initQueue(); // Fila Pote Surpresa de Nota Maxima

    Pilha *apostas = initPilha(); // Pilha de apostas
    
    int op; // variavel para receber as opção escolhidas pelo usuário

    // Do while para fazer um menu de opções
    do {    
        printf("\nSeja bem vindo a loteria! Insira:\n");
        printf("0 - sair\n1 - Registrar Cliente\n2 - Cadastrar Aposta\n3 - Mostrar apostas\n4 - Fazer sorteio!\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        // escolher opção do menu com switch
        switch (op) {
            // Liberar a memoria das filas, da pilha e dos clientes ao sair do programa
            case 0:
                freeQueue(megaAprov);
                freeQueue(feriasMerecida);
                freeQueue(poteSurpresa);
                free(apostas);
                printf("\nPrograma Encerrado!");
                break;
            case 1:
                // Função para registrar um cliente
                registrarCliente(megaAprov, feriasMerecida, poteSurpresa);
                break;
            case 2: 
                // Função para fazer uma aposta
                cadastrarAposta(megaAprov, feriasMerecida, poteSurpresa, apostas);
                break;
            case 3:
                // Função para mostrar as apostas
                exibirApostas(apostas);
                break;
            case 4:
                // Função para realizar o sorteio
                realizarSorteio(apostas);
                break;
            default: // Se a opção for inválida, uma mensagem na tela para alertar o usuário
                printf("Opcao invalida!\n");
        }
    } while (op != 0); // se a opção for 0 encerra o programa

    return 0;
}