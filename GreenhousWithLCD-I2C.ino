// 2018 05 01 - finally got the I2C to function properly

#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal.h>
#include <SimpleDHT.h>

int pinWaterPump = 53;

int pinDHT22 = 22;
SimpleDHT22 dht22;

LiquidCrystal_I2C lcd(0x3F,20,21);  // the address was wrong: mine is 0x3F (not 0x27 as it said in the doc)

void setup() {

    Serial.begin(115200);
    pinMode(pinWaterPump, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.print("Setting up");
  lcd.setCursor(0,1);
  lcd.print("the system");

  delay(2000);
  lcd.clear();

}

void loop() {

// Temperature & humidity loop (DHT22 sensor)
  float temperature = 0;
  float humidity = 0;
   int err = SimpleDHTErrSuccess;
  if ((err = dht22.read2(pinDHT22, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    lcd.print("Read DHT22 failed, err="); lcd.println(err);delay(2000);
    return;
  }

 lcd.clear();
 lcd.print("Air");
 delay(1000);
 lcd.setCursor(0,1); lcd.print("Temperature "); 
 delay(1000);
 lcd.clear();
 lcd.print((float)temperature); lcd.print("C, ");
 delay(2000);
 lcd.clear();
 lcd.print("Humidity ");
 delay(1000);
 lcd.setCursor(0,1); lcd.print((float)humidity); lcd.print("%");  

// DHT22 sampling rate is 0.5HZ. I have set it for a reading every 2s
  delay(2000);

// Plant soil moisture loop (LM-393 sensor)
int humidityRaw = analogRead(A0); // 1023 to 0 ===> 0 to 100%
int humidityReal = map(humidityRaw, 1023, 0, 0, 100);
lcd.clear();lcd.print("Soil humidity ");
lcd.setCursor(0,1);
delay(1000);
lcd.print(humidityReal);lcd.print("% ");
delay(2000);
if (humidityReal > 30)
{
  digitalWrite(pinWaterPump, HIGH);
}else{
  digitalWrite(pinWaterPump, LOW);
}
  
}

