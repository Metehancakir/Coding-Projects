#include <stdio.h>
#include <stdlib.h>

#define N 9

char *binalar[N] = {
    "Muhendislik",
    "Fen",
    "Kutuphane",
    "MerkezKantin",
    "Yurt",
    "SporSalonu",
    "SaglikMerkezi",
    "Rektorluk",
    "KonferansSalonu"
};


int graph[N][N] = {

   //m f k mk y ss sm r ks
    {0,1,0,1, 0,0, 0, 0,0}, // Muhendislik
    {1,0,1,0, 0,0, 0, 0,0}, // Fen
    {0,1,0,1, 1,0, 0, 0,0}, // Kutuphane 
    {1,0,1,0, 1,0, 0, 0,0}, // MerkezKantin
    {0,0,1,1, 0,1, 0, 0,0}, // Yurt 
    {0,0,0,0, 1,0, 1, 0,0}, // SporSalonu
    {0,0,0,0, 0,1, 0, 0,0}, // SaglikMerkezi
    {0,0,0,0, 0,0, 0, 0,1}, // Rektorluk
    {0,0,0,0, 0,0, 0, 1,0}  // KonferansSalonu


};



void bfs(int start, int end) { //zaman karmaşıklığı O(V + E) cünkü her düğüm ve kenar en fazla bir kez ziyaret edilir
    int visited[N] = {0};
    int prev[N];
    for (int i = 0; i < N; i++) prev[i] = -1;

    int queue[N], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int v = queue[front++];

        for (int i = 0; i < N; i++) {
            if (graph[v][i] && !visited[i]) {
                visited[i] = 1;
                prev[i] = v;
                queue[rear++] = i;
            }
        }
    }

    if (!visited[end]) {
        printf("Bu iki bina arasinda yol yok.\n");
        return;
    }

    int path[N], len = 0;
    for (int at = end; at != -1; at = prev[at])
        path[len++] = at;

    printf("En az durakli yol:\n");
    for (int i = len - 1; i >= 0; i--) {
        printf("%s", binalar[path[i]]);
        if (i != 0) printf(" -> ");
    }
    printf("\n");
}

void dfs(int v, int visited[]) { //zaman karmaşıklığı O(V + E) cünkü her düğüm ve kenar en fazla bir kez ziyaret edilir
    visited[v] = 1;
    printf("%s ", binalar[v]);

    for (int i = 0; i < N; i++) {
        if (graph[v][i] && !visited[i])
            dfs(i, visited);
    }
}

int main() {
    int start, end;
    int visited[N] = {0};

    printf("Binalar:\n");
    for (int i = 0; i < N; i++)
        printf("%d - %s\n", i, binalar[i]);

    printf("\nBaslangic binasi numarasi: ");
    scanf("%d", &start);
    printf("Hedef binasi numarasi: ");
    scanf("%d", &end);

    bfs(start, end);

    printf("\nBagli bilesenler:\n");
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            dfs(i, visited);
            printf("\n");
        }
    }

    return 0;
}
