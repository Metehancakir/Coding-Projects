#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL 100
#define MAX_STACK 50


typedef struct {
    char urls[MAX_STACK][MAX_URL];
    int top;
} Stack;

typedef struct {
    char aktifSayfa[MAX_URL];
    Stack backYigini;
    Stack forwardYigini;
} Tarayici;

void yiginBaslat(Stack *s) {
    s->top = -1;
}

int bosMu(Stack *s) {
    return s->top == -1;
}

void ekle(Stack *s, char *url) {
    if (s->top < MAX_STACK - 1) {
        s->top++;
        strcpy(s->urls[s->top], url);
    }
}

void cikar(Stack *s, char *url) {
    if (s->top >= 0) {
        strcpy(url, s->urls[s->top]);
        s->top--;
    }
}

void temizle(Stack *s) {
    s->top = -1;
}

void tarayiciBaslat(Tarayici *t) {
    strcpy(t->aktifSayfa, "Bos");
    yiginBaslat(&t->backYigini);
    yiginBaslat(&t->forwardYigini);
}

void ziyaretEt(Tarayici *t, char *url) {
    if (strcmp(t->aktifSayfa, "Bos") != 0) {
        ekle(&t->backYigini, t->aktifSayfa);
    }
    strcpy(t->aktifSayfa, url);
    temizle(&t->forwardYigini);
    printf("\n-> %s adresine gidildi\n", url);
}

void geriGit(Tarayici *t) {
    if (bosMu(&t->backYigini)) {
        printf("\nGeri gidilemez!\n");
        return;
    }
    char oncekiSayfa[MAX_URL];
    ekle(&t->forwardYigini, t->aktifSayfa);
    cikar(&t->backYigini, oncekiSayfa); // onceki sayfayi backten cıkar
    strcpy(t->aktifSayfa, oncekiSayfa); // onceki sayfayi aktif sayfaya kopyala
    printf("\n<- Geri: %s\n", t->aktifSayfa);
}

void ileriGit(Tarayici *t) {
    if (bosMu(&t->forwardYigini)) {
        printf("\nIleri gidilemez!\n");
        return;
    }
    char sonrakiSayfa[MAX_URL];
    ekle(&t->backYigini, t->aktifSayfa);
    cikar(&t->forwardYigini, sonrakiSayfa);
    strcpy(t->aktifSayfa, sonrakiSayfa);
    printf("\n-> Ileri: %s\n", t->aktifSayfa);
}

void durumGoster(Tarayici *t) {
    printf("Aktif Sayfa: %s\n", t->aktifSayfa);
    
    printf("Back Yigini: ");
    if (bosMu(&t->backYigini)) {
        printf("[Bos]");
    } else {
        for (int i = t->backYigini.top; i >= 0; i--) {
            printf("%s ", t->backYigini.urls[i]);
        }
    }
    
    printf("\nForward Yigini: ");
    if (bosMu(&t->forwardYigini)) {
        printf("[Bos]");
    } else {
        for (int i = t->forwardYigini.top; i >= 0; i--) {
            printf("%s ", t->forwardYigini.urls[i]);
        }
    }
}

int main() {
    Tarayici t;
    tarayiciBaslat(&t);
    
    int secim;
    char url[MAX_URL];
    
    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Yeni URL\n");
        printf("2. Geri\n");
        printf("3. Ileri\n");
        printf("4. Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &secim);
        getchar();
        
        if (secim == 1) {
            printf("URL: ");
            fgets(url, MAX_URL, stdin);
            url[strcspn(url, "\n")] = 0;
            ziyaretEt(&t, url);
            durumGoster(&t);
        }
        else if (secim == 2) {
            geriGit(&t);
            durumGoster(&t);
        }
        else if (secim == 3) {
            ileriGit(&t);
            durumGoster(&t);
        }
        else if (secim == 4) {
            printf("\ncikiliyor\n");
            break;
        }
        else {
            printf("\ngecersiz secim!\n");
        }
    }
    
    return 0;
}
