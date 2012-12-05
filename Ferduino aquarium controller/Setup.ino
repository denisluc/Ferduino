//------------------------setup------------------------------
void setup()
{
  Serial.begin(38400);
  Serial2.begin(38400); //stamps
  pinMode(ledPinBlue, OUTPUT);
  pinMode(ledPinWhite, OUTPUT);
  pinMode(aquecedorPin, OUTPUT);
  pinMode(chillerPin, OUTPUT);
  pinMode(alarmPin, OUTPUT);
  pinMode(fanPin, OUTPUT);
  pinMode(bomba1Pin, OUTPUT);
  pinMode(bomba2Pin, OUTPUT);
  pinMode(bomba3Pin, OUTPUT);
  pinMode(reatorPin, OUTPUT);
  pinMode(ozonizadorPin, OUTPUT);
  pinMode(solenoide1Pin, OUTPUT);
  pinMode(multiplexadorS0Pin, OUTPUT);
  pinMode(multiplexadorS1Pin, OUTPUT);
  pinMode (4, OUTPUT);  //sd card
  digitalWrite (4, HIGH);
  pinMode (dosadora1, OUTPUT);
  pinMode (dosadora2, OUTPUT);
  pinMode (dosadora3, OUTPUT);

  myGLCD.InitLCD(LANDSCAPE);
  myGLCD.clrScr();

  myTouch.InitTouch(LANDSCAPE);
  myTouch.setPrecision(PREC_MEDIUM);

  sensors.begin();     //start up temperature library
  // set the resolution to 10 bit
  sensors.setResolution(sensor_agua, 10);
  sensors.setResolution(sensor_dissipador, 10);

  if(Ethernet_Shield == true)
  {
    if (ether.begin(sizeof Ethernet::buffer, mymac) == 0) 
    {
      Serial.println( "Failed to access Ethernet controller");
    }
    ether.staticSetup(myip,gwip);
  }
  // Set the clock to run-mode
  rtc.halt(false);
  min_cnt= (t.hour*60)+t.min;
  ReadFromEEPROM();
  lertpaEEPROM();
  lerPHAEEPROM();
  lerPHREEPROM();
  lerORPEEPROM();
  lerDENEEPROM();
  ler_dosadora_EEPROM();
  LED_levels_output(); 
  card.init(SPI_QUARTER_SPEED,chipselect);
  volume.init(&card);
  root.openRoot(&volume);
  mainScreen(true);
  Open_channel(ph1);
  delay(50);
  Serial2.print("e");
  Serial2.print('\r');
  delay(1000);
  Serial2.flush();
  Serial2.print("L0");
  Serial2.print('\r');
  delay(1000);
  Open_channel(ph2);
  delay(50);
  Serial2.print("e");
  Serial2.print('\r');
  delay(1000);
  Serial2.flush();
  Serial2.print("L0");
  Serial2.print('\r');
  delay(1000);
  Open_channel(orp);
  delay(50);
  Serial2.print("e");
  Serial2.print('\r');
  delay(1000);
  Serial2.flush();
  Serial2.print("L0");
  Serial2.print('\r');
  delay(1000);    
  Open_channel(ec);
  delay(50);
  Serial2.print("e");
  Serial2.print('\r');
  delay(1000);
  Serial2.flush();
  Serial2.print("L0");
  Serial2.print('\r');
  delay(1000);

}

