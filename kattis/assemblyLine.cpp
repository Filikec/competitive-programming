#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<char,int> charToIndex;
char indexToChar[26];
long long Table[26][26][2];

long long Dynamic[200][201][26];

void work(int n){
    string line;

    cin >> line;

    for (int i=0;i<line.size()+1;i++){
        for (int j=0;j<line.size();j++){
            for (int k=0;k<n;k++){
                Dynamic[j][i][k] = INT32_MAX;
            }
        }
    }

    for (int i=0;i<line.size();i++){
        Dynamic[i][1][charToIndex[line[i]]] = 0;
    }
    

    for (int s=2;s<=line.size();s++){
        for (int i=0;i+s<=line.size();i++){
            for (int j=1;j<s;j++){
                for (int c1=0;c1<n;c1++){
                    for (int c2=0;c2<n;c2++){
                        int result = Table[c1][c2][1];
                        long long time = Table[c1][c2][0];
                        Dynamic[i][s][result] = min(Dynamic[i][s][result],Dynamic[i][j][c1]+Dynamic[i+j][s-j][c2]+time);
                    }
                }
            }
        }    
    }

    int minimal = 0;
    for (int i=0;i<n;i++){
        if (Dynamic[0][line.size()][minimal] > Dynamic[0][line.size()][i]) minimal = i;
    }   

    cout << Dynamic[0][line.size()][minimal] << '-' << indexToChar[minimal] << '\n';
    

}


int main(){

    int n;

    cin >> n;

    for (int i=0;i<n;i++){
        char tmp;
        cin >> tmp;
        charToIndex[tmp] = i;
        indexToChar[i] = tmp;
    }

     for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            long long time;
            cin >> time;
            cin.get();
            char result;
            cin >> result;
            Table[i][j][0] = time;
            Table[i][j][1] = charToIndex[result];
        }
    }

    int cases;

    cin>>cases;

    for (int c=0;c<cases;c++){
        work(n);
    }

    return 0;
}