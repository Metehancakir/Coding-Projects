#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define sutun 2
#define satir 2

int dizi1[satir][sutun];
int dizi2[satir][sutun];
int toplamSonuc[satir][sutun];
int carpimSonuc[satir][sutun];
int transposeSonuc[sutun][satir];

void rastgeleSayi(int matrix[satir][sutun]);
void yazdir(int matrix[satir][sutun]);
void hesaplaToplamSonuc(int arr1[satir][sutun], int arr2[satir][sutun]);
void hesaplaCarpimSonuc(int arr1[satir][sutun], int arr2[satir][sutun]);
void transpose(int matrix[satir][sutun], int transpose[sutun][satir]);


int main() {
    srand(time(NULL));
    rastgeleSayi(dizi1);
    rastgeleSayi(dizi2);

    printf("dizi 1:\n");
    yazdir(dizi1);
    printf("\n");

    printf("dizi 2:\n");
    yazdir(dizi2);
    printf("\n");

    hesaplaToplamSonuc(dizi1, dizi2);
    printf("dizilerin toplami:\n");
    yazdir(toplamSonuc);
    printf("\n");

    hesaplaCarpimSonuc(dizi1, dizi2);
    printf("dizilerin carpimi:\n");
    yazdir(carpimSonuc);
    printf("\n");

    transpose(carpimSonuc, transposeSonuc);
    printf("carpim sonucunun transpozu:\n");
    yazdir(transposeSonuc);


    return 0;
}

void rastgeleSayi(int matrix[satir][sutun]) {
    int i, j;
    for (i = 0; i < satir; i++) {
        for (j = 0; j < sutun; j++) {
            matrix[i][j] = rand() % 10 + 1;
        }
    }
}

void yazdir(int matrix[satir][sutun]) {
    int i, j;
    for (i = 0; i < satir; i++) {
        for (j = 0; j < sutun; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void hesaplaToplamSonuc(int arr1[satir][sutun], int arr2[satir][sutun]) {
    int i, j;
    for (i = 0; i < satir; i++) {
        for (j = 0; j < sutun; j++) {
            toplamSonuc[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
}

void hesaplaCarpimSonuc(int arr1[satir][sutun], int arr2[satir][sutun]) {
    int i = 0;
    int j = 0;
    int k = 0;

    for (i = 0; i < satir; i++) {
        for (j = 0; j < sutun; j++) {
            for (k = 0; k < sutun; k++) {
                carpimSonuc[i][j] = ( arr1[i][j] * arr2[i][j] ) + ( arr1[i][k] * arr2[k][j] );
            }
        }
    }
}


void transpose(int matrix[satir][sutun], int transpose[sutun][satir]) {
    int i, j;
    for (i = 0; i < satir; i++) {
        for (j = 0; j < sutun; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}