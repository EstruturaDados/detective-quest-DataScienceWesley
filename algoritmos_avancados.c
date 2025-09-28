#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Desafio Detective Quest
// Tema 4 - Árvores e Tabela Hash
// Este código inicial serve como base para o desenvolvimento das estruturas de navegação, pistas e suspeitos.
// Use as instruções de cada região para desenvolver o sistema completo com árvore binária, árvore de busca e tabela hash.


// 🌱 Nível Novato: Mapa da Mansão com Árvore Binária
//
// - Crie uma struct Sala com nome, e dois ponteiros: esquerda e direita.
// - Use funções como criarSala(), conectarSalas() e explorarSalas().
// - A árvore pode ser fixa: Hall de Entrada, Biblioteca, Cozinha, Sótão etc.
// - O jogador deve poder explorar indo à esquerda (e) ou à direita (d).
// - Finalize a exploração com uma opção de saída (s).
// - Exiba o nome da sala a cada movimento.
// - Use recursão ou laços para caminhar pela árvore.
// - Nenhuma inserção dinâmica é necessária neste nível.

// Struct da sala
typedef struct Sala {
    char nome[50];
    struct Sala* esquerda;
    struct Sala* direita;
} Sala;

// Função para criar uma nova sala
Sala* criarSala(const char* nome) {
    Sala* novaSala = (Sala*)malloc(sizeof(Sala));
    if (novaSala == NULL) {
        printf("Erro ao alocar memória para a sala.\n");
        exit(1);
    }
    strcpy(novaSala->nome, nome);
    novaSala->esquerda = NULL;
    novaSala->direita = NULL;
    return novaSala;
}

// Função para explorar as salas (navegar na árvore)
void explorarSalas(Sala* atual) {
    char opcao;
    while (1) {
        printf("\nVocê está na sala: %s\n", atual->nome);
        printf("Escolha uma direção: (e) Esquerda | (d) Direita | (s) Sair: ");
        scanf(" %c", &opcao);

        if (opcao == 's') {
            printf("\nSaindo da mansão...\n");
            break;
        } else if (opcao == 'e') {
            if (atual->esquerda != NULL) {
                atual = atual->esquerda;
            } else {
                printf("🚫 Não há sala à esquerda.\n");
            }
        } else if (opcao == 'd') {
            if (atual->direita != NULL) {
                atual = atual->direita;
            } else {
                printf("🚫 Não há sala à direita.\n");
            }
        } else {
            printf("Opção inválida! Use 'e', 'd' ou 's'.\n");
        }
    }
}


// 🔍 Nível Aventureiro: Armazenamento de Pistas com Árvore de Busca
//
// - Crie uma struct Pista com campo texto (string).
// - Crie uma árvore binária de busca (BST) para inserir as pistas coletadas.
// - Ao visitar salas específicas, adicione pistas automaticamente com inserirBST().
// - Implemente uma função para exibir as pistas em ordem alfabética (emOrdem()).
// - Utilize alocação dinâmica e comparação de strings (strcmp) para organizar.
// - Não precisa remover ou balancear a árvore.
// - Use funções para modularizar: inserirPista(), listarPistas().
// - A árvore de pistas deve ser exibida quando o jogador quiser revisar evidências.


// 🧠 Nível Mestre: Relacionamento de Pistas com Suspeitos via Hash
//
// - Crie uma struct Suspeito contendo nome e lista de pistas associadas.
// - Crie uma tabela hash (ex: array de ponteiros para listas encadeadas).
// - A chave pode ser o nome do suspeito ou derivada das pistas.
// - Implemente uma função inserirHash(pista, suspeito) para registrar relações.
// - Crie uma função para mostrar todos os suspeitos e suas respectivas pistas.
// - Adicione um contador para saber qual suspeito foi mais citado.
// - Exiba ao final o “suspeito mais provável” baseado nas pistas coletadas.
// - Para hashing simples, pode usar soma dos valores ASCII do nome ou primeira letra.
// - Em caso de colisão, use lista encadeada para tratar.
// - Modularize com funções como inicializarHash(), buscarSuspeito(), listarAssociacoes().

int main() {

    // 🌱 Nível Novato: Mapa da Mansão com Árvore Binária

    Sala* hall = criarSala("Hall de Entrada");
    Sala* biblioteca = criarSala("Biblioteca");
    Sala* cozinha = criarSala("Cozinha");
    Sala* sotao = criarSala("Sótão");
    Sala* jardim = criarSala("Jardim");

    // Conectando as salas
    hall->esquerda = biblioteca;
    hall->direita = cozinha;
    biblioteca->esquerda = sotao;
    biblioteca->direita = jardim;

    printf("🔍 Detective Quest - Início da exploração!\n");
    explorarSalas(hall);

    // Liberação de memória
    free(hall);
    free(biblioteca);
    free(cozinha);
    free(sotao);
    free(jardim);

    return 0;
}