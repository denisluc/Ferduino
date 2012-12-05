//------------------------------------menu----------------------------------------------------------- tela =1
void menuScreen()
{

  printHeader("MENU");

  printButton("HORA E DATA", tanD[0], tanD[1], tanD[2], tanD[3]);
  printButton("TESTAR LED", tesT[0], tesT[1], tesT[2], tesT[3]);
  printButton("CONTROLE PARAM.", temC[0], temC[1], temC[2], temC[3]);
  printButton("GRAFICOS", graF[0], graF[1], graF[2], graF[3]);
  printButton("ALT. VALORES LED", ledW[0], ledW[1], ledW[2], ledW[3]);
  printButton("TPA AUTOMATICA", tpaA[0], tpaA[1], tpaA[2], tpaA[3]);
  printButton("DOSADORAS", dosA[0], dosA[1], dosA[2], dosA[3]);
  printButton("WAVEMAKER", wavM[0], wavM[1], wavM[2], wavM[3]);
  printButton("INICIO", iniC[0], iniC[1], iniC[2], iniC[3]);
}

// -------------------------Relogio------------------------------------------------------tela=2
void setClock()   
{
  t_temp = rtc.getTime();

  printHeader("ALTERAR HORA E DATA");

  printButton ("+", houU[0], houU[1], houU[2], houU[3], true);   //hour up
  printButton ("-", houD[0], houD[1], houD[2], houD[3], true);   //hour down

  printButton ("+", minU[0], minU[1], minU[2], minU[3], true);   //min up
  printButton ("-", minD[0], minD[1], minD[2], minD[3], true);   //min down 

  printButton ("+", segC[0], segC[1], segC[2], segC[3], true);   //segundo mais
  printButton ("-", segB[0], segB[1], segB[2], segB[3], true);   //segundo menos

  printButton ("+", yeaU[0], yeaU[1], yeaU[2], yeaU[3], true);    //year up
  printButton ("-", yeaD[0], yeaD[1], yeaD[2], yeaD[3], true);     //year down

  printButton ("-", dayD[0], dayD[1], dayD[2], dayD[3], true);     //day down
  printButton ("+", dayU[0], dayU[1], dayU[2], dayU[3], true);    //day up

  printButton ("+", monU[0], monU[1], monU[2], monU[3], true);    //month up
  printButton ("-", monD[0], monD[1], monD[2], monD[3], true);     //month down

  printButton("SALVAR", prOK[0], prOK[1], prOK[2], prOK[3]);
  printButton("INICIO", iniC[0], iniC[1], iniC[2], iniC[3]);
  printButton("MENU", menU[0], menU[1], menU[2], menU[3]);

  setFont(LARGE, 255, 255, 255, 0, 0, 0);

  if (t_temp.date==0)
  {
    t_temp.date=1;
    t_temp.mon=1;
    t_temp.year=2010;
    t_temp.dow=5;
    t_temp.hour=0;
    t_temp.min=0;
    t_temp.sec=0;
    ct=true;
    cd=true;
  }

  myGLCD.print("   :     ", 70, 48);  //fill over old time
  myGLCD.print("   :     ", 160, 48);  //fill over old time

  if (t_temp.hour<10)
  {
    myGLCD.printNumI(0, 70, 48);
    myGLCD.printNumI(t_temp.hour, 86, 48);
  }
  else
  {
    myGLCD.printNumI(t_temp.hour, 70, 48);
  } 
  if (t_temp.min<10)
  {
    myGLCD.printNumI(0, 160, 48);
    myGLCD.printNumI(t_temp.min, 176, 48);
  }
  else
  {
    myGLCD.printNumI(t_temp.min, 160, 48);
  } 
  if (t_temp.sec<10)
  {
    myGLCD.printNumI(0, 250, 48);
    myGLCD.printNumI(t_temp.sec, 266, 48);
  }
  else
  {
    myGLCD.printNumI(t_temp.sec, 250, 48);
  }
  if (t_temp.date<10)
  {
    myGLCD.printNumI(0, 70, 132);
    myGLCD.printNumI(t_temp.date, 86, 132);
  }
  else
  {
    myGLCD.printNumI(t_temp.date, 70, 132);
  }
  if (t_temp.mon<10)
  {
    myGLCD.printNumI(0, 160, 132);
    myGLCD.printNumI(t_temp.mon, 176, 132);
  }
  else
  {
    myGLCD.printNumI(t_temp.mon, 160, 132);
  }
  myGLCD.printNumI(t_temp.year, 230, 132);
  myGLCD.setFont(SmallFont);
  myGLCD.print("HORA:", 10, 51);
  myGLCD.print("DATA:", 10, 134);
  setFont(LARGE, 255, 255, 255, 0, 0, 0);  
}

void testScreen(boolean refreshAll=false)//--------------------------------teste-------------------------------------tela =3
{    
  if (refreshAll == true) 
  {  
    printHeader("TESTAR VARIACAO DE LUMINOSIDADE");
    myGLCD.fillRect (1, 15, 318, 99);      //clear 'Test in progress'
    printButton ("", stsT[0], stsT[1], stsT[2], stsT[3], true);   //start/stop
    printButton ("-10s", tenM[0], tenM[1], tenM[2], tenM[3], true);     //-10s
    printButton ("+10s", tenP[0], tenP[1], tenP[2], tenP[3], true);   //+10s
    myGLCD.print("INICIAR", stsT[0]+10, stsT[1]+15);
    myGLCD.print("TESTE", stsT[0]+25, stsT[1]+40);   
    printButton("INICIO", iniC[0], iniC[1], iniC[2], iniC[3]);
    printButton("MENU", menU[0], menU[1], menU[2], menU[3]);
  } 
  else
  {
    min_cnt=0;

    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect (1, 15, 318, 99);    //clear above buttons
    myGLCD.setColor(0, 0, 200);
    myGLCD.fillRect(stsT[0]+5, stsT[1]+5, stsT[2]-5, stsT[3]-40);   //clear 'start'
    setFont(LARGE, 255, 255, 255, 0, 0, 200);
    myGLCD.print("PARAR", stsT[0]+25, stsT[1]+15);

    myGLCD.setColor(255, 0, 0);
    myGLCD.fillRect (1, 15, 318, 37);
    myGLCD.drawRoundRect (stsT[0], stsT[1], stsT[2], stsT[3]);       //red button during test
    setFont(LARGE, 255, 255, 255, 255, 0, 0);
    myGLCD.print("TESTE EM ANDAMENTO", 15, 16);
    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("TEMPO:", 33, 40);
    myGLCD.print("POTENCIA DE SAIDA (0-255):", 30, 40);

    while (LEDtestTick == true)               //test LED and speed up time
    {
      if (myTouch.dataAvailable())  {
        processMyTouch();
      }

      if (millis() - previousMillis > 500)    //change time every 0.5s
      {
        previousMillis = millis();

        min_cnt++;
        int hour = min_cnt/60;
        int minut = min_cnt%60;
        setFont(LARGE, 255, 255, 255, 0, 0, 0);
        myGLCD.print("  :  ", 20, 55);
        myGLCD.printNumI(hour, 24, 55);
        myGLCD.printNumI(minut, 64, 55);
        String bled = "B: " + String(bled_out) + "  ";      
        char bufferB[9];
        bled.toCharArray(bufferB, 9);
        myGLCD.print(bufferB, 180, 55);      //Blue led graph
        String wled = "W: " + String(wled_out) + "  ";
        char bufferW[9];
        wled.toCharArray(bufferW, 9);
        myGLCD.print(bufferW, 180, 75);

        LED_levels_output();

      }
    }
  } 
}

//---------------------------------------------Temperatura--------------------------------tela =4 ----------
void tempScreen(boolean refreshAll=false)
{

  if (refreshAll)
  {
    if (setTempC==0) {
      setTempC = tempC;  
    }                  //change to current temp.
    temp2beS = setTempC;
    temp2beO = offTempC;
    temp2beA = alarmTempC;

    printHeader("CONTROLE DE TEMPERATURA DA AGUA");

    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("TEMPERATURA DESEJADA:", 85, 20);
    myGLCD.print("VARIACAO PERMITIDA:", 90, 70);
    myGLCD.print("VARIACAO PARA ACIONAR O ALARME:", 50, 120);

    printButton("-", temM[0], temM[1], temM[2], temM[3], true);      //temp minus
    printButton("+", temP[0], temP[1], temP[2], temP[3], true);      //temp plus
    printButton("-", offM[0], offM[1], offM[2], offM[3], true);      //offset minus
    printButton("+", offP[0], offP[1], offP[2], offP[3], true);      //offset plus
    printButton("-", almM[0], almM[1], almM[2], almM[3], true);      //alarm minus
    printButton("+", almP[0], almP[1], almP[2], almP[3], true);      //alarm plus

    printButton("SALVAR", prOK[0], prOK[1], prOK[2], prOK[3]);
    printButton("INICIO", iniC[0], iniC[1], iniC[2], iniC[3]);
    printButton("VOLTAR", menU[0], menU[1], menU[2], menU[3]);
  }

  setFont(LARGE, 255, 255, 255, 0, 0, 0);
  myGLCD.printNumF(temp2beS, 1, 130, 40);
  myGLCD.printNumF(temp2beO, 1, 140, 90);
  myGLCD.printNumF(temp2beA, 1, 140, 140);
}
void ledSetScreen()   //--------------------------------alterar valores-----------------------------------tela =5
{
  int a;

  if (WorB) {
    for (int i; i<96; i++)
      tled[i] = wled[i];
    setFont(SMALL, 255, 255, 0, 255, 255, 0);
    myGLCD.fillRect (1, 1, 318, 14);
    myGLCD.setColor(0, 0, 0);
    myGLCD.print("POTENCIA DOS LEDS BRANCOS: 255 = 100%",15, 2);
    printButton("AZUL", leWB[0], leWB[1], leWB[2], leWB[3], SMALL);
  }
  else {
    for (int i; i<96; i++)
      tled[i] = bled[i];
    setFont(SMALL, 255, 255, 0, 255, 255, 0);
    myGLCD.fillRect (1, 1, 318, 14);
    myGLCD.setColor(0, 0, 0);
    myGLCD.print("POTENCIA LEDS AZUIS: 255 = 100%" ,15, 2);
    printButton("BRANCO", leWB[0], leWB[1], leWB[2], leWB[3], SMALL);
  }

  setFont(SMALL, 255, 255, 255, 0, 0, 0);
  for (int i=0; i<12; i++) {
    myGLCD.setColor(0, 255, 255);
    myGLCD.printNumI((i*2), (i*26)+13, 14); 
    myGLCD.printNumI(((i*2)+2), (i*26)+13, 24);
    for (int j=0; j<8; j++) {
      a= (i*8)+j;         
      myGLCD.setColor(255, 255, 255);
      myGLCD.printNumI(tled[a], (i*26)+7, (j*18)+39);
      myGLCD.setColor(100, 100, 100);
      myGLCD.drawRect((i*26)+4, (j*18)+35, (i*26)+30, (j*18)+53);
    }
  }

  printButton("ALTERAR", leST[0], leST[1], leST[2], leST[3], SMALL);
  printButton("SALVAR EEPROM", savE[0], savE[1], savE[2], savE[3], SMALL);
  printButton("MENU", menU[0], menU[1], menU[2], menU[3]);
  printButton("INICIO", iniC[0], iniC[1], iniC[2], iniC[3]);

}
void ledChangeScreen()    //---------------------------------------potencia dos leds------------------------------tela =6
{
  if (WorB)
    printHeader("ALTERAR POTENCIAS DOS LEDS BRANCOS");
  else
    printHeader("ALTERAR POTENCIA DOS LEDS AZUIS");

  setFont(SMALL, 0, 255, 255, 0,0,0);
  for (int i=0; i<12; i++) {
    myGLCD.setColor(0, 255, 255);
    myGLCD.printNumI(((i*2)), (i*26)+10, 22);
    myGLCD.printNumI(((i*2)+2), (i*26)+10, 33);
    myGLCD.setColor(100, 100, 100);
    myGLCD.drawRect((i*26)+4, 20 , (i*26)+30, 45);
  }

  for (int i=0; i<8; i++)
  {
    printButton("+", (i*38)+10, 70, (i*38)+35, 95, LARGE);
    printButton("-", (i*38)+10, 125, (i*38)+35, 150, LARGE);
  }

  printButton("SALVAR", prOK[0], prOK[1], prOK[2], prOK[3]);
  printButton("INICIO", iniC[0], iniC[1], iniC[2], iniC[3]);
  printButton("MENU", menU[0], menU[1], menU[2], menU[3]);
}
void tpaScreen(boolean refreshAll = false) //--------------------------------------------------------tela =7
{
  if(refreshAll)
  {
    temp2hora = hora;
    temp2minuto = minuto;
    temp2duracaomaximatpa = duracaomaximatpa;
    temp2segunda = segunda;
    temp2terca = terca;
    temp2quarta = quarta;
    temp2quinta = quinta;
    temp2sexta = sexta;
    temp2sabado = sabado;
    temp2domingo = domingo;

    printHeader("CONF. DIAS E HORARIO PARA TPA AUTOMATICA");

    printButton("+", houU[0], houU[1], houU[2], houU[3], true); //hour up
    printButton("-", houD[0], houD[1], houD[2], houD[3], true); //hour down
    printButton("+", minUT[0], minUT[1], minUT[2], minUT[3], true); //min up
    printButton("-", minDT[0], minDT[1], minDT[2], minDT[3], true); //min down
    printButton("+", durC[0], durC[1], durC[2], durC[3], true); //min up
    printButton("-", durB[0], durB[1], durB[2], durB[3], true); //min down

    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.print(":", 105, 48);
    myGLCD.setFont(SmallFont);
    myGLCD.print("HORA:", 10, 51);
    myGLCD.print("DURACAO MAXIMA", 157, 31);
    myGLCD.print("POR ESTAGIO:", 170, 46);
    printButton("SALVAR", prOK[0], prOK[1], prOK[2], prOK[3]);
    printButton("INICIO", iniC[0], iniC[1], iniC[2], iniC[3]);
    printButton("MENU", menU[0], menU[1], menU[2], menU[3]);
  }
  if (temp2segunda == 1) {
    printButton_verde("SEGUNDA", segU[0], segU[1], segU[2], segU[3]); //botao segunda
  } 
  else {
    printButton("SEGUNDA", segU[0], segU[1], segU[2], segU[3]); //botao segunda
  }
  if (temp2terca == 2) {
    printButton_verde("TERCA", terC[0], terC[1], terC[2], terC[3]); //botao terca
  } 
  else {
    printButton("TERCA", terC[0], terC[1], terC[2], terC[3]); //botao terca
  }
  if (temp2quarta == 3) {
    printButton_verde("QUARTA", quaR[0], quaR[1], quaR[2], quaR[3]); //botao quarta
  } 
  else {
    printButton("QUARTA", quaR[0], quaR[1], quaR[2], quaR[3]); //botao quarta
  }
  if (temp2quinta == 4) {
    printButton_verde("QUINTA", quiN[0], quiN[1], quiN[2], quiN[3]); //botao quinta
  } 
  else {
    printButton("QUINTA", quiN[0], quiN[1], quiN[2], quiN[3]); //botao quinta
  }
  if (temp2sexta == 5) {
    printButton_verde("SEXTA", sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
  } 
  else {
    printButton("SEXTA", sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
  }
  if (temp2sabado == 6) printButton_verde("SABADO", sabA[0], sabA[1], sabA[2], sabA[3]); //botao sabado
  else {
    printButton("SABADO", sabA[0], sabA[1], sabA[2], sabA[3]); //botao sabado
  }
  if (temp2domingo == 7) printButton_verde("DOMINGO", domI[0], domI[1], domI[2], domI[3]); //botao sabado
  else {
    printButton("DOMINGO", domI[0], domI[1], domI[2], domI[3]); //botao sabado
  }
  if (falha_tpa == true) {
    printButton_vermelho("FALHA!!", proX[0], proX[1], proX[2], proX[3]); //Sinaliza que houve uma falha durante a TPA.
  } 
  else {
    printButton("NORMAL", proX[0], proX[1], proX[2], proX[3]); //Sinaliza que a TPA foi realizada normalmente ou não foi realizada.
  }

  setFont(LARGE, 255, 255, 255, 0, 0, 0);
  if (temp2hora < 10) {
    myGLCD.printNumI(0, 70, 48);
    myGLCD.printNumI(temp2hora, 86, 48);
  } 
  else {
    myGLCD.printNumI(temp2hora, 70, 48);
  }

  if (temp2minuto < 10) {
    myGLCD.printNumI(0, 120, 48);
    myGLCD.printNumI(temp2minuto, 136, 48);
  } 
  else {
    myGLCD.printNumI(temp2minuto, 120, 48);
  }
  if (temp2duracaomaximatpa < 10) {
    myGLCD.printNumI(0, 275, 48);
    myGLCD.printNumI(temp2duracaomaximatpa, 291, 48);
  } 
  else {
    myGLCD.printNumI(temp2duracaomaximatpa, 275, 48);
  }  
}
void menu_dosadoras()//---------------------------------------------tela =8
{

  printHeader("ALTERAR CONFIGURACAO DAS DOSADORAS");

  printButton("MANUAL", manU[0], manU[1], manU[2], manU[3]);
  printButton("AUTOMATICO", autO[0], autO[1], autO[2], autO[3]);
  printButton("PERSONALIZADO", perS[0], perS[1], perS[2], perS[3]);
  printButton("REVER CONFIG.", reV[0], reV[1], reV[2], reV[3]);
  printButton("CALIBRAR", caliB[0], caliB[1], caliB[2], caliB[3]);
  printButton("INICIO", iniC[0], iniC[1], iniC[2], iniC[3]);
  printButton("MENU", menU[0], menU[1], menU[2], menU[3]);
}

void graficoScreen()//------------------------------------------------------------tela =9
{  
  printHeader("ESCOLHA UM GRAFICO"); 
  printButton("INICIO", iniC[0], iniC[1], iniC[2], iniC[3]); 
  printButton("MENU", menU[0], menU[1], menU[2], menU[3]);
  printButton("TEMPERATURA", tempG[0], tempG[1], tempG[2],tempG[3]);
  printButton("PH AQUARIO", phA[0], phA[1], phA[2], phA[3]);
  printButton("PH REATOR", phR[0], phR[1], phR[2], phR[3]);
  printButton("ORP", orP[0], orP[1], orP[2], orP[3]);
  printButton("DENSIDADE", denS[0], denS[1], denS[2], denS[3]);

}

void waveScreen(boolean refreshAll=false)///------------------------------------------------------------------tela =10
{
  printHeader("WAVEMAKER");
  printButton("INICIO", iniC[0], iniC[1], iniC[2], iniC[3]);
  printButton("MENU", menU[0], menU[1], menU[2], menU[3]);

  setFont(SMALL, 255, 255, 255, 0, 0, 0);
  myGLCD.print("FUNCAO INCOMPLETA", 80, 30);
}
void parametroScreen()//------------------------------------------------------------tela =14---------
{  
  printHeader("ESCOLHA UM PARAMETRO"); 
  printButton("INICIO", iniC[0], iniC[1], iniC[2], iniC[3],false); 
  printButton("MENU", menU[0], menU[1], menU[2], menU[3],false);
  printButton("TEMPERATURA", tempG[0], tempG[1], tempG[2],tempG[3]);
  printButton("PH AQUARIO", phA[0], phA[1], phA[2], phA[3]);
  printButton("PH REATOR", phR[0], phR[1], phR[2], phR[3]);
  printButton("ORP", orP[0], orP[1], orP[2], orP[3]);
  printButton("DENSIDADE", denS[0], denS[1], denS[2], denS[3]);
  printButton("CALIBRAR SONDAS", caliB[0], caliB[1], caliB[2], caliB[3]);

}
//---------------------------------------------PH do reator--------------------------------tela =15 ----------
void config_phR_Screen(boolean refreshAll=false)
{

  if (refreshAll)
  {
    if (setPHR==0) {
      setPHR = PHR;  
    }                  //change to current temp.
    PHR2beS = setPHR;
    PHR2beO = offPHR;
    PHR2beA = alarmPHR;

    printHeader("CONTROLE DE PH DO REATOR DE CALCIO");

    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("PH DESEJADO:", 110, 20);
    myGLCD.print("VARIACAO PERMITIDA:", 90, 70);
    myGLCD.print("VARIACAO PARA ACIONAR O ALARME:", 50, 120);

    printButton("-", temM[0], temM[1], temM[2], temM[3], true);      //temp minus
    printButton("+", temP[0], temP[1], temP[2], temP[3], true);      //temp plus
    printButton("-", offM[0], offM[1], offM[2], offM[3], true);      //offset minus
    printButton("+", offP[0], offP[1], offP[2], offP[3], true);      //offset plus
    printButton("-", almM[0], almM[1], almM[2], almM[3], true);      //alarm minus
    printButton("+", almP[0], almP[1], almP[2], almP[3], true);      //alarm plus

    printButton("SALVAR", prOK[0], prOK[1], prOK[2], prOK[3]);
    printButton("INICIO", iniC[0], iniC[1], iniC[2], iniC[3]);
    printButton("VOLTAR", menU[0], menU[1], menU[2], menU[3]);
  }

  setFont(LARGE, 255, 255, 255, 0, 0, 0);
  myGLCD.printNumF(PHR2beS, 1, 135, 40);
  myGLCD.printNumF(PHR2beO, 1, 140, 90);
  myGLCD.printNumF(PHR2beA, 1, 140, 140);
}

//---------------------------------------------ORP--------------------------------tela =16 ----------
void config_orp_Screen(boolean refreshAll=false)
{

  if (refreshAll)
  {
    ORP2beS = setORP;
    ORP2beO = offORP;
    ORP2beA = alarmORP;

    printHeader("CONTROLE DE ORP");

    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("ORP DESEJADA:", 115, 20);
    myGLCD.print("VARIACAO PERMITIDA:", 90, 70);
    myGLCD.print("VARIACAO PARA ACIONAR O ALARME:", 50, 120);

    printButton("-", temM[0], temM[1], temM[2], temM[3], true);      //temp minus
    printButton("+", temP[0], temP[1], temP[2], temP[3], true);      //temp plus
    printButton("-", offM[0], offM[1], offM[2], offM[3], true);      //offset minus
    printButton("+", offP[0], offP[1], offP[2], offP[3], true);      //offset plus
    printButton("-", almM[0], almM[1], almM[2], almM[3], true);      //alarm minus
    printButton("+", almP[0], almP[1], almP[2], almP[3], true);      //alarm plus

    printButton("SALVAR", prOK[0], prOK[1], prOK[2], prOK[3]);
    printButton("INICIO", iniC[0], iniC[1], iniC[2], iniC[3]);
    printButton("VOLTAR", menU[0], menU[1], menU[2], menU[3]);
  }

  setFont(LARGE, 255, 255, 255, 0, 0, 0);
  myGLCD.printNumI(ORP2beS,145, 40);
  myGLCD.printNumI(ORP2beO,150, 90);
  myGLCD.printNumI(ORP2beA, 150, 140);
}
//---------------------------------------------PH do aquario--------------------------------tela =18 ----------

void config_phA_Screen(boolean refreshAll=false)
{

  if (refreshAll)
  {
    if (setPHA==0) {
      setPHA = PHA;  
    }                  //change to current temp.
    PHA2beS = setPHA;
    PHA2beO = offPHA;
    PHA2beA = alarmPHA;

    printHeader("CONTROLE DE PH DO AQUARIO");

    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("PH DESEJADO:", 110, 20);
    myGLCD.print("VARIACAO PERMITIDA:", 90, 70);
    myGLCD.print("VARIACAO PARA ACIONAR O ALARME:", 50, 120);
    myGLCD.print("NAO HA FUNCAO DE CONTROLE", 25, 170);
    myGLCD.print("ATRIBUIDADA PARA ESTE PARAMETRO", 25, 185);
    myGLCD.print("ESSES VALORES SAO APENAS ", 25, 200);
    myGLCD.print("REFERENCIA PARA O GRAFICO.", 25, 215);

    printButton("-", temM[0], temM[1], temM[2], temM[3], true);      //temp minus
    printButton("+", temP[0], temP[1], temP[2], temP[3], true);      //temp plus
    printButton("-", offM[0], offM[1], offM[2], offM[3], true);      //offset minus
    printButton("+", offP[0], offP[1], offP[2], offP[3], true);      //offset plus
    printButton("-", almM[0], almM[1], almM[2], almM[3], true);      //alarm minus
    printButton("+", almP[0], almP[1], almP[2], almP[3], true);      //alarm plus

    printButton("SALVAR", prOK[0], prOK[1], prOK[2], prOK[3]);
    printButton("INICIO", iniC[0], iniC[1], iniC[2], iniC[3]);
    printButton("VOLTAR", menU[0], menU[1], menU[2], menU[3]);
  }

  setFont(LARGE, 255, 255, 255, 0, 0, 0); 
  myGLCD.printNumF(PHA2beS, 1, 135, 40);
  myGLCD.printNumF(PHA2beO, 1, 140, 90);
  myGLCD.printNumF(PHA2beA, 1, 140, 140);
}
//---------------------------------------------configurar densidade--------------------------------tela =20 ----------
void config_dens_Screen(boolean refreshAll=false)
{

  if (refreshAll)
  {
    DEN2beS = setDEN;
    DEN2beO = offDEN;
    DEN2beA = alarmDEN;

    printHeader("CONTROLE DE DENSIDADE");

    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("DENSIDADE DESEJADA:", 90, 20);
    myGLCD.print("VARIACAO PERMITIDA:", 90, 70);
    myGLCD.print("VARIACAO PARA ACIONAR O ALARME:", 50, 120);
    myGLCD.print("NAO HA FUNCAO DE CONTROLE", 25, 170);
    myGLCD.print("ATRIBUIDA PARA ESTE PARAMETRO", 25, 185);
    myGLCD.print("ESSES VALORES SAO APENAS", 25, 200);
    myGLCD.print("REFERENCIA PARA O GRAFICO.", 25, 215);

    printButton("-", temM[0], temM[1], temM[2], temM[3], true);      //temp minus
    printButton("+", temP[0], temP[1], temP[2], temP[3], true);      //temp plus
    printButton("-", offM[0], offM[1], offM[2], offM[3], true);      //offset minus
    printButton("+", offP[0], offP[1], offP[2], offP[3], true);      //offset plus
    printButton("-", almM[0], almM[1], almM[2], almM[3], true);      //alarm minus
    printButton("+", almP[0], almP[1], almP[2], almP[3], true);      //alarm plus

    printButton("SALVAR", prOK[0], prOK[1], prOK[2], prOK[3]);
    printButton("INICIO", iniC[0], iniC[1], iniC[2], iniC[3]);
    printButton("VOLTAR", menU[0], menU[1], menU[2], menU[3]);
  }

  setFont(LARGE, 255, 255, 255, 0, 0, 0); 
  myGLCD.printNumI(DEN2beS, 128, 40);
  myGLCD.printNumI(DEN2beO, 150, 90);
  myGLCD.printNumI(DEN2beA, 150, 140);
}

void selecionar_dosadora(boolean refreshAll=false)//---------------------------------------------tela =21
{
  printHeader("ESCOLHA UMA DOSADORA");
  printButton("DOSADORA 1", dosa1[0], dosa1[1], dosa1[2], dosa1[3]);
  printButton("DOSADORA 2", dosa2[0], dosa2[1], dosa2[2], dosa2[3]);
  printButton("DOSADORA 3", dosa3[0], dosa3[1], dosa3[2], dosa3[3]);
  printButton("INICIO", iniC[0], iniC[1], iniC[2], iniC[3]);
  printButton("MENU", menU[0], menU[1], menU[2], menU[3]);
  printButton("VOLTAR", volT[0], volT[1], volT[2], volT[3]);  
}

//---------------------------------------- Calibrar dosadoras ---------------------- tela =26 
void calibrar_dosadoras(boolean refreshAll=false)
{
  if(refreshAll)
  {
    fator_calib_dosadora_1_temp2 = fator_calib_dosadora_1;
    fator_calib_dosadora_2_temp2 = fator_calib_dosadora_2;
    fator_calib_dosadora_3_temp2 = fator_calib_dosadora_3;

    printHeader("CALIBRAR DOSADORA");
    printButton("INICIO", iniC[0], iniC[1], iniC[2], iniC[3]);
    printButton("VOLTAR", volT[0], volT[1], volT[2], volT[3]);
    printButton("SALVAR", salV[0], salV[1], salV[2], salV[3]);
    printButton("INICIAR", iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
    printButton("-", almM[0], almM[1], almM[2], almM[3], true);      //alarm minus
    printButton("+", almP[0], almP[1], almP[2], almP[3], true);      //alarm plus  
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRect(20, 50, 310, 125);
    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("COLOQUE O RECIPIENTE SOB O BICO", 30, 55);
    myGLCD.print("DOSADOR E CLIQUE EM INICIAR.", 30, 70);  
    myGLCD.print("EM SEGUIDA INSIRA O VALOR OBTIDO", 30, 85);
    myGLCD.print("EM ML NO CAMPO ABAIXO.", 30, 100);
    myGLCD.print("PARA MELHORES RESULTADOS REPITA O TESTE", 5, 165);
    myGLCD.print("ALGUMAS VEZES E USE UMA MEDIA.", 35, 177);
  }
  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRect(117, 135, 203, 160);

  if((modo_calibrar == true) && (dosadora_1_selecionada == true))
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.printNumF(fator_calib_dosadora_1_temp2,1, 130, 140);
    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("DOSADORA 1 SELECIONADA", 80, 30);
  }

  if((modo_calibrar == true) && (dosadora_2_selecionada == true))
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.printNumF(fator_calib_dosadora_2_temp2,1, 130, 140);  
    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("DOSADORA 2 SELECIONADA", 80, 30);
  }

  if((modo_calibrar == true) && (dosadora_3_selecionada == true))
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.printNumF(fator_calib_dosadora_3_temp2,1, 130, 140);
    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("DOSADORA 3 SELECIONADA", 80, 30);
  } 
}

void config_dosagem_manual(boolean refreshAll=false) // ----------tela =27
{
  if(refreshAll)
  {
    printHeader("DOSAGEM MANUAL");
    printButton("INICIO", iniC[0], iniC[1], iniC[2], iniC[3]);
    printButton("VOLTAR", volT[0], volT[1], volT[2], volT[3]);
    printButton("INICIAR", iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
    printButton("-", almM[0], almM[1], almM[2], almM[3], true);      //alarm minus
    printButton("+", almP[0], almP[1], almP[2], almP[3], true);      //alarm plus  
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRect(20, 50, 310, 125);
    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("SELECIONE O VOLUME A SER DOSADO", 30, 55);
    myGLCD.print("EM ML NO CAMPO ABAIXO  E", 30, 70);  
    myGLCD.print("EM SEGUIDA TOQUE EM INICIAR.", 30, 85);
    myGLCD.print("A DOSAGEM INICIARA EM 10 SEGUNDOS", 30, 100);
  }
  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRect(117, 135, 203, 160);

  if((modo_manual == true) && (dosadora_1_selecionada == true))
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.printNumF(dose_dosadora_1_manual,1, 130, 140);
    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("DOSADORA 1 SELECIONADA", 80, 30);
  }

  if((modo_manual == true) && (dosadora_2_selecionada == true))
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.printNumF(dose_dosadora_2_manual,1, 130, 140);  
    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("DOSADORA 2 SELECIONADA", 80, 30);
  }

  if((modo_manual == true) && (dosadora_3_selecionada == true))
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.printNumF(dose_dosadora_3_manual,1, 130, 140);
    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("DOSADORA 3 SELECIONADA", 80, 30);
  } 
}

void config_dosagem_automatica(boolean refreshAll=false) // ----------tela =28
{
  if(refreshAll)
  { 
    hora_inicial_dosagem_automatica_1_temp2 = hora_inicial_dosagem_automatica_1;
    minuto_inicial_dosagem_automatica_1_temp2 = minuto_inicial_dosagem_automatica_1;
    hora_final_dosagem_automatica_1_temp2 = hora_final_dosagem_automatica_1;
    minuto_final_dosagem_automatica_1_temp2 = minuto_final_dosagem_automatica_1;
    hora_inicial_dosagem_automatica_2_temp2 = hora_inicial_dosagem_automatica_2;
    minuto_inicial_dosagem_automatica_2_temp2 = minuto_inicial_dosagem_automatica_2;
    hora_final_dosagem_automatica_2_temp2 = hora_final_dosagem_automatica_2;
    minuto_final_dosagem_automatica_2_temp2 = minuto_final_dosagem_automatica_2;
    hora_inicial_dosagem_automatica_3_temp2 = hora_inicial_dosagem_automatica_3;
    minuto_inicial_dosagem_automatica_3_temp2 = minuto_inicial_dosagem_automatica_3;
    hora_final_dosagem_automatica_3_temp2 = hora_final_dosagem_automatica_3;
    minuto_final_dosagem_automatica_3_temp2 = minuto_final_dosagem_automatica_3;
    dose_dosadora_1_automatica_temp2 = dose_dosadora_1_automatica;
    dose_dosadora_2_automatica_temp2 = dose_dosadora_2_automatica;
    dose_dosadora_3_automatica_temp2 = dose_dosadora_3_automatica;
    quantidade_dose_dosadora_1_automatica_temp2 = quantidade_dose_dosadora_1_automatica;
    quantidade_dose_dosadora_2_automatica_temp2 = quantidade_dose_dosadora_2_automatica;
    quantidade_dose_dosadora_3_automatica_temp2 = quantidade_dose_dosadora_3_automatica;
    modo_automatico_on_1_temp2 = modo_automatico_on_1;
    modo_automatico_on_2_temp2 = modo_automatico_on_2;
    modo_automatico_on_3_temp2 = modo_automatico_on_3;
  }
  printHeader("CONFIGURAR DOSAGEM AUTOMATICA");

  printButton("+", houU[0], houU[1], houU[2], houU[3], true); //hour up
  printButton("-", houD[0], houD[1], houD[2], houD[3], true); //hour down
  printButton("+", minUT[0], minUT[1], minUT[2], minUT[3], true); //min up
  printButton("-", minDT[0], minDT[1], minDT[2], minDT[3], true); //min down
  printButton("+", houU[0]+deslocamento_botao_x, houU[1], houU[2]+deslocamento_botao_x, houU[3], true); //hora mais
  printButton("-", houD[0]+deslocamento_botao_x, houD[1], houD[2]+deslocamento_botao_x, houD[3], true); //hora menos
  printButton("+", minUT[0]+deslocamento_botao_x, minUT[1], minUT[2]+deslocamento_botao_x, minUT[3], true); //minuto mais
  printButton("-", minDT[0]+deslocamento_botao_x, minDT[1], minDT[2]+deslocamento_botao_x, minDT[3], true); //minuto menos
  printButton("+", minUT[0], minUT[1]+deslocamento_botao_y, minUT[2], minUT[3]+deslocamento_botao_y, true); //min up
  printButton("-", minDT[0], minDT[1]+deslocamento_botao_y, minDT[2], minDT[3]+deslocamento_botao_y, true); //min down
  printButton("+", durC[0], durC[1]+deslocamento_botao_y, durC[2], durC[3]+deslocamento_botao_y, true); //minuto mais
  printButton("-", durB[0], durB[1]+deslocamento_botao_y, durB[2], durB[3]+deslocamento_botao_y, true); //minuto menos

  printButton("INICIO", iniC[0], iniC[1], iniC[2], iniC[3]);
  printButton("VOLTAR", volT[0], volT[1], volT[2], volT[3]);
  printButton("SALVAR", salV[0], salV[1], salV[2], salV[3]);

  setFont(LARGE, 255, 255, 255, 0, 0, 0);
  myGLCD.print(":", 105, 48);
  myGLCD.print(":", 105 + deslocamento_botao_x, 48);
  myGLCD.setFont(SmallFont);
  myGLCD.print("INICIAL:", 5, 51);
  myGLCD.print("FINAL:", 172, 51);
  myGLCD.print("SELECIONE O", 10, 31 + deslocamento_botao_y);
  myGLCD.print("VOLUME ", 10, 55 + deslocamento_botao_y);
  myGLCD.print("(ML/DIA):", 10, 75 + deslocamento_botao_y);
  myGLCD.print("QUANTIDADE", 190, 46 + deslocamento_botao_y);
  myGLCD.print("DE DOSES:", 190, 61 + deslocamento_botao_y);

  if(dosadora_1_selecionada == true)
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    if (hora_inicial_dosagem_automatica_1_temp2 < 10) {
      myGLCD.printNumI(0, 70, 48);
      myGLCD.printNumI(hora_inicial_dosagem_automatica_1_temp2, 86, 48);
    } 
    else {
      myGLCD.printNumI(hora_inicial_dosagem_automatica_1_temp2, 70, 48);
    }

    if (minuto_inicial_dosagem_automatica_1_temp2 < 10) {
      myGLCD.printNumI(0, 120, 48);
      myGLCD.printNumI(minuto_inicial_dosagem_automatica_1_temp2, 136, 48);
    } 
    else {
      myGLCD.printNumI(minuto_inicial_dosagem_automatica_1_temp2, 120, 48);
    }
    if (hora_final_dosagem_automatica_1_temp2 < 10) {
      myGLCD.printNumI(0, 70 + deslocamento_botao_x, 48);
      myGLCD.printNumI(hora_final_dosagem_automatica_1_temp2, 86 + deslocamento_botao_x, 48);
    } 
    else {
      myGLCD.printNumI(hora_final_dosagem_automatica_1_temp2, 70 + deslocamento_botao_x, 48);
    }

    if (minuto_final_dosagem_automatica_1_temp2 < 10) {
      myGLCD.printNumI(0, 120 + deslocamento_botao_x, 48);
      myGLCD.printNumI(minuto_final_dosagem_automatica_1_temp2, 136 + deslocamento_botao_x, 48);
    } 
    else {
      myGLCD.printNumI(minuto_final_dosagem_automatica_1_temp2, 120 + deslocamento_botao_x, 48);
    }

    setFont(LARGE, 255, 255, 255, 0, 0, 0);

    myGLCD.printNumF(dose_dosadora_1_automatica_temp2, 1, 100, 48 + deslocamento_botao_y);

    if (quantidade_dose_dosadora_1_automatica_temp2 < 10) 
    {
      myGLCD.printNumI(0, 275, 48 + deslocamento_botao_y);
      myGLCD.printNumI(quantidade_dose_dosadora_1_automatica_temp2, 291, 48 + deslocamento_botao_y);
    } 
    else 
    {
      myGLCD.printNumI(quantidade_dose_dosadora_1_automatica_temp2, 275, 48 + deslocamento_botao_y);
    }
    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("DOSADORA 1", 10, 198);
    myGLCD.print("SELECIONADA", 10, 218);

    if (modo_automatico_on_1_temp2 == 1) 
    {
      printButton_verde("ON", domI[0], domI[1], domI[2], domI[3]); 
    } 
    else 
    {
      printButton("OFF", domI[0], domI[1], domI[2], domI[3]); 
    }
  }
  if(dosadora_2_selecionada == true)
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);

    if (hora_inicial_dosagem_automatica_2_temp2 < 10) {
      myGLCD.printNumI(0, 70, 48);
      myGLCD.printNumI(hora_inicial_dosagem_automatica_2_temp2, 86, 48);
    } 
    else {
      myGLCD.printNumI(hora_inicial_dosagem_automatica_2_temp2, 70, 48);
    }

    if (minuto_inicial_dosagem_automatica_2_temp2 < 10) {
      myGLCD.printNumI(0, 120, 48);
      myGLCD.printNumI(minuto_inicial_dosagem_automatica_2_temp2, 136, 48);
    } 
    else {
      myGLCD.printNumI(minuto_inicial_dosagem_automatica_2_temp2, 120, 48);
    }
    if (hora_final_dosagem_automatica_2_temp2 < 10) {
      myGLCD.printNumI(0, 70 + deslocamento_botao_x, 48);
      myGLCD.printNumI(hora_final_dosagem_automatica_2_temp2, 86 + deslocamento_botao_x, 48);
    } 
    else {
      myGLCD.printNumI(hora_final_dosagem_automatica_2_temp2, 70 + deslocamento_botao_x, 48);
    }

    if (minuto_final_dosagem_automatica_2_temp2 < 10) {
      myGLCD.printNumI(0, 120 + deslocamento_botao_x, 48);
      myGLCD.printNumI(minuto_final_dosagem_automatica_2_temp2, 136 + deslocamento_botao_x, 48);
    } 
    else {
      myGLCD.printNumI(minuto_final_dosagem_automatica_2_temp2, 120 + deslocamento_botao_x, 48);
    }
    setFont(LARGE, 255, 255, 255, 0, 0, 0);

    myGLCD.printNumF(dose_dosadora_2_automatica_temp2, 1, 100, 48 + deslocamento_botao_y);

    if (quantidade_dose_dosadora_2_automatica_temp2 < 10) 
    {
      myGLCD.printNumI(0, 275, 48 + deslocamento_botao_y);
      myGLCD.printNumI(quantidade_dose_dosadora_2_automatica_temp2, 291, 48 + deslocamento_botao_y);
    } 
    else 
    {
      myGLCD.printNumI(quantidade_dose_dosadora_2_automatica_temp2, 275, 48 + deslocamento_botao_y);
    }
    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("DOSADORA 2", 10, 198);
    myGLCD.print("SELECIONADA", 10, 218);

    if (modo_automatico_on_2_temp2 == 1) 
    {
      printButton_verde("ON", domI[0], domI[1], domI[2], domI[3]); 
    } 
    else 
    {
      printButton("OFF", domI[0], domI[1], domI[2], domI[3]); 
    }
  }
  if(dosadora_3_selecionada == true)
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);

    if (hora_inicial_dosagem_automatica_3_temp2 < 10) {
      myGLCD.printNumI(0, 70, 48);
      myGLCD.printNumI(hora_inicial_dosagem_automatica_3_temp2, 86, 48);
    } 
    else {
      myGLCD.printNumI(hora_inicial_dosagem_automatica_3_temp2, 70, 48);
    }

    if (minuto_inicial_dosagem_automatica_3_temp2 < 10) {
      myGLCD.printNumI(0, 120, 48);
      myGLCD.printNumI(minuto_inicial_dosagem_automatica_3_temp2, 136, 48);
    } 
    else {
      myGLCD.printNumI(minuto_inicial_dosagem_automatica_3_temp2, 120, 48);
    }
    if (hora_final_dosagem_automatica_3_temp2 < 10) {
      myGLCD.printNumI(0, 70 + deslocamento_botao_x, 48);
      myGLCD.printNumI(hora_final_dosagem_automatica_3_temp2, 86 + deslocamento_botao_x, 48);
    } 
    else {
      myGLCD.printNumI(hora_final_dosagem_automatica_3_temp2, 70 + deslocamento_botao_x, 48);
    }

    if (minuto_final_dosagem_automatica_3_temp2 < 10) {
      myGLCD.printNumI(0, 120 + deslocamento_botao_x, 48);
      myGLCD.printNumI(minuto_final_dosagem_automatica_3_temp2, 136 + deslocamento_botao_x, 48);
    } 
    else {
      myGLCD.printNumI(minuto_final_dosagem_automatica_3_temp2, 120 + deslocamento_botao_x, 48);
    }
    setFont(LARGE, 255, 255, 255, 0, 0, 0);

    myGLCD.printNumF(dose_dosadora_3_automatica_temp2, 1, 100, 48 + deslocamento_botao_y);

    if (quantidade_dose_dosadora_3_automatica_temp2 < 10) 
    {
      myGLCD.printNumI(0, 275, 48 + deslocamento_botao_y);
      myGLCD.printNumI(quantidade_dose_dosadora_3_automatica_temp2, 291, 48 + deslocamento_botao_y);
    } 
    else 
    {
      myGLCD.printNumI(quantidade_dose_dosadora_3_automatica_temp2, 275, 48 + deslocamento_botao_y);
    }
    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("DOSADORA 3", 10, 198);
    myGLCD.print("SELECIONADA", 10, 218);

    if (modo_automatico_on_3_temp2 == 1) 
    {
      printButton_verde("ON", domI[0], domI[1], domI[2], domI[3]); 
    } 
    else 
    {
      printButton("OFF", domI[0], domI[1], domI[2], domI[3]); 
    }
  }  
  myGLCD.setColor(0, 0, 0);                      
  myGLCD.fillRect(205, 195, 310, 239);
}

void config_dosagem_personalizada(boolean refreshAll=false) // ----------tela =29
{
  if(refreshAll)
  {   

    temp2hora_inicial_dosagem_personalizada_1 = hora_inicial_dosagem_personalizada_1;
    temp2minuto_inicial_dosagem_personalizada_1 = minuto_inicial_dosagem_personalizada_1;
    temp2hora_final_dosagem_personalizada_1 = hora_final_dosagem_personalizada_1;
    temp2minuto_final_dosagem_personalizada_1 = minuto_final_dosagem_personalizada_1;
    temp2segunda_dosagem_personalizada_1 = segunda_dosagem_personalizada_1;
    temp2terca_dosagem_personalizada_1 = terca_dosagem_personalizada_1;
    temp2quarta_dosagem_personalizada_1 = quarta_dosagem_personalizada_1;
    temp2quinta_dosagem_personalizada_1 = quinta_dosagem_personalizada_1;
    temp2sexta_dosagem_personalizada_1 = sexta_dosagem_personalizada_1;
    temp2sabado_dosagem_personalizada_1 = sabado_dosagem_personalizada_1;
    temp2domingo_dosagem_personalizada_1 = domingo_dosagem_personalizada_1;
    temp2hora_inicial_dosagem_personalizada_2 = hora_inicial_dosagem_personalizada_2;
    temp2minuto_inicial_dosagem_personalizada_2 = minuto_inicial_dosagem_personalizada_2;
    temp2hora_final_dosagem_personalizada_2 = hora_final_dosagem_personalizada_2;
    temp2minuto_final_dosagem_personalizada_2 = minuto_final_dosagem_personalizada_2;
    temp2segunda_dosagem_personalizada_2 = segunda_dosagem_personalizada_2;
    temp2terca_dosagem_personalizada_2 = terca_dosagem_personalizada_2;
    temp2quarta_dosagem_personalizada_2 = quarta_dosagem_personalizada_2;
    temp2quinta_dosagem_personalizada_2 = quinta_dosagem_personalizada_2;
    temp2sexta_dosagem_personalizada_2 = sexta_dosagem_personalizada_2;
    temp2sabado_dosagem_personalizada_2 = sabado_dosagem_personalizada_2;
    temp2domingo_dosagem_personalizada_2 = domingo_dosagem_personalizada_2;
    temp2hora_inicial_dosagem_personalizada_3 = hora_inicial_dosagem_personalizada_3;
    temp2minuto_inicial_dosagem_personalizada_3 = minuto_inicial_dosagem_personalizada_3;
    temp2hora_final_dosagem_personalizada_3 = hora_final_dosagem_personalizada_3;
    temp2minuto_final_dosagem_personalizada_3 = minuto_final_dosagem_personalizada_3;
    temp2segunda_dosagem_personalizada_3 = segunda_dosagem_personalizada_3;
    temp2terca_dosagem_personalizada_3 = terca_dosagem_personalizada_3;
    temp2quarta_dosagem_personalizada_3 = quarta_dosagem_personalizada_3;
    temp2quinta_dosagem_personalizada_3 = quinta_dosagem_personalizada_3;
    temp2sexta_dosagem_personalizada_3 = sexta_dosagem_personalizada_3;
    temp2sabado_dosagem_personalizada_3 = sabado_dosagem_personalizada_3;
    temp2domingo_dosagem_personalizada_3 = domingo_dosagem_personalizada_3;

  }
  printHeader("CONFIGURAR DOSAGEM PERSONALIZADA");

  printButton("+", houU[0], houU[1], houU[2], houU[3], true); //hour up
  printButton("-", houD[0], houD[1], houD[2], houD[3], true); //hour down
  printButton("+", minUT[0], minUT[1], minUT[2], minUT[3], true); //min up
  printButton("-", minDT[0], minDT[1], minDT[2], minDT[3], true); //min down
  printButton("+", houU[0]+deslocamento_botao_x, houU[1], houU[2]+deslocamento_botao_x, houU[3], true); //hora mais
  printButton("-", houD[0]+deslocamento_botao_x, houD[1], houD[2]+deslocamento_botao_x, houD[3], true); //hora menos
  printButton("+", minUT[0]+deslocamento_botao_x, minUT[1], minUT[2]+deslocamento_botao_x, minUT[3], true); //minuto mais
  printButton("-", minDT[0]+deslocamento_botao_x, minDT[1], minDT[2]+deslocamento_botao_x, minDT[3], true); //minuto menos

  setFont(LARGE, 255, 255, 255, 0, 0, 0);
  myGLCD.print(":", 105, 48);
  myGLCD.print(":", 105 + deslocamento_botao_x, 48);
  myGLCD.setFont(SmallFont);
  myGLCD.print("INICIAL:", 5, 51);
  myGLCD.print("FINAL:", 172, 51);
  printButton("PROXIMO", proX[0], proX[1], proX[2], proX[3]); 
  printButton("INICIO", iniC[0], iniC[1], iniC[2], iniC[3]);
  printButton("MENU", menU[0], menU[1], menU[2], menU[3]);
  printButton("VOLTAR", volT[0], volT[1], volT[2], volT[3]);

  if(dosadora_1_selecionada == true)
  {
    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("DOSADORA 1", 10, 198);
    myGLCD.print("SELECIONADA", 10, 218);

    if (temp2segunda_dosagem_personalizada_1 == 1) {
      printButton_verde("SEGUNDA", segU[0], segU[1], segU[2], segU[3]); //botao segunda
    } 
    else {
      printButton("SEGUNDA", segU[0], segU[1], segU[2], segU[3]); //botao segunda
    }
    if (temp2terca_dosagem_personalizada_1 == 2) {
      printButton_verde("TERCA", terC[0], terC[1], terC[2], terC[3]); //botao terca
    } 
    else {
      printButton("TERCA", terC[0], terC[1], terC[2], terC[3]); //botao terca
    }
    if (temp2quarta_dosagem_personalizada_1 == 3) {
      printButton_verde("QUARTA", quaR[0], quaR[1], quaR[2], quaR[3]); //botao quarta
    } 
    else {
      printButton("QUARTA", quaR[0], quaR[1], quaR[2], quaR[3]); //botao quarta
    }
    if (temp2quinta_dosagem_personalizada_1 == 4) {
      printButton_verde("QUINTA", quiN[0], quiN[1], quiN[2], quiN[3]); //botao quinta
    } 
    else {
      printButton("QUINTA", quiN[0], quiN[1], quiN[2], quiN[3]); //botao quinta
    }
    if (temp2sexta_dosagem_personalizada_1 == 5) {
      printButton_verde("SEXTA", sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
    } 
    else {
      printButton("SEXTA", sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
    }
    if (temp2sabado_dosagem_personalizada_1 == 6) printButton_verde("SABADO", sabA[0], sabA[1], sabA[2], sabA[3]); //botao sabado
    else {
      printButton("SABADO", sabA[0], sabA[1], sabA[2], sabA[3]); //botao sabado
    }
    if (temp2domingo_dosagem_personalizada_1 == 7) printButton_verde("DOMINGO", domI[0], domI[1], domI[2], domI[3]); //botao sabado
    else {
      printButton("DOMINGO", domI[0], domI[1], domI[2], domI[3]); //botao sabado
    }

    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    if (temp2hora_inicial_dosagem_personalizada_1 < 10) {
      myGLCD.printNumI(0, 70, 48);
      myGLCD.printNumI(temp2hora_inicial_dosagem_personalizada_1, 86, 48);
    } 
    else {
      myGLCD.printNumI(temp2hora_inicial_dosagem_personalizada_1, 70, 48);
    }

    if (temp2minuto_inicial_dosagem_personalizada_1 < 10) {
      myGLCD.printNumI(0, 120, 48);
      myGLCD.printNumI(temp2minuto_inicial_dosagem_personalizada_1, 136, 48);
    } 
    else {
      myGLCD.printNumI(temp2minuto_inicial_dosagem_personalizada_1, 120, 48);
    }
    if (temp2hora_final_dosagem_personalizada_1 < 10) {
      myGLCD.printNumI(0, 70 + deslocamento_botao_x, 48);
      myGLCD.printNumI(temp2hora_final_dosagem_personalizada_1, 86 + deslocamento_botao_x, 48);
    } 
    else {
      myGLCD.printNumI(temp2hora_final_dosagem_personalizada_1, 70 + deslocamento_botao_x, 48);
    }

    if (temp2minuto_final_dosagem_personalizada_1 < 10) {
      myGLCD.printNumI(0, 120 + deslocamento_botao_x, 48);
      myGLCD.printNumI(temp2minuto_final_dosagem_personalizada_1, 136 + deslocamento_botao_x, 48);
    } 
    else {
      myGLCD.printNumI(temp2minuto_final_dosagem_personalizada_1, 120 + deslocamento_botao_x, 48);
    }
  }
  if(dosadora_2_selecionada == true)
  {
    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("DOSADORA 2", 10, 198);
    myGLCD.print("SELECIONADA", 10, 218);

    if (temp2segunda_dosagem_personalizada_2 == 1) {
      printButton_verde("SEGUNDA", segU[0], segU[1], segU[2], segU[3]); //botao segunda
    } 
    else {
      printButton("SEGUNDA", segU[0], segU[1], segU[2], segU[3]); //botao segunda
    }
    if (temp2terca_dosagem_personalizada_2 == 2) {
      printButton_verde("TERCA", terC[0], terC[1], terC[2], terC[3]); //botao terca
    } 
    else {
      printButton("TERCA", terC[0], terC[1], terC[2], terC[3]); //botao terca
    }
    if (temp2quarta_dosagem_personalizada_2 == 3) {
      printButton_verde("QUARTA", quaR[0], quaR[1], quaR[2], quaR[3]); //botao quarta
    } 
    else {
      printButton("QUARTA", quaR[0], quaR[1], quaR[2], quaR[3]); //botao quarta
    }
    if (temp2quinta_dosagem_personalizada_2 == 4) {
      printButton_verde("QUINTA", quiN[0], quiN[1], quiN[2], quiN[3]); //botao quinta
    } 
    else {
      printButton("QUINTA", quiN[0], quiN[1], quiN[2], quiN[3]); //botao quinta
    }
    if (temp2sexta_dosagem_personalizada_2 == 5) {
      printButton_verde("SEXTA", sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
    } 
    else {
      printButton("SEXTA", sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
    }
    if (temp2sabado_dosagem_personalizada_2 == 6) printButton_verde("SABADO", sabA[0], sabA[1], sabA[2], sabA[3]); //botao sabado
    else {
      printButton("SABADO", sabA[0], sabA[1], sabA[2], sabA[3]); //botao sabado
    }
    if (temp2domingo_dosagem_personalizada_2 == 7) printButton_verde("DOMINGO", domI[0], domI[1], domI[2], domI[3]); //botao sabado
    else {
      printButton("DOMINGO", domI[0], domI[1], domI[2], domI[3]); //botao sabado
    }

    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    if (temp2hora_inicial_dosagem_personalizada_2 < 10) {
      myGLCD.printNumI(0, 70, 48);
      myGLCD.printNumI(temp2hora_inicial_dosagem_personalizada_2, 86, 48);
    } 
    else {
      myGLCD.printNumI(temp2hora_inicial_dosagem_personalizada_2, 70, 48);
    }

    if (temp2minuto_inicial_dosagem_personalizada_2 < 10) {
      myGLCD.printNumI(0, 120, 48);
      myGLCD.printNumI(temp2minuto_inicial_dosagem_personalizada_2, 136, 48);
    } 
    else {
      myGLCD.printNumI(temp2minuto_inicial_dosagem_personalizada_2, 120, 48);
    }
    if (temp2hora_final_dosagem_personalizada_2 < 10) {
      myGLCD.printNumI(0, 70 + deslocamento_botao_x, 48);
      myGLCD.printNumI(temp2hora_final_dosagem_personalizada_2, 86 + deslocamento_botao_x, 48);
    } 
    else {
      myGLCD.printNumI(temp2hora_final_dosagem_personalizada_2, 70 + deslocamento_botao_x, 48);
    }

    if (temp2minuto_final_dosagem_personalizada_2 < 10) {
      myGLCD.printNumI(0, 120 + deslocamento_botao_x, 48);
      myGLCD.printNumI(temp2minuto_final_dosagem_personalizada_2, 136 + deslocamento_botao_x, 48);
    } 
    else {
      myGLCD.printNumI(temp2minuto_final_dosagem_personalizada_2, 120 + deslocamento_botao_x, 48);
    }
  }
  if(dosadora_3_selecionada == true)
  {
    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("DOSADORA 3", 10, 198);
    myGLCD.print("SELECIONADA", 10, 218);

    if (temp2segunda_dosagem_personalizada_3 == 1) {
      printButton_verde("SEGUNDA", segU[0], segU[1], segU[2], segU[3]); //botao segunda
    } 
    else {
      printButton("SEGUNDA", segU[0], segU[1], segU[2], segU[3]); //botao segunda
    }
    if (temp2terca_dosagem_personalizada_3 == 2) {
      printButton_verde("TERCA", terC[0], terC[1], terC[2], terC[3]); //botao terca
    } 
    else {
      printButton("TERCA", terC[0], terC[1], terC[2], terC[3]); //botao terca
    }
    if (temp2quarta_dosagem_personalizada_3 == 3) {
      printButton_verde("QUARTA", quaR[0], quaR[1], quaR[2], quaR[3]); //botao quarta
    } 
    else {
      printButton("QUARTA", quaR[0], quaR[1], quaR[2], quaR[3]); //botao quarta
    }
    if (temp2quinta_dosagem_personalizada_3 == 4) {
      printButton_verde("QUINTA", quiN[0], quiN[1], quiN[2], quiN[3]); //botao quinta
    } 
    else {
      printButton("QUINTA", quiN[0], quiN[1], quiN[2], quiN[3]); //botao quinta
    }
    if (temp2sexta_dosagem_personalizada_3 == 5) {
      printButton_verde("SEXTA", sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
    } 
    else {
      printButton("SEXTA", sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
    }
    if (temp2sabado_dosagem_personalizada_3 == 6) printButton_verde("SABADO", sabA[0], sabA[1], sabA[2], sabA[3]); //botao sabado
    else {
      printButton("SABADO", sabA[0], sabA[1], sabA[2], sabA[3]); //botao sabado
    }
    if (temp2domingo_dosagem_personalizada_3 == 7) printButton_verde("DOMINGO", domI[0], domI[1], domI[2], domI[3]); //botao sabado
    else {
      printButton("DOMINGO", domI[0], domI[1], domI[2], domI[3]); //botao sabado
    }

    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    if (temp2hora_inicial_dosagem_personalizada_3 < 10) {
      myGLCD.printNumI(0, 70, 48);
      myGLCD.printNumI(temp2hora_inicial_dosagem_personalizada_3, 86, 48);
    } 
    else {
      myGLCD.printNumI(temp2hora_inicial_dosagem_personalizada_3, 70, 48);
    }

    if (temp2minuto_inicial_dosagem_personalizada_3 < 10) {
      myGLCD.printNumI(0, 120, 48);
      myGLCD.printNumI(temp2minuto_inicial_dosagem_personalizada_3, 136, 48);
    } 
    else {
      myGLCD.printNumI(temp2minuto_inicial_dosagem_personalizada_3, 120, 48);
    }
    if (temp2hora_final_dosagem_personalizada_3 < 10) {
      myGLCD.printNumI(0, 70 + deslocamento_botao_x, 48);
      myGLCD.printNumI(temp2hora_final_dosagem_personalizada_3, 86 + deslocamento_botao_x, 48);
    } 
    else {
      myGLCD.printNumI(temp2hora_final_dosagem_personalizada_3, 70 + deslocamento_botao_x, 48);
    }

    if (temp2minuto_final_dosagem_personalizada_3 < 10) {
      myGLCD.printNumI(0, 120 + deslocamento_botao_x, 48);
      myGLCD.printNumI(temp2minuto_final_dosagem_personalizada_3, 136 + deslocamento_botao_x, 48);
    } 
    else {
      myGLCD.printNumI(temp2minuto_final_dosagem_personalizada_3, 120 + deslocamento_botao_x, 48);
    }
  }
}

void solicitar_senha()  //---------------tela =30
{
  printHeader("DIGITE A SENHA");
  printButton("1", boT1[0], boT1[1], boT1[2], boT1[3],true);
  printButton("2", boT2[0], boT2[1], boT2[2], boT2[3],true);
  printButton("3", boT3[0], boT3[1], boT3[2], boT3[3],true);
  printButton("4", boT4[0], boT4[1], boT4[2], boT4[3],true);
  printButton("5", boT5[0], boT5[1], boT5[2], boT5[3],true);
  printButton("6", boT6[0], boT6[1], boT6[2], boT6[3],true);
  printButton("7", boT7[0], boT7[1], boT7[2], boT7[3],true);
  printButton("8", boT8[0], boT8[1], boT8[2], boT8[3],true);
  printButton("9", boT9[0], boT9[1], boT9[2], boT9[3],true);
  printButton("0", boT0[0], boT0[1], boT0[2], boT0[3],true);
  printButton("LIMPAR", boTL[0], boTL[1], boTL[2], boTL[3],true);
  printButton("ENTRAR", boTE[0], boTE[1], boTE[2], boTE[3],true);
  printButton("INICIO", iniC[0], iniC[1], iniC[2], iniC[3]);

}

void config_dosagem_personalizada_2(boolean refreshAll=false) // ----------tela =31
{
  if(refreshAll)
  {
    dose_dosadora_1_personalizada_temp2 = dose_dosadora_1_personalizada;
    dose_dosadora_2_personalizada_temp2 = dose_dosadora_2_personalizada;
    dose_dosadora_3_personalizada_temp2 = dose_dosadora_3_personalizada;
    quantidade_dose_dosadora_1_personalizada_temp2 = quantidade_dose_dosadora_1_personalizada;
    quantidade_dose_dosadora_2_personalizada_temp2 = quantidade_dose_dosadora_2_personalizada;
    quantidade_dose_dosadora_3_personalizada_temp2 = quantidade_dose_dosadora_3_personalizada;
    modo_personalizado_on_1_temp2 = modo_personalizado_on_1;
    modo_personalizado_on_2_temp2 = modo_personalizado_on_2;
    modo_personalizado_on_3_temp2 = modo_personalizado_on_3;

    printHeader("CONFIGURAR DOSAGEM PERSONALIZADA");
    printButton("INICIO", iniC[0], iniC[1], iniC[2], iniC[3]);
    printButton("MENU", menU[0], menU[1], menU[2], menU[3]);
    printButton("ANTERIOR", anT[0],anT[1], anT[2], anT[3]);
    printButton("SALVAR", prOK[0],prOK[1], prOK[2], prOK[3]);
    printButton("+", minUT[0], minUT[1], minUT[2], minUT[3], true); //min up
    printButton("-", minDT[0], minDT[1], minDT[2], minDT[3], true); //min down
    printButton("+", durC[0], durC[1], durC[2], durC[3], true); //minuto mais
    printButton("-", durB[0], durB[1], durB[2], durB[3], true); //minuto menos
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.setFont(SmallFont);
    myGLCD.print("SELECIONE O", 10, 31);
    myGLCD.print("VOLUME ", 10, 55);
    myGLCD.print("(ML/DIA):", 10, 75);
    myGLCD.print("QUANTIDADE", 190, 46);
    myGLCD.print("DE DOSES:", 190, 61);
  }

  if ((dosadora_1_selecionada == true) && (modo_personalizado == true ))
  { 
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.printNumF(dose_dosadora_1_personalizada_temp2, 1, 100, 48);  
    if (quantidade_dose_dosadora_1_personalizada_temp2 < 10) 
    {
      myGLCD.printNumI(0, 275, 48);
      myGLCD.printNumI(quantidade_dose_dosadora_1_personalizada_temp2, 291, 48);
    } 
    else 
    {
      myGLCD.printNumI(quantidade_dose_dosadora_1_personalizada_temp2, 275, 48);
    }
    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("DOSADORA 1 SELECIONADA", 125, 213);

    if (modo_personalizado_on_1_temp2 == 1) 
    {
      printButton_verde("ON", sexT[0], sexT[1], sexT[2], sexT[3]); 
    } 
    else 
    {
      printButton("OFF", sexT[0], sexT[1], sexT[2], sexT[3]); 
    }
  } 
  if ((dosadora_2_selecionada == true) && (modo_personalizado == true ))
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.printNumF(dose_dosadora_2_personalizada_temp2, 1, 100, 48);  
    if (quantidade_dose_dosadora_2_personalizada_temp2 < 10) 
    {
      myGLCD.printNumI(0, 275, 48);
      myGLCD.printNumI(quantidade_dose_dosadora_2_personalizada_temp2, 291, 48);
    } 
    else 
    {
      myGLCD.printNumI(quantidade_dose_dosadora_2_personalizada_temp2, 275, 48);
    }
    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("DOSADORA 2 SELECIONADA", 125, 213);
    if (modo_personalizado_on_2_temp2 == 1) 
    {
      printButton_verde("ON", sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
    } 
    else 
    {
      printButton("OFF", sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
    }
  }
  if ((dosadora_3_selecionada == true) && (modo_personalizado == true))
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.printNumF(dose_dosadora_3_personalizada_temp2, 1, 100, 48); 

    if (quantidade_dose_dosadora_3_personalizada_temp2 < 10) 
    {
      myGLCD.printNumI(0, 275, 48);
      myGLCD.printNumI(quantidade_dose_dosadora_3_personalizada_temp2, 291, 48);
    } 
    else 
    {
      myGLCD.printNumI(quantidade_dose_dosadora_3_personalizada_temp2, 275, 48);
    }
    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("DOSADORA 3 SELECIONADA", 125, 213);
    if (modo_personalizado_on_3_temp2 == 1) 
    {
      printButton_verde("ON", sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
    } 
    else 
    {
      printButton("OFF", sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
    }
  }
}

void rever_dosagem_personalizada() // ----------tela =32
{

  printHeader("REVER CONF. DA DOSAGEM PERSONALIZADA");
  printButton("INICIO", iniC[0], iniC[1], iniC[2], iniC[3]);
  printButton("MENU", menU[0], menU[1], menU[2], menU[3]);

  myGLCD.setColor(161, 127, 73);                    
  myGLCD.drawLine(1, 88, 319, 88);  
  myGLCD.drawLine(1, 158, 319, 158);
  myGLCD.drawLine(319, 15, 319, 239);

  setFont(SMALL, 255, 255, 255, 0, 0, 0);
  myGLCD.print("DOSADORA 1:", 10, 30);   
  myGLCD.print("INICIAL:", 10, 50);  
  myGLCD.print("FINAL:", 118, 50);
  myGLCD.print("QUANTIDADE DE DOSES:", 10, 70);
  myGLCD.print("VOLUME:", 215, 50);    //Posição correta
  myGLCD.print(":", 90, 50);
  myGLCD.print(":", 180, 50);

  myGLCD.printNumF(dose_dosadora_1_personalizada, 1, 275, 50); //Posição correta
  myGLCD.printNumI(quantidade_dose_dosadora_1_personalizada, 170, 70);

  if(hora_inicial_dosagem_personalizada_1 < 10)
  {
    myGLCD.printNumI(0, 72, 50);
    myGLCD.printNumI(hora_inicial_dosagem_personalizada_1, 80, 50);
  }
  else
  {
    myGLCD.printNumI(hora_inicial_dosagem_personalizada_1, 72, 50);
  }
  if(minuto_inicial_dosagem_personalizada_1 < 10)
  {
    myGLCD.printNumI(0, 98, 50);
    myGLCD.printNumI(minuto_inicial_dosagem_personalizada_1, 106, 50);
  }
  else
  {
    myGLCD.printNumI(minuto_inicial_dosagem_personalizada_1, 98, 50);
  }
  if(hora_final_dosagem_personalizada_1 < 10)
  {
    myGLCD.printNumI(0, 165, 50);
    myGLCD.printNumI(hora_final_dosagem_personalizada_1, 173, 50); 
  }
  else
  {
    myGLCD.printNumI(hora_final_dosagem_personalizada_1, 165, 50);
  }
  if(minuto_final_dosagem_personalizada_1 < 10)
  {
    myGLCD.printNumI(0, 188, 50);
    myGLCD.printNumI(minuto_final_dosagem_personalizada_1, 196, 50);
  }
  else
  {
    myGLCD.printNumI(minuto_final_dosagem_personalizada_1, 188, 50);
  }
  if(segunda_dosagem_personalizada_1 == 1)
  {
    printButton_verde("S", 110, 23, 130, 43);
  }
  else
  {
    printButton("S", 110, 23, 130, 43);
  }
  if(terca_dosagem_personalizada_1 == 2)
  {
    printButton_verde("T", 140, 23, 160, 43);
  }
  else
  {
    printButton("T", 140, 23, 160, 43);
  }
  if(quarta_dosagem_personalizada_1 == 3)
  {
    printButton_verde("Q", 170, 23, 190, 43);
  }
  else
  {
    printButton("Q", 170, 23, 190, 43);
  }    
  if(quinta_dosagem_personalizada_1 == 4)
  {
    printButton_verde("Q", 200, 23, 220, 43);
  }
  else
  {
    printButton("Q", 200, 23, 220, 43);
  }    
  if(sexta_dosagem_personalizada_1 == 5)
  {
    printButton_verde("S", 230, 23, 250, 43);
  }
  else
  {
    printButton("S", 230, 23, 250, 43);
  }
  if(sabado_dosagem_personalizada_1 == 6)
  {
    printButton_verde("S", 260, 23, 280, 43);
  }
  else
  {
    printButton("S", 260, 23, 280, 43);
  }
  if(domingo_dosagem_personalizada_1 == 7)
  {
    printButton_verde("D", 290, 23, 310, 43);
  }
  else
  {
    printButton("D", 290, 23, 310, 43);
  } 
  if (modo_personalizado_on_1 == 1) 
  {
    printButton_verde("ON", 200, 65, 245, 85); 
  } 
  else 
  {
    printButton("ON", 200, 65, 245, 85); 
  }
  if (modo_personalizado_on_1 == 0) 
  {
    printButton_verde("OFF", 250, 65, 295, 85); 
  } 
  else 
  {
    printButton("OFF", 250, 65, 295, 85); 
  }
  setFont(SMALL, 255, 255, 255, 0, 0, 0);    
  myGLCD.print("DOSADORA 2:", 10, 100);   
  myGLCD.print("INICIAL:", 10, 120);  
  myGLCD.print("FINAL:", 118, 120);
  myGLCD.print("QUANTIDADE DE DOSES:", 10, 140);
  myGLCD.print("VOLUME:", 215, 120);    
  myGLCD.print(":", 90, 120);
  myGLCD.print(":", 180, 120);

  myGLCD.printNumF(dose_dosadora_2_personalizada, 1, 275, 120); 
  myGLCD.printNumI(quantidade_dose_dosadora_2_personalizada, 170, 140);
  if(hora_inicial_dosagem_personalizada_2 < 10)
  {
    myGLCD.printNumI(0, 72, 120);
    myGLCD.printNumI(hora_inicial_dosagem_personalizada_2, 80, 120);
  }
  else
  {
    myGLCD.printNumI(hora_inicial_dosagem_personalizada_2, 72, 120);
  }
  if(minuto_inicial_dosagem_personalizada_2 < 10)
  {
    myGLCD.printNumI(0, 98, 120);
    myGLCD.printNumI(minuto_inicial_dosagem_personalizada_2, 106, 120);
  }
  else
  {
    myGLCD.printNumI(minuto_inicial_dosagem_personalizada_2, 98, 120);
  }
  if(hora_final_dosagem_personalizada_2 < 10)
  {
    myGLCD.printNumI(0, 165, 120);
    myGLCD.printNumI(hora_final_dosagem_personalizada_2, 173, 120); 
  }
  else
  {
    myGLCD.printNumI(hora_final_dosagem_personalizada_2, 165, 120);
  }
  if(minuto_final_dosagem_personalizada_2 < 10)
  {
    myGLCD.printNumI(0, 188, 120);
    myGLCD.printNumI(minuto_final_dosagem_personalizada_2, 196, 120);
  }
  else
  {
    myGLCD.printNumI(minuto_final_dosagem_personalizada_2, 188, 120);
  }
  if(segunda_dosagem_personalizada_2 == 1)
  {
    printButton_verde("S", 110, 93, 130, 113);
  }
  else
  {
    printButton("S", 110, 93, 130, 113);
  }
  if(terca_dosagem_personalizada_2 == 2)
  {
    printButton_verde("T", 140, 93, 160, 113);
  }
  else
  {
    printButton("T", 140, 93, 160, 113);
  }
  if(quarta_dosagem_personalizada_2 == 3)
  {
    printButton_verde("Q", 170, 93, 190, 113);
  }
  else
  {
    printButton("Q", 170, 93, 190, 113);
  }    
  if(quinta_dosagem_personalizada_2 == 4)
  {
    printButton_verde("Q", 200, 93, 220, 113);
  }
  else
  {
    printButton("Q", 200, 93, 220, 113);
  }    
  if(sexta_dosagem_personalizada_2 == 5)
  {
    printButton_verde("S", 230, 93, 250, 113);
  }
  else
  {
    printButton("S", 230, 93, 250, 113);
  }
  if(sabado_dosagem_personalizada_2 == 6)
  {
    printButton_verde("S", 260, 93, 280, 113);
  }
  else
  {
    printButton("S", 260, 93, 280, 113);
  }
  if(domingo_dosagem_personalizada_2 == 7)
  {
    printButton_verde("D", 290, 93, 310, 113);
  }
  else
  {
    printButton("D", 290, 93, 310, 113);
  } 
  if (modo_personalizado_on_2 == 1) 
  {
    printButton_verde("ON", 200, 135, 245, 155); 
  } 
  else 
  {
    printButton("ON", 200, 135, 245, 155); 
  }
  if (modo_personalizado_on_2 == 0) 
  {
    printButton_verde("OFF", 250, 135, 295, 155); 
  } 
  else 
  {
    printButton("OFF", 250, 135, 295, 155); 
  } 
  setFont(SMALL, 255, 255, 255, 0, 0, 0);    
  myGLCD.print("DOSADORA 3:", 10, 170);   
  myGLCD.print("INICIAL:", 10, 190);  
  myGLCD.print("FINAL:", 118, 190);
  myGLCD.print("QUANTIDADE DE DOSES:", 10, 210);
  myGLCD.print("VOLUME:", 215, 190);    
  myGLCD.print(":", 90, 190);
  myGLCD.print(":", 180, 190);

  myGLCD.printNumF(dose_dosadora_3_personalizada, 1, 275, 190); 
  myGLCD.printNumI(quantidade_dose_dosadora_3_personalizada, 170, 210);
  if(hora_inicial_dosagem_personalizada_3 < 10)
  {
    myGLCD.printNumI(0, 72, 190);
    myGLCD.printNumI(hora_inicial_dosagem_personalizada_3, 80, 190);
  }
  else
  {
    myGLCD.printNumI(hora_inicial_dosagem_personalizada_3, 72, 190);
  }
  if(minuto_inicial_dosagem_personalizada_3 < 10)
  {
    myGLCD.printNumI(0, 98, 190);
    myGLCD.printNumI(minuto_inicial_dosagem_personalizada_3, 106, 190);
  }
  else
  {
    myGLCD.printNumI(minuto_inicial_dosagem_personalizada_3, 98, 190);
  }
  if(hora_final_dosagem_personalizada_3 < 10)
  {
    myGLCD.printNumI(0, 165, 190);
    myGLCD.printNumI(hora_final_dosagem_personalizada_3, 173, 190); 
  }
  else
  {
    myGLCD.printNumI(hora_final_dosagem_personalizada_3, 165, 190);
  }
  if(minuto_final_dosagem_personalizada_3 < 10)
  {
    myGLCD.printNumI(0, 188, 190);
    myGLCD.printNumI(minuto_final_dosagem_personalizada_3, 196, 190);
  }
  else
  {
    myGLCD.printNumI(minuto_final_dosagem_personalizada_3, 188, 190);
  }
  if(segunda_dosagem_personalizada_3 == 1)
  {
    printButton_verde("S", 110, 163, 130, 183);
  }
  else
  {
    printButton("S", 110, 163, 130, 183);
  }
  if(terca_dosagem_personalizada_3 == 2)
  {
    printButton_verde("T", 140, 163, 160, 183);
  }
  else
  {
    printButton("T", 140, 163, 160, 183);
  }
  if(quarta_dosagem_personalizada_3 == 3)
  {
    printButton_verde("Q", 170, 163, 190, 183);
  }
  else
  {
    printButton("Q", 170, 163, 190, 183);
  }    
  if(quinta_dosagem_personalizada_3 == 4)
  {
    printButton_verde("Q", 200, 163, 220, 183);
  }
  else
  {
    printButton("Q", 200, 163, 220, 183);
  }    
  if(sexta_dosagem_personalizada_3 == 5)
  {
    printButton_verde("S", 230, 163, 250, 183);
  }
  else
  {
    printButton("S", 230, 163, 250, 183);
  }
  if(sabado_dosagem_personalizada_3 == 6)
  {
    printButton_verde("S", 260, 163, 280, 183);
  }
  else
  {
    printButton("S", 260, 163, 280, 183);
  }
  if(domingo_dosagem_personalizada_3 == 7)
  {
    printButton_verde("D", 290, 163, 310, 183);
  }
  else
  {
    printButton("D", 290, 163, 310, 183);
  } 
  if (modo_personalizado_on_3 == 1) 
  {
    printButton_verde("ON", 200, 205, 245, 225); 
  } 
  else 
  {
    printButton("ON", 200, 205, 245, 225); 
  }
  if (modo_personalizado_on_3 == 0) 
  {
    printButton_verde("OFF", 250, 205, 295, 225); 
  } 
  else 
  {
    printButton("OFF", 250, 205, 295, 225); 
  }     
}
