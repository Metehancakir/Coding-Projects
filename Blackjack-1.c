#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int input();
int random();
int secim, kasa, kullanici;

int main() {
    srand(time(NULL));
    kasa = random() + random();
    kullanici = random() + random();
    printf("Eliniz %d, Kasa %d \n", kullanici, kasa);
    printf("Cekmek istiyorsaniz 1'i, Kalmak istiyorsaniz 2'yi tuslayin:\n");

    do {
        secim = input();
        if (secim == 1) {
            kullanici += random();
            if (kullanici > 21) {
                printf("Eliniz %d, Kasa %d. Patladiniz.\n", kullanici, kasa);
                return 0;
            } else if (kullanici == 21) {
                break;
            }
            printf("Eliniz %d. Devam etmek istiyorsaniz 1'i, Kalmak istiyorsaniz 2'yi tuslayin:\n", kullanici);
        } else if (secim == 2) {
            break;
        } else {
            printf("Gecersiz giris, lutfen 1 veya 2 tuslayin.\n");
        }
    } while (secim != 2);

    while (kasa < 17) {
        kasa += random();
    }

    if (kasa > 21 || kullanici > kasa) {
        printf("Eliniz %d, Kasa %d. Kazandiniz!\n", kullanici, kasa);
    } else {
        printf("Eliniz %d, Kasa %d. Kaybettiniz.\n", kullanici, kasa);
    }

    return 0;
}

int random() {
    return rand() % 10 + 1;
}

int input() {
    int temp;
    scanf("%d", &temp);
    return temp;
}