void check_status()
{

  if (tempCflag==true)
  {
    chiller_status = 100;
  }
  else
  {
    chiller_status = 0;
  }

  if (tempHflag==true)
  {
    aquecedor_status = 100;
  }
  else
  {
    aquecedor_status = 0;
  }
  if (PHRflag==true)
  {
    reator_status = 100;
  }
  else
  {
    reator_status =0;
  }
  if (ORPflag==true)
  {
    ozonio_status = 100;
  }
  else
  {
    ozonio_status = 0;
  }
  if (ato==true)
  {
    reposicao_status = 100;
  }
  else
  {
    reposicao_status = 0;
  }
  if (nivel_status==false)
  {
    niveis_status = 100;
  }
  else
  {
    niveis_status = 0;
  }
  if (falha_tpa == true)
  {
    tpa_status = 100;
  }
}

void cosm () //--------------- Envia dados para o cosm.com ------------------------------------
{

  if (millis() - previous_Millis > 65000)    //Envia dados a cada 65s
  {
    previous_Millis = millis();

    ether.dnsLookup(website);

    byte sd = stash.create();
    stash.print("1,"); //Temp. da agua
    stash.println(tempC,DEC);
    stash.print("2,"); //Temp. dissipador
    stash.println(tempH,DEC);
    stash.print("3,"); //PH do aquario
    stash.println(PHA, DEC);
    stash.print("4,"); //PH do reator de calcio
    stash.println(PHR,DEC);
    stash.print("5,"); //Densidade
    stash.println(DEN);
    stash.print("6,"); //ORP
    stash.println(ORP);
    stash.print("7,"); //Status chiller 0 = desligado, 100 = ligado
    stash.println(chiller_status);
    stash.print("8,"); //Status aquecedor 0 = desligado, 100 = ligado
    stash.println(aquecedor_status);
    stash.print("9,"); //Status reator de calcio 0 = desligado, 100 = ligado
    stash.println(reator_status);
    stash.print("10,"); // Status ozonizador 0 = desligado, 100 = ligado
    stash.println(ozonio_status);
    stash.print("11,"); //Status reposicao de agua doce 0 = desligado, 100 = ligado
    stash.println(reposicao_status);
    stash.print("12,"); //Status niveis 0 = baixo, 100 = normaj
    stash.println(niveis_status);
    stash.print("13,"); //Status TPA 0 = desligado, 100 = ligado
    stash.println(tpa_status);
    stash.print("14,"); //Potencia dos leds azuis
    stash.println(LedToPercent(bled_out));
    stash.print("15,"); //Potencia dos leds brancos
    stash.println(LedToPercent(wled_out));

    stash.save();

    // generate the header with payload - note that the stash size is used,
    // and that a "stash descriptor" is passed in as argument using "$H"
    Stash::prepare(PSTR("PUT http://$F/v2/feeds/$F.csv HTTP/1.0" "\r\n"
      "Host: $F" "\r\n"
      "X-PachubeApiKey: $F" "\r\n"
      "Content-Length: $D" "\r\n"
      "\r\n"
      "$H"),
    website, PSTR(FEED), website, PSTR(APIKEY), stash.size(), sd);

    // send the packet - this also releases all stash buffers once done
    ether.tcpSend();
  }
}
