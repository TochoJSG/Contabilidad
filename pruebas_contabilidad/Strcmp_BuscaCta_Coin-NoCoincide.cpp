#include<string.h>
#include<stdlib.h>
#include<stdio.h>
short i;
/*struct Clientes{
	   char c1[6];//={"ara"};
	   char c2[6];//={"tocha"};
	   char c3[6];//={"puff"};
	   }c={"ara","tocha","puff"};*/
//char c[]={"Chapa"};
char arreglo[][6]={"ara","tocha","puff"};
int main(){
//	Clientes *cl = new Clientes();
//	Clientes c[4];
    char cliente[8];
	printf("Digite cuenta"); scanf("%s",cliente);
	for(i=0;i<3;i++){
					 if(strcmp(arreglo[i],cliente)==0){//Si la cuenta a que se desea depositar es cliente registrado
													   printf("\nCoincide");
															 }else{
																   printf("\nNo existe");
																	}
					 }
	system("pause"); return 0;
	}
