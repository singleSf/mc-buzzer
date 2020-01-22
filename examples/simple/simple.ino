using namespace std;

#include <Arduino.h>
#include "buzzer.h"

const byte pinBuzzer = 8;

BUZZER *Buzzer = new BUZZER(pinBuzzer);

void setup() {
  Serial.begin(9600);
  
  Serial.println("question");
  Buzzer->question(1000);

  Serial.println("ok");
  Buzzer->ok(1000);
  
  Serial.println("no");
  Buzzer->no(1000);
  
  Serial.println("alarm");
  Buzzer->alarm(1000);
  
  Serial.println("done");
  Buzzer->done(1000);
  
  Serial.println("refuse");
  Buzzer->refuse(1000);
  
  Serial.println("cancel");
  Buzzer->cancel(1000);
  
  Serial.println("ping");
  Buzzer->ping(1000);
  
  Serial.println("pong");
  Buzzer->pong(1000);
  
  Serial.println("in");
  Buzzer->in(1000);

  Serial.println("out");
  Buzzer->out(1000);


  Serial.println("End");
}

void loop() {

}