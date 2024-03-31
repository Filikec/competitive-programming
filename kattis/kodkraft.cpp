#include <iostream>
#include <vector>

using namespace std;


vector<int> Competitions;

typedef struct node{
    int num, pos;
    struct node *next;
} Node;


Node Nodes[1000000], *Nums[1000001];



int main(){

    int n,k;

    cin >> n >> k;
    Competitions.reserve(n);
    
    for (int i=0;i<n;i++){
        cin >> Competitions[i];

        int num = Competitions[i];
        
        Node *new_node = &Nodes[i];
        
        (*new_node) = {num,i,NULL};

        if (!Nums[num]){

        }
    }




    int curr = 1;
    
    for (int i=0;i<n;i++){

    }


    return 0;
}