/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Dev: Sebastian Enrique Lemus Salvador
   Fecha: 21 de junio de 2024
   
   link de la simulacion: 
   
*/

#include <Ultrasonic.h>
#include <Adafruit_NeoPixel.h>

#define PIN_Leds 2        // Cambiado de 3 a 2 para evitar conflicto
#define NUMPIXELS 16

#define Trigger 10
#define Echo 11

#define A 3
#define B 4
#define C 5
#define D 6
#define E 7
#define F 8
#define G 9

int conteo_personas = 0;
unsigned long tiempo_ultima_lectura = 0;
const unsigned long debounce_delay = 500;  

Adafruit_NeoPixel neopixel = Adafruit_NeoPixel(NUMPIXELS, PIN_Leds, NEO_GRB + NEO_KHZ800); // Cambiado para coincidir con NUMPIXELS
Ultrasonic ultrasonic(Trigger, Echo);

void setup() {
  Serial.begin(9600);
  neopixel.begin();
  neopixel.setBrightness(50);

  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);

  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);

  apagarDisplay();
}

void loop() {
  unsigned long current_time = millis();
  
  if (current_time - tiempo_ultima_lectura > debounce_delay) {
    int distancia = ultrasonic.Ranging(CM);
    
    if (distancia >= 6 && distancia <= 10) {
      conteo_personas++;
      if (conteo_personas > 9) {
        conteo_personas = 9; // Limitar el conteo a 9
      }
      actualizarDisplay();
      tiempo_ultima_lectura = current_time;
    }
  }
}

void actualizarDisplay() {
  apagarDisplay(); 
  switch (conteo_personas) {
    case 0:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      break;
    case 1:
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      break;
    case 2:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(G, HIGH);
      break;
    case 3:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(G, HIGH);
      break;
    case 4:
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    case 5:
      digitalWrite(A, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    case 6:
      digitalWrite(A, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    case 7:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      break;
    case 8:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    case 9:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    default:
      digitalWrite(G, HIGH);
  }
}

void apagarDisplay() {
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}
