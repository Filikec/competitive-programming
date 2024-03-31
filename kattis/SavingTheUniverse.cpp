#include <iostream>
#include <unordered_map>

using namespace std;


string Engines[100];

int Lines[1001][100];
int Best[1002];

void work(int c){
    int s;
    cin >> s;
    cin.get();

    for (int i=0;i<s;i++){
        getline(cin,Engines[i]);
    }

    int q;
    cin >> q;
    cin.get();
    
    
    for (int i=0;i<q;i++){
        string search;
        getline(cin,search);
        for (int j=0;j<s;j++){
            Lines[i][j] = (search != Engines[j]);
        }   
        Best[i] = 1;
    }

    for (int i=0;i<s;i++){
        for (int j=q-2;j>=0;j--){
            if (Lines[j][i]){
                Lines[j][i] += Lines[j+1][i];
            }else{
                Lines[j][i] = 0;
            }
            Best[j] = max(Best[j],Lines[j][i]);
        }   
    } 
    

    int index = 0;
    int switches = 0;

    while (index <= q-1){   
        switches++;
        index += Best[index];    
    }
    switches--;
    cout << "Case #" << c << ": " << (switches<0?0:switches) << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cases;

    cin >> cases;

    for (int i=0;i<cases;i++){
        work(i+1);
    }



    return 0;
}




