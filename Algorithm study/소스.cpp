#include <stdio.h>

int sum(int res) {
	int a=0; 
	for (int i = 0; i <= res; i++) {
		a += i;
	}
	printf("%d", a);
	return a;
}
int main() {
	sum(10);
}