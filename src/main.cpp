#include <Wire.h>
#include <Arduino.h>

#define BMP280_ADDRESS 0x77 // Current address of the BMP280 sensor

void setup()
{
  Wire.begin();
  Serial.begin(115200);
  delay(1000);

  // Open serial monitor to check the output
  Serial.println("Starting BMP280 address reprogramming...");
}

void loop()
{
  // Send the address programming command sequence
  Wire.beginTransmission(BMP280_ADDRESS);
  Wire.write(0xf5); // Register address of CTRL_REG1
  Wire.write(0x76); // New address to be programmed (0x76)
  Wire.endTransmission();

  delay(100); // Delay to allow the sensor to process the address change

  // Verify the address change
  Wire.beginTransmission(0x76);
  byte error = Wire.endTransmission();

  if (error == 0)
  {
    Serial.println("BMP280 address reprogrammed successfully!");
  }
  else
  {
    Serial.println("Error occurred during BMP280 address reprogramming!");
  }

  while (1)
  {
    // Stay in an infinite loop after reprogramming the address
  }
}
