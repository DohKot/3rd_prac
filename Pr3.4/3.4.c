#include<stdio.h>
#include<stdlib.h>
#include <math.h>
void massive(float* h, int n)
{
    int count = 0;
    for (int j = 0; j < n; j++)
    {
        if (h[j] >= 0)
            count++;
    }
    float* c = (float*) malloc(count * sizeof(float));
    int count_c = 0;
    for (int i = 0; i < n; i++)
    {
        if (h[i] >= 0)
        {
            c[count_c] = (pow(h[i], 0.5) / 5);
            count_c++;
        }
    }
    for (int i = 0; i < count; i++)
        printf("%f\n", c[i]);

    int minIdx;
    float temp;
    for (int i = 0; i < count - 1; i++) {
        minIdx = i;
        for (int j = i + 1; j < count; j++) {
            if (c[j] < c[minIdx]) {
                minIdx = j;
            }
        }
        // Меняем местами найденный минимальный элемент с текущим элементом
        temp = c[minIdx];
        c[minIdx] = c[i];
        c[i] = temp;
    }

    // Вывод отсортированного массива
    printf("Отсортированный массив:\n");
    for (int i = 0; i < count; i++) {
        printf("%f\n", c[i]);
    }
    free(c);

}
int main()
{
    int n = 6;
    int count = 0;
    float* b = (float*) malloc(n * sizeof(float));
    b[0] = -23;
    b[1] = 12;
    b[2] = 34;
    b[3] = 98.78;
    b[4] = -123.456;
    b[5] = 0.899;
    massive(b, n);
    free(b);
}
