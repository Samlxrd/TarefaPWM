#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define PWM_SERVO 22 // Servo conectado ao pino GPIO 22 como PWM
const uint16_t WRAP_PERIOD = 10000; // valor máximo do contador - WRAP
const float PWM_DIVISER = 250.0; // divisor do clock para o PWM

// Protótipo das funções
void pwm_setup();

int main()
{
    stdio_init_all(); //inicializa o sistema padrão de I/O
    pwm_setup(); //configura o PWM

    while (true) {

    }
}

// função para configurar o módulo PWM
void pwm_setup()
{
    gpio_set_function(PWM_SERVO, GPIO_FUNC_PWM); //habilitar o pino GPIO como PWM
    uint slice = pwm_gpio_to_slice_num(PWM_SERVO); //obter o canal PWM da GPIO

    pwm_set_clkdiv(slice, PWM_DIVISER); //define o divisor de clock do PWM
    pwm_set_wrap(slice, WRAP_PERIOD); //definir o valor de wrap
    pwm_set_enabled(slice, true); //habilita o pwm no slice correspondente
}