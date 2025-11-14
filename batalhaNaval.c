#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define TABULEIRO_TAM 10
#define NAVIO_TAM 3

void inicializarTabuleiro(int tabuleiro[TABULEIRO_TAM][TABULEIRO_TAM]) {
    for (int i = 0; i < TABULEIRO_TAM; i++) {
        for (int j = 0; j < TABULEIRO_TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

int validarHorizontal(int linha, int coluna, int tabuleiro[TABULEIRO_TAM][TABULEIRO_TAM]) {
    if (coluna + NAVIO_TAM > TABULEIRO_TAM) return 0;

    for (int i = 0; i < NAVIO_TAM; i++) {
        if (tabuleiro[linha][coluna + i] != 0)
            return 0;
    }

    return 1;
}

int validarVertical(int linha, int coluna, int tabuleiro[TABULEIRO_TAM][TABULEIRO_TAM]) {
    if (linha + NAVIO_TAM > TABULEIRO_TAM) return 0;

    for (int i = 0; i < NAVIO_TAM; i++) {
        if (tabuleiro[linha + i][coluna] != 0)
            return 0;
    }

    return 1;
}

void incluirNavioHorizontal(int linha, int coluna, int tabuleiro[TABULEIRO_TAM][TABULEIRO_TAM]) {
    for (int i = 0; i < NAVIO_TAM; i++) {
        tabuleiro[linha][coluna + i] = 3;
    }
}

void incluirNavioVertical(int linha, int coluna, int tabuleiro[TABULEIRO_TAM][TABULEIRO_TAM]) {
    for (int i = 0; i < NAVIO_TAM; i++) {
        tabuleiro[linha + i][coluna] = 3;
    }
}

void exibirTabuleiro(int tabuleiro[TABULEIRO_TAM][TABULEIRO_TAM]) {
    printf("\n===== TABULEIRO BATALHA NAVAL =====\n\n");

    // Cabeçalho das colunas
    printf("    ");
    for (int col = 0; col < TABULEIRO_TAM; col++) {
        printf("%d ", col);
    }
    printf("\n");

    // Linha separadora
    printf("   --------------------\n");

    // Linhas do tabuleiro
    for (int i = 0; i < TABULEIRO_TAM; i++) {
        printf("%d | ", i);  // Label da linha
        for (int j = 0; j < TABULEIRO_TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {

    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    int tabuleiro[TABULEIRO_TAM][TABULEIRO_TAM];

    inicializarTabuleiro(tabuleiro);

    int linhaH = 2, colunaH = 4;  // navio horizontal
    int linhaV = 5, colunaV = 1;  // navio vertical

    if (validarHorizontal(linhaH, colunaH, tabuleiro)) {
        incluirNavioHorizontal(linhaH, colunaH, tabuleiro);
    } else {
        printf("Erro ao posicionar navio horizontal!\n");
        return 1;
    }

    if (validarVertical(linhaV, colunaV, tabuleiro)) {
        incluirNavioVertical(linhaV, colunaV, tabuleiro);
    } else {
        printf("Erro ao posicionar navio vertical!\n");
        return 1;
    }

    exibirTabuleiro(tabuleiro);

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
