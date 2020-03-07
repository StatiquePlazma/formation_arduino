#include <dht11.h>
#define dht_apin A0 // Analog Pin sensor is connected to
// the lines preceded by "//" are just comments

//declare variables
int rouge = 12;
int jaune  = 11;
int vert = 10;
dht11 DHT;
float temp;
float hum;
void setup(){
  pinMode(rouge, OUTPUT); 
  pinMode(jaune, OUTPUT);
  pinMode(vert, OUTPUT);
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
  digitalWrite(rouge, LOW);
  digitalWrite(jaune, LOW);
  digitalWrite(vert, LOW);
 
}//end "setup()"
 
void loop(){
  //Start of Program 
 
    DHT.read(dht_apin);
    hum = DHT.humidity;
    temp = DHT.temperature;
    Serial.print("Current humidity = ");
    Serial.print(hum);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(temp); 
    Serial.println("C  ");
    //conditions on the temperature read ans stocked in "temp" 
    if(temp < 30){
      digitalWrite(rouge, LOW);
      digitalWrite(jaune, LOW);
      digitalWrite(vert, HIGH);
    }
    else if(temp >= 30 && temp < 40){
      digitalWrite(rouge, LOW);
      digitalWrite(jaune, HIGH);
      digitalWrite(vert, HIGH);
    }
    else{
      digitalWrite(rouge, HIGH);
      digitalWrite(jaune, HIGH);
      digitalWrite(vert, HIGH);
    }
    
    delay(5000);//Wait 5 seconds before accessing sensor again.
 
  //Fastest should be once every two seconds.
 
}// end loop(
