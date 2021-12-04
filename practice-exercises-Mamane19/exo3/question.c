#include <stdio.h>


void add(int *a, int *b) {
    *a = *a + *b;
}


int main() {
    int a = 5;
    int b = 100;
    add(&a, &b);
    printf("%d\n", a);
    return 0;
}