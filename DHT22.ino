#include "DHT.h" // DHT library develloped by adafruit

#define DHTPIN 4     // what digital pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)

int freq =2000;

DHT dht(DHTPIN, DHTTYPE); 
/*creating an object using the classes already develloped by adafrruit that takes two parameters. 
 *first parameter is the data pin number. 
 * second parameter is the sensor type.*/


void setup() {
  Serial.begin(9600);
  Serial.println("IOTBOX Dev testing DHT22 ");

  dht.begin();
}

void loop() {
  
  delay(freq );// fdemand uence de mesure 

  Serial.print("Temperature: ");
  Serial.print(data("c"));
  Serial.print(" *C ");
  Serial.println("-----------------");
    
  Serial.print("Heat index: ");
  Serial.print(data("hic"));
  Serial.print(" *C ");
  Serial.println("-----------------");
      
  Serial.print("Humidity: ");
  Serial.print(data("h"));
  Serial.println(" % ");
  Serial.println("===========================");
}

float data(String demand )
{
  float h = dht.readHumidity(); // read humidity as %rh
  float t = dht.readTemperature(); // Read temperature as Celsius
  
  /*float f = dht.readTemperature(true);*/

  float hic = dht.computeHeatIndex(t, h, false); // Compute heat index in Celsius (isFahreheit = false)

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");  // Check if any reads failed and exit early (to try again).
    return;
  }
  if(demand  =="c"){
    return t;//return Cilsus
  }else if(demand  =="h"){
    return h;// return humidity
  }else if(demand  =="hic"){
    return hic;// return heat index in Cilsus
  }else{
    return 0.000;// if no demand est found, retun 0.000
  }
 
}
