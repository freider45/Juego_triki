#include <stdio.h>

int main(int argc, char *argv[]) {
	char marca,matriz[3][3];
	char jugador='A';
	int fila,columna,turnos,empate;
	printf("\tjuego Triki\n");
	printf("Elija la marca con la que va a empezar (x-o): \n");
	scanf("%c",&marca);
	turnos=0;
	empate=0;
	if(marca=='x' || marca=='o'){
		for(int x=0;x<3;x++){
			for(int y=0;y<3;y++){
				matriz[x][y]='-';
			}
		}
		for(int x=0;x<3;x++){
			printf("\n");
			for(int y=0;y<3;y++){
				printf("\t%c ",matriz[x][y]);
			}
		}
		do{
			do{
				printf("\n");
				printf("\nJugador %c\n",jugador);
				do{
					printf("Digite la fila en la que va a marcar: ");
					scanf("%d",&fila);
					if(fila<1 || fila>3){
						printf("\n");
						printf("Esta ingresando una fila incorrecta, recuerde es de (1-3)\n");
					}
				}while(fila<1 || fila>3);
				do{
					printf("Digite la columna en la que va a marcar: ");
					scanf("%d",&columna);
					if(columna<1 || columna>3){
						printf("\n");
						printf("Esta ingresando una columna incorrecta, recuerde es de (1-3)\n");
					}
				}while(columna<1 || columna>3);
				if(matriz[fila-1][columna-1]=='x' || matriz[fila-1][columna-1]=='o'){
					printf("\n");
					printf("la posicion ya esta ocupada, intente nuevamente\n");
				}
			}while(matriz[fila-1][columna-1]=='x' || matriz[fila-1][columna-1]=='o');
			matriz[fila-1][columna-1]=marca;
			for(int x=0;x<3;x++){
				printf("\n");
				for(int y=0;y<3;y++){
					printf("\t%c ",matriz[x][y]);
				}
			}
			if(matriz[fila-1][0]==matriz[fila-1][1] && matriz[fila-1][1]==matriz[fila-1][2]){
				printf("\n");
				printf("\nFin del juego\n");
				printf("\nEl ganador es el jugador %c con marca %c\n",jugador,matriz[fila-1][columna-1]);
				turnos=10;
				empate=0;
			}
			if(matriz[0][columna-1]==matriz[1][columna-1] && matriz[1][columna-1]==matriz[2][columna-1]){
				printf("\n");
				printf("\nFin del juego\n");
				printf("\nEl ganador es el jugador %c con marca %c\n",jugador,matriz[fila-1][columna-1]);
				turnos=10;
				empate=0;
			}
			if(matriz[0][0]!='-' && matriz[0][0]==matriz[1][1] && matriz[1][1]==matriz[2][2]){
				printf("\n");
				printf("\nFin del juego\n");
				printf("\nEl ganador es el jugador %c con marca %c\n",jugador,matriz[fila-1][columna-1]);
				turnos=10;
				empate=0;
			}
			if(matriz[0][2]!='-' && matriz[0][2]==matriz[1][1] && matriz[1][1]==matriz[2][0]){
				printf("\n");
				printf("\nFin del juego\n");
				printf("\nEl ganador es el jugador %c con marca %c\n",jugador,matriz[fila-1][columna-1]);
				turnos=10;
				empate=0;
			}
			if(empate==8){
				printf("\nEmpate!\n");
			}
			if(marca=='x' && jugador=='A'){
				marca = 'o';
				jugador = 'B';
			}else{
				if(marca=='o'){
					marca='x';
				}else{
					marca='o';
				}
				if(jugador=='A'){
					jugador='B';
				}else{
					jugador='A';
				}
				
			}
			turnos++;
			empate++;
		}while(turnos<9);
		printf("\n");
		
	}else {
		printf("\nEligio una marca incorrecta\n");
	}
	
	return 0;
}

