#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define PRIME_LIMIT 1000

// Quick function to check that the code works.
void isPrime(int num);

void isPrime(int num) {
    
    if(num % 2 == 0) {
        printf("%d - COMPOSITE\n", num);
        return;
    }
    
    for(int i = 3;i < sqrt(num) + 1;i += 2) {
        
        if(num % i == 0) {
            printf("%d - COMPOSITE %d\n", num, i);
            return;
        }
    }
}

void getPrimes();

void getPrimes() {
    
    time_t start_t, end_t;
    double diff_t;
    
    time(&start_t);
    FILE * f = fopen("primes2.txt", "w");
    
    bool primes[PRIME_LIMIT];
    
    for(int i = 2;i < PRIME_LIMIT;i++) {
        primes[i] = true;
    }
    
    primes[0] = false;
    primes[1] = false;
    
    int primeNumbers[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    
    for(int i = 0;i < 11;i++) {
        
        for(int j = 2;primeNumbers[i] * j < PRIME_LIMIT;j++) {
            primes[primeNumbers[i] * j] = false;
        }
    }
    
    for(int i = 2;i < PRIME_LIMIT;i++) {
        //printf("%d - %s\n", i, primes[i] ? "true" : "false"); // Cool way of printing true/false for booleans.
        
        if(primes[i]) {
            fprintf(f, "%d\n", i);
            //isPrime(i);
        }
    }
    
    fclose(f);
    
    time(&end_t);
    diff_t = difftime(end_t, start_t);
    printf("Execution time = %f\n", diff_t);
}

int main(void) {
    
    getPrimes();
    return 0;
}