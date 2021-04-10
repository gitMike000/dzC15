#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // for use boolean type

#include "geek.h"

// Task 1
const int LEN=100;

int simpleHashSum(char* in) {
 int hash = 0;
 int i=0;
 while (in[i]!='\0' && i<LEN) hash+=in[i++];
 return hash;
}

// Task 2

int* exchange(char* money, int size, int sum) {
    int sum_bag=0;
    int i=0;
    // to use the stack in practice
    OneLinkList *bag=(OneLinkList*) malloc((sizeof(OneLinkList)));
    initOneLinkList(bag);
    while ((sum_bag!=sum) && (i<= size)) {
     if ((sum_bag+money[i])<=sum) {
         if (pushOneLinkStack(bag,money[i])) {
          sum_bag+=money[i];
          continue;
         } else return NULL;
     }
     i++;
    }

    int *arr=(int*) malloc((bag->size)*sizeof (int));
    i=bag->size;
    arr[i--]=0;
    while (bag->size!=0) arr[i--]=(int) popOneLinkStack(bag);
    free(bag);
    return arr;

}

int main()
{
// Task 1
    printf("Task 1\n");
    char c[LEN];
    printf("Enter word:");
    scanf("%s",&c);
    printf("Hash sum=%d\n",simpleHashSum(c));

// Task 2
    printf("\nTask 2\n");
    char money[] = {50, 10, 5, 2, 1};
    int size = 5;
    int *bug=exchange(money,size,98);
    if (bug==NULL) return 1;
    int i=0;
    int sum=0;
    while (bug[i]!=0) {
     printf("%d ", bug[i]);
     sum+=bug[i++];
    }
    printf("\nTotal coins in the wallet: %d\n", sum);
    free(bug);
    return 0;
}
