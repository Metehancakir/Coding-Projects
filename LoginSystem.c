#include <stdio.h>
#include <string.h>

char username[100] = "mete";
char password[100] = "12345";

char girilen_sifre[100];
char girilen_ad[100];

void kullaniciAdi(char array[]);
void kullaniciSifre(char array[]);
void input(char array[], void (*inputFonksiyon)(char array[]));
int uzunlukBul(char array[]);
void kontrol(char name[], char pass[]);

int main() {
    kullaniciAdi(girilen_ad);
    kullaniciSifre(girilen_sifre);

    kontrol(girilen_ad, girilen_sifre);

    printf("Girilen sifrenin uzunlugu: %d\n", uzunlukBul(girilen_sifre));
    return 0;
}

void kullaniciAdi(char array[]) {
    printf("Kullanici adi giriniz: ");
    scanf("%s", array);
}

void kullaniciSifre(char array[]) {
    printf("Kullanici şifre giriniz: ");
    scanf("%s", array);

    int uzunluk = uzunlukBul(array);
    if (uzunluk < 4 || uzunluk > 8) {
        printf("Kullanici şifreniz 4 ile 8 karakter arasinda olmalidir\n");
    }
}

int uzunlukBul(char array[]) {
    int i;
    for (i = 0; array[i] != '\0'; i++);
    return i;
}

void kontrol(char name[], char pass[]) {
    if (strcmp(name, username) == 0 && strcmp(pass, password) == 0) {
        printf("Dogru giris\n");
    } else {
        printf("Yanlis giris\n");
    }
}