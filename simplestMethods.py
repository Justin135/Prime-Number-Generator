import math, time

def worst(num):
    
    for i in range(2, num - 1):
        if num % i == 0:
            print(f"{num} = Composite")
            return False
    
    print(f"{num} = Prime")
    return True

def good(num):
    
    if num % 2 == 0:
        #print(f"{num} = Composite")
        return False
    
    for i in range(2, int(math.sqrt(num)), 2):
        if num % i == 0:
            #print(f"{num} = Composite")
            return False
    
    #print(f"{num} = Prime")
    return True

start = time.time()
good(200002177)
end = time.time() - start
print(end)

start = time.time()
worst(200002177)
end = time.time() - start
print(end)