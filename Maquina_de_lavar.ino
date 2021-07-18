// comeco
int Start = 10;

// Motor
int sentido1 = 12;
int sentido2 = 11;

// Outros
int bomba = 9;
int valvula = 8;

// flag
bool Rotina = false;

void bater()
{
  int Delay = 500;
  for(int j = 0; j < 5; j++)
  {
    //1 min de execucão
    for(int i = 0; i < 30; i++)
    {
      digitalWrite(sentido1,LOW);
      delay(Delay);
      digitalWrite(sentido1,HIGH);
      delay(Delay);
      digitalWrite(sentido2,LOW);
      delay(Delay);
      digitalWrite(sentido2,HIGH);
      delay(Delay);
    }
  }
  delay(500);
}

void molho()
{
  for(int j = 0; j < 5; j++)
  {
    //1 min de execucão
    for(int i = 0; i < 30; i++)
    {
      delay(2000);
    }
  }
}

void encher()
{
  // encher
  digitalWrite(valvula,LOW);
  for(int e = 0; e < 105; e++)
  {
    delay(4000);
  }
  digitalWrite(valvula,HIGH);
  delay(500);
}

void centrifugar()
{
  digitalWrite(bomba,LOW);
  delay(4000);
  for (int j = 0; j < 10; j++)
  {
    digitalWrite(sentido1,LOW);
    delay(12000);
    digitalWrite(sentido1,HIGH);
    for(int i = 0; i < 25; i++)
    {
      delay(1000);
    }
  }
  delay(500);
}

void escorrer()
{
  // escorrer agua
  digitalWrite(bomba,LOW);
  for (int j = 0; j < 2; j++){
    for(int i = 0; i < 30; i++)
    {
      delay(2000);
    }
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  // put your setup code here, to run once:
  pinMode(Start,INPUT);
  pinMode(sentido1,OUTPUT);
  pinMode(sentido2,OUTPUT);
  pinMode(bomba,OUTPUT);
  pinMode(valvula,OUTPUT);

  digitalWrite(sentido1,HIGH);
  digitalWrite(sentido2,HIGH);
  digitalWrite(bomba,HIGH);
  digitalWrite(valvula,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:  
  
  if(digitalRead(Start) == HIGH)
  {
    Rotina = true;
  }
  delay(500);
  if(Rotina)
  {
    for(int caso = 0; caso <= 6; caso++){
      switch (caso)
      {
        case 0:
          // encher
          encher();
        break;
        case 1:
          // bater
          bater();
          molho();
          bater();
        break;
        case 2:
          // escorrer agua
          escorrer();
        break;
        case 3:
          // centrifugar
          centrifugar();
          delay(500);
          digitalWrite(bomba,HIGH);
        break;
        case 4:
          // enxaguar 
          encher();
          bater();
          escorrer();
        break;
        case 5:
          centrifugar();
          centrifugar();
          delay(500);
          digitalWrite(bomba,HIGH);
        break;
        default:
          // desliga tudo
          digitalWrite(sentido1,HIGH);
          digitalWrite(sentido2,HIGH);
          digitalWrite(bomba,HIGH);
          digitalWrite(valvula,HIGH);
          Rotina = false;
        break;
      }
    }
  }
}
