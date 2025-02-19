#include <stdio.h>

void print_binary(int n){
	for (int i = 3;
		 i >= 0;
		 i --){
		printf("%d",
			(n >> i)
			& 1);
	}
}

int main() {
	for (int i = 0;
		i <= 10;
		i++){
	print_binary(i);
	printf("\n");
	}
	return 0;
}

