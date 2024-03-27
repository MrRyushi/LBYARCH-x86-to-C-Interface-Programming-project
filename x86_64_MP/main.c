#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

extern float dotproduct(int *vectorA, int *vectorB, int length);

float dotProductC(float vectorA[], float vectorB[], int length) {
    float sum = 0;
    for (int i = 0; i < length; i++) {
        float mul = vectorA[i] * vectorB[i];
        sum += mul;
    }
    return sum;
}

int main() {
    // Seed the random number generator
    srand((unsigned int)time(NULL));

    // get the length of vectors
    printf("Input Vector Length: ");
    int length = 0;
    scanf_s("%d", &length);

    // declare the vectors and sdot variable
    float* vectorA = malloc(length * sizeof(float));
    float* vectorB = malloc(length * sizeof(float));
    float sdot = 0.0;
    float sdot2 = 0.0;

    // Initialize random data
    for (int i = 0; i < length; i++) {
        // Generate a random integer between 1 and 1000 (for more precision)
        int randomInt = rand() % 1000 + 1;
        // Convert to float and scale to desired range (1 to 10)
        float randomValue = (float)randomInt / 100.0f;
        vectorA[i] = randomValue;
        vectorB[i] = randomValue;
    }

    // Measure time for Assembly Kernel
    clock_t start_time = clock();
    sdot = dotproduct(vectorA, vectorB, length);
    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Time taken by A Kernel: %fs\n", elapsed_time);
    printf("Assembly Kernel Result = %f \n", sdot);

    // Measure time for C Kernel
    start_time = clock();
    sdot2 = dotProductC(vectorA, vectorB, length);
    end_time = clock();
    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Time taken by C Kernel: %f seconds\n", elapsed_time);
    printf("C Kernel Result = %f \n", sdot2);

    free(vectorA);
    free(vectorB);
    

    return 0;

}