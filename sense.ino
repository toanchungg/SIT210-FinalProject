#include<Wire.h>
#define triggerPin D7
#define echoPin D3

const double speedOfSound = 0.0135;
double duration, distance;
int led = A5;

void setup() {
    Wire.begin(0x8);
    Wire.onReceive(receiveEvent);
    
    pinMode(led, OUTPUT);
    digitalWrite(led, LOW);
    
    pinMode(triggerPin, OUTPUT);
    pinMode(echoPin, INPUT);

}

double getDistance(){
    digitalWrite(triggerPin, HIGH); // ensure the trigger pin is clear
    delayMicroseconds(2);
    digitalWrite(triggerPin, LOW); // generate an ultrasonic sound wave
    delayMicroseconds(10);
    
    duration = pulseIn(echoPin, HIGH); // measure the duration of a pulse in microsecond
    distance = (duration / 2) * speedOfSound;
    
    return distance;
}

void receiveEvent(int data) {
    while (Wire.available()){
        char s = Wire.read();
        digitalWrite(led,s);
    }
}

void loop() {
    double data = getDistance();
    if(data < 10) {
        Particle.publish("Alert", "Door Opened", PRIVATE);
    }
    if(data > 20) {
        Particle.publish("Alert", "Safe", PRIVATE);
    }
    delay(2000);double data = getDistance();
    if(data < 10) {
        Particle.publish("Alert", "Door Opened", PRIVATE);
    }
    if(data > 20) {
        Particle.publish("Alert", "Safe", PRIVATE);
    }
    delay(2000);
}
