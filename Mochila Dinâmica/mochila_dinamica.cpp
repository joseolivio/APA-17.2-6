#include <iostream>  // Biblioteca padr�o c plus plus.
#include <algorithm> // Fun��o max() pego daqui..

using namespace std;

        // N = NUMERO DE ELEMENTOS
        // M = TAMANHO M�XIMO DA MOCHILA
        // PESO[] ARRAY COM O PESO DE CADA PRODUTO
        // VALOR[] ARRAY COM O VALOR DE CADA PRODUTO
int MochilaDinamica(int n, int M, int pesos[], int valores[])
{
    int G[n+1][M+1]; // +1 para incluir o zero...
    int i, j;

   for (i=0;i<= n;i++)  { // Linhas, at� o n�mero de elementos
       for (j=0;j<=M;j++)   { // Colunas, at� o tamanho m�ximo da mochila
           if (i==0||j==0) {
               G[i][j] = 0; // Gn(y) = 0 ,No come�o ele n�o ta ganhando nada, pois n�o pega nenhum produto..
           }
           else if (pesos[i-1]<=j) { // Se o peso couber ele vai ver qual � o melhor caminho, se n�o ele j� pega o anterior...
            // Gi(y) = max{Gi+1(y),Gi+1(y-peso(i+1) + valor(i+1)} <-- F�rmula geral ( Top-down )
                 G[i][j] = max(G[i-1][j],valores[i-1] + G[i-1][j-pesos[i-1]]); // Bottom-up
           }                                                              //    ^
           else {                                                        //     |
                 G[i][j] = G[i-1][j];                                   //      |
           }                                                           //       |
       }
   }
return G[n][M];
}

int main(void)
{   // Exemplo de sala de aula:
    int valores[] = {3,4,5,3};
    int pesos[] = {3,2,4,3};
    int M = 6;
    int n = sizeof(valores)/sizeof(valores[0]);
    cout << "Valor maximo vc conssegue armazenar nessa mochila: " <<  MochilaDinamica(n,M,pesos,valores) << endl;
    return 0;
}
