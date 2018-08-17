#include <BoltIoT-Arduino-Helper.h>

int pwm_pin[] = {3,5,6,9,10,11};

String switchOn(String *data) {
  int pin = data[0].toInt();
  int pwm = data[1].toInt();
  if ((pin < 1) || (pin > 6)) {
    return "pin number should be b/w 1 and 6";
  }
  pin--;
  analogWrite(pwm_pin[pin],pwm);
  return "Pin"+String(pin)+"was set to pwm value"+String(pwm);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  boltiot.begin(Serial);
  boltiot.setCommandString("ON",switchOn,2,' ');
}

void loop() {
  // put your main code here, to run repeatedly:
  boltiot.handleCommand();
}
