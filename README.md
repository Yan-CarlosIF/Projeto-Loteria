# Projeto: Sistema de Gerenciamento de Loteria

## Descrição Geral
Este projeto implementa um sistema para gerenciar uma loteria, organizando os clientes em filas e pilhas, registrando suas apostas, armazenando os resultados e identificando os vencedores com base em um sistema de prioridades. O projeto é dividido em três partes principais: gerenciamento de filas para registrar os clientes, estruturação de pilhas para armazenar as apostas e o sorteio dos resultados utilizando filas de prioridade.

## Estrutura do Projeto

### 1. Entrando na Loteria
Um balcão de loteria organiza os clientes em diferentes filas baseadas no prêmio escolhido. Cada cliente informa:
- **Nome**: Nome do cliente.
- **Prêmio**: Categoria do prêmio que deseja concorrer:
  - Mega da Aprovação
  - Loteria das Férias Merecidas
  - Pote Surpresa de Nota Máxima
- **Senha**: Um número único que identifica sua posição na fila.

#### Funcionalidades:
- Implementação de uma estrutura de fila.
- Métodos para adicionar clientes à fila, verificar sua posição e nome da fila.
- Documentação clara do código e de cada método.

### 2. Chamada para a Aposta
Um sistema baseado em pilhas é usado para registrar as apostas feitas pelos clientes. Cada aposta inclui:
- **Aposta**: Conjunto de seis números inteiros (0 a 99).
  - **Identificação do cliente**: Estrutura Cliente.
  - **Números Escolhidos**: Array de números.
  - **Valor Apostado**: Valor em dinheiro da aposta.
- **Quantidade de apostas de cada prêmio**: Estrutura que guarda quantidades.
- **Soma Total**: Soma do valor de todas as apostas.

#### Funcionalidades:
- Implementação de uma estrutura de pilha.
- Métodos para:
  - Registrar uma nova aposta.
  - Verificar quantas apostas existem em cada categoria.
  - Exibir o valor total apostado.
- Integração com as categorias da Questão 1.

### 3. Armazenando os Resultados
Após o sorteio, seis números entre 0 e 99 são selecionados. As apostas registradas nas pilhas são desempilhadas e comparadas com os números sorteados. Os vencedores são organizados em uma fila de prioridade com base no número de dezenas acertadas:

#### Prioridades:
1. **6 dezenas**: Prioridade 6 (máxima)
2. **5 dezenas**: Prioridade 5
3. **4 dezenas**: Prioridade 4
4. **3 dezenas**: Prioridade 3
5. **2 dezenas**: Prioridade 2
6. **1 dezena**: Prioridade 1
7. **Nenhuma dezena**: Ignorados

#### Funcionalidades:
- Implementação de uma fila de prioridade para armazenar os vencedores.
- Método para:
  - Adicionar vencedores à fila com base na prioridade.
  - Consultar o número total de vencedores.
  - Prêmio aos vencedores de prioridade máxima.

## Execução e Testes

#### 1. Entrando na Loteria:
   - Insira clientes nas filas.
   - Verifique as posições e categorias.

#### 2. Chamada para a Aposta:
   - Registre apostas no prêmio que preferir.
   - Confira o total de apostas e o valor total apostado.

#### 3. Armazenando os Resultados:
   - Realize o sorteio com seis números aleatórios.
   - Os vencedores serão armazenados na fila de prioridade.
   - Resultado dos vencedores exibido ao final.

## Documentação e Estrutura de Código
Todo o código está amplamente documentado, incluindo:
- Descrições de cada função e sua finalidade.
- Explicação dos argumentos e estruturas utilizadas.

## Conclusão
Este sistema aborda aspectos relacionados ao gerenciamento de uma loteria, desde o registro de clientes até a identificação e organização dos vencedores. Ele utiliza estruturas de dados eficientes como filas, pilhas e filas de prioridade para garantir um processamento rápido e confiável.

#### Bônus:
- **Esse projeto foi codado escutando essa [PEDRADA](https://on.soundcloud.com/7TJYwxuW1TQEvcgu8)**


