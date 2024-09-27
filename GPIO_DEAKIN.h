#ifndef GPIO_DEAKIN_H
#define GPIO_DEAKIN_H

#include <Arduino.h>

class GPIO_DEAKIN {
public:
    GPIO_DEAKIN();
    void setPinMode(uint8_t mode); // INPUT or OUTPUT
    uint8_t getPinMode(); // Return the mode of the pin
    // Add other GPIO methods as needed
private:
    uint8_t pinMode; // Store pin mode
};

#endif // GPIO_DEAKIN_H
