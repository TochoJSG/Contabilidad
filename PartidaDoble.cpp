/*		PRACTICA DE PARTIDA DOBLE; VIDEO 2
				 ->Compra-Venta de Mercancia-Bienes     */
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
using namespace std;
//Variables globales
float transferencia,bienes=2000000.0,dinero_LaEsperanza=500000.0,dinero_Maya=100000.0;//$$$ de socios, con el que iniciamos operaciones, en dif. bancos
char clientes[][23]={"LA_LIQUIDADORA,S.A.","LA_MAYORISTA,S.A.","MUEBLES_TABLITAS,S.A."};//Cliente, proveeddor,acreedor
char cuenta[30];
bool band = false;
float almacen=500000.0,venta,otroIngreso,gasto;
float j;
short i,opcion,movimiento;//movimiento=nuestra accion en la empresa
//Funciones
void empresa();
float banco_LaEsperanza(short,float);
float banco_Maya(short,float);
void bienesLaPartidaDobleSA(short,float);
void almacenLaPartidaDoble(short,float);
void diarios(short,float);
//bool valida_pago(float,float);
float valida_pago(float,float);
bool valida_cuenta(short);
void valida_saldo(float,float);
float iterador(float);
float actualiza_saldo(float,float);
int main(){//Funcion Principal
    empresa();//Somos nosotros
	system("pause"); return 0;
	}
float banco_LaEsperanza(short operacion,float transf){
	  cout<<"Bienvenido al sitio de Banco la Esperanza\n"<<endl; fflush(stdin);
	  switch(operacion){
						case 1:case 2: case 5: cout<<"Escriba el nombre del beneficiario::"; cin>>cuenta; strupr(cuenta);//Nosotros pagamos
								  	   		cout<<"Monto de transferencia::$"<<transf<<"MxN para "<<cuenta<<endl;
								  			for(i=0;i<3;i++){ if(strcmp(clientes[i],cuenta)==0) band=true; }
								  			if(band) { valida_pago(dinero_LaEsperanza,transf); cout<<"\aTransferencia exitosa"<<endl; }
                                           			 else { cout<<"\aEsa cuanta no existe"<<endl; }
							 	  break;//Opcion de compra (-Dinero en banco)(+Mercancia)
						case 3:case 4: srand(time(NULL)); i=rand()%3;
			 				      cout<<"Se recibio pago por::$"<<transf<<"MxN"<<" de "<<clientes[i][30]<<endl;
						          dinero_LaEsperanza+=transferencia;//Actualiza el dinero
							 	  break;
						default: empresa(); break;
				        }
	  }
float banco_Maya(short operacion,float transf){
      cout<<"Bienvenido a Banco Maya\n"<<endl; fflush(stdin);
	  switch(operacion){
						case 1:case 2:case 5: cout<<"Escriba el nombre del beneficiario::"; cin>>cuenta; strupr(cuenta);//Nosotros pagamos
								  cout<<"Monto de transferencia::$"<<transf<<"MxN para "<<cuenta<<endl;
								  for(i=0;i<3;i++){ if(strcmp(clientes[i],cuenta)==0) band=true; }
								  if(band) { valida_pago(dinero_Maya,transf); cout<<"\aTransferencia exitosa"<<endl; }
                                           else { cout<<"\aEsa cuanta no existe"<<endl; }
								   break;//Opcion de compra (-Dinero en banco)(+Mercancia)
						case 3:case 4: srand(time(NULL)); cout<<"Se recibio pago por::$"<<transf<<"MxN"<<" de "<<clientes[rand()%3][30]<<endl;
						          dinero_Maya+=transferencia;//Actualiza el dinero
							 	  break;
						default: empresa(); break;
				        }
	  }
float valida_pago(float capital,float transf){
	  if(capital>transf){
	  					 return capital-transf;
						   }else{
								 cout<<"\aSaldo insuficiente"<<endl;
						   		 return capital;
									}
									}
void empresa(){
	 int banco;//identifica accion a hacer,Identifica el banco a interactuar
	 cout<<"\t .:   COMERCIALIZADORA `LA PARTIDA DOBLE, S.A. DE C.V.   :.` \n\n"<<endl;
	 cout<<"     Saldo en banco La esperanza $"<<dinero_LaEsperanza<<"  /  Saldo en banco Maya $"<<dinero_Maya<<endl;
	 cout<<"De una instruccion de la operacion a realizar"<<endl;
	 cout<<"\t1.Compra de mercancia"<<endl;
	 cout<<"\t2.Compra de Mobiliario/Equipo"<<endl;
	 cout<<"\t3.Venta de mercancias"<<endl;
	 cout<<"\t4.Venta de Mobiliario/Equipo"<<endl;
	 cout<<"\t5.Pagar servicio, imprevisto o cualquier otro gasto"<<endl;
	 cout<<"Operacion elegida::"; cin>>movimiento;
	 cout<<"Para usar el banco 'La Esperanza', digite 1  /  Para el 'Banco Maya', digite 2::"; scanf("%i",&banco);
     if(banco==1){
				  switch(movimiento){
				 					 case 1: cout<<"Cuanto vamos a pagar? "; cin>>transferencia; banco_LaEsperanza(movimiento,transferencia);
									  	  	 almacenLaPartidaDoble(movimiento,transferencia); diarios(movimiento,transferencia);
											 break;
									 case 2: cout<<"Cuanto vamos a pagar? "; cin>>transferencia; banco_LaEsperanza(movimiento,transferencia);
									 	  	 bienesLaPartidaDobleSA(movimiento,transferencia); diarios(movimiento,transferencia);
											 break;
									 case 3: cout<<"Cuanto en mercancia vendimos, se cobrara con un 70% mas de utilidad "; cin>>transferencia;
									 	  	 banco_LaEsperanza(movimiento,transferencia*1.7); almacenLaPartidaDoble(movimiento,transferencia);
									 	  	 diarios(movimiento,transferencia);
											 break;
									 case 4: cout<<"Cuanto vamos a cobrar? "; cin>>transferencia; banco_LaEsperanza(movimiento,transferencia);
									 	  	 bienesLaPartidaDobleSA(movimiento,transferencia); diarios(movimiento,transferencia);
											 break;
									 case 5: cout<<"Cuanto se gasto::"; cin>>transferencia; banco_LaEsperanza(movimiento,transferencia);
									 	  	 gasto += transferencia; diarios(movimiento,transferencia);
											 break;
                                     case 6: cout<<"laEsperanza->$"<<dinero_LaEsperanza<<endl;
									 	  	 cout<<"Maya->$"<<dinero_Maya<<endl;
											 break;
									 default: system("cls"); getch(); empresa(); break;       }
          							 }else if(banco==2){
                                                switch(movimiento){
				 					 							   case 1: cout<<"Cuanto vamos a pagar? "; cin>>transferencia;
									 	  	 					   		   banco_Maya(movimiento,transferencia); almacenLaPartidaDoble(movimiento,transferencia);
											 					   		   break;
									 							   case 2: cout<<"Cuanto vamos a pagar? "; cin>>transferencia;
									 	  	 					   		   banco_Maya(movimiento,transferencia); bienesLaPartidaDobleSA(movimiento,transferencia);
											 					   		   break;
									 							   case 3: cout<<"Cuanto en mercancia vendimos, se cobrara con un 70% mas de utilidad"; cin>>transferencia;
									 	  	 					   		   banco_Maya(movimiento,transferencia*1.7); almacenLaPartidaDoble(movimiento,transferencia);
											 							   break;
							 									   case 4: cout<<"Cuanto vamos a cobrar? "; cin>>transferencia;
									 	  	 					   		   banco_Maya(movimiento,transferencia); bienesLaPartidaDobleSA(movimiento,transferencia);
											 							   break;
							 									   case 5: cout<<"Cuanto se gasto::"; cin>>transferencia; cin>>transferencia;
									 	  	 					   		   banco_Maya(movimiento,transferencia);
											 					   		   break;
							 									   default: system("cls"); getch(); empresa(); break;       }
    													   }else{
				  										   		 empresa(); }
     //diarios(transferencia,cargo);
	 }
void almacenLaPartidaDoble(short mov,float valor){//La compra de nuestra mercancia para vender o producir, si es el caso de una fabrica
	 if(mov==1){
				almacen = almacen + valor;//Almacen aumenta por el valor de la transferencia que hicimos
				 }else if(mov==2){
					   almacen = almacen - valor;
					   venta = valor*1.7;//Para saber el importe ganado por ventas al final
						}
	 }
void bienesLaPartidaDobleSA(short mov,float otroIngreso){//Nuestra empresa, muebles, maquinaria, electronicos... Toda compra para la empresa, que no sea mercancia
     if(mov==2){
	 			bienes = bienes + otroIngreso;//Aumentamos valor del patrimonio, por valor de la transferencia que hicimos
	 			 }else if(mov==4){
						bienes = bienes - otroIngreso;//Disminuimos valor del patrimonio
	 					}
     }
void diarios(short opcion,float cargo){
	 switch(opcion){
					case 1: case 2: cout<<"Cargo->"<<cargo<<endl;
						    	 	cout<<"  Iva->"<<cargo*.16<<endl;
						    		cout<<"\tAbono a Bancos->"<<cargo*1.16<<endl;
									break;
					case 3: case 4: cout<<"Cargoa Bancos->"<<cargo<<endl;
						    	 	cout<<"          Iva->"<<cargo*.16<<endl;
						    		cout<<"   \t   Abono a Bancos->"<<cargo*1.16<<endl;
					case 5: cout<<"Gastos->"<<cargo<<endl;
  	 					 	cout<<"  Iva->"<<cargo*.16<<endl;
   							cout<<"\tAbono a Bancos->"<<cargo*1.16<<endl;
							break;
					default: empresa(); break;
				    }
	 }
