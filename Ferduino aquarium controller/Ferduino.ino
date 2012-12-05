// Este programa compatível com a IDE 1.0.2 desde que as bibliotecas "WConstants.h" e "wiring.h" sejam colocadas na pasta ...arduino-1.0.2\hardware\arduino\cores\arduino.
//Dúvidas, sugestões e elogios: fefegarcia_1@hotmail.com
//---------------------------------------------------------
//Ferduino controlador de aquários versão 2.4.0>> Última atualização:26/11/2012.
//Este programa foi desenvolvido com base na versão Stilo 2.1
//Disponível nesta página http://code.google.com/p/stilo/ 
//---------------------------------------------------------
//Algoritmo de controle de LED é baseado em Krusduino de Hugh Dangerfield
//http://Code.Google.com/p/dangerduino/
//Algoritmo da fase lunar foi escrito por Jamie Jardin vulgo "TheDOdblG", baseado no código de NightAtTheOpera's Lunar Phase 
//http://www.nano-reef.com/forums/index.php?showtopic=217305
//-----------------------------------------------------------
// Este programa é software livre; Você pode redistribuí-lo e/ou
// modificá-lo sob os termos da GNU General Public License
// como publicada pela Free Software Foundation versão 3
// da licença, ou (por sua opção) qualquer versão posterior.
// Este programa é distribuído na esperança que seja útil,
// Mas sem qualquer garantia; sem mesmo a garantia implícita de
// comercialização ou propósito particular. Consulte o
// GNU General Public License para mais detalhes.

//*************************************************************************************************
//*************** Biliotecas utilizadas ***********************************************************
//*************************************************************************************************
#include <ITDB02_Graph16.h>
#include <ITDB02_Touch.h>
#include <Wire.h>
#include <EEPROM.h>
#include <writeAnything.h> // Template
#include <DS1307henning.h> //Atenção: Para usar a biblioteca original renomeie para <DS1307.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SdFat.h>
#include <SdFatUtil.h>
#include <EtherCard.h>

//****************************************************************************************************
//***************** Sensore de temperatura ***********************************************************
//****************************************************************************************************
OneWire OneWireBus(47);                   //Sensor de temperatura da agua e dissipador ligado ao pino 47.
DallasTemperature sensors(&OneWireBus);  // Pass our oneWire reference to Dallas Temperature.                         
DeviceAddress sensor_agua= { 
  0x28, 0x9C, 0xA9, 0xAA, 0x03, 0x00, 0x00, 0x44 }; // Assign the addresses of temperature sensors.  Add/Change addresses as needed.
DeviceAddress sensor_dissipador = { 
  0x28, 0xE1, 0x96, 0xAA, 0x03, 0x00, 0x00, 0x7D }; // Assign the addresses of temperature sensors.  Add/Change addresses as needed.

//****************************************************************************************************
//****************** Variaveis de textos e fontes ****************************************************
//****************************************************************************************************
#define LARGE true
#define SMALL false
extern uint8_t SmallFont[];   // Declare which fonts we will be using
extern uint8_t BigFont[];     // Declare which fonts we will be using

//****************************************************************************************************
//****************** Define funcoes dos pinos digitais e analogicos **********************************
//****************************************************************************************************

// Pinos disponiveis [PWM (7,44,45,46)TX/RX(16,17,18,19) ANALOGICO(A6, A7, A8)]

const int ledPinBlue = 8;     //Pino que liga os leds azuis
const int ledPinWhite = 9;    //Pino que liga os leds brancos
const int aquecedorPin = 42;   // Pino que liga o aquecedor
const int chillerPin = 43;   // Pino que liga o chiller
const int alarmPin = A13;  // Pino que aciona o alarme de temperatura da agua baixa ou alta
const int fanPin = 13;     // Pino que controla a velocidade das ventoinhas do dissipador
const int sensor1 = A0;       //Pino analogico que verifica se ha tensao na boia da quarentena.
const int sensor2 = A1;       //Pino analogico que verifica se ha tensao na boia inferior do sump.
const int sensor3 = A2;       //Pino analogico que verifica se ha tensao na boia superior do sump.
const int sensor4 = A3;       //Pino analogico que verifica se ha tensao na boia inferior do reservatório.
const int sensor5 = A4;       //Pino analogico que verifica o nivel do reef.
const int sensor6 = A5;       //Pino analogico que verifica o nivel do fish only.
const int bomba1Pin = A9;    // Bomba que tira agua da quarentena.
const int bomba2Pin = A10;    // Bomba que tira agua do sump.
const int bomba3Pin = A11;    // Bomba que coloca água no sump.
const int solenoide1Pin = 48; // Liga a reposicao de agua doce.
const int reatorPin = 49;     // Pino que liga o CO2 do reator.
const int ozonizadorPin = A12; // pino que liga o zonizador
const int multiplexadorS0Pin = A14; // Pino S0 de controle dos stamps
const int multiplexadorS1Pin = A15; // Pino S1 de controle dos stamps
const int dosadora1 = 10;     // Bomba dosadora 1
const int dosadora2 = 11;     // Bomba dosadora 2
const int dosadora3 = 12;     // Bomba dosadora 3

//*******************************************************************************************************
//********************** Funcoes RTC ********************************************************************
//*******************************************************************************************************
DS1307 rtc(20, 21); // Indicao os pinos que o RTC esta conectado
Time t_temp;
boolean ct=false;
boolean cd=false;

//*******************************************************************************************************
//********************** Variaveis das fucoes do touch screen e tela inicial ****************************
//*******************************************************************************************************
ITDB02        myGLCD(38,39,40,41,1);     // Altere o aspecto se não estiver usando o ITDB02-3.2WC >>>>>>>>>>> (38,39,40,41,x) onde x é o modelo do LCD
ITDB02_Touch  myTouch(6,5,4,3,2);
int x, y;                  // touch coordinates
long previousMillis = 0;
byte data[56];
String day; 
int whiteLed, blueLed;    // previous Led output values
int dispScreen = 0;

// tela inicio =0, 
//tela de menu = 1, 
//tela do relogio = 2,
// tela de teste = 3,
//tela controle de temperatua = 4, 
//tela alterar valores dos led = 5
// tela para alterar potencia dos leds = 6,
// tela tpa = 7, 
// tela config. bombas dosadoras = 8,
// tela graficos = 9,
// tela wavemaker = 10, 
// tela grafico temperatura = 11,
// tela grafico orp = 12, 
// tela grafico ph do aquario = 13,
// tela configuracao parametros = 14, 
// tela configuracao de ph do reator de calcio = 15, 
// tela configuracao orp = 16, 
// tela grafico de ph do reator de calcio = 17, 
// tela configuracao de ph do aquario = 18, 
// tela grafico de densidade = 19,
// tela configurar densidade = 20, 
// tela esolha uma dosadora = 21, 
// tela dosadora 1 = 22, 
//tela dosadora 2 = 23, tela dosadora 3 = 24, tela dosadora 4 = 25, tela calibra dosadoras = 26

Time  t;

//*****************************************************************************************
//*********************** Variaveis do controle de temperatura da agua ********************
//*****************************************************************************************
float tempC = 0;              // Temperatura da agua
float setTempC = 0;          // Temperatura desejada
float offTempC = 0;          // Variacao permitida da temperatura
float alarmTempC = 0;        // Variacao para acionar o alarme de temperatura da agua
boolean tempCflag = 0;         // Sinaliza que o aquecedor está ligado / desligado
boolean tempHflag = 0;         // Sinaliza que o chiller está ligado / desligado
boolean tempAflag = 0;         // Sinaliza que o alarme de temperatura está ativo
int contador_temp = 0;
float temperatura_agua_temp = 0; //temperatura temporaria
float temperatura_dissipador_temp = 0; //temperatura temporaria


//*****************************************************************************************
//************************ Variaveis do controle do PH do aquario *************************
//*****************************************************************************************
float PHA = 0;               // PH do aquario
float setPHA = 0;           // PH desejado do aquario
float offPHA = 0;           // Variacao permitida do PH do aquario
float alarmPHA = 0;         // Variacao para acionar o alarme de ph do aquario
boolean PHAAflag = 0;          // Sinaliza que o PH do aquario esta fora do especificado

//*****************************************************************************************
//************************ Variaveis de controle de densidade *****************************
//*****************************************************************************************
int DEN = 0;                  // Densidade
int setDEN = 0;             // Densidade desejada
int offDEN = 0;             // Variacao permitida da densidade
int alarmDEN = 0;           // Variacao para acionar o alarme de densidade
boolean DENAflag = 0;        // Sinaliza que a densidade esta fora do especificado

//*****************************************************************************************
//************************ Variaveis de controle do PH do reator de calcio ****************
//*****************************************************************************************
float PHR =0;               // Valores PH reator
float setPHR = 0;           // PH do reator desejado
float offPHR = 0;           // Variacao permitida do PH do reator
float alarmPHR = 0;         // Variacao para acionar o alarme do PH do reator de calcio
boolean PHRflag = 0;          // Sinaliza que CO2 esta ligado / desligado
boolean PHRAflag = 0;        // Sinaliza que o PH do reator de calcio esta fora do especificado

//*****************************************************************************************
//************************ Variaveis de controle da  ORP **********************************
//*****************************************************************************************
int ORP =0;                 // Valores ORP
float setORP = 0;           // ORP desejada
float offORP = 0;           // Variacao permitida da ORP
float alarmORP = 0;         // Variacao para acionar o alarme da ORP
boolean ORPflag=0;          // Sinaliza que o ozonizador esta ligado / desligado
float ORPAflag = 0;        // Sinaliza que a ORP esta fora do especificado

//*****************************************************************************************
//************************ Variaveis de controle de velocidade dos coolers ****************
//*****************************************************************************************
const int HtempMin = 30;    //Declara a temperatura para iniciar o funcionamento das ventoinha do dissipador 
const int HtempMax = 40;    //Declara que as ventoinhas devem estar em sua velocidade maxima quando o dissipador estiver com 40°c

//*****************************************************************************************
//************************ Variavel de controle da temperatura do dissipador **************
//*****************************************************************************************
float tempH = 0;            //Temperatura do dissipador

//*****************************************************************************************
//************************ Variaveis temporarias de controle de temperatura da agua *******
//*****************************************************************************************
float temp2beS;           
float temp2beO;
float temp2beA;

//*****************************************************************************************
//************************ Variaveis temporarias de controle do PH do reator de calcio ****
//*****************************************************************************************
float PHR2beS;             
float PHR2beO;
float PHR2beA;

//*****************************************************************************************
//************************ Variaveis temporarias de controle do PH do aquario *************
//*****************************************************************************************
float PHA2beS;             
float PHA2beO;
float PHA2beA;

//*****************************************************************************************
//************************ Variaveis temporarias de controle da ORP ***********************
//*****************************************************************************************
float ORP2beS;               //orp temporaria
float ORP2beO;
float ORP2beA;

//*****************************************************************************************
//************************ Variaveis temporarias de controle da densidade *****************
//*****************************************************************************************
float DEN2beS;            
float DEN2beO;
float DEN2beA;

//*****************************************************************************************
//************************ Variaveis de controle da iluminacao ****************************
//*****************************************************************************************
int LedChangTime = 0;             //LED change page, time and values
boolean WorB;                     //display LED change page for whites (true) or blues (false)
boolean BUCKPUCK  = false;  //For Mean Well displays change "true" to "false"
boolean LEDtestTick = false;   //for testing leds and speed up clock
int min_cnt ;
int bled_out ;
int wled_out ;
#define WHITE true
#define BLUE false

//*****************************************************************************************
//************************ Variave da fase lunar ******************************************
//*****************************************************************************************
float LC = 29.53059;  //1 Lunar Cycle = 29.53059 days
String LP;
double AG;

//*****************************************************************************************
//************************ Variaveis da TPA automatica ************************************
//*****************************************************************************************
int hora = 0;
int minuto = 0;
int duracaomaximatpa = 0;
int segunda = 0;
int terca = 0;
int quarta = 0;
int quinta = 0;
int sexta = 0;
int sabado = 0;
int domingo = 0;
int tpa = 0;                             // Controla od estagio da TPA automatica
boolean tpa_em_andamento = false;           // Sinaliza TPA automatica em andamento
boolean falha_tpa = false;           // Sinaliza falha durante a TPA automatica
unsigned long tempo = 0;                 // Duracao de cada estagio da TPA automatica
unsigned long marcadoriniciotpa = 0;   // Evita que uma tpa inicie proximo do millis zerar
unsigned long shiftedmillis = 0;       // Evita que uma tpa inicie proximo do millis zerar

//*****************************************************************************************
//************************ Variaveis temporarias da TPA automatica ************************************
//*****************************************************************************************
int temp2hora;
int temp2minuto;
int temp2duracaomaximatpa;
int temp2segunda;
int temp2terca;
int temp2quarta;
int temp2quinta;
int temp2sexta;
int temp2sabado;
int temp2domingo;

//****************************************************************************************
//*********************** Variaveis de controle das funcoes que utilizam o cartao SD *****
//****************************************************************************************
unsigned long logtempminutoantes = 0;  // Variavel que controla o tempo para gravacao dos parametro no cartao SD 
const int chipselect = 4;            // Para utilizar o Sd card do LCD altere para 53
Sd2Card card;
SdFile file;
SdFile root;
SdVolume volume;
char time1;
char time2;
char time3;
char time4;
char time5;

//*****************************************************************************************
//*********************** Variavel do controle de niveis **********************************
//*****************************************************************************************
boolean nivel_status = 0;             // Sinaliza nivel baixo em um dos aquarios

//*****************************************************************************************
//************************ Variavel de controle da reposicao de agua doce *****************
//*****************************************************************************************
boolean ato = 0;                      // Sinaliza reposicao ligada / desligada

//*****************************************************************************************
//************************ Variaveis de envio da informacoes ao cosm.com ******************
//*****************************************************************************************
long previous_Millis = 0; // Variavel que controla o tempo para envio dos dados
int chiller_status;   
int aquecedor_status;
int reator_status;
int ozonio_status;
int reposicao_status;
int niveis_status;
int tpa_status;

//*****************************************************************************************
//************************* Funcoes ethernet shield ***************************************
//*****************************************************************************************
boolean Ethernet_Shield = true; // Altere para "false" caso não tenha um Ethernet Shield conectado ao Arduino.
/*
#define FEED    "xxxxx"               // Numero do projeto(cosm.com).
 #define APIKEY  "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" //Senha do projeto(cosm.com)
 #define KEY   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" // supertweet.net: senha criptografada em base 64 (http://tuxgraphics.org/~guido/javascript/base64-javascript.html).
 */
#define FEED    "69337"               // Numero do projeto status aquarios (cosm.com)
#define APIKEY  "Z9VxU-o1rFDfN-37x_WoJsMfo-eSAKx0MGd4WmdHT0IwTT0g" //Senha do projeto(cosm.com)

static byte mymac[] = {
  0x54, 0x55, 0x58, 0x10, 0x00, 0x26}; // Este mac deve ser único na rede.
static byte myip[] = {
  192,168,2,105};
static byte gwip[] = {
  192,168,2,1 };
char website[] PROGMEM = "api.cosm.com";
char website1[] PROGMEM = "api.supertweet.net";
byte Ethernet::buffer[500];
Stash stash;

//*****************************************************************************************
//************************** Variaveis de controle do multiplexador ***********************
//*****************************************************************************************
boolean Stamps = true; // Altere para "false" caso não tenha ao menos um dos circuitos de PH, ORP e EC da Atlas Scientific.
long millis_antes = 0;
int DENT; //Densidade temporária.
float PHT; // PH temporário.
int ORPT; //ORP temporária
char sensorstring[15];
byte holding;
short ph1=0; //Y0
short ph2=1; //Y1
short orp=2; //Y2
short ec=3; //Y3
int done = 0;

//*****************************************************************************************
//************************** Variaveis da solicitacao de senha ****************************
//*****************************************************************************************
char stCurrent[7]="";
char limpar_senha [7] = "";
int stCurrentLen=0;
char senha [7] = {
  '1','2','3','4','5','6','\0'}; // Insira sua senha aqui. O caracter '\0' nao deve ser alterado.

//*****************************************************************************************
//************************** Variaveis dosadoras ******************************************
//*****************************************************************************************
char time6;
char time7;
char time8;
char time9;
char time10;
char time11;
int contador = 0;
int minuto01 = 0;
int minuto11 = 0;
int deslocamento_botao_x = 155;
int deslocamento_botao_y = 90;
long tempo_dosagem_1 = 0;
int pwm_dosadora_1 = 255;
int pwm_dosadora_2 = 255;
int pwm_dosadora_3 = 255;
float dose_dosadora_1_manual = 0.0;
float dose_dosadora_2_manual = 0.0;
float dose_dosadora_3_manual = 0.0;
boolean modo_manual = false;
boolean modo_personalizado = false;
boolean modo_automatico = false;
boolean modo_calibrar = false;
boolean dosadora_1_selecionada = false;
boolean dosadora_2_selecionada = false;
boolean dosadora_3_selecionada = false;
int modo_personalizado_on_1 = 0;
int modo_automatico_on_1 = 0;
int modo_personalizado_on_2 = 0;
int modo_automatico_on_2 = 0;
int modo_personalizado_on_3 = 0;
int modo_automatico_on_3 = 0;
float fator_calib_dosadora_1 = 0.0;
float fator_calib_dosadora_2 = 0.0;
float fator_calib_dosadora_3 = 0.0;
float dose_dosadora_1_personalizada = 0.0;
float dose_dosadora_2_personalizada = 0.0;
float dose_dosadora_3_personalizada = 0.0;
float dose_dosadora_1_automatica = 0.0;
float dose_dosadora_2_automatica = 0.0;
float dose_dosadora_3_automatica = 0.0;
int hora_inicial_dosagem_personalizada_1 = 0;
int minuto_inicial_dosagem_personalizada_1 = 0;
int hora_final_dosagem_personalizada_1 = 0;
int minuto_final_dosagem_personalizada_1 = 0;
int segunda_dosagem_personalizada_1 = 0;
int terca_dosagem_personalizada_1 = 0;
int quarta_dosagem_personalizada_1 = 0;
int quinta_dosagem_personalizada_1 = 0;
int sexta_dosagem_personalizada_1 = 0;
int sabado_dosagem_personalizada_1 = 0;
int domingo_dosagem_personalizada_1 = 0;
int hora_inicial_dosagem_personalizada_2 = 0;
int minuto_inicial_dosagem_personalizada_2 = 0;
int hora_final_dosagem_personalizada_2 = 0;
int minuto_final_dosagem_personalizada_2 = 0;
int segunda_dosagem_personalizada_2 = 0;
int terca_dosagem_personalizada_2 = 0;
int quarta_dosagem_personalizada_2 = 0;
int quinta_dosagem_personalizada_2 = 0;
int sexta_dosagem_personalizada_2 = 0;
int sabado_dosagem_personalizada_2 = 0;
int domingo_dosagem_personalizada_2 = 0;
int hora_inicial_dosagem_personalizada_3 = 0;
int minuto_inicial_dosagem_personalizada_3 = 0;
int hora_final_dosagem_personalizada_3 = 0;
int minuto_final_dosagem_personalizada_3 = 0;
int segunda_dosagem_personalizada_3 = 0;
int terca_dosagem_personalizada_3 = 0;
int quarta_dosagem_personalizada_3 = 0;
int quinta_dosagem_personalizada_3 = 0;
int sexta_dosagem_personalizada_3 = 0;
int sabado_dosagem_personalizada_3 = 0;
int domingo_dosagem_personalizada_3 = 0;
int quantidade_dose_dosadora_1_personalizada = 0;
int quantidade_dose_dosadora_2_personalizada = 0;
int quantidade_dose_dosadora_3_personalizada = 0;
int quantidade_dose_dosadora_1_automatica = 0;
int quantidade_dose_dosadora_2_automatica = 0;
int quantidade_dose_dosadora_3_automatica = 0;
int hora_inicial_dosagem_automatica_1 = 0;
int minuto_inicial_dosagem_automatica_1 = 0;
int hora_final_dosagem_automatica_1 = 0;
int minuto_final_dosagem_automatica_1 = 0;
int hora_inicial_dosagem_automatica_2 = 0;
int minuto_inicial_dosagem_automatica_2 = 0;
int hora_final_dosagem_automatica_2 = 0;
int minuto_final_dosagem_automatica_2 = 0;
int hora_inicial_dosagem_automatica_3 = 0;
int minuto_inicial_dosagem_automatica_3 = 0;
int hora_final_dosagem_automatica_3 = 0;
int minuto_final_dosagem_automatica_3 = 0;

//*****************************************************************************************
//************************** Variaveis temporarias das dosadoras **************************
//*****************************************************************************************
float fator_calib_dosadora_1_temp2;
float fator_calib_dosadora_2_temp2;
float fator_calib_dosadora_3_temp2;
float dose_dosadora_1_personalizada_temp2;
float dose_dosadora_2_personalizada_temp2;
float dose_dosadora_3_personalizada_temp2;
float dose_dosadora_1_automatica_temp2;
float dose_dosadora_2_automatica_temp2;
float dose_dosadora_3_automatica_temp2;
float dose_dosadora_1_manual_temp2;
float dose_dosadora_2_manual_temp2;
float dose_dosadora_3_manual_temp2;
int temp2hora_inicial_dosagem_personalizada_1;
int temp2minuto_inicial_dosagem_personalizada_1;
int temp2hora_final_dosagem_personalizada_1;
int temp2minuto_final_dosagem_personalizada_1;
int temp2segunda_dosagem_personalizada_1;
int temp2terca_dosagem_personalizada_1;
int temp2quarta_dosagem_personalizada_1;
int temp2quinta_dosagem_personalizada_1;
int temp2sexta_dosagem_personalizada_1;
int temp2sabado_dosagem_personalizada_1;
int temp2domingo_dosagem_personalizada_1;
int temp2hora_inicial_dosagem_personalizada_2;
int temp2minuto_inicial_dosagem_personalizada_2;
int temp2hora_final_dosagem_personalizada_2;
int temp2minuto_final_dosagem_personalizada_2;
int temp2segunda_dosagem_personalizada_2;
int temp2terca_dosagem_personalizada_2;
int temp2quarta_dosagem_personalizada_2;
int temp2quinta_dosagem_personalizada_2;
int temp2sexta_dosagem_personalizada_2;
int temp2sabado_dosagem_personalizada_2;
int temp2domingo_dosagem_personalizada_2;
int temp2hora_inicial_dosagem_personalizada_3;
int temp2minuto_inicial_dosagem_personalizada_3;
int temp2hora_final_dosagem_personalizada_3;
int temp2minuto_final_dosagem_personalizada_3;
int temp2segunda_dosagem_personalizada_3;
int temp2terca_dosagem_personalizada_3;
int temp2quarta_dosagem_personalizada_3;
int temp2quinta_dosagem_personalizada_3;
int temp2sexta_dosagem_personalizada_3;
int temp2sabado_dosagem_personalizada_3;
int temp2domingo_dosagem_personalizada_3;
int quantidade_dose_dosadora_1_personalizada_temp2;
int quantidade_dose_dosadora_2_personalizada_temp2;
int quantidade_dose_dosadora_3_personalizada_temp2;
int quantidade_dose_dosadora_1_automatica_temp2;
int quantidade_dose_dosadora_2_automatica_temp2;
int quantidade_dose_dosadora_3_automatica_temp2;
int modo_personalizado_on_1_temp2;
int modo_automatico_on_1_temp2;
int modo_personalizado_on_2_temp2;
int modo_automatico_on_2_temp2;
int modo_personalizado_on_3_temp2;
int modo_automatico_on_3_temp2;
int hora_inicial_dosagem_automatica_1_temp2;
int minuto_inicial_dosagem_automatica_1_temp2;
int hora_final_dosagem_automatica_1_temp2;
int minuto_final_dosagem_automatica_1_temp2;
int hora_inicial_dosagem_automatica_2_temp2;
int minuto_inicial_dosagem_automatica_2_temp2;
int hora_final_dosagem_automatica_2_temp2;
int minuto_final_dosagem_automatica_2_temp2;
int hora_inicial_dosagem_automatica_3_temp2;
int minuto_inicial_dosagem_automatica_3_temp2;
int hora_final_dosagem_automatica_3_temp2;
int minuto_final_dosagem_automatica_3_temp2;

//*****************************************************************************************
//************************** Variaveis de controle da potencia dos leds *******************
//*****************************************************************************************
byte bled[96] = {                       // Potencia de saida dos leds azuis 255 = 100% da potencia
  12, 12, 12, 12, 12, 12, 12, 12,       // 0 e 2
  12, 12, 12, 12, 12, 12, 12, 12,       // 2 e 4
  12, 12, 12, 12, 12, 21, 30, 39,       // 4 e 6
  48, 57, 66, 75, 84, 93, 102, 111,     // 6 e 8 
  120, 129, 138, 147, 156, 165, 174, 183, // 8 e 10
  192, 201, 210, 219, 228, 237, 246, 255, // 10 e 12
  255, 246, 237, 228, 219, 210, 201, 192, // 12 e 14
  183, 174, 165, 156, 147, 138, 129, 120,  // 14 e 16
  111, 102, 93, 84, 75, 66, 57, 48,       // 16 e 18
  39, 30, 21, 12, 12, 12, 12, 12,         // 18 a 20
  12, 12, 12, 12, 12, 12, 12, 12,         // 20 e 22
  12, 12, 12, 12, 12, 12, 12, 12          // 22 a 24
};  

byte wled[96] = {                         //Potencia de saida dos leds brancos 255 = 100% da potencia
  12, 12, 12, 12, 12, 12, 12, 12,         // 0 e 2
  12, 12, 12, 12, 12, 12, 12, 12,          // 2 e 4
  12, 12, 12, 12, 12, 21, 30, 39,          // 4 e 6
  48, 57, 66, 75, 84, 93, 102, 111,        // 6 e 8 
  120, 129, 138, 147, 156, 165, 174, 183,  // 8 e 10
  192, 201, 210, 219, 228, 237, 246, 255,  // 10 e 12
  255, 246, 237, 228, 219, 210, 201, 192,  // 12 e 14
  183, 174, 165, 156, 147, 138, 129, 120,  // 14 e 16
  111, 102, 93, 84, 75, 66, 57, 48,        // 16 e 18
  39, 30, 21, 12, 12, 12, 12, 12,          //18 a 20
  12, 12, 12, 12, 12, 12, 12, 12,         // 20 e 22
  12, 12, 12, 12, 12, 12, 12, 12           // 22 a 24
};
byte tled[96];

