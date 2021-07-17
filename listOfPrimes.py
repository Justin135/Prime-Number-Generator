#from simplestMethods import good
import math, time

def good(num):
    
    if num % 2 == 0 and num != 2:
        #print(f"{num} = Composite")
        return False
    
    for i in range(3, math.ceil(math.sqrt(num)) + 1, 2):
        
        if num % i == 0:
            #print(f"{num} = Composite")
            return False
    
    #print(f"{num} = Prime")
    return True

start = time.time()
f = open("primes.txt", "w")
f.write("2\n")

for i in range(3, 1000000, 2):
    
    if good(i):
        f.write(str(i) + "\n")

f.close()
end = time.time() - start
print(end)