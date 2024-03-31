from array import array
from concurrent.futures import process
import sys

D = array('d');
for i in range(1001):
    for j in range(100):
        D.append(0);

def index(i, j):
    return i*10+j



def process(n,k):
    k+=1
    for j in range(k):
        D[index(1,j)] = 1;

    for i in range(2,n+1):
        for j in range(k):
            D[index(i,j)] = D[index(i-1,j)]
            if j > 0:
                D[index(i,j)] += D[index(i-1,j-1)]
            if j < k-1:
                D[index(i,j)] += D[index(i-1,j+1)]


for i in sys.stdin:
    ab = i.split()
    k = int(ab[0])
    n = int(ab[1])
    process(n,k)
    count = 0 
    for j in range(k+1):
        count += D[index(n,j)]
    print(str(count/pow(k+1,n)*100))

