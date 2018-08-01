/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>
#include "OsciladorPWM.h"
/*End of auto generated code by Atmel studio */

/* Este cartel no tiene control remoto, ni indicador "En turno". Va a tener multiples modos, que van a ir rotando cada 5 segundos (aprox). */

unsigned char modo=0;
unsigned char enturno=0;
unsigned int tiempo=0;






//Salidas
const int cruz1 = 5;	// Cruz interna (OC0B)
const int cruz2 = 6;	// Cruz externa (OC0A)
const int circ	= 3;	// Circunferencia externa (OC2B)


//Para el modo 5
osciladorPWM PWM5a = osciladorPWM(cruz1,255,0,400,0,400,1600);
osciladorPWM PWM5b = osciladorPWM(cruz2,255,800,400,0,400,800);
osciladorPWM PWM5c = osciladorPWM(circ,255,1600,400,0,400,0);

//Modo 6
osciladorPWM PWM6a = osciladorPWM(cruz1,255,0,400,200,400,800);	
osciladorPWM PWM6b = osciladorPWM(cruz2,255,400,400,200,400,400);
osciladorPWM PWM6c = osciladorPWM(circ,255,800,400,200,400,0);

//osciladorPWM PWM6a = osciladorPWM(cruz1,255,0,400,200,400,1600);	//Esta combinacion da una aleatoriedad muy copada! xD
//osciladorPWM PWM6b = osciladorPWM(cruz2,255,400,400,200,400,800);
//osciladorPWM PWM6c = osciladorPWM(circ,255,800,400,200,400,0);

//Modo 7
osciladorPWM PWM7a = osciladorPWM(cruz1,255,0,400,200,400,400);
osciladorPWM PWM7b = osciladorPWM(cruz2,255,0,400,200,400,400);
osciladorPWM PWM7c = osciladorPWM(circ,255,0,400,200,400,400);


void setup() {
	//GPIO
	pinMode(cruz1,OUTPUT);
	pinMode(cruz2,OUTPUT);
	pinMode(circ,OUTPUT);
	
	
	////Interrupciones
	//PCIFR = 0;	//Baja todas las banderas de interrupcion
	//PCICR = 0x02;	//Habilita las interrupciones por cambio desde A0 a A5
	//PCMSK1 = 0x0F;	//Habilita las interrupciones de A0:A4
	
	
	
	digitalWrite(cruz1,LOW);
	digitalWrite(cruz2,LOW);
	digitalWrite(circ,LOW);
}

void loop() {
	//while(1){
		//for(int i=0;i<10000;i++){
			//PWM7a.oscilar();
			//PWM7b.oscilar();
			//PWM7c.oscilar();
			//delay(1);
		//}	
		//while(1);
	//}
	
	
	//Modo 0
	digitalWrite(circ,HIGH);
	digitalWrite(cruz1,HIGH);
	digitalWrite(cruz2,HIGH);
	delay(5000);
	
	//Modo 1
	for(int i=0; i<5;i++){
		digitalWrite(cruz1,LOW);
		delay(200);
		digitalWrite(cruz2,LOW);
		delay(200);
		digitalWrite(circ,LOW);
		delay(200);
		digitalWrite(cruz1,HIGH);
		delay(200);
		digitalWrite(cruz2,HIGH);
		delay(200);
		digitalWrite(circ,HIGH);
		delay(200);
	}
	
	//Modo 2
	for(int i=0;i<12;i++){
		digitalWrite(cruz1,LOW);
		delay(200);
		digitalWrite(cruz1,HIGH);
		delay(200);
	}
	
	//Modo 3
	for(int i=0;i<12;i++){
		digitalWrite(cruz2,LOW);
		delay(200);
		digitalWrite(cruz2,HIGH);
		delay(200);
	}
	
	//Modo 4
	for(int i=0;i<12;i++){
		digitalWrite(cruz1,LOW);
		digitalWrite(cruz2,LOW);
		digitalWrite(circ,LOW);
		delay(500);
		digitalWrite(cruz1,HIGH);
		digitalWrite(cruz2,HIGH);
		digitalWrite(circ,HIGH);
		delay(500);
	}


	//Modo 5
	for(int i=0;i<10000;i++){
		PWM5a.oscilar();
		PWM5b.oscilar();
		PWM5c.oscilar();
		delay(1);
	}
	
	//Modo 6
	for(int i=0;i<10000;i++){
		PWM6a.oscilar();
		PWM6b.oscilar();
		PWM6c.oscilar();
		delay(1);
	}
	
	//Modo 5
	for(int i=0;i<10000;i++){
		PWM7a.oscilar();
		PWM7b.oscilar();
		PWM7c.oscilar();
		delay(1);
	}
}
