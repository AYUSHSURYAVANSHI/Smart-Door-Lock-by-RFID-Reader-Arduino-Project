#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
String UID = "F1 A9 75 1B";
String UIC = "70 98 C5 21";
String UIV = "CA 3D 91 19";
String UIP = "1A F2 5C 19";
String UIA = "6A 72 4A 19";
String UIS = "CA 88 5C 1A";
byte lock = 0;

Servo servo;
LiquidCrystal_I2C lcd(0x27, 16, 2);
MFRC522 rfid(SS_PIN, RST_PIN);


void setup() {
    lcd.init();  
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("You are In");
   lcd.setCursor(0,1);
  lcd.print(" Raymond");
  delay(2000);
  lcd.clear();

lcd.setCursor(0,0);
lcd.print("WellCome To");
lcd.setCursor(0,1);
lcd.print("Server Room");
delay(2000);
lcd.clear();

lcd.setCursor(0,0);
lcd.print("MADE by:");
lcd.setCursor(0,1);
lcd.print("ABHISHEK SHAKYA");
delay(2000);
lcd.clear();
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  
  Serial.begin(9600);
  servo.write(70);
  lcd.init();
  lcd.backlight();
  servo.attach(3);
  SPI.begin();
  rfid.PCD_Init();
}

void loop() {
  lcd.setCursor(4, 0);
  lcd.print("Welcome!");
  lcd.setCursor(1, 1);
  lcd.print("Scan your card");

  if ( ! rfid.PICC_IsNewCardPresent())
    return;
  if ( ! rfid.PICC_ReadCardSerial())
    return;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Scanning");
  Serial.print("NUID tag is :");
  String ID = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    lcd.print(".");
    ID.concat(String(rfid.uid.uidByte[i] < 0x10 ? " 0" : " "));
    ID.concat(String(rfid.uid.uidByte[i], HEX));
    delay(300);
  }
  ID.toUpperCase();

  if (ID.substring(1) == UID && lock == 0 ) {

    digitalWrite(2,LOW);
    delay(1000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Door is Open");
    delay(1500);
    lcd.clear();
    lock = 1;
  } else if (ID.substring(1) == UID && lock == 1 ) {

    digitalWrite(2, HIGH);
    delay(1000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Door is Locked");
    delay(1500);
    lcd.clear();
    lock = 0;
  } 


    if (ID.substring(1) == UIS && lock == 0 ) {

    digitalWrite(2,LOW);
    delay(1000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Door is Open");
    delay(1500);
    lcd.clear();
    lock = 1;
  } else if (ID.substring(1) == UIS && lock == 1 ) {

    digitalWrite(2, HIGH);
    delay(1000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Door is Locked");
    delay(1500);
    lcd.clear();
    lock = 0;
  }


    if (ID.substring(1) == UIA && lock == 0 ) {

    digitalWrite(2,LOW);
    delay(1000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Door is Open");
    delay(1500);
    lcd.clear();
    lock = 1;
  }else if (ID.substring(1) == UIA && lock == 1 ) {

    digitalWrite(2, HIGH);
    delay(1000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Door is Locked");
    delay(1500);
    lcd.clear();
    lock = 0;
  }

    if (ID.substring(1) == UIP && lock == 0 ) {

    digitalWrite(2,LOW);
    delay(1000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Door is Open");
    delay(1500);
    lcd.clear();
    lock = 1;
  } else if (ID.substring(1) == UIP && lock == 1 ) {
    digitalWrite(2, HIGH);
    delay(1000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Door is Locked");
    delay(1500);
    lcd.clear();
    lock = 0;
  }

    if (ID.substring(1) == UIV && lock == 0 ) {

    digitalWrite(2,LOW);
    delay(1000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Door is Open");
    delay(1500);
    lcd.clear();
    lock = 1;
  } else if (ID.substring(1) == UIV && lock == 1 ) {

    digitalWrite(2, HIGH);
    delay(1000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Door is Locked");
    delay(1500);
    lcd.clear();
    lock = 0;
  }


    if (ID.substring(1) == UIC && lock == 0 ) {

    digitalWrite(2,LOW);
    delay(1000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Door is Open");
    delay(1500);
    lcd.clear();
    lock = 1;
  } else if (ID.substring(1) == UIC && lock == 1 ) {

    digitalWrite(2, HIGH);
    delay(1000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Door is Locked");
    delay(1500);
    lcd.clear();
    lock = 0;
  }
  else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Wrong card!");
    lcd.setCursor(0, 1);
    lcd.print("Access Denied");
    delay(1500);
    lcd.clear();
  }
}
