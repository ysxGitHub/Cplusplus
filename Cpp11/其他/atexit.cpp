#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func_1(void) {
	printf("my is %s\n",__FUNCTION__);
}
void func_2(void) {
	printf("my is %s\n",__FUNCTION__);
}
void func_3(void) {
	printf("my is %s\n",__FUNCTION__);
}

int main(int argc,char **argv) {
	atexit(func_1);
	atexit(func_2);
	atexit(func_3);
	atexit(func_3);
	atexit(func_1);

	printf("main func end\n");

	return 0;
}
