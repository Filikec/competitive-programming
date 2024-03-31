#include <iostream>
#include <list>


using namespace std;


struct Node{
    int num, s, e, endedNow;
    struct Node *l, *r;
};

Node NullNode, *Null = &NullNode;


Node* createTree(int l, int r){
    Node *newNode = new Node();

    if (l > r || r < l) return Null;
    
    int mid = (l+r)/2;    

    newNode->e = newNode->s = newNode->endedNow = 0;
    newNode->l = newNode->r = Null;
    newNode->num = mid;
    
    if (l==r) return newNode;
    
    newNode->l = createTree(l, mid-1);
    newNode->r = createTree(mid+1, r);
    
    return newNode;
}


void add_start(int value, Node *start){
    if (start == Null) return;

    if (value < start->num){
        start->s++;
        add_start(value,start->l);
    }else if (value > start->num){
        add_start(value,start->r);
    }else{
        start->s++;
    }
}

void add_end(int value, Node *start){
    if (start == Null) return;

    if (value < start->num){
        start->e++;
        add_end(value,start->l);
    }else if (value > start->num){
        add_end(value,start->r);
    }else{
        start->e++;
        start->endedNow++;
    }
}

pair<int,int> getStats(int value, Node *node, pair<int, int> stats){
    if (node == Null) return stats;
    
    if (value < node->num){
        return getStats(value,node->l,stats);
    }else if (value == node->num){
        stats.first += node->s;
        stats.second += node->e-node->endedNow;
        return stats;
    }else{
        stats.first += node->s;
        stats.second += node->e;
        return getStats(value,node->r,stats);
    }
}

int main(){

    int n, k;

    NullNode = {0,0,0,0,Null,Null};

    cin >> n >> k;
    list<pair<int,int>> times;

    int maxim = 0;

    for (int i=0;i<n;i++){
        int s,e;
        cin >> s >> e;
        maxim = max(maxim,e);
        times.push_back({s,e});
    }

    Node *head = createTree(0,maxim);
    
    for (auto e : times){
        add_start(e.first,head);
        add_end(e.second,head);
    }

    k = min(k, maxim);

    int best = 0;
    for (int i=0;i+k<=maxim;i++){
        int starts = getStats(i+k, head, {0,0}).first;
        int ends = getStats(i, head, {0,0}).second;
        best = max(best, starts-ends);
    }
 
    cout << best << '\n';
    
    return 0;
}