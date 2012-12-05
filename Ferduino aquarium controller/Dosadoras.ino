// Não existem
//---------------------------------------- Bomba dosadora 1 ---------------------- tela =22

//---------------------------------------- Bomba dosadora 2 ---------------------- tela =23

//---------------------------------------- Bomba dosadora 3 ---------------------- tela =24

//---------------------------------------- Bomba dosadora 4 ---------------------- tela =25

void check_dosagem_automatica_1()
{
  int16_t n;
  char buf[7];
  t = rtc.getTime();
  char oldminuto6;
  oldminuto6 = time6;
  time6 = t.min;
  int minutos_agora = (t.hour * 60) + t.min;

  digitalWrite (4, LOW);


  if (oldminuto6!=time6)
  {  
    if(modo_automatico_on_1 == 1)
    {
      file.open(&root, "HDA1.TXT", O_READ);
      while ((n = file.read(buf, sizeof(buf))) > 0)
      {
        minuto01 = atoi(buf);
        if(minuto01 == minutos_agora)
        {
          Serial.println("Dosando 1:");
          Serial.println(rtc.getTimeStr(FORMAT_LONG));
          tempo_dosagem_1 = map (((dose_dosadora_1_automatica/quantidade_dose_dosadora_1_automatica)*2), 0, fator_calib_dosadora_1, 0, 60000);
          tempo_dosagem_1 /= 2;                 
          digitalWrite(dosadora1, HIGH);
          delay(tempo_dosagem_1);
          digitalWrite(dosadora1, LOW);
          Serial.println(rtc.getTimeStr(FORMAT_LONG));
        }
      }
      file.close();
      
    }
  }
  digitalWrite (4, HIGH);
}

void check_dosagem_automatica_2()
{
  int16_t n;
  char buf[7];
  minuto01 = 0;
  t = rtc.getTime();
  char oldminuto7;
  oldminuto7 = time7;
  time7 = t.min;
  int minutos_agora = (t.hour * 60) + t.min;

  digitalWrite (4, LOW);

  if (oldminuto7!=time7)
  {  
    if(modo_automatico_on_3 == 1)
    {
      file.open(&root, "HDA2.TXT", O_READ);
      while ((n = file.read(buf, sizeof(buf))) > 0)
      {
        minuto01 = atoi(buf);        
        if(minuto01 == minutos_agora)
        {
          Serial.println("Dosando 2:");
          Serial.println(rtc.getTimeStr(FORMAT_LONG));
          tempo_dosagem_1 = map (((dose_dosadora_2_automatica/quantidade_dose_dosadora_2_automatica)*2), 0, fator_calib_dosadora_2, 0, 60000);
          tempo_dosagem_1 /= 2;                 
          digitalWrite(dosadora2, HIGH);
          delay(tempo_dosagem_1);
          digitalWrite(dosadora2, LOW);
          Serial.println(rtc.getTimeStr(FORMAT_LONG));
        }
      }
      file.close();
      
    }
  }
  digitalWrite (4, HIGH);
}

void check_dosagem_automatica_3()
{
  int16_t n;
  char buf[7];
  minuto01 = 0;
  t = rtc.getTime();
  char oldminuto8;
  oldminuto8 = time8;
  time8 = t.min;
  int minutos_agora = (t.hour * 60) + t.min;

  digitalWrite (4, LOW);

  if (oldminuto8!=time8)
  {  

    if(modo_automatico_on_3 == 1)
    {
      file.open(&root, "HDA3.TXT", O_READ);
      while (n = file.read(buf, sizeof(buf) > 0))
      {
        minuto01 = atoi(buf);        
        if(minuto01 == minutos_agora)
        {
          Serial.println(rtc.getTimeStr(FORMAT_LONG));
          tempo_dosagem_1 = map (((dose_dosadora_3_automatica/quantidade_dose_dosadora_3_automatica)*2), 0, fator_calib_dosadora_3, 0, 60000);
          tempo_dosagem_1 /= 2;                 
          digitalWrite(dosadora3, HIGH);
          delay(tempo_dosagem_1);
          digitalWrite(dosadora3, LOW);          
          Serial.println("Dosando 3:");
          Serial.println(rtc.getTimeStr(FORMAT_LONG));
        }
      }
      file.close();
      
    }
  }
  digitalWrite (4, HIGH);
}

void check_dosagem_personalizada_1()
{
  int16_t n;
  char buf[7];
  minuto01 = 0;
  t = rtc.getTime();
  char oldminuto9;
  oldminuto9 = time9;
  time9 = t.min;
  int minutos_agora = (t.hour * 60) + t.min;

  digitalWrite (4, LOW);

  if (oldminuto9!=time9)
  {  

    if(modo_personalizado_on_1 == 1)
    {
      if(segunda_dosagem_personalizada_1 == t.dow)
      {
        file.open(&root, "HDP1.TXT", O_READ);
        while ((n = file.read(buf, sizeof(buf))) > 0)
        {
          minuto01 = atoi(buf);
          if(minuto01 == minutos_agora)
          {
            Serial.println("Dosando 1:");
            Serial.println(rtc.getTimeStr(FORMAT_LONG));
            tempo_dosagem_1 = map (((dose_dosadora_1_personalizada/quantidade_dose_dosadora_1_personalizada)*2), 0, fator_calib_dosadora_1, 0, 60000);
            tempo_dosagem_1 /= 2;                 
            digitalWrite(dosadora1, HIGH);
            delay(tempo_dosagem_1);
            digitalWrite(dosadora1, LOW);
            Serial.println(rtc.getTimeStr(FORMAT_LONG));
          }
        }
        file.close();
      }
      if(terca_dosagem_personalizada_1 == t.dow)
      {
        file.open(&root, "HDP1.TXT", O_READ);
        while ((n = file.read(buf, sizeof(buf))) > 0)
        {
          minuto01 = atoi(buf);
          if(minuto01 == minutos_agora)
          {
            Serial.println("Dosando 1:");
            Serial.println(rtc.getTimeStr(FORMAT_LONG));
            tempo_dosagem_1 = map (((dose_dosadora_1_personalizada/quantidade_dose_dosadora_1_personalizada)*2), 0, fator_calib_dosadora_1, 0, 60000);
            tempo_dosagem_1 /= 2;                 
            digitalWrite(dosadora1, HIGH);
            delay(tempo_dosagem_1);
            digitalWrite(dosadora1, LOW);
            Serial.println(rtc.getTimeStr(FORMAT_LONG));
          }
        }
        file.close();
        
      }
      if(quarta_dosagem_personalizada_1 == t.dow)
      {
        file.open(&root, "HDP1.TXT", O_READ);
        while ((n = file.read(buf, sizeof(buf))) > 0)
        {
          minuto01 = atoi(buf);
          if(minuto01 == minutos_agora)
          {
            Serial.println("Dosando 1:");
            Serial.println(rtc.getTimeStr(FORMAT_LONG));
            tempo_dosagem_1 = map (((dose_dosadora_1_personalizada/quantidade_dose_dosadora_1_personalizada)*2), 0, fator_calib_dosadora_1, 0, 60000);
            tempo_dosagem_1 /= 2;                 
            digitalWrite(dosadora1, HIGH);
            delay(tempo_dosagem_1);
            digitalWrite(dosadora1, LOW);
            Serial.println(rtc.getTimeStr(FORMAT_LONG));
          }
        }
        file.close();
        
      }
      if(quinta_dosagem_personalizada_1 == t.dow)
      {
        file.open(&root, "HDP1.TXT", O_READ);
        while ((n = file.read(buf, sizeof(buf))) > 0)
        {
          minuto01 = atoi(buf);
          if(minuto01 == minutos_agora)
          {
            Serial.println("Dosando 1:");
            Serial.println(rtc.getTimeStr(FORMAT_LONG));
            tempo_dosagem_1 = map (((dose_dosadora_1_personalizada/quantidade_dose_dosadora_1_personalizada)*2), 0, fator_calib_dosadora_1, 0, 60000);
            tempo_dosagem_1 /= 2;                 
            digitalWrite(dosadora1, HIGH);
            delay(tempo_dosagem_1);
            digitalWrite(dosadora1, LOW);
            Serial.println(rtc.getTimeStr(FORMAT_LONG));
          }
        }
        file.close();
        
      }
      if(sexta_dosagem_personalizada_1 == t.dow)
      {
        file.open(&root, "HDP1.TXT", O_READ);
        while ((n = file.read(buf, sizeof(buf))) > 0)
        {
          minuto01 = atoi(buf);
          if(minuto01 == minutos_agora)
          {
            Serial.println("Dosando 1:");
            Serial.println(rtc.getTimeStr(FORMAT_LONG));
            tempo_dosagem_1 = map (((dose_dosadora_1_personalizada/quantidade_dose_dosadora_1_personalizada)*2), 0, fator_calib_dosadora_1, 0, 60000);
            tempo_dosagem_1 /= 2;                 
            digitalWrite(dosadora1, HIGH);
            delay(tempo_dosagem_1);
            digitalWrite(dosadora1, LOW);
            Serial.println(rtc.getTimeStr(FORMAT_LONG));
          }
        }
        file.close();
        
      }
      if(sabado_dosagem_personalizada_1 == t.dow)
      {
        file.open(&root, "HDP1.TXT", O_READ);
        while ((n = file.read(buf, sizeof(buf))) > 0)
        {
          minuto01 = atoi(buf);
          if(minuto01 == minutos_agora)
          {
            Serial.println("Dosando 1:");
            Serial.println(rtc.getTimeStr(FORMAT_LONG));
            tempo_dosagem_1 = map (((dose_dosadora_1_personalizada/quantidade_dose_dosadora_1_personalizada)*2), 0, fator_calib_dosadora_1, 0, 60000);
            tempo_dosagem_1 /= 2;                 
            digitalWrite(dosadora1, HIGH);
            delay(tempo_dosagem_1);
            digitalWrite(dosadora1, LOW);
            Serial.println(rtc.getTimeStr(FORMAT_LONG));
          }
        }
        file.close();
        
      }
      if(domingo_dosagem_personalizada_1 == t.dow)
      {
        file.open(&root, "HDP1.TXT", O_READ);
        while ((n = file.read(buf, sizeof(buf))) > 0)
        {
          minuto01 = atoi(buf);
          if(minuto01 == minutos_agora)
          {
            Serial.println("Dosando 1:");
            Serial.println(rtc.getTimeStr(FORMAT_LONG));
            tempo_dosagem_1 = map (((dose_dosadora_1_personalizada/quantidade_dose_dosadora_1_personalizada)*2), 0, fator_calib_dosadora_1, 0, 60000);
            tempo_dosagem_1 /= 2;                 
            digitalWrite(dosadora1, HIGH);
            delay(tempo_dosagem_1);
            digitalWrite(dosadora1, LOW);
            Serial.println(rtc.getTimeStr(FORMAT_LONG));
          }
        }
        file.close();
        
      }
    }
  }
  digitalWrite (4, HIGH);
}

void check_dosagem_personalizada_2()
{
  int16_t n;
  char buf[7];
  minuto01 = 0;
  t = rtc.getTime();
  char oldminuto10;
  oldminuto10 = time10;
  time10 = t.min;
  int minutos_agora = (t.hour * 60) + t.min;

  digitalWrite (4, LOW);

  if (oldminuto10!=time10)
  {  
    if(modo_personalizado_on_2 == 1)
    {
      if(segunda_dosagem_personalizada_2 == t.dow)
      {
        file.open(&root, "HDP2.TXT", O_READ);
        while ((n = file.read(buf, sizeof(buf))) > 0)
        {
          minuto01 = atoi(buf);
          if(minuto01 == minutos_agora)
          {
            Serial.println("Dosando 2:");
            Serial.println(rtc.getTimeStr(FORMAT_LONG));
            tempo_dosagem_1 = map (((dose_dosadora_2_personalizada/quantidade_dose_dosadora_2_personalizada)*2), 0, fator_calib_dosadora_2, 0, 60000);
            tempo_dosagem_1 /= 2;                 
            digitalWrite(dosadora2, HIGH);
            delay(tempo_dosagem_1);
            digitalWrite(dosadora2, LOW);
            Serial.println(rtc.getTimeStr(FORMAT_LONG));
          }
        }
        file.close();
        
      }
      if(terca_dosagem_personalizada_2 == t.dow)
      {
        file.open(&root, "HDP2.TXT", O_READ);
        while ((n = file.read(buf, sizeof(buf))) > 0)
        {
          minuto01 = atoi(buf);
          if(minuto01 == minutos_agora)
          {
            Serial.println("Dosando 2:");
            Serial.println(rtc.getTimeStr(FORMAT_LONG));
            tempo_dosagem_1 = map (((dose_dosadora_2_personalizada/quantidade_dose_dosadora_2_personalizada)*2), 0, fator_calib_dosadora_2, 0, 60000);
            tempo_dosagem_1 /= 2;                 
            digitalWrite(dosadora2, HIGH);
            delay(tempo_dosagem_1);
            digitalWrite(dosadora2, LOW);
            Serial.println(rtc.getTimeStr(FORMAT_LONG));
          }
        }
        file.close();
      }
      if(quarta_dosagem_personalizada_2 == t.dow)
      {
        file.open(&root, "HDP2.TXT", O_READ);
        while ((n = file.read(buf, sizeof(buf))) > 0)
        {
          minuto01 = atoi(buf);
          if(minuto01 == minutos_agora)
          {
            Serial.println("Dosando 2:");
            Serial.println(rtc.getTimeStr(FORMAT_LONG));
            tempo_dosagem_1 = map (((dose_dosadora_2_personalizada/quantidade_dose_dosadora_2_personalizada)*2), 0, fator_calib_dosadora_2, 0, 60000);
            tempo_dosagem_1 /= 2;                 
            digitalWrite(dosadora2, HIGH);
            delay(tempo_dosagem_1);
            digitalWrite(dosadora2, LOW);
            Serial.println(rtc.getTimeStr(FORMAT_LONG));
          }
        }
        file.close();
      }
      if(quinta_dosagem_personalizada_2 == t.dow)
      {
        file.open(&root, "HDP2.TXT", O_READ);
        while ((n = file.read(buf, sizeof(buf))) > 0)
        {
          minuto01 = atoi(buf);
          if(minuto01 == minutos_agora)
          {
            Serial.println("Dosando 2:");
            Serial.println(rtc.getTimeStr(FORMAT_LONG));
            tempo_dosagem_1 = map (((dose_dosadora_2_personalizada/quantidade_dose_dosadora_2_personalizada)*2), 0, fator_calib_dosadora_2, 0, 60000);
            tempo_dosagem_1 /= 2;                 
            digitalWrite(dosadora2, HIGH);
            delay(tempo_dosagem_1);
            digitalWrite(dosadora2, LOW);
            Serial.println(rtc.getTimeStr(FORMAT_LONG));
          }
        }
        file.close();
      }
      if(sexta_dosagem_personalizada_2 == t.dow)
      {
        file.open(&root, "HDP2.TXT", O_READ);
        while ((n = file.read(buf, sizeof(buf))) > 0)
        {
          minuto01 = atoi(buf);
          if(minuto01 == minutos_agora)
          {
            Serial.println("Dosando 2:");
            Serial.println(rtc.getTimeStr(FORMAT_LONG));
            tempo_dosagem_1 = map (((dose_dosadora_2_personalizada/quantidade_dose_dosadora_2_personalizada)*2), 0, fator_calib_dosadora_2, 0, 60000);
            tempo_dosagem_1 /= 2;                 
            digitalWrite(dosadora2, HIGH);
            delay(tempo_dosagem_1);
            digitalWrite(dosadora2, LOW);
            Serial.println(rtc.getTimeStr(FORMAT_LONG));
          }
        }
        file.close();
        
      }
      if(sabado_dosagem_personalizada_2 == t.dow)
      {
        file.open(&root, "HDP2.TXT", O_READ);
        while ((n = file.read(buf, sizeof(buf))) > 0)
        {
          minuto01 = atoi(buf);
          if(minuto01 == minutos_agora)
          {
            Serial.println("Dosando 2:");
            Serial.println(rtc.getTimeStr(FORMAT_LONG));
            tempo_dosagem_1 = map (((dose_dosadora_2_personalizada/quantidade_dose_dosadora_2_personalizada)*2), 0, fator_calib_dosadora_2, 0, 60000);
            tempo_dosagem_1 /= 2;                 
            digitalWrite(dosadora2, HIGH);
            delay(tempo_dosagem_1);
            digitalWrite(dosadora2, LOW);
            Serial.println(rtc.getTimeStr(FORMAT_LONG));
          }
        }
        file.close();
        
      }
      if(domingo_dosagem_personalizada_2 == t.dow)
      {
        file.open(&root, "HDP2.TXT", O_READ);
        while ((n = file.read(buf, sizeof(buf))) > 0)
        {
          minuto01 = atoi(buf);
          if(minuto01 == minutos_agora)
          {
            Serial.println("Dosando 2:");
            Serial.println(rtc.getTimeStr(FORMAT_LONG));
            tempo_dosagem_1 = map (((dose_dosadora_2_personalizada/quantidade_dose_dosadora_2_personalizada)*2), 0, fator_calib_dosadora_2, 0, 60000);
            tempo_dosagem_1 /= 2;                 
            digitalWrite(dosadora2, HIGH);
            delay(tempo_dosagem_1);
            digitalWrite(dosadora2, LOW);
            Serial.println(rtc.getTimeStr(FORMAT_LONG));
          }
        }
        file.close();
        
      }
    }
  }
  digitalWrite (4, HIGH);
}

void check_dosagem_personalizada_3()
{
  int16_t n;
  char buf[7];
  minuto01 = 0;
  t = rtc.getTime();
  char oldminuto11;
  oldminuto11 = time11;
  time11 = t.min;
  int minutos_agora = (t.hour * 60) + t.min;

  digitalWrite (4, LOW);

  if (oldminuto11!=time11)
  {  
    if(modo_personalizado_on_3 == 1)
    {
      if(segunda_dosagem_personalizada_3 == t.dow)
      {
        file.open(&root, "HDP3.TXT", O_READ);
        while ((n = file.read(buf, sizeof(buf))) > 0)
        {
          minuto01 = atoi(buf);
          if(minuto01 == minutos_agora)
          {
            Serial.println("Dosando 3:");
            Serial.println(rtc.getTimeStr(FORMAT_LONG));
            tempo_dosagem_1 = map (((dose_dosadora_3_personalizada/quantidade_dose_dosadora_3_personalizada)*2), 0, fator_calib_dosadora_3, 0, 60000);
            tempo_dosagem_1 /= 2;                 
            digitalWrite(dosadora3, HIGH);
            delay(tempo_dosagem_1);
            digitalWrite(dosadora3, LOW);
            Serial.println(rtc.getTimeStr(FORMAT_LONG));
          }
        }
        file.close();
        
      }
      if(terca_dosagem_personalizada_3 == t.dow)
      {
        file.open(&root, "HDP3.TXT", O_READ);
        while ((n = file.read(buf, sizeof(buf))) > 0)
        {
          minuto01 = atoi(buf);
          if(minuto01 == minutos_agora)
          {
            Serial.println("Dosando 3:");
            Serial.println(rtc.getTimeStr(FORMAT_LONG));
            tempo_dosagem_1 = map (((dose_dosadora_3_personalizada/quantidade_dose_dosadora_3_personalizada)*2), 0, fator_calib_dosadora_3, 0, 60000);
            tempo_dosagem_1 /= 2;                 
            digitalWrite(dosadora3, HIGH);
            delay(tempo_dosagem_1);
            digitalWrite(dosadora3, LOW);
            Serial.println(rtc.getTimeStr(FORMAT_LONG));
          }
        }
        file.close();
        
      }
      if(quarta_dosagem_personalizada_3 == t.dow)
      {
        file.open(&root, "HDP3.TXT", O_READ);
        while ((n = file.read(buf, sizeof(buf))) > 0)
        {
          minuto01 = atoi(buf);
          if(minuto01 == minutos_agora)
          {
            Serial.println("Dosando 3:");
            Serial.println(rtc.getTimeStr(FORMAT_LONG));
            tempo_dosagem_1 = map (((dose_dosadora_3_personalizada/quantidade_dose_dosadora_3_personalizada)*2), 0, fator_calib_dosadora_3, 0, 60000);
            tempo_dosagem_1 /= 2;                 
            digitalWrite(dosadora3, HIGH);
            delay(tempo_dosagem_1);
            digitalWrite(dosadora3, LOW);
            Serial.println(rtc.getTimeStr(FORMAT_LONG));
          }
        }
        file.close();
        
      }
      if(quinta_dosagem_personalizada_3 == t.dow)
      {
        file.open(&root, "HDP3.TXT", O_READ);
        while ((n = file.read(buf, sizeof(buf))) > 0)
        {
          minuto01 = atoi(buf);
          if(minuto01 == minutos_agora)
          {
            Serial.println("Dosando 3:");
            Serial.println(rtc.getTimeStr(FORMAT_LONG));
            tempo_dosagem_1 = map (((dose_dosadora_3_personalizada/quantidade_dose_dosadora_3_personalizada)*2), 0, fator_calib_dosadora_3, 0, 60000);
            tempo_dosagem_1 /= 2;                 
            digitalWrite(dosadora3, HIGH);
            delay(tempo_dosagem_1);
            digitalWrite(dosadora3, LOW);
            Serial.println(rtc.getTimeStr(FORMAT_LONG));
          }
        }
        file.close();
        
      }
      if(sexta_dosagem_personalizada_3 == t.dow)
      {
        file.open(&root, "HDP3.TXT", O_READ);
        while ((n = file.read(buf, sizeof(buf))) > 0)
        {
          minuto01 = atoi(buf);
          if(minuto01 == minutos_agora)
          {
            Serial.println("Dosando 3:");
            Serial.println(rtc.getTimeStr(FORMAT_LONG));
            tempo_dosagem_1 = map (((dose_dosadora_3_personalizada/quantidade_dose_dosadora_3_personalizada)*2), 0, fator_calib_dosadora_3, 0, 60000);
            tempo_dosagem_1 /= 2;                 
            digitalWrite(dosadora3, HIGH);
            delay(tempo_dosagem_1);
            digitalWrite(dosadora3, LOW);
            Serial.println(rtc.getTimeStr(FORMAT_LONG));
          }
        }
        file.close();
        
      }
      if(sabado_dosagem_personalizada_3 == t.dow)
      {
        file.open(&root, "HDP3.TXT", O_READ);
        while ((n = file.read(buf, sizeof(buf))) > 0)
        {
          minuto01 = atoi(buf);
          if(minuto01 == minutos_agora)
          {
            Serial.println("Dosando 3:");
            Serial.println(rtc.getTimeStr(FORMAT_LONG));
            tempo_dosagem_1 = map (((dose_dosadora_3_personalizada/quantidade_dose_dosadora_3_personalizada)*2), 0, fator_calib_dosadora_3, 0, 60000);
            tempo_dosagem_1 /= 2;                 
            digitalWrite(dosadora3, HIGH);
            delay(tempo_dosagem_1);
            digitalWrite(dosadora3, LOW);
            Serial.println(rtc.getTimeStr(FORMAT_LONG));
          }
        }
        file.close();
        
      }
      if(domingo_dosagem_personalizada_3 == t.dow)
      {
        file.open(&root, "HDP3.TXT", O_READ);
        while ((n = file.read(buf, sizeof(buf))) > 0)
        {
          minuto01 = atoi(buf);
          if(minuto01 == minutos_agora)
          {
            Serial.println("Dosando 3:");
            Serial.println(rtc.getTimeStr(FORMAT_LONG));
            tempo_dosagem_1 = map (((dose_dosadora_3_personalizada/quantidade_dose_dosadora_3_personalizada)*2), 0, fator_calib_dosadora_3, 0, 60000);
            tempo_dosagem_1 /= 2;                 
            digitalWrite(dosadora3, HIGH);
            delay(tempo_dosagem_1);
            digitalWrite(dosadora3, LOW);
            Serial.println(rtc.getTimeStr(FORMAT_LONG));
          }
        }
        file.close();
        
      }
    }
  }
  digitalWrite (4, HIGH);
}

