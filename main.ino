#include <Keypad.h>          // Biblioteca para ler o teclado matricial


//  Nokie


// Pinos conectados às linhas (ROWS) do teclado
byte rowPins[3] = {3, 4, 5};  

// Pinos conectados às colunas (COLS) do teclado
byte colPins[4] = {6, 7, 8, 9};  

// Mapeamento das teclas (4x4)
char keys[3][4] = {
  {'0', '1', '2', '3'},
  {'4', '5', '6', '7'},
  {'8', '9', 'A', 'B'},
};

// Inicializa o teclado com as configurações acima
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, 3, 4);

// Pino conectado ao buzzer (saída de som)
#define BUZZER_PIN 10

// Notas musicais correspondentes às teclas (C4 a C5, 14 notas)
int notas[12] = {
  262, 277, 294, 311,   // C, C#, D, D#
  330, 349, 370, 392,   // E, F, F#, G
  415, 440, 466, 494,   // G#, A, A#, B               // C (oitava acima)
};

void setup() {
  // Configura o pino do buzzer como saída
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // Lê todas as teclas ativas no momento
  if (keypad.getKeys()) {
    for (int i = 0; i < LIST_MAX; i++) {
      // Pega a tecla atual da lista
      Key k = keypad.key[i];
       if (k.stateChanged) {
        int index = teclaToIndice(k.kchar);

          if (k.kstate == PRESSED) {
            // Toca o som enquanto a tecla está pressionada
            tone(BUZZER_PIN, notas[index]);

            // Envia a tecla pressionada para o outro Arduino
          }

          if (k.kstate == RELEASED) {
            // Para o som quando a tecla é solta
            noTone(BUZZER_PIN);
          }
       }
        }
      }
    }


// ========================================
// 🔄 Converte caractere da tecla para índice
// ========================================
int teclaToIndice(char tecla) {
  switch (tecla) {
    case '0': return 0;
    case '1': return 1;
    case '2': return 2;
    case '3': return 3;
    case '4': return 4;
    case '5': return 5;
    case '6': return 6;
    case '7': return 7;
    case '8': return 8;
    case '9': return 9;
    case 'A': return 10;
    case 'B': return 11;
    default: return -1;  // Tecla inválida
  }
}
