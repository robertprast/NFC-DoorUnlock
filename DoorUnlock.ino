#include <Servo.h>
#include <PN532_HSU.h>
#include <PN532.h>
Servo servo;
PN532_HSU pn532hsu(Serial);
PN532 nfc(pn532hsu);
uint8_t MATCH[] = {69, 232, 180};
int tag;

void setup(void) {
  Serial.begin(115200);
  servo.attach(5);
  nfc.begin();
  nfc.SAMConfig();
}
void loop() {
  uint8_t success;
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };
  uint8_t uidLength;
  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength);
  

  if (success) {
    Serial.println("SUCCESS");
    servo.write(0);
    delay(1000);
    servo.write(180);
  }
}

