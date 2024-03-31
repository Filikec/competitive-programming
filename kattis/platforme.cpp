#include <iostream>
#include <algorithm>

using namespace std;

typedef struct table{
    int x1,x2,y;
} Table;

Table Tables[100];

bool compare(Table n1, Table n2){
    return n1.y < n2.y;
}



int main(){
    long long  n, result = 0;

    cin >> n;

    for (int i=0;i<n;i++){
        cin >> Tables[i].y >> Tables[i].x1 >> Tables[i].x2;
    }

    sort(Tables,Tables+n,compare);

    for (int i=0;i<n;i++){
        double e1 = Tables[i].x1 + 0.5;
        double e2 = Tables[i].x2 - 0.5;
        int flag = 2;
        int left = -1;
        int right = -1;
        
        for (int j=i-1;j>=0;j--){
            if (left == -1 && e1 > Tables[j].x1 && e1 < Tables[j].x2){
                flag--;
                result += Tables[i].y-Tables[j].y;
                left = j;
            }
            if (right == -1 && e2 > Tables[j].x1 && e2 < Tables[j].x2){
                flag--;
                right = j;
                result += Tables[i].y-Tables[j].y;
            }
            if (!flag){
                break;
            }
        }
        result += Tables[i].y*flag;
    }

    cout << result << "\n";


    return 0;
}
