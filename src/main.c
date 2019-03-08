/* Somador
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void limpabuffer(char buffer[MAX]) {
	int i = 0;
	for (i = 0; i < MAX; i++) {
		buffer[i] = '\0';
	}
}

int efloat (char numero[MAX]) {
	return 1;
}

int main() {
	char c;
	int i = 0;
	char buffer[MAX];
	limpabuffer(buffer);
	
	do {
		c = getchar();
		buffer[i] = c;
		i++;
	}
	while (c != '\n');
	
	//printf("%s\n", buffer);
	
	char numero[MAX];
	limpabuffer(numero);
	int j = 0;
	i = 0;
	float soma = 0;
	
	printf("blabla");
	
	while (buffer[i] != '\n') {
		do {
			numero[j] = buffer[i];
			i++;
			j++;	
		}
		while (buffer[i] != ' ' || buffer[i] != '\n');
		//if (efloat(numero)) {
			//soma = soma + atof(numero);
		//} 
		printf("%s", numero);
		limpabuffer(numero);
		j = 0;
	}
	
	printf("Resultado= %f\n", soma);
	
	
	return 0;
}
