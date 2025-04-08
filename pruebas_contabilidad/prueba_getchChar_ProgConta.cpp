//Obtener codigo ASCII
#include<iostream>
#include<fstream>
#include<iomanip>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<math.h>
char valor;
int main(){
	valor = getchar();
	printf("%c %i\n\n", valor, valor);
	valor = toupper(valor);
	printf("%c %i\n\n",valor, valor);
	system("pause");    return 0;
	}
