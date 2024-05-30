#include <stdio.h>
int n, a[100], used[100]={0};
void inkq(){
    for(int i = 1; i <= n; i++){
        printf("%d", a[i]);
    }
    printf("\n");
}
void Try1(int i){
    for(int j = 0; j <=1; j++){
        a[i] = j;
        if(i == n){
            inkq();
        }
        else Try1(i + 1);
    }
}
void Try2(int i){
    for(int j = 1; j <= n; j++){
        if(used[j] == 0){
            a[i] = j;
            used[j] == 1;
            if(i == n) inkq();
            else Try2(i + 1);
            used[j] = 0;
        }

    }
}
int main(){
    scanf("%d", &n);
   // Try1(1);
   //Try2(1);
   printf("%d", used[40]);
    return 0;
}