// This #include statement was automatically added by the Particle IDE.
#include <HC_SR04.h>
#include <PietteTech_DHT.h>

const int button1_PIN = D2;
const int button2_PIN = D3;
const int button3_PIN = D4;

int button1State;
int button2State;
int button3State;

#define DHTTYPE  DHT22    
#define DHTPIN   D5 
PietteTech_DHT DHT(DHTPIN, DHTTYPE);

double cm = 0.0;
const int trigPin = A4;
const int echoPin = D6;
HC_SR04 rangefinder = HC_SR04(trigPin, echoPin);

int luminance;
int photon = A3;
int volume;
int flag=0;   

void setup() {
    //DHT set-up
    delay(1000);
    DHT.begin();
    
    //photon set-up
    Particle.variable("luminance", luminance);
    Particle.variable("photon", photon);
    pinMode(luminance,INPUT);
    
    Particle.variable("volume", volume);
    pinMode(volume,INPUT);
    
    pinMode(button1_PIN, INPUT_PULLDOWN);
    pinMode(button2_PIN, INPUT_PULLDOWN);
    pinMode(button3_PIN, INPUT_PULLDOWN);
    

}

void loop() {

    button1State = digitalRead(button1_PIN); 
    button2State = digitalRead(button2_PIN); 
    button3State = digitalRead(button3_PIN); 
    
    if(button1State == 1){
            button1Function();
    }
    if(button2State == 1){
            button2Function();
    }
    if(button3State == 1){
            button3Function();
    }
    
}

void button1Function(){

    //DHT22 temp and humidity
    float temp = DHT.getCelsius();
    float humid = DHT.getHumidity();
    
    //sound sensor
    volume = analogRead(A3);
    
    //Humidity and Temperature false data remover.
    if(temp < 0){
        temp = temp + 23.5;
    }
    if(humid < 0){
        humid = humid + 33.5;
    }

    
    //Recording Data as Event:
    Particle.publish("temperature", String(temp), PRIVATE);
    Particle.publish("humidity", String(humid), PRIVATE);
    Particle.publish("volume",String(volume),PRIVATE);
    
    //IFTTT alert: 
    if(humid > 70){
        Particle.publish("alert","Danger! Humidity level reaches 70 !",  PRIVATE);
    }
    
    if(temp > 35){
        Particle.publish("alert","Danger! Temperature reaches 35 !",  PRIVATE);
    }
    if(volume > 500){
        Particle.publish("alert","Danger! Noise level reaches 500 !",  PRIVATE);
    }
    
    
    delay(3000);
}

void button2Function(){
    //DHT22 temp and humidity
    float temp = DHT.getCelsius();
    float humid = DHT.getHumidity();
    
    //Photoresistor
    luminance = analogRead(photon);
    
    //Humidity and Temperature false data remover.
    if(temp < 0){
        temp = temp + 23.5;
    }
    if(humid < 0){
        humid = humid + 33.5;
    }
 
    //Recording Data as Event:
    Particle.publish("temperature", String(temp), PRIVATE);
    Particle.publish("humidity", String(humid), PRIVATE);
    Particle.publish("luminance",String(luminance),PRIVATE);
    
    //IFTTT alert: 
    if(humid > 70){
        Particle.publish("alert","Humidity level reaches 70 !",  PRIVATE);
    }
    if(temp > 35){
        Particle.publish("alert","Luminance level reaches 5000 ! It's too bright",  PRIVATE);
    }
    if(luminance  > 5000){
        Particle.publish("alert","Luminance level reaches 5000 ! It's too bright",  PRIVATE);
    }
    if(luminance  < 40){
        Particle.publish("alert","Luminance level lower than 40 ! It's too dark",  PRIVATE);
    }
    
    delay(3000);
}

void button3Function(){
    //Distance Sensor
    cm = rangefinder.getDistanceCM();
    
    //Photoresistor
    luminance = analogRead(photon);
    
    //sound sensor
    volume = analogRead(A3);
    
    //Recording Data as Events:
    Particle.publish("cm",String(cm),PRIVATE);
    Particle.publish("volume",String(volume),PRIVATE);
    Particle.publish("luminance",String(luminance),PRIVATE);
    
    //IFTTT alert: 
    if(cm < 10 || cm > 30){
        Particle.publish("alert","Adjust your sitting position !",  PRIVATE);
    }
    if(luminance  > 4000){
        Particle.publish("alert","This place is too bright ! Find another place",  PRIVATE);
    }
    if(luminance  < 50){
        Particle.publish("alert","This place is too dark ! Find another place",  PRIVATE);
    }
    if(volume > 500){
        Particle.publish("alert","This place is too loud ! Find another place",  PRIVATE);
    }
   
    delay(3000);
}