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

    
    printf("������� ���������� ��������� �������: ");
    scanf("%d", &m);

    if (m < 2) {
        printf("������ ������ ��������� ��� ������� 2 ��������.\n");
        return 1;
    }

    
    int* P = (int*)malloc(m * sizeof(int));
    if (P == NULL) {
        printf("������ ��������� ������.\n");
        return 1;
    }

    
    printf("������� �������� �������:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &P[i]);
    }

    int count = 0;

    
    for (int i = 0; i < m - 1; i++) {
        if (areReversed(P[i], P[i + 1])) {
            count++;
            printf("���� (%d, %d) �������� ���������������.\n", P[i], P[i + 1]);
        }
    }

    printf("���������� ���, ������� �������� ���������������� �� ���������: %d\n", count);

    
    free(P);

    return 0;
}
