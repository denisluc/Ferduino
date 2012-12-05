//---------------------------------------main screen ----------------------------------------------tela =0
void mainScreen(boolean refreshAll=false)
{
  int ledLevel, s, u;
  String oldval, rtc1, rtcm;
  oldval = day;
  day = String(t.date);                             //refresh date if different

  myGLCD.setColor(64, 64, 64);
  myGLCD.fillRect(0, 226, 400, 239);
  setFont(SMALL, 255, 255, 0, 64, 64, 64);
  myGLCD.print(rtc.getDOWStr(FORMAT_LONG), 10, 227);
  myGLCD.printNumI(t.date, 75, 227);
  myGLCD.print("DE", 95, 227);
  myGLCD.print(rtc.getMonthStr(FORMAT_LONG), 125, 227);
  myGLCD.print("DE", 205, 227);
  myGLCD.printNumI(t.year, 225, 227);
  myGLCD.print(rtc.getTimeStr(FORMAT_LONG), 315, 227);  
  setFont(SMALL, 255, 255, 255, 0, 0, 0);

  if ((oldval != day) || refreshAll)
  {
    char bufferLP[16];
    LP.toCharArray(bufferLP, 16);
    myGLCD.print(bufferLP, 98, 210); //Print Moon Phase Description to LCD

    float lunarCycle = moonPhase(t.year,t.mon, t.date); //get a value for the lunar cycle
    if ((lunarCycle*100) < 1) //Print % of Full to LCD
    { 
      myGLCD.print(" 0.00", 212, 210); 
    }
    else { 
      myGLCD.printNumF(lunarCycle*100, 1, 242, 210);
    }
    myGLCD.print("% ILUMINADA", 280, 210);
    myGLCD.print("FASE LUNAR:", 10, 210);
  }
  if ((blueLed!=bled_out) || refreshAll)       //refresh blue led displays
  {
    blueLed = bled_out;
    ledLevel = LedToPercent(bled_out);
    oldval = "A: " + String(ledLevel) + "%  ";
    char bufferB[9];
    oldval.toCharArray(bufferB, 11);
    s= 117 + (bled_out*1.3);
    if (s > 295)
      u = s - 78;
    else if (s <= 295)
      u = s;
    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect(u, 9, 372, 14);          //hide end of last bar
    setFont(LARGE, 100, 100, 255, 0, 0, 0);
    myGLCD.print(bufferB, 3, 5);              //Blue led value
    myGLCD.drawLine(115, 5, 115, 19);
    myGLCD.fillRect(117, 9, u, 14);           //blue bar
    myGLCD.drawLine(373, 5, 373, 19);
  }

  if ((whiteLed!=wled_out) || refreshAll)         //refresh white led display
  {
    whiteLed = wled_out;
    ledLevel = LedToPercent(wled_out);
    oldval = "B: " + String(ledLevel) + "%  ";
    char bufferW[9];
    oldval.toCharArray(bufferW, 11);
    s= 117 + (wled_out*1.3);

    if (s > 295)
      u = s - 78;
    else if (s <= 295)
      u = s;

    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect(u, 27, 372, 35);               //hide end of last bar
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.print(bufferW, 3, 20);                  //White led value
    myGLCD.drawLine(115, 25, 115, 39);      
    myGLCD.fillRect(117, 29, u, 34);                //white bar
    myGLCD.drawLine(373, 25, 373, 39);
  }

  if ( refreshAll)                                  //draw static elements
  {
    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    myGLCD.print("T.DISSIPADOR:", 12, 86);   
    myGLCD.print("TEMP. AGUA:", 12, 67);
    myGLCD.print("PH DO AQUARIO:", 12, 105);
    myGLCD.print("PH DO REATOR:", 12, 124);
    myGLCD.print("DENSIDADE:", 12, 143);
    myGLCD.print("ORP:", 12, 162);

    myGLCD.print("CHILLER:", 212, 67);
    myGLCD.print("AQUECEDOR:", 212, 86);
    myGLCD.print("REATOR:", 212, 105);
    myGLCD.print("OZONIO:", 212, 124);
    myGLCD.print("REPOSICAO:", 212, 143);
    myGLCD.print("NIVEL:", 212, 162);
    myGLCD.print("TPA:", 212, 181);

    setFont (LARGE, 0, 255, 0, 0, 0, 0);
    myGLCD.drawCircle(179, 84, 2);
    myGLCD.print("C", 182, 81);

    myGLCD.drawCircle(177, 65, 2);               //t. agua
    myGLCD.print("C", 180, 62);                  // t. agua

    myGLCD.print("mV", 100, 159);             //unidade orp
    myGLCD.print("g/l", 152, 140);            //unidade densidade

    myGLCD.setColor(161, 127, 73);                     //draw upper line
    myGLCD.drawLine(1, 50, 398, 50);

    myGLCD.drawRect(7, 57, 199, 205);             //Desenhar retangulos
    myGLCD.drawRect(206, 57, 392, 205);
  } 

  myGLCD.setColor(0, 0, 0);                      
  myGLCD.fillRect(100, 62, 170, 80);               //Apagar temperatura
  myGLCD.fillRect(113, 83, 170, 99);               //Apagar temp. dissipador
  myGLCD.fillRect(124, 102, 190, 119);               //Apagar PH do aquario
  myGLCD.fillRect(118, 121, 190, 137);               //Apagar PH do reator
  myGLCD.fillRect(88, 140, 150, 156);               //Apagar densidade
  myGLCD.fillRect(45, 160, 97, 178);               //Apagar ORP

  myGLCD.fillRect(282, 60, 330, 78);               //Apagar noticia de chiller ligado/desligado
  myGLCD.fillRect(292, 79, 350, 97);              // Apagar noticia de aquecedor ligado/desligado
  myGLCD.fillRect(270, 100, 320, 118);              // Apagar noticia de reator ligado/desligado
  myGLCD.fillRect(270, 119, 320, 137);              // Apagar noticia de ozonio ligado/desligado
  myGLCD.fillRect(287, 138, 350, 155);              // Apagar noticia de reposicao ligado/desligado
  myGLCD.fillRect(263, 158, 390, 174);              // Apagar noticia de nivel normal/anormal
  myGLCD.fillRect(245, 178, 365, 195);              // Apagar noticia de TPA ligado/desligado

  setFont(LARGE, 0, 255, 0, 0, 0, 0);  
  myGLCD.printNumF(tempC, 1, 102, 62); // Temperatura da agua
  myGLCD.printNumF(tempH, 1, 111, 83);   //Temperatura dissipador
  myGLCD.printNumF(PHA, 2, 122, 102);   //PH aqua
  myGLCD.printNumF( PHR, 2, 116, 121);  //PH reator
  myGLCD.printNumI(DEN, 88, 140);   //densidade
  myGLCD.printNumI( ORP, 45, 160);  //ORP 

  if (tempCflag==true) 
  {
    setFont(LARGE, 0, 255, 0, 0, 0, 0);
    myGLCD.print("ON", 279, 62);                       //chiller ligado
  }
  else if (tempCflag==false) 
  {
    setFont(LARGE, 0, 255, 0, 0, 0, 0);
    myGLCD.print("OFF", 279, 62);                        //chiller desligado
  }
  if (tempHflag==true) 
  {
    setFont(LARGE, 0, 255, 0, 0, 0, 0);
    myGLCD.print("ON", 289, 81);           // aquecedor ligado
  } 
  else if (tempHflag==false) 
  {
    setFont(LARGE, 0, 255, 0, 0, 0, 0);
    myGLCD.print("OFF", 289, 81);           // aquecedor desligado
  } 
  if (PHRflag==true) 
  {              
    setFont(LARGE, 0, 255, 0, 0, 0, 0);
    myGLCD.print("ON", 270, 100);           // reator ligado
  } 
  else if (PHRflag==false) 
  {              
    setFont(LARGE, 0, 255, 0, 0, 0, 0);
    myGLCD.print("OFF", 270, 100);           // reator desligado
  }
  if (ORPflag==true) 
  {             
    setFont(LARGE, 0, 255, 0, 0, 0, 0);
    myGLCD.print("ON", 270, 119);           // reator ligado
  } 
  else if (ORPflag==false) 
  {                
    setFont(LARGE, 0, 255, 0, 0, 0, 0);
    myGLCD.print("OFF", 270, 119);           // reator desligado
  }
  if ((tpa_em_andamento==true) && (falha_tpa == false))
  {             
    setFont(LARGE, 0, 255, 0, 0, 0, 0);
    myGLCD.print("ON", 250, 180);           // TPA em andamento
  }
  else if ((tpa_em_andamento==false) && (falha_tpa == false))
  {             
    setFont(LARGE, 0, 255, 0, 0, 0, 0);
    myGLCD.print("OFF", 250, 180);           // TPA não esta em andamento
  }
  if (nivel_status==true) {             
    setFont(LARGE, 255, 0, 0, 0, 0, 0);
    myGLCD.print("BAIXO!", 265, 160);           // Nivel baixo em vermelho
  }
  else if (nivel_status==false) 
  {             
    setFont(LARGE, 0, 255, 0, 0, 0, 0);
    myGLCD.print("NORMAL", 265, 160);           // Nivel nornal
  }  
  if (ato==true) 
  {             
    setFont(LARGE, 0, 255, 0, 0, 0, 0);
    myGLCD.print("ON", 289, 140);           // reposicao ligada
  }
  else if (ato==false)
  {             
    setFont(LARGE, 0, 255, 0, 0, 0, 0);
    myGLCD.print("OFF", 289, 140);           // reposicao desligada
  }

  if (tempAflag==true) 
  {                                //print alarm
    setFont(LARGE, 255, 0, 0, 0, 0, 0);
    myGLCD.printNumF( tempC, 1, 102, 64);              //temperatura em vermelho
  }  
  if (PHAAflag==true) 
  {                                //print alarm
    setFont(LARGE, 255, 0, 0, 0, 0, 0);
    myGLCD.printNumF(PHA, 2, 122, 102);   //PH do aquario em vermelho
  }    
  if (PHRAflag==true) 
  {                                //print alarm
    setFont(LARGE, 255, 0, 0, 0, 0, 0);
    myGLCD.printNumF(PHR, 2, 116, 121);   //PH do reator em vermelho
  }
  if (ORPAflag==true) 
  {                                //print alarm
    setFont(LARGE, 255, 0, 0, 0, 0, 0);
    myGLCD.printNumI(ORP, 45, 160);   //ORP em vermelho
  }    
  if (DENAflag==true) 
  {                                //print alarm
    setFont(LARGE, 255, 0, 0, 0, 0, 0);
    myGLCD.printNumI(DEN, 88, 140);   //PH do reator em vermelho
  }
  if (falha_tpa == true)
  {             
    setFont(LARGE, 255, 0, 0, 0, 0, 0);
    myGLCD.print("FALHA!", 250, 180);           // Sinaliza falha durante uma TPA
  }  
}

