/* testmalloc.c */
#include <stdio.h>
#include <stdlib.h>

int main() {
        int max, i,j,m;
        int *ptr1, *ptr2, *ptrsum;

        printf("두 배열의 원소 개수는? ");
        scanf("%d",&max);

        ptr1 = (int *)malloc(max * sizeof(int));
        ptr2 = (int *)malloc(max * sizeof(int));
        ptrsum = (int *)malloc(max * sizeof(int));

        if ((ptr1 == NULL) && (ptr2 == NULL)){
                printf("메모리를 할당하지 못했습니다.");
                exit(-1);
        }

        printf("첫 번째 배열 리스트를 입력하세요.\n");
        for( i = 0; i < max; i++ )
                scanf("%d", &ptr1[i]);

        printf("두 번째 배열 리스트를 입력하세요.\n");
        for( i = 0; i < max; i++ )
                scanf("%d", &ptr2[i]);

        for( i = 0; i < max; i++ )
                ptrsum[i] = ptr1[i] + ptr2[i];

        printf("두 값을 더한 리스트:");
        for( i = 0; i < max; i++ )
                printf("%d ", *(ptrsum+i));
        printf("\n");
        free((int *)ptr1);
	free((int *)ptr2);
	free((int *)ptrsum);
}
