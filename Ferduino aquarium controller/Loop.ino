//-----------------------main loop------------------------------
void loop()
{
  /*  int valor1=0;
   int valor2=0;
   int valor3=0;
   int valor4=0;
   int valor5=0;
   int valor6=0;
   
   valor1 = analogRead(sensor1);
   valor2 = analogRead(sensor2);
   valor3 = analogRead(sensor3);
   valor4 = analogRead(sensor4);
   valor5 = analogRead(sensor5);
   valor6 = analogRead(sensor6);*/

 if(Ethernet_Shield == true)
  {
    ether.packetLoop(ether.packetReceive());
  }

  if (myTouch.dataAvailable())  
  { 
    processMyTouch(); 
  }

  if(Stamps == true)
  {
    if((millis() - millis_antes) >= 120000)
    {
    millis_antes = millis();        
   parametros();
    }
  }
  if (millis() - previousMillis > 5000)    //check time, temp and LED levels every 5 s
  {
    previousMillis = millis();  
    t = rtc.getTime();
    checkTempC();
    min_cnt= (t.hour*60)+t.hour;
    LED_levels_output();
    reposicao_agua_doce();
    check_nivel();
    check_PH_reator();
    check_PH_aquario();
    check_densidade();
    check_ORP();
    check_alarme();

    if (dispScreen == 0)
    {
      mainScreen();    
    }
    
    /*
     Serial.println("Dia da semana");  
     Serial.println(rtc.getDOWStr()); 
     
     Serial.println("Horario");
     Serial.println(rtc.getTimeStr(FORMAT_LONG));

    Serial.print ("Memoria livre:");
    Serial.println (FreeRam());

     Serial.println("Sensor 1:");    
     Serial.println(valor1);
     
     Serial.println("Sensor 2:");
     Serial.println(valor2);
     
     Serial.println("Sensor 3:");
     Serial.println(valor3);
     
     Serial.println("Sensor 4:");
     Serial.println(valor4);
     
     Serial.println("Sensor 5:");    
     Serial.println(valor5);      
     
     Serial.println("Sensor 6:");
     Serial.println(valor6);
     
     Serial.println("marcadoriniciotpa:");
     Serial.println(marcadoriniciotpa);
     
     Serial.println("shiftedmillis:");
     Serial.println(shiftedmillis);
     
     Serial.println("Tempo:");
     Serial.println(tempo);
     
     if (digitalRead(bomba1Pin)==HIGH)
     {
     Serial.println("Bomba1: ligada");
     }
     else
     {
     Serial.println("Bomba1: desligada");
     }
     if (digitalRead(bomba2Pin)==HIGH)
     {
     Serial.println("Bomba2: ligada");
     }
     else
     {
     Serial.println("Bomba2: desligada");
     }
     if (digitalRead(bomba3Pin)==HIGH)
     {
     Serial.println("Bomba3: ligada");
     }
     else
     {
     Serial.println("Bomba3: desligada");
     }*/
  }
  checktpa();
  check_status();
  logtempgraf();
  logphagraf();
  logphrgraf();
  logdengraf();
  logorpgraf();
  
  
  if((Ethernet_Shield == true) && (tpa_em_andamento == false))
  {
    cosm ();
  }
  
  if (millis() - logtempminutoantes > 900000ul) //Grava parametros a cada 15 minutos no cartao SD.
  {
    logtempminutoantes = millis();
    logparametros();
  }
  check_dosagem_automatica_1();
  check_dosagem_personalizada_1();
  check_dosagem_automatica_2();
  check_dosagem_personalizada_2();
  check_dosagem_automatica_3();
  check_dosagem_personalizada_3();
} //-------------------end of main loop
