// This #include statement was automatically added by the Particle IDE.
#include "math.h"
#include "Adafruit_MAX6675.h"
STARTUP(WiFi.selectAntenna(ANT_EXTERNAL));

int thermoCLK = A3;
int thermoCS = A2;
int thermoDO = A4;

Adafruit_MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

void setup() {
  // open serial terminal and press ENTER to start
  Serial.begin(9600);
  while(!Serial.available()) SPARK_WLAN_Loop();

  Serial.println("MAX6675 test");
  // wait for MAX chip to stabilize
  delay(500);
}

void loop() {
  // basic readout test, just print the current temp
   


   double c = thermocouple.readCelsius();
   if (isnan(c)) {
     Serial.println("Something wrong with thermocouple!");
   } else {
     Serial.print("C = ");
     Serial.println(c);
   }
   //Serial.print("F = ");
   //Serial.println(thermocouple.readFarenheit());
    Particle.publish("HoneyTemp" , String(c, 2));
   delay(1000);
}
