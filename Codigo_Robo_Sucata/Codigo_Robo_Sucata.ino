// Bibliotecas
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

// Saidas Motores
const int baseE = 24, baseD = 26;
const int ombroE = 28, ombroD = 30;
const int cotoveloE = 32, cotoveloD = 34;
const int pulsoE = 36, pulsoD = 38;
const int rotacaoE = 40, rotacaoD = 42;
const int garraE = 44, garraD = 46;

// Saidas PWM
const int pwm_Base = 7;
const int pwm_Ombro = 6;
const int pwm_Cotovelo = 5;
const int pwm_Pulso = 4;
const int pwm_Rotacao = 3;
const int pwm_Garra = 2;

// Posição Minima e Maxima
const int min_Base = 4, max_Base = 96;
const int min_Ombro = 4, max_Ombro = 44;
const int min_Cotovelo = 15, max_Cotovelo = 96;
const int min_Pulso = 15, max_Pulso = 90;
const int min_Rotacao = 15, max_Rotacao = 96;
const int min_Garra = 0, max_Garra = 1;

// Entradas Potenciometros
const int scanner_Base = A1;
const int scanner_Ombro = A2;
const int scanner_Cotovelo = A3;
const int scanner_Pulso = A4;
const int scanner_Rotacao = A5;
const int scanner_Garra = A6;

// Entradas e Saidas Bluetooth
const int RxD = 12, TxD = 11;
SoftwareSerial Bluetooth(RxD, TxD);  //RX pino 12, TX pino 11

// Outras Entradas e Saidas
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Saídas SDA E SCL nas entradas 20 e 21 respectivamente
const int botao = 22;
const int luz = 10;
const int led = 13;
String status_garra = "";

// Variaveis
int posicaoAtual = -1;
bool contadorState = false;      // Estado atual do botão Contador
bool lastContadorState = false;  // Estado anterior do botão Contador
int countContador = 0;           // Contagem de cliques do botão Contador
bool nivel = 0;
bool imprimeStatus = true;
bool bluetooth = false;
bool serial = false;
unsigned long anteriorMillis = 0;
const long intervalo = 1000;  //1000

// Funçoes dos Motores
void _Garra(int coordenada);
void _Rotacao(int coordenada);
void _Pulso(int coordenada);
void _Cotovelo(int coordenada);
void _Ombro(int coordenada);
void _Base(int coordenada);
void _OmbroCotovelo(int ombro, int cotovelo);
void _CotoveloPulso(int cotovelo, int pulso);
void _BaseRotacao(int base, int rotacao);
void _OmbroCotoveloPulso(int ombro, int cotovelo, int pulso);

// Outras Funções
void _DisplaySerial(char index, int coordenada);
void _entradaDados(char *articulacao, int *posicao);
void _posicaoInicial();
void _Status(int envio);

void setup() {
  Serial.begin(38400);
  Bluetooth.begin(38400);
  _DisplaySerial('I', 0);

  // Definindo Motores
  pinMode(baseE, OUTPUT);
  pinMode(baseD, OUTPUT);
  pinMode(ombroE, OUTPUT);
  pinMode(ombroD, OUTPUT);
  pinMode(cotoveloE, OUTPUT);
  pinMode(cotoveloD, OUTPUT);
  pinMode(pulsoE, OUTPUT);
  pinMode(pulsoD, OUTPUT);
  pinMode(rotacaoE, OUTPUT);
  pinMode(rotacaoD, OUTPUT);
  pinMode(garraE, OUTPUT);
  pinMode(garraD, OUTPUT);

  // Definindo nivellogico dos sensores
  pinMode(scanner_Base, INPUT_PULLUP);
  pinMode(scanner_Ombro, INPUT_PULLUP);
  pinMode(scanner_Cotovelo, INPUT_PULLUP);
  pinMode(scanner_Pulso, INPUT_PULLUP);
  pinMode(scanner_Rotacao, INPUT_PULLUP);
  pinMode(scanner_Garra, INPUT_PULLUP);

  // Definindo Outras Entradas e Saidas
  pinMode(botao, INPUT_PULLUP);
  pinMode(luz, OUTPUT);
  pinMode(led, OUTPUT);

  // Iniciando Motores
  digitalWrite(baseE, LOW);
  digitalWrite(baseD, LOW);
  digitalWrite(ombroE, LOW);
  digitalWrite(ombroD, LOW);
  digitalWrite(cotoveloE, LOW);
  digitalWrite(cotoveloD, LOW);
  digitalWrite(pulsoE, LOW);
  digitalWrite(pulsoD, LOW);
  digitalWrite(rotacaoE, LOW);
  digitalWrite(rotacaoD, LOW);
  digitalWrite(garraE, LOW);
  digitalWrite(garraD, LOW);
  digitalWrite(luz, LOW);
  digitalWrite(led, LOW);

  _entradaDados('x', -1);  // Chamada de função para bloquear a ultima instrução enviada
                           //_posicaoInicial();

  /*
  _OmbroCotovelo(44, 15);
  delay(500);

  _OmbroCotovelo(10, 60);
  delay(500);
  _OmbroCotovelo(44, 15);
  delay(500);
*/
  /*
  _BaseRotacao(50, 10);
  delay(500);

  _BaseRotacao(10, 80);
  delay(500);
  _BaseRotacao(50, 10);
  delay(500);
*/

/*
_CotoveloPulso(30, 60);
_CotoveloPulso(15, 45);
*/
  _Status(1);  // Serial
  _Status(2);  // Bluettoth
}

void loop() {
  contadorState = digitalRead(botao);                         // Lê o estado atual do botão
  if (contadorState == false && lastContadorState == true) {  // Verifica se o botão foi pressionado (transição de HIGH para LOW)
    delay(200);                                               // Pequena pausa para evitar leituras falsas, efeito de Bounce
    countContador++;                                          // Incrementa o contador de cliques
    imprimeStatus = true;                                     // Libera a impressão de status
    digitalWrite(led, !digitalRead(led));
    delay(100);
    digitalWrite(led, !digitalRead(led));
  }
  if (countContador == 0) {
    if (imprimeStatus == true) {
      _DisplaySerial('0', NULL);
      imprimeStatus = false;  // Bloqueia a impressão de status continuo
    }
    /* Aqui vai a função */
    _Comandos();
    _Status(1);  // Imprime o status dos motores a cada 1s
    /*------------------*/
  } else if (countContador == 1) {
    if (imprimeStatus == true) {
      _DisplaySerial('1', NULL);
      imprimeStatus = false;
    }
    /* Aqui vai a função */
  } else if (countContador == 2) {
    if (imprimeStatus == true) {
      _DisplaySerial('2', NULL);
      imprimeStatus = false;
    }
    /* Aqui vai a função */
  } else if (countContador == 3) {
    if (imprimeStatus == true) {
      _DisplaySerial('3', NULL);
      imprimeStatus = false;
    }
    /* Aqui vai a função */
  } else if (countContador == 4) {
    countContador = -1;
    if (imprimeStatus == true) {
      lcd.noDisplay();  // APAGA OS CARACTERES
      lcd.clear();
      lcd.display();
      imprimeStatus = false;
    }
  }
  lastContadorState = contadorState;  // Atualiza o estado anterior do botão
}

void _posicaoInicial() {
  ////// Posicao Inicial/Final do Robo ///////////
  digitalWrite(luz, HIGH);
  delay(2000);  //2000
  digitalWrite(luz, LOW);

  _Ombro(44);
  _Cotovelo(15);
  _Pulso(45);
  _Garra(1);     // Fechada.
  _Rotacao(80);  // Centralizado
  _Base(43);     // Centralizado

  Serial.println("-----------------------------> Robo Inicializado com Sucesso <-----------------------------");
}