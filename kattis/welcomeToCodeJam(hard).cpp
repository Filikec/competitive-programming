#include <iostream>
#include <unordered_map>

using namespace std;

char mapI[19] = {'w','e','l','c','o','m','e',' ','t','o',' ','c','o','d','e',' ','j','a','m'};

void work(){
    int dynamic[501][20];
    string line;

    getline(cin,line);

    int size = line.size();

    for (int i=0;i<=500;i++){
        for (int k=0;k<=19;k++){ 
            dynamic[i][k] = 0;
        }
        dynamic[i][0] = 1;
    }
        

    for (int i=1;i<=size;i++){
        for (int j=1;j<=19;j++){
            dynamic[i][j] = dynamic[i-1][j];
            
            if (line[i-1] == mapI[j-1]) dynamic[i][j] += dynamic[i-1][j-1];
            dynamic[i][j] %= 10000;
        }
    }

    printf("%.04d\n",dynamic[size][19]);

}


int main(){
    int n;

    cin >> n;
    cin.get();
    for (int i=0;i<n;i++){
        cout << "Case #" << i+1 << ": ";
        work();
    }


    return 0;
}