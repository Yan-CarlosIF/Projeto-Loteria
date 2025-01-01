#include "Filas/fila.c"
#include "Pilha/pilha.c"
#include <time.h>

/** Função numeroEscolhido
*
*  Verifica se o numero escolhido ja foi sorteado
*
* Args:
* - numero (int): numero escolhido
* - numeros (int *): array de numeros escolhidos
* - size (int): tamanho do array
* 
* Return: true se o numero escolhido ja foi sorteado, false caso contrario
**/
bool numeroEscolhido(int numero, int *numeros, int size) {
    for (int i = 0; i < size; i++) 
        if (numeros[i] == numero) return true;

    return false;
}

/** Função registrarCliente
*
*  Recebe os dados do cliente e adiciona um novo cliente na fila correspondente ao premio escolhido
*
* Args:
* - mega (Queue *): ponteiro para a mega da aprovacao
* - ferias (Queue *): ponteiro para a loteria das ferias merecidas
* - surpresa (Queue *): ponteiro para o pote surpresa de nota maxima
* 
**/
void registrarCliente(Queue *mega, Queue *ferias, Queue *surpresa) {
    int premio; // variavel para receber o ID de cada premio(Fila)

    // Do while para garantir que o usuário digite uma fila válida
    do {
        printf("\nInsira qual premio deseja concorrer:\n");
        printf("1 - Mega da Aprovacao\n2 - Loteria das Ferias Merecidas\n3 - Pote Surpresa de Nota Maxima\nEscolha uma opcao: ");
        scanf("%d", &premio);
    } while (premio < 1 || premio > 3);
    getchar(); // Limpar buffer antes de receber o nome do usuário

    char nome[50];
    printf("\nInsira o nome do cliente: ");
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = '\0'; // Função para excluir a quebra de linha ao final do nome

    int senha;
    // Switch para adicionar à fila correta!
    switch (premio) {
        case 1:
            // senha é o tamanho da fila + 1! para pegar a posição do cliente
            senha = mega->size + 1;
            enqueue(mega, nome, premio, senha); 
            break;
        case 2:
            senha = ferias->size + 1;
            enqueue(ferias, nome, premio, senha);
            break;
        case 3:
            senha = surpresa->size + 1;
            enqueue(surpresa, nome, premio, senha);
            break;
    }

    printf("\nCliente '%s' cadastrado com sucesso, sua senha e %d\n", nome, senha);
}

/** Função fazerAposta
*
*  Recebe os dados do cliente e faz a aposta
*
* Args:
* - fila (Queue *): ponteiro para a fila
* - apostas (Pilha *): ponteiro para a pilha
* 
**/
void fazerAposta(Queue *fila, Pilha *apostas) {
    // Verifica se existem clientes cadastrados
    if (fila->size <= 0) {
        printf("Nenhum cliente cadastrado!\n");
        return;
    }

    // Variaveis de opção do cliente, valor apostado
    int op, valorApostado;

    // Aloca memoria para os numeros da aposta
    int *numerosAposta = (int*)malloc(sizeof(int) * 6);
    if (numerosAposta == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }

    printf("\nEscolha um cliente: \n");
    // Exibe os clientes cadastrados
    displayQueue(fila);

    // Do while para garantir que o usuário digite uma opção valida
    do {
        printf("Insira: ");
        scanf("%d", &op);
        if (op < 1 || op > fila->size) printf("Opcao invalida!\n");
    } while (op < 1 || op > fila->size);

    // Loop para encontrar o cliente escolhido
    Cliente *cliente = fila->head;
    for (int i = 1; i < op; i++) cliente = cliente->next;
    
    // Loop para solicitar os numeros da aposta
    for (int i = 0; i < 6; i++) {
        do {
            printf("Digite o %d numero da sua aposta (entre 0 e 99): ", i + 1);
            scanf("%d", &numerosAposta[i]);

            if (numerosAposta[i] < 0 || numerosAposta[i] > 99 || numeroEscolhido(numerosAposta[i], numerosAposta, i))
                printf("Numero invalido ou ja escolhido!\n");
        // Do while para garantir que o usuário digite um numero valido
        } while (numerosAposta[i] < 0 || numerosAposta[i] > 99 || numeroEscolhido(numerosAposta[i], numerosAposta, i));
    }   
    
    // Do while para solicitar o valor apostado
    do {
        printf("\nDigite o valor apostado: ");
        scanf("%d", &valorApostado);
    } while (valorApostado < 0);
    
    // Adiciona a aposta na pilha
    push(apostas, numerosAposta, valorApostado, cliente);
    printf("\nAposta numero %d realizada com sucesso!\n", apostas->tamanho);
}

/** Função cadastrarAposta
*
*  Cadastra uma aposta de acordo com o premio escolhido pelo usuário
*  Garante que o usuário sempre digite um premio valido
*
* Args:
* - mega (Queue *): ponteiro para a mega da aprovacao
* - ferias (Queue *): ponteiro para a loteria das ferias merecidas
* - surpresa (Queue *): ponteiro para o pote surpresa de nota maxima
* - apostas (Pilha *): ponteiro para a pilha de apostas
* 
**/
void cadastrarAposta(Queue *mega, Queue *ferias, Queue *surpresa, Pilha *apostas) {
    // Variavel para receber o ID do premio
    int premio;

    // Do while para garantir que o usuário digite um premio valido
    do {
        printf("\nDigite qual premio deseja fazer a aposta:");
        printf("\n1 - Mega da Aprovacao\n2 - Loteria das Ferias Merecidas\n3 - Pote Surpresa de Nota Maxima\nEscolha uma opcao: ");
        scanf("%d", &premio);
    } while(premio < 1 || premio > 3); 
    
    // Switch para fazer a aposta de acordo com o premio
    switch (premio) {
        case 1:
            fazerAposta(mega, apostas);
            break;
        case 2:
            fazerAposta(ferias, apostas);
            break;
        case 3:
            fazerAposta(surpresa, apostas);
            break;
    }
}

/** Função exibirApostas
*
*  Exibe as apostas e a quantidade de apostas realizadas
*
* Args:
* - apostas (Pilha *): ponteiro para a pilha
* 
**/
void exibirApostas(Pilha *apostas) {
    // Verifica se existem apostas
    if (apostas->tamanho <= 0) {
        printf("\nNenhuma aposta realizada!\n");
        return;
    }

    // loop para exibir as apostas
    Aposta *temp = apostas->topo;
    printf("\n%d Aposta(s) realizada(s) na loteria:\n", apostas->tamanho);
    for (int i = 0; i < apostas->tamanho; i++) {
        printf("Aposta %d do cliente '%s':\n", i + 1, temp->cliente->nome);
        mostrarAposta(temp);
        temp = temp->prox;
    }
    
    // Exibe a quantidade de apostas realizadas por cada tipo de premio
    printf("quantidade de apostas na Mega da Aprovacao: %d\n", apostas->qtdApostas.megaAprov);
    printf("quantidade de apostas na Loteria das Ferias Merecidas: %d\n", apostas->qtdApostas.feriasMerecida);
    printf("quantidade de apostas na Pote Surpresa de Nota Maxima: %d\n", apostas->qtdApostas.poteSurpresa);
    // Exibe o valor total apostado
    printf("Valor total apostado: %.2fR$\n\n", apostas->somaTotal);
}

/** Função sortearNumeros
*
*  Sorteia os numeros da loteria
*
* Args:
* - min (const int): numero minimo
* - max (const int): numero maximo
* 
* Return:
* - int*: ponteiro para os numeros sorteados
*/
int* sortearNumeros(const int min, const int max) {
    // Aloca memoria para os numeros
    int *numeros = (int*)malloc(sizeof(int) * 6);
    if (numeros == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }

    // Cria uma semente para a funcao rand
    srand(time(NULL));

    // Loop para sortear os numeros
    for (int i = 0; i < 6; i++) {
        int num;

        // Loop para garantir que o numero sorteado nao seja repetido
        do {
            num = rand() % (max - min + 1) + min;
        } while (numeroEscolhido(num, numeros, i));
        numeros[i] = num;
    }

    return numeros;
}

/** Função realizarSorteio
*
*  Realiza o sorteio da loteria
*
* Args:
* - apostas (Pilha *): ponteiro para a pilha
* 
**/
void realizarSorteio(Pilha *apostas) {
    // Verifica se existem apostas para realizar o sorteio
    if (apostas->tamanho <= 0) {
        printf("\nNenhuma aposta realizada!\n");
        return;
    }
    
    // Inicializa a fila de vencedores
    Queue *vencedores = initQueue();
    // Sorteia os numeros da loteria de 0 a 99
    int *numerosLoteria = sortearNumeros(0, 99);

    // Loop para exibir os numeros sorteados
    printf("\nOs numeros sorteados foram: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", numerosLoteria[i]);
    }

    // Inicia a contagem de ganhadores
    int contGanhadores = 0;
    // Loop para percorrer a pilha e inserir na pilha de prioridade de acordo com os numeros sorteados
    while (1) {
        // Remove a aposta da pilha
        Aposta *aposta = pop(apostas);
        // Quando a pilha estiver vazia após os pops, encerra o loop
        if (aposta == NULL) break;
        
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 6; k++) {
                // Se o numero da aposta for igual ao numero sorteado, incrementa a prioridade
                if (numerosLoteria[j] == aposta->numsAposta[k]) {
                    aposta->cliente->prioridade++;
                    break;
                }
            }
        }

        // Insere a aposta na pilha de prioridade se a prioridade for maior que 0
        if (aposta->cliente->prioridade > 0) {
            if (aposta->cliente->prioridade == 6) {
                contGanhadores++;
            }
            enqueuePriority(vencedores, aposta->cliente);
        }

        // Libera memoria dos numeros da aposta
        free(aposta->numsAposta);
        // Libera memoria da aposta
        free(aposta);
    }
    
    // Zera as quantidades de apostas após zerar a pilha
    apostas->qtdApostas.feriasMerecida = 0;
    apostas->qtdApostas.megaAprov = 0;
    apostas->qtdApostas.poteSurpresa = 0;

    // Variavel para percorrer a fila
    Cliente *temp = vencedores->head;
    
    if (vencedores->size > 0) {
        printf("\n\nResultado da loteria:\n");
        while (temp != NULL) {
            printf("Cliente '%s' - Acertou %d dezenas\n", temp->nome, temp->prioridade);
            temp->prioridade = 0;
            temp = temp->next;
        }

        if (contGanhadores == 0) {
            // Caso nenhum ganhador
            printf("\nNenhum cliente acertou todas as dezenas.\n\n");
        } else {
            // Exibe o número de ganhadores
            printf("\n%d Cliente(s) acertou(aram) todas as dezenas!\n", contGanhadores);

            if (contGanhadores == 1) {
                // Caso apenas um ganhador
                printf("O ganhador levou um prêmio de: %.2fR$\n\n", apostas->somaTotal);
            } else {
                // Caso mais de um ganhador
                float premio = apostas->somaTotal / contGanhadores;
                printf("O prêmio foi dividido entre os ganhadores: %.2fR$ por cliente.\n\n", premio);
            }
        }
    } else {
        printf("\nNinguem acertou nenhuma dezena!\n");
    }

    // Zera o valor total apostado
    apostas->somaTotal = 0;
    // Libera memoria do array de numeros sorteados
    free(numerosLoteria);
    // Libera memoria da fila de vencedores
    free(vencedores);
}