#include "fonctions.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define n 50
#define N 50

int main(){
    int** matrice;
    matrice=allouerMatrice(n,N);
    initialiserMatrice(matrice, n, N);
    srand(time(NULL));
    while (1){
        afficher(matrice,n,N);
        reloadMatrice1(matrice, n, N);
        usleep(500000);
    }
    return 0;
}