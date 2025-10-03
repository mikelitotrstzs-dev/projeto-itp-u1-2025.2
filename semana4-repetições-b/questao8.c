#include <stdio.h>
int main(){
    int p1,p2,qt;
    scanf("%d %d %d",&p1,&p2,&qt);
    for(int i=0;i<=10;i++){
        for(int j=0;j<=10;j++){
            int gasto=i*p1+j*p2;
            if(gasto<=qt)
                printf("Comprando %d do primeiro e %d do segundo resta: %d\n",i,j,qt-gasto);
        }
    }
    return 0;
}
