#include <stdio.h>
#include <math.h>

typedef struct node{
    double start_x;
    double start_y;
    double end_x;
    double end_y;
    double a;
    double b;
    double c;
    double time;
    double connections[];
} Node;

Node Graph[103]; // Graph[0][1] = time between node 0 (start position) and 1, [1] = end position;

double Start[2], End[2];


double get_diff(double x1, double y1, double x2, double y2){
    
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

double get_len(double x, double y, int n){
    double a, b ,c, x1, y1, l1, l2;
    Node node;

    node = Graph[n];
    
    x1 = (b*(b*x - a*y) - a*c)/(a*a+b*b);
    y1 = (a*(-b*x + a*y)-b*c)/(a*a+b*b);

    if ((a*x1 + c)/-b != y1){
        l1 = get_diff(x,y,node.start_x,node.start_y);
        l2 = get_diff(x,y,node.end_x,node.end_y);
        
        return l1<l2?l1:l2;
    }
    
    return abs(a*x+b*y+c)/sqrt(a*a+b*b);

}

double get_time_between_nodes(double *x_p, double *y_p, int n1, int n2){
    double sinus, cosinus, t, time, length, new_x, new_y, last, current;
    Node node1, node2;
    double x, y;

    x = *x_p;
    y = *y_p;

    node1 = Graph[n1];
    node2 = Graph[n2];

    t = 0;

    last = get_len(x,y,n2); 
    length = get_diff(node1.start_x,node1.start_y,node1.end_x,node1.end_y);
    cosinus = (node1.end_x-node1.start_x)/length;
    sinus = (node1.end_y-node1.start_y)/length;

    printf("first:%lf\n",last);

    while (1){
        t += 0.0001;

        new_x = x + cosinus*2*t;
        new_y = y + sinus*2*t;

        if (n2 == 1){
            current = get_diff(new_x,new_y,Graph[n2].start_x,Graph[n2].start_y)+t;
        }else{
            current = get_len(new_x,new_y,n2)+t;
        }
        
        if (current>=last){
            printf("x:%lf y:%lf parted\n",new_x-cosinus*2*0.0001,new_y-sinus*2*0.0001);
            return last; 
        }

        last = current;
    }
}


int main(){
    int n, i;

    scanf("%lf %lf %lf %lf",&Graph[0].start_x,&Graph[0].start_y,&Graph[1].start_x,&Graph[1].start_y);

    printf("%lf",get_time_between_nodes(0,0,2,3),0);   

    
    scanf("%d",&n);
    
    for (i=0;i<n;i++){
        scanf("%lf %lf %lf %lf",&Graph[i+2].start_x,&Graph[i+2].start_y,&Graph[i+2].end_x,&Graph[i+2].end_y);
            Graph[i+2].a = Graph[i+2].end_x-Graph[i+2].start_x;
            Graph[i+2].b = Graph[i+2].end_y-Graph[i+2].start_y;

            Graph[i+2].c = Graph[i+2].b;
            Graph[i+2].b = Graph[i+2].a;
            Graph[i+2].a = -Graph[i+2].c;
            
            Graph[i+2].c = -(Graph[i+2].a*Graph[i+2].end_x + Graph[i+2].b*Graph[i+2].end_y);
    }

    for (i=0;i<n+2;i++){
        
    }
    

    return 0;
}