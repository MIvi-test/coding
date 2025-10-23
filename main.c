#include <stdio.h> 


int* sample3(int n[]) {
	// так заработало
	*n = *n + 1;
	return n;
}

int* sample3same(int *n) {
	// аналогично sample3same
	*n = *n + 2;
	return n;
}


int main() {

	int lol[] = {122,13, 36};
	// printf("%d\n", *sample3(&lol));
	printf("%d\n", *sample3same(&(lol[0])));
}