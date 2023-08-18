???#include <avr/io.h>

int main(void) {
    // Set PD2, PD3, and PD4 as input for a, b, and c respectively
    DDRD &= ~((1 << PD2) | (1 << PD3) | (1 << PD4));

    // Enable internal pull-ups for PD2, PD3, and PD4
    PORTD |= (1 << PD2) | (1 << PD3) | (1 << PD4);

    // Set PB5 as output for LED
    DDRB |= (1 << PB5);

    while (1) {
        uint8_t a = PIND & (1 << PD2);
        uint8_t b = PIND & (1 << PD3);
        uint8_t c = PIND & (1 << PD4);

        if (
            (a || b || !c) && 
            (!a || !b || !c) && 
            (!a || b || c) && 
            (!a || !b || !c)
        ) {
            // Turn ON the LED if the expression is true
            PORTB |= (1 << PB5);
        } else {
            // Turn OFF the LED otherwise
            PORTB &= ~(1 << PB5);
        }
    }

    return 0; // This will never be reached
}
