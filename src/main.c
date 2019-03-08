/* Somador
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
#define INICIO 0
#define INTEIRO 1
#define PONTO 2
#define FLOAT 3

const int DEBUGMODE = 0;

void limpabuffer(char buffer[MAX]) {
	int i = 0;
	for (i = 0; i < MAX; i++) {
		buffer[i] = '\0';
	}
}

int edigito(char c)
{
  if ((c >= '0') && (c <= '9')) {
  	return 1;
  }
  else return 0;
}

int efloat (char numero[MAX]) {
	int maquina = INICIO;
	int caractere = 0;
	int i = 0;
	for (i = 0; numero[i] != '\0' && caractere == 0; i++) {
		switch (maquina) {
			case INICIO:
				if (edigito(numero[i])) {
					maquina = INTEIRO;
				}
				else caractere = 1;
				break;
			case INTEIRO:
				if (numero[i] == '.') {
					maquina = PONTO;
				}
				else if (!edigito(numero[i])) {
					caractere = 1;
				}
				break;
			case PONTO:
				if (edigito(numero[i])) {
					maquina = FLOAT;
				}
				else caractere = 1;
				break;
			case FLOAT:
				if (!edigito(numero[i])) {
					caractere = 1;
				}
				break;
		}
	}
	if (caractere == 1 || maquina == PONTO) {
		return 0;
	}
	else return 1;
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
		
	char numero[MAX];
	limpabuffer(numero);
	int j = 0;
	i = 0;
	float soma = 0;
	
	while (buffer[i] != '\0' && buffer[i] != '\n') {
		do {
			numero[j] = buffer[i];
			i++;
			j++;	
		}
		while (buffer[i] != ' ' && buffer[i] != '\n');
		if( DEBUGMODE >= 5) {
			printf ("%s\n", numero);
			}
		if (efloat(numero)) {
			soma = soma + atof(numero);
			if( DEBUGMODE >= 5) {
			printf("sou um numero\n");
			}
		} 
		limpabuffer(numero);
		j = 0;
		i = i + 1;
		if( DEBUGMODE >= 5) {
			printf("Estou aqui\n");
		}
	}
	
	printf("%g\n", soma);
	
	return 0;
}
