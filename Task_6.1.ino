#include <Arduino.h>
#include "USART_DEAKIN.h"

// Create an instance of the USART_DEAKIN class
USART_DEAKIN usart;

void setup() {
    // Initialize Serial for debugging
    Serial.begin(9600);

    // Initialize USART with desired parameters
    usart.init(9600, 1, 0, 0); // Example parameters: baud rate, stop bits, parity, txPad
}

void loop() {
    // Call the display function periodically
    displayTimerState();

    // Check for available data on Serial
    if (Serial.available()) {
        // Read a byte from Serial
        char incomingByte = Serial.read();

        // Echo the byte back to Serial
        Serial.print("Received: ");
        Serial.println(incomingByte);
    }

    delay(1000); // Adjust delay as needed
}

void displayTimerState() {
    // Check if the USART is busy or ready
    Serial.println(SERCOM0->USART.INTFLAG.bit.RXC ? "USART is busy" : "USART is ready");
}
