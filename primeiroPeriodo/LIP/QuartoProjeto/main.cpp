#include <TimerOne.h>
#include <MultiFuncShield.h>

bool rodando = false;
bool pausado = false;
int cronometro = 0;  
unsigned long atualizado = 0;

const int tempo_maximo= 40;  

void setup() {
  Serial.begin(9600);
  Timer1.initialize();
  MFS.initialize(&Timer1);
  MFS.write(cronometro);  
}

void loop() {
  byte btn = MFS.getButton();
  if (btn) {
    byte buttonNumber = btn & B00111111;
    byte buttonAction = btn & B11000000;

    if (buttonAction == BUTTON_SHORT_RELEASE_IND) {
      switch (buttonNumber) {
        case 1: 
          rodando = true;
          pausado = false;
          cronometro = 0;
          MFS.writeLeds(LED_ALL, OFF);
          break;

        case 2:  
          if (rodando) {
            pausado = !pausado;
          }
          break;

        case 3:  
          rodando = false;
          pausado = false;
          cronometro = 0;
          MFS.writeLeds(LED_ALL, OFF);
          MFS.write(0);
          break;
      }
    }
  }

  if (rodando && !pausado) {
    unsigned long atual = millis();

    if (atual - atualizado >= 1000) {  
      atualizado = atual;
      cronometro++;
      Serial.print("Tempo: ");
      Serial.println(cronometro);
      MFS.write(cronometro);  

      if (cronometro <= 40) {
        byte leds = 0b0000;

        if (cronometro >= 10) leds = 0b0001;
        if (cronometro >= 20) leds = 0b0011;
        if (cronometro >= 30) leds = 0b0111;
        if (cronometro >= 40) leds = 0b1111;

        MFS.writeLeds(LED_ALL, OFF);  
        MFS.writeLeds(leds, ON);
      }

      if (cronometro == tempo_maximo) {
        piscarLeds(3);  
        som(5);      
        pausado = true;  
      }
    }
  }
}

void piscarLeds(int times) {
  for (int i = 0; i < times; i++) {
    MFS.writeLeds(LED_ALL, ON);
    delay(200);
    MFS.writeLeds(LED_ALL, OFF);
    delay(200);
  }
}

void som(int times) {
  for (int i = 0; i < times; i++) {
    MFS.beep();
    delay(100);
  }
}