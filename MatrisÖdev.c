#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define satir1 2
#define sutun1 3

#define satir2 3
#define sutun2 2

int dizi1[satir1][sutun1];
int dizi2[satir2][sutun2];
int toplamSonuc[satir1][sutun1]; 
int carpimSonuc[satir1][sutun2]; 

void rastgeleDoldur(int satir, int sutun, int matrix[satir][sutun]);
void yazdirMatris(int satir, int sutun, int matrix[satir][sutun]);
void hesaplaToplamSonuc(int arr1[satir1][sutun1], int arr2[satir1][sutun1]);
void hesaplaCarpimSonuc(int arr1[satir1][sutun1], int arr2[satir2][sutun2]);

int main() {
    srand(time(NULL));

    rastgeleDoldur(satir1, sutun1, dizi1);
    rastgeleDoldur(satir2, sutun2, dizi2);

    printf("dizi 1:\n");
    yazdirMatris(satir1, sutun1, dizi1);
    printf("\n");

    printf("dizi 2:\n");
    yazdirMatris(satir2, sutun2, dizi2);
    printf("\n");

    if (satir1 == satir2 && sutun1 == sutun2) {
        hesaplaToplamSonuc(dizi1, dizi1); 
        printf("dizilerin toplami:\n");
        yazdirMatris(satir1, sutun1, toplamSonuc);
        printf("\n");
    } else {
        printf("matris boyutlari esit olmadigindan toplama yapilamaz\n");
        printf("\n");
    }
    
    hesaplaCarpimSonuc(dizi1, dizi2);
    printf("dizilerin carpimi:\n");
    yazdirMatris(satir1, sutun2, carpimSonuc);
    printf("\n");

    return 0;
}

void rastgeleDoldur(int satir, int sutun, int matrix[satir][sutun]) {
    for (int i = 0; i < satir; i++) {
        for (int j = 0; j < sutun; j++) {
            matrix[i][j] = rand() % 100 + 1;
        }
    }
}

void yazdirMatris(int satir, int sutun, int matrix[satir][sutun]) {
    for (int i = 0; i < satir; i++) {
        for (int j = 0; j < sutun; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void hesaplaToplamSonuc(int arr1[satir1][sutun1], int arr2[satir1][sutun1]) {
    for (int i = 0; i < satir1; i++) {
        for (int j = 0; j < sutun1; j++) {
            toplamSonuc[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
}

void hesaplaCarpimSonuc(int arr1[satir1][sutun1], int arr2[satir2][sutun2]) {
    for (int i = 0; i < satir1; i++) { 
        for (int j = 0; j < sutun2; j++) { 
            carpimSonuc[i][j] = 0; 
            for (int k = 0; k < sutun1; k++) { 
                carpimSonuc[i][j] =( carpimSonuc[i][j] ) + ( arr1[i][k] * arr2[k][j] );
            }
        }
    }
}