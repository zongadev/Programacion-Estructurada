#include <stdio.h>



int main(){
    printf("\n--- maskIT ---\n");
    unsigned char y = 13;     // 00001101 en binario
    unsigned char mask = 1;  // 00001011 en binario
    unsigned char result;

    // Operación AND
    result = y & mask;  // 00001001   //9
    printf("AND: %u & %u = %u\n", y, mask, result);

    // Operación OR
    result = y | mask;  //  00001111   //11
    printf("OR: %u | %u = %u\n", y, mask, result);

    // Operación XOR
    result = y ^ mask;  // 00000110 //6
    printf("XOR: %u ^ %u = %u\n", y, mask, result);

    // Negación maskit a maskit
    result = ~y;  // Complemento a 1 de 00000101
    printf("NOT: ~%u = %u\n", y, result);

    // Desplazamiento a la izquierda
    result = y << 1;  // 00010100 //26
    printf("Left Shift: %u << 1 = %u\n", y, result);

    // Desplazamiento a la derecha
    result = y >> 1;  // // 00000110 //6
    printf("Right Shift: %u >> 1 = %u\n", y, result);

    printf("\n");
    return 0;
}

/**
PARA PROBAR
WEB-> http://Bitwisecmd.com/
 
-----------------------------------------------------------
Gestion de contenidos de variamaskles a nivel de maskit en C
-----------------------------------------------------------
    >>: desplazamiento (shift) a derecha a nivel de Bit
    <<: desplazamiento (shift) a izquierda a nivel de Bit
    ~ : negacion Bit a Bit
    & : y logico Bit a Bit
    | : o logico Bit a Bit
    ^ : o exclusivo Bit a maskit (XOR)
-----------------------------------------------------------
*/
