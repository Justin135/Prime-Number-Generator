#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define LIMIT 1000000000
#define BITS 32
#define SetBit(A,k)     ( A[(k / 32)] |= (1 << (k % 32)) ) // Go to index k / 32, then shift 1 k % 32 times.
#define GetBit(A,k)     ( A[(k / 32)] & (1 << (k % 32)) )

// 4-bytes.
typedef struct {
    unsigned b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1;
} Bits;

void efficientMemoryPrimes(int limit);
void efficientMemoryPrimes(int limit) {
    
    clock_t  start = clock();
    int * primes = calloc(limit / BITS, sizeof(int));
    
    if(primes == NULL) {
        return;
    }
    
    for(unsigned long long int i = 3;i < limit;i += 2) {
        
        if(!GetBit(primes, i)) {
            
            for(int j = 3;(i * j) < limit;j += 2) {
                SetBit(primes, (i * j));
            }
            
            //printf("%lld done.\n", i);
        }
    }
    
    FILE * f = fopen("bitwisePrimes.txt", "w");
    fprintf(f, "2\n");
    
    for(int i = 3;i < limit;i += 2) {
        
        if(!GetBit(primes, i)) {
            fprintf(f, "%d\n", i);
        }
    }
    
    fclose(f);
    free(primes);
    
    clock_t diff = clock() - start;
    printf("Timed: %g\n", (diff / CLOCKS_PER_SEC));
}

void getPrimes(int limit);
void getPrimes(int limit) {
    
    clock_t  start = clock();
    
    bool * primes = calloc(limit, sizeof(bool));
    
    if(primes == NULL) {
        puts("Damnit.");
        return;
    }
    
    for(unsigned long long int i = 3;i < limit;i += 2) {
        
        if(!primes[i]) {
            
            for(int j = 3;(i * j) < limit;j += 2) {
                primes[i * j] = true;
            }
        }
    }
    
    FILE * f = fopen("secondSieveAttemptPrimes.txt", "w");
    fprintf(f, "2\n");
    
    for(int i = 3;i < limit;i += 2) {
        
        if(!primes[i]) {
            fprintf(f, "%d\n", i);
        }
    }
    
    fclose(f);
    free(primes);
    
    clock_t diff = clock() - start;
    printf("Timed: %g\n", (diff / CLOCKS_PER_SEC));
}

int main(void) {
    
    // getPrimes(LIMIT);
    efficientMemoryPrimes(LIMIT);
    return 0;
}