#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int array[500];
void rastgeleSayi();
void yazdir();
void bubbleSort(int array[], int n);
int n = 500;

int main(){
    srand(time(NULL));

    printf("Rastgele Sayilar:\n");
    rastgeleSayi();
    yazdir();    
    bubbleSort(array, n);
    
    printf("\nsiralanmis dizi: ");
    yazdir();
    return 0;
}

void rastgeleSayi(){
    for(int i = 0; i < n; i++){
        array[i] = rand() % 10 + 1;
    }
}    

void yazdir(){
    for(int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

void bubbleSort(int array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (array[i] > array[i + 1]) {
            int temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
            i = -1; 
        }
    }
}



        

