/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Dev: Sebastian Enrique Lemus Salvador
   Fecha: 11 de julio de 2024  
    
*/

#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// pantalla lcd con I2C
#define direccion_lcd 0x27
#define filas 2
#define columnas 16

bool estadoSensorHall;

bool estadoSensorObstaculos;

int paso [8][4] =
{
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};

LiquidCrystal_I2C lcdSebasLem(direccion_lcd, columnas, filas);

int contador_revoluciones = 0;

unsigned int velocidad_adc;

unsigned char velocidad;

void setup()
{ 
  lcdSebasLem.init();
  lcdSebasLem.backlight();
  lcdSebasLem.setCursor(0, 0);
  lcdSebasLem.print("Contador de rev.");
  lcdSebasLem.setCursor(0, 1);
  lcdSebasLem.print("No. de Rev: 0");
  
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  
  pinMode(A3, INPUT);
          
  pinMode(2, INPUT);
  
  pinMode(3, INPUT);
}

void loop() {
  estadoSensorObstaculos = digitalRead(3);

  if(estadoSensorObstaculos == LOW){
    medicion_adc();
    for (int i = 0; i < 8; i++)
    {
      digitalWrite(6, paso[i][0]);
      digitalWrite(7, paso[i][1]);
      digitalWrite(8, paso[i][2]);
      digitalWrite(9, paso[i][3]);
      delay(velocidad);
    }

    estadoSensorHall = digitalRead(2);
    
    if(estadoSensorHall == LOW){
      medicion_rev_lcd();
      delay(1000);
    }
  }
}

void medicion_adc(){
  velocidad_adc = analogRead(A3);    
  velocidad = map(velocidad_adc,0,1023,0,10);
}

int medicion_rev_lcd(){
  contador_revoluciones = contador_revoluciones+1;
  lcdSebasLem.clear();
  lcdSebasLem.setCursor(0, 0);
  lcdSebasLem.print("Contador de rev.");
  lcdSebasLem.setCursor(0, 1);
  lcdSebasLem.print("No. de rev: ");
  lcdSebasLem.setCursor(13, 1);
  lcdSebasLem.print(contador_revoluciones);
}
