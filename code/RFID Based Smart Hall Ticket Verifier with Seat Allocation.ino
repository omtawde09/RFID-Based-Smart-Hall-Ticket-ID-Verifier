#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>

// RFID pins
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);

// LCD pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
egregregrebfd
// ---- Student Database ----
struct Student {
  String uid;
  String name;
  int seat;
  bool accessed; // prevent duplicates
};

// Example UIDs (replace with yours)
Student students[] = {
//{"2189FD466800", "Rahul", 21, false},
  {"Card-ID", "Student-Name", Seat-No, false},
  {"Card-ID", "Student-Name", Seat-No, false},
  {"Card-ID", "Student-Name", Seat-No, false},
  {"Card-ID", "Student-Name", Seat-No, false},
  {"Card-ID", "Student-Name", Seat-No, false},
};
int studentCount = sizeof(students) / sizeof(students[0]);

// ---- Setup ----
void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  
  lcd.begin(16, 2);
  lcd.print("RFID Attendance");
  delay(2000);
  lcd.clear();
  lcd.print("Scan your Card");
}

// ---- Loop ----
void loop() {
  if (!mfrc522.PICC_IsNewCardPresent()) return;
  if (!mfrc522.PICC_ReadCardSerial()) return;

  // Get UID
  String uid = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    uid += String(mfrc522.uid.uidByte[i], HEX);
  }
  uid.toUpperCase();
  Serial.println("Scanned UID: " + uid);

  bool found = false;
  for (int i = 0; i < studentCount; i++) {
    if (uid == students[i].uid) {
      found = true;
      unsigned long currentTime = millis() / 1000; // seconds since power on
      int hours = (currentTime / 3600) % 24;
      int minutes = (currentTime / 60) % 60;
      int seconds = currentTime % 60;

      if (!students[i].accessed) {
        students[i].accessed = true;
        lcd.clear();
        lcd.print("Welcome ");
        lcd.print(students[i].name);
        lcd.setCursor(0, 1);
        lcd.print("Seat No: ");
        lcd.print(students[i].seat);

        Serial.print("Access: ");
        Serial.print(students[i].name);
        Serial.print(" | Seat ");
        Serial.print(students[i].seat);
        Serial.print(" | Time: ");
        Serial.print(hours); Serial.print(":");
        Serial.print(minutes); Serial.print(":");
        Serial.println(seconds);

      } else {
        lcd.clear();
        lcd.print("Already Scanned");

        Serial.print("Duplicate Access: ");
        Serial.print(students[i].name);
        Serial.print(" | Time: ");
        Serial.print(hours); Serial.print(":");
        Serial.print(minutes); Serial.print(":");
        Serial.println(seconds);
      }
      break;
    }
  }

  if (!found) {
    lcd.clear();
    lcd.print("Access Denied");
    Serial.println("Access Denied");
  }

  delay(2000);
  lcd.clear();
  lcd.print("Scan your Card");
}
