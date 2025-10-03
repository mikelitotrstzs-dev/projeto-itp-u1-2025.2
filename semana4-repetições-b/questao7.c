#include <stdio.h>
int primo(int n){
    if(n<2) return 0;
    for(int i=2;i*i<=n;i++)
        if(n%i==0) return 0;
    return 1;
}
int main(){
    int a,b;
    do scanf("%d %d",&a,&b); while(a<=b);
    for(int i=b+1;i<a;i++)
        if(primo(i)) printf("%d ",i);
    return 0;
}
