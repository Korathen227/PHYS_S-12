// BLUETOOTH STEPPER: Connect with your phone through an app like BLE Scanner, connect with Bluetooth, and send a special command. Type "1" to open, "0" to close. 

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

// See the following for generating UUIDs:
// https://www.uuidgenerator.net/

#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"


#include <AccelStepper.h>

const int stepPin = 13;  // blue
const int dirPin = 12;   // orange

// Define a stepper and the pins it will use
AccelStepper stepper(1, stepPin, dirPin); // initialise accelstepper for a two wire board

////
String pos = "0"; // 0 for closed, 1 for open

class MyCallbacks: public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic *pCharacteristic) {
      std::string value = pCharacteristic->getValue();
      if (value.length() > 0) {
        pos = String(value[0]);
      }
    }
};


void setup() {
  Serial.begin(115200);
  BLEDevice::init("MyESP32");
  BLEServer *pServer = BLEDevice::createServer();

  BLEService *pService = pServer->createService(SERVICE_UUID);

  BLECharacteristic *pCharacteristic = pService->createCharacteristic(
                                         CHARACTERISTIC_UUID,
                                         BLECharacteristic::PROPERTY_READ |
                                         BLECharacteristic::PROPERTY_WRITE
                                       );

  pCharacteristic->setCallbacks(new MyCallbacks());

  pCharacteristic->setValue("Hello World");
  pService->start();

  BLEAdvertising *pAdvertising = pServer->getAdvertising();
  pAdvertising->start();
}

void loop()
{
  
  if (stepper.distanceToGo() == 0 and stepper.currentPosition() != 2300 and pos == "1")
  {
    // Random change to speed, position and acceleration
    // Make sure we dont get 0 speed or accelerations
    delay(1000);
    stepper.moveTo(2300);
    stepper.setSpeed(500);
    stepper.setAcceleration(500);
  } else if (stepper.distanceToGo() == 0 and pos == "0")
  {
    // Random change to speed, position and acceleration
    // Make sure we dont get 0 speed or accelerations
    stepper.moveTo(0);  
    stepper.setSpeed(500);
    stepper.setAcceleration(500);
  }
  stepper.run();
}
