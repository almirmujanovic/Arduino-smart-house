#include <DHT.h>
#include <Servo.h>
#include <SoftwareSerial.h>

#define DHTPIN 2
#define DHTTYPE DHT11
#define LIGHT_SENSOR A0
#define LED_PIN 9
#define VENTILATOR_PIN 3
#define SERVO_PIN 6

DHT dht(DHTPIN, DHTTYPE);
Servo windowServo;
SoftwareSerial bluetooth(10, 11); // RX, TX

float temperature;
float humidity;
int lightLevel;
boolean ventilatorState = false;
boolean lightState = false;
boolean windowState = false; // false: open, true: closed

void setup() {
    pinMode(VENTILATOR_PIN, OUTPUT);
    pinMode(LED_PIN, OUTPUT);
    dht.begin();
    windowServo.attach(SERVO_PIN);
    windowServo.write(0); // Start with window open
    bluetooth.begin(9600);
    Serial.begin(9600);
    Serial.println("Smart House System Initialized");
}

void loop() {
    // Read sensors
    temperature = dht.readTemperature();
    humidity = dht.readHumidity();
    lightLevel = analogRead(LIGHT_SENSOR);

    // Handle sensor-based logic
    handleVentilator();
    handleWindow();
    handleLights();

    // Handle Bluetooth commands
    if (bluetooth.available()) {
        char command = bluetooth.read();
        handleBluetoothCommand(command);
    }

    // Send data over Bluetooth
    sendDataToBluetooth();

    delay(1000); // Delay for sensor stability
}

void handleVentilator() {
    if (temperature > 30) { // High temperature threshold
        digitalWrite(VENTILATOR_PIN, HIGH);
        ventilatorState = true;
    } else {
        digitalWrite(VENTILATOR_PIN, LOW);
        ventilatorState = false;
    }
}

void handleWindow() {
    if (temperature < 15 || humidity > 80) { // Low temperature or high humidity
        closeWindow();
    } else {
        openWindow();
    }
}

void handleLights() {
    if (lightLevel < 500) { // Dark environment
        digitalWrite(LED_PIN, HIGH);
        lightState = true;
    } else {
        digitalWrite(LED_PIN, LOW);
        lightState = false;
    }
}

void closeWindow() {
    if (!windowState) {
        windowServo.write(90); // Close the window
        windowState = true;
    }
}

void openWindow() {
    if (windowState) {
        windowServo.write(0); // Open the window
        windowState = false;
    }
}

void handleBluetoothCommand(char command) {
    switch (command) {
        case 'L': // Toggle lights
            lightState = !lightState;
            digitalWrite(LED_PIN, lightState ? HIGH : LOW);
            break;
        case 'V': // Toggle ventilator
            ventilatorState = !ventilatorState;
            digitalWrite(VENTILATOR_PIN, ventilatorState ? HIGH : LOW);
            break;
        case 'O': // Open window
            openWindow();
            break;
        case 'C': // Close window
            closeWindow();
            break;
        case 'T': // Send temperature
            bluetooth.print("Temperature: ");
            bluetooth.println(temperature);
            break;
        case 'H': // Send humidity
            bluetooth.print("Humidity: ");
            bluetooth.println(humidity);
            break;
        default:
            bluetooth.println("Invalid Command");
            break;
    }
}

void sendDataToBluetooth() {
    bluetooth.print("Temp: ");
    bluetooth.print(temperature);
    bluetooth.print("C, Humidity: ");
    bluetooth.print(humidity);
    bluetooth.print("%, Light: ");
    bluetooth.print(lightLevel);
    bluetooth.println();
}
