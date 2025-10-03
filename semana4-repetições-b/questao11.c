#include <stdio.h>
#include <stdlib.h>
int main(){
    int tab[4];
    for(tab[0]=0;tab[0]<4;tab[0]++)
    for(tab[1]=0;tab[1]<4;tab[1]++)
    for(tab[2]=0;tab[2]<4;tab[2]++)
    for(tab[3]=0;tab[3]<4;tab[3]++){
        int ok=1;
        for(int i=0;i<4;i++){
            for(int j=i+1;j<4;j++){
                if(tab[i]==tab[j] || abs(tab[i]-tab[j])==j-i)
                    ok=0;
            }
        }
        if(ok){
            for(int i=0;i<4;i++) printf("(%d,%d) ",i,tab[i]);
            printf("\n");
        }
    }
    return 0;
}
