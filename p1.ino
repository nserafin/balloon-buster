/*
 * Turn a servo when a switch throws.
 *
 * The intended use was to pop a balloon when a door opened.
 *
 * Copyright 2018 Josh LeFevre
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software
 * is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <Servo.h>

#define SERVO_PIN 2
#define DOOR_PIN 3

#define POP_ANGLE 120

Servo servo;

void setup()
{
    pinMode(DOOR_PIN, INPUT);

    servo.attach(SERVO_PIN);

    servo.write(0);

    Serial.begin(9600);
}

void loop()
{
    int door_closed = !digitalRead(DOOR_PIN);

    if (door_closed) {
        delay(1000);
        servo.write(POP_ANGLE);
    }
    else {
        servo.write(0);
    }

    delay(50);
}
