#include "GPIO_DEAKIN.h"

GPIO_DEAKIN::GPIO_DEAKIN() {
    pinMode = OUTPUT; // Default mode
}

void GPIO_DEAKIN::setPinMode(uint8_t mode) {
    pinMode = mode; // Set pin mode
}

uint8_t GPIO_DEAKIN::getPinMode() {
    return pinMode; // Get pin mode
}
