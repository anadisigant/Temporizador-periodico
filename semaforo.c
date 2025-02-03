#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Definição das GPIOs corretas para os LEDs
#define LED_PIN_RED 11
#define LED_PIN_YELLOW 12
#define LED_PIN_GREEN 13

int estado = 0; // Estado inicial
int contador = 0; // Contador de segundos

// Callback para alternar o semáforo a cada 3 segundos
bool repeating_timer_callback(struct repeating_timer *t) {
    // Desliga todos os LEDs
    gpio_put(LED_PIN_RED, 0);
    gpio_put(LED_PIN_YELLOW, 0);
    gpio_put(LED_PIN_GREEN, 0);

    // Aciona o LED correspondente ao estado atual
    switch (estado) {
        case 0:
            gpio_put(LED_PIN_RED, 1);
            printf("Pare!\n");
            break;
        case 1:
            gpio_put(LED_PIN_YELLOW, 1);
            printf("Atenção!\n");
            break;
        case 2:
            gpio_put(LED_PIN_GREEN, 1);
            printf("Siga!\n");
            break;
    }
    
    estado = (estado + 1) % 3; // Alterna entre 0, 1 e 2
    contador = 0; // Reinicia o contador de segundos
    return true;
}

// Callback para contar segundos continuamente
bool second_timer_callback(struct repeating_timer *t) {
    contador++;
    printf("%d\n", contador);
    return true;
}

int main() {
    stdio_init_all(); // Inicializa a comunicação serial
    
    // Inicializa os pinos dos LEDs
    gpio_init(LED_PIN_RED);
    gpio_set_dir(LED_PIN_RED, GPIO_OUT);
    gpio_init(LED_PIN_YELLOW);
    gpio_set_dir(LED_PIN_YELLOW, GPIO_OUT);
    gpio_init(LED_PIN_GREEN);
    gpio_set_dir(LED_PIN_GREEN, GPIO_OUT);

    // Garante que o LED vermelho inicie ligado
    gpio_put(LED_PIN_RED, 1);

    // Inicializa os temporizadores
    struct repeating_timer semaforo_timer;
    struct repeating_timer contador_timer;

    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &semaforo_timer);
    add_repeating_timer_ms(1000, second_timer_callback, NULL, &contador_timer);

    while (true) {
        tight_loop_contents(); // Mantém o loop ativo sem sobrecarregar o processador
    }
    return 0;
}