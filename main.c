#include <stdio.h>

int main(void){
    int n;
    printf("input -->");
    scanf("%d",&n);

    for(int i=0;i<n+1;i++){
        for (int k=n-i;k!=0;k--){
            printf(" ");
        }
        for(int j=0;j<i;j++){
            printf("**");
        }
        printf("\n");
        
    }
    for(int i=0;i<n+1;i++){
        for(int j=0;j<i;j++){
            printf(" ");  
        }
        for(int k=n-i;k!=0;k--){
            printf("**");
        }
        printf("\n");
    }

   return 0; 
}