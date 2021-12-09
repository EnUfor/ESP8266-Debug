#include <GDBStub.h>

void setup() {
  Serial.begin(115200);
  gdbstub_init();
  Serial.printf("Starting...\n");
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  static uint32_t cnt = 0;
  Serial.printf("%d\n", cnt++);
  delay(100);

  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}