#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char id[10];
	printf("Digite id :");
	scanf("%s", &id );
	setbuf(stdin,NULL);
	
	printf("id: %s\n\n", id);
	printf("digite seu nome:");
	gets (id);
	
	printf("id: %s\n\n", id);
	return(0);
}
