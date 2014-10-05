#include <iostream>
using namespace std;

#define VAZIO 0

bool aux_resolveSudoku(int n, int **matriz);
bool resolveSudoku(int n, int **matriz, int linha, int coluna);
bool verifica(int n, int **matriz, int linha, int coluna, int numero);
bool verificaLinha(int n, int **matriz, int linha, int numero);
bool verificaColuna(int n, int **matriz, int coluna, int numero);
bool verificaFinal(int n, int **matriz);
void imprimeSudoku(int n, int **matriz);

int main(void){
    int n;
    cin >> n;
    int **matriz = new int*[n];
    
    for(int i = 0; i < n; i++)
    	matriz[i] = new int[n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matriz[i][j];

    if (aux_resolveSudoku(n, matriz) == true){
        cout << "Solucao:\n";
        imprimeSudoku(n, matriz);
    }else
        cout << "Sem Solucao!\n";

	for(int i = 0; i < n; i++)
    	delete[]matriz[i];
    delete []matriz;
    
    return 0;
}

bool aux_resolveSudoku(int n, int **matriz){
    for (int linha = 0; linha < n; linha++)
        for (int coluna = 0; coluna < n; coluna++)
            if (resolveSudoku(n, matriz, linha, coluna) && verificaFinal(n, matriz))
                return true;
    return false;
}

bool resolveSudoku(int n, int **matriz, int linha, int coluna){
    if (matriz[linha][coluna] != VAZIO)
        return true;

    for (int i = 1; i <= n; i++)
        if (verifica(n, matriz, linha, coluna, i)){
            matriz[linha][coluna] = i;

            if (resolveSudoku(n, matriz, linha, coluna))
                return true;
            matriz[linha][coluna] = VAZIO;
        }
    return false;
}

bool verifica(int n, int **matriz, int linha, int coluna, int numero){
    return(!verificaLinha(n, matriz, linha, numero) && !verificaColuna(n, matriz, coluna, numero));
}

bool verificaLinha(int n, int **matriz, int linha, int numero){
    for (int coluna = 0; coluna < n; coluna++)
        if (matriz[linha][coluna] == numero)
            return true;
    return false;
}

bool verificaColuna(int n, int **matriz, int coluna, int numero){
    for (int linha = 0; linha <  n; linha++)
        if (matriz[linha][coluna] == numero)
            return true;
    return false;
}

bool verificaFinal(int n, int **matriz){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (matriz[i][j] == VAZIO)
                return false;
    return true;
}

void imprimeSudoku(int n, int **matriz){
    for (int linha = 0; linha < n; linha++){
        for (int coluna = 0; coluna < n; coluna++)
            cout << matriz[linha][coluna];
        cout << "\n";
    }
}
