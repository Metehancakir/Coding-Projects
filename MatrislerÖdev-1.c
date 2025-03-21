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

void rastgeleSayi1(int matrix[satir1][sutun1]);
void rastgeleSayi2(int matrix[satir2][sutun2]);
void yazdir1(int matrix[satir1][sutun1]);
void yazdir2(int matrix[satir2][sutun2]);
void yazdirCarpim(int matrix[satir1][sutun2]);
void yazdirToplam(int matrix[satir1][sutun1]);
void hesaplaToplamSonuc(int arr1[satir1][sutun1], int arr2[satir1][sutun1]);
void hesaplaCarpimSonuc(int arr1[satir1][sutun1], int arr2[satir2][sutun2]);

int main() {
    srand(time(NULL));


    rastgeleSayi1(dizi1);
    rastgeleSayi2(dizi2);

    printf("dizi 1:\n");
    yazdir1(dizi1);
    printf("\n");

    printf("dizi 2:\n");
    yazdir2(dizi2);
    printf("\n");

    
    if (satir1 == satir2 && sutun1 == sutun2) {
        hesaplaToplamSonuc(dizi1, dizi1); 
        printf("dizilerin toplami:\n");
        yazdirToplam(toplamSonuc);
        printf("\n");
    } else {
        printf("matris boyutlari esit olmadigindan toplama yapilamaz\n");
        printf("\n");
    }
    
    
    hesaplaCarpimSonuc(dizi1, dizi2);
    printf("dizilerin carpimi:\n");
    yazdirCarpim(carpimSonuc);
    printf("\n");

    return 0;
}

void rastgeleSayi1(int matrix[satir1][sutun1]) {
    for (int i = 0; i < satir1; i++) {
        for (int j = 0; j < sutun1; j++) {
            matrix[i][j] = rand() % 5 + 1;
        }
    }
}

void rastgeleSayi2(int matrix[satir2][sutun2]) {
    for (int i = 0; i < satir2; i++) {
        for (int j = 0; j < sutun2; j++) {
            matrix[i][j] = rand() % 5 + 1;
        }
    }
}

void yazdir1(int matrix[satir1][sutun1]) {
    for (int i = 0; i < satir1; i++) {
        for (int j = 0; j < sutun1; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void yazdir2(int matrix[satir2][sutun2]) {
    for (int i = 0; i < satir2; i++) {
        for (int j = 0; j < sutun2; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void yazdirToplam(int matrix[satir1][sutun1]) {
    for (int i = 0; i < satir1; i++) {
        for (int j = 0; j < sutun1; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void yazdirCarpim(int matrix[satir1][sutun2]) {
    for (int i = 0; i < satir1; i++) {
        for (int j = 0; j < sutun2; j++) {
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
            for (int k = 0; k < sutun1; k++) { 
                carpimSonuc[i][j] = carpimSonuc[i][j] + ( arr1[i][k] * arr2[k][j] );
            }
        }
    }
}