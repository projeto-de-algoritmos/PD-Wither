#include <stdio.h>
#include <stdlib.h>

int knapsack(int *wt, int *val, int W, int n, int **matrix) {
    // base conditions
    if (n == 0 || W == 0) {
        return 0;
    }
    if (matrix[n][W] != -1) {
        return matrix[n][W];
    }

    // choice diagram code
    if (wt[n - 1] <= W) {
        matrix[n][W] = (val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1, matrix)) >
                       knapsack(wt, val, W, n - 1, matrix)
                           ? (val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1, matrix))
                           : knapsack(wt, val, W, n - 1, matrix);
        return matrix[n][W];
    } else if (wt[n - 1] > W) {
        matrix[n][W] = knapsack(wt, val, W, n - 1, matrix);
        return matrix[n][W];
    }
}

int main() {
    int instancias;
    scanf("%d", &instancias);
    int *poderes = malloc(sizeof(int));
    int *pesos = malloc(sizeof(int));

    for (int i = 0; i < instancias; i++) {
        int qnt_projeteis;
        scanf("%d", &qnt_projeteis);
        poderes = realloc(poderes, qnt_projeteis * sizeof(int));
        pesos = realloc(pesos, qnt_projeteis * sizeof(int));
        for (int j = 0; j < qnt_projeteis; j++) {
            int poder, peso;
            scanf("%d %d", &poder, &peso);
            poderes[j] = poder;
            pesos[j] = peso;
        }

        int cargaCanhao, resistenciaCastelo;
        scanf("%d %d", &cargaCanhao, &resistenciaCastelo);
        int **matrix = malloc((qnt_projeteis + 1) * sizeof(int *));
        for (int k = 0; k < qnt_projeteis + 1; k++) {
            matrix[k] = malloc((cargaCanhao + 1) * sizeof(int));
            for (int l = 0; l < cargaCanhao + 1; l++) {
                matrix[k][l] = -1;
            }
        }
        int poderDestrutivo = knapsack(pesos, poderes, cargaCanhao, qnt_projeteis, matrix);

        if (poderDestrutivo >= resistenciaCastelo) {
            printf("Missao completada com sucesso\n");
        } else {
            printf("Falha na missao\n");
        }

        for (int k = 0; k < qnt_projeteis + 1; k++) {
            free(matrix[k]);
        }
        free(matrix);
    }

    free(poderes);
    free(pesos);

    return 0;
}
