#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

extern float dotproduct(float *vectorA, float *vectorB, int length);

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
    float sdot = 0;

    // Initialize random data
    for (int i = 0; i < length; i++) {
        // Generate a random integer between 1 and 1000 (for more precision)
        int randomInt = rand() % 1000 + 1;
        // Convert to float and scale to desired range (1 to 10)
        float randomValue = (float)randomInt / 100.0f;
        vectorA[i] = randomValue;
        vectorB[i] = randomValue;
        printf("value %i = %f \n", i, randomValue);
    }

    printf("%f", dotproduct(vectorA, vectorB, length));
    printf("sdot = %f \n", sdot);

    // Don't forget to free allocated memory when done
    free(vectorA);
    free(vectorB);

    return 0;

}