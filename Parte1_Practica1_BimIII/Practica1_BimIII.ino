/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Dev: Sebastian Enrique Lemus Salvador
   Fecha: 4 de julio de 2024
   
   link de la simulacion: https://www.tinkercad.com/things/4snlNrY9odO-parte-i-practica-1-bim-iii 
   
*/

#include <Adafruit_NeoPixel.h>

#define PIN_Leds 2
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

Adafruit_NeoPixel neopixel = Adafruit_NeoPixel(NUMPIXELS, PIN_Leds, NEO_GRB + NEO_KHZ800);

int conteo_personas = 0;
float Medida;
float MedidaAnterior = 0;

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
  
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);

  encenderNeoPixelVerde();
}

void loop() {
  Medida = LecturaDistancia();
  Serial.println(Medida);
  delay(100);
  if (Medida >= 6 && Medida <= 10 && (MedidaAnterior < 6 || MedidaAnterior > 10)) {
    conteo_personas++;
    if (conteo_personas > 10) {
    }
    actualizarDisplay();
    Serial.println(conteo_personas);
  }
  MedidaAnterior = Medida;
}

float LecturaDistancia() {
  digitalWrite(Trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);
  float sensor = pulseIn(Echo, HIGH);
  float distancia = sensor / 59;
  return distancia;
}

void actualizarDisplay() {
  apagarDisplay();
  switch (conteo_personas) {
    case 0:
      encenderNeoPixelVerde();
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      break;
    case 1:
      encenderNeoPixelVerde();
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      break;
    case 2:
      encenderNeoPixelVerde();
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(G, HIGH);
      break;
    case 3:
      encenderNeoPixelVerde();
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(G, HIGH);
      break;
    case 4:
      encenderNeoPixelVerde();
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    case 5:
      encenderNeoPixelVerde();
      digitalWrite(A, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    case 6:
      encenderNeoPixelVerde();
      digitalWrite(A, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    case 7:
      encenderNeoPixelVerde();
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      break;
    case 8:
      encenderNeoPixelVerde();
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    case 9:
      encenderNeoPixelRojo();
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    case 10:
      encenderNeoPixelRojo();
      digitalWrite(G, HIGH);
      conteo_personas = 10;
      break;
    default:
      digitalWrite(G, HIGH);
  }
}

void encenderNeoPixelVerde() {
  for (int i = 0; i < NUMPIXELS; i++) {
    neopixel.setPixelColor(i, neopixel.Color(0, 255, 0));
  }
  neopixel.show();
}

void encenderNeoPixelRojo() {
  for (int i = 0; i < NUMPIXELS; i++) {
    neopixel.setPixelColor(i, neopixel.Color(255, 0, 0));
  }
  neopixel.show();
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
