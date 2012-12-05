//-------------------------------------------Touch screen----------------------------
void processMyTouch()
{
  myTouch.read();
  x=myTouch.getX();
  y=myTouch.getY();
  if ((x>=iniC[0]) && (x<=iniC[2]) && (y>=iniC[1]) && (y<=iniC[3]) && (dispScreen!=0))  // volta ao inicio
  {
    waitForIt(iniC[0], iniC[1], iniC[2], iniC[3]);
    LEDtestTick = false;

    if (dispScreen == 3)
    {
      delay(100);
      myGLCD.setColor(0, 0, 0);
      myGLCD.fillRect (1, 15, 318, 99);    //clear above buttons
    }

    modo_manual = false;
    modo_automatico = false;
    modo_personalizado = false;
    modo_calibrar = false;
    dosadora_1_selecionada = false;
    dosadora_2_selecionada = false;
    dosadora_3_selecionada = false; 

    dispScreen=0;
    clearScreen();
    mainScreen(true);   
  } 
  else
  {
    switch (dispScreen) 
    {
    case 0:                       //Tela de inico
      dispScreen=30;
      clearScreen();
      solicitar_senha();
      break;
    case 1:     //------------------------------------Tela de menu-------------------------------------------------
      if ((x>=tanD[0]) && (x<=tanD[2]))               //first column
      {
        if ((y>=tanD[1]) && (y<=tanD[3]))             //press clock
        {
          waitForIt(tanD[0], tanD[1], tanD[2], tanD[3]);
          dispScreen=2;
          clearScreen();
          setClock();
        }

        if ((y>=tesT[1]) && (y<=tesT[3]))              //press LED test
        {
          waitForIt(tesT[0], tesT[1], tesT[2], tesT[3]);
          dispScreen=3;
          clearScreen();
          testScreen(true);
        }  
        if ((y>=temC[1]) && (y<=temC[3]))               //controle de parametros
        {
          waitForIt(temC[0], temC[1], temC[2], temC[3]);
          dispScreen=14;
          clearScreen();
          parametroScreen();
        }
        if ((y>=graF[1]) && (y<=graF[3]))           // seleciona a funcao grafico
        {
          waitForIt(graF[0], graF[1], graF[2], graF[3]);
          dispScreen=9;
          clearScreen();
          graficoScreen();
        } 
      }
      if ((x>=ledW[0]) && (x<=ledW[2]))                 //second column
      {
        if  ((y>=ledW[1]) && (y<=ledW[3]))           //press change LED values
        {
          waitForIt(ledW[0], ledW[1], ledW[2], ledW[3]);
          dispScreen=5;
          WorB=WHITE;
          clearScreen();
          ledSetScreen();
        } 
        if  ((y>=tpaA[1]) && (y<=tpaA[3]))           // seleciona a funcao "TPA automatica"
        {
          waitForIt(tpaA[0], tpaA[1], tpaA[2], tpaA[3]);
          dispScreen=7;
          clearScreen();
          tpaScreen(true);
        }      
        if  ((y>=dosA[1]) && (y<=dosA[3]))           // seleciona a funcao "Bomba dosadora"
        {
          waitForIt(dosA[0], dosA[1], dosA[2], dosA[3]);
          dispScreen=8;
          clearScreen();
          menu_dosadoras();
        } 
        if ((y>=wavM[1]) && (y<=wavM[3]))           // seleciona a funcao "wavemaker"
        {
          waitForIt(wavM[0], wavM[1], wavM[2], wavM[3]);
          dispScreen=10;
          clearScreen();
          waveScreen(true);
        } 
      }
      break;

    case 2:    // -------------------------------------Tela configuracao data e hora---------------------

      if ((y>=houU[1]) && (y<=houU[3])) // Buttons: Time UP
      {
        if((x>=houU[0]) && (x<=houU[2]))
        {
          waitForIt(houU[0], houU[1], houU[2], houU[3]);

          t_temp.hour = (t_temp.hour+1) %24;
          if (t_temp.hour<10)
          {
            myGLCD.printNumI(0, 70, 48);
            myGLCD.printNumI(t_temp.hour, 86, 48);
          }
          else
          {
            myGLCD.printNumI(t_temp.hour, 70, 48);
          }
          if (ct==false)
          {
            ct=true;
            myGLCD.setColor(255, 0, 0);
            myGLCD.setFont(SmallFont);
            myGLCD.print("ALTERADO!", 10, 200);
            myGLCD.setColor(255, 255, 255);
            myGLCD.setFont(BigFont);
          }      
        }
        else if ((x>=minU[0]) && (x<=minU[2]))
        {
          waitForIt(minU[0], minU[1], minU[2], minU[3]);
          t_temp.min = (t_temp.min +1) %60;
          if (t_temp.min<10)
          {
            myGLCD.printNumI(0, 160, 48);
            myGLCD.printNumI(t_temp.min, 176, 48);
          }
          else
          {
            myGLCD.printNumI(t_temp.min, 160, 48);
          }   
          if (ct==false)
          {
            ct=true;
            myGLCD.setColor(255, 0, 0);
            myGLCD.setFont(SmallFont);
            myGLCD.print("ALTERADO!", 10, 200);
            myGLCD.setColor(255, 255, 255);
            myGLCD.setFont(BigFont);
          }
        }
        else if ((x>=segC[0]) && (x<=segC[2]))
        {
          waitForIt(segC[0], segC[1], segC[2], segC[3]);
          t_temp.sec = (t_temp.sec +1) %60;
          if (t_temp.sec==60)
            t_temp.sec=0;
          if (t_temp.sec<10)
          {
            myGLCD.printNumI(0, 250, 48);
            myGLCD.printNumI(t_temp.sec, 266, 48);
          }
          else
          {
            myGLCD.printNumI(t_temp.sec, 250, 48);
          } 
          if (ct==false)
          {
            ct=true;
            myGLCD.setColor(255, 0, 0);
            myGLCD.setFont(SmallFont);
            myGLCD.print("ALTERADO!", 10, 200);
            myGLCD.setColor(255, 255, 255);
            myGLCD.setFont(BigFont);
          }      
        }
      }
      else if ((y>=houD[1]) && (y<=houD[3])) // Buttons: Time DOWN
      {
        if ((x>=houD[0]) && (x<=houD[2]))
        {
          waitForIt(houD[0], houD[1], houD[2], houD[3]);
          t_temp.hour =(t_temp.hour + 23)% 24;
          if (t_temp.hour<10)
          {
            myGLCD.printNumI(0, 70, 48);
            myGLCD.printNumI(t_temp.hour, 86, 48);
          }
          else
          {
            myGLCD.printNumI(t_temp.hour, 70, 48);
          }            
          if (ct==false)
          {
            ct=true;
            myGLCD.setColor(255, 0, 0);
            myGLCD.setFont(SmallFont);
            myGLCD.print("ALTERADO!", 10, 200);
            myGLCD.setColor(255, 255, 255);
            myGLCD.setFont(BigFont);
          }
        }
        else if ((x>=minD[0]) && (x<=minD[2]))
        {
          waitForIt(minD[0], minD[1], minD[2], minD[3]);
          t_temp.min =(t_temp.min +59) %60;
          if (t_temp.min<10)
          {
            myGLCD.printNumI(0, 160, 48);
            myGLCD.printNumI(t_temp.min, 176, 48);
          }
          else
          {
            myGLCD.printNumI(t_temp.min, 160, 48);
          } 
          if (ct==false)
          {
            ct=true;
            myGLCD.setColor(255, 0, 0);
            myGLCD.setFont(SmallFont);
            myGLCD.print("ALTERADO!", 10, 200);
            myGLCD.setColor(255, 255, 255);
            myGLCD.setFont(BigFont);
          }
        }
        else if ((x>=segB[0]) && (x<=segB[2]))
        {
          waitForIt(segB[0], segB[1], segB[2], segB[3]); 
          t_temp.sec = (t_temp.sec +59) %60;
          if (t_temp.sec<10)
          {
            myGLCD.printNumI(0, 250, 48);
            myGLCD.printNumI(t_temp.sec, 266, 48);
          }
          else
          {
            myGLCD.printNumI(t_temp.sec, 250, 48);
          }
          if (ct==false)
          {
            ct=true;
            myGLCD.setColor(255, 0, 0);
            myGLCD.setFont(SmallFont);
            myGLCD.print("ALTERADO!", 10, 200);
            myGLCD.setColor(255, 255, 255);
            myGLCD.setFont(BigFont);
          }
        }
      }

      if ((y>=dayU[1]) && (y<=dayU[3])) // Buttons: Date UP
      {
        if ((x>=dayU[0]) && (x<=dayU[2]))
        {
          waitForIt(dayU[0], dayU[1], dayU[2], dayU[3]);
          t_temp.date+=1;
          t_temp.date=validateDate(t_temp.date, t_temp.mon, t_temp.year);
          if (t_temp.date<10)
          {
            myGLCD.printNumI(0, 70, 132);
            myGLCD.printNumI(t_temp.date, 86, 132);
          }
          else
          {
            myGLCD.printNumI(t_temp.date, 70, 132);
          }
          if (ct==false)
          {
            ct=true;
            myGLCD.setColor(255, 0, 0);
            myGLCD.setFont(SmallFont);
            myGLCD.print("ALTERADO!", 10, 200);
            myGLCD.setColor(255, 255, 255);
            myGLCD.setFont(BigFont);
          }
        }
        else if ((x>=monU[0]) && (x<=monU[2]))
        {
          waitForIt(monU[0], monU[1], monU[2], monU[3]);
          t_temp.mon =(t_temp.mon + 1) %13;
          if (t_temp.mon ==0)
          {
            t_temp.mon = 1;
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

          t_temp.date=validateDateForMonth(t_temp.date, t_temp.mon, t_temp.year);
          if (ct==false)
          {
            ct=true;
            myGLCD.setColor(255, 0, 0);
            myGLCD.setFont(SmallFont);
            myGLCD.print("ALTERADO!", 10, 200);
            myGLCD.setColor(255, 255, 255);
            myGLCD.setFont(BigFont);
          }
        }
        else if ((x>=yeaU[0]) && (x<=yeaU[2]))   
        {
          waitForIt(yeaU[0], yeaU[1], yeaU[2], yeaU[3]);
          t_temp.year+=1;
          if (t_temp.year==2100)
            t_temp.year=2000;
          myGLCD.printNumI(t_temp.year, 230, 132);

          t_temp.date=validateDateForMonth(t_temp.date, t_temp.mon, t_temp.year);
          if (ct==false)
          {
            ct=true;
            myGLCD.setColor(255, 0, 0);
            myGLCD.setFont(SmallFont);
            myGLCD.print("ALTERADO!", 10, 200);
            myGLCD.setColor(255, 255, 255);
            myGLCD.setFont(BigFont);
          }
        }
        t_temp.dow=calcDOW(t_temp.date, t_temp.mon, t_temp.year);
      }
      else if ((y>=dayD[1]) && (y<=dayD[3]))  // Buttons: Date DOWN
      {
        if ((x>=dayD[0]) && (x<=dayD[2]))
        {
          waitForIt(dayD[0], dayD[1], dayD[2], dayD[3]);
          t_temp.date-=1;
          t_temp.date=validateDate(t_temp.date, t_temp.mon, t_temp.year);
          if (t_temp.date<10)
          {
            myGLCD.printNumI(0, 70, 132);
            myGLCD.printNumI(t_temp.date, 86, 132);
          }
          else
          {
            myGLCD.printNumI(t_temp.date, 70, 132);
          }
          if (ct==false)
          {
            ct=true;
            myGLCD.setColor(255, 0, 0);
            myGLCD.setFont(SmallFont);
            myGLCD.print("ALTERADO!", 10, 200);
            myGLCD.setColor(255, 255, 255);
            myGLCD.setFont(BigFont);
          }
        }
        else if ((x>=monD[0]) && (x<=monD[2]))   
        {
          waitForIt(monD[0], monD[1], monD[2], monD[3]);
          t_temp.mon =(t_temp.mon +12) %13;
          if (t_temp.mon ==0)
          {
            t_temp.mon = 12;
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
          t_temp.date=validateDateForMonth(t_temp.date, t_temp.mon, t_temp.year);
          if (ct==false)
          {
            ct=true;
            myGLCD.setColor(255, 0, 0);
            myGLCD.setFont(SmallFont);
            myGLCD.print("ALTERADO!", 10, 200);
            myGLCD.setColor(255, 255, 255);
            myGLCD.setFont(BigFont);
          }
        }

        else if ((x>=yeaD[0]) && (x<=yeaD[2]))
        {
          waitForIt(yeaD[0], yeaD[1], yeaD[2], yeaD[3]);
          t_temp.year = (t_temp.year +2099) %2100;

          myGLCD.printNumI(t_temp.year, 230, 132);
          t_temp.date=validateDateForMonth(t_temp.date, t_temp.mon, t_temp.year);
          if (ct==false)
          {
            ct=true;
            myGLCD.setColor(255, 0, 0);
            myGLCD.setFont(SmallFont);
            myGLCD.print("ALTERADO!", 10, 200);
            myGLCD.setColor(255, 255, 255);
            myGLCD.setFont(BigFont);
          }          
        }
        t_temp.dow=calcDOW(t_temp.date, t_temp.mon, t_temp.year);
      }
      if ((y>=prOK[1]) && (y<=prOK[3]) && (x>=prOK[0]) && (x<=prOK[2]))
      {
        waitForIt(prOK[0], prOK[1], prOK[2], prOK[3]); //funcao salvar
        rtc.halt(true);
        rtc.setTime(t_temp.hour, t_temp.min, t_temp.sec); 
        rtc.setDate(t_temp.date, t_temp.mon, t_temp.year);
        rtc.setDOW(t_temp.dow);
        rtc.halt(false);
        dispScreen=0;
        clearScreen();
        mainScreen(true);
      }
      if ((y>=iniC[1]) && (y<=iniC[3]) && (x>=iniC[0]) && (x<=iniC[2]))
      {
        waitForIt(iniC[0], iniC[1], iniC[2], iniC[3]); //volta ao inicio
        dispScreen=0;
        clearScreen();
        mainScreen(true);
      }
      if ((y>=menU[1]) && (y<=menU[3]) && (x>=menU[0]) && (x<=menU[2]))
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]); //volta ao menu
        dispScreen=1;
        clearScreen();
        menuScreen();
      }     
      break;
    case 3:                    // -------------------Tela testar led------------------------------------------
      if ((x>=stsT[0]) && (x<=stsT[2]) && (y>=stsT[1]) && (y<=stsT[3]))     //press start/stop test
      {
        waitForIt(stsT[0], stsT[1], stsT[2], stsT[3]); 

        if (LEDtestTick == true) 
        {
          LEDtestTick = false;
          testScreen(true);
          myGLCD.setColor(0, 0, 0);
          myGLCD.fillRect (1, 15, 318, 99);    //clear above buttons
        }
        else {
          LEDtestTick = true;             
          testScreen(); 
        }
      } 
      else
      {
        if ((x>=tenM[0]) && (x<=tenM[2]) && (y>=tenM[1]) && (y<=tenM[3]))      //press -10s
        {
          waitForIt(tenM[0], tenM[1], tenM[2], tenM[3]);
          min_cnt -= 10;
          if (min_cnt<0) {
            min_cnt= 0; 
          }

        }
        if ((x>=tenP[0]) && (x<=tenP[2]) && (y>=tenP[1]) && (y<=tenP[2]))    //press +10s
        {
          waitForIt(tenP[0], tenP[1], tenP[2], tenP[3]);
          min_cnt += 10;
          if (min_cnt>1440) {
            min_cnt = 1440; 
          }

        }
        if ((x>=menU[0]) && (x<=menU[2]) && (y>=menU[1]) && (y<=menU[3]))           // volta ao menu
        {
          waitForIt(menU[0], menU[1], menU[2], menU[3]);
          LEDtestTick = false;
          dispScreen=1;
          clearScreen();
          clearScreen();
          menuScreen(); 
        }
      }    
      break;
    case 4:             //---------------------------------------Tela controle de temperatura----------------------------------
      if ((x>=prOK[0]) && (x<=prOK[2]) && (y>=prOK[1]) && (y<=prOK[3]))       //Funcao salvar
      {
        waitForIt(prOK[0], prOK[1], prOK[2], prOK[3]);
        setTempC = temp2beS;
        offTempC = temp2beO;
        alarmTempC = temp2beA;
        dispScreen=0;
        SaveTempToEEPROM();
        clearScreen();
        mainScreen(true);
      } 
      else
      {
        if ((x>=temM[0]) && (x<=temM[2]))                         // Primeira coluna
        {
          if ((y>=temM[1]) && (y<=temM[3]))                      //press temp minus
          {
            waitForIt(temM[0], temM[1], temM[2], temM[3]);
            temp2beS -= 0.1;
            if (temp2beS<10) {
              temp2beS = 10; 
            }
            tempScreen();
          }
          if ((y>=offM[1]) && (y<=offM[3]))                       //press offset minus
          {
            waitForIt(offM[0], offM[1], offM[2], offM[3]);
            temp2beO -= 0.1;
            if (temp2beO <= 0.1) {
              temp2beO = 0.0; 
            }
            tempScreen();
          }          
          if ((y>=almM[1]) && (y<=almM[3]))                        //press alarm minus
          {
            waitForIt(almM[0], almM[1], almM[2], almM[3]);
            temp2beA -= 0.1;
            if (temp2beA < 0.1) {
              temp2beA = 0.0;  
            }
            tempScreen();
          }
        }
        if ((x>=temP[0]) && (x<=temP[2]))                             //Segunda coluna
        {
          if ((y>=temP[1]) && (y<=temP[3]))                      //press temp plus
          {
            waitForIt(temP[0], temP[1], temP[2], temP[3]);
            temp2beS += 0.1;
            if (temp2beS >= 40) {
              temp2beS = 40; 
            }
            tempScreen();
          }
          if ((y>=offP[1]) && (y<=offP[3]))                           //press offset plus
          {
            waitForIt(offP[0], offP[1], offP[2], offP[3]);
            temp2beO += 0.1;
            if (temp2beO >= 10) {
              temp2beO = 9.9; 
            }
            tempScreen();
          }
          if ((y>=almP[1]) && (y<=almP[3]))                           //press alarm plus
          {
            waitForIt(almP[0], almP[1], almP[2], almP[3]);
            temp2beA += 0.1;
            if (temp2beA >= 10) {
              temp2beA = 9.9;  
            }
            tempScreen();
          }
        }
        if ((x>=menU[0]) && x<=menU[2] && (y>=menU[1]) && (y<=menU[3]))           // volta ao menu
        {
          waitForIt(menU[0], menU[1], menU[2], menU[3]);
          dispScreen=14;
          clearScreen();
          parametroScreen();
        } 

      }
      break;
    case 5:         // --------------------------------Tela alterar valores led------------------------------------------------------------
      if ((x>=menU[0]) && (x<=menU[2]) && (y>=menU[1]) && (y<=menU[3]))           // volta ao menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen=1;
        clearScreen();
        menuScreen();
      }

      if ((x>=leWB[0]) && (x<=leWB[2]) && (y>=leWB[1]) && (y<=leWB[3]))       //press show white/blue
      {
        waitForIt(leWB[0], leWB[1], leWB[2], leWB[3]);
        if (WorB)
          WorB = false;
        else
          WorB = true;
        clearScreen();
        ledSetScreen();
      } 
      else if ((x>=leST[0]) && (x<=leST[2]) && (y>=leST[1]) && (y<=leST[3]))       //press change
      {
        waitForIt(leST[0], leST[1], leST[2], leST[3]);
        dispScreen=6;
        clearScreen();
        ledChangeScreen();
      }
      else if ((x>=savE[0]) && (x<=savE[2]) && (y>=savE[1]) && (y<=savE[3]))      //press save to EEPROM
      {
        waitForIt(savE[0], savE[1], savE[2], savE[3]);
        SaveLEDToEEPROM();
        dispScreen=0;
        clearScreen();
        mainScreen(true);
      }


      break;
    case 6:             //----------------------------------Tela alterar potencia dos leds---------------------
      if ((x>=leSh[0]) && (x<=leSh[2]) && (y>=leSh[1]) && (y<=leSh[3]))       //press OK
      {
        waitForIt(leSh[0], leSh[1], leSh[2], leSh[3]);
        dispScreen=5;
        if (WorB) {
          for (int i; i<88; i++) {
            wled[i]=tled[i]; 
          }
        } 
        else {
          for (int i; i<88; i++) {
            bled[i]=tled[i]; 
          }
        }
        clearScreen();
        ledSetScreen();
      }
      else if ((y>=15) && (y<=40))                                    //top row with times was touched
      {
        if ((x>=4) && (x<=316))
        {
          int oldLCT = LedChangTime;
          LedChangTime = map(x, 3, 320, 0, 12);                

          if (oldLCT != LedChangTime)                        //highlight touched time
          {
            myGLCD.setColor(0, 0, 0);
            myGLCD.fillRect((oldLCT*26)+5, 21, (oldLCT*26)+29, 45);
            setFont(SMALL, 0, 255, 255, 0, 0, 0);
            myGLCD.printNumI((oldLCT*2), (oldLCT*26)+10, 22);
            myGLCD.printNumI(((oldLCT*2)+2), (oldLCT*26)+10, 33);
            myGLCD.setColor(255, 0, 0);
            myGLCD.fillRect((LedChangTime*26)+5, 21, (LedChangTime*26)+29, 45);
            setFont(SMALL, 255, 255, 255, 255, 0, 0);
            myGLCD.printNumI((LedChangTime*2), (LedChangTime*26)+10, 22);
            myGLCD.printNumI(((LedChangTime*2)+2), (LedChangTime*26)+10, 33);

            for (int i=0; i<8; i++)                          //print led values for highlighted time
            {
              int k=(LedChangTime*8)+i;

              setFont(SMALL, 255, 255, 255, 0, 0, 0);
              myGLCD.print( "   ", (i*38)+12, 105);
              myGLCD.printNumI( tled[k], (i*38)+12, 105);
            }
          }
        }
      } 
      else if ((y>=70) && (y<=95))       //plus buttons were touched
      {
        for (int i=0; i<8; i++) {                
          if ((x>=(i*38)+10) && (x<=(i*38)+35)) {
            int k= (LedChangTime*8)+i;
            tled[k]++;
            if (tled[k]>255) {
              tled[k]=255; 
            }
            myGLCD.printNumI( tled[k], (i*38)+12, 105);
          }
        }
      }
      else if ((y>=125) && (y<=150))     //minus buttons were touched
      {
        for (int i=0; i<8; i++) {                
          if ((x>=(i*38)+10) && (x<=(i*38)+35)) {
            int k= (LedChangTime*8)+i;
            tled[k]--;
            if (tled[k]<0) {
              tled[k]=0; 
            }
            myGLCD.print( "  ", (i*38)+20, 105);
            myGLCD.printNumI( tled[k], (i*38)+12, 105);
          }
        }  
      }
      if ((x>=menU[0]) && x<=menU[2] && (y>=menU[1]) && (y<=menU[3]))           /// volta ao menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen=1;
        clearScreen();
        menuScreen(); 
      }

      break;
    case 7: //--------------------------------------------- configurar tpa autom.-----------------------------------
      if ((y >= houU[1]) && (y <= houU[3])) // Buttons: Time UP
      {
        if ((x >= houU[0]) && (x <= houU[2])) {
          waitForIt(houU[0], houU[1], houU[2], houU[3]);
          temp2hora = (temp2hora + 1) % 24;
          tpaScreen();
        } 
        if ((x >= minUT[0]) && (x <= minUT[2])) {
          waitForIt(minUT[0], minUT[1], minUT[2], minUT[3]);
          temp2minuto = (temp2minuto + 1) % 60;
          tpaScreen();
        } 
        if ((x >= durC[0]) && (x <= durC[2])) {
          waitForIt(durC[0], durC[1], durC[2], durC[3]); 
          temp2duracaomaximatpa = (temp2duracaomaximatpa + 1) % 60;
          tpaScreen();
        }
      } 
      if ((y >= houD[1]) && (y <= houD[3])) // Buttons: Time DOWN
      {
        if ((x >= houD[0]) && (x <= houD[2])) {
          waitForIt(houD[0], houD[1], houD[2], houD[3]);
          temp2hora = (temp2hora + 23) % 24;
          tpaScreen();
        } 
        if ((x >= minDT[0]) && (x <= minDT[2])) {
          waitForIt(minDT[0], minDT[1], minDT[2], minDT[3]);
          temp2minuto = (temp2minuto + 59) % 60;
          tpaScreen();
        } 
        if ((x >= durB[0]) && (x <= durB[2])) {
          waitForIt(durB[0], durB[1], durB[2], durB[3]);
          temp2duracaomaximatpa = (temp2duracaomaximatpa + 59) % 60;
          tpaScreen();          
        }
      }
      if ((y >= prOK[1]) && (y <= prOK[3]) && (x >= prOK[0]) && (x <= prOK[2])) {
        waitForIt(prOK[0], prOK[1], prOK[2], prOK[3]); //funcao salvar
        hora = temp2hora;
        minuto = temp2minuto;
        duracaomaximatpa = temp2duracaomaximatpa;
        segunda = temp2segunda;
        terca = temp2terca;
        quarta = temp2quarta;
        quinta = temp2quinta;
        sexta = temp2sexta;
        sabado = temp2sabado;
        domingo =temp2domingo;
        SalvartpaEEPROM();
        dispScreen = 0;
        clearScreen();
        mainScreen(true);
      }
      if ((y >= menU[1]) && (y <= menU[3]) && (x >= menU[0]) && (x <= menU[2])) {
        waitForIt(menU[0], menU[1], menU[2], menU[3]); //volta ao menu
        dispScreen = 1;
        clearScreen();
        menuScreen();
      }
      if ((x >= segU[0]) && (x <= segU[2]) && (y >= segU[1]) && (y <= segU[3])) {
        if (temp2segunda == 1) {
          temp2segunda = 0;
          tpaScreen();
        } 
        else {
          temp2segunda = 1;
          tpaScreen();
        }
      }
      if ((x >= terC[0]) && (x <= terC[2]) && (y >= terC[1]) && (y <= terC[3])) {
        if (temp2terca == 2) {
          temp2terca = 0;
          tpaScreen();
        } 
        else {
          temp2terca = 2;
          tpaScreen();
        }
      }
      if ((x >= quaR[0]) && (x <= quaR[2]) && (y >= quaR[1]) && (y <= quaR[3])) {

        if (temp2quarta == 3) {
          temp2quarta = 0;
          tpaScreen();
        } 
        else {
          temp2quarta = 3;
          tpaScreen();
        }
      }
      if ((x >= quiN[0]) && (x <= quiN[2]) && (y >= quiN[1]) && (y <= quiN[3])) {

        if (temp2quinta == 4) {
          temp2quinta = 0;
          tpaScreen();
        } 
        else {
          temp2quinta = 4;
          tpaScreen();
        }
      }
      if ((x >= sexT[0]) && (x <= sexT[2]) && (y >= sexT[1]) && (y <= sexT[3])) {
        if (temp2sexta == 5) {
          temp2sexta = 0;
          tpaScreen();
        } 
        else {
          temp2sexta = 5;
          tpaScreen();
        }
      }
      if ((x >= sabA[0]) && (x <= sabA[2]) && (y >= sabA[1]) && (y <= sabA[3])) {
        if (temp2sabado == 6) {
          temp2sabado = 0;
          tpaScreen();
        } 
        else {
          temp2sabado = 6;
          tpaScreen();
        }
      }
      if ((x >= domI[0]) && (x <= domI[2]) && (y >= domI[1]) && (y <= domI[3])) {
        if (temp2domingo == 7) {
          temp2domingo = 0;
          tpaScreen();
        } 
        else {
          temp2domingo = 7;
          tpaScreen();
        }
      }
      if ((x >= proX[0]) && (x <= proX[2]) && (y >= proX[1]) && (y <= proX[3])) 
      {
        if (falha_tpa == true)
        {
          falha_tpa = false;
          tpa_em_andamento = false;
          tpaScreen();
        }
        else
        {
          falha_tpa = true;
          tpaScreen();
        }
      }

      break;
    case 8: //--------------------------------------------- Escolher dosadora -----------------------------------

      if ((x>=manU[0]) && x<=manU[2] && (y>=manU[1]) && (y<=manU[3]))
      {
        waitForIt(manU[0], manU[1], manU[2], manU[3]);
        modo_manual = true;
        modo_automatico = false;
        modo_personalizado = false;
        modo_calibrar = false;
        dispScreen = 21;
        clearScreen();
        selecionar_dosadora(true);
        setFont(SMALL, 255, 255, 255, 0, 0, 0);
        myGLCD.print("MODO MANUAL SELECIONADO", 15, 220);
      }
      if ((x>=autO[0]) && x<=autO[2] && (y>=autO[1]) && (y<=autO[3]))
      {
        waitForIt(autO[0], autO[1], autO[2], autO[3]);
        modo_manual = false;
        modo_automatico = true;
        modo_personalizado = false;
        modo_calibrar = false;
        dispScreen = 21;
        clearScreen();
        selecionar_dosadora(true);
        setFont(SMALL, 255, 255, 255, 0, 0, 0);
        myGLCD.print("MODO AUTOMATICO SELECIONADO", 15, 220);      
      } 
      if ((x>=perS[0]) && x<=perS[2] && (y>=perS[1]) && (y<=perS[3]))
      {
        waitForIt(perS[0], perS[1], perS[2], perS[3]);
        modo_manual = false;
        modo_automatico = false;
        modo_personalizado = true;
        modo_calibrar = false;
        dispScreen = 21;
        clearScreen();
        selecionar_dosadora(true);
        setFont(SMALL, 255, 255, 255, 0, 0, 0);
        myGLCD.print("MODO PERSONALIZADO SELECIONADO", 15, 220);      
      }
      if ((x>=caliB[0]) && x<=caliB[2] && (y>=caliB[1]) && (y<=caliB[3]))
      {
        waitForIt(caliB[0], caliB[1], caliB[2], caliB[3]);
        modo_manual = false;
        modo_automatico = false;
        modo_personalizado = false;
        modo_calibrar = true;
        dispScreen=21;
        clearScreen();
        selecionar_dosadora(true);
        setFont(SMALL, 255, 255, 255, 0, 0, 0);
        myGLCD.print("MODO CALIBRACAO SELECIONADO", 15, 220);      
      }    
      if ((x>=menU[0]) && x<=menU[2] && (y>=menU[1]) && (y<=menU[3]))           /// volta ao menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen=1;
        clearScreen();
        menuScreen();
        modo_manual = false;
        modo_automatico = false;
        modo_personalizado = false;
        modo_calibrar = false; 
      }          
      if ((x>=reV[0]) && x<=reV[2] && (y>=reV[1]) && (y<=reV[3]))           /// volta ao menu
      {
        waitForIt(reV[0], reV[1], reV[2], reV[3]);
        dispScreen=32;
        clearScreen();
        rever_dosagem_personalizada();
      }
      break;    

    case 9: //  -----------------------------------------Tela escolher graficos-----------------------------------------
      if ((x>=orP[0]) && x<=orP[2] && (y>=orP[1]) && (y<=orP[3]))           
      {
        waitForIt(orP[0], orP[1], orP[2], orP[3]);
        dispScreen=12;
        clearScreen();
        orpScreen(); 
      } 
      if ((x>=phR[0]) && x<=phR[2] && (y>=phR[1]) && (y<=phR[3]))           
      {
        waitForIt(phR[0], phR[1], phR[2], phR[3]);
        dispScreen=13;
        clearScreen();
        PHRScreen(); 
      } 
      if ((x>=tempG[0]) && x<=tempG[2] && (y>=tempG[1]) && (y<=tempG[3]))           
      {
        waitForIt(tempG[0], tempG[1], tempG[2], tempG[3]);
        dispScreen=13;
        clearScreen();
        tempgScreen(); 
      }
      if ((x>=phA[0]) && x<=phA[2] && (y>=phA[1]) && (y<=phA[3]))           
      {
        waitForIt(phA[0], phA[1], phA[2], phA[3]);
        dispScreen=17;
        clearScreen();
        PHAScreen(); 
      } 
      if ((x>=denS[0]) && x<=denS[2] && (y>=denS[1]) && (y<=denS[3]))           
      {
        waitForIt(denS[0], denS[1], denS[2], denS[3]);
        dispScreen=19;
        clearScreen();
        densidadeScreen(); 
      }       

      if ((x>=menU[0]) && x<=menU[2] && (y>=menU[1]) && (y<=menU[3]))           /// volta ao menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen=1;
        clearScreen();
        menuScreen(); 
      }          
      break;

    case 10: //--------------------------------- Tela wavemaker ----------------------------
      if ((x>=menU[0]) && x<=menU[2] && (y>=menU[1]) && (y<=menU[3]))           // volta ao menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen = 1;
        clearScreen();
        menuScreen(); 
      }
      break;

    case 11:  //----------------------------- Tela grafico de temperatura ------------------------------
      if ((x>=menU[0]) && x<=menU[2] && (y>=menU[1]) && (y<=menU[3]))           /// volta ao menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen=1;
        clearScreen();
        menuScreen(); 
      }
      if ((x>=volT[0]) && x<=volT[2] && (y>=volT[1]) && (y<=volT[3]))           // volta a tela de graficos
      {
        waitForIt(volT[0], volT[1], volT[2], volT[3]);
        dispScreen=9;
        clearScreen();
        graficoScreen(); 
      }           
      break;

    case 12:  //--------------------------- Tela grafico de orp---------------------------------------
      if ((x>=menU[0]) && x<=menU[2] && (y>=menU[1]) && (y<=menU[3]))           /// volta ao menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen=1;
        clearScreen();
        menuScreen(); 
      }
      if ((x>=volT[0]) && x<=volT[2] && (y>=volT[1]) && (y<=volT[3]))           // volta a tela de graficos
      {
        waitForIt(volT[0], volT[1], volT[2], volT[3]);
        dispScreen=9;
        clearScreen();
        graficoScreen(); 
      }  
      break;           

    case 13:   //-----------------Tela grafico de ph do aquario----------------------------------
      if ((x>=menU[0]) && x<=menU[2] && (y>=menU[1]) && (y<=menU[3]))           // volta ao menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen=1;
        clearScreen();
        menuScreen(); 
      }
      if ((x>=volT[0]) && x<=volT[2] && (y>=volT[1]) && (y<=volT[3]))         // volta a tela de graficos
      {
        waitForIt(volT[0], volT[1], volT[2], volT[3]);
        dispScreen=9;
        clearScreen();
        graficoScreen(); 
      } 
      break; 

    case 14:  //--------------------------------Tela escolher parametro para configurar-----------------------------------
      if ((x>=orP[0]) && x<=orP[2] && (y>=orP[1]) && (y<=orP[3]))           
      {
        waitForIt(orP[0], orP[1], orP[2], orP[3]);
        dispScreen=16;
        clearScreen();
        config_orp_Screen(true); 
      } 
      if ((x>=phR[0]) && x<=phR[2] && (y>=phR[1]) && (y<=phR[3]))           
      {
        waitForIt(phR[0], phR[1], phR[2], phR[3]);
        dispScreen=15;
        clearScreen();
        config_phR_Screen(true); 
      }
      if ((x>=phA[0]) && x<=phA[2] && (y>=phA[1]) && (y<=phA[3]))           
      {
        waitForIt(phA[0], phA[1], phA[2], phA[3]);
        dispScreen=18;
        clearScreen();
        config_phA_Screen(true); 
      } 
      if ((x>=tempG[0]) && x<=tempG[2] && (y>=tempG[1]) && (y<=tempG[3]))           
      {
        waitForIt(tempG[0], tempG[1], tempG[2], tempG[3]);
        dispScreen=4;
        clearScreen();
        tempScreen(true); 
      }
      if ((x>=caliB[0]) && x<=caliB[2] && (y>=caliB[1]) && (y<=caliB[3]))           
      {
        waitForIt(caliB[0], caliB[1], caliB[2], caliB[3]);
        dispScreen=0;
        clearScreen();
        mainScreen(true); 
      }
      if ((x>=denS[0]) && x<=denS[2] && (y>=denS[1]) && (y<=denS[3]))           
      {
        waitForIt(denS[0], denS[1], denS[2], denS[3]);
        dispScreen=20;
        clearScreen();
        config_dens_Screen(true); 
      }  
      if ((x>=menU[0]) && x<=menU[2] && (y>=menU[1]) && (y<=menU[3]))           /// volta ao menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen=1;
        clearScreen();
        menuScreen(); 
      }          
      break;
    case 15:             //---------------------------------------Tela controle de PH do reator--------
      if ((x>=prOK[0]) && (x<=prOK[2]) && (y>=prOK[1]) && (y<=prOK[3]))       //Funcao salvar
      {
        waitForIt(prOK[0], prOK[1], prOK[2], prOK[3]);
        setPHR = PHR2beS;
        offPHR = PHR2beO;
        alarmPHR = PHR2beA;
        dispScreen=0;
        SavePHRToEEPROM();
        clearScreen();
        mainScreen(true);
      } 
      else
      {
        if ((x>=temM[0]) && (x<=temM[2]))                         // Primeira coluna
        {
          if ((y>=temM[1]) && (y<=temM[3]))                      //press ph minus
          {
            waitForIt(temM[0], temM[1], temM[2], temM[3]);
            PHR2beS -= 0.1;
            config_phR_Screen();
          }
          if ((y>=offM[1]) && (y<=offM[3]))                       //press offset minus
          {
            waitForIt(offM[0], offM[1], offM[2], offM[3]);
            PHR2beO -= 0.1;
            if (PHR2beO <= 0.1) {
              PHR2beO = 0.0; 
            }
            config_phR_Screen();
          }          
          if ((y>=almM[1]) && (y<=almM[3]))                        //press alarm minus
          {
            waitForIt(almM[0], almM[1], almM[2], almM[3]);
            PHR2beA -= 0.1;
            if (PHR2beA < 0.1) {
              PHR2beA = 0.0;  
            }
            config_phR_Screen();
          }
        }
        if ((x>=temP[0]) && (x<=temP[2]))                             //Segunda coluna
        {
          if ((y>=temP[1]) && (y<=temP[3]))                      //press ph plus
          {
            waitForIt(temP[0], temP[1], temP[2], temP[3]);
            PHR2beS += 0.1;
            if (PHR2beS > 9.9)
            {
              PHR2beS = 9.9;
            }
            config_phR_Screen();            
          }
          if ((y>=offP[1]) && (y<=offP[3]))                           //press offset plus
          {
            waitForIt(offP[0], offP[1], offP[2], offP[3]);
            PHR2beO += 0.1;
            if (PHR2beO > 9.9)
            {
              PHR2beO = 9.9;
            }
            config_phR_Screen();

          }
          if ((y>=almP[1]) && (y<=almP[3]))                           //press alarm plus
          {
            waitForIt(almP[0], almP[1], almP[2], almP[3]);
            PHR2beA += 0.1;
            if (PHR2beA > 9.9)
            {
              PHR2beA = 9.9;
            }
            config_phR_Screen();
          }
        }
        if ((x>=menU[0]) && x<=menU[2] && (y>=menU[1]) && (y<=menU[3]))           // volta ao menu
        {
          waitForIt(menU[0], menU[1], menU[2], menU[3]);
          dispScreen=14;
          clearScreen();
          parametroScreen(); 
        } 

      }
      break;
    case 16:             //---------------------------------------Tela controle de ORP---------------------------------
      if ((x>=prOK[0]) && (x<=prOK[2]) && (y>=prOK[1]) && (y<=prOK[3]))       //Funcao salvar
      {
        waitForIt(prOK[0], prOK[1], prOK[2], prOK[3]);
        setORP = ORP2beS;
        offORP = ORP2beO;
        alarmORP = ORP2beA;
        dispScreen=0;
        SaveORPToEEPROM();
        clearScreen();
        mainScreen(true);
      } 
      else
      {
        if ((x>=temM[0]) && (x<=temM[2]))                         // Primeira coluna
        {
          if ((y>=temM[1]) && (y<=temM[3]))                      //press orp minus
          {
            waitForIt(temM[0], temM[1], temM[2], temM[3]);
            ORP2beS -= 10;
            if (ORP2beS < 100)
            {
              ORP2beS =100;
            }
            config_orp_Screen();
          }
          if ((y>=offM[1]) && (y<=offM[3]))                       //press offset minus
          {
            waitForIt(offM[0], offM[1], offM[2], offM[3]);
            ORP2beO -= 10;
            if (ORP2beO < 10)
            {
              ORP2beO = 10;
            }
            config_orp_Screen();
          }          
          if ((y>=almM[1]) && (y<=almM[3]))                        //press alarm minus
          {
            waitForIt(almM[0], almM[1], almM[2], almM[3]);
            ORP2beA -= 10;
            if (ORP2beA < 10)
            {
              ORP2beA = 10;
            }
            config_orp_Screen();
          }
        }
        if ((x>=temP[0]) && (x<=temP[2]))                             //Segunda coluna
        {
          if ((y>=temP[1]) && (y<=temP[3]))                      //press orp plus
          {
            waitForIt(temP[0], temP[1], temP[2], temP[3]);
            ORP2beS += 10;
            if (ORP2beS >999)
            {
              ORP2beS = 990;
            }
            config_orp_Screen();
          }
          if ((y>=offP[1]) && (y<=offP[3]))                           //press offset plus
          {
            waitForIt(offP[0], offP[1], offP[2], offP[3]);
            ORP2beO += 10;
            if (ORP2beO >999)
            {
              ORP2beO = 990;
            }
            config_orp_Screen();
          }
          if ((y>=almP[1]) && (y<=almP[3]))                           //press alarm plus
          {
            waitForIt(almP[0], almP[1], almP[2], almP[3]);
            ORP2beA += 10;
            if (ORP2beA >999)
            {
              ORP2beA = 990;
            }
            config_orp_Screen();
          }
        }
        if ((x>=menU[0]) && x<=menU[2] && (y>=menU[1]) && (y<=menU[3]))           // volta ao menu
        {
          waitForIt(menU[0], menU[1], menU[2], menU[3]);
          dispScreen=14;
          clearScreen();
          parametroScreen();
        } 

      }
      break;
    case 17:   //---------------------Tela grafico de ph do reator de calcio-------------------------------------
      if ((x>=menU[0]) && x<=menU[2] && (y>=menU[1]) && (y<=menU[3]))           /// volta ao menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen=1;
        clearScreen();
        menuScreen(); 
      }
      if ((x>=volT[0]) && x<=volT[2] && (y>=volT[1]) && (y<=volT[3]))           // volta a tela de graficos
      {
        waitForIt(volT[0], volT[1], volT[2], volT[3]);
        dispScreen=9;
        clearScreen();
        graficoScreen(); 
      }  
      break; 

    case 18: //--------------------------Tela configuracao de ph do aquario-----------------------------------
      if ((x>=prOK[0]) && (x<=prOK[2]) && (y>=prOK[1]) && (y<=prOK[3]))       //Funcao salvar
      {
        waitForIt(prOK[0], prOK[1], prOK[2], prOK[3]);
        setPHA = PHA2beS;
        offPHA = PHA2beO;
        alarmPHA = PHA2beA;
        dispScreen=0;
        SavePHAToEEPROM();
        clearScreen();
        mainScreen(true);
      } 
      else
      {
        if ((x>=temM[0]) && (x<=temM[2]))                         // Primeira coluna
        {
          if ((y>=temM[1]) && (y<=temM[3]))                      //press ph minus
          {
            waitForIt(temM[0], temM[1], temM[2], temM[3]);
            PHA2beS -= 0.1;
            config_phA_Screen();
            if (PHA2beS <0.1)
            {
              PHA2beS = 0.0;
            }
          }
          if ((y>=offM[1]) && (y<=offM[3]))                       //press offset minus
          {
            waitForIt(offM[0], offM[1], offM[2], offM[3]);
            PHA2beO -= 0.1;
            if (PHA2beO < 0.1) {
              PHA2beO = 0.0; 
            }
            config_phA_Screen();
          }          
          if ((y>=almM[1]) && (y<=almM[3]))                        //press alarm minus
          {
            waitForIt(almM[0], almM[1], almM[2], almM[3]);
            PHA2beA -= 0.1;
            if (PHA2beA < 0.1) {
              PHA2beA = 0.0;  
            }
            config_phA_Screen();
          }
        }
        if ((x>=temP[0]) && (x<=temP[2]))                             //Segunda coluna
        {
          if ((y>=temP[1]) && (y<=temP[3]))                      //press temp plus
          {
            waitForIt(temP[0], temP[1], temP[2], temP[3]);
            PHA2beS += 0.1;
            if (PHA2beS > 9.9)
            {
              PHA2beS = 9.9;
            }            
            config_phA_Screen();
          }
          if ((y>=offP[1]) && (y<=offP[3]))                           //press offset plus
          {
            waitForIt(offP[0], offP[1], offP[2], offP[3]);
            PHA2beO += 0.1;
            if (PHA2beO > 9.9)
            {
              PHA2beO = 9.9;
            }
            config_phA_Screen();
          }
          if ((y>=almP[1]) && (y<=almP[3]))                           //press alarm plus
          {
            waitForIt(almP[0], almP[1], almP[2], almP[3]);
            PHA2beA += 0.1;
            if (PHA2beA > 9.9)
            {
              PHA2beA = 9.9;
            }
            config_phA_Screen();
          }
        }
        if ((x>=menU[0]) && x<=menU[2] && (y>=menU[1]) && (y<=menU[3]))           // volta ao menu
        {
          waitForIt(menU[0], menU[1], menU[2], menU[3]);
          dispScreen=14;
          clearScreen();
          parametroScreen(); 
        } 

      }
      break;

    case 19://----------------------Tela grafico de densidade----------------------------------
      if ((x>=menU[0]) && x<=menU[2] && (y>=menU[1]) && (y<=menU[3]))           /// volta ao menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen=1;
        clearScreen();
        menuScreen(); 
      }
      if ((x>=volT[0]) && x<=volT[2] && (y>=volT[1]) && (y<=volT[3]))           // volta a tela de graficos
      {
        waitForIt(volT[0], volT[1], volT[2], volT[3]);
        dispScreen=9;
        clearScreen();
        graficoScreen(); 
      }  
      break;

    case 20: //--------------------------Tela configuração densidade  -----------------------------------------------------
      if ((x>=prOK[0]) && (x<=prOK[2]) && (y>=prOK[1]) && (y<=prOK[3]))       //Funcao salvar
      {
        waitForIt(prOK[0], prOK[1], prOK[2], prOK[3]);
        setDEN = DEN2beS;
        offDEN = DEN2beO;
        alarmDEN = DEN2beA;
        dispScreen=0;
        SaveDENToEEPROM();
        clearScreen();
        mainScreen(true);
      } 
      else
      {
        if ((x>=temM[0]) && (x<=temM[2]))                         // Primeira coluna
        {
          if ((y>=temM[1]) && (y<=temM[3]))                      //press densidade minus
          {
            waitForIt(temM[0], temM[1], temM[2], temM[3]);
            DEN2beS -= 1;
            if (DEN2beS < 1000)
            {
              DEN2beS = 1000;
            }
            config_dens_Screen();
          }
          if ((y>=offM[1]) && (y<=offM[3]))                       //press offset minus
          {
            waitForIt(offM[0], offM[1], offM[2], offM[3]);
            DEN2beO -= 1;
            if (DEN2beO < 1)
            {
              DEN2beO = 0;
            }
            config_dens_Screen();
          }          
          if ((y>=almM[1]) && (y<=almM[3]))                        //press alarm minus
          {
            waitForIt(almM[0], almM[1], almM[2], almM[3]);
            DEN2beA -= 1;
            if (DEN2beA < 1)
            {
              DEN2beA =0;
            }
            config_dens_Screen();
          }
        }
        if ((x>=temP[0]) && (x<=temP[2]))                             //Segunda coluna
        {
          if ((y>=temP[1]) && (y<=temP[3]))                      //press densidade plus
          {
            waitForIt(temP[0], temP[1], temP[2], temP[3]);
            DEN2beS += 1;
            if (DEN2beS > 9999)
            {
              DEN2beS = 9999;
            }
            config_dens_Screen();
          }
          if ((y>=offP[1]) && (y<=offP[3]))                           //press offset plus
          {
            waitForIt(offP[0], offP[1], offP[2], offP[3]);
            DEN2beO += 1;
            if (DEN2beO > 9999)
            {
              DEN2beO = 9999;
            }
            config_dens_Screen();
          }
          if ((y>=almP[1]) && (y<=almP[3]))                           //press alarm plus
          {
            waitForIt(almP[0], almP[1], almP[2], almP[3]);
            DEN2beA += 1;
            if (DEN2beA > 9999)
            {
              DEN2beA = 9999;
            }
            config_dens_Screen();
          }
        }
        if ((x>=menU[0]) && x<=menU[2] && (y>=menU[1]) && (y<=menU[3]))           // volta ao menu
        {
          waitForIt(menU[0], menU[1], menU[2], menU[3]);
          dispScreen=14;
          clearScreen();
          parametroScreen(); 
        } 
      }
      break;
    case 21: // ------------------------------------------------ Escolher dosadora -----------------------------------

      if ((x>=dosa1[0]) && x<=dosa1[2] && (y>=dosa1[1]) && (y<=dosa1[3]))         
      {
        waitForIt(dosa1[0], dosa1[1], dosa1[2], dosa1[3]);
        if (modo_manual == true)
        {
          dosadora_1_selecionada = true;
          dosadora_2_selecionada = false;
          dosadora_3_selecionada = false;
          dispScreen = 27;
          clearScreen();
          config_dosagem_manual(true);
        }
        if (modo_automatico == true)
        {
          dosadora_1_selecionada = true;
          dosadora_2_selecionada = false;
          dosadora_3_selecionada = false;
          dispScreen = 28;
          clearScreen();
          config_dosagem_automatica(true);
        }          
        if (modo_personalizado == true)
        {
          dosadora_1_selecionada = true;
          dosadora_2_selecionada = false;
          dosadora_3_selecionada = false;
          dispScreen = 29;
          clearScreen();
          config_dosagem_personalizada(true);
        }

        if (modo_calibrar == true)
        {
          dosadora_1_selecionada = true;
          dosadora_2_selecionada = false;
          dosadora_3_selecionada = false;
          dispScreen = 26;
          clearScreen();
          calibrar_dosadoras(true);
        }           
      }
      if ((x>=dosa2[0]) && x<=dosa2[2] && (y>=dosa2[1]) && (y<=dosa2[3]))         
      {
        waitForIt(dosa2[0], dosa2[1], dosa2[2], dosa2[3]);
        if (modo_manual == true)
        {
          dosadora_2_selecionada = true;
          dosadora_1_selecionada = false;
          dosadora_3_selecionada = false;
          dispScreen = 27;
          clearScreen();
          config_dosagem_manual(true);
        }
        if (modo_automatico == true)
        {
          dosadora_2_selecionada = true;
          dosadora_1_selecionada = false;
          dosadora_3_selecionada = false;
          dispScreen = 28;
          clearScreen();
          config_dosagem_automatica(true);
        }          
        if (modo_personalizado == true)
        {
          dosadora_2_selecionada = true;
          dosadora_1_selecionada = false;
          dosadora_3_selecionada = false;
          dispScreen = 29;
          clearScreen();
          config_dosagem_personalizada(true);
        }

        if (modo_calibrar == true)
        {
          dosadora_2_selecionada = true;
          dosadora_1_selecionada = false;
          dosadora_3_selecionada = false;
          dispScreen = 26;
          clearScreen();
          calibrar_dosadoras(true);
        } 
      }
      if ((x>=dosa3[0]) && x<=dosa3[2] && (y>=dosa3[1]) && (y<=dosa3[3]))         
      {
        waitForIt(dosa3[0], dosa3[1], dosa3[2], dosa3[3]);
        if (modo_manual == true)
        {
          dosadora_3_selecionada = true;
          dosadora_1_selecionada = false;
          dosadora_2_selecionada = false;
          dispScreen = 27;
          clearScreen();
          config_dosagem_manual(true);
        }
        if (modo_automatico == true)
        {
          dosadora_3_selecionada = true;
          dosadora_1_selecionada = false;
          dosadora_2_selecionada = false;
          dispScreen = 28;
          clearScreen();
          config_dosagem_automatica(true);
        }          
        if (modo_personalizado == true)
        {
          dosadora_3_selecionada = true;
          dosadora_1_selecionada = false;
          dosadora_2_selecionada = false;
          dispScreen = 29;
          clearScreen();
          config_dosagem_personalizada(true);
        }

        if (modo_calibrar == true)
        {
          dosadora_3_selecionada = true;
          dosadora_1_selecionada = false;
          dosadora_2_selecionada = false;
          dispScreen = 26;
          clearScreen();
          calibrar_dosadoras(true);
        }  
      }        
      if ((x>=menU[0]) && x<=menU[2] && (y>=menU[1]) && (y<=menU[3]))           // volta ao menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen = 1;
        clearScreen();
        menuScreen(); 
        modo_manual = false;
        modo_automatico = false;
        modo_personalizado = false;
        modo_calibrar = false;
        dosadora_1_selecionada = false;
        dosadora_2_selecionada = false;
        dosadora_3_selecionada = false; 
      }
      if ((x>=volT[0]) && x<=volT[2] && (y>=volT[1]) && (y<=volT[3]))           // volta a tela de escolha da dosadora
      {
        waitForIt(volT[0], volT[1], volT[2], volT[3]);
        dispScreen = 8;
        clearScreen();
        menu_dosadoras();
        modo_manual = false;
        modo_automatico = false;
        modo_personalizado = false;
        modo_calibrar = false;
        dosadora_1_selecionada = false;
        dosadora_2_selecionada = false;
        dosadora_3_selecionada = false; 
      }
      break;

    case 26: //------------------------------------ calibrar dosadoras -------------------------------------------
      if ((x>=almP[0]) && x<=almP[2] && (y>=almP[1]) && (y<=almP[3]) && (dosadora_1_selecionada == true))            //fator calibracao mais.
      {
        waitForIt(almP[0], almP[1], almP[2], almP[3]);
        fator_calib_dosadora_1_temp2 += 0.1;
        if (fator_calib_dosadora_1_temp2 > 99.9)
        {
          fator_calib_dosadora_1_temp2 = 0.0;
        }
        calibrar_dosadoras();
      }
      if ((x>=almM[0]) && x<=almM[2] && (y>=almM[1]) && (y<=almM[3]) && (dosadora_1_selecionada == true))            //fator calibracao menos.
      {
        waitForIt(almM[0], almM[1], almM[2], almM[3]);
        fator_calib_dosadora_1_temp2 -= 0.1;
        if (fator_calib_dosadora_1_temp2 < 0.1)
        {
          fator_calib_dosadora_1_temp2 = 99.9;
        }
        calibrar_dosadoras();
      }
      if ((x>=almP[0]) && x<=almP[2] && (y>=almP[1]) && (y<=almP[3]) && (dosadora_2_selecionada == true))            //fator calibracao mais.
      {
        waitForIt(almP[0], almP[1], almP[2], almP[3]);
        fator_calib_dosadora_2_temp2 += 0.1;
        if (fator_calib_dosadora_2_temp2 > 99.9)
        {
          fator_calib_dosadora_2_temp2 = 0.0;
        }
        calibrar_dosadoras();
      }
      if ((x>=almM[0]) && x<=almM[2] && (y>=almM[1]) && (y<=almM[3]) && (dosadora_2_selecionada == true))            //fator calibracao menos.
      {
        waitForIt(almM[0], almM[1], almM[2], almM[3]);
        fator_calib_dosadora_2_temp2 -= 0.1;
        if (fator_calib_dosadora_2_temp2 < 0.1)
        {
          fator_calib_dosadora_2_temp2 = 99.9;
        }
        calibrar_dosadoras();
      }          
      if ((x>=almP[0]) && x<=almP[2] && (y>=almP[1]) && (y<=almP[3]) && (dosadora_3_selecionada == true))            //fator calibracao mais.
      {
        waitForIt(almP[0], almP[1], almP[2], almP[3]);
        fator_calib_dosadora_3_temp2 += 0.1;
        if (fator_calib_dosadora_3_temp2 > 99.9)
        {
          fator_calib_dosadora_3_temp2 = 0.0;
        }
        calibrar_dosadoras();
      }
      if ((x>=almM[0]) && x<=almM[2] && (y>=almM[1]) && (y<=almM[3]) && (dosadora_3_selecionada == true))            //fator calibracao menos.
      {
        waitForIt(almM[0], almM[1], almM[2], almM[3]);
        fator_calib_dosadora_3_temp2 -= 0.1;
        if (fator_calib_dosadora_3_temp2 < 0.1)
        {
          fator_calib_dosadora_3_temp2 = 99.9;
        }
        calibrar_dosadoras();
      }    
      if ((x>=salV[0]) && x<=salV[2] && (y>=salV[1]) && (y<=salV[3]))
      {
        if(dosadora_1_selecionada == true)
        {
          fator_calib_dosadora_1 = fator_calib_dosadora_1_temp2;
          Salvar_dosadora_EEPROM();
          dispScreen = 21;
          clearScreen();
          selecionar_dosadora(true);
          setFont(SMALL, 255, 255, 255, 0, 0, 0);
          myGLCD.print("MODO CALIBRACAO SELECIONADO", 15, 220);
          modo_manual = false;
          modo_automatico = false;
          modo_personalizado = false;
          modo_calibrar = true;
          dosadora_1_selecionada = false;
          dosadora_2_selecionada = false;
          dosadora_3_selecionada = false;
        }        
        if(dosadora_2_selecionada == true)
        {
          fator_calib_dosadora_2 = fator_calib_dosadora_2_temp2;
          Salvar_dosadora_EEPROM();
          dispScreen = 21;
          clearScreen();
          selecionar_dosadora(true);
          setFont(SMALL, 255, 255, 255, 0, 0, 0);
          myGLCD.print("MODO CALIBRACAO SELECIONADO", 15, 220);
          modo_manual = false;
          modo_automatico = false;
          modo_personalizado = false;
          modo_calibrar = true;
          dosadora_1_selecionada = false;
          dosadora_2_selecionada = false;
          dosadora_3_selecionada = false;
        }
        if(dosadora_3_selecionada == true)
        {
          fator_calib_dosadora_3 = fator_calib_dosadora_3_temp2;
          Salvar_dosadora_EEPROM();
          dispScreen = 21;
          clearScreen();
          selecionar_dosadora(true);
          setFont(SMALL, 255, 255, 255, 0, 0, 0);
          myGLCD.print("MODO CALIBRACAO SELECIONADO", 15, 220);
          modo_manual = false;
          modo_automatico = false;
          modo_personalizado = false;
          modo_calibrar = true;
          dosadora_1_selecionada = false;
          dosadora_2_selecionada = false;
          dosadora_3_selecionada = false;
        }
      }      
      if ((x>=volT[0]) && x<=volT[2] && (y>=volT[1]) && (y<=volT[3]))           // Volta a tela altera configuracao das dosadoras
      {
        waitForIt(volT[0], volT[1], volT[2], volT[3]);
        dispScreen = 21;
        clearScreen();
        selecionar_dosadora(true);
        setFont(SMALL, 255, 255, 255, 0, 0, 0);
        myGLCD.print("MODO CALIBRACAO SELECIONADO", 15, 220);
        modo_manual = false;
        modo_automatico = false;
        modo_personalizado = false;
        modo_calibrar = true;
        dosadora_1_selecionada = false;
        dosadora_2_selecionada = false;
        dosadora_3_selecionada = false; 
      }
      if ((x>=iniciaR[0]) && x<=iniciaR[2] && (y>=iniciaR[1]) && (y<=iniciaR[3]))
      {
        waitForIt(iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
        if((modo_calibrar == true) && (dosadora_1_selecionada == true))
        {
          printButton_verde("INICIAR", iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
          delay(10000);
          digitalWrite(dosadora1, HIGH);
          delay(60000);
          digitalWrite(dosadora1, LOW);
          printButton("INICIAR", iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
        }
        if((modo_calibrar == true) && (dosadora_2_selecionada == true))
        {
          printButton_verde("INICIAR", iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
          delay(10000);
          digitalWrite(dosadora2, HIGH);
          delay(60000);
          digitalWrite(dosadora2, LOW);
          printButton("INICIAR", iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
        }
        if((modo_calibrar == true) && (dosadora_3_selecionada == true))
        {
          printButton_verde("INICIAR", iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
          delay(10000);
          digitalWrite(dosadora3, HIGH);
          delay(60000);
          digitalWrite(dosadora3, LOW);
          printButton("INICIAR", iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
        }
      }      
      break;
    case 27:   // ----------------------------------------- Config dosagem manual --------------------------------------
      if ((x>=almP[0]) && x<=almP[2] && (y>=almP[1]) && (y<=almP[3]) && (dosadora_1_selecionada == true))            //dose manual mais.
      {
        waitForIt(almP[0], almP[1], almP[2], almP[3]);
        dose_dosadora_1_manual += 0.5;
        if (dose_dosadora_1_manual > 99.5)
        {
          dose_dosadora_1_manual = 0.0;
        }
        config_dosagem_manual();
      }
      if ((x>=almM[0]) && x<=almM[2] && (y>=almM[1]) && (y<=almM[3]) && (dosadora_1_selecionada == true))            //dose manual menos.
      {
        waitForIt(almM[0], almM[1], almM[2], almM[3]);
        dose_dosadora_1_manual -= 0.5;
        if (dose_dosadora_1_manual < 0.5)
        {
          dose_dosadora_1_manual = 99.5;
        }
        config_dosagem_manual();
      }
      if ((x>=almP[0]) && x<=almP[2] && (y>=almP[1]) && (y<=almP[3]) && (dosadora_2_selecionada == true))            //dose manual mais.
      {
        waitForIt(almP[0], almP[1], almP[2], almP[3]);
        dose_dosadora_2_manual += 0.5;
        if (dose_dosadora_2_manual > 99.5)
        {
          dose_dosadora_2_manual = 0.0;
        }
        config_dosagem_manual();
      }
      if ((x>=almM[0]) && x<=almM[2] && (y>=almM[1]) && (y<=almM[3]) && (dosadora_2_selecionada == true))            //dose manual menos.
      {
        waitForIt(almM[0], almM[1], almM[2], almM[3]);
        dose_dosadora_2_manual -= 0.5;
        if (dose_dosadora_2_manual < 0.5)
        {
          dose_dosadora_2_manual = 99.5;
        }
        config_dosagem_manual();
      }          
      if ((x>=almP[0]) && x<=almP[2] && (y>=almP[1]) && (y<=almP[3]) && (dosadora_3_selecionada == true))            //dose manual mais.
      {
        waitForIt(almP[0], almP[1], almP[2], almP[3]);
        dose_dosadora_3_manual += 0.5;
        if (dose_dosadora_3_manual > 99.5)
        {
          dose_dosadora_3_manual = 0.5;
        }
        config_dosagem_manual();
      }
      if ((x>=almM[0]) && x<=almM[2] && (y>=almM[1]) && (y<=almM[3]) && (dosadora_3_selecionada == true))            //dose manual menos.
      {
        waitForIt(almM[0], almM[1], almM[2], almM[3]);
        dose_dosadora_3_manual -= 0.5;
        if (dose_dosadora_3_manual < 0.5)
        {
          dose_dosadora_3_manual = 99.5;
        }
        config_dosagem_manual();
      }    

      if ((x>=volT[0]) && x<=volT[2] && (y>=volT[1]) && (y<=volT[3]))           // Volta a tela altera configuracao das dosadoras
      {
        waitForIt(volT[0], volT[1], volT[2], volT[3]);
        dispScreen = 21;
        clearScreen();
        selecionar_dosadora(true);
        setFont(SMALL, 255, 255, 255, 0, 0, 0);
        myGLCD.print("MODO MANUAL SELECIONADO", 15, 220);
        modo_manual = true;
        modo_automatico = false;
        modo_personalizado = false;
        modo_calibrar = false;
        dosadora_1_selecionada = false;
        dosadora_2_selecionada = false;
        dosadora_3_selecionada = false; 
      }
      if ((x>=iniciaR[0]) && x<=iniciaR[2] && (y>=iniciaR[1]) && (y<=iniciaR[3]))
      {
        waitForIt(iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
        if((modo_manual == true) && (dosadora_1_selecionada == true))
        {
          if(fator_calib_dosadora_1 > 10)
          {
            printButton_verde("INICIAR", iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);  
            tempo_dosagem_1 = map ((dose_dosadora_1_manual*2), 0, fator_calib_dosadora_1, 0, 60000);
            tempo_dosagem_1 /= 2;                 
            delay(10000);
            digitalWrite(dosadora1, HIGH);
            delay(tempo_dosagem_1);
            digitalWrite(dosadora1, LOW);
            printButton("INICIAR", iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
          }
        }
        if((modo_manual == true) && (dosadora_2_selecionada == true))
        {
          if(fator_calib_dosadora_2 > 10)
          {
            printButton_verde("INICIAR", iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
            tempo_dosagem_1 = map ((dose_dosadora_2_manual*2), 0, fator_calib_dosadora_2, 0, 60000);
            tempo_dosagem_1 /= 2;
            delay(10000);
            digitalWrite(dosadora2, HIGH);
            delay(tempo_dosagem_1);
            digitalWrite(dosadora2, LOW);
            printButton("INICIAR", iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
          }
        }
        if((modo_manual == true) && (dosadora_3_selecionada == true))
        {
          if(fator_calib_dosadora_3 > 10)
          {
            printButton_verde("INICIAR", iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
            tempo_dosagem_1 = map ((dose_dosadora_3_manual*2), 0, fator_calib_dosadora_3, 0, 60000);
            tempo_dosagem_1 /= 2;
            delay(10000);
            digitalWrite(dosadora3, HIGH);
            delay(tempo_dosagem_1);
            digitalWrite(dosadora3, LOW);
            printButton("INICIAR", iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
          }
        }
      }      
      break;
    case 28:   // ----------------------------------------- Config dosagem automatica --------------------------------------

      if ((x>=volT[0]) && x<=volT[2] && (y>=volT[1]) && (y<=volT[3]))           // // Volta a tela altera configuracao das dosadoras
      {
        waitForIt(volT[0], volT[1], volT[2], volT[3]);
        dispScreen = 21;
        clearScreen();
        selecionar_dosadora(true);
        setFont(SMALL, 255, 255, 255, 0, 0, 0);
        myGLCD.print("MODO AUTOMATICO SELECIONADO", 15, 220);
        modo_manual = false;
        modo_automatico = true;
        modo_personalizado = false;
        modo_calibrar = false;
        dosadora_1_selecionada = false;
        dosadora_2_selecionada = false;
        dosadora_3_selecionada = false; 
      }
      if(dosadora_1_selecionada == true)
      {
        if ((y >= houU[1]) && (y <= houU[3])) // Buttons: Time UP
        {
          if ((x >= houU[0]) && (x <= houU[2])) {
            waitForIt(houU[0], houU[1], houU[2], houU[3]);
            hora_inicial_dosagem_automatica_1_temp2 = (hora_inicial_dosagem_automatica_1_temp2 + 1) % 24;
            config_dosagem_automatica();
          } 
          if ((x >= minUT[0]) && (x <= minUT[2])) {
            waitForIt(minUT[0], minUT[1], minUT[2], minUT[3]);
            minuto_inicial_dosagem_automatica_1_temp2 = (minuto_inicial_dosagem_automatica_1_temp2 + 1) % 60;
            config_dosagem_automatica();
          } 


          if ((x >= houU[0] + deslocamento_botao_x) && (x <= houU[2] + deslocamento_botao_x)) {
            waitForIt(houU[0] + deslocamento_botao_x, houU[1], houU[2] + deslocamento_botao_x, houU[3]);
            hora_final_dosagem_automatica_1_temp2 = (hora_final_dosagem_automatica_1_temp2 + 1) % 24;
            config_dosagem_automatica();
          } 
          if ((x >= minUT[0] + deslocamento_botao_x) && (x <= minUT[2] + deslocamento_botao_x)) {
            waitForIt(minUT[0] + deslocamento_botao_x, minUT[1], minUT[2] + deslocamento_botao_x, minUT[3]);
            minuto_final_dosagem_automatica_1_temp2 = (minuto_final_dosagem_automatica_1_temp2 + 1) % 60;
            config_dosagem_automatica();
          }

        } 
        if ((y >= houD[1]) && (y <= houD[3])) // Buttons: Time DOWN
        {
          if ((x >= houD[0]) && (x <= houD[2])) {
            waitForIt(houD[0], houD[1], houD[2], houD[3]);
            hora_inicial_dosagem_automatica_1_temp2 = (hora_inicial_dosagem_automatica_1_temp2 + 23) % 24;
            config_dosagem_automatica();
          } 
          if ((x >= minDT[0]) && (x <= minDT[2])) {
            waitForIt(minDT[0], minDT[1], minDT[2], minDT[3]);
            minuto_inicial_dosagem_automatica_1_temp2 = (minuto_inicial_dosagem_automatica_1_temp2 + 59) % 60;
            config_dosagem_automatica();
          } 

          if ((x >= houD[0] + deslocamento_botao_x) && (x <= houD[2] + deslocamento_botao_x)) {
            waitForIt(houD[0] + deslocamento_botao_x, houD[1], houD[2] + deslocamento_botao_x, houD[3]);
            hora_final_dosagem_automatica_1_temp2 = (hora_final_dosagem_automatica_1_temp2 + 23) % 24;
            config_dosagem_automatica();
          } 
          if ((x >= minDT[0] + deslocamento_botao_x) && (x <= minDT[2] + deslocamento_botao_x)) {
            waitForIt(minDT[0] + deslocamento_botao_x, minDT[1], minDT[2] + deslocamento_botao_x, minDT[3]);
            minuto_final_dosagem_automatica_1_temp2 = (minuto_final_dosagem_automatica_1_temp2 + 59) % 60;
            config_dosagem_automatica();
          }
        }
        if ((x >= minUT[0]) && (x <= minUT[2]) && (y >= minUT[1]+ deslocamento_botao_y) && (y <= minUT[3] + deslocamento_botao_y)) // Dose diaria mais
        {
          waitForIt(minUT[0], minUT[1] + deslocamento_botao_y, minUT[2], minUT[3] + deslocamento_botao_y);
          dose_dosadora_1_automatica_temp2 += 0.5;
          if(dose_dosadora_1_automatica_temp2 > 999.5)
          {
            dose_dosadora_1_automatica_temp2 = 0.5;
          }
          if(dose_dosadora_1_automatica_temp2 <= 9.5)
          {
            myGLCD.setColor(0, 0, 0);                      
            myGLCD.fillRect(100, 45 + deslocamento_botao_y, 185, 67 + deslocamento_botao_y);
          }           

          config_dosagem_automatica();
        }
        if ((x >= minDT[0]) && (x <= minDT[2]) && (y >= minDT[1] + deslocamento_botao_y) && (y <= minDT[3] + deslocamento_botao_y)) // Dose diaria menos
        {
          waitForIt(minDT[0], minDT[1] + deslocamento_botao_y, minDT[2], minDT[3] + deslocamento_botao_y);
          dose_dosadora_1_automatica_temp2 -= 0.5;
          if(dose_dosadora_1_automatica_temp2 <0.5)
          {
            dose_dosadora_1_automatica_temp2 = 999.5;
          }
          if(dose_dosadora_1_automatica_temp2 <= 9.5)
          {
            myGLCD.setColor(0, 0, 0);                      
            myGLCD.fillRect(100, 45 + deslocamento_botao_y, 185, 67 + deslocamento_botao_y);
          }
          config_dosagem_automatica();
        }
        if ((x >= durC[0]) && (x <= durC[2]) && (y >= durC[1] + deslocamento_botao_y) && (y <= durC[3] + deslocamento_botao_y)) 
        {
          waitForIt(durC[0], durC[1] + deslocamento_botao_y, durC[2], durC[3] + deslocamento_botao_y); 
          quantidade_dose_dosadora_1_automatica_temp2 += 1;
          if(quantidade_dose_dosadora_1_automatica_temp2 > 24)
          {
            quantidade_dose_dosadora_1_automatica_temp2 = 1;
          }
          config_dosagem_automatica();
        }

        if ((x >= durB[0]) && (x <= durB[2]) && (y >= durB[1] + deslocamento_botao_y) && (y <= durB[3] + deslocamento_botao_y)) 
        {
          waitForIt(durB[0], durB[1] + deslocamento_botao_y, durB[2], durB[3] + deslocamento_botao_y);
          quantidade_dose_dosadora_1_automatica_temp2 -= 1;
          if(quantidade_dose_dosadora_1_automatica_temp2 < 1)
          {
            quantidade_dose_dosadora_1_automatica_temp2 = 24;
          }
          config_dosagem_automatica();        
        }
        if ((x >= domI[0]) && (x<= domI[2]) && (y >= domI [1]) && (y <= domI[3])) // Ativar ou desativar modo automatico
        {
          waitForIt(domI[0], domI[1], domI[2], domI[3]);
          if(modo_automatico_on_1_temp2 == 0)
          {
            modo_automatico_on_1_temp2 = 1;
            modo_personalizado_on_1_temp2 = 0;
            config_dosagem_automatica();
          }
          else
          {
            modo_automatico_on_1_temp2 = 0;
            modo_personalizado_on_1_temp2 = 1;
            config_dosagem_automatica();
          }
        }
        if ((y >= salV[1]) && (y <= salV[3]) && (x >= salV[0]) && (x <= salV[2])) 
        {
          waitForIt(salV[0], salV[1], salV[2], salV[3]); //funcao salvar
          dose_dosadora_1_automatica = dose_dosadora_1_automatica_temp2;
          quantidade_dose_dosadora_1_automatica = quantidade_dose_dosadora_1_automatica_temp2;
          modo_automatico_on_1 = modo_automatico_on_1_temp2;
          modo_personalizado_on_1 = modo_personalizado_on_1_temp2;
          hora_inicial_dosagem_automatica_1 = hora_inicial_dosagem_automatica_1_temp2;
          minuto_inicial_dosagem_automatica_1 = minuto_inicial_dosagem_automatica_1_temp2;
          hora_final_dosagem_automatica_1 = hora_final_dosagem_automatica_1_temp2;
          minuto_final_dosagem_automatica_1 = minuto_final_dosagem_automatica_1_temp2;

          if((hora_final_dosagem_automatica_1_temp2 == hora_inicial_dosagem_automatica_1) && (minuto_final_dosagem_automatica_1_temp2 < (minuto_inicial_dosagem_automatica_1+10)))
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);
            myGLCD.print("INTERVALO ", 225, 198);
            myGLCD.print("ERRADO!", 225, 218);

          }
          if(hora_final_dosagem_automatica_1_temp2 < hora_inicial_dosagem_automatica_1)
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);
            myGLCD.print("HORA FINAL", 225, 198);
            myGLCD.print("ERRADA!", 225, 218);
          }
          if((hora_final_dosagem_automatica_1_temp2 == hora_inicial_dosagem_automatica_1) && (minuto_final_dosagem_automatica_1_temp2 >= (minuto_inicial_dosagem_automatica_1+10)))
          {
            dispScreen = 0;
            clearScreen();
            mainScreen(true);
            digitalWrite (4, LOW); 
            file.open(&root, "HDA1.TXT", O_WRITE);
            file.remove();       
            file.open(&root, "HDA1.TXT", O_CREAT | O_APPEND | O_WRITE);
           
            minuto01 = (((hora_final_dosagem_automatica_1 * 60) + (minuto_final_dosagem_automatica_1)) - ((hora_inicial_dosagem_automatica_1 * 60) + (minuto_inicial_dosagem_automatica_1))); 
            minuto01 /= 1 + quantidade_dose_dosadora_1_automatica;
            
            for(int i = 1; i <= quantidade_dose_dosadora_1_automatica; i++)
            { 
              contador += 1;  
              if(contador == 1)
              {
                minuto11 = (hora_inicial_dosagem_automatica_1 * 60) + minuto_inicial_dosagem_automatica_1 + minuto01;
              }
              if(contador > 1)
              {
                minuto11 += minuto01; 
              }
              if(minuto11 < 10)
              {
                file.print("000");  
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 > 10) && (minuto11 < 100))
              {
                file.print("00");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 >= 100) && (minuto11 < 1000))
              {
                file.print("0");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(minuto11 >= 1000)
              {
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }              
            }
            file.close();  
            contador = 0;
            digitalWrite (4, HIGH);
            Salvar_dosadora_EEPROM(); 
          }    

          if(hora_final_dosagem_automatica_1_temp2 > hora_inicial_dosagem_automatica_1)
          {
            dispScreen = 0;
            clearScreen();
            mainScreen(true);
            digitalWrite (4, LOW); 
            file.open(&root, "HDA1.TXT", O_WRITE);
            file.remove();       
            file.open(&root, "HDA1.TXT", O_CREAT | O_APPEND | O_WRITE);

            minuto01 = (((hora_final_dosagem_automatica_1 * 60) + (minuto_final_dosagem_automatica_1)) - ((hora_inicial_dosagem_automatica_1 * 60) + (minuto_inicial_dosagem_automatica_1))); 
            minuto01 /= 1 + quantidade_dose_dosadora_1_automatica;
            
            for(int i = 1; i <= quantidade_dose_dosadora_1_automatica; i++)
            { 
              contador += 1;  
              if(contador == 1)
              {
                minuto11 = (hora_inicial_dosagem_automatica_1 * 60) + minuto_inicial_dosagem_automatica_1 + minuto01;
              }
              if(contador > 1)
              {
                minuto11 += minuto01; 
              }
              if(minuto11 < 10)
              {
                file.print("000");  
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 > 10) && (minuto11 < 100))
              {
                file.print("00");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 >= 100) && (minuto11 < 1000))
              {
                file.print("0");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(minuto11 >= 1000)
              {
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
            }
            file.close();  
            contador = 0;
            digitalWrite (4, HIGH);
            Salvar_dosadora_EEPROM();
          }         
        }
      }
      if(dosadora_2_selecionada == true)
      {
        if ((y >= houU[1]) && (y <= houU[3])) // Buttons: Time UP
        {
          if ((x >= houU[0]) && (x <= houU[2])) {
            waitForIt(houU[0], houU[1], houU[2], houU[3]);
            hora_inicial_dosagem_automatica_2_temp2 = (hora_inicial_dosagem_automatica_2_temp2 + 1) % 24;
            config_dosagem_automatica();
          } 
          if ((x >= minUT[0]) && (x <= minUT[2])) {
            waitForIt(minUT[0], minUT[1], minUT[2], minUT[3]);
            minuto_inicial_dosagem_automatica_2_temp2 = (minuto_inicial_dosagem_automatica_2_temp2 + 1) % 60;
            config_dosagem_automatica();
          } 


          if ((x >= houU[0] + deslocamento_botao_x) && (x <= houU[2] + deslocamento_botao_x)) {
            waitForIt(houU[0] + deslocamento_botao_x, houU[1], houU[2] + deslocamento_botao_x, houU[3]);
            hora_final_dosagem_automatica_2_temp2 = (hora_final_dosagem_automatica_2_temp2 + 1) % 24;
            config_dosagem_automatica();
          } 
          if ((x >= minUT[0] + deslocamento_botao_x) && (x <= minUT[2] + deslocamento_botao_x)) {
            waitForIt(minUT[0] + deslocamento_botao_x, minUT[1], minUT[2] + deslocamento_botao_x, minUT[3]);
            minuto_final_dosagem_automatica_2_temp2 = (minuto_final_dosagem_automatica_2_temp2 + 1) % 60;
            config_dosagem_automatica();
          }

        } 
        if ((y >= houD[1]) && (y <= houD[3])) // Buttons: Time DOWN
        {
          if ((x >= houD[0]) && (x <= houD[2])) {
            waitForIt(houD[0], houD[1], houD[2], houD[3]);
            hora_inicial_dosagem_automatica_2_temp2 = (hora_inicial_dosagem_automatica_2_temp2 + 23) % 24;
            config_dosagem_automatica();
          } 
          if ((x >= minDT[0]) && (x <= minDT[2])) {
            waitForIt(minDT[0], minDT[1], minDT[2], minDT[3]);
            minuto_inicial_dosagem_automatica_2_temp2 = (minuto_inicial_dosagem_automatica_2_temp2 + 59) % 60;
            config_dosagem_automatica();
          } 

          if ((x >= houD[0] + deslocamento_botao_x) && (x <= houD[2] + deslocamento_botao_x)) {
            waitForIt(houD[0] + deslocamento_botao_x, houD[1], houD[2] + deslocamento_botao_x, houD[3]);
            hora_final_dosagem_automatica_2_temp2 = (hora_final_dosagem_automatica_2_temp2 + 23) % 24;
            config_dosagem_automatica();
          } 
          if ((x >= minDT[0] + deslocamento_botao_x) && (x <= minDT[2] + deslocamento_botao_x)) {
            waitForIt(minDT[0] + deslocamento_botao_x, minDT[1], minDT[2] + deslocamento_botao_x, minDT[3]);
            minuto_final_dosagem_automatica_2_temp2 = (minuto_final_dosagem_automatica_2_temp2 + 59) % 60;
            config_dosagem_automatica();
          }
        }
        if ((x >= minUT[0]) && (x <= minUT[2]) && (y >= minUT[1]+ deslocamento_botao_y) && (y <= minUT[3] + deslocamento_botao_y)) // Dose diaria mais
        {
          waitForIt(minUT[0], minUT[1] + deslocamento_botao_y, minUT[2], minUT[3] + deslocamento_botao_y);
          dose_dosadora_2_automatica_temp2 += 0.5;
          if(dose_dosadora_2_automatica_temp2 > 999.5)
          {
            dose_dosadora_2_automatica_temp2 = 0.5;
          }
          if(dose_dosadora_2_automatica_temp2 <= 9.5)
          {
            myGLCD.setColor(0, 0, 0);                      
            myGLCD.fillRect(100, 45 + deslocamento_botao_y, 185, 67 + deslocamento_botao_y);
          }           

          config_dosagem_automatica();
        }
        if ((x >= minDT[0]) && (x <= minDT[2]) && (y >= minDT[1] + deslocamento_botao_y) && (y <= minDT[3] + deslocamento_botao_y)) // Dose diaria menos
        {
          waitForIt(minDT[0], minDT[1] + deslocamento_botao_y, minDT[2], minDT[3] + deslocamento_botao_y);
          dose_dosadora_2_automatica_temp2 -= 0.5;
          if(dose_dosadora_2_automatica_temp2 <0.5)
          {
            dose_dosadora_2_automatica_temp2 = 999.5;
          }
          if(dose_dosadora_2_automatica_temp2 <= 9.5)
          {
            myGLCD.setColor(0, 0, 0);                      
            myGLCD.fillRect(100, 45 + deslocamento_botao_y, 185, 67 + deslocamento_botao_y);
          }
          config_dosagem_automatica();
        }
        if ((x >= durC[0]) && (x <= durC[2]) && (y >= durC[1] + deslocamento_botao_y) && (y <= durC[3] + deslocamento_botao_y)) 
        {
          waitForIt(durC[0], durC[1] + deslocamento_botao_y, durC[2], durC[3] + deslocamento_botao_y); 
          quantidade_dose_dosadora_2_automatica_temp2 += 1;
          if(quantidade_dose_dosadora_2_automatica_temp2 > 24)
          {
            quantidade_dose_dosadora_2_automatica_temp2 = 1;
          }
          config_dosagem_automatica();
        }

        if ((x >= durB[0]) && (x <= durB[2]) && (y >= durB[1] + deslocamento_botao_y) && (y <= durB[3] + deslocamento_botao_y)) 
        {
          waitForIt(durB[0], durB[1] + deslocamento_botao_y, durB[2], durB[3] + deslocamento_botao_y);
          quantidade_dose_dosadora_2_automatica_temp2 -= 1;
          if(quantidade_dose_dosadora_2_automatica_temp2 < 1)
          {
            quantidade_dose_dosadora_2_automatica_temp2 = 24;
          }
          config_dosagem_automatica();        
        }
        if ((x >= domI[0]) && (x<= domI[2]) && (y >= domI [1]) && (y <= domI[3])) // Ativar ou desativar modo automatico
        {
          waitForIt(domI[0], domI[1], domI[2], domI[3]);
          if(modo_automatico_on_2_temp2 == 0)
          {
            modo_automatico_on_2_temp2 = 1;
            modo_personalizado_on_2_temp2 = 0;
            config_dosagem_automatica();
          }
          else
          {
            modo_automatico_on_2_temp2 = 0;
            modo_personalizado_on_2_temp2 = 1;
            config_dosagem_automatica();
          }
        }
        if ((y >= salV[1]) && (y <= salV[3]) && (x >= salV[0]) && (x <= salV[2])) 
        {
          waitForIt(salV[0], salV[1], salV[2], salV[3]); //funcao salvar
          dose_dosadora_2_automatica = dose_dosadora_2_automatica_temp2;
          quantidade_dose_dosadora_2_automatica = quantidade_dose_dosadora_2_automatica_temp2;
          modo_automatico_on_2 = modo_automatico_on_2_temp2;
          modo_personalizado_on_2 = modo_personalizado_on_2_temp2;
          hora_inicial_dosagem_automatica_2 = hora_inicial_dosagem_automatica_2_temp2;
          minuto_inicial_dosagem_automatica_2 = minuto_inicial_dosagem_automatica_2_temp2;
          hora_final_dosagem_automatica_2 = hora_final_dosagem_automatica_2_temp2;
          minuto_final_dosagem_automatica_2 = minuto_final_dosagem_automatica_2_temp2;

          if((hora_final_dosagem_automatica_2_temp2 == hora_inicial_dosagem_automatica_2) && (minuto_final_dosagem_automatica_2_temp2 < (minuto_inicial_dosagem_automatica_2+10)))
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);
            myGLCD.print("INTERVALO ", 225, 198);
            myGLCD.print("ERRADO!", 225, 218);

          }
          if(hora_final_dosagem_automatica_2_temp2 < hora_inicial_dosagem_automatica_2)
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);
            myGLCD.print("HORA FINAL", 225, 198);
            myGLCD.print("ERRADA!", 225, 218);
          }
          if((hora_final_dosagem_automatica_2_temp2 == hora_inicial_dosagem_automatica_2) && (minuto_final_dosagem_automatica_2_temp2 >= (minuto_inicial_dosagem_automatica_2+10)))
          {
            dispScreen = 0;
            clearScreen();
            mainScreen(true);
            digitalWrite (4, LOW); 
            file.open(&root, "HDA2.TXT", O_WRITE);
            file.remove();       
            file.open(&root, "HDA2.TXT", O_CREAT | O_APPEND | O_WRITE);
            
            minuto01 = (((hora_final_dosagem_automatica_2 * 60) + (minuto_final_dosagem_automatica_2)) - ((hora_inicial_dosagem_automatica_2 * 60) + (minuto_inicial_dosagem_automatica_2))); 
            minuto01 /= 1 + quantidade_dose_dosadora_2_automatica;
            
            for(int i = 1; i <= quantidade_dose_dosadora_2_automatica; i++)
            { 
              contador += 1;  
              if(contador == 1)
              {
                minuto11 = (hora_inicial_dosagem_automatica_2 * 60) + minuto_inicial_dosagem_automatica_2 + minuto01;
              }
              if(contador > 1)
              {
                minuto11 += minuto01; 
              }
              if(minuto11 < 10)
              {
                file.print("000");  
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 > 10) && (minuto11 < 100))
              {
                file.print("00");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 >= 100) && (minuto11 < 1000))
              {
                file.print("0");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(minuto11 >= 1000)
              {
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
            }
            file.close();  
            contador = 0;
            digitalWrite (4, HIGH);
            Salvar_dosadora_EEPROM(); 
          }    

          if(hora_final_dosagem_automatica_2_temp2 > hora_inicial_dosagem_automatica_2)
          {
            dispScreen = 0;
            clearScreen();
            mainScreen(true);
            digitalWrite (4, LOW); 
            file.open(&root, "HDA2.TXT", O_WRITE);
            file.remove();       
            file.open(&root, "HDA2.TXT", O_CREAT | O_APPEND | O_WRITE);

            minuto01 = (((hora_final_dosagem_automatica_2 * 60) + (minuto_final_dosagem_automatica_2)) - ((hora_inicial_dosagem_automatica_2 * 60) + (minuto_inicial_dosagem_automatica_2))); 
            minuto01 /= 1 + quantidade_dose_dosadora_2_automatica;
            
            for(int i = 1; i <= quantidade_dose_dosadora_2_automatica; i++)
            { 
              contador += 1;  
              if(contador == 1)
              {
                minuto11 = (hora_inicial_dosagem_automatica_2 * 60) + minuto_inicial_dosagem_automatica_2 + minuto01;
              }
              if(contador > 1)
              {
                minuto11 += minuto01; 
              }
              if(minuto11 < 10)
              {
                file.print("000");  
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 > 10) && (minuto11 < 100))
              {
                file.print("00");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 >= 100) && (minuto11 < 1000))
              {
                file.print("0");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(minuto11 >= 1000)
              {
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
            }
            file.close();  
            contador = 0;
            digitalWrite (4, HIGH);
            Salvar_dosadora_EEPROM();
          }         
        }
      }
      if(dosadora_3_selecionada == true)
      {
        if ((y >= houU[1]) && (y <= houU[3])) // Buttons: Time UP
        {
          if ((x >= houU[0]) && (x <= houU[2])) {
            waitForIt(houU[0], houU[1], houU[2], houU[3]);
            hora_inicial_dosagem_automatica_3_temp2 = (hora_inicial_dosagem_automatica_3_temp2 + 1) % 24;
            config_dosagem_automatica();
          } 
          if ((x >= minUT[0]) && (x <= minUT[2])) {
            waitForIt(minUT[0], minUT[1], minUT[2], minUT[3]);
            minuto_inicial_dosagem_automatica_3_temp2 = (minuto_inicial_dosagem_automatica_3_temp2 + 1) % 60;
            config_dosagem_automatica();
          } 


          if ((x >= houU[0] + deslocamento_botao_x) && (x <= houU[2] + deslocamento_botao_x)) {
            waitForIt(houU[0] + deslocamento_botao_x, houU[1], houU[2] + deslocamento_botao_x, houU[3]);
            hora_final_dosagem_automatica_3_temp2 = (hora_final_dosagem_automatica_3_temp2 + 1) % 24;
            config_dosagem_automatica();
          } 
          if ((x >= minUT[0] + deslocamento_botao_x) && (x <= minUT[2] + deslocamento_botao_x)) {
            waitForIt(minUT[0] + deslocamento_botao_x, minUT[1], minUT[2] + deslocamento_botao_x, minUT[3]);
            minuto_final_dosagem_automatica_3_temp2 = (minuto_final_dosagem_automatica_3_temp2 + 1) % 60;
            config_dosagem_automatica();
          }

        } 
        if ((y >= houD[1]) && (y <= houD[3])) // Buttons: Time DOWN
        {
          if ((x >= houD[0]) && (x <= houD[2])) {
            waitForIt(houD[0], houD[1], houD[2], houD[3]);
            hora_inicial_dosagem_automatica_3_temp2 = (hora_inicial_dosagem_automatica_3_temp2 + 23) % 24;
            config_dosagem_automatica();
          } 
          if ((x >= minDT[0]) && (x <= minDT[2])) {
            waitForIt(minDT[0], minDT[1], minDT[2], minDT[3]);
            minuto_inicial_dosagem_automatica_3_temp2 = (minuto_inicial_dosagem_automatica_3_temp2 + 59) % 60;
            config_dosagem_automatica();
          } 

          if ((x >= houD[0] + deslocamento_botao_x) && (x <= houD[2] + deslocamento_botao_x)) {
            waitForIt(houD[0] + deslocamento_botao_x, houD[1], houD[2] + deslocamento_botao_x, houD[3]);
            hora_final_dosagem_automatica_3_temp2 = (hora_final_dosagem_automatica_3_temp2 + 23) % 24;
            config_dosagem_automatica();
          } 
          if ((x >= minDT[0] + deslocamento_botao_x) && (x <= minDT[2] + deslocamento_botao_x)) {
            waitForIt(minDT[0] + deslocamento_botao_x, minDT[1], minDT[2] + deslocamento_botao_x, minDT[3]);
            minuto_final_dosagem_automatica_3_temp2 = (minuto_final_dosagem_automatica_3_temp2 + 59) % 60;
            config_dosagem_automatica();
          }
        }
        if ((x >= minUT[0]) && (x <= minUT[2]) && (y >= minUT[1]+ deslocamento_botao_y) && (y <= minUT[3] + deslocamento_botao_y)) // Dose diaria mais
        {
          waitForIt(minUT[0], minUT[1] + deslocamento_botao_y, minUT[2], minUT[3] + deslocamento_botao_y);
          dose_dosadora_3_automatica_temp2 += 0.5;
          if(dose_dosadora_3_automatica_temp2 > 999.5)
          {
            dose_dosadora_3_automatica_temp2 = 0.5;
          }
          if(dose_dosadora_3_automatica_temp2 <= 9.5)
          {
            myGLCD.setColor(0, 0, 0);                      
            myGLCD.fillRect(100, 45 + deslocamento_botao_y, 185, 67 + deslocamento_botao_y);
          }           

          config_dosagem_automatica();
        }
        if ((x >= minDT[0]) && (x <= minDT[2]) && (y >= minDT[1] + deslocamento_botao_y) && (y <= minDT[3] + deslocamento_botao_y)) // Dose diaria menos
        {
          waitForIt(minDT[0], minDT[1] + deslocamento_botao_y, minDT[2], minDT[3] + deslocamento_botao_y);
          dose_dosadora_3_automatica_temp2 -= 0.5;
          if(dose_dosadora_3_automatica_temp2 <0.5)
          {
            dose_dosadora_3_automatica_temp2 = 999.5;
          }
          if(dose_dosadora_3_automatica_temp2 <= 9.5)
          {
            myGLCD.setColor(0, 0, 0);                      
            myGLCD.fillRect(100, 45 + deslocamento_botao_y, 185, 67 + deslocamento_botao_y);
          }
          config_dosagem_automatica();
        }
        if ((x >= durC[0]) && (x <= durC[2]) && (y >= durC[1] + deslocamento_botao_y) && (y <= durC[3] + deslocamento_botao_y)) 
        {
          waitForIt(durC[0], durC[1] + deslocamento_botao_y, durC[2], durC[3] + deslocamento_botao_y); 
          quantidade_dose_dosadora_3_automatica_temp2 += 1;
          if(quantidade_dose_dosadora_3_automatica_temp2 > 24)
          {
            quantidade_dose_dosadora_3_automatica_temp2 = 1;
          }
          config_dosagem_automatica();
        }

        if ((x >= durB[0]) && (x <= durB[2]) && (y >= durB[1] + deslocamento_botao_y) && (y <= durB[3] + deslocamento_botao_y)) 
        {
          waitForIt(durB[0], durB[1] + deslocamento_botao_y, durB[2], durB[3] + deslocamento_botao_y);
          quantidade_dose_dosadora_3_automatica_temp2 -= 1;
          if(quantidade_dose_dosadora_3_automatica_temp2 < 1)
          {
            quantidade_dose_dosadora_3_automatica_temp2 = 24;
          }
          config_dosagem_automatica();        
        }
        if ((x >= domI[0]) && (x<= domI[2]) && (y >= domI [1]) && (y <= domI[3])) // Ativar ou desativar modo automatico
        {
          waitForIt(domI[0], domI[1], domI[2], domI[3]);
          if(modo_automatico_on_3_temp2 == 0)
          {
            modo_automatico_on_3_temp2 = 1;
            modo_personalizado_on_3_temp2 = 0;
            config_dosagem_automatica();
          }
          else
          {
            modo_automatico_on_3_temp2 = 0;
            modo_personalizado_on_3_temp2 = 1;
            config_dosagem_automatica();
          }
        }
        if ((y >= salV[1]) && (y <= salV[3]) && (x >= salV[0]) && (x <= salV[2])) 
        {
          waitForIt(salV[0], salV[1], salV[2], salV[3]); //funcao salvar
          dose_dosadora_3_automatica = dose_dosadora_3_automatica_temp2;
          quantidade_dose_dosadora_3_automatica = quantidade_dose_dosadora_3_automatica_temp2;
          modo_automatico_on_3 = modo_automatico_on_3_temp2;
          modo_personalizado_on_3 = modo_personalizado_on_3_temp2;
          hora_inicial_dosagem_automatica_3 = hora_inicial_dosagem_automatica_3_temp2;
          minuto_inicial_dosagem_automatica_3 = minuto_inicial_dosagem_automatica_3_temp2;
          hora_final_dosagem_automatica_3 = hora_final_dosagem_automatica_3_temp2;
          minuto_final_dosagem_automatica_3 = minuto_final_dosagem_automatica_3_temp2;

          if((hora_final_dosagem_automatica_3_temp2 == hora_inicial_dosagem_automatica_3) && (minuto_final_dosagem_automatica_3_temp2 < (minuto_inicial_dosagem_automatica_3+10)))
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);
            myGLCD.print("INTERVALO ", 225, 198);
            myGLCD.print("ERRADO!", 225, 218);

          }
          if(hora_final_dosagem_automatica_3_temp2 < hora_inicial_dosagem_automatica_3)
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);
            myGLCD.print("HORA FINAL", 225, 198);
            myGLCD.print("ERRADA!", 225, 218);
          }
          if((hora_final_dosagem_automatica_3_temp2 == hora_inicial_dosagem_automatica_3) && (minuto_final_dosagem_automatica_3_temp2 >= (minuto_inicial_dosagem_automatica_3+10)))
          {
            dispScreen = 0;
            clearScreen();
            mainScreen(true);
            digitalWrite (4, LOW); 
            file.open(&root, "HDA3.TXT", O_WRITE);
            file.remove();       
            file.open(&root, "HDA3.TXT", O_CREAT | O_APPEND | O_WRITE);

            minuto01 = (((hora_final_dosagem_automatica_3 * 60) + (minuto_final_dosagem_automatica_3)) - ((hora_inicial_dosagem_automatica_3 * 60) + (minuto_inicial_dosagem_automatica_3))); 
            minuto01 /= 1 + quantidade_dose_dosadora_3_automatica;
            
            for(int i = 1; i <= quantidade_dose_dosadora_3_automatica; i++)
            { 
              contador += 1;  
              if(contador == 1)
              {
                minuto11 = (hora_inicial_dosagem_automatica_3 * 60) + minuto_inicial_dosagem_automatica_3 + minuto01;
              }
              if(contador > 1)
              {
                minuto11 += minuto01; 
              }
              if(minuto11 < 10)
              {
                file.print("000");  
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 > 10) && (minuto11 < 100))
              {
                file.print("00");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 >= 100) && (minuto11 < 1000))
              {
                file.print("0");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(minuto11 >= 1000)
              {
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
            }
            file.close();  
            contador = 0;
            digitalWrite (4, HIGH);
            Salvar_dosadora_EEPROM(); 
          }    

          if(hora_final_dosagem_automatica_3_temp2 > hora_inicial_dosagem_automatica_3)
          {
            dispScreen = 0;
            clearScreen();
            mainScreen(true);
            digitalWrite (4, LOW); 
            file.open(&root, "HDA3.TXT", O_WRITE);
            file.remove();       
            file.open(&root, "HDA3.TXT", O_CREAT | O_APPEND | O_WRITE);

            minuto01 = (((hora_final_dosagem_automatica_3 * 60) + (minuto_final_dosagem_automatica_3)) - ((hora_inicial_dosagem_automatica_3 * 60) + (minuto_inicial_dosagem_automatica_3))); 
            minuto01 /= 1 + quantidade_dose_dosadora_3_automatica;
            
            for(int i = 1; i <= quantidade_dose_dosadora_3_automatica; i++)
            { 
              contador += 1;  
              if(contador == 1)
              {
                minuto11 = (hora_inicial_dosagem_automatica_3 * 60) + minuto_inicial_dosagem_automatica_3 + minuto01;
              }
              if(contador > 1)
              {
                minuto11 += minuto01; 
              }
              if(minuto11 < 10)
              {
                file.print("000");  
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 > 10) && (minuto11 < 100))
              {
                file.print("00");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 >= 100) && (minuto11 < 1000))
              {
                file.print("0");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(minuto11 >= 1000)
              {
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
            }
            file.close();  
            contador = 0;
            digitalWrite (4, HIGH);
            Salvar_dosadora_EEPROM();
          }         
        }
      }
      break;

    case 29:   // ----------------------------------------- Config dosagem personalizada --------------------------------------
      if ((x>=menU[0]) && x<=menU[2] && (y>=menU[1]) && (y<=menU[3]))           // volta ao menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen = 1;
        clearScreen();
        menuScreen(); 
        modo_manual = false;
        modo_automatico = false;
        modo_personalizado = false;
        modo_calibrar = false;
        dosadora_1_selecionada = false;
        dosadora_2_selecionada = false;
        dosadora_3_selecionada = false;
      }
      if ((x>=volT[0]) && x<=volT[2] && (y>=volT[1]) && (y<=volT[3]))           // Volta a tela altera configuracao das dosadoras
      {
        waitForIt(volT[0], volT[1], volT[2], volT[3]);
        dispScreen = 21;
        clearScreen();
        selecionar_dosadora(true);
        setFont(SMALL, 255, 255, 255, 0, 0, 0);
        myGLCD.print("MODO PERSONALIZADO SELECIONADO", 15, 220);
        modo_manual = false;
        modo_automatico = false;
        modo_personalizado = true;
        modo_calibrar = false;
        dosadora_1_selecionada = false;
        dosadora_2_selecionada = false;
        dosadora_3_selecionada = false; 
      }
      if ((y >= proX[1]) && (y <= proX[3]) && (x >= proX[0]) && (x <= proX[2])) {
        waitForIt(proX[0], proX[1], proX[2], proX[3]); //funcao salvar
        dispScreen = 31;
        clearScreen();
        config_dosagem_personalizada_2(true);
      }
      if(dosadora_1_selecionada == true)
      {
        if ((y >= houU[1]) && (y <= houU[3])) // Buttons: Time UP
        {
          if ((x >= houU[0]) && (x <= houU[2])) {
            waitForIt(houU[0], houU[1], houU[2], houU[3]);
            temp2hora_inicial_dosagem_personalizada_1 = (temp2hora_inicial_dosagem_personalizada_1 + 1) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minUT[0]) && (x <= minUT[2])) {
            waitForIt(minUT[0], minUT[1], minUT[2], minUT[3]);
            temp2minuto_inicial_dosagem_personalizada_1 = (temp2minuto_inicial_dosagem_personalizada_1 + 1) % 60;
            config_dosagem_personalizada();
          } 


          if ((x >= houU[0] + deslocamento_botao_x) && (x <= houU[2] + deslocamento_botao_x)) {
            waitForIt(houU[0] + deslocamento_botao_x, houU[1], houU[2] + deslocamento_botao_x, houU[3]);
            temp2hora_final_dosagem_personalizada_1 = (temp2hora_final_dosagem_personalizada_1 + 1) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minUT[0] + deslocamento_botao_x) && (x <= minUT[2] + deslocamento_botao_x)) {
            waitForIt(minUT[0] + deslocamento_botao_x, minUT[1], minUT[2] + deslocamento_botao_x, minUT[3]);
            temp2minuto_final_dosagem_personalizada_1 = (temp2minuto_final_dosagem_personalizada_1 + 1) % 60;
            config_dosagem_personalizada();
          }

        } 
        if ((y >= houD[1]) && (y <= houD[3])) // Buttons: Time DOWN
        {
          if ((x >= houD[0]) && (x <= houD[2])) {
            waitForIt(houD[0], houD[1], houD[2], houD[3]);
            temp2hora_inicial_dosagem_personalizada_1 = (temp2hora_inicial_dosagem_personalizada_1 + 23) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minDT[0]) && (x <= minDT[2])) {
            waitForIt(minDT[0], minDT[1], minDT[2], minDT[3]);
            temp2minuto_inicial_dosagem_personalizada_1 = (temp2minuto_inicial_dosagem_personalizada_1 + 59) % 60;
            config_dosagem_personalizada();
          } 

          if ((x >= houD[0] + deslocamento_botao_x) && (x <= houD[2] + deslocamento_botao_x)) {
            waitForIt(houD[0] + deslocamento_botao_x, houD[1], houD[2] + deslocamento_botao_x, houD[3]);
            temp2hora_final_dosagem_personalizada_1 = (temp2hora_final_dosagem_personalizada_1 + 23) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minDT[0] + deslocamento_botao_x) && (x <= minDT[2] + deslocamento_botao_x)) {
            waitForIt(minDT[0] + deslocamento_botao_x, minDT[1], minDT[2] + deslocamento_botao_x, minDT[3]);
            temp2minuto_final_dosagem_personalizada_1 = (temp2minuto_final_dosagem_personalizada_1 + 59) % 60;
            config_dosagem_personalizada();
          }
        }

        if ((x >= segU[0]) && (x <= segU[2]) && (y >= segU[1]) && (y <= segU[3])) {
          if (temp2segunda_dosagem_personalizada_1 == 1) {
            temp2segunda_dosagem_personalizada_1 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2segunda_dosagem_personalizada_1 = 1;
            config_dosagem_personalizada();
          }
        }
        if ((x >= terC[0]) && (x <= terC[2]) && (y >= terC[1]) && (y <= terC[3])) {
          if (temp2terca_dosagem_personalizada_1 == 2) {
            temp2terca_dosagem_personalizada_1 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2terca_dosagem_personalizada_1 = 2;
            config_dosagem_personalizada();
          }
        }
        if ((x >= quaR[0]) && (x <= quaR[2]) && (y >= quaR[1]) && (y <= quaR[3])) {

          if (temp2quarta_dosagem_personalizada_1 == 3) {
            temp2quarta_dosagem_personalizada_1 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2quarta_dosagem_personalizada_1 = 3;
            config_dosagem_personalizada();
          }
        }
        if ((x >= quiN[0]) && (x <= quiN[2]) && (y >= quiN[1]) && (y <= quiN[3])) {

          if (temp2quinta_dosagem_personalizada_1 == 4) {
            temp2quinta_dosagem_personalizada_1 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2quinta_dosagem_personalizada_1 = 4;
            config_dosagem_personalizada();
          }
        }
        if ((x >= sexT[0]) && (x <= sexT[2]) && (y >= sexT[1]) && (y <= sexT[3])) {
          if (temp2sexta_dosagem_personalizada_1 == 5) {
            temp2sexta_dosagem_personalizada_1 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2sexta_dosagem_personalizada_1 = 5;
            config_dosagem_personalizada();
          }
        }
        if ((x >= sabA[0]) && (x <= sabA[2]) && (y >= sabA[1]) && (y <= sabA[3])) {
          if (temp2sabado_dosagem_personalizada_1 == 6) {
            temp2sabado_dosagem_personalizada_1 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2sabado_dosagem_personalizada_1 = 6;
            config_dosagem_personalizada();
          }
        }
        if ((x >= domI[0]) && (x <= domI[2]) && (y >= domI[1]) && (y <= domI[3])) {
          if (temp2domingo_dosagem_personalizada_1 == 7) {
            temp2domingo_dosagem_personalizada_1 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2domingo_dosagem_personalizada_1 = 7;
            config_dosagem_personalizada();
          }
        }
      }
      if(dosadora_2_selecionada == true)
      {
        if ((y >= houU[1]) && (y <= houU[3])) // Buttons: Time UP
        {
          if ((x >= houU[0]) && (x <= houU[2])) {
            waitForIt(houU[0], houU[1], houU[2], houU[3]);
            temp2hora_inicial_dosagem_personalizada_2 = (temp2hora_inicial_dosagem_personalizada_2 + 1) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minUT[0]) && (x <= minUT[2])) {
            waitForIt(minUT[0], minUT[1], minUT[2], minUT[3]);
            temp2minuto_inicial_dosagem_personalizada_2 = (temp2minuto_inicial_dosagem_personalizada_2 + 1) % 60;
            config_dosagem_personalizada();
          } 


          if ((x >= houU[0] + deslocamento_botao_x) && (x <= houU[2] + deslocamento_botao_x)) {
            waitForIt(houU[0] + deslocamento_botao_x, houU[1], houU[2] + deslocamento_botao_x, houU[3]);
            temp2hora_final_dosagem_personalizada_2 = (temp2hora_final_dosagem_personalizada_2 + 1) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minUT[0] + deslocamento_botao_x) && (x <= minUT[2] + deslocamento_botao_x)) {
            waitForIt(minUT[0] + deslocamento_botao_x, minUT[1], minUT[2] + deslocamento_botao_x, minUT[3]);
            temp2minuto_final_dosagem_personalizada_2 = (temp2minuto_final_dosagem_personalizada_2 + 1) % 60;
            config_dosagem_personalizada();
          }

        } 
        if ((y >= houD[1]) && (y <= houD[3])) // Buttons: Time DOWN
        {
          if ((x >= houD[0]) && (x <= houD[2])) {
            waitForIt(houD[0], houD[1], houD[2], houD[3]);
            temp2hora_inicial_dosagem_personalizada_2 = (temp2hora_inicial_dosagem_personalizada_2 + 23) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minDT[0]) && (x <= minDT[2])) {
            waitForIt(minDT[0], minDT[1], minDT[2], minDT[3]);
            temp2minuto_inicial_dosagem_personalizada_2 = (temp2minuto_inicial_dosagem_personalizada_2 + 59) % 60;
            config_dosagem_personalizada();
          } 

          if ((x >= houD[0] + deslocamento_botao_x) && (x <= houD[2] + deslocamento_botao_x)) {
            waitForIt(houD[0] + deslocamento_botao_x, houD[1], houD[2] + deslocamento_botao_x, houD[3]);
            temp2hora_final_dosagem_personalizada_2 = (temp2hora_final_dosagem_personalizada_2 + 23) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minDT[0] + deslocamento_botao_x) && (x <= minDT[2] + deslocamento_botao_x)) {
            waitForIt(minDT[0] + deslocamento_botao_x, minDT[1], minDT[2] + deslocamento_botao_x, minDT[3]);
            temp2minuto_final_dosagem_personalizada_2 = (temp2minuto_final_dosagem_personalizada_2 + 59) % 60;
            config_dosagem_personalizada();
          }
        }

        if ((x >= segU[0]) && (x <= segU[2]) && (y >= segU[1]) && (y <= segU[3])) {
          if (temp2segunda_dosagem_personalizada_2 == 1) {
            temp2segunda_dosagem_personalizada_2 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2segunda_dosagem_personalizada_2 = 1;
            config_dosagem_personalizada();
          }
        }
        if ((x >= terC[0]) && (x <= terC[2]) && (y >= terC[1]) && (y <= terC[3])) {
          if (temp2terca_dosagem_personalizada_2 == 2) {
            temp2terca_dosagem_personalizada_2 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2terca_dosagem_personalizada_2 = 2;
            config_dosagem_personalizada();
          }
        }
        if ((x >= quaR[0]) && (x <= quaR[2]) && (y >= quaR[1]) && (y <= quaR[3])) {

          if (temp2quarta_dosagem_personalizada_2 == 3) {
            temp2quarta_dosagem_personalizada_2 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2quarta_dosagem_personalizada_2 = 3;
            config_dosagem_personalizada();
          }
        }
        if ((x >= quiN[0]) && (x <= quiN[2]) && (y >= quiN[1]) && (y <= quiN[3])) {

          if (temp2quinta_dosagem_personalizada_2 == 4) {
            temp2quinta_dosagem_personalizada_2 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2quinta_dosagem_personalizada_2 = 4;
            config_dosagem_personalizada();
          }
        }
        if ((x >= sexT[0]) && (x <= sexT[2]) && (y >= sexT[1]) && (y <= sexT[3])) {
          if (temp2sexta_dosagem_personalizada_2 == 5) {
            temp2sexta_dosagem_personalizada_2 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2sexta_dosagem_personalizada_2 = 5;
            config_dosagem_personalizada();
          }
        }
        if ((x >= sabA[0]) && (x <= sabA[2]) && (y >= sabA[1]) && (y <= sabA[3])) {
          if (temp2sabado_dosagem_personalizada_2 == 6) {
            temp2sabado_dosagem_personalizada_2 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2sabado_dosagem_personalizada_2 = 6;
            config_dosagem_personalizada();
          }
        }
        if ((x >= domI[0]) && (x <= domI[2]) && (y >= domI[1]) && (y <= domI[3])) {
          if (temp2domingo_dosagem_personalizada_2 == 7) {
            temp2domingo_dosagem_personalizada_2 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2domingo_dosagem_personalizada_2 = 7;
            config_dosagem_personalizada();
          }
        }
      }
      if(dosadora_3_selecionada == true)
      {
        if ((y >= houU[1]) && (y <= houU[3])) // Buttons: Time UP
        {
          if ((x >= houU[0]) && (x <= houU[2])) {
            waitForIt(houU[0], houU[1], houU[2], houU[3]);
            temp2hora_inicial_dosagem_personalizada_3 = (temp2hora_inicial_dosagem_personalizada_3 + 1) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minUT[0]) && (x <= minUT[2])) {
            waitForIt(minUT[0], minUT[1], minUT[2], minUT[3]);
            temp2minuto_inicial_dosagem_personalizada_3 = (temp2minuto_inicial_dosagem_personalizada_3 + 1) % 60;
            config_dosagem_personalizada();
          } 


          if ((x >= houU[0] + deslocamento_botao_x) && (x <= houU[2] + deslocamento_botao_x)) {
            waitForIt(houU[0] + deslocamento_botao_x, houU[1], houU[2] + deslocamento_botao_x, houU[3]);
            temp2hora_final_dosagem_personalizada_3 = (temp2hora_final_dosagem_personalizada_3 + 1) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minUT[0] + deslocamento_botao_x) && (x <= minUT[2] + deslocamento_botao_x)) {
            waitForIt(minUT[0] + deslocamento_botao_x, minUT[1], minUT[2] + deslocamento_botao_x, minUT[3]);
            temp2minuto_final_dosagem_personalizada_3 = (temp2minuto_final_dosagem_personalizada_3 + 1) % 60;
            config_dosagem_personalizada();
          }

        } 
        if ((y >= houD[1]) && (y <= houD[3])) // Buttons: Time DOWN
        {
          if ((x >= houD[0]) && (x <= houD[2])) {
            waitForIt(houD[0], houD[1], houD[2], houD[3]);
            temp2hora_inicial_dosagem_personalizada_3 = (temp2hora_inicial_dosagem_personalizada_3 + 23) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minDT[0]) && (x <= minDT[2])) {
            waitForIt(minDT[0], minDT[1], minDT[2], minDT[3]);
            temp2minuto_inicial_dosagem_personalizada_3 = (temp2minuto_inicial_dosagem_personalizada_3 + 59) % 60;
            config_dosagem_personalizada();
          } 

          if ((x >= houD[0] + deslocamento_botao_x) && (x <= houD[2] + deslocamento_botao_x)) {
            waitForIt(houD[0] + deslocamento_botao_x, houD[1], houD[2] + deslocamento_botao_x, houD[3]);
            temp2hora_final_dosagem_personalizada_3 = (temp2hora_final_dosagem_personalizada_3 + 23) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minDT[0] + deslocamento_botao_x) && (x <= minDT[2] + deslocamento_botao_x)) {
            waitForIt(minDT[0] + deslocamento_botao_x, minDT[1], minDT[2] + deslocamento_botao_x, minDT[3]);
            temp2minuto_final_dosagem_personalizada_3 = (temp2minuto_final_dosagem_personalizada_3 + 59) % 60;
            config_dosagem_personalizada();
          }
        }

        if ((x >= segU[0]) && (x <= segU[2]) && (y >= segU[1]) && (y <= segU[3])) {
          if (temp2segunda_dosagem_personalizada_3 == 1) {
            temp2segunda_dosagem_personalizada_3 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2segunda_dosagem_personalizada_3 = 1;
            config_dosagem_personalizada();
          }
        }
        if ((x >= terC[0]) && (x <= terC[2]) && (y >= terC[1]) && (y <= terC[3])) {
          if (temp2terca_dosagem_personalizada_3 == 2) {
            temp2terca_dosagem_personalizada_3 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2terca_dosagem_personalizada_3 = 2;
            config_dosagem_personalizada();
          }
        }
        if ((x >= quaR[0]) && (x <= quaR[2]) && (y >= quaR[1]) && (y <= quaR[3])) {

          if (temp2quarta_dosagem_personalizada_3 == 3) {
            temp2quarta_dosagem_personalizada_3 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2quarta_dosagem_personalizada_3 = 3;
            config_dosagem_personalizada();
          }
        }
        if ((x >= quiN[0]) && (x <= quiN[2]) && (y >= quiN[1]) && (y <= quiN[3])) {

          if (temp2quinta_dosagem_personalizada_3 == 4) {
            temp2quinta_dosagem_personalizada_3 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2quinta_dosagem_personalizada_3 = 4;
            config_dosagem_personalizada();
          }
        }
        if ((x >= sexT[0]) && (x <= sexT[2]) && (y >= sexT[1]) && (y <= sexT[3])) {
          if (temp2sexta_dosagem_personalizada_3 == 5) {
            temp2sexta_dosagem_personalizada_3 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2sexta_dosagem_personalizada_3 = 5;
            config_dosagem_personalizada();
          }
        }
        if ((x >= sabA[0]) && (x <= sabA[2]) && (y >= sabA[1]) && (y <= sabA[3])) {
          if (temp2sabado_dosagem_personalizada_3 == 6) {
            temp2sabado_dosagem_personalizada_3 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2sabado_dosagem_personalizada_3 = 6;
            config_dosagem_personalizada();
          }
        }
        if ((x >= domI[0]) && (x <= domI[2]) && (y >= domI[1]) && (y <= domI[3])) {
          if (temp2domingo_dosagem_personalizada_3 == 7) {
            temp2domingo_dosagem_personalizada_3 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2domingo_dosagem_personalizada_3 = 7;
            config_dosagem_personalizada();
          }
        }
      }
      break;

    case 30:  // ----------------------------------------- Digitar a senha --------------------------------------------

      if ((x>=boT1[0]) && (x<=boT1[2]) && (y>=boT1[1]) && (y<=boT1[3]))  // Botao: 1
      {
        waitForIt(boT1[0], boT1[1], boT1[2] ,boT1[3]);
        updateStr('1');
      }

      if ((x>=boT2[0]) && (x<=boT2[2]) && (y>=boT2[1]) && (y<=boT2[3]))  // Botao: 2
      {
        waitForIt(boT2[0], boT2[1], boT2[2], boT2[3]);
        updateStr('2');
      }
      if ((x>=boT3[0]) && (x<=boT3[2]) && (y>=boT3[1]) && (y<=boT3[3]))  // Botao: 3
      {
        waitForIt(boT3[0], boT3[1], boT3[2], boT3[3]);
        updateStr('3');
      }
      if ((x>=boT4[0]) && (x<=boT4[2]) && (y>=boT4[1]) && (y<=boT4[3]))  // Botao: 4
      {
        waitForIt(boT4[0], boT4[1], boT4[2], boT4[3]);
        updateStr('4');
      }
      if ((x>=boT5[0]) && (x<=boT5[2]) && (y>=boT5[1]) && (y<=boT5[3]))  // Botao: 5
      {
        waitForIt(boT5[0], boT5[1], boT5[2], boT5[3]);
        updateStr('5');
      }

      if ((x>=boT6[0]) && (x<=boT6[2]) && (y>=boT6[1]) && (y<=boT6[3]))  // Botao: 6
      {
        waitForIt(boT6[0], boT6[1], boT6[2], boT6[3]);
        updateStr('6');
      }
      if ((x>=boT7[0]) && (x<=boT7[2]) && (y>=boT7[1]) && (y<=boT7[3]))  // Botao: 7
      {
        waitForIt(boT7[0], boT7[1], boT7[2], boT7[3]);
        updateStr('7');
      }
      if ((x>=boT8[0]) && (x<=boT8[2]) && (y>=boT8[1]) && (y<=boT8[3]))  // Botao: 8
      {
        waitForIt(boT8[0], boT8[1], boT8[2], boT8[3]);
        updateStr('8');
      }
      if ((x>=boT9[0]) && (x<=boT9[2]) && (y>=boT9[1]) && (y<=boT9[3]))  // Botao: 9
      {
        waitForIt(boT9[0], boT9[1], boT9[2], boT9[3]);
        updateStr('9');
      }
      if ((x>=boT0[0]) && (x<=boT0[2]) && (y>=boT0[1]) && (y<=boT0[3]))  // Botao: 0
      {
        waitForIt(boT0[0], boT0[1], boT0[2], boT0[3]);
        updateStr('0');
      }

      if ((x>=boTL[0]) && (x<=boTL[2]) && (y>=boTL[1]) && (y<=boTL[3]))  // Botao: limpar
      {
        waitForIt(boTL[0], boTL[1], boTL[2], boTL[3]);
        for (int i=0; i < 7;i++) stCurrent[i] = '\0';
        stCurrentLen=0;
        myGLCD.setColor(0, 0, 0);
        myGLCD.setBackColor(0, 0, 0);
        myGLCD.print("                                 ", 110, 210);
      }
      if ((x>=boTE[0]) && (x<=boTE[2]) && (y>=boTE[1]) && (y<=boTE[3]))  // Botao: entrar
      {
        waitForIt(boTE[0], boTE[1], boTE[2], boTE[3]);
        if ((stCurrent[0] == senha [0]) && (stCurrent[1] == senha [1]) && (stCurrent[2] == senha [2]) && (stCurrent[3] == senha [3]) && (stCurrent[4] == senha [4]) && (stCurrent[5] == senha [5]) && stCurrentLen <=6)
        {
          stCurrentLen=0;
          myGLCD.setFont(BigFont);
          myGLCD.setColor(0, 255, 0);
          myGLCD.setBackColor(0, 0, 0);
          myGLCD.print("SENHA CORRETA", 51, 192);
          delay(500);
          myGLCD.print("              ", 51, 192);
          dispScreen=1;
          clearScreen();
          menuScreen();
          memcpy(stCurrent, limpar_senha, sizeof(limpar_senha));
        }

        else if(stCurrentLen <=6)
        {
          myGLCD.setFont(BigFont);
          myGLCD.setColor(255, 0, 0);
          myGLCD.setBackColor(0, 0, 0);
          myGLCD.print("SENHA INCORRETA!", 35, 192);
          delay(500);
          myGLCD.print("                 ", 35, 192);
          delay(500);            
          myGLCD.print("SENHA INCORRETA!", 35, 192);
          delay(500);
          myGLCD.print("                 ", 35, 192);
          delay(500);
          myGLCD.print("SENHA INCORRETA!", 35, 192);
          delay(500);
          myGLCD.print("                ", 35, 192);
          myGLCD.print("                                                ", 110 , 210); //Limpar senha impressa ***************
          stCurrentLen=0;
          memcpy(stCurrent, limpar_senha, sizeof(limpar_senha));
        }
        else if(stCurrentLen > 6)
        {
          myGLCD.setFont(BigFont);
          myGLCD.setColor(255, 0, 0);
          myGLCD.setBackColor(0, 0, 0);
          myGLCD.print("SENHA INCORRETA!", 35, 192);
          delay(500);
          myGLCD.print("                 ", 35, 192);
          delay(500);            
          myGLCD.print("MAXIMO 6 DIGITOS!", 35, 192);
          delay(1000);
          myGLCD.print("                 ", 35, 192);
          delay(500);
          myGLCD.print("SENHA INCORRETA!", 35, 192);
          delay(500);
          myGLCD.print("                ", 35, 192);
          delay(500);
          myGLCD.print("MAXIMO 6 DIGITOS!", 35, 192);
          delay(1000);
          myGLCD.print("                 ", 35, 192);
          delay(500);
          myGLCD.print("                                               ", 110 , 210); //Limpar senha impressa ***************
          stCurrentLen=0;
          memcpy(stCurrent, limpar_senha, sizeof(limpar_senha));
        }
      }
      break;
    case 31:// ----------------------------------------- Dosagem personalizada --------------------------------------------
      if ((x>=menU[0]) && x<=menU[2] && (y>=menU[1]) && (y<=menU[3]))           // volta ao menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen = 1;
        clearScreen();
        menuScreen(); 
        modo_manual = false;
        modo_automatico = false;
        modo_personalizado = false;
        modo_calibrar = false;
        dosadora_1_selecionada = false;
        dosadora_2_selecionada = false;
        dosadora_3_selecionada = false;
      }
      if ((y >= anT[1]) && (y <= anT[3]) && (x >= anT[0]) && (x <= anT[2])) // Volta ao menu dosagem personalizada
      {
        waitForIt(anT[0], anT[1], anT[2], anT[3]);
        dispScreen = 29;
        clearScreen();
        config_dosagem_personalizada();
      }
      if(dosadora_1_selecionada == true)
      {
        if ((x >= minUT[0]) && (x <= minUT[2]) && (y >= minUT[1]) && (y <= minUT[3])) // Dose diaria mais
        {
          waitForIt(minUT[0], minUT[1], minUT[2], minUT[3]);
          dose_dosadora_1_personalizada_temp2 += 0.5;
          if(dose_dosadora_1_personalizada_temp2 > 999.5)
          {
            dose_dosadora_1_personalizada_temp2 = 0.5;
          }
          if(dose_dosadora_1_personalizada_temp2 <= 9.5)
          {
            myGLCD.setColor(0, 0, 0);                      
            myGLCD.fillRect(100, 45, 185, 67);
          }           

          config_dosagem_personalizada_2();
        }
        if ((x >= minDT[0]) && (x <= minDT[2]) && (y >= minDT[1]) && (y <= minDT[3])) // Dose diaria menos
        {
          waitForIt(minDT[0], minDT[1], minDT[2], minDT[3]);
          dose_dosadora_1_personalizada_temp2 -= 0.5;
          if(dose_dosadora_1_personalizada_temp2 <0.5)
          {
            dose_dosadora_1_personalizada_temp2 = 999.5;
          }
          if(dose_dosadora_1_personalizada_temp2 <= 9.5)
          {
            myGLCD.setColor(0, 0, 0);                      
            myGLCD.fillRect(100, 45, 185, 67);
          }
          config_dosagem_personalizada_2();
        }
        if ((x >= durC[0]) && (x <= durC[2]) && (y >= durC[1]) && (y <= durC[3])) 
        {
          waitForIt(durC[0], durC[1], durC[2], durC[3]); 
          quantidade_dose_dosadora_1_personalizada_temp2 += 1;
          if(quantidade_dose_dosadora_1_personalizada_temp2 > 24)
          {
            quantidade_dose_dosadora_1_personalizada_temp2 = 1;
          }
          config_dosagem_personalizada_2();
        }

        if ((x >= durB[0]) && (x <= durB[2]) && (y >= durB[1]) && (y <= durB[3])) 
        {
          waitForIt(durB[0], durB[1], durB[2], durB[3]);
          quantidade_dose_dosadora_1_personalizada_temp2 -= 1;
          if(quantidade_dose_dosadora_1_personalizada_temp2 < 1)
          {
            quantidade_dose_dosadora_1_personalizada_temp2 = 24;
          }
          config_dosagem_personalizada_2();        
        }
        if ((x >= sexT[0]) && (x<= sexT[2]) && (y >= sexT [1]) && (y <= sexT[3])) // Ativar ou desativar modo personalizado
        {
          waitForIt(sexT[0], sexT[1], sexT[2], sexT[3]);
          if(modo_personalizado_on_1_temp2 == 0)
          {
            modo_personalizado_on_1_temp2 = 1;
            modo_automatico_on_1_temp2 = 0;
            config_dosagem_personalizada_2();
          }
          else
          {
            modo_personalizado_on_1_temp2 = 0;
            modo_automatico_on_1_temp2 = 1;
            config_dosagem_personalizada_2();
          }
        }
        if ((y >= prOK[1]) && (y <= prOK[3]) && (x >= prOK[0]) && (x <= prOK[2])) 
        {
          waitForIt(prOK[0], prOK[1], prOK[2], prOK[3]); //funcao salvar
          dose_dosadora_1_personalizada = dose_dosadora_1_personalizada_temp2;
          quantidade_dose_dosadora_1_personalizada = quantidade_dose_dosadora_1_personalizada_temp2;
          modo_personalizado_on_1 = modo_personalizado_on_1_temp2;
          modo_automatico_on_1 = modo_automatico_on_1_temp2;
          hora_inicial_dosagem_personalizada_1 = temp2hora_inicial_dosagem_personalizada_1;
          minuto_inicial_dosagem_personalizada_1 = temp2minuto_inicial_dosagem_personalizada_1;
          hora_final_dosagem_personalizada_1 = temp2hora_final_dosagem_personalizada_1;
          minuto_final_dosagem_personalizada_1 = temp2minuto_final_dosagem_personalizada_1;
          segunda_dosagem_personalizada_1 = temp2segunda_dosagem_personalizada_1;
          terca_dosagem_personalizada_1 = temp2terca_dosagem_personalizada_1;
          quarta_dosagem_personalizada_1 = temp2quarta_dosagem_personalizada_1;
          quinta_dosagem_personalizada_1 = temp2quinta_dosagem_personalizada_1;
          sexta_dosagem_personalizada_1 = temp2sexta_dosagem_personalizada_1;
          sabado_dosagem_personalizada_1 = temp2sabado_dosagem_personalizada_1;
          domingo_dosagem_personalizada_1 = temp2domingo_dosagem_personalizada_1;

          if((hora_final_dosagem_personalizada_1 == hora_inicial_dosagem_personalizada_1) && (minuto_final_dosagem_personalizada_1 < (minuto_inicial_dosagem_personalizada_1+10)))
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);
            myGLCD.print("O INTERVALO ENTRE A INICIAL E A FINAL", 20, 110);
            myGLCD.print("DEVE SER DE NO MINIMO 10 MINUTOS!", 35, 130);

          }
          if(hora_final_dosagem_personalizada_1 < hora_inicial_dosagem_personalizada_1)
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);
            myGLCD.print("A HORA FINAL NAO PODE SER MENOR", 50, 110);
            myGLCD.print("QUE A INICIAL!", 100, 130);
          }

          if((temp2hora_final_dosagem_personalizada_1 == hora_inicial_dosagem_personalizada_1) && (temp2minuto_final_dosagem_personalizada_1 >= (minuto_inicial_dosagem_personalizada_1+10)))
          {
            dispScreen = 0;
            clearScreen();
            mainScreen(true);
            digitalWrite (4, LOW); 
            file.open(&root, "HDP1.TXT", O_WRITE);
            file.remove();       
            file.open(&root, "HDP1.TXT", O_CREAT | O_APPEND | O_WRITE);

            if((minuto_inicial_dosagem_personalizada_1 == minuto_inicial_dosagem_personalizada_2) || (minuto_inicial_dosagem_personalizada_1 == minuto_inicial_dosagem_personalizada_3))
            {
              minuto_inicial_dosagem_personalizada_1 += 10;
            }
            minuto01 = (((hora_final_dosagem_personalizada_1 * 60) + (minuto_final_dosagem_personalizada_1)) - ((hora_inicial_dosagem_personalizada_1 * 60) + (minuto_inicial_dosagem_personalizada_1))); 
            minuto01 /= 1 + quantidade_dose_dosadora_1_personalizada;
            
            for(int i = 1; i <= quantidade_dose_dosadora_1_personalizada; i++)
            { 
              contador += 1;  
              if(contador == 1)
              {
                minuto11 = (hora_inicial_dosagem_personalizada_1 * 60) + minuto_inicial_dosagem_personalizada_1 + minuto01;
              }
              if(contador > 1)
              {
                minuto11 += minuto01; 
              }
              if(minuto11 < 10)
              {
                file.print("000");  
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 > 10) && (minuto11 < 100))
              {
                file.print("00");
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 >= 100) && (minuto11 < 1000))
              {
                file.print("0");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(minuto11 >= 1000)
              {
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
            }
            file.close();  
            contador = 0;
            digitalWrite (4, HIGH);
            Salvar_dosadora_EEPROM(); 
          }    

          if(temp2hora_final_dosagem_personalizada_1 > hora_inicial_dosagem_personalizada_1)
          {
            dispScreen = 0;
            clearScreen();
            mainScreen(true);
            digitalWrite (4, LOW); 
            file.open(&root, "HDP1.TXT", O_WRITE);
            file.remove();       
            file.open(&root, "HDP1.TXT", O_CREAT | O_APPEND | O_WRITE);

            if((minuto_inicial_dosagem_personalizada_1 == minuto_inicial_dosagem_personalizada_2) || (minuto_inicial_dosagem_personalizada_1 == minuto_inicial_dosagem_personalizada_3))
            {
              minuto_inicial_dosagem_personalizada_1 += 10;
            }
            if(minuto_inicial_dosagem_personalizada_1 >= 60)
            {
              minuto_inicial_dosagem_personalizada_1 -= 60;
              hora_inicial_dosagem_personalizada_1 += 1;
            }
            minuto01 = (((hora_final_dosagem_personalizada_1 * 60) + (minuto_final_dosagem_personalizada_1)) - ((hora_inicial_dosagem_personalizada_1 * 60) + (minuto_inicial_dosagem_personalizada_1))); 
            minuto01 /= 1 + quantidade_dose_dosadora_1_personalizada;
            
            for(int i = 1; i <= quantidade_dose_dosadora_1_personalizada; i++)
            { 
              contador += 1;  
              if(contador == 1)
              {
                minuto11 = (hora_inicial_dosagem_personalizada_1 * 60) + minuto_inicial_dosagem_personalizada_1 + minuto01;
              }
              if(contador > 1)
              {
                minuto11 += minuto01; 
              }
              if(minuto11 < 10)
              {
                file.print("000");  
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 > 10) && (minuto11 < 100))
              {
                file.print("00");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 >= 100) && (minuto11 < 1000))
              {
                file.print("0");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(minuto11 >= 1000)
              {
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
            }
            file.close();  
            contador = 0;
            digitalWrite (4, HIGH);
            Salvar_dosadora_EEPROM();
          }         
        } 
      }      
      if(dosadora_2_selecionada == true)
      {
        if ((x >= minUT[0]) && (x <= minUT[2]) && (y >= minUT[1]) && (y <= minUT[3])) // Dose diaria mais
        {
          waitForIt(minUT[0], minUT[1], minUT[2], minUT[3]);
          dose_dosadora_2_personalizada_temp2 += 0.5;
          if(dose_dosadora_2_personalizada_temp2 > 999.5)
          {
            dose_dosadora_2_personalizada_temp2 = 0.5;
          }
          if(dose_dosadora_2_personalizada_temp2 <= 9.5)
          {
            myGLCD.setColor(0, 0, 0);                      
            myGLCD.fillRect(100, 45, 185, 67);
          }
          config_dosagem_personalizada_2();
        }
        if ((x >= minDT[0]) && (x <= minDT[2]) && (y >= minDT[1]) && (y <= minDT[3])) // Dose diaria menos
        {
          waitForIt(minDT[0], minDT[1], minDT[2], minDT[3]);
          dose_dosadora_2_personalizada_temp2 -= 0.5;
          if(dose_dosadora_2_personalizada_temp2 <0.5)
          {
            dose_dosadora_2_personalizada_temp2 = 999.5;
          }
          if(dose_dosadora_2_personalizada_temp2 <= 9.5)
          {
            myGLCD.setColor(0, 0, 0);                      
            myGLCD.fillRect(100, 45, 185, 67);
          }
          config_dosagem_personalizada_2();
        }
        if ((x >= durC[0]) && (x <= durC[2]) && (y >= durC[1]) && (y <= durC[3])) 
        {
          waitForIt(durC[0], durC[1], durC[2], durC[3]); 
          quantidade_dose_dosadora_2_personalizada_temp2 += 1;
          if(quantidade_dose_dosadora_2_personalizada_temp2 > 24)
          {
            quantidade_dose_dosadora_2_personalizada_temp2 = 1;
          }
          config_dosagem_personalizada_2();
        }

        if ((x >= durB[0]) && (x <= durB[2]) && (y >= durB[1]) && (y <= durB[3])) 
        {
          waitForIt(durB[0], durB[1], durB[2], durB[3]);
          quantidade_dose_dosadora_2_personalizada_temp2 -= 1;
          if(quantidade_dose_dosadora_2_personalizada_temp2 < 1)
          {
            quantidade_dose_dosadora_2_personalizada_temp2 = 24;
          }
          config_dosagem_personalizada_2();        
        }
        if ((x >= sexT[0]) && (x<= sexT[2]) && (y >= sexT [1]) && (y <= sexT[3]))
        {
          waitForIt(sexT[0], sexT[1], sexT[2], sexT[3]);
          if(modo_personalizado_on_2_temp2 == 0)
          {
            modo_personalizado_on_2_temp2 = 1;
            modo_automatico_on_2_temp2 = 0;
            config_dosagem_personalizada_2();
          }
          else
          {
            modo_personalizado_on_2_temp2 = 0;
            modo_automatico_on_2_temp2 = 1;
            config_dosagem_personalizada_2();
          }
        }
        if ((y >= prOK[1]) && (y <= prOK[3]) && (x >= prOK[0]) && (x <= prOK[2])) 
        {
          waitForIt(prOK[0], prOK[1], prOK[2], prOK[3]); //funcao salvar
          dose_dosadora_2_personalizada = dose_dosadora_2_personalizada_temp2;
          quantidade_dose_dosadora_2_personalizada = quantidade_dose_dosadora_2_personalizada_temp2;
          modo_personalizado_on_2 = modo_personalizado_on_2_temp2;
          modo_automatico_on_2 = modo_automatico_on_2_temp2;
          hora_inicial_dosagem_personalizada_2 = temp2hora_inicial_dosagem_personalizada_2;
          minuto_inicial_dosagem_personalizada_2 = temp2minuto_inicial_dosagem_personalizada_2;
          hora_final_dosagem_personalizada_2 = temp2hora_final_dosagem_personalizada_2;
          minuto_final_dosagem_personalizada_2 = temp2minuto_final_dosagem_personalizada_2;
          segunda_dosagem_personalizada_2 = temp2segunda_dosagem_personalizada_2;
          terca_dosagem_personalizada_2 = temp2terca_dosagem_personalizada_2;
          quarta_dosagem_personalizada_2 = temp2quarta_dosagem_personalizada_2;
          quinta_dosagem_personalizada_2 = temp2quinta_dosagem_personalizada_2;
          sexta_dosagem_personalizada_2 = temp2sexta_dosagem_personalizada_2;
          sabado_dosagem_personalizada_2 = temp2sabado_dosagem_personalizada_2;
          domingo_dosagem_personalizada_2 = temp2domingo_dosagem_personalizada_2;

          if((hora_final_dosagem_personalizada_2 == hora_inicial_dosagem_personalizada_2) && (minuto_final_dosagem_personalizada_2 < (minuto_inicial_dosagem_personalizada_2+10)))
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);
            myGLCD.print("O INTERVALO ENTRE A INICIAL E A FINAL", 20, 110);
            myGLCD.print("DEVE SER DE NO MINIMO 10 MINUTOS!", 35, 130);
          }
          if(hora_final_dosagem_personalizada_2 < hora_inicial_dosagem_personalizada_2)
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);
            myGLCD.print("A HORA FINAL NAO PODE SER MENOR", 50, 110);
            myGLCD.print("QUE A INICIAL!", 100, 130);
          }

          if((temp2hora_final_dosagem_personalizada_2 == hora_inicial_dosagem_personalizada_2) && (temp2minuto_final_dosagem_personalizada_2 >= (minuto_inicial_dosagem_personalizada_2+10)))
          {
            dispScreen = 0;
            clearScreen();
            mainScreen(true);
            digitalWrite (4, LOW); 
            file.open(&root, "HDP2.TXT", O_WRITE);
            file.remove();       
            file.open(&root, "HDP2.TXT", O_CREAT | O_APPEND | O_WRITE);
            
            minuto01 = (((hora_final_dosagem_personalizada_2 * 60) + (minuto_final_dosagem_personalizada_2)) - ((hora_inicial_dosagem_personalizada_2 * 60) + (minuto_inicial_dosagem_personalizada_2))); 
            minuto01 /= 1 + quantidade_dose_dosadora_2_personalizada;
            
            for(int i = 1; i <= quantidade_dose_dosadora_2_personalizada; i++)
            { 
              contador += 1;  
              if(contador == 1)
              {
                minuto11 = (hora_inicial_dosagem_personalizada_2 * 60) + minuto_inicial_dosagem_personalizada_2 + minuto01;
              }
              if(contador > 1)
              {
                minuto11 += minuto01; 
              }
              if(minuto11 < 10)
              {
                file.print("000");  
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 > 10) && (minuto11 < 100))
              {
                file.print("00");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 >= 100) && (minuto11 < 1000))
              {
                file.print("0");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(minuto11 >= 1000)
              {
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
            }
            file.close();  
            contador = 0;
            digitalWrite (4, HIGH);
            Salvar_dosadora_EEPROM(); 
          }    

          if(temp2hora_final_dosagem_personalizada_2 > hora_inicial_dosagem_personalizada_2)
          {
            dispScreen = 0;
            clearScreen();
            mainScreen(true);
            digitalWrite (4, LOW); 
            file.open(&root, "HDP2.TXT", O_WRITE);
            file.remove();       
            file.open(&root, "HDP2.TXT", O_CREAT | O_APPEND | O_WRITE);

            minuto01 = (((hora_final_dosagem_personalizada_2 * 60) + (minuto_final_dosagem_personalizada_2)) - ((hora_inicial_dosagem_personalizada_2 * 60) + (minuto_inicial_dosagem_personalizada_2))); 
            minuto01 /= 1 + quantidade_dose_dosadora_2_personalizada;
            
            for(int i = 1; i <= quantidade_dose_dosadora_2_personalizada; i++)
            { 
              contador += 1;  
              if(contador == 1)
              {
                minuto11 = (hora_inicial_dosagem_personalizada_2 * 60) + minuto_inicial_dosagem_personalizada_2 + minuto01;
              }
              if(contador > 1)
              {
                minuto11 += minuto01; 
              }
              if(minuto11 < 10)
              {
                file.print("000");  
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 > 10) && (minuto11 < 100))
              {
                file.print("00");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 >= 100) && (minuto11 < 1000))
              {
                file.print("0");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(minuto11 >= 1000)
              {
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
            }
            file.close();  
            contador = 0;
            digitalWrite (4, HIGH);
            Salvar_dosadora_EEPROM();
          }         
        }      
      }
      if(dosadora_3_selecionada == true)
      {
        if ((x >= minUT[0]) && (x <= minUT[2]) && (y >= minUT[1]) && (y <= minUT[3])) // Dose diaria mais
        {
          waitForIt(minUT[0], minUT[1], minUT[2], minUT[3]);
          dose_dosadora_3_personalizada_temp2 += 0.5;
          if(dose_dosadora_3_personalizada_temp2 > 999.5)
          {
            dose_dosadora_3_personalizada_temp2 = 0.5;
          }
          if(dose_dosadora_3_personalizada_temp2 <= 9.5)
          {
            myGLCD.setColor(0, 0, 0);                      
            myGLCD.fillRect(100, 45, 185, 67);
          }
          config_dosagem_personalizada_2();
        }
        if ((x >= minDT[0]) && (x <= minDT[2]) && (y >= minDT[1]) && (y <= minDT[3])) // Dose diaria menos
        {
          waitForIt(minDT[0], minDT[1], minDT[2], minDT[3]);
          dose_dosadora_3_personalizada_temp2 -= 0.5;
          if(dose_dosadora_3_personalizada_temp2 <0.5)
          {
            dose_dosadora_3_personalizada_temp2 = 999.5;
          }
          if(dose_dosadora_3_personalizada_temp2 <= 9.5)
          {
            myGLCD.setColor(0, 0, 0);                      
            myGLCD.fillRect(100, 45, 185, 67);
          }
          config_dosagem_personalizada_2();
        }
        if ((x >= durC[0]) && (x <= durC[2]) && (y >= durC[1]) && (y <= durC[3])) 
        {
          waitForIt(durC[0], durC[1], durC[2], durC[3]); 
          quantidade_dose_dosadora_3_personalizada_temp2 += 1;
          if(quantidade_dose_dosadora_3_personalizada_temp2 > 24)
          {
            quantidade_dose_dosadora_3_personalizada_temp2 = 1;
          }
          config_dosagem_personalizada_2();
        }

        if ((x >= durB[0]) && (x <= durB[2]) && (y >= durB[1]) && (y <= durB[3])) 
        {
          waitForIt(durB[0], durB[1], durB[2], durB[3]);
          quantidade_dose_dosadora_3_personalizada_temp2 -= 1;
          if(quantidade_dose_dosadora_3_personalizada_temp2 < 1)
          {
            quantidade_dose_dosadora_3_personalizada_temp2 = 24;
          }
          config_dosagem_personalizada_2();        
        }
        if ((x >= sexT[0]) && (x<= sexT[2]) && (y >= sexT [1]) && (y <= sexT[3]))
        {
          waitForIt(sexT[0], sexT[1], sexT[2], sexT[3]);
          if(modo_personalizado_on_3_temp2 == 0)
          {
            modo_personalizado_on_3_temp2 = 1;
            modo_automatico_on_3_temp2 = 0;
            config_dosagem_personalizada_2();
          }
          else
          {
            modo_personalizado_on_3_temp2 = 0;
            modo_automatico_on_3_temp2 = 1;
            config_dosagem_personalizada_2();
          }
        }
        if ((y >= prOK[1]) && (y <= prOK[3]) && (x >= prOK[0]) && (x <= prOK[2])) 
        {
          waitForIt(prOK[0], prOK[1], prOK[2], prOK[3]); //funcao salvar
          dose_dosadora_3_personalizada = dose_dosadora_3_personalizada_temp2;
          quantidade_dose_dosadora_3_personalizada = quantidade_dose_dosadora_3_personalizada_temp2;
          modo_personalizado_on_3 = modo_personalizado_on_3_temp2;
          modo_automatico_on_3 = modo_automatico_on_3_temp2;
          hora_inicial_dosagem_personalizada_3 = temp2hora_inicial_dosagem_personalizada_3;
          minuto_inicial_dosagem_personalizada_3 = temp2minuto_inicial_dosagem_personalizada_3;
          hora_final_dosagem_personalizada_3 = temp2hora_final_dosagem_personalizada_3;
          minuto_final_dosagem_personalizada_3 = temp2minuto_final_dosagem_personalizada_3;
          segunda_dosagem_personalizada_3 = temp2segunda_dosagem_personalizada_3;
          terca_dosagem_personalizada_3 = temp2terca_dosagem_personalizada_3;
          quarta_dosagem_personalizada_3 = temp2quarta_dosagem_personalizada_3;
          quinta_dosagem_personalizada_3 = temp2quinta_dosagem_personalizada_3;
          sexta_dosagem_personalizada_3 = temp2sexta_dosagem_personalizada_3;
          sabado_dosagem_personalizada_3 = temp2sabado_dosagem_personalizada_3;
          domingo_dosagem_personalizada_3 = temp2domingo_dosagem_personalizada_3;
          if((hora_final_dosagem_personalizada_3 == hora_inicial_dosagem_personalizada_3) && (minuto_final_dosagem_personalizada_3 < (minuto_inicial_dosagem_personalizada_3+10)))
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);
            myGLCD.print("O INTERVALO ENTRE A INICIAL E A FINAL", 20, 110);
            myGLCD.print("DEVE SER DE NO MINIMO 10 MINUTOS!", 35, 130);
          }
          if(hora_final_dosagem_personalizada_3 < hora_inicial_dosagem_personalizada_3)
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);
            myGLCD.print("A HORA FINAL NAO PODE SER MENOR", 50, 110);
            myGLCD.print("QUE A INICIAL!", 100, 130);
          }

          if((temp2hora_final_dosagem_personalizada_3 == hora_inicial_dosagem_personalizada_3) && (temp2minuto_final_dosagem_personalizada_3 >= (minuto_inicial_dosagem_personalizada_3+10)))
          {
            dispScreen = 0;
            clearScreen();
            mainScreen(true);
            digitalWrite (4, LOW); 
            file.open(&root, "HDP3.TXT", O_WRITE);
            file.remove();       
            file.open(&root, "HDP3.TXT", O_CREAT | O_APPEND | O_WRITE);

            minuto01 = (((hora_final_dosagem_personalizada_3 * 60) + (minuto_final_dosagem_personalizada_3)) - ((hora_inicial_dosagem_personalizada_3 * 60) + (minuto_inicial_dosagem_personalizada_3))); 
            minuto01 /= 1 + quantidade_dose_dosadora_3_personalizada;
            
            for(int i = 1; i <= quantidade_dose_dosadora_3_personalizada; i++)
            { 
              contador += 1;  
              if(contador == 1)
              {
                minuto11 = (hora_inicial_dosagem_personalizada_3 * 60) + minuto_inicial_dosagem_personalizada_3 + minuto01;
              }
              if(contador > 1)
              {
                minuto11 += minuto01; 
              }
              if(minuto11 < 10)
              {
                file.print("000");  
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 > 10) && (minuto11 < 100))
              {
                file.print("00");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 >= 100) && (minuto11 < 1000))
              {
                file.print("0");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(minuto11 >= 1000)
              {
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
            }
            file.close();  
            contador = 0;
            digitalWrite (4, HIGH);
            Salvar_dosadora_EEPROM(); 
          }    

          if(temp2hora_final_dosagem_personalizada_3 > hora_inicial_dosagem_personalizada_3)
          {
            dispScreen = 0;
            clearScreen();
            mainScreen(true);
            digitalWrite (4, LOW); 
            file.open(&root, "HDP3.TXT", O_WRITE);
            file.remove();       
            file.open(&root, "HDP3.TXT", O_CREAT | O_APPEND | O_WRITE);

            minuto01 = (((hora_final_dosagem_personalizada_3 * 60) + (minuto_final_dosagem_personalizada_3)) - ((hora_inicial_dosagem_personalizada_3 * 60) + (minuto_inicial_dosagem_personalizada_3))); 
            minuto01 /= 1 + quantidade_dose_dosadora_3_personalizada;
            
            for(int i = 1; i <= quantidade_dose_dosadora_3_personalizada; i++)
            { 
              contador += 1;  
              if(contador == 1)
              {
                minuto11 = (hora_inicial_dosagem_personalizada_3 * 60) + minuto_inicial_dosagem_personalizada_3 + minuto01;
              }
              if(contador > 1)
              {
                minuto11 += minuto01; 
              }
              if(minuto11 < 10)
              {
                file.print("000");  
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 > 10) && (minuto11 < 100))
              {
                file.print("00");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 >= 100) && (minuto11 < 1000))
              {
                file.print("0");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(minuto11 >= 1000)
              {
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
            }
            file.close();  
            contador = 0;
            digitalWrite (4, HIGH);
            Salvar_dosadora_EEPROM();
          }         
        }
      }      
      break;
    }
  }
}

