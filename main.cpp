#include "matriz.hpp"
#include <iostream>
#include <cstring>
#include <fstream>

int main(){

    char sudoku_matriz[9][9];
    char opcao[10];
    int linha, coluna;

    LerMatriz(sudoku_matriz);
    ConverteMatriz(sudoku_matriz);
    Imprime(sudoku_matriz);

    //std::cout << "Deu bom!" << std::endl;

    return 0;
}