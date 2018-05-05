/*
LARS_LOAD ASSISTANCE ROVER SYSTEM
Archit Khode
San Jose State University 2018
Controlling Motors via FS-R6b

MODIFIED By: Paul Teogalbo
*/


const int in1 = 9; // Motor 1
const int in2 = 8; // Motor 1
  
const int in3 = 11; // Motor 2
const int in4 = 10;

const int ena = 6; // Motor 1 PWM Control

const int enb = 5; // Motor 2 PWM Control

int ch1, ch3; // For RF remote inputs

bool safetoturn = false; 

void setup()
{
    Serial.begin(9600);
    pinMode(ena, OUTPUT); // Motor 1 PWM Control
    pinMode(in1, OUTPUT); // Motor 1
    pinMode(in2, OUTPUT); // Motor 1
    pinMode(enb, OUTPUT); // Motor 2 PWM Control
    pinMode(in3, OUTPUT); // Motor 2
    pinMode(in4, OUTPUT); // Motor 2
}

void loop()
{
    
// Get RF input
ch3 = int(pulseIn(A0, HIGH));
ch1 = int(pulseIn(A1, HIGH));

// Forward + Backward if block
if (1300 <= ch3 && ch3 <= 1500) {
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        safetoturn = true;
    }
    else if (ch3 <= 1200) {
        Serial.println("I go FORWARD");
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        analogWrite(ena, 50);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        analogWrite(enb, 50);
        safetoturn = false; // Don't want ch1's if block to reset the motor inputs
    }
    else if (1600 <= ch3) {
        Serial.println("I go BACK");
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        analogWrite(ena, 50);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        analogWrite(enb, 50);
        safetoturn = false; // Don't want ch1's if block to reset the motor inputs
    }

// Turning if block
  if(safetoturn){
        if (1300 <= ch1 && ch1 <= 1500) {
          digitalWrite(in1, LOW);
          digitalWrite(in2, LOW);
          digitalWrite(in3, LOW);
          digitalWrite(in4, LOW);
      }
      else if (ch1 <= 1200) {
          Serial.println("I go LEFT");
          digitalWrite(in1, HIGH);
          digitalWrite(in2, LOW);
          analogWrite(ena, 50);
          digitalWrite(in3, LOW);
          digitalWrite(in4, LOW);
      }
      else if (1700 <= ch1) {
          Serial.println("I go RIGHT");
          digitalWrite(in3, HIGH);
          digitalWrite(in4, LOW);
          analogWrite(enb, 50);
          digitalWrite(in1, LOW);
          digitalWrite(in2, LOW);
          }
  }

    delay(50);
}
