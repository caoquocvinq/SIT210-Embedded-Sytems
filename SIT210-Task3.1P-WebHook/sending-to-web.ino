// This #include statement was automatically added by the Particle IDE.
#include <PietteTech_DHT.h>

#define DHTTYPE  DHT22    
#define DHTPIN   D3 


PietteTech_DHT DHT(DHTPIN, DHTTYPE);

void setup() {

    Particle.process();
    delay(1000);
    DHT.begin();
    
}

void loop() {
     //get the status.
    int status = DHT.acquireAndWait(1000);
    //get the tempuerature by Celsius.
    float temp = DHT.getCelsius();
    Particle.publish("temp", String(temp), PRIVATE);
    delay(10000);
}