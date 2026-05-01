#include <IRremote.h> // For the IR Receiver (v4+)
#include <Servo.h>    // For the Servo Motor

// --- Define Our Component Pins ---
const int IR_RECEIVER_PIN = 11;
const int SERVO_PIN = 9;
const int RED_LED_PIN = 7;
const int GREEN_LED_PIN = 8;

// --- Define Our Servo Positions ---
const int DOOR_CLOSED_POS = 0;
const int DOOR_OPEN_POS = 90;

// --- Create our objects ---
Servo myServo; 
// No IRrecv object needed for v4

// --- State Variable ---
bool isDoorOpen = false;

// ==========================================================
//  SETUP: Runs once when the Arduino first boots up
// ==========================================================
void setup() {
  Serial.begin(9600);
  Serial.println("IR Receiver ready (v4). Point your remote and press a button.");

  myServo.attach(SERVO_PIN);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);

  // Start the IR receiver (NEW v4+ SYNTAX)
  IrReceiver.begin(IR_RECEIVER_PIN, ENABLE_LED_FEEDBACK); // Start receiver

  // Set the initial "closed" state
  closeDoor();
}

// ==========================================================
//  LOOP: Runs over and over forever
// ==========================================================
void loop() {

  // Check if we have received an IR signal (NEW v4+ SYNTAX)
  if (IrReceiver.decode()) {

    // --- THIS IS STEP 1: FIND YOUR CODE ---
    // Print the received code to the Serial Monitor in HEX format
    // We now use 'IrReceiver.decodedIRData.decodedRawData'
    Serial.print("Received IR Code: ");
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);

    // Filter out "repeat" signals (when you hold the button)
    if (IrReceiver.decodedIRData.decodedRawData != 0) {

      // --- THIS IS STEP 2: MAKE IT WORK ---
      // Change 'YOUR_REMOTE_CODE' to the value you see in the Serial Monitor
      // e.g., if you see "FF629D", change it to '0xFF629D'
      
      // Use 'IrReceiver.decodedIRData.decodedRawData' instead of 'results.value'
      if (IrReceiver.decodedIRData.decodedRawData == 0xE916FF00) { // <--!! REPLACE THIS !!
        
        if (isDoorOpen == false) {
          openDoor();
        } else {
          closeDoor();
        }
        
      } // End of button check
    }

    // Tell the receiver to get ready for the next signal (NEW v4+ SYNTAX)
    IrReceiver.resume();
  }
}

// ==========================================================
//  Helper Functions (These are unchanged)
// ==========================================================

void openDoor() {
  Serial.println("Command received: OPENING DOOR");
  digitalWrite(GREEN_LED_PIN, HIGH);
  digitalWrite(RED_LED_PIN, LOW);
  myServo.write(DOOR_OPEN_POS);
  isDoorOpen = true;
}

void closeDoor() {
  Serial.println("Command received: CLOSING DOOR");
  digitalWrite(GREEN_LED_PIN, LOW);
  digitalWrite(RED_LED_PIN, HIGH);
  myServo.write(DOOR_CLOSED_POS);
  isDoorOpen = false;
}