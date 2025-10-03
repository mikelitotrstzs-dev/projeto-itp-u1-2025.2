#include <stdio.h>
int main(){
    int p1,p2,qt;
    scanf("%d %d %d",&p1,&p2,&qt);
    int melhor_i=0,melhor_j=0,menor=qt;
    for(int i=0;i<=10;i++){
        for(int j=0;j<=10;j++){
            int gasto=i*p1+j*p2;
            if(gasto<=qt && qt-gasto<menor){
                menor=qt-gasto;
                melhor_i=i;melhor_j=j;
            }
        }
    }
    printf("Resta menos comprando %d do primeiro e %d do segundo\n",melhor_i,melhor_j);
    return 0;
}
