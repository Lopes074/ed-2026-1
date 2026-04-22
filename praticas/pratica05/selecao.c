#include "selecao.h"

// -------------------
// LINEAR SEARCH
// -------------------
int linear_search(int v[], int n, int chave) {
    for (int i = 0; i < n; i++) {
        if (v[i] == chave) {
            return i;
        }
    }
    return -1;
}

// -------------------
// FUNÇÃO AUXILIAR (PARTITION)
// -------------------
int partition(int v[], int left, int right) {
    int pivot = v[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (v[j] <= pivot) {
            i++;
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }

    int temp = v[i + 1];
    v[i + 1] = v[right];
    v[right] = temp;

    return i + 1;
}

// -------------------
// QUICK SELECT
// -------------------
int quick_select(int v[], int left, int right, int k) {
    if (left == right) {
        return v[left];
    }

    int pivotIndex = partition(v, left, right);

    if (k == pivotIndex) {
        return v[k];
    } else if (k < pivotIndex) {
        return quick_select(v, left, pivotIndex - 1, k);
    } else {
        return quick_select(v, pivotIndex + 1, right, k);
    }
}