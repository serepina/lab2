/* assert_test.c */
#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define my_assert(_Expression)\
 (void)\
 ((!!(_Expression)) ||\
   (printf("%s:%d:%s",__FILE__,__LINE__,#_Expression)))


void foo(int num) {
	my_assert( ((num >=0)&&(num <= 100)) );
	printf("foo: num = %d\n", num);
}

int main(int argc, char *argv[])
{
	int num;
	if(argc < 2) {
		fprintf(stderr,"Usage: assert_test aNumber\n(0 <= aNumber <= 100\n");
		exit(1);
	}
	num = atoi(argv[1]);
	foo(num);
} 

