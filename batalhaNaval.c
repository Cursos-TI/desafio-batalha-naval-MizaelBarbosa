#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define TABULEIRO_TAM 10
#define NAVIO_TAM 3

// ----------------------------
// Função: inicializa o tabuleiro com água (0)
// ----------------------------
void inicializarTabuleiro(int tabuleiro[TABULEIRO_TAM][TABULEIRO_TAM]) {
    for (int i = 0; i < TABULEIRO_TAM; i++) {
        for (int j = 0; j < TABULEIRO_TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// ----------------------------
// Validação horizontal
// ----------------------------
int validarHorizontal(int linha, int coluna, int tabuleiro[TABULEIRO_TAM][TABULEIRO_TAM]) {
    if (coluna + NAVIO_TAM > TABULEIRO_TAM) return 0;

    for (int i = 0; i < NAVIO_TAM; i++) {
        if (tabuleiro[linha][coluna + i] != 0){
            return 0;
        }
    }

    return 1;
}

// ----------------------------
// Validação vertical
// ----------------------------
int validarVertical(int linha, int coluna, int tabuleiro[TABULEIRO_TAM][TABULEIRO_TAM]) {
    if (linha + NAVIO_TAM > TABULEIRO_TAM) return 0;

    for (int i = 0; i < NAVIO_TAM; i++) {
        if (tabuleiro[linha + i][coluna] != 0)
            return 0;
    }

    return 1;
}

// ----------------------------
// Validação diagonal crescente (↘)
// Ex: (2,2),(3,3),(4,4)
// ----------------------------
int validarDiagonalCrescente(int linha, int col, int tab[TABULEIRO_TAM][TABULEIRO_TAM]) {
    if (linha + NAVIO_TAM > TABULEIRO_TAM || col + NAVIO_TAM > TABULEIRO_TAM) return 0;

    for (int i = 0; i < NAVIO_TAM; i++)
        if (tab[linha + i][col + i] != 0) return 0;

    return 1;
}

// ----------------------------
// Validação diagonal decrescente (↙)
// Ex: (2,7),(3,6),(4,5)
// ----------------------------
int validarDiagonalDecrescente(int linha, int col, int tab[TABULEIRO_TAM][TABULEIRO_TAM]) {
    if (linha + NAVIO_TAM > TABULEIRO_TAM || col - (NAVIO_TAM - 1) < 0) return 0;

    for (int i = 0; i < NAVIO_TAM; i++)
        if (tab[linha + i][col - i] != 0) return 0;

    return 1;
}

// ----------------------------
// Posiciona navio horizontal
// ----------------------------
void incluirNavioHorizontal(int linha, int coluna, int tabuleiro[TABULEIRO_TAM][TABULEIRO_TAM]) {
    for (int i = 0; i < NAVIO_TAM; i++) {
        tabuleiro[linha][coluna + i] = 3;
    }
}

// ----------------------------
// Posiciona navio vertical
// ----------------------------
void incluirNavioVertical(int linha, int coluna, int tabuleiro[TABULEIRO_TAM][TABULEIRO_TAM]) {
    for (int i = 0; i < NAVIO_TAM; i++) {
        tabuleiro[linha + i][coluna] = 3;
    }
}

// ----------------------------
// Posiciona navio diagonal crescente (↘)
// ----------------------------
void incluirNavioDiagonalCrescente(int linha, int col, int tab[TABULEIRO_TAM][TABULEIRO_TAM]) {
    for (int i = 0; i < NAVIO_TAM; i++)
        tab[linha + i][col + i] = 3;
}

// ----------------------------
// Posiciona navio diagonal decrescente (↙)
// ----------------------------
void incluirNavioDiagonalDecrescente(int linha, int col, int tab[TABULEIRO_TAM][TABULEIRO_TAM] ) {
    for (int i = 0; i < NAVIO_TAM; i++)
        tab[linha + i][col - i] = 3;
}


// ----------------------------
// Exibe o tabuleiro no console
// ----------------------------
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

// ----------------------------
// Função principal
// ----------------------------
int main() {

    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    int tabuleiro[TABULEIRO_TAM][TABULEIRO_TAM];
    inicializarTabuleiro(tabuleiro);

    // ------------------------------------------
    // DEFINE AS COORDENADAS (fixas para o nível)
    // Você pode mudar os valores se quiser
    // ------------------------------------------
    int Hlinha = 1, Hcol = 2;   // Horizontal
    int Vlinha = 4, Vcol = 7;   // Vertical

    int DClinha = 2, DCcol = 2; // Diagonal crescente
    int DDlinha = 6, DDcol = 4; // Diagonal decrescente

    // ------------------------------------------
    // POSICIONA OS NAVIOS
    // ------------------------------------------

    if (validarHorizontal(Hlinha, Hcol, tabuleiro))
        incluirNavioHorizontal(Hlinha, Hcol, tabuleiro);
    else printf("Erro ao posicionar navio horizontal!\n");

    if (validarVertical(Vlinha, Vcol, tabuleiro))
        incluirNavioVertical(Vlinha, Vcol, tabuleiro);
    else printf("Erro ao posicionar navio vertical!\n");

    if (validarDiagonalCrescente(DClinha, DCcol, tabuleiro))
        incluirNavioDiagonalCrescente(DClinha, DCcol, tabuleiro);
    else printf("Erro ao posicionar navio diagonal crescente!\n");

    if (validarDiagonalDecrescente(DDlinha, DDcol, tabuleiro))
        incluirNavioDiagonalDecrescente(DDlinha, DDcol, tabuleiro);
    else printf("Erro ao posicionar navio diagonal decrescente!\n");

    // ------------------------------------------
    // EXIBE O TABULEIRO FINAL
    // ---------
    exibirTabuleiro(tabuleiro);

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
