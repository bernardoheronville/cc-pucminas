// C++ code


// Bibliotecas
#include <Adafruit_LiquidCrystal.h>
#include <Servo.h>

// Constantes
const int servoPin = 13;
const int buzzerPin = 12;


// Variaveis globais

// Servomotor
Servo myservo;
int pos = 0;

// Tela LCD 16x2
Adafruit_LiquidCrystal lcd(0);

// sensor humidade
int humidade = 0;
  
// sensor temperatura
int temperatura = 0;






// ------------------------ Setup ------------------------
void setup()
{
  pinMode(A0, OUTPUT); // Sensor de Humidade
  pinMode(A1, INPUT);  // Sensor de Humidade
  
  lcd.begin(16, 2);           // Display 16x2
  myservo.attach(servoPin);   // Servo Motor
  pinMode(A3, INPUT);         // Sensor de Temperatura
  pinMode(buzzerPin, OUTPUT); // Buzzer
  
  Serial.begin(9600); // Acionando monitor serial
  
  
  // Msg introdutoria
  lcd.print("Projeto LIP");
  lcd.setCursor(0,1);
  lcd.print("Estufa Auto.");
  delay(2000);
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("H: ");
  lcd.setCursor(0,1);
  lcd.print("T: ");
  
  
  Serial.begin(9600);
}








// ------------------------ LOOP ------------------------

void loop()
{
  // SENSOR DE HUMIDADE
  digitalWrite(A0, HIGH);
  delay(10);
  humidade = analogRead(A1);
  digitalWrite(A0, LOW);
  
  lcd.setCursor(2,0);
  lcd.print(humidade);
  lcd.print("ml  ");
  
  if (humidade < 200) 
  {
    myservo.write(180); // Aciona o servo-motor
    lcd.setCursor(8, 0);
    lcd.print("B: ON ");
    delay(1500);
  }
  else
  {
    myservo.write(0); // desativa o servo-motor
    lcd.setCursor(8, 0);
    lcd.print("B: OFF");
    //delay(1500);
  }
  
  // SENSOR DE TEMPERATURA
  
  // transformar a temperatura p/ celsius
  temperatura = map(((analogRead(A3) - 20) * 3.04), 0, 1023, -40, 125);
  
  // printa temperatura em uma parte específica da tela
  lcd.setCursor(2,1);
  lcd.print(temperatura);
  lcd.print("C   "); //limpar o display

  
  if((temperatura < 0)||(temperatura >50))//<- comocar var para mudar temps
  {
    lcd.setCursor(8, 1);
    lcd.print("TempCrit");
    
    
    tone(buzzerPin,1000);
    delay(1000);
    noTone(buzzerPin);
    delay(1000);
    
  }
  else
  {
    lcd.setCursor(8, 1);
    lcd.print("        "); //limpar o display
  }
  
  Serial.println(temperatura);
}