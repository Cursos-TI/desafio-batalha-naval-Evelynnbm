#include <stdio.h>

int main() {
	int matriz[10][10] = {0}; // Criação da matriz
	int canCreate = 1;
	int navioErrado = 0; 

	// Posição do navio horizontal
	int linha_navio = 9, coluna_navio = 7;

	// Verifica se sai do mapa
	if (linha_navio > 9 || coluna_navio + 2 > 9) { // +2 pois posição inicial + 2 = total de 3 posições
		canCreate = 0;
		navioErrado = 1;
	}

	// Cria se possível
	if (canCreate == 1) {
		for (int i = 0; i < 3; i++) {
			matriz[linha_navio][coluna_navio + i] = 1;
		}
	}

	// Posição do navio vertical
	linha_navio = 4;
	coluna_navio = 1;

	// Verifica se sai do mapa
	if (linha_navio + 2 > 9 || coluna_navio > 9) {
		canCreate = 0;
		if (navioErrado != 0)
			navioErrado = 12; // Ambos fora do mapa
		else
			navioErrado = 2;
	}

	// Verifica sobreposição
	if (canCreate == 1) {
		for (int i = 0; i < 3; i++) {
			if (matriz[linha_navio + i][coluna_navio] != 0) {
				canCreate = 0;
				navioErrado = 3; // Código 3: sobreposição
				break;
			}
		}
	}

	// Cria se possível
	if (canCreate == 1) {
		for (int i = 0; i < 3; i++) {
			matriz[linha_navio + i][coluna_navio] = 1;
		}
	}

	// Imprime resultado
	if (canCreate == 1) {
		printf("Matriz:\n");
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				printf("%d ", matriz[i][j]);
			}
			printf("\n");
		}
	} else {
		switch (navioErrado) {
			case 1:
				printf("O navio horizontal esta fora do mapa.\n");
				break;
			case 2:
				printf("O navio vertical esta fora do mapa.\n");
				break;
			case 12:
				printf("Ambos os navios estao fora do mapa.\n");
				break;
			case 3:
				printf("O navio vertical esta sobrepondo o horizontal.\n");
				break;
			default:
				printf("Erro desconhecido.\n");
		}
	}

	return 0;
}
