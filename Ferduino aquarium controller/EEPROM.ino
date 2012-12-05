//**********************************************************************************************
//************************ Funcões EEPROM ******************************************************
//**********************************************************************************************
struct config_t                              // Temperatura
{
  int tempset;
  int tempoff;
  int tempalarm;
} 
tempSettings;

struct config_PHR                          // PH do reator
{
  int PHRset;
  int PHRoff;
  int PHRalarm;
} 
PHRSettings;

struct config_PHA                         // PH do aquario
{
  int PHAset;
  int PHAoff;
  int PHAalarm;
} 
PHASettings;

struct config_ORP                        // ORP
{
  int ORPset;
  int ORPoff;
  int ORPalarm;
} 
ORPSettings;

struct config_DEN                        // Densidade
{
  int DENset;
  int DENoff;
  int DENalarm;
} 
DENSettings;

struct config_tpa                       // TPA automatica
{
  int temphora;
  int tempminuto;
  int tempduracaomaximatpa;
  int tempsegunda;
  int tempterca;
  int tempquarta;
  int tempquinta;
  int tempsexta;
  int tempsabado;
  int tempdomingo;
} 
tpaconfig;

struct config_dos
{
  int fator_calib_dosadora_1_temp;
  int fator_calib_dosadora_2_temp;
  int fator_calib_dosadora_3_temp;
  int dose_dosadora_1_personalizada_temp;
  int dose_dosadora_2_personalizada_temp;
  int dose_dosadora_3_personalizada_temp;
  int dose_dosadora_1_automatica_temp;
  int dose_dosadora_2_automatica_temp;
  int dose_dosadora_3_automatica_temp;
  int hora_inicial_dosagem_personalizada_1_temp; 
  int minuto_inicial_dosagem_personalizada_1_temp;
  int hora_final_dosagem_personalizada_1_temp; 
  int minuto_final_dosagem_personalizada_1_temp; 
  int segunda_dosagem_personalizada_1_temp; 
  int terca_dosagem_personalizada_1_temp; 
  int quarta_dosagem_personalizada_1_temp; 
  int quinta_dosagem_personalizada_1_temp; 
  int sexta_dosagem_personalizada_1_temp; 
  int sabado_dosagem_personalizada_1_temp; 
  int domingo_dosagem_personalizada_1_temp;
  int hora_inicial_dosagem_personalizada_2_temp; 
  int minuto_inicial_dosagem_personalizada_2_temp;
  int hora_final_dosagem_personalizada_2_temp; 
  int minuto_final_dosagem_personalizada_2_temp; 
  int segunda_dosagem_personalizada_2_temp; 
  int terca_dosagem_personalizada_2_temp; 
  int quarta_dosagem_personalizada_2_temp; 
  int quinta_dosagem_personalizada_2_temp; 
  int sexta_dosagem_personalizada_2_temp; 
  int sabado_dosagem_personalizada_2_temp; 
  int domingo_dosagem_personalizada_2_temp;
  int hora_inicial_dosagem_personalizada_3_temp; 
  int minuto_inicial_dosagem_personalizada_3_temp;
  int hora_final_dosagem_personalizada_3_temp; 
  int minuto_final_dosagem_personalizada_3_temp; 
  int segunda_dosagem_personalizada_3_temp; 
  int terca_dosagem_personalizada_3_temp; 
  int quarta_dosagem_personalizada_3_temp; 
  int quinta_dosagem_personalizada_3_temp; 
  int sexta_dosagem_personalizada_3_temp; 
  int sabado_dosagem_personalizada_3_temp; 
  int domingo_dosagem_personalizada_3_temp;
  int quantidade_dose_dosadora_1_personalizada_temp;
  int quantidade_dose_dosadora_2_personalizada_temp;
  int quantidade_dose_dosadora_3_personalizada_temp;
  int quantidade_dose_dosadora_1_automatica_temp;
  int quantidade_dose_dosadora_2_automatica_temp;
  int quantidade_dose_dosadora_3_automatica_temp;
  int modo_personalizado_on_1_temp;
  int modo_automatico_on_1_temp;
  int modo_personalizado_on_2_temp;
  int modo_automatico_on_2_temp;
  int modo_personalizado_on_3_temp;
  int modo_automatico_on_3_temp;
  int hora_inicial_dosagem_automatica_1_temp; 
  int minuto_inicial_dosagem_automatica_1_temp;
  int hora_final_dosagem_automatica_1_temp; 
  int minuto_final_dosagem_automatica_1_temp;
  int hora_inicial_dosagem_automatica_2_temp; 
  int minuto_inicial_dosagem_automatica_2_temp;
  int hora_final_dosagem_automatica_2_temp; 
  int minuto_final_dosagem_automatica_2_temp;  
  int hora_inicial_dosagem_automatica_3_temp; 
  int minuto_inicial_dosagem_automatica_3_temp;
  int hora_final_dosagem_automatica_3_temp; 
  int minuto_final_dosagem_automatica_3_temp;
}
dosaconfig;

void SaveLEDToEEPROM()                  
{
  EEPROM.write(0, 123);         //to determine if data available in EEPROM
  for (int i=1; i<97; i++)  {
    EEPROM.write(i, wled[i]);
    EEPROM.write(i+96, bled[i]);
  } 
}

void SaveTempToEEPROM()
{
  tempSettings.tempset = int(setTempC*10);
  tempSettings.tempoff = int(offTempC*10);
  tempSettings.tempalarm = int(alarmTempC*10);
  EEPROM_writeAnything(194, tempSettings);
}

void SalvartpaEEPROM()
{
  tpaconfig.temphora = int(hora);
  tpaconfig.tempminuto = int(minuto);
  tpaconfig.tempduracaomaximatpa = int(duracaomaximatpa);
  tpaconfig.tempsegunda = int(segunda);
  tpaconfig.tempterca = int(terca);
  tpaconfig.tempquarta = int(quarta);
  tpaconfig.tempquinta = int(quinta);
  tpaconfig.tempsexta = int(sexta);
  tpaconfig.tempsabado = int(sabado);
  tpaconfig.tempdomingo = int(domingo);
  EEPROM_writeAnything(200, tpaconfig);
}

void SavePHRToEEPROM()
{
  PHRSettings.PHRset = int(setPHR*10);
  PHRSettings.PHRoff = int(offPHR*10);
  PHRSettings.PHRalarm = int(alarmPHR*10);
  EEPROM_writeAnything(220, PHRSettings);
}

void SaveORPToEEPROM()
{
  ORPSettings.ORPset = int(setORP);
  ORPSettings.ORPoff = int(offORP);
  ORPSettings.ORPalarm = int(alarmORP);
  EEPROM_writeAnything(226, ORPSettings);
}

void SavePHAToEEPROM()
{
  PHASettings.PHAset = int(setPHA*10);
  PHASettings.PHAoff = int(offPHA*10);
  PHASettings.PHAalarm = int(alarmPHA*10);
  EEPROM_writeAnything(232, PHASettings);
}

void SaveDENToEEPROM()
{
  DENSettings.DENset = int(setDEN-1000);
  DENSettings.DENoff = int(offDEN);
  DENSettings.DENalarm = int(alarmDEN);
  EEPROM_writeAnything(238, DENSettings);

}

void Salvar_dosadora_EEPROM()
{
  dosaconfig.fator_calib_dosadora_1_temp = int (fator_calib_dosadora_1*10);
  dosaconfig.fator_calib_dosadora_2_temp = int (fator_calib_dosadora_2*10);
  dosaconfig.fator_calib_dosadora_3_temp = int (fator_calib_dosadora_3*10);
  dosaconfig.dose_dosadora_1_personalizada_temp = int(dose_dosadora_1_personalizada*10);
  dosaconfig.dose_dosadora_2_personalizada_temp = int(dose_dosadora_2_personalizada*10);
  dosaconfig.dose_dosadora_3_personalizada_temp = int(dose_dosadora_3_personalizada*10);
  dosaconfig.dose_dosadora_1_automatica_temp = int(dose_dosadora_1_automatica*10);
  dosaconfig.dose_dosadora_2_automatica_temp = int(dose_dosadora_2_automatica*10);
  dosaconfig.dose_dosadora_3_automatica_temp = int(dose_dosadora_3_automatica*10);
  dosaconfig.hora_inicial_dosagem_personalizada_1_temp = int(hora_inicial_dosagem_personalizada_1);
  dosaconfig.minuto_inicial_dosagem_personalizada_1_temp = int(minuto_inicial_dosagem_personalizada_1); 
  dosaconfig.hora_final_dosagem_personalizada_1_temp = int(hora_final_dosagem_personalizada_1);
  dosaconfig.minuto_final_dosagem_personalizada_1_temp = int(minuto_final_dosagem_personalizada_1);
  dosaconfig.segunda_dosagem_personalizada_1_temp = int(segunda_dosagem_personalizada_1);
  dosaconfig.terca_dosagem_personalizada_1_temp = int(terca_dosagem_personalizada_1);
  dosaconfig.quarta_dosagem_personalizada_1_temp = int(quarta_dosagem_personalizada_1);
  dosaconfig.quinta_dosagem_personalizada_1_temp = int(quinta_dosagem_personalizada_1);
  dosaconfig.sexta_dosagem_personalizada_1_temp = int(sexta_dosagem_personalizada_1);
  dosaconfig.sabado_dosagem_personalizada_1_temp = int(sabado_dosagem_personalizada_1);
  dosaconfig.domingo_dosagem_personalizada_1_temp = int(domingo_dosagem_personalizada_1);
  dosaconfig.hora_inicial_dosagem_personalizada_2_temp = int(hora_inicial_dosagem_personalizada_2);
  dosaconfig.minuto_inicial_dosagem_personalizada_2_temp = int(minuto_inicial_dosagem_personalizada_2); 
  dosaconfig.hora_final_dosagem_personalizada_2_temp = int(hora_final_dosagem_personalizada_2);
  dosaconfig.minuto_final_dosagem_personalizada_2_temp = int(minuto_final_dosagem_personalizada_2);
  dosaconfig.segunda_dosagem_personalizada_2_temp = int(segunda_dosagem_personalizada_2);
  dosaconfig.terca_dosagem_personalizada_2_temp = int(terca_dosagem_personalizada_2);
  dosaconfig.quarta_dosagem_personalizada_2_temp = int(quarta_dosagem_personalizada_2);
  dosaconfig.quinta_dosagem_personalizada_2_temp = int(quinta_dosagem_personalizada_2);
  dosaconfig.sexta_dosagem_personalizada_2_temp = int(sexta_dosagem_personalizada_2);
  dosaconfig.sabado_dosagem_personalizada_2_temp = int(sabado_dosagem_personalizada_2);
  dosaconfig.domingo_dosagem_personalizada_2_temp = int(domingo_dosagem_personalizada_2);
  dosaconfig.hora_inicial_dosagem_personalizada_3_temp = int(hora_inicial_dosagem_personalizada_3);
  dosaconfig.minuto_inicial_dosagem_personalizada_3_temp = int(minuto_inicial_dosagem_personalizada_3); 
  dosaconfig.hora_final_dosagem_personalizada_3_temp = int(hora_final_dosagem_personalizada_3);
  dosaconfig.minuto_final_dosagem_personalizada_3_temp = int(minuto_final_dosagem_personalizada_3);
  dosaconfig.segunda_dosagem_personalizada_3_temp = int(segunda_dosagem_personalizada_3);
  dosaconfig.terca_dosagem_personalizada_3_temp = int(terca_dosagem_personalizada_3);
  dosaconfig.quarta_dosagem_personalizada_3_temp = int(quarta_dosagem_personalizada_3);
  dosaconfig.quinta_dosagem_personalizada_3_temp = int(quinta_dosagem_personalizada_3);
  dosaconfig.sexta_dosagem_personalizada_3_temp = int(sexta_dosagem_personalizada_3);
  dosaconfig.sabado_dosagem_personalizada_3_temp = int(sabado_dosagem_personalizada_3);
  dosaconfig.domingo_dosagem_personalizada_3_temp = int(domingo_dosagem_personalizada_3);
  dosaconfig.quantidade_dose_dosadora_1_personalizada_temp = int(quantidade_dose_dosadora_1_personalizada);
  dosaconfig.quantidade_dose_dosadora_2_personalizada_temp = int(quantidade_dose_dosadora_2_personalizada);
  dosaconfig.quantidade_dose_dosadora_3_personalizada_temp = int(quantidade_dose_dosadora_3_personalizada);
  dosaconfig.quantidade_dose_dosadora_1_automatica_temp = int(quantidade_dose_dosadora_1_automatica);
  dosaconfig.quantidade_dose_dosadora_2_automatica_temp = int(quantidade_dose_dosadora_2_automatica);
  dosaconfig.quantidade_dose_dosadora_3_automatica_temp = int(quantidade_dose_dosadora_3_automatica);
  dosaconfig.modo_personalizado_on_1_temp = int (modo_personalizado_on_1);
  dosaconfig.modo_automatico_on_1_temp = int (modo_automatico_on_1);
  dosaconfig.modo_personalizado_on_2_temp = int (modo_personalizado_on_2);
  dosaconfig.modo_automatico_on_2_temp = int (modo_automatico_on_2);
  dosaconfig.modo_personalizado_on_3_temp = int (modo_personalizado_on_3);
  dosaconfig.modo_automatico_on_3_temp = int (modo_automatico_on_3);
  dosaconfig.hora_inicial_dosagem_automatica_1_temp = int(hora_inicial_dosagem_automatica_1);
  dosaconfig.minuto_inicial_dosagem_automatica_1_temp = int(minuto_inicial_dosagem_automatica_1); 
  dosaconfig.hora_final_dosagem_automatica_1_temp = int(hora_final_dosagem_automatica_1);
  dosaconfig.minuto_final_dosagem_automatica_1_temp = int(minuto_final_dosagem_automatica_1);
  dosaconfig.hora_inicial_dosagem_automatica_2_temp = int(hora_inicial_dosagem_automatica_2);
  dosaconfig.minuto_inicial_dosagem_automatica_2_temp = int(minuto_inicial_dosagem_automatica_2); 
  dosaconfig.hora_final_dosagem_automatica_2_temp = int(hora_final_dosagem_automatica_2);
  dosaconfig.minuto_final_dosagem_automatica_2_temp = int(minuto_final_dosagem_automatica_2);
  dosaconfig.hora_inicial_dosagem_automatica_3_temp = int(hora_inicial_dosagem_automatica_3);
  dosaconfig.minuto_inicial_dosagem_automatica_3_temp = int(minuto_inicial_dosagem_automatica_3); 
  dosaconfig.hora_final_dosagem_automatica_3_temp = int(hora_final_dosagem_automatica_3);
  dosaconfig.minuto_final_dosagem_automatica_3_temp = int(minuto_final_dosagem_automatica_3);
  EEPROM_writeAnything(244, dosaconfig);
}

void ReadFromEEPROM()
{
  int k = EEPROM.read(0);
  //char tempString[3];
  if (k==123) {
    for (int i=1; i<89; i++)  {
      wled[i] = EEPROM.read(i);
      bled[i] = EEPROM.read(i+88);
    }  
  }

  EEPROM_readAnything(194, tempSettings);  
  setTempC = tempSettings.tempset;
  setTempC /=10;
  offTempC = tempSettings.tempoff;
  offTempC /=10;
  alarmTempC = tempSettings.tempalarm;
  alarmTempC /= 10;
}

void lertpaEEPROM()
{
  //  char tpaString[9];
  EEPROM_readAnything(200, tpaconfig);  
  hora = tpaconfig.temphora;
  minuto = tpaconfig.tempminuto;
  duracaomaximatpa = tpaconfig.tempduracaomaximatpa;
  segunda = tpaconfig.tempsegunda;
  terca = tpaconfig.tempterca;
  quarta = tpaconfig.tempquarta;
  quinta = tpaconfig.tempquinta;
  sexta = tpaconfig.tempsexta;
  sabado = tpaconfig.tempsabado;
  domingo = tpaconfig.tempdomingo;
}

void lerPHREEPROM()
{
  EEPROM_readAnything(220, PHRSettings);  
  setPHR = PHRSettings.PHRset;
  setPHR /=10;
  offPHR = PHRSettings.PHRoff;
  offPHR /=10;
  alarmPHR = PHRSettings.PHRalarm;
  alarmPHR /= 10;
}

void lerORPEEPROM()
{
  EEPROM_readAnything(226, ORPSettings);  
  setORP = ORPSettings.ORPset;
  offORP = ORPSettings.ORPoff;
  alarmORP = ORPSettings.ORPalarm;
}

void lerPHAEEPROM()
{
  EEPROM_readAnything(232, PHASettings);  
  setPHA = PHASettings.PHAset;
  setPHA /=10;
  offPHA = PHASettings.PHAoff;
  offPHA /=10;
  alarmPHA = PHASettings.PHAalarm;
  alarmPHA /= 10;
}

void lerDENEEPROM()
{
  EEPROM_readAnything(238, DENSettings);  
  setDEN = DENSettings.DENset;
  setDEN +=1000;
  offDEN = DENSettings.DENoff;
  alarmDEN = DENSettings.DENalarm;
}

void ler_dosadora_EEPROM()
{
  EEPROM_readAnything(244,dosaconfig);
  fator_calib_dosadora_1 = dosaconfig.fator_calib_dosadora_1_temp;
  fator_calib_dosadora_1 /=10;
  fator_calib_dosadora_2 = dosaconfig.fator_calib_dosadora_2_temp;
  fator_calib_dosadora_2 /=10;
  fator_calib_dosadora_3 = dosaconfig.fator_calib_dosadora_3_temp;
  fator_calib_dosadora_3 /=10;
  dose_dosadora_1_personalizada = dosaconfig.dose_dosadora_1_personalizada_temp;
  dose_dosadora_1_personalizada /= 10;
  dose_dosadora_2_personalizada = dosaconfig.dose_dosadora_2_personalizada_temp;
  dose_dosadora_2_personalizada /= 10;
  dose_dosadora_3_personalizada = dosaconfig.dose_dosadora_3_personalizada_temp; 
  dose_dosadora_3_personalizada /= 10;
  dose_dosadora_1_automatica = dosaconfig.dose_dosadora_1_automatica_temp;
  dose_dosadora_1_automatica /=10; 
  dose_dosadora_2_automatica = dosaconfig.dose_dosadora_2_automatica_temp; 
  dose_dosadora_2_automatica /=10; 
  dose_dosadora_3_automatica = dosaconfig.dose_dosadora_3_automatica_temp; 
  dose_dosadora_3_automatica /=10;
  hora_inicial_dosagem_personalizada_1 = dosaconfig.hora_inicial_dosagem_personalizada_1_temp;
  minuto_inicial_dosagem_personalizada_1 = dosaconfig.minuto_inicial_dosagem_personalizada_1_temp;
  hora_final_dosagem_personalizada_1 = dosaconfig.hora_final_dosagem_personalizada_1_temp;  
  minuto_final_dosagem_personalizada_1 = dosaconfig.minuto_final_dosagem_personalizada_1_temp; 
  segunda_dosagem_personalizada_1 = dosaconfig.segunda_dosagem_personalizada_1_temp; 
  terca_dosagem_personalizada_1 = dosaconfig.terca_dosagem_personalizada_1_temp; 
  quarta_dosagem_personalizada_1 = dosaconfig.quarta_dosagem_personalizada_1_temp;
  quinta_dosagem_personalizada_1 = dosaconfig.quinta_dosagem_personalizada_1_temp;
  sexta_dosagem_personalizada_1  = dosaconfig.sexta_dosagem_personalizada_1_temp;
  sabado_dosagem_personalizada_1 = dosaconfig.sabado_dosagem_personalizada_1_temp;
  domingo_dosagem_personalizada_1 = dosaconfig.domingo_dosagem_personalizada_1_temp;
  hora_inicial_dosagem_personalizada_2 = dosaconfig.hora_inicial_dosagem_personalizada_2_temp;
  minuto_inicial_dosagem_personalizada_2 = dosaconfig.minuto_inicial_dosagem_personalizada_2_temp;
  hora_final_dosagem_personalizada_2 = dosaconfig.hora_final_dosagem_personalizada_2_temp;  
  minuto_final_dosagem_personalizada_2 = dosaconfig.minuto_final_dosagem_personalizada_2_temp; 
  segunda_dosagem_personalizada_2 = dosaconfig.segunda_dosagem_personalizada_2_temp; 
  terca_dosagem_personalizada_2 = dosaconfig.terca_dosagem_personalizada_2_temp; 
  quarta_dosagem_personalizada_2 = dosaconfig.quarta_dosagem_personalizada_2_temp;
  quinta_dosagem_personalizada_2 = dosaconfig.quinta_dosagem_personalizada_2_temp;
  sexta_dosagem_personalizada_2  = dosaconfig.sexta_dosagem_personalizada_2_temp;
  sabado_dosagem_personalizada_2 = dosaconfig.sabado_dosagem_personalizada_2_temp;
  domingo_dosagem_personalizada_2 = dosaconfig.domingo_dosagem_personalizada_2_temp;
  hora_inicial_dosagem_personalizada_3 = dosaconfig.hora_inicial_dosagem_personalizada_3_temp;
  minuto_inicial_dosagem_personalizada_3 = dosaconfig.minuto_inicial_dosagem_personalizada_3_temp;
  hora_final_dosagem_personalizada_3 = dosaconfig.hora_final_dosagem_personalizada_3_temp;  
  minuto_final_dosagem_personalizada_3 = dosaconfig.minuto_final_dosagem_personalizada_3_temp; 
  segunda_dosagem_personalizada_3 = dosaconfig.segunda_dosagem_personalizada_3_temp; 
  terca_dosagem_personalizada_3 = dosaconfig.terca_dosagem_personalizada_3_temp; 
  quarta_dosagem_personalizada_3 = dosaconfig.quarta_dosagem_personalizada_3_temp;
  quinta_dosagem_personalizada_3 = dosaconfig.quinta_dosagem_personalizada_3_temp;
  sexta_dosagem_personalizada_3  = dosaconfig.sexta_dosagem_personalizada_3_temp;
  sabado_dosagem_personalizada_3 = dosaconfig.sabado_dosagem_personalizada_3_temp;
  domingo_dosagem_personalizada_3 = dosaconfig.domingo_dosagem_personalizada_3_temp;
  quantidade_dose_dosadora_1_personalizada = dosaconfig.quantidade_dose_dosadora_1_personalizada_temp;
  quantidade_dose_dosadora_2_personalizada = dosaconfig.quantidade_dose_dosadora_2_personalizada_temp;
  quantidade_dose_dosadora_3_personalizada = dosaconfig.quantidade_dose_dosadora_3_personalizada_temp;
  quantidade_dose_dosadora_1_automatica = dosaconfig.quantidade_dose_dosadora_1_automatica_temp;
  quantidade_dose_dosadora_2_automatica = dosaconfig.quantidade_dose_dosadora_2_automatica_temp;
  quantidade_dose_dosadora_3_automatica = dosaconfig.quantidade_dose_dosadora_3_automatica_temp;
  modo_personalizado_on_1 = dosaconfig.modo_personalizado_on_1_temp;
  modo_automatico_on_1 = dosaconfig.modo_automatico_on_1_temp;
  modo_personalizado_on_2 = dosaconfig.modo_personalizado_on_2_temp;
  modo_automatico_on_2 = dosaconfig.modo_automatico_on_2_temp;
  modo_personalizado_on_3 = dosaconfig.modo_personalizado_on_3_temp;
  modo_automatico_on_3 = dosaconfig.modo_automatico_on_3_temp;
  hora_inicial_dosagem_automatica_1 = dosaconfig.hora_inicial_dosagem_automatica_1_temp;
  minuto_inicial_dosagem_automatica_1 = dosaconfig.minuto_inicial_dosagem_automatica_1_temp;
  hora_final_dosagem_automatica_1 = dosaconfig.hora_final_dosagem_automatica_1_temp;  
  minuto_final_dosagem_automatica_1 = dosaconfig.minuto_final_dosagem_automatica_1_temp;
  hora_inicial_dosagem_automatica_2 = dosaconfig.hora_inicial_dosagem_automatica_2_temp;
  minuto_inicial_dosagem_automatica_2 = dosaconfig.minuto_inicial_dosagem_automatica_2_temp;
  hora_final_dosagem_automatica_2 = dosaconfig.hora_final_dosagem_automatica_2_temp;  
  minuto_final_dosagem_automatica_2 = dosaconfig.minuto_final_dosagem_automatica_2_temp;
  hora_inicial_dosagem_automatica_3 = dosaconfig.hora_inicial_dosagem_automatica_3_temp;
  minuto_inicial_dosagem_automatica_3 = dosaconfig.minuto_inicial_dosagem_automatica_3_temp;
  hora_final_dosagem_automatica_3 = dosaconfig.hora_final_dosagem_automatica_3_temp;  
  minuto_final_dosagem_automatica_3 = dosaconfig.minuto_final_dosagem_automatica_3_temp;
}
