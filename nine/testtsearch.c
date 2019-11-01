#include <stdio.h>
#include <search.h>
#include <string.h>
#include <stdlib.h>

struct node {
        char *name;
        int m_point;
        int f_point;
};

#define TABLESIZE 50

char nametable[TABLESIZE*20];
struct node *root = NULL;

int compare(const void *cp1, const void *cp2) {
        return strcmp(((struct node *)cp1)->name, ((struct node * )cp2)->name);}

void print_node(const void *, VISIT, int);

int main() {
        char *nameptr = nametable;
        struct node **ret;
        struct node *arr;
        int max, i;

	printf("입력 받을 학생 수는? ");
	scanf("%d",&max);

        arr = (struct node *)malloc(sizeof(struct node) * max);

        if (arr == NULL){
                printf("메모리를 할당하지 못했습니다.");
                exit(-1);
        }

        for (i = 0; i < max; i++) {
                printf("학생 이름: ");
                scanf("%s", nameptr);
                printf("중간 성적: ");
                scanf("%d", &arr[i].m_point);
                printf("기말 성적: ");
                scanf("%d", &arr[i].f_point);
                arr[i].name = nameptr;
                ret = (struct node **) tsearch((void *)&arr[i], (void **) &root, compare);
                printf("\"%s\" 님이 ", (*ret)->name);
                if (*ret == &arr[i])
                        printf("트리에 추가되었습니다.\n");
                else
                        printf("트리에 이미 존재합니다.\n");
                nameptr += strlen(nameptr) + 1;
        }
        twalk((void *) root, print_node);
}

void print_node(const void *arr, VISIT order, int level) {
        if (order == preorder || order == leaf)
                printf("이름 = %-20s, 중간 성적 = %d, 기말 성적 = %d\n", (*(struct node **)arr)->name, (*(struct node **)arr)->m_point, (*(struct node **)arr)->f_point);
}

