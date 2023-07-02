const int segmentA = 14;
const int segmentB = 15;
const int segmentC = 16;
const int segmentD = 17;
const int segmentE = 18;
const int segmentF = 19;
const int segmentG = 8;
const int sw0 = 0;
const int sw1 = 1;
const int sw2 = 2;
const int sw3 = 3;
const int sw4 = 4;
const int sw5 = 5;
const int sw6 = 6;
const int sw7 = 7;


const int digit1 = 12;
const int digit2 = 11;
const int digit3 = 10;
const int digit4 = 9;
int ones, tens, hundreds, thousands;

void display_0() 
{
  digitalWrite(segmentA,HIGH); 
  digitalWrite(segmentB,HIGH); 
  digitalWrite(segmentC,HIGH); 
  digitalWrite(segmentD,HIGH); 
  digitalWrite(segmentE,HIGH);
  digitalWrite(segmentF,HIGH);
  digitalWrite(segmentG,LOW);
}

void display_1() 
{
  digitalWrite(segmentA,LOW); 
  digitalWrite(segmentB,HIGH); 
  digitalWrite(segmentC,HIGH); 
  digitalWrite(segmentD,LOW); 
  digitalWrite(segmentE,LOW);
  digitalWrite(segmentF,LOW);
  digitalWrite(segmentG,LOW);
}

void display_2() 
{
  digitalWrite(segmentA,HIGH); 
  digitalWrite(segmentB,HIGH); 
  digitalWrite(segmentC,LOW); 
  digitalWrite(segmentD,HIGH); 
  digitalWrite(segmentE,HIGH);
  digitalWrite(segmentF,LOW);
  digitalWrite(segmentG,HIGH);
}

void display_3() 
{
  digitalWrite(segmentA,HIGH); 
  digitalWrite(segmentB,HIGH); 
  digitalWrite(segmentC,HIGH); 
  digitalWrite(segmentD,HIGH); 
  digitalWrite(segmentE,LOW);
  digitalWrite(segmentF,LOW);
  digitalWrite(segmentG,HIGH);
}

void display_4() 
{
  digitalWrite(segmentA,LOW); 
  digitalWrite(segmentB,HIGH); 
  digitalWrite(segmentC,HIGH); 
  digitalWrite(segmentD,LOW); 
  digitalWrite(segmentE,LOW);
  digitalWrite(segmentF,HIGH);
  digitalWrite(segmentG,HIGH);
}

void display_5() 
{
  digitalWrite(segmentA,HIGH); 
  digitalWrite(segmentB,LOW); 
  digitalWrite(segmentC,HIGH); 
  digitalWrite(segmentD,HIGH); 
  digitalWrite(segmentE,LOW);
  digitalWrite(segmentF,HIGH);
  digitalWrite(segmentG,HIGH);
}

void display_6() 
{
  digitalWrite(segmentA,HIGH); 
  digitalWrite(segmentB,LOW); 
  digitalWrite(segmentC,HIGH); 
  digitalWrite(segmentD,HIGH); 
  digitalWrite(segmentE,HIGH);
  digitalWrite(segmentF,HIGH);
  digitalWrite(segmentG,HIGH);
}

void display_7() 
{
  digitalWrite(segmentA,HIGH); 
  digitalWrite(segmentB,HIGH); 
  digitalWrite(segmentC,HIGH); 
  digitalWrite(segmentD,LOW); 
  digitalWrite(segmentE,LOW);
  digitalWrite(segmentF,HIGH);
  digitalWrite(segmentG,LOW);
}

void display_8() 
{
  digitalWrite(segmentA,HIGH); 
  digitalWrite(segmentB,HIGH); 
  digitalWrite(segmentC,HIGH); 
  digitalWrite(segmentD,HIGH); 
  digitalWrite(segmentE,HIGH);
  digitalWrite(segmentF,HIGH);
  digitalWrite(segmentG,HIGH);
}

void display_9()
{
  digitalWrite(segmentA,HIGH);
  digitalWrite(segmentB,HIGH);
  digitalWrite(segmentC,HIGH);
  digitalWrite(segmentE,LOW);
  digitalWrite(segmentD,HIGH);
  digitalWrite(segmentF,HIGH);
  digitalWrite(segmentG,HIGH);
}

int readSwitch()
{
  int countUpper = 0;
  int countLower = 0;
 
  for(int i = sw0; i <= sw3; i++)
  {
    if (digitalRead(i))
      switch(i)
      {
        case 0: countUpper += 1; break; 
        case 1: countUpper += 2; break; 
        case 2: countUpper += 4; break; 
        case 3: countUpper += 8; break; 
      }
  }

  for(int i = sw4; i <= sw7; i++)
  {
    if (digitalRead(i))
      switch(i)
      {
        case 4: countLower += 1; break; 
        case 5: countLower += 2; break; 
        case 6: countLower += 4; break; 
        case 7: countLower += 8; break; 
      }
  }

  return countUpper * countLower;
}

void display7Segment(int value)
{
  switch(value)
  {
    case 0: display_0(); break;
    case 1: display_1(); break;
    case 2: display_2(); break;
    case 3: display_3(); break;
    case 4: display_4(); break;
    case 5: display_5(); break;
    case 6: display_6(); break;
    case 7: display_7(); break;
    case 8: display_8(); break;
    case 9: display_9(); break;
  }
}

void setup() 
{
  for (int i=sw0; i<=sw7; i++)
  {
    pinMode(i, INPUT) ; //sw0 - sw7 are connected to input pins
  }

  for (int i=segmentA; i<= segmentF; i++)
  {
    pinMode(i, OUTPUT);//segmentA-segmentF are set as output
  }
  pinMode(segmentG, OUTPUT);

  for (int i=digit4; i<= digit1; i++)
  {
    pinMode(i, OUTPUT);//digit1-digit4 are set as output
  }
}
//-----------------------------------------------------------------
void loop() 
{
  int x;
  x = readSwitch();

  if (x < 10)
  {
    ones = x;

    display7Segment(ones);
    digitalWrite(digit1, LOW);
    digitalWrite(digit2, LOW);
    digitalWrite(digit3, LOW);
    digitalWrite(digit4, HIGH);
    delay(10);
  }

  else if (x < 100)
  {
    tens = x/10;

    ones = x%10;

    display7Segment(tens);
    digitalWrite(digit1, LOW);
    digitalWrite(digit2, LOW);
    digitalWrite(digit3, HIGH);
    digitalWrite(digit4, LOW);
    delay(10);

    display7Segment(ones);
    digitalWrite(digit1, LOW);
    digitalWrite(digit2, LOW);
    digitalWrite(digit3, LOW);
    digitalWrite(digit4, HIGH);
    delay(10);
  }

  else if (x < 1000)
  {
    hundreds = x/100;

    tens = x/10;
    tens = tens%10;

    ones = x%10;

    display7Segment(hundreds);
    digitalWrite(digit1, LOW);
    digitalWrite(digit2, HIGH);
    digitalWrite(digit3, LOW);
    digitalWrite(digit4, LOW);
    delay(10);

    display7Segment(tens);
    digitalWrite(digit1, LOW);
    digitalWrite(digit2, LOW);
    digitalWrite(digit3, HIGH);
    digitalWrite(digit4, LOW);
    delay(10);

    display7Segment(ones);
    digitalWrite(digit1, LOW);
    digitalWrite(digit2, LOW);
    digitalWrite(digit3, LOW);
    digitalWrite(digit4, HIGH);
    delay(10);
  }

  else
  {
    thousands = x/1000;

    hundreds = x/100;
    hundreds = hundreds%10;

    tens = x/10;
    tens = tens%10;

    ones = x%10;

    display7Segment(thousands);
    digitalWrite(digit1, HIGH);
    digitalWrite(digit2, LOW);
    digitalWrite(digit3, LOW);
    digitalWrite(digit4, LOW);
    delay(5);

    display7Segment(hundreds);
    digitalWrite(digit1, LOW);
    digitalWrite(digit2, HIGH);
    digitalWrite(digit3, LOW);
    digitalWrite(digit4, LOW);
    delay(5);

    display7Segment(tens);
    digitalWrite(digit1, LOW);
    digitalWrite(digit2, LOW);
    digitalWrite(digit3, HIGH);
    digitalWrite(digit4, LOW);
    delay(5);

    display7Segment(ones);
    digitalWrite(digit1, LOW);
    digitalWrite(digit2, LOW);
    digitalWrite(digit3, LOW);
    digitalWrite(digit4, HIGH);
    delay(5);
  }
}
