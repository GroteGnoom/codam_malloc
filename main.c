#include "malloc.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>

void func() {
	char * bla = malloc(1000000000);
	bla[50] = 100;
	for (int i = 0; i < 100; i++) {
		printf("%d: %c ", i, bla[i]);
	}
	munmap(bla, 1000000000);
}

int main() {
	func();
	system("leaks test");
	char execbuffer[1000];
	sprintf(execbuffer, "vmmap --wide %u", getpid());
	//printf("execbuffer: %s\n", execbuffer);
	system(execbuffer);
}
