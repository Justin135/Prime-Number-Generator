#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define PRIME_1LIMIT 1000
#define PRIME_2LIMIT 1000000

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
    
    bool primes[PRIME_1LIMIT];
    
    for(int i = 3;i < PRIME_1LIMIT;i += 2) {
        primes[i] = true;
    }
    
    primes[0] = false;
    primes[1] = false;
    primes[2] = true;
    
    int primeNumbers[10] = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    
    for(int i = 0;i < 10;i++) {
        
        for(int j = 3;primeNumbers[i] * j < PRIME_1LIMIT;j += 2) {
            primes[primeNumbers[i] * j] = false;
        }
    }
    
    fprintf(f, "2\n");
    
    for(int i = 3;i < PRIME_1LIMIT;i += 2) {
        //printf("%d - %s\n", i, primes[i] ? "true" : "false"); // Cool way of printing true/false for booleans.
        
        if(primes[i]) {
            fprintf(f, "%d\n", i);
            //isPrime(i);
        }
    }
    
    fclose(f);
    
    
    /********************************
    *            MILLION            *
    ********************************/
    
    FILE * f2 = fopen("primes2.txt", "r");
    bool primes2[PRIME_2LIMIT];
    
    for(int i = 3;i < PRIME_2LIMIT;i += 2) {
        primes2[i] = true;
    }
    
    primes[0] = false;
    primes[1] = false;
    primes[2] = true;
    
    int primeNumbers2[167] = {};
    int primeMultiples[167] = {};
    
    fscanf(f2, "%d", &primeNumbers2[0]);
    
    for(int i = 0; i < 167;i++) {
        fscanf(f2, "%d", &primeNumbers2[i]);
    }
    
    fclose(f2);
    
    for(int i = 0;i < 167;i++) {
        
        for(int j = 3;primeNumbers2[i] * j < PRIME_2LIMIT;j += 2) {
            primes2[primeNumbers2[i] * j] = false;
            primeMultiples[i] = primeNumbers2[i] * j;
        }
    }
    
    FILE * f3 = fopen("primes3.txt", "w");
    
    fprintf(f3, "2\n");
    
    for(int i = 3;i < PRIME_2LIMIT;i += 2) {
        //printf("%d - %s\n", i, primes[i] ? "true" : "false"); // Cool way of printing true/false for booleans.
        
        if(primes2[i]) {
            fprintf(f3, "%d\n", i);
            //isPrime(i);
        }
    }
    
    time(&end_t);
    diff_t = difftime(end_t, start_t);
    printf("Execution time = %f\n", diff_t);
    
    /********************************
    *            BILLION            *
    ********************************/
    
    FILE * f4 = fopen("primes3.txt", "r");
    
    int primeNumbers3[78497] = {};
    int primeMultiples2[78497] = {};
    
    for(int i = 0;i < 167;i++) {
        primeMultiples2[i] = primeMultiples[i];
    }
    
    fscanf(f4, "%d", &primeNumbers3[0]);
    
    for(int i = 0; i < 78497;i++) {
        fscanf(f4, "%d", &primeNumbers3[i]);
    }
    
    fclose(f4);
    
    puts("Good.");
    
    
    for(int k = 1;k < 2;k++) {
        
        for(int i = 1;i < PRIME_2LIMIT;i += 2) {
            primes2[i] = true;
        }
        /*
        for(int i = 0;pow(primeNumbers3[i], 2) < (PRIME_2LIMIT * (k + 1));i++) {
            printf("Good.%d\n", i);
            for(int j = 1;primeMultiples2[i] * (primeNumbers3[i] * j) < (PRIME_2LIMIT * (k + 1));j += 2) {
                printf("G.%d\n", j);
                primes2[(primeMultiples2[i] * (primeNumbers3[i] * j)) - (PRIME_2LIMIT * k)] = false;
            }
        }
        */
        
        puts("Good.");
        /*
        FILE * f5 = fopen("primes4.txt", "a");
        
        for(int i = 1;i < PRIME_2LIMIT;i += 2) {
            
            if(primes2[i]) {
                fprintf(f5, "%d\n", (i + (PRIME_2LIMIT * k)));
            }
        }
        
        fclose(f5);
        */
    }
    
}

int main(void) {
    
    getPrimes();
    return 0;
}