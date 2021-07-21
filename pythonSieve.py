import time

def sieve(n):
    
    primes = [True] * (n + 1)
    
    for i in range(2, n + 1):
        
        if primes[i]:
            for j in range(i * i, n + 1, i):
                primes[j] = False
    
    f = open("pythonSievePrimes.txt", "w")
    
    for i in range(2, n + 1):
        
        if primes[i]:
            f.write(str(i) + "\n")
    
start = time.time()
sieve(1000000)
end = time.time() - start
print(end)