byte validateDateForMonth(byte d, byte m, word y)
{
  byte mArr[12] = {
    31,0,31,30,31,30,31,31,30,31,30,31                                                          };
  byte od;
  boolean dc=false;

  if (m==2)
  {
    if ((y % 4)==0)
    {
      if (d>29)
      {
        d=29;
        dc=true;
      }
    }
    else
    {  
      if (d>28)
      {
        d=28;
        dc=true;
      }
    }
  }
  else
  {
    if (d>mArr[m-1])
    {
      d=mArr[m-1];
      dc=true;
    }
  }
  return d;
}

byte calcDOW(byte d, byte m, int y)
{
  int dow;
  byte mArr[12] = {6,2,2,5,0,3,5,1,4,6,2,4};

  dow = (y % 100);
  dow = dow*1.25;
  dow += d;
  dow += mArr[m-1];
  if (((y % 4)==0) && (m<3))
    dow -= 1;
  while (dow>7)
    dow -= 7;

  return dow;
}
