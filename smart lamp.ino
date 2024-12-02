#include <SoftwareSerial.h>
Bluetooth
SoftwareSerial BTSerial(10, 11); // RX, TX untuk komunikasi Bluetooth
int ledPin = 13;
// Pin LED void setup() {// Memulai komunikasi serial Serial.begin(9600);
// Komunikasi serial untuk monitor
BTSerial.begin(9600); // Komunikasi dengan HC-05
pinMode(ledPin, OUTPUT); // Mengatur pin LED sebagai output
Serial.println("Smart Lamp - Menunggu perintah...");}
void loop() {// Jika ada data yang diterima dari Bluetooth
if (BTSerial.available()) {char data = BTSerial.read(); // Membaca data dari Bluetooth
// Menampilkan data yang diterima pada serial monitor
Serial.print("Perintah diterima: "); Serial.println(data);
if (data == '1') {digitalWrite(ledPin, HIGH); // Nyalakan lampu
BTSerial.println("Lampu ON"); // Mengirimkan status ke ponsel}
else if (data == '0') {digitalWrite(ledPin, LOW); // Matikan lampu
BTSerial.println("Lampu OFF"); // Mengirimkan status ke ponsel }