# Clock e Temporizadores
Repositório criado a fim de armazenar uma aplicação prática da função add_repeating_timer_ms().<br>
__Autora:__ Ana Karolina Disigant Reis

## Temporizador periódico
A função _add_repeating_timer_ms()_ tem sua aplicação evidenciada no projeto de um semáforo com temporização de 3 segundos para cada alteração de sinal.<br>

__Componentes necessários:__ <br>
1) Microcontrolador Raspberry Pi Pico W;
2) 03 LEDs (vermelho, amarelo e verde);
3) 03 Resistores de 330 Ω.

__Requisitos de desenvolvimento:__

1) O acionamento dos LEDs (sinais do semáforo) deve iniciar na cor vermelha, alterando para amarela e, em seguida, verde; ✅
2) O temporizador deve ser ajustado para um atraso de 3 segundos (3.000ms); ✅
3) A mudança de estado dos LEDs deve ser implementa na função de call-back do temporizador, a exemplo da rotina trabalhada na aula síncrona - repeating_timer_callback(); ✅
4) A rotina principal, presente no interior da estrutura de repetição while, deve imprimir algum tipo de informação a cada segundo (1.000 ms) - a mensagem enviada pela porta serial fica a critério do discente; ✅
5) Com o emprego da Ferramenta Educacional BitDogLab, faça um experimento com o código deste exercício utilizando o LED RGB – GPIOs 11, 12 e 13 (vide vídeo em anexo junto com o projeto). ✅

__Requisitos para o uso:__

1) Raspberry Pi Pico;
2) SDK do Raspberry Pi Pico configurado;
3) Compilador GCC para ARM (arm-none-eabi-gcc);
4) CMake e Make;
5) Cabo USB para comunicação.

__Configuração e Compilação:__

1. Clone o repositório:
   ```sh
   git clone https://github.com/anadisigant/Temporizador-periodico.git
   cd Temporizador-periodico
   ```
2. Configure o ambiente:
   ```sh
   export PICO_SDK_PATH=</caminho/para/o/pico-sdk>
   ```
3. Crie e entre no diretório de build:
   ```sh
   mkdir build && cd build
   ```
4. Execute o CMake:
   ```sh
   cmake ..
   ```
5. Compile o projeto:
   ```sh
   make
   ```
6. Após a compilação, conecte o Raspberry Pi Pico no modo BOOTSEL e arraste o arquivo `.uf2` gerado para o dispositivo.

__Uso__

1. Após carregar o firmware no Raspberry Pi Pico, o temporizador será inicializado.
2. O código está configurado para acionar eventos em intervalos regulares.
3. Para modificar o tempo do temporizador, ajuste os parâmetros no código-fonte.

