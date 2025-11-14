#include <stdio.h>
#include <stdlib.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define TABULEIRO_TAM 10
#define NAVIO_TAM 3
#define H 5         // Tamanho das matrizes de habilidade
#define X 3         // Tamanho das matrizes de habilidade

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


// --------------------------------------------------
// Cria matriz em forma de cone apontando para baixo
//
//   0 0 1 0 0
//   0 1 1 1 0
//   1 1 1 1 1
//
// Condição: linha >= coluna central - camada  && linha <= coluna central + camada
// --------------------------------------------------
void criarCone(int cone[H][H]) {
    int centro = H / 2;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < H; j++) {
            if (i >= 0 && j >= centro - i && j <= centro + i)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }
}

// --------------------------------------------------
// Cria matriz em forma de cruz
//
//      0 0 1 0 0
//      0 0 1 0 0
//      1 1 1 1 1
//      0 0 1 0 0
//      0 0 1 0 0
//
// Condição: i == centro || j == centro
// --------------------------------------------------
void criarCruz(int cruz[H][H]) {
    int centro = (H / 2);
    for (int i = 0; i < H; i++){
        for (int j = 0; j < H; j++){
            cruz[i][j] = (i == centro || j == centro) ? 2 : 0;
        }
    }
}

// --------------------------------------------------
// Cria matriz em forma de octaedro (losango)
//
//        0 0 1 0 0
//        0 1 1 1 0
//        1 1 1 1 1
//        0 1 1 1 0
//        0 0 1 0 0
//
// Condição: |i - centro| + |j - centro| <= raio
// --------------------------------------------------
void criarOctaedro(int oct[H][H]) {
    int centro = H / 2;
    int raio = H / 2;

    for (int i = 0; i < H; i++)
        for (int j = 0; j < H; j++)
            oct[i][j] = (abs(i - centro) + abs(j - centro) <= raio) ? 4 : 0;
}


// --------------------------------------------------
// Sobrepõe matriz de habilidade ao tabuleiro
// Marca valor 5 nas posições atingidas
// --------------------------------------------------
void aplicarHabilidade(int tabuleiro[TABULEIRO_TAM][TABULEIRO_TAM], int matriz[H][H], int origemL, int origemC) {

    int offset = H / 2;  // Quantas casas a matriz se estende ao redor do centro

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {

            if (matriz[i][j] == 1 || matriz[i][j] == 2 || matriz[i][j] == 4  ) {

                int linhaTab = origemL + (i - offset);
                int colTab = origemC + (j - offset);

                // Verifica limites
                if (linhaTab >= 0 && linhaTab < TABULEIRO_TAM &&
                    colTab >= 0 && colTab < TABULEIRO_TAM) {

                    // Evita sobrescrever navios
                    if (tabuleiro[linhaTab][colTab] == 0)
                        tabuleiro[linhaTab][colTab] = matriz[i][j] ;
                }
            }
        }
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



    int tabuleiro[TABULEIRO_TAM][TABULEIRO_TAM];
    inicializarTabuleiro(tabuleiro);


 // ------------------------------------------
    // DEFINE AS COORDENADAS (fixas para o nível)
    // Você pode mudar os valores se quiser
    // ------------------------------------------
    int Hlinha = 0, Hcol = 4;   // Horizontal
    int Vlinha = 6, Vcol = 9;   // Vertical

    int DClinha = 1, DCcol = 4; // Diagonal crescente
    int DDlinha = 6, DDcol = 8; // Diagonal decrescente

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

    // Matriz do cone
    int cone[H][H];
    criarCone(cone);

    // Matriz da cruz
    int cruz[H][H];
    criarCruz(cruz);

    // Matriz do octaedro
    int oct[H][H];
    criarOctaedro(oct);


     // ------------------------------------------
    // APLICAR HABILIDADES NAS COORDENADAS:
    //
    // (3,3) cone
    // (6,6) cruz
    // (5,2) octaedro
    // ------------------------------------------
    aplicarHabilidade(tabuleiro, cone, 3, 2);
    aplicarHabilidade(tabuleiro, cruz, 4, 7);
    aplicarHabilidade(tabuleiro, oct, 7, 2);


    // ------------------------------------------
    // EXIBE O TABULEIRO FINAL
    // ---------
    exibirTabuleiro(tabuleiro);

    return 0;
}
