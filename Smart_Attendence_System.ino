

#include <SPI.h>

#include <MFRC522.h>

#include <LiquidCrystal.h>

#define RST_PIN 9

#define SS_PIN 10

MFRC522 mfrc522(SS_PIN, RST_PIN);

int const RedLed=6;

int const GreenLed=5;

int const Buzzer=8;

void setup() {

Serial.begin(9600);

while (!Serial);

SPI.begin();

mfrc522.PCD_Init();

delay(800);

mfrc522.PCD_DumpVersionToSerial();

Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));

pinMode(RedLed,OUTPUT);

pinMode(GreenLed,OUTPUT);

pinMode(Buzzer,OUTPUT);

}

void loop() {

if ( ! mfrc522.PICC_IsNewCardPresent()) {

return;

}

// Select one of the cards

if ( ! mfrc522.PICC_ReadCardSerial()) {

return;

}

String content= "";

byte letter;

for (byte i = 0; i < mfrc522.uid.size; i++)

{

content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));

content.concat(String(mfrc522.uid.uidByte[i], HEX));

}

Serial.println();

Serial.print("Name: ");

content.toUpperCase();

if (content.substring(1) == "56 A5 26 F9")

{

Serial.println("sonesh yadav");

Serial.print("Roll No:");

Serial.println("1904723");

Serial.print("Mobile No:");

Serial.println("9457277850");

digitalWrite(GreenLed,HIGH);

delay(800);

digitalWrite(RedLed,LOW);

digitalWrite(Buzzer,HIGH);

delay(800);

digitalWrite(Buzzer,LOW);

digitalWrite(GreenLed,LOW);

delay(800);

}

else if (content.substring(1) == "41 3D 9B 20")

{

Serial.println("Ashish kushwah");

Serial.print("Roll No:");

Serial.println("1904684");

Serial.print("Mobile No:");

Serial.println("8954242805");

digitalWrite(RedLed,HIGH);

delay(800);

digitalWrite(GreenLed,LOW);

digitalWrite(Buzzer,HIGH);

delay(800);

digitalWrite(Buzzer,LOW);

digitalWrite(RedLed,LOW);

delay(800);

}

else {

Serial.println("Invalid");

delay(800);

}

}
