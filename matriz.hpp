#ifndef matriz_hpp
#define matriz_hpp

void Imprime(char [][9]);
int VerificaLinha(char [][9], int, char[]);
int VerificaColuna(char [][9], int, char[]);
int VerificaRegiao(char [][9], int, int, char[]);
int OrdenaRegiao(int, int);
void LerMatriz(char [][9]);
void ConverteMatriz(char [][9]);
void CharParaInt(char [], int&, int&);
void Menu(char [][9], char [], int, int);

#endif