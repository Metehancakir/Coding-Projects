#include <stdio.h>
#include <stdlib.h>

void ortalama(int ogrenci, int sinav, int dizi[ogrenci][sinav]);
int minimum(int ogrenci, int sinav, int dizi[ogrenci][sinav]);
int maximum(int ogrenci, int sinav, int dizi[ogrenci][sinav]);
void yazdir(int ogrenci, int sinav, int dizi[ogrenci][sinav]);

int main() {
    int ogrenci, sinav;

    printf("Kac ogrenci var: ");
    scanf("%d", &ogrenci);
    printf("Kac sinav var: ");
    scanf("%d", &sinav);

    int dizi[ogrenci][sinav];

    for (int k = 0; k < ogrenci; k++) {
        for (int i = 0; i < sinav; i++) {
            printf("Notlari sirayla giriniz: ");
            scanf("%d", &dizi[k][i]);
        }
    }

    yazdir(ogrenci, sinav, dizi);
    printf("\n");

    ortalama(ogrenci, sinav, dizi);
    printf("\n");

    int min = minimum(ogrenci, sinav, dizi);
    printf("En dusuk not: %d\n", min);

    int max = maximum(ogrenci, sinav, dizi);
    printf("En yuksek not: %d\n", max);

    return 0;
}

void yazdir(int ogrenci, int sinav, int dizi[ogrenci][sinav]) {
    for (int i = 0; i < ogrenci; i++) {
        printf("Ogrenci %d notlari: ", i + 1);
        for (int j = 0; j < sinav; j++) {
            printf("%d ", dizi[i][j]);
        }
        printf("\n");
    }
}

int minimum(int ogrenci, int sinav, int dizi[ogrenci][sinav]) {
    int min = 100;

    for (int i = 0; i < ogrenci; i++) {
        for (int j = 0; j < sinav; j++) {
            if (dizi[i][j] < min) {
                min = dizi[i][j];
            }
        }
    }

    return min;
}

int maximum(int ogrenci, int sinav, int dizi[ogrenci][sinav]) {
    int max = 0;

    for (int i = 0; i < ogrenci; i++) {
        for (int j = 0; j < sinav; j++) {
            if (dizi[i][j] > max) {
                max = dizi[i][j];
            }
        }
    }

    return max;
}

void ortalama(int ogrenci, int sinav, int dizi[ogrenci][sinav]) {
    for (int i = 0; i < ogrenci; i++) {
        int toplam = 0;
        for (int j = 0; j < sinav; j++) {
            toplam += dizi[i][j];
        }
        double ortalama = toplam / (double)sinav;
        printf("Ogrenci %d ortalamasi: %.2f\n", i + 1, ortalama);
    }
}