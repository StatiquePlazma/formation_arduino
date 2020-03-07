// the lines preceded by "//" are just comments
#include <dht11.h>
#define dht_apin A0 // Analog Pin sensor is connected to
 
dht11 DHT;
 
void setup(){
  //start the serial comunication
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
 
}//end "setup()"
 
void loop(){
  //Start of Program 
 
    DHT.read(dht_apin);
    // print the data read
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
    
    delay(3000);//Wait 3 seconds before accessing sensor again.
 
  //Fastest should be once every two seconds.
 
}// end loop(
