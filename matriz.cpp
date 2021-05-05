#include "matriz.hpp"
#include <iostream>
#include <fstream>
#include <cstring>

void Imprime(char sudoku_matriz[9][9]){
    for(int i = 0;i < 9;i++){
        for(int j = 0;j < 9;j++){
            std::cout << sudoku_matriz[i][j];

            if(j != 8)
                std::cout << " ";
            if(j == 2 || j == 5)
                std::cout << " ";
        }
    
        std::cout << std::endl;
        if(i == 2 || i == 5)
            std::cout << std::endl;
    }
}

int VerificaLinha(char sudoku_matriz[9][9], int linha, char opcao[10]){
    for(int i = 0;i < 9;i++){
        if(sudoku_matriz[linha][i] == opcao[2])
            return 1;
    }

    return 0;
}

int VerificaColuna(char sudoku_matriz[9][9], int coluna, char opcao[10]){
    for(int j = 0;j < 9;j++){
        if(sudoku_matriz[j][coluna] == opcao[2])
            return 1;
    }

    return 0;
}

int VerificaRegiao(char sudoku_matriz[9][9], int linha, int coluna, char opcao[10]){
    if(linha >= 0 && linha < 3){
        if(coluna >= 0 && coluna < 3){
            for(int i = 0;i < 3;i++)
                for(int j = 0;j < 3;j++)
                    if(sudoku_matriz[i][j] == opcao[2])
                        return 1;
        }
        if(coluna >= 3 && coluna < 6){
            for(int i = 0;i < 3;i++)
                for(int j = 3;j < 6;j++)
                    if(sudoku_matriz[i][j] == opcao[2])
                        return 1;
        }
        if(coluna >= 6 && coluna < 9){
            for(int i = 0;i < 3;i++)
                for(int j = 6;j < 9;j++)
                    if(sudoku_matriz[i][j] == opcao[2])
                        return 1;
        }
    }
    if(linha >= 3 && linha < 6){
        if(coluna >= 0 && coluna < 3){
            for(int i = 3;i < 6;i++)
                for(int j = 0;j < 3;j++)
                    if(sudoku_matriz[i][j] == opcao[2])
                        return 1;
        }
        if(coluna >= 3 && coluna < 6){
            for(int i = 3;i < 6;i++)
                for(int j = 3;j < 6;j++)
                    if(sudoku_matriz[i][j] == opcao[2])
                        return 1;
        }
        if(coluna >= 6 && coluna < 9){
            for(int i = 3;i < 6;i++)
                for(int j = 6;j < 9;j++)
                    if(sudoku_matriz[i][j] == opcao[2])
                        return 1;
        }
    }
    if(linha >= 6 && linha < 9){
        if(coluna >= 0 && coluna < 3){
            for(int i = 6;i < 9;i++)
                for(int j = 0;j < 3;j++)
                    if(sudoku_matriz[i][j] == opcao[2])
                        return 1;
        }
        if(coluna >= 3 && coluna < 6){
            for(int i = 6;i < 9;i++)
                for(int j = 3;j < 6;j++)
                    if(sudoku_matriz[i][j] == opcao[2])
                        return 1;
        }
        if(coluna >= 6 && coluna < 9){
            for(int i = 6;i < 9;i++)
                for(int j = 6;j < 9;j++)
                    if(sudoku_matriz[i][j] == opcao[2])
                        return 1;
        }
    }

    return 0;
}

int OrdenaRegiao(int linha, int coluna){
    if(linha >= 0 && linha < 3){
        if(coluna >= 0 && coluna < 3)
            return 1;
        else if(coluna >= 3 && coluna < 6)
            return 2;
        else if(coluna >= 6 && coluna < 9)
            return 3;
    }
    if(linha >= 3 && linha < 6){
        if(coluna >= 0 && coluna < 3)
            return 4;
        else if(coluna >= 3 && coluna < 6)
            return 5;
        else if(coluna >= 6 && coluna < 9)
            return 6;
    }
    if(linha >= 6 && linha < 9){
        if(coluna >= 0 && coluna < 3)
            return 7;
        else if(coluna >= 3 && coluna < 6)
            return 8;
        else if(coluna >= 6 && coluna < 9)
            return 9;
    }
}

/*int Verifica(char sudoku_matriz[9][9], int linha, int coluna, char opcao[10]){
    int horizontal = 0, vertical = 0, regiao = 0;

    horizontal = VerificaLinha(sudoku_matriz, linha, opcao);
    vertical = VerificaColuna(sudoku_matriz, coluna, opcao);
    regiao = VerificaRegiao(sudoku_matriz, linha, coluna, opcao);
}*/

void LerMatriz(char sudoku_matriz[9][9]){
    char arquivo_texto[100];

    std::ifstream matriz;

    std::cout << "Indique o arquivo que contem a matriz original: ";
    std::cin >> arquivo_texto;

    matriz.open(arquivo_texto);

    for(int linha = 0;linha < 9;linha++){
        for(int coluna = 0;coluna < 9;coluna++)
            matriz >> sudoku_matriz[linha][coluna];
    }

    matriz.close();
}

void ConverteMatriz(char sudoku_matriz[9][9]){
    for(int i = 0;i < 9;i++){
        for(int j = 0;j < 9;j++){
            if(sudoku_matriz[i][j] == '0')
                sudoku_matriz[i][j] = '_';
        }
    }
}

void CharParaInt(char opcao[10], int& linha, int& coluna){
    if(opcao[0] == '1')
        linha = 1;
    if(opcao[0] == '2')
        linha = 2;
    if(opcao[0] == '3')
        linha = 3;
    if(opcao[0] == '4')
        linha = 4;
    if(opcao[0] == '5')
        linha = 5;
    if(opcao[0] == '6')
        linha = 6;
    if(opcao[0] == '7')
        linha = 7;
    if(opcao[0] == '8')
        linha = 8;
    if(opcao[0] == '9')
        linha = 9;
    
    if(opcao[1] == '1')
        coluna == 1;
    if(opcao[1] == '2')
        coluna == 2;
    if(opcao[1] == '3')
        coluna == 3;
    if(opcao[1] == '4')
        coluna == 4;
    if(opcao[1] == '5')
        coluna == 5;
    if(opcao[1] == '6')
        coluna == 6;
    if(opcao[1] == '7')
        coluna == 7;
    if(opcao[1] == '8')
        coluna == 8;
    if(opcao[1] == '9')
        coluna == 9;
}

void Menu(char sudoku_matriz[9][9], char opcao[10], int linha, int coluna){ //TODO vitória
    do{

        std::cout << "\nDigite o comando ou indique uma celula para alterar: ";
        std::cin >> opcao;

        if(!strcmp(opcao, "salvar")){
            std::ofstream salvar;

            salvar.open("matriz.txt");

            for(int linha = 0;linha < 9;linha++){
                for(int coluna = 0;coluna < 9;coluna++){
                    if(sudoku_matriz[linha][coluna] == '_')
                        sudoku_matriz[linha][coluna] == '0';

                    salvar << sudoku_matriz[linha][coluna];
                }

                std::cout << "O jogo foi salvo no arquivo texto" << std::endl;

                salvar.close();
            }
        }else if(strcmp(opcao, "sair")){
            CharParaInt(opcao, linha, coluna);
            linha--;coluna--;

            if(opcao[2] == '0'){
                sudoku_matriz[linha][coluna] = '_';
                Imprime(sudoku_matriz);
            }
            else if(sudoku_matriz[linha][coluna] != '_'){
                std::cout << "Erro! Impossivel alterar essa celula predefinida." << std::endl;
            }
            else{
                int num_regiao = OrdenaRegiao(linha, coluna);
                int horizontal = VerificaLinha(sudoku_matriz, linha, opcao);
                int vertical = VerificaColuna(sudoku_matriz, coluna, opcao);
                int regiao = VerificaRegiao(sudoku_matriz, linha, coluna, opcao);

                if(horizontal == 1)
                    std::cout << "Erro! A linha " << linha+1 << " ja possui o valor " << opcao[2] << "." << std::endl;
                if(vertical == 1)
                    std::cout << "Erro! A coluna " << coluna+1 << " ja possui o valor " << opcao[2] << "." << std::endl;
                if(regiao == 1)
                    std::cout << "Erro! A regiao " << num_regiao << " ja possui o valor " << opcao[2] << "." << std::endl;
                if(horizontal == 0 && vertical == 0 && regiao == 0){
                    sudoku_matriz[linha][coluna] = opcao[2];
                    Imprime(sudoku_matriz);
                }
            }
        }

    }while(strcmp(opcao,"sair"));
}