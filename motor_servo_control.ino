#define IN1 4
#define IN2 3

#define IN3 5
#define IN4 6

#include <Servo.h>

Servo myservotop;
Servo myservobottom;
int pos = 0;
int i = 0;

void setup() {
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(11, OUTPUT); // LED indicator

    // Blink LED 3 times
    for (int j = 0; j < 3; j++) {
        digitalWrite(11, HIGH);
        delay(200);
        pinMode(11, INPUT);
        delay(500);
        pinMode(11, OUTPUT);
    }

    // 4th longer blink
    digitalWrite(11, HIGH);
    delay(1000);
    pinMode(11, INPUT);
    delay(200);
    
    // Attach servos and set initial positions
    myservobottom.attach(9);
    myservotop.attach(8);
    myservobottom.write(0);
    myservotop.write(15);
    delay(1000);
}

void loop() {
    delay(5000);

    // Move motor forward for a short duration
    while (i < 1200) {
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        delay(1);

        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        delay(1);
        i++;
    }

    // Move top servo to 0 degrees
    for (pos = 15; pos >= 0; pos--) {
        myservotop.write(pos);
        delay(30);
    }

    delay(2000);

    // Move bottom servo to 180 degrees
    for (pos = 0; pos <= 180; pos++) {
        myservobottom.write(pos);
        delay(30);
    }

    // Move top servo to 70 degrees
    for (pos = 0; pos <= 70; pos++) {
        myservotop.write(pos);
        delay(30);
    }

    delay(2000);

    // Move second motor forward for 1 second
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    delay(1000);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    delay(10000);

    // Move top servo back to 0 degrees
    for (pos = 70; pos >= 0; pos--) {
        myservotop.write(pos);
        delay(30);
    }

    delay(1000);

    // Move bottom servo back to 0 degrees
    for (pos = 180; pos >= 0; pos--) {
        myservobottom.write(pos);
        delay(30);
    }

    delay(2000);

    // Move second motor in reverse for a short duration
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(300);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);

    // Move top servo back to 15 degrees
    for (pos = 0; pos <= 15; pos++) {
        myservotop.write(pos);
        delay(30);
    }

    delay(10000);

    i = 0; // Reset counter
}
