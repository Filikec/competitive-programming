#include <iostream>
#include <list>

using namespace std;


typedef struct node{
    int count;
    char c;
    struct node* children[26][11];
    string *p;
} Node;


Node Nodes[100  0000], Root;
int Used;


void add_word(string *s){
    list<pair<int,int>> chars;

    for (int i=0;i<26;i++){
        pair<int,int> curr = make_pair(i,0);
        for (int si=0;si<s->size();si++){
            if (s->at(si) == 'a'+i) curr.second++;
        }
        if (curr.second) chars.push_back(curr);
        
    }

    Node *current = &Root;

    while (!chars.empty()){
        pair<int,int> cur = chars.front();
        chars.pop_front();
        int index = cur.first, count = cur.second;
        if (current->children[index][count] == NULL){
            Node *new_node = &Nodes[Used++];
            
            current->children[index][count] = new_node;
            current = current->children[index][count];
            current->count = 1;
            current->c = index+'a';

        }else{
            current = current->children[index][count];
            current->count++;
        }
    }
    if (current->count==1){
        current->p = s;
    }
}

void print_tree(Node *node){
    cout << "[ ";
    for (int i=0;i<26;i++){
        for (int j=0;j<11;j++){
            if (node->children[i][j] != NULL){
                cout << (char) ('a'+i) << ' ' << j << " " << node->children[i][j]->count<<": ";
                print_tree(node->children[i][j]);
            }
        }
    }
    cout << "]";
}

typedef struct search{
    Node *node;
    int step;
    list<pair<int,int>>::iterator it;
} Search_node;

bool get_word(string *s){
    list<Search_node> queue;
    list<pair<int,int>> chars;

    for (int i=0;i<26;i++){
        pair<int,int> curr = make_pair(i,0);
        for (int si=0;si<s->size();si++){
            if (s->at(si) == 'a'+i) curr.second++;
        }
        if (curr.second) chars.push_back(curr);
    }

    Search_node ser = {&Root,0,chars.begin()};
    queue.push_back(ser);
 
    while (!queue.empty()){
        auto curr = queue.front();
        queue.pop_front();
        auto it = curr.it;
        Node *node = curr.node;
        int step = curr.step, ind = it->first, count = it->second;
        Search_node new_node;
        

        if (it == chars.end()){
            if (node->count>1) return false;
            if (node->p != s) return false;
            continue;
        }

        for (int i=step;i<ind;i++){
            for (int j=1;j<11;j++){
                if (node->children[i][j]!=NULL){
                    new_node = {node->children[i][j],step+1,it};
                    queue.push_back(new_node);
                }
            }
        }

        for (int i=count;i<11;i++){
            if (node->children[ind][i]!=NULL){

                new_node = {node->children[ind][i],step+1,next(it)};
                queue.push_back(new_node);
            }
        }
    
    }     
  
    return true;
}

string Words[15000];

int main(){
    
    ios_base::sync_with_stdio(false);
    string s;
    
    int n = 0;

    while (cin>>Words[n]){
        add_word(&Words[n]);
        cout << n <<"\n";
        n++;
    }
    cout << "ok\n";
    
    list<string> results;
    for (int i=0;i<n;i++){
        if (get_word(&Words[i])){
            results.push_back(Words[i]);
        }
    }
    results.sort();
    for (auto e : results){
        cout << e << "\n";
    }
    return 0;
}