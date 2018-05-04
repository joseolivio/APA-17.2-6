#include <iostream>  // Biblioteca padrão c plus plus.
#include <algorithm> // Função max() pego daqui..

using namespace std;

        // N = NUMERO DE ELEMENTOS
        // M = TAMANHO MÁXIMO DA MOCHILA
        // PESO[] ARRAY COM O PESO DE CADA PRODUTO
        // VALOR[] ARRAY COM O VALOR DE CADA PRODUTO
int MochilaDinamica(int n, int M, int pesos[], int valores[])
{
    int G[n+1][M+1]; // +1 para incluir o zero...
    int i, j;
    int valorFinal;
    int postos[n];

   for (i=0;i<=n;i++)  { // Linhas, até o número de elementos
       for (j=0;j<=M;j++)   { // Colunas, até o tamanho máximo da mochila
           if (i==0||j==0) {
               G[i][j] = 0; // Gn(y) = 0 ,No começo ele não ta ganhando nada, pois não pega nenhum produto..
           }
           else if (pesos[i-1]<=j) { // Se o peso couber ele vai ver qual é o melhor caminho, se não ele já pega o anterior...
            // Gi(y) = max{Gi+1(y),Gi+1(y-peso(i+1) + valor(i+1)} <-- Fórmula geral ( Top-down )

                 G[i][j] = max(G[i-1][j],valores[i-1] + G[i-1][j-pesos[i-1]]); // Bottom-up
           }                                                              //    ^
           else {                                                        //     |
                 G[i][j] = G[i-1][j];                                   //      |
           }                                                           //       |
       }
   } // fim do for

    valorFinal = G[n][M];
    cout << "Carga total carregada na mochila: " << valorFinal << endl;
    cout << endl << "Elementos que foram adicionados na mochila: "<< endl;


    j = M;
    for (i=n;valorFinal>0&&i>0;i--) { // vai iterar até um dos 2 argumentos ( i e carga final ) chegar em zero.
        // Aqui vamos percorer a coluna, de baixo para cima, se a solução for igual a linha de cima, significa que o resultado veio de lá,
        // no nosso max{x.x} ele pegou o primeiro valor, ou seja, o resultado de cima, vamos continuar até chegar em um ponto
        // que o resultado da linha de cima é diferente do resultado da linha atual, isso signfica que o objeto da linha atual foi posto na mochila.
        if (valorFinal == G[i-1][j])
            continue; // volta pro for e diminiu o i ( pula uma linha pra cima )
        else {
            cout << "Elemento " << i << ", que possui:" << endl;
            cout << "Peso: " << pesos[i-1] << " Valor: " << valores[i-1] << endl;

            valorFinal = valorFinal - valores[i - 1]; // o valor do item que ja foi considerado é retirado do valor final..
            j = j - pesos[i - 1]; // aqui nessa linha movemos a coluna(j) para a posição correta para continuarmos o loop. ( explique na tabela )
        }
    }

}

int main(void)
{   // Exemplo de sala de aula:
    int valores[] = {3,4,5,3};
    int pesos[] = {3,2,4,3};
    int M = 6;
    int n = sizeof(valores)/sizeof(valores[0]);
    MochilaDinamica(n,M,pesos,valores);
    return 0;
}
