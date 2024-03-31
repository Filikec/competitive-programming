#include <bits/stdc++.h>


using namespace std;


typedef struct {
    long long x, y;
} Point;

Point Points[100000];
int N, P;

double get_product(pair<long long, long long> v1, pair<long long, long long> v2){
    return v1.first*v2.second-v1.second*v2.first;
}

bool passes(){
    long long rand_id = (1LL*rand()*rand())%N;
    long long rand_id_2 = (1LL*rand()*rand())%N;
    if (rand_id_2 == rand_id){
        rand_id_2 = (rand_id+rand())%N;
    }

    pair<long long,long long> vector1 = make_pair(Points[rand_id].x-Points[rand_id_2].x,Points[rand_id].y-Points[rand_id_2].y);
    int sum = 2;
    for (int i=0;i<N;i++){
        if (i == rand_id || i == rand_id_2) continue;

        pair<long long,long long> vector2 = make_pair(Points[rand_id].x-Points[i].x,Points[rand_id].y-Points[i].y);
        long long product = get_product(vector1,vector2);
        if (!product) sum++;
    }

    double min_points = ceil(N*(P/100.));
    return sum >= min_points;
}   

int main(){
    srand(time(NULL));
    cin >> N >> P;

    for (int i=0;i<N;i++){
        cin >> Points[i].x >> Points[i].y;
    }

    if (N==1){
        cout << "possible\n";
        return 0;
    }
    for (int i=0;i<200;i++){
        if (passes()){
            cout << "possible\n";
            return 0;
        }
    }

    cout << "impossible\n";


    return 0;
}
