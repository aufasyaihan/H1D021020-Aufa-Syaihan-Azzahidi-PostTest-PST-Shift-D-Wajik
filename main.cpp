// Deklarasi library
#include <Arduino.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

// Deklrasi variabel serta pin yang dipasangkan pada alat
Servo myServo;

LiquidCrystal_I2C lcd(0x27, 16, 2);
int SDA_pin = D6;
int SCL_pin = D7;

void setup()
{
    // Inisialisasi pin yang akan dipasangkan pada servo
    myServo.attach(D0);

    // inisialisasi i2c pin
    Wire.begin(SDA_pin, SCL_pin);

    // inisialisasi lcd
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
}

void loop()
{
    // Membuka Servo
    myServo.write(180);

    // Membersihkan layar lcd
    lcd.clear();

    // Mencetak teks ketika servo terbuka
    lcd.print("TERBUKA");

    // Durasi selama 5 detik
    delay(5000);

    // Menutup Servo
    myServo.write(0);

    // Membersihkan layar LCD
    lcd.clear();
    
    // Mencetak teks ketika servo ditutup
    lcd.print("TERTUTUP");

    // Durasi selama 5 detik
    delay(5000);


    // Inisialisasi I2C untuk mencari alamat yang dimana ditemukan bahwa alamat tersebut adalah 0x27
    /*
    byte error, address;
    int nDevices;
    Serial.println("Scanning...");
    nDevices = 0;
    for(address = 1; address < 127; address++ )
    {
        Wire.beginTransmission(address);
        error = Wire.endTransmission();

        if (error == 0)
        {
        Serial.print("I2C terbaca pada alamat 0x");
        if (address<16)
            Serial.print("0");
        Serial.print(address,HEX);
        Serial.println("  !");

        nDevices++;
        }
        else if (error==4)
        {
        Serial.print("Ada error yang tidak diketahui pada alamat 0x");
        if (address<16)
            Serial.print("0");
        Serial.println(address,HEX);
        }
    }
    if (nDevices == 0)
        Serial.println("Tidak ada satupun alamat I2C yang ditemukan\n");
    else
        Serial.println("selesai\n");

    delay(5000);
    */
}