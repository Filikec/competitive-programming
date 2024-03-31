#include <bits/stdc++.h>


using namespace std;

void solve(){
    long long a,b,c,d;
    cin >> a >> b >> c >> d;

    long long most_score=-1;
    for (int i=0;i<1000000;i++){
        long long score = 0;
        long long cur_a =a ,cur_b =b,cur_c=c,cur_d=d;
        long long *least;
        
        least = &cur_a;

        if (*least > cur_b){
            least = &cur_b;
        }
        if (*least > cur_c){
            least = &cur_c;
        }

        *least += i;
        cur_d-=i;
        if (cur_a<*least){
            cur_d -= *least-cur_a;
            cur_a = *least;
        }
        if (cur_b<*least){
            cur_d -= *least-cur_b;
            cur_b = *least;
        }
        if (cur_c<*least){
            cur_d -= *least-cur_c;
            cur_c = *least;
        }
        if (cur_d < 0){
            break;
        }
        long long most = max(cur_a,max(cur_b,cur_c));

        if (most == cur_a){
            cur_a+=cur_d;
        }else if( most == cur_b){
            cur_b += cur_d;
        }else{
            cur_c += cur_d;
        }
        score = cur_a*cur_a + cur_b*cur_b + cur_c*cur_c + 7*min(cur_a,min(cur_b,cur_c));
        most_score = max(most_score,score);
    }

    cout << most_score << "\n";
}


int main(){
    int cases;

    cin >> cases;

    for (int c=0;c<cases;c++){
        solve();
    }
    return 0;
}