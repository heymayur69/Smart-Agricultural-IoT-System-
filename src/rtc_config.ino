// ===============================
//  RTC DS1307 Configuration Script
//  Sets RTC time based on compiler time/date
// ===============================

#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>

const char* monthName[12] = {
  "Jan", "Feb", "Mar", "Apr", "May", "Jun",
  "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

tmElements_t tm;

bool parse = false;
bool config = false;

void setup() {
  Serial.begin(9600);
  while (!Serial);              // Wait for Serial Monitor
  delay(200);

  // Get date & time from compiler and configure RTC
  if (getDate(__DATE__) && getTime(__TIME__)) {
    parse = true;
    if (RTC.write(tm)) {
      config = true;
    }
  }

  // Status Messages
  if (parse && config) {
    Serial.print("DS1307 Successfully Configured! Time=");
    Serial.print(__TIME__);
    Serial.print(", Date=");
    Serial.println(__DATE__);
  } 
  else if (parse) {
    Serial.println("DS1307 Communication Error :-{");
    Serial.println("Please check wiring (SDA, SCL, VCC, GND).");
  } 
  else {
    Serial.print("Could not parse compiler data. Time=\"");
    Serial.print(__TIME__);
    Serial.print("\", Date=\"");
    Serial.print(__DATE__);
    Serial.println("\"");
  }
}

void loop() {
  // Nothing to do here
  // Run this sketch once to set RTC time
}

// ===============================
//       Parse Time
// ===============================
bool getTime(const char* str) {
  int Hour, Min, Sec;
  if (sscanf(str, "%d:%d:%d", &Hour, &Min, &Sec) != 3) return false;

  tm.Hour = Hour;
  tm.Minute = Min;
  tm.Second = Sec;
  return true;
}

// ===============================
//       Parse Date
// ===============================
bool getDate(const char* str) {
  char Month[12];
  int Day, Year;
  uint8_t monthIndex = 0;

  if (sscanf(str, "%s %d %d", Month, &Day, &Year) != 3) return false;

  // Convert month abbreviation to index
  for (monthIndex = 0; monthIndex < 12; monthIndex++) {
    if (strcmp(Month, monthName[monthIndex]) == 0) break;
  }

  if (monthIndex >= 12) return false;

  tm.Day = Day;
  tm.Month = monthIndex + 1;
  tm.Year = CalendarYrToTm(Year);

  return true;
}
