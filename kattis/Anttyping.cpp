#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <set>

using namespace std;




int Count[9][9],First;
long long Best = 10000000;


void getSeconds(vector<int> &num){
    int Dist[9][9];
    

    Count[num[0]-1][First-1]++;

    for (int i=0;i<num.size();i++){
        for (int j=i;j<num.size();j++){
            Dist[num[i]-1][num[j]-1] = Dist[num[j]-1][num[i]-1] = j-i;
        }
    }
    long long needed = 0;
    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            needed += Count[i][j]*Dist[i][j];
        }
    }

    Count[num[0]-1][First-1]--;
    Best = min(Best,needed);
}


void getNum(vector<int> &num,set<int> &choices){

    if (num.size() == 9){
        getSeconds(num);
        return;
    }
    auto copy = choices;
    for (auto c : choices){
        num.push_back(c);
        copy.erase(c);
        
        getNum(num,copy);

        copy.insert(c);
        num.pop_back();
    }
}

int main(){
    string line;

    getline(cin,line);
    First = line[0]-'0';

    for (int i=0;i<line.size()-1;i++){
        Count[line[i]-'0'-1][line[i+1]-'0'-1]++;
    }

    vector<int> num;
    set<int>choices = {1,2,3,4,5,6,7,8,9};

    getNum(num,choices);

    cout << Best+line.size() << '\n';


    return 0;
}