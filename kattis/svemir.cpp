#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define heapcmp [&](pair<int, pair<int, int>> l, pair<int, pair<int, int>> r){return l.first > r.first;}

typedef vector<pair<int,pair<int, int>>> heap; 

struct Elem{
    long long val;
    int id;
};

vector<Elem> xV,yV,zV;
heap xH, yH, zH;
int PlanetMap[100000][3], Used[100000];

void initMap(vector<Elem> *v, int coordinate){
    for (int i=0;i<v->size();i++){
        PlanetMap[v->at(i).id][coordinate] = i;
    }
}

void addNew(int i, heap *h, vector<Elem> *v){\
    if (i+1 < v->size()){
        h->push_back({abs(v->at(i).val-v->at(i+1).val),{v->at(i).id,v->at(i+1).id}});
        push_heap(h->begin(),h->end(),heapcmp);
    }
    
    if (i){
        h->push_back({abs(v->at(i).val-v->at(i-1).val),{v->at(i).id,v->at(i-1).id}});
        push_heap(h->begin(),h->end(),heapcmp);
    }
}

bool cmp(Elem l, Elem r){
    return l.val < r.val;
}

int main(){
    int n;

    cin >> n;

    for (int i=0; i<n; i++){
        int x, y, z;
        cin >> x >> y >> z;
        xV.push_back({x,i});
        yV.push_back({y,i});
        zV.push_back({z,i});
    }

    sort(xV.begin(),xV.end(),cmp);
    sort(yV.begin(),yV.end(),cmp);
    sort(zV.begin(),zV.end(),cmp);

    initMap(&xV,0);
    initMap(&yV,1);
    initMap(&zV,2);

    int curAdd = 0;
    long long cost = 0;

    for (int i=1;i<n;i++){
        int xI, yI, zI;
        xI = PlanetMap[curAdd][0], yI = PlanetMap[curAdd][1], zI = PlanetMap[curAdd][2];
        
        addNew(xI,&xH,&xV);
        addNew(yI,&yH,&yV);
        addNew(zI,&zH,&zV);

        Used[curAdd] = 1;

        while (Used[xH.front().second.first] && Used[xH.front().second.second]){
            pop_heap(xH.begin(),xH.end(),heapcmp);
            xH.pop_back();
        }
        while (Used[yH.front().second.first] && Used[yH.front().second.second]){
            pop_heap(yH.begin(),yH.end(),heapcmp);
            yH.pop_back();
        }
        while (Used[zH.front().second.first] && Used[zH.front().second.second]){
            pop_heap(zH.begin(),zH.end(),heapcmp);
            zH.pop_back();
        }
        
        pair<int, pair<int,int>> best;

        if (xH.front().first <= yH.front().first && xH.front().first <= zH.front().first){
            best = xH.front();
            if (Used[best.second.first]) curAdd = best.second.second;
            else curAdd = best.second.first;
            cost += best.first;
        }else if (yH.front().first <= xH.front().first && yH.front().first <= zH.front().first){
            best = yH.front();
            if (Used[best.second.first]) curAdd = best.second.second;
            else curAdd = best.second.first;
            cost += best.first;
        }else{
            best = zH.front();
            if (Used[best.second.first]) curAdd = best.second.second;
            else curAdd = best.second.first;
            cost += best.first;
        }

    }


    cout << cost << '\n';
    
    return 0;
}




