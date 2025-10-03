#include <stdio.h>
int main(){
    float p,q;
    scanf("%f %f",&p,&q);
    int bestX=0,bestY=0;
    float best=0;
    for(int x=2;x<=10;x++){
        for(int y=1;y<x;y++){
            float lucro=x*p-y*q;
            if(lucro>=0){
                float razao=(float)x/y;
                if(razao>best){
                    best=razao;
                    bestX=x;bestY=y;
                }
            }
        }
    }
    printf("A melhor promocao eh: leve %d pague %d\n",bestX,bestY);
    return 0;
}
