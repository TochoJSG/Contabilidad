/*
  INGENIERIA ECONOMICA

  */
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<iomanip>
using namespace std;
struct Elementos{
	   float presente;// P
	   float tasa_interes;//  i
	   float intereses;
	   float monto_intereses;
	   float total_con_intereses;
	   char periodo;
	   int periodos;//  n
	   float futuro;//  F
	   float serie;//  A
	   };
struct SimpleCompuesto{
	   float base;
	   float tasa_interes;//  i
	   };
Elementos situacion;
int i,j;
float tabla[3][20];
//Funciones
void compara_intereses();
float intereses(float&,float&);
void interes_simple(float&,float&,int&);
void interes_compuesto(float&,float&,int&);
int main(){
    compara_intereses();
	system("pause");	return 0;
	}
void compara_intereses(){
	 float monto_base,tasa_interes;
	 int periodos;//Los periodos deben ser un entero, pues no seran 3.3 meses o .5 quincenas
	 do{
	 	printf("\nDigita la cantidad recibida/dada::"); scanf("%f",&monto_base);
		printf("\nDigita la tasa::"); scanf("%f",&tasa_interes);
		printf("\nDigita cuantos pagos se haran (# Periodos)::"); scanf("%i",&periodos);
		}while((tasa_interes < 0) || (periodos < 0) || (monto_base < 0));//Filtro para asegurar ingreso
	 interes_simple(monto_base,tasa_interes,periodos);
	 interes_compuesto(monto_base,tasa_interes,periodos);
	 }
void interes_simple(float &base,float &in,int &periodos){
	 situacion.intereses=intereses(base,in);
	 for(i=0;i<periodos;i++){
                             situacion.monto_intereses+=situacion.intereses;//La sumatoria de los intereses de cada mes
                             situacion.total_con_intereses = base + situacion.monto_intereses;
	 						 for(j=0;j<4;j++){
										        tabla[i][0] = base;
										        tabla[i][1] = situacion.intereses;
										        tabla[i][2] = situacion.monto_intereses;//Asignamos la sumatoria de los intereses a la tabla a exponer
										        tabla[i][3] = situacion.total_con_intereses;
										 }}
     for(i=0;i<periodos;i++){
				 	 for(j=0;j<4;j++){
											 cout<<setw(15)<<tabla[i][j];
											  }cout<<endl; }
     cout<<"\n\tSe pagaran al final>>"<<situacion.total_con_intereses<<endl;
	 }
void interes_compuesto(float &base,float &in,int &periodos){
//	 situacion.presente=base;
	 situacion.total_con_intereses=base;
	 for(i=0;i<periodos;i++){
                             situacion.total_con_intereses += intereses(situacion.total_con_intereses,in);
                             situacion.intereses=intereses(situacion.total_con_intereses,in);
                             situacion.monto_intereses+=situacion.intereses;//La sumatoria de los intereses de cada mes
	 						 for(j=0;j<4;j++){
										        tabla[i][0] = base;
										        tabla[i][1] = situacion.intereses;
										        tabla[i][2] = situacion.monto_intereses;//Asignamos la sumatoria de los intereses a la tabla a exponer
										        tabla[i][3] = situacion.total_con_intereses;
										 }}
     for(i=0;i<periodos;i++){
				 	 for(j=0;j<4;j++){
											 cout<<setw(15)<<tabla[i][j];
											  }cout<<endl; }
     cout<<"\n\tSe pagaran al final>>"<<situacion.total_con_intereses<<endl;
	 }
float intereses(float &base,float &tasa){
	  float interes; interes=tasa/100;
	  return interes * base;
	  }
//void periodos{
//
//	 }
