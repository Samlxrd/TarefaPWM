## Instruções de Uso do Programa
1. Clone o repositório
    ```bash
    git clone https://github.com/Samlxrd/TarefaPWM.git

2. Navegue até o diretório do projeto:
    ```bash
    cd TarefaPWM

3. Execução do Código
    - Basta compilar o projeto utilizando o Pico SDK e abrir a simulação do Wokwi no VS Code.

## Funcionalidades do projeto

Inicialmente é definido a frequência do PWM para aproximadamente 50hz - período de 20ms. Em seguida, o ciclo ativo do módulo pwm é ajustado para:
- 2.400µs (Ajustando a flange (braço) do servomotor para a posição de, aproximadamente, 180 graus)
- 1.470µs (Ajustando a flange (braço) do servomotor para a posição de, aproximadamente, 90 graus)
- 500µs (Ajustando a flange (braço) do servomotor para a posição de, aproximadamente, 0 graus)

Por fim uma rotina entra em execução, fazendo a movimentação periódica do braço do servomotor entre os ângulos de 0 e 180 graus.

Link do vídeo de apresentação do projeto: https://youtu.be/-WLf0dEpGBQ
