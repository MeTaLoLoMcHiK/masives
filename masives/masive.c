#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>



bool areReversed(int a, int b) {
    int reversed = 0, original = b;
    while (b != 0) {
        reversed = reversed * 10 + b % 10; 
        b /= 10;
    }
    return reversed == a; 
}

int main() {
    setlocale(LC_ALL, "RU"); 
    int m;

    
    printf("Введите количество элементов массива: ");
    scanf("%d", &m);

    if (m < 2) {
        printf("Массив должен содержать как минимум 2 элемента.\n");
        return 1;
    }

    
    int* P = (int*)malloc(m * sizeof(int));
    if (P == NULL) {
        printf("Ошибка выделения памяти.\n");
        return 1;
    }

    
    printf("Введите элементы массива:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &P[i]);
    }

    int count = 0;

    
    for (int i = 0; i < m - 1; i++) {
        if (areReversed(P[i], P[i + 1])) {
            count++;
            printf("Пара (%d, %d) является противоположной.\n", P[i], P[i + 1]);
        }
    }

    printf("Количество пар, которые являются противоположными по написанию: %d\n", count);

    
    free(P);

    return 0;
}
