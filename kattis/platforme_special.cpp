#include <iostream>
#include <algorithm>

using namespace std;

typedef struct table{
    int x1,x2,y;
} Table;

Table Tables[100];
int Occupied[10000];

bool compare(Table n1, Table n2){
    return n1.y < n2.y;
}

int main(){
    long long  n, result = 0;
    fill(Occupied,Occupied+10000,-1);
    cin >> n;

    for (int i=0;i<n;i++){
        cin >> Tables[i].y >> Tables[i].x1 >> Tables[i].x2;
    }

    sort(Tables,Tables+n,compare);

    for (int i=0;i<n;i++){
        int biggest[2] = {0,0};
        int taken = -1;
        Table current = Tables[i];
        for (int j=current.x1;j<=current.x2;j++){
            for (int l=0;l<2;l++){
                if (Occupied[j]!=-1&&j>current.x1&&j<current.x2&&taken!=Occupied[j]&&Tables[Occupied[j]].y>biggest[l]){
                    if (!l){
                        biggest[1] = biggest[0];
                        taken=Occupied[j];
                    } 
                    biggest[l] = Tables[Occupied[j]].y;
                }
            }
            Occupied[j] = i;
        }

        result += current.y-biggest[0];
        result += current.y-biggest[1];
    }

    cout << result << "\n";


    return 0;
}
