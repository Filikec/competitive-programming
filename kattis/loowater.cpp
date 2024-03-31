#include <iostream>

#define MAX_HEIGHT 10000

using namespace std;

int Heads[20000], Soldiers[MAX_HEIGHT+1];

int get_int(){
    char c;
    int num = 0;

    while ((c=cin.get())>='0'){
        num = num*10+c-'0';
    }
    return num;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    while ((n = get_int()) && (m = get_int())){
        for (int i=0;i<=MAX_HEIGHT;i++) Soldiers[i]=0;
        for (int i=0;i<n;i++){
            Heads[i] = get_int();
        }
        for (int i=0;i<m;i++){
            int tmp = get_int();
            Soldiers[tmp]++; 
        }

        bool f;
        int money = 0;
        for (int i=0;i<n;i++){
            int head = Heads[i];
            f = false;
            for (int j=head;j<=MAX_HEIGHT;j++){
                if (Soldiers[j]){
                    Soldiers[j]--;
                    money += j;
                    f = true;
                    break;
                }
            }
            if (!f) break;
        }

        if (!f) cout << "Loowater is doomed!\n";
        else cout << money << '\n';


    
    }

    return 0;
}
