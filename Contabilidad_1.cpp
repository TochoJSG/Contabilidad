/*		PRACTICA DE PARTIDA DOBLE; VIDEO 2
				 ->Compra-Venta de Mercancia-Bienes     */
#include<iostream>
#include<iomanip>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
using namespace std;
struct Cuentas{
	   float bancos;
	   float inventario;
	   float proveedor;
	   float cliente;
	   float patrimonio;
//	   struct EdoResultados edoResultados;
//	   struct Bancos losBancos;
	   };
struct EdoResultados{
	   struct Cuentas ctas;//Con esto desde La estructura EdoCuantas acceso a elementos de Cuentas
	   float ventas;
	   float costos;
	   float resultadoBruto;
	   float gastos;
	   float resultadoNeto;
	   };
struct Bancos{
	   float dinero_LaEsperanza;
	   float dinero_Maya;
	   float transferencia;
	   };
//Variables globales
struct EdoResultados movimientos;
struct Bancos banco;
//float transferencia,dinero_LaEsperanza=500000.0,dinero_Maya=100000.0;//bienes=2000000.0$$$ de socios, con el que iniciamos operaciones, en dif. bancos
char clientes[][23]={"ADMING","X","LA_LIQUIDADORA,S.A.","LA_MAYORISTA,S.A.","MUEBLES_TABLITAS,S.A."};//Cliente, proveedor,acreedor
char cuenta[30],ope;
bool band = false, aprobacion = false;
float j;
short i,opcion,movimiento;//movimiento=nuestra accion en la empresa
//Funciones
float banco_LaEsperanza(short,float);
float banco_Maya(short,float);

void empresa();
void bienesLaPartidaDobleSA(short,float);
void almacenLaPartidaDoble(short,float);
void diarios(short,float);
bool valida_pago(float &,float);
void edoResultados();
void fecha();

int main(){//Funcion Principal
	movimientos.ctas.inventario=500000.0; //movimientos.ctas.bancos=dinero_LaEsperanza+dinero_Maya; movimientos.ctas.patrimonio=200000.0;
 	do{
		cout<<"Digite la cantidad con la que empezaremos en banco 'La Esperanza' :: "; cin>>banco.dinero_LaEsperanza;
		cout<<"Digite la cantidad con la que empezaremos en banco 'Maya' :: "<<endl; cin>>banco.dinero_Maya;
		}while(banco.dinero_LaEsperanza<1000.0 && banco.dinero_Maya < 1000.0);
		
	do{
       fecha(); empresa(); //Somos nosotros
       cout<<"\t::Realizar otra operacion::s|n::"; cin>>ope;// toupper(ope);
       system("cls");
	   }while(ope=='S'||ope=='s');
	   edoResultados();
	system("pause"); return 0;
	}
	
void empresa(){//Funcion empresa realiza control de Cuentas y Resultados pues concierne a la empresa
	 int opc_banco; system("color 0B");
	 cout<<"\t .:   COMERCIALIZADORA `LA PARTIDA DOBLE, S.A. DE C.V.  a :.` \n\n"<<endl;
	 cout<<"      Saldo en banco La esperanza $"<<banco.dinero_LaEsperanza<<" / Saldo en banco Maya $"<<banco.dinero_Maya<<endl;
	 cout<<"De una instruccion de la operacion a realizar"<<endl;
	 cout<<"\t1.Compra de mercancia"<<endl;
	 cout<<"\t2.Compra de Mobiliario/Equipo"<<endl;
	 cout<<"\t3.Venta de mercancias"<<endl;
	 cout<<"\t4.Venta de Mobiliario/Equipo"<<endl;
	 cout<<"\t5.Pagar servicio, imprevisto o cualquier otro gasto"<<endl;
	 cout<<"Operacion elegida::"; cin>>movimiento;
	 cout<<"Para usar el banco 'La Esperanza', digite 1  /  Para el 'Banco Maya', digite 2::"; scanf("%i",&opc_banco);
	 if(opc_banco==1){
				  switch(movimiento){
				 					 case 1: system("cls"); cout<<"\n\t.:Compra de Mercancia:."<<endl;
			 	  	   				 	  	 cout<<"Cuanto vamos a pagar? "; cin>>banco.transferencia; banco_LaEsperanza(movimiento,banco.transferencia);
										     if(band){almacenLaPartidaDoble(movimiento,banco.transferencia/1.16); diarios(movimiento,banco.transferencia/1.16);}
											 break;
									 case 2: system("cls"); cout<<"\n\t.:Compra de Mobiliario/Equipo:."<<endl;
									 	  	 cout<<"Cuanto vamos a pagar? "; cin>>banco.transferencia; banco_LaEsperanza(movimiento,banco.transferencia);
											 if(band){bienesLaPartidaDobleSA(movimiento,banco.transferencia/1.16); diarios(movimiento,banco.transferencia/1.16);}
											 break;
									 case 3: system("cls"); cout<<"\n\t.:Venta de Mercancias:."<<endl;
									 	  	 cout<<"Cuanto en mercancia vendimos, se cobrara con un 70% mas de utilidad "; cin>>banco.transferencia;
									 	  	 banco_LaEsperanza(movimiento,banco.transferencia*1.7);
									 	  	 if(band){almacenLaPartidaDoble(movimiento,banco.transferencia); diarios(movimiento,banco.transferencia);}
											 break;
									 case 4: system("cls");cout<<"\n\t.:Venta de Mobiliario/Equipo:."<<endl;
									 	  	 cout<<"Cuanto vamos a cobrar? "; cin>>banco.transferencia;
									 	  	 banco_LaEsperanza(movimiento,banco.transferencia);
										     if(band){bienesLaPartidaDobleSA(movimiento,banco.transferencia); diarios(movimiento,banco.transferencia/1.16);}
											 break;
									 case 5: system("cls"); cout<<"\n\t.:Gastos / Servicios:."<<endl;
									 	  	 cout<<"Cuanto se gasto::"; cin>>banco.transferencia; banco_LaEsperanza(movimiento,banco.transferencia);
									 	  	 if(band){movimientos.gastos += banco.transferencia; diarios(movimiento,banco.transferencia);}
											 break;
                                     case 6: cout<<"LaEsperanza->$"<<banco.dinero_LaEsperanza<<endl;
									 	  	 cout<<"Maya->$"<<banco.dinero_Maya<<endl;
											 break;
									 default: system("cls"); getch(); empresa(); break;       }
          							 }else if(opc_banco==2){
                                                switch(movimiento){
				 					 							   case 1: system("cls");cout<<"\n\t.:Compra de Mercancia:."<<endl;
   		  		 	   		  		 							   		   cout<<"Cuanto vamos a pagar? "; cin>>banco.transferencia; banco_Maya(movimiento,banco.transferencia);
																	 	   if(band){almacenLaPartidaDoble(movimiento,banco.transferencia/1.16); diarios(movimiento,banco.transferencia/1.16);}
																		   break;
									 							   case 2: system("cls");cout<<"\n\t.:Compra de Mobiliario/Equipo:."<<endl;
																   		   cout<<"Cuanto vamos a pagar? "; cin>>banco.transferencia; banco_Maya(movimiento,banco.transferencia);
																		   if(band){bienesLaPartidaDobleSA(movimiento,banco.transferencia/1.16); diarios(movimiento,banco.transferencia/1.16);}
											 					   		   break;
									 							   case 3: system("cls"); cout<<"\n\t.:Venta de Mercancias:."<<endl;
																   		   cout<<"Cuanto en mercancia vendimos, se cobrara con un 70% mas de utilidad "; cin>>banco.transferencia;
																		   banco_Maya(movimiento,banco.transferencia*1.7);
																		   if(band){almacenLaPartidaDoble(movimiento,banco.transferencia); diarios(movimiento,banco.transferencia);}
																		   break;
							 									   case 4: system("cls"); cout<<"\n\t.:Venta de Mobiliario/Equipo:."<<endl;
																   		   cout<<"Cuanto vamos a cobrar? "; cin>>banco.transferencia; banco_Maya(movimiento,banco.transferencia);
																		   if(band){bienesLaPartidaDobleSA(movimiento,banco.transferencia); diarios(movimiento,banco.transferencia/1.16);}
											 							   break;
							 									   case 5: system("cls"); cout<<"\n\t.:Gastos / Servicios:."<<endl;
																   		   cout<<"Cuanto se gasto::"; cin>>banco.transferencia; banco_Maya(movimiento,banco.transferencia);
							 									           if(band){movimientos.gastos += banco.transferencia; diarios(movimiento,banco.transferencia);}
											 					   		   break;
                                                                   case 6: cout<<"laEsperanza->$"<<banco.dinero_LaEsperanza<<endl;
									 	  	 					   		   cout<<"Maya->$"<<banco.dinero_Maya<<endl;
											 							   break;
							 									   default: system("cls"); getch(); empresa(); break;       }
    													   }else{
				  										   		 empresa(); } //edoResultados();
	 movimientos.ctas.bancos=banco.dinero_LaEsperanza + banco.dinero_Maya;
	 }
void almacenLaPartidaDoble(short mov,float valor){//La compra de nuestra mercancia para vender o producir, si es el caso de una fabrica
	 if(mov==1){//Compra
				movimientos.ctas.bancos = movimientos.ctas.bancos-(valor*1.16);
				movimientos.ctas.inventario += valor;
				movimientos.costos+=valor;
				 }else if(mov==3){//Venta
					   movimientos.ctas.bancos += valor*1.7;
					   movimientos.ctas.inventario -= valor;
					   movimientos.ventas += valor*1.7;//Para saber el importe ganado por ventas al final
					   movimientos.costos += valor;
					   }
	 }
void bienesLaPartidaDobleSA(short mov,float otro){//Nuestra empresa, muebles, maquinaria, electronicos... Toda compra para la empresa, que no sea mercancia
	 if(mov==2){
	 			movimientos.ctas.patrimonio+=otro;
  	            movimientos.ctas.bancos=movimientos.ctas.bancos-(otro*1.16);}// + valor del patrimonio
				else if(mov==4){
					 			movimientos.ctas.patrimonio = movimientos.ctas.patrimonio-otro;
	   			                movimientos.ctas.bancos = movimientos.ctas.bancos+(otro*1.16); }//Disminuimos valor del patrimonio
     }
void diarios(short opcion,float cargo){
	 ofstream asiento;
	 asiento.open("Diarios.txt",ios::app);
	 switch(opcion){
					case 1: case 2: cout<<"           Cargan->"<<cargo<<endl;
						    	 	cout<<"              Iva->"<<cargo*.16<<endl;
						    	 	cout<<"          Credito->"<<endl;
						    		cout<<"Abonamos a Bancos->\t"<<cargo*1.16<<endl;
									break;
					case 3: case 4: cout<<" Cargo a Bancos->"<<cargo<<endl;
						    	 	cout<<"            Iva->"<<cargo*.16<<endl;
						    		cout<<"Abona Comprador->\t"<<cargo*1.16<<endl;
						    		if(opcion==3){
                                                  cout<<" Cargo a Costo de Ventas->"<<cargo<<endl;
						    					  cout<<"         Abona Almacen->\t"<<cargo*1.16<<endl;
												  }
						    		break;
					case 5: cout<<"        Gastos->"<<cargo<<endl;
  	 					 	cout<<"           Iva->"<<cargo*.16<<endl;
   							cout<<"Abono a Bancos->\t"<<cargo*1.16<<endl;
							break;
					default: empresa(); break;
				    }
     switch(opcion){//	Switch para registrar en  ' .txt '
					case 1: asiento<<"Almacen->"<<cargo<<endl;
						    asiento<<"    Iva->"<<cargo*.16<<endl;
						    asiento<<"Credito->"<<endl;
						    asiento<<" Bancos->\t"<<cargo*1.16<<endl;
                            break;
					case 2: asiento<<"Bienes->"<<cargo<<endl;
						    asiento<<"   Iva->"<<cargo*.16<<endl;
						    asiento<<"Credito->"<<endl;
						    asiento<<" Bancos->\t"<<cargo*1.16<<endl;
							break;
					case 3: asiento<<" Cargo a Bancos->"<<cargo<<endl;
						    asiento<<"            Iva->"<<cargo*.16<<endl;
						    asiento<<"Abona Comprador->\t"<<cargo*1.16<<endl;
                            break;
					case 4: asiento<<" Cargo a Bancos->"<<cargo<<endl;
						    asiento<<"            Iva->"<<cargo*.16<<endl;
						    asiento<<"Abona Comprador->\t"<<cargo*1.16<<endl;
						    break;
					case 5: cout<<"        Gastos->"<<cargo<<endl;
  	 					 	cout<<"           Iva->"<<cargo*.16<<endl;
   							cout<<"Abono a Bancos->\t"<<cargo*1.16<<endl;
							break;
					default: empresa(); break;
				    }
	 asiento.close();
	 }
	 
void edoResultados(){
	 movimientos.resultadoBruto = movimientos.ventas - movimientos.costos;
	 movimientos.resultadoNeto = movimientos.resultadoBruto - movimientos.gastos;
     cout<<"\n \t.:Estado de resultados al momento:."<<endl;
     cout<<"Ventas->\t"<<setw(5)<<movimientos.ventas<<endl;
     cout<<"(-)Costo de ventas->\t"<<setw(5)<<movimientos.costos<<endl;
     cout<<"(=)Perdida/Ganancia Bruta->\t"<<setw(5)<<movimientos.resultadoBruto<<endl;
     cout<<"(-)Gastos->\t"<<setw(5)<<movimientos.gastos<<endl;
     cout<<"(=)Perdida/Ganancia Neta->\t"<<setw(5)<<movimientos.resultadoNeto<<endl;
     cout<<"\nInventario="<<movimientos.ctas.inventario<<endl;
     cout<<"\nBancos="<<movimientos.ctas.bancos<<endl;
     cout<<"\nPatrimonio="<<movimientos.ctas.patrimonio<<endl<<endl;
	 }
	 
void fecha(){//Obtiene la hora de ordenador y la coloca en el programa
	time_t tiempo = time(NULL);//variables donde guardo el valor de la funcion time.
    struct tm *tlocal = localtime(&tiempo);//estructura donde obtengo el tiempo
    char output[11]; //array donde guardo la fecha
    strftime(output,11,"%d/%m/%y",tlocal); //formato para guardar la fecha obtenido en *tlocal como dd/mm/yyyy
    printf("%s\n",output);
	}
//Bancos son sistemas y entidades externos, por lo que las siguientes funciones son simples y tienen fin unico de apoyo a las anteriores
float banco_LaEsperanza(short operacion,float transf){//Debe contener funciones de un banco
	  cout<<"Bienvenido al sitio de Banco la Esperanza\n"<<endl; fflush(stdin); band = false; aprobacion = false;
	  switch(operacion){
						case 1:case 2: case 5: cout<<"Escriba el nombre del beneficiario::"; cin>>cuenta; strupr(cuenta);//Nosotros pagamos
					  	   	   cout<<"Monto de transferencia::$"<<transf<<"MxN para "<<cuenta<<endl;
					  		   for(i=0;i<3;i++){
							   					if(strcmp(clientes[i],cuenta)==0) band=true; }//for busca cuentas
					  		   if(band){//Se hayo al cliente
							   			if(valida_pago(banco.dinero_LaEsperanza,transf)){ aprobacion = true;}
										}else{ cout<<"\aEsa cuanta no existe"<<endl; }
							   if(aprobacion){ cout<<"\n\a\tSu nuevo saldo es->$"<<banco.dinero_LaEsperanza<<endl;}
							 	  break;
						case 3:case 4: srand(time(NULL)); i=rand()%3;
			 				      cout<<"Se recibio pago por::$"<<transf<<"MxN"<<" de "<<clientes[i][30]<<endl;
						          band=true; banco.dinero_LaEsperanza+=banco.transferencia;//Actualiza el dinero
							 	  break;
						default: empresa(); break;
				        }
	  }
float banco_Maya(short operacion,float transf){
      cout<<"Bienvenido a Banco Maya\n"<<endl; fflush(stdin); band = false; aprobacion = false;
	  switch(operacion){
						case 1:case 2:case 5: cout<<"Escriba el nombre del beneficiario::"; cin>>cuenta; strupr(cuenta);//Nosotros pagamos
							   cout<<"Monto de transferencia::$"<<transf<<"MxN para "<<cuenta<<endl;
							   for(i=0;i<3;i++){
							   					if(strcmp(clientes[i],cuenta)==0) band=true; }//for busca usuarios
						       if(band){
							   			if(valida_pago(banco.dinero_Maya,transf)){ aprobacion=true; }
							   			}else{ cout<<"\aEsa cuanta no existe"<<endl; }
                               if(aprobacion){cout<<"\n\a\tSu nuevo saldo es->$"<<banco.dinero_Maya<<endl;}
							   break;
						case 3:case 4: srand(time(NULL)); cout<<"Se recibio pago por::$"<<transf<<"MxN"<<" de "<<clientes[rand()%3][30]<<endl;
						       band=true; banco.dinero_Maya+=banco.transferencia;//Actualiza el dinero
							   break;
						default: empresa(); break;
				        }
	  }
bool valida_pago(float &capital,float transf){
	 if(capital>transf){cout<<"\aPago aprobado"<<endl; capital=capital-transf; return true;}
	 					else{ cout<<"\aSaldo insufieciente, se transferira lo disponible"<<endl; capital=capital-(banco.transferencia-(banco.transferencia-capital)); return false;}
  }
