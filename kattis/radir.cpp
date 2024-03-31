#include <iostream>
#include <list>

#define INF 2147483647

using namespace std;

int Card_appearances[52];

int get_int(){
    int num = 0;
    char c;

    while ((c=getchar()) >= '0'){
        num = num*10+c-'0';
    }
    return num;
}

int main(){

    int n,p;

    cin >> n >> p;
    getchar();
    for (int i=0;i<52;i++) Card_appearances[i] = INF;
    for (int i=0;i<n;i++){
        int suit, value, card;
        suit = get_int();
        value = get_int();
        card = (suit-1)*13+value-1;
        if (Card_appearances[card] == INF){
            Card_appearances[card] = i;
        }
    }

    int mini = INF;
    for (int i=0;i<52;i++){
        int value = i%13+1;
        if (value > 11) continue;

        int first = Card_appearances[i], second=Card_appearances[i+1], third=Card_appearances[i+2];
        
        if (first==INF || second==INF || third==INF) continue;

        mini = min(mini,max(max(first,second),third));
    }  

    if (mini == INF){
        cout << "neibb\n";
    }else if (mini+1 <= p){
        cout << 1 << "\n";
    }else{
        cout << mini+1-p << "\n";
    }

    

    return 0;
}
