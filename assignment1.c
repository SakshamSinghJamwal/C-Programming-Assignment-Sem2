#include<stdio.h>
#include<stdlib.h>

int min_operat(int target[], int N) {
  int operations = 0;
  for (int i=0;i<N;i++) {
  
    if (target[i]%2==0) {
      operations++; 
    } else {
      operations++;    
      int doubled_target=target[i]*2;
      if (doubled_target<(target[i]+(N-i-1))) 
      {
        operations++;  
      } else {
          operations+=(N-i-1);
      }
    }
  }
  return operations;
}

void main() {
  int N;
  printf("Enter the number of buckets: ");
  scanf("%d", &N);
  int target[N];
  printf("Enter the target number of fruits for each bucket respectively:\n");
  for (int i=0;i<N;i++) {
    scanf("%d", &target[i]);
  }
  int min_ops = min_operat(target, N);
  printf("Minimum no. of operations: %d\n", min_ops);

}