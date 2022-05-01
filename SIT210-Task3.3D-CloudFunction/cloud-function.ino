int ledD4 = D4;
int ledD7 = D7;
int count;

void subscription(const char *event, const char *data);
void wave_func();
void pat_func();


void setup() {
    pinMode(ledD4, OUTPUT);
    pinMode(ledD7, OUTPUT);
    Particle.subscribe("Particle", subscription);
}

void loop() {

}

void subscription(const char *event, const char *data){
    if(strcmp(data, "wave")==0){
        wave_func();
        Particle.publish("Particle waves", "wave");
    }else if (strcmp(data, "pat")==0){
        pat_func();
        Particle.publish("Particle pats", "pat");
    }
    
}

void wave_func(){
    for(count = 0; count < 2; count++){
        digitalWrite(ledD4, HIGH);
        delay(1s);
        digitalWrite(ledD4, LOW);
        delay(1s);
    }
}

void pat_func(){
    for(count =0; count < 3; count++){
        digitalWrite(ledD7, HIGH);
        delay(1s);
        digitalWrite(ledD7, LOW);
        delay(1s);
    }
}