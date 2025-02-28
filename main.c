#include <stdio.h>

int main(void){
    int n;
    printf("input -->");
    scanf("%d",&n);

    for(int i=0;i<n+1;i++){
        for(int j=0;j<i;j++){

            if(j==0){
                for (int k=n-i;k!=0;k--){
                    printf(" ");
                }
            }

            printf("**");
        }
        if(i!=n){
            printf("\n");
        }
    }
    for(int i=0;i<n+1;i++){
      for(int j=0;j<i;j++){
        printf(" ");
        if(j==i-1){
            for(int k=n-i;k!=0;k--){
                printf("**");
            }
        }
      }
      printf("\n");
    }

    
}