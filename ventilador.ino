//#include <SimpleDHT.h>

//#include <DHT.h>
//#include <DHT_U.h>

//#include <Wire.h>

//#include <Adafruit_AM2320.h>


#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

//#include"DHT.h"

#include <DHT.h>
 
#define DHTPIN 2//sensor
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
#define ENABLE 5//del motor
#define DIRA 3//del motor
#define DIRB 4//del motor
int buttonApin = 6;


void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);
  dht.begin();
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP); 
 
}
   

void loop(){
  while(1)
  {
 
    float h,t,i;
    float indicefinal;
    h=dht.readHumidity();
    t=dht.readTemperature();
    i=dht.computeHeatIndex(t,h,false);
    if (digitalRead(buttonApin) == LOW)
  {
     pinMode(ENABLE,LOW);
     pinMode(DIRA,LOW);
     pinMode(DIRB,LOW);
  }

    if(isnan(h)||isnan(t)){
      lcd.println("Error ");
      return;
    }
    
//    indicefinal=indice(i);
    Serial.println(t);
    temperatura(t);
    humedad(h);
    if(t>20){
     digitalWrite(ENABLE,HIGH);
     digitalWrite(DIRA,HIGH); //one way
     digitalWrite(DIRB,LOW);
    }
    else
    {
     digitalWrite(ENABLE,LOW);
     digitalWrite(DIRA,LOW); //one way
     digitalWrite(DIRB,LOW);
    }
    delay(200);
  
    
  }
  
}

float temperatura(float temp)
{
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" C");
  
  return 0;
}
float humedad(float humedad)
{
  lcd.setCursor(0,4);
  lcd.print("Humedad: ");
  lcd.print(humedad);
  lcd.print("%");
  return 0;
}
/*float indice(float i)
{
  float indice;
  lcd.setCursor(0,8);
  lcd.print("Indice de calor : ");
  lcd.print(i);
  indice=i;
  return indice;

  
}*/
