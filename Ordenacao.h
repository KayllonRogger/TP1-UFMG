#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

// Função BubbleSort.
// A função se repete até que nenhum elemento do vetor seja mais trocado. Por
// isso a função é chamada Bolha, pois os elementos dos vetores trocam entre si,
// casa por casa, até que esteja na posição correta.

void Bolha (int *v, int n)
{
     int i, j, aux;
     for( i = 0; i < n; i++)
          for( j = 0; j < n-1; j++)
               if(v[j] > v[j+1])
               {
                       aux = v[j];
                       v[j] = v[j+1];
                       v[j+1] = aux;
               }
}

// Função SelectionSort.
// Escolhe-se um n-ésimo maior ou menor termo e troca-o até que esteja na
// posição correta do vetor.

void Selecao(int *v, int n)
{
     int i, j, Min, aux;
     for ( i = 0; i < n; i++)
     {
         Min = i;
         for( j = i + 1; j < n; j++)
              if(v[j] < v[Min])
                      Min = j;
              aux = v[Min];
              v[Min] = v[i];
              v[i] = aux;
         }
}

// Função InsertionSort.
// Escolhe-se o segundo elemento do vetor, e verifica se ele deve ficar antes ou
// na posição em que já está. Depois o terceiro elemento é escolhido e faz a
// verificação novamente. A função termina quando todos os elementos estiverem
// sido organizados.

void Insercao(int *v, int n)
{
     int i, j, aux;
     for( i = 1; i < n; i++)
     {
          aux = v[i];
          j = i - 1;
          while( (j >= 0) && (aux < v[j]) )
          {
                 v[j + 1] = v[j];
                 j--;
          }
          v[j + 1] = aux;
     }
}

// Função Quicksort.
// O algoritimo consiste na expressão "dividir para conquistar", onde dividimos
// o vetor em outros dois: o de elementos maiores e o de elementos menores.
// Primeiramente, escolhemos um elemento pivô. Reorganiza o vetor de modo que os
// elementos menores fiquem antes do pivô e os elementos maiores fique depois do
// pivô. Assim, o elemento pivô já se posiciona corretamente em sua posição. A
// função só para quando todos os elementos estejam em seus devidos lugadres.

int particao(int *v, int esquerda, int direita){
    int pivo, e, d;
    
    e = esquerda;
    d = direita;
    pivo = v[esquerda];
    while(esquerda < direita){
                   while((v[direita] >= pivo) && (esquerda < direita)) direita--;
                   if(esquerda != direita){
                               v[esquerda] = v[direita];
                               esquerda++;
                   }
                   while((v[esquerda] <= pivo) && (esquerda < direita)) esquerda++;
                   if(esquerda != direita){
                               v[direita] = v[esquerda];
                               direita--;
                   }
    }
    v[esquerda] = pivo;
    pivo = esquerda;
    esquerda = e;
    direita = d;
    if(esquerda < pivo) particao (v, esquerda, pivo-1);
    if(direita > pivo) particao (v, pivo+1, direita);
}

void QuickSort(int *v, int n){
     particao(v, 0, n-1);
}

// Função MergeSort.
// O algoritimo consiste em dividir o vetor em diversos outros vetores menores
// até que se tenha um vetor de 2 elementos, a partir de entao, organiza-se
// esses 2 elementos em todos os vetores menores, e compara-se com o proximo
// tendo a partir de entao, um vetor de 4 elementos, organizando entre si. Após
// essas comparações, organiza-se com o proximo vetor de 4 elementos, tendo-se
// entao um vetor de 8 elementos, e asssim sucessivamente. A função só para
// quando todos os elementos estiverem sido posicionados corretamente.

void intercala (int d, int m, int e, int *v)
{
   int i, j, k, *w;
   w = (int*)malloc((e - d)*sizeof(int));
   i = d; j = m;
   k = 0;

   while (i < m && j < e) {
      if (v[i] <= v[j])  w[k++] = v[i++];
      else  w[k++] = v[j++];
   }
   while (i < m)  w[k++] = v[i++];
   while (j < e)  w[k++] = v[j++];
   for (i = d; i < e; ++i)  v[i] = w[i - d];
   free (w);
}

void mergesort (int d, int e, int *v)
{
   if (d < e - 1) {
      int m = (d + e)/2;
      mergesort (d, m, v);
      mergesort (m, e, v);
      intercala (d, m, e, v);
   }
}

// Função: Novo
// Utilizando a ideia da função separa do Quicksort e a função InsertionSort para ordenar
// os subvetores gerado pelo separa.

void novo(int* v, int n) {
    int i , j , value;
    int aux = 1;
    do {
        aux = 3*aux+1;
    } while(aux < n);
    do {
       aux /= 3;
       for(i = aux; i < n; i++) {
            value = v[i];
            j = i - aux;
            while (j >= 0 && value < v[j]) {
                v [j + aux] = v[j];
                j -= aux;
            }
            v [j + aux] = value;
        }
    } while ( aux > 1);
}
