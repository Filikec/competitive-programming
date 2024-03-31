#include <iostream>


using namespace std;


struct line{
    int a1,a2,b1,b2;

    bool isParallelTo(line &line){
        int xDif1 = a1-b1, xDif2 = line.a1-line.b1;
        int yDif1 = a2-b2, yDif2 = line.a2-line.b2;

        return (xDif1*yDif2==xDif2*yDif1);
    }

    bool isSameAs(line &line){
        int xDif1 = a1-b1, xDif2 = line.a1-line.b1;
        int yDif1 = a2-b2, yDif2 = line.a2-line.b2;
        
        return (xDif1*yDif2)
    }
};



int main(){



    return 0;
}


