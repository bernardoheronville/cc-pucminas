#define LDR A0         
#define BOTAO 7        
#define BUZZER 12      

#define VERMELHO 4
#define AMARELO 3
#define VERDE 2
#define PED_VERMELHO 6
#define PED_VERDE 5

int pot = 0;
bool pedidoPedestre = false;

void setup() {
  pinMode(LDR, INPUT);
  pinMode(BOTAO, INPUT_PULLUP);
  pinMode(BUZZER, OUTPUT);

  pinMode(VERMELHO, OUTPUT);
  pinMode(AMARELO, OUTPUT);
  pinMode(VERDE, OUTPUT);
  pinMode(PED_VERMELHO, OUTPUT);
  pinMode(PED_VERDE, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int luz = analogRead(LDR);
  pot = analogRead(A1);
  Serial.println(luz);

  if (digitalRead(BOTAO) == HIGH) {
    pedidoPedestre = true;
  }

  if (luz < pot) {
    modoNoturno();
  } else {
    modoDia();
  }
}

void modoNoturno() {
    desligarTudo();
    digitalWrite(AMARELO, HIGH);
    delay(500);
    digitalWrite(AMARELO, LOW);
    delay(500);
}

void modoDia() {
  digitalWrite(VERDE, HIGH);
  digitalWrite(AMARELO, LOW);
  digitalWrite(VERMELHO, LOW);
  digitalWrite(PED_VERMELHO, HIGH);
  digitalWrite(PED_VERDE, LOW);
  delay(13000);

  digitalWrite(AMARELO, HIGH);
  digitalWrite(VERDE, LOW);
  delay(2000);

  digitalWrite(VERMELHO, HIGH);
  digitalWrite(AMARELO, LOW);
  digitalWrite(VERDE, LOW);
  abrirSemaforoPedestre();
  delay(8000);
  if (pedidoPedestre) {
    abrirSemaforoPedestre();
    pedidoPedestre = false;
  } else {
    digitalWrite(PED_VERMELHO, LOW);
    digitalWrite(PED_VERDE, LOW);
  }
}

void abrirSemaforoPedestre() {
  digitalWrite(PED_VERMELHO, LOW);
  digitalWrite(PED_VERDE, HIGH);
  delay(1000);
  tone(BUZZER,523,1000);

  delay(4000); 

  for (int i = 0; i < 3; i++) {
	tone(BUZZER,523,1000);
    delay(200);
    noTone(BUZZER);
    delay(200);
  }

  digitalWrite(PED_VERDE, LOW);
  digitalWrite(PED_VERMELHO, HIGH);
  delay(1000);
}

void desligarTudo() {
  digitalWrite(VERMELHO, LOW);
  digitalWrite(AMARELO, LOW);
  digitalWrite(VERDE, LOW);
  digitalWrite(PED_VERMELHO, LOW);
  digitalWrite(PED_VERDE, LOW);
  noTone(BUZZER);
}