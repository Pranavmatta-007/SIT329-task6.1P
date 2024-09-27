#ifndef USART_DEAKIN_H
#define USART_DEAKIN_H

#include <Arduino.h>

class USART_DEAKIN {
public:
    USART_DEAKIN();  // Constructor declaration
    void init(uint32_t baudRate, uint8_t stopBits, uint8_t parity, uint8_t txPad);
    // Add other member functions as needed

private:
    // Add private members if needed
};

#endif // USART_DEAKIN_H
