#include <iostream>

using namespace std;

char in[1<<21]; // sizeof in varied in problem
char const*o;

void init_in()
{ 
    o = in; 
    in[ fread(in,1,sizeof(char),stdin)]=0;//set 0 at the end of buffer.
}

int readInt(){ 
   unsigned u = 0, s = 0;
   
   while(*o>='0' && *o<='9')u = (u<<3) + (u << 1) + (*o++ - '0');  // u * 10 = u * 8 + u * 2 :)
   
   return static_cast<int>( (u^s) + !!s) ;
}

int main(){
    int n, cases, curr,operations,comp,comparison,i;
    init_in();
    cases = readInt();
    cout << cases << "\n";
    for (int j=0;j<cases;j++){
        n = readInt();
    
        operations = 0;
        comp = 1;
        for (i=0;i<n-8;i+=8){
            curr = readInt();
            comparison = curr==comp;
            comp += comparison;
            operations += !comparison;
        }   
        printf("%d\n",operations);
    }

    return 0;
}