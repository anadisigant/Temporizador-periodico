# Clock e Temporizadores
Repositório criado a fim de armazenar uma aplicação prática da função add_repeating_timer_ms().<br>
__Autora:__ Ana Karolina Disigant Reis

## Temporizador periódico
Para que a função _add_repeating_timer_ms()_ tem sua aplicação evidenciada no projeto de um semáforo com temporização de 3 segundos para cada alteração de sinal.<br>

__Componentes necessários:__ <br>
1) Microcontrolador Raspberry Pi Pico W;
2) 03 LEDs (vermelho, amarelo e verde);
3) 03 Resistores de 330 Ω.

__Requisitos:__

1) O acionamento dos LEDs (sinais do semáforo) deve iniciar na cor vermelha, alterando para amarela e, em seguida, verde; ✅
2) O temporizador deve ser ajustado para um atraso de 3 segundos (3.000ms); ✅
3) A mudança de estado dos LEDs deve ser implementa na função de call-back do temporizador, a exemplo da rotina trabalhada na aula síncrona - repeating_timer_callback(); ✅
4) A rotina principal, presente no interior da estrutura de repetição while, deve imprimir algum tipo de informação a cada segundo (1.000 ms) - a mensagem enviada pela porta serial fica a critério do discente; ✅
5) Com o emprego da Ferramenta Educacional BitDogLab, faça um experimento com o código deste exercício utilizando o LED RGB – GPIOs 11, 12 e 13 (vide vídeo em anexo junto com o projeto). ✅
