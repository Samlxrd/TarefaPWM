#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define PWM_SERVO 22 // Servo conectado ao pino GPIO 22 como PWM
const uint16_t WRAP_PERIOD = 10000; // valor máximo do contador - WRAP
const float PWM_DIVISER = 250.0; // divisor do clock para o PWM

// Protótipo das funções
void pwm_setup();
void set_pwm_dc(uint16_t active_cycle);

int main()
{
    stdio_init_all(); //inicializa o sistema padrão de I/O
    pwm_setup(); //configura o PWM

    set_pwm_dc(2400); // Ciclo ativo de 2.400 µs (180 graus)
    sleep_ms(5000);

    set_pwm_dc(1470); // Ciclo ativo de 1.470 µs (90 graus)
    sleep_ms(5000);
    
    set_pwm_dc(500); // Ciclo ativo de 500 µs (0 graus)
    sleep_ms(5000);

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

void set_pwm_dc(uint16_t active_cycle) {
    uint16_t duty_cycle = (active_cycle * WRAP_PERIOD) / 20000;
    pwm_set_gpio_level(PWM_SERVO, duty_cycle);
}