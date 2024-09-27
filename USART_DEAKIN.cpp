#include "USART_DEAKIN.h"

// Define positions for USART control registers if not already defined
#ifndef SERCOM_USART_CTRLB_TXPO_Pos
#define SERCOM_USART_CTRLB_TXPO_Pos 24  // Define TXPO position
#endif

#ifndef SERCOM_USART_CTRLB_RXPO_Pos
#define SERCOM_USART_CTRLB_RXPO_Pos 26  // Define RXPO position
#endif

#ifndef SERCOM_USART_CTRLA_STOPBITS_Pos
#define SERCOM_USART_CTRLA_STOPBITS_Pos 21  // Define STOPBITS position
#endif

#ifndef SERCOM_USART_CTRLA_PARITY_Pos
#define SERCOM_USART_CTRLA_PARITY_Pos 18  // Define PARITY position
#endif

// Constructor implementation
USART_DEAKIN::USART_DEAKIN() {
    // You can initialize any members here if needed
}

// Initialize the USART_DEAKIN
void USART_DEAKIN::init(uint32_t baudRate, uint8_t stopBits, uint8_t parity, uint8_t txPad) {
    // Enable the SERCOM in the internal clock mode
    SERCOM0->USART.CTRLA.reg = SERCOM_USART_CTRLA_MODE_USART_INT_CLK;

    // Configure TX and RX pads
    SERCOM0->USART.CTRLB.reg = (txPad << SERCOM_USART_CTRLB_TXPO_Pos) | // Set TX pad
                               (1 << SERCOM_USART_CTRLB_RXPO_Pos);    // Set RX pad (1 for RX pad 1)

    // Configure stop bits and parity
    SERCOM0->USART.CTRLA.reg |= (stopBits << SERCOM_USART_CTRLA_STOPBITS_Pos) |
                                 (parity << SERCOM_USART_CTRLA_PARITY_Pos);

    // Set the baud rate
    uint16_t baudValue = (SystemCoreClock / (16 * baudRate)) - 1; // Calculate baud value
    SERCOM0->USART.BAUD.reg = baudValue;

    // Wait for synchronization
    while (SERCOM0->USART.SYNCBUSY.reg & SERCOM_USART_SYNCBUSY_SWRST); // Wait for synchronization
}
