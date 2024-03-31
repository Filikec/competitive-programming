#include <iostream>
#include <ctime>

#define LIMIT 1000000

using namespace std;


int main(){


   

    long double ones = 0, zeroes = 0, count = 0;
    long long x = 123;
    long long a = 212;
    long long c = 32;
    long long m = 3213;

    int prev = 1;

    for (long long i=0;i<LIMIT;i++){    
         x = (a*x+c)%m;
         
         if (x%2){
            if (!prev){
                ones++;
                count++;
            }
         }else if (prev){
            zeroes++;
            count++;
         }

         prev = x%2;
    }

    cout << "1 - " << ones/count << ", 0 - " << zeroes/count << '\n';

    return 0;
}
