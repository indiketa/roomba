#include <Wire.h>
#include <string.h>
#include <SD.h>
#include "RTClib.h"

#define SD_CS 9
//#define DEBUG 1
#define MIDA_BUFFER 128
#define DESVIACIO_ACTIVA 0.33
#define LED_PWM 3

RTC_DS3231 rtc;
bool disparat = false;
bool estable = false;
unsigned char buffer[MIDA_BUFFER];
unsigned char punter;
unsigned char mitjana;
unsigned char valor;
int suma;

void serial(const char *dades) {
#ifdef DEBUG
  Serial.println(dades);
#endif
}

void serial(const char *dades, int valor) {
#ifdef DEBUG
  Serial.print(dades);
  Serial.println(valor, DEC);
#endif
}


void inicialitzaMitjana() {
  memset(buffer, 0, sizeof buffer);
  punter = 0;
  estable = false;
}

char comprovaValor(int sensor) {
  valor = (char)(sensor >> 2); // El maxim és 1024, treiem 2 bits: 512, 256 -> Ja ens cap en un char.
  char disparat = 'N'; 
  serial("valor=", valor);
  suma -= buffer[punter];
  buffer[punter] = valor;  
  suma += valor;
  punter++;
  punter = punter % MIDA_BUFFER;

  if (!estable && punter == 0) { // Ja tenim el buffer ple, a partir d'ara ja s'hi val disparar-se
    estable = true;
    suma = 0;
    for (int i = 0; i < MIDA_BUFFER; i++) {
      suma = suma + buffer[i];
    }
  }

  if (estable) {
    mitjana = (suma / MIDA_BUFFER);

    if (valor >= mitjana * (1 + DESVIACIO_ACTIVA)) {
      disparat = 'C';
    } else if ( valor <= mitjana * (1 - DESVIACIO_ACTIVA)) {
      disparat = 'F';
    }

  }

  return disparat;
}

char* f00(char* dades) {
  if (strlen(dades) == 1) {  // Formata amb zero per davant (quina pijeria, tu!)
    dades[1] = dades[0]; 
    dades[0] = '0';
    dades[2] = 0;
  }
  return dades;
}

void formatar(DateTime date, char* str)
{
  char aux[5];
  itoa(date.day(), aux, 10);
  strcat(str, f00(aux));
  strcat(str, "/");
  itoa(date.month(), aux, 10);
  strcat(str, f00(aux));
  strcat(str, "/");
  itoa(date.year(), aux, 10);
  strcat(str, aux);

  strcat(str, " ");
  itoa(date.hour(), aux, 10);
  strcat(str, aux);
  strcat(str, ":");
  itoa(date.minute(), aux, 10);
  strcat(str, f00(aux));
  strcat(str, ":");
  itoa(date.second(), aux, 10);
  strcat(str, f00(aux));
  strcat(str, " MITJANA: ");
  itoa(mitjana, aux, 10);
  strcat(str, aux);
  strcat(str, " VALOR: ");
  itoa(valor,aux, 10);
  strcat(str, aux);
}

void ledFlash(){ // Fem visible que ens hem disparat.
  
 for (int voltes = 1; voltes < 6; voltes++) {
  digitalWrite(LED_PWM, HIGH);   
  delay(100);                    
  digitalWrite(LED_PWM, LOW);    
  delay(100);                      
 }
  
}

void setup() {
  
  // Led de sortida
  pinMode(LED_PWM, OUTPUT);
  digitalWrite(LED_PWM, HIGH); // L'encenem abans de fer setup i l'apaguem quan acabem així sabem si estem al bucle o al setup en cas de problemes.
  
#ifdef DEBUG
  // debug
  Serial.begin(9600);
#endif

  // rellotge
  while (!rtc.begin()) {
    serial("No trobo el rellotge");
    delay(1000);
  }

  // Si el rellotge ha perdut la corrent
  if (rtc.lostPower()) {
    // Establim la hora que s'ha compilat aquest programa
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

    // Posar-la a pel:
    // rtc.adjust(DateTime(2016, 1, 21, 3, 0, 0));
  }

  // Targeta SD
  while (!SD.begin(SD_CS)) {
    serial("SD: Problema, no targeta o fallo");
    delay(1000);
  }

  // inicialitzar buffer
  inicialitzaMitjana();

  // Indiquem que ja està a punt
  delay(500); // Que tinguem temps de veure que passa pel setup
  digitalWrite(LED_PWM, LOW);
}

void loop() {
  int lecturaSensor = analogRead(A0);

  char disparat = comprovaValor(lecturaSensor);
  bool gravar = false;
  char desc[7];

  desc[0] = 0;

  if (disparat == 'C') {
    strcat(desc, " CLAR");
    gravar = true;
  } else if (disparat == 'F') {
    strcat(desc, " FOSC");
    gravar = true;
  }

  if (gravar) {
    inicialitzaMitjana();
    char cadena[64];
    cadena[0] = 0;
    formatar(rtc.now(), cadena);
    strcat(cadena, desc);
    serial(cadena);
    File fitxer = SD.open("log.txt", FILE_WRITE);
    if (fitxer) {
      fitxer.println(cadena);
      fitxer.close();
    }
    ledFlash();
  }

  delay(100);
}
