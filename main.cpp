/* Trabalho prático 01 Algoritimo e Estrutura de Dados */
/* Professor: Thiago Noronha                           */
/* Aluno: Kayllon Rogger Nunes                         */
/* Matricula: 2011016465                               */
#include "Ordenacao.h"

//#define TAM 10
int main(){
    int TAM, resposta, *v;
    
    cout << "Qual o tamanho do vetor a ser ordenado ? ";
    cin >> TAM;
    cout << "1- Gerados Aleatoriamente,\n2- Previamente ordenados em ordem Crescente\n3- Previamente ordenados em ordem decrescente\n -> ";
    cin >> resposta;
    
    v = (int*)malloc(sizeof(int)*TAM);
    double dif;
    time_t start, end;
    
    switch(resposta){
                     case (1):{
                               for(int i = 0; i < TAM; i++)
                                       v[i] = rand()%100;
                               break;
                     }
                     case (2):{
                               for(int i = 0; i < TAM; i++)
                                       v[i] = rand()%100;
                               mergesort(0, TAM, v);
                               break;
                     }
                     case(3):{
                               int *w;
                               w = (int*)malloc(sizeof(int)*TAM);
                               for(int i = 0; i < TAM; i++)
                                       v[i] = rand()%100;
                               mergesort(0, TAM, v);
                               for(int i = 0; i < TAM; i++)
                                       w[i] = v[TAM -1 - i];
                               for(int i = 0; i < TAM; i++)
                                       v[i] = w[i];
                               break;
                     }
    }
    resposta = 0;
    cout << "Escolha o metodo de ordenacao\n1- Bubble Sort\n2- Selection Sort\n3- Insertion Sort\n4- Quick Sort\n5- Merge Sort\n6- Novo metodo\n-> ";
    cin >> resposta;
    switch(resposta){
                     case(1):{
                               time(&start);
                               Bolha(v, TAM);
                               time(&end);
                               break;
                     }
                     case(2):{
                               time(&start);
                               Selecao(v, TAM);
                               time(&end);
                               break;
                     }
                     case(3):{
                               time(&start);
                               Insercao(v, TAM);
                               time(&end);
                               break;
                     }
                     case(4):{
                               time(&start);
                               QuickSort(v, TAM);
                               time(&end);
                               break;
                     }
                     case(5):{
                               time(&start);
                               mergesort(0, TAM, v);
                               time(&end);
                               break;
                     }
                     case(6):{
                              time(&start);
                              novo(v, TAM);
                              time(&end);
                              break;
                     }
    }
    dif = difftime(end, start);
    cout << "\n";
    cout << "Tempo: " << dif << "segundos" << endl;
    system("pause");
    return 0;
}
