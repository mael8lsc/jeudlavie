#include "fonctions.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void afficher(int** matrice, int n, int N){
    system("clear");
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<N ; j++){
            if (matrice[i][j]){
                printf("██");
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int** allouerMatrice(int n, int N){
    int** matrice;
    matrice=malloc(n*sizeof(int*));
    for (int i=0; i<n; i++){
        matrice[i]=malloc(N*sizeof(int));
    }
    return matrice;
}

void initialiserMatrice(int** matrice, int n, int N){
    srand(time(NULL));
    for (int i=0;i<n;i++){
        for (int j=0;j<N;j++){
            matrice[i][j]=rand()%2;
        }
    }
}

int** reloadMatrice1(int** matrice, int n, int N){
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<N ; j++){
            int voisins=nombreVoisins(matrice,n,N,i,j);
            //printf("%d ",voisins);
            if (matrice[i][j]){
                if ((voisins!=2) && (voisins!=3)){
                    matrice[i][j]=0;
                }
            }
            else {
                if (voisins==3){
                    matrice[i][j]=1;
                }
            }
        }
        //printf("\n");
    }
    return matrice;
}

int** reloadMatrice2(int** matrice, int n, int N){
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<N ; j++){
            int voisins=nombreVoisins(matrice,n,N,i,j);
            //printf("%d ",voisins);
            if (voisins==3){
                matrice[i][j]=1;
            }
            else if ((voisins<2) || (voisins>3)){
                matrice[i][j]=0;
            }
        }
        //printf("\n");
    }
    return matrice;
}

int nombreVoisins(int** matrice, int n, int N, int i, int j){
    int voisins=0;
    for (int y = i-1; y<=i+1; y++) {
        for (int x = j-1; x<=j+1; x++) {
            if ((y >= 0) && (y < n) && (x >= 0) && (x < N) && !((y == n) && (x == N))) {
                if (matrice[x][y]){
                    voisins=voisins+1;
                }
            }
        }
    }
    return voisins;
}
