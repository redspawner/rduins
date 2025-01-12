#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <OneWire.h> 
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

LiquidCrystal_I2C lcd(0x27, 16, 2);

unsigned long debounceDelay = 50;
unsigned long lastDebounceTime = 0;
unsigned long CM = 0;
unsigned long T = 0;
int Te = 0;
int cTe = 0;
int F = 0;
int lastButtonState = LOW;
int buttonState = LOW;
String message = "";

unsigned long lastUpdateLCD = 0;
unsigned long updateLCDInterval = 300;

bool updateMessage = false;

unsigned long waitStart = 0;

bool a = true; 
bool c = true;


void setup() {
  sensors.begin();
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(12, INPUT);
  // ligar todos os LED
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  //digitalWrite(12,HIGH);
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("PRESS BUTTON");
  lcd.setCursor(3,1);
  lcd.print("TO START...");
  
  do {
    delay(10);
  } while (read_debounce_button() == LOW);
  a = false;
  waitStart = millis();
  // desligar todos os LED
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
}

int read_debounce_button() {
  // read the state of the switch into a local variable:
  int reading = digitalRead(12);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;
    }
  }

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;

  return buttonState;
}


void loop() { 
  
  while (c == true){

    updateMessage = true;
    while (a == false){
      
      sensors.requestTemperatures();

      // atualizar LCD apenas em intervalos
      if ((millis() - lastUpdateLCD) > updateLCDInterval) {
        lastUpdateLCD = millis();
        if (updateMessage == true) {
          lcd.clear();
          lcd.setCursor(6,0);
          lcd.print("TEMP");
          updateMessage = false;
        }
        /*
        lcd.setCursor(0,1);
        lcd.print("                ");
        lcd.setCursor(5,1);
        lcd.print(sensors.getTempCByIndex(0));
        lcd.setCursor(10,1);
        lcd.print("C");
        */

        //char emit[16];
        //sprintf(emit, "     %.2f%s      ", sensors.getTempCByIndex(0), "C");
        lcd.setCursor(0,1);
        String s = "     " + String(sensors.getTempCByIndex(0)) + "C      ";
        lcd.print(s);
      }
      
      if (sensors.getTempCByIndex(0) > 50 && sensors.getTempCByIndex(0) < 52){
        digitalWrite(7, HIGH);
        tone(10,300);
        delay(1000);
      }
      if (sensors.getTempCByIndex(0) > 70 && sensors.getTempCByIndex(0) < 72){
        digitalWrite(6, HIGH);
        tone(10,300);
        delay(1000);  
      }
      if (sensors.getTempCByIndex(0) > 93 && sensors.getTempCByIndex(0) < 94){
        digitalWrite(5, HIGH);
        tone(10,100);
        lcd.print("READY");
        delay(5000);
      }
      if (sensors.getTempCByIndex(0) > 95){
        lcd.print("BURNING!");
        tone(10,800);
        delay(1000);
      }
      noTone(10);
      //delay(300);  

      if ((read_debounce_button() == HIGH) && ((millis() - waitStart) > 2000)) {
        a = true;
      } 
       
     } // end while

    CM = millis();
    message = "BLOOMING";
    updateMessage = true;
    lastUpdateLCD = 0;
    
    while (a == true){  
       if (T==0){
        digitalWrite(7,LOW);
        digitalWrite(6,LOW);
        digitalWrite(5,LOW);
       }
       T = millis()- CM;
       //lcd.clear();
       //lcd.setCursor(0,0);
       Te = int(T/1000);
       cTe = int(T/1000);
       F = 45 - Te;
       if (cTe == 46){
        tone(10, 1000);
        delay(1500);
        noTone(10);
        message = "POURING";
        updateMessage = true;
       }
       if (cTe == 106){
        tone(10, 2000);
        delay(1500);
        noTone(10);
        message = "DRAINING";
        updateMessage = true;
       }
       if (cTe > 46 && cTe <= 106){
        //ligar led do meio e buzzer apita
        Te = int((T/1000)-45);
        F = 60 - Te;
        digitalWrite(7,HIGH);
       }
       if (cTe > 106){
        //ligar led da direita e buzzer apita
        Te = int((T/1000)-105);
        F = 60 - Te;
        digitalWrite(6,HIGH);
       }
       if (cTe > 165){
          //começar musica final
          digitalWrite(5,HIGH);
          lcd.clear();
          lcd.setCursor(5,0);
          lcd.print("COFFEE");
          lcd.setCursor(5,1);
          lcd.print("READY!");

          for (int i = 0; i < 5; i++) {
            tone(10,500);
            delay(100);
            tone(10,600);
            delay(100);
            tone(10,500);
            delay(100);
            tone(10,750);
            delay(100);
            tone(10,400);
            delay(100);
            tone(10,300);
            delay(100);
            noTone(10);
            delay(1000);
          }
          delay(30000);
          a = false;
          c = false;
         }
         // atualizar LCD apenas em intervalos
         else if ((millis() - lastUpdateLCD) > updateLCDInterval) {
             lastUpdateLCD = millis();
             /*
             lcd.setCursor(0,1);
             lcd.print("                ");
             lcd.setCursor(6,1);
             lcd.print(F);
             lcd.setCursor(8,1);
             lcd.print("s");
            */ 
            char emit[16];
            sprintf(emit, "      %02d%s       ", F, "s");
            lcd.setCursor(0,1);
            String s = String(emit);
            lcd.print(s);
    

             if (updateMessage == true) {
               lcd.clear();
               lcd.setCursor(4,0);
               lcd.print(message); 
               updateMessage = false;
             }
          }
         
       }
 
      if (c == false){
       lcd.clear();
       lcd.setCursor(0, 1);
       lcd.print("Turn off please!");
       delay(10000);
      }
  }
 }
