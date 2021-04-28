#include <LiquidCrystal.h>
#include <stdio.h>
const int rs = PA_7, e = PA_6, d4 = PA_5, d5 = PB_4, d6 = PB_1, d7 = PE_4;
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

int randomNumber = 0;
const int pinKopukleme = PE_1; // the pin that the pushbutton is attached to
const int pinYikama = PE_2; // the pin that the pushbutton is attached to
const int pinKurulama = PE_3; // the pin that the pushbutton is attached to
const int pinCilalama = PB_2; // the pin that the pushbutton is attached to
const int pinBes_TL = PB_6; // the pin that the pushbutton is attached to
const int pinOn_TL = PA_4; // the pin that the pushbutton is attached to
const int pinYirmi_TL = PA_3; // the pin that the pushbutton is attached to
const int pinElli_TL = PA_2; // the pin that the pushbutton is attached to
const int pinYuz_TL = PD_2; // the pin that the pushbutton is attached to
const int pinBitis = PE_5; // the pin that the pushbutton is attached to
const int pinBitis2 = PE_0;// the pin that the pushbutton is attached to
const int pinReset = PF_0; // the pin that the pushbutton is attached to
const int greenled = PD_1; // the pin that the LED is attached to
const int Redled = PF_1; // the pin that the LED is attached to


int kopuklemeState = 0; // current state of the button
int yikamaState = 0; // current state of the button
int kurulamaState = 0; // current state of the button
int cilalamaState = 0; // current state of the button
int bes_TLState = 0; // current state of the button
int on_TLState = 0; // current state of the button
int yirmi_TLState = 0; // current state of the button
int elli_TLState = 0; // current state of the button
int yuz_TLState = 0; // current state of the button
int Bitis2State = 0;// current state of the button
int BitisState = 0; // current state of the button
int ResetState = 0; // current state of the button

int coinStocks[5] = {20, 20, 10, 30, 5};
int diziKopukleme[2] = {20, 5};
int diziYikama[2] = {20, 10};
int diziKurulama[2] = {10, 20};
int diziCilalama[2] = {30, 50};

int currency = 0;
int tempCurrency = 0;
int counter1 = 0;
int counter2 = 0;
int counter3 = 0;
int counter4 = 0;
int counter5 = 0;
boolean isDone = false;

byte topSmile[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b11011,
  0b00000,
  0b01010,
  0b10101,
  0b01010
};
byte bottomSmile[8] = {
  0b10001,
  0b10001,
  0b10001,
  0b01110,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};
void setup()
{
  Serial.begin(9600);
  initPinModes();
  randomSeed(analogRead(0));
  lcd.createChar(0, topSmile);
  lcd.createChar(1, bottomSmile);
  lcd.begin(16, 2);
  lcd.setCursor(2, 0);
  lcd.print("Lutfen seçim yapın:");
  lcd.setCursor(2, 1);
  lcd.print("lutfen para yukle: ");
  lcd.setCursor(14, 0);
  lcd.write((uint8_t)0);
  lcd.setCursor(14, 1);
  lcd.write((uint8_t)1);
}

void loop()
{
  kopuklemeState = digitalRead(pinKopukleme);
  yikamaState = digitalRead(pinYikama);
  kurulamaState = digitalRead(pinKurulama);
  cilalamaState = digitalRead(pinCilalama);
  bes_TLState = digitalRead(pinBes_TL);
  on_TLState = digitalRead(pinOn_TL);
  yirmi_TLState = digitalRead(pinYirmi_TL);
  elli_TLState = digitalRead(pinElli_TL);
  yuz_TLState = digitalRead(pinYuz_TL);
  Bitis2State = digitalRead(pinBitis2);
  BitisState = digitalRead(pinBitis);
  ResetState = digitalRead(pinReset);

  if (isDone == false)
  {
    bes_tl_fonksiyon();
    on_tl_fonksiyon();
    yirmi_tl_fonksiyon();
    elli_tl_fonksiyon();
    yuz_tl_fonksiyon();
    doneButton();
  }
  else
  {
    func_kopukleme();
    func_yikama();
    func_kurulama();
    func_cilalama();
    func_Reset();
    func_Bitis();
  }
  //endofcode
}
void initPinModes()
{
  pinMode(Redled, OUTPUT);
  pinMode(greenled, OUTPUT);
  pinMode(pinKopukleme, INPUT_PULLUP);
  pinMode(pinYikama, INPUT_PULLUP);
  pinMode(pinKurulama, INPUT_PULLUP);
  pinMode(pinCilalama, INPUT_PULLUP);
  pinMode(pinReset, INPUT_PULLUP);
  pinMode(pinBitis2, INPUT_PULLUP);
  pinMode(pinBitis, INPUT_PULLUP);
  pinMode(pinBes_TL, INPUT_PULLUP);
  pinMode(pinOn_TL, INPUT_PULLUP);
  pinMode(pinYirmi_TL, INPUT_PULLUP);
  pinMode(pinElli_TL, INPUT_PULLUP);
  pinMode(pinYuz_TL, INPUT_PULLUP);
}
void bes_tl_fonksiyon()
{
  if (bes_TLState == 0) //5TL
  {
    digitalWrite(greenled, HIGH);
  }
  else {
    currency += 5;
    digitalWrite(greenled, LOW);
    delay(500);
    lcd.clear();
    lcd.print("BAKIYE = " + String(currency) + "TL");
  }
}
void on_tl_fonksiyon()
{
  if (on_TLState == 0) //10TL
  {
    digitalWrite(greenled, HIGH);
  }
  else {
    currency += 10;

    digitalWrite(greenled, LOW);
    delay(500);
    lcd.clear();
    lcd.print("BAKIYE = " + String(currency) + "TL");
  }
}
void yirmi_tl_fonksiyon()
{
  if (yirmi_TLState == 0) //20TL
  {
    digitalWrite(greenled, HIGH);
  }
  else {
    currency += 20;

    digitalWrite(greenled, LOW);
    delay(500);
    lcd.clear();
    lcd.print("BAKIYE = " + String(currency) + "TL");
  }
}

void elli_tl_fonksiyon()
{
  if (elli_TLState == 0)
  {
    digitalWrite(greenled, HIGH);
  }
  else {
    currency += 50;
    digitalWrite(greenled, LOW);
    delay(500);
    lcd.clear();
    lcd.print("BAKIYE = " + String(currency) + "TL");
  }
}

void yuz_tl_fonksiyon()
{
  if (yuz_TLState == 0)
  {
    digitalWrite(greenled, HIGH);
  }
  else {
    currency += 100;
    digitalWrite(greenled, LOW);
    delay(500);
    lcd.clear();
    lcd.print("BAKIYE = " + String(currency) + "TL");
  }
}
void doneButton()
{
  if (BitisState == 0)
  {
    digitalWrite(greenled, HIGH);
  }
  else {
    isDone = true;
    tempCurrency = currency;
    digitalWrite(greenled, LOW);
    delay(500);
    lcd.clear();
    lcd.print("BAKIYENIZ = " + String(currency) + "TL");
    lcd.setCursor(0, 1);
    lcd.print("SECIM YAPINIZ");
  }
}
//PART TWO
void func_kopukleme()
{
  if (kopuklemeState == 0)
  {
  }
  else {
    counter2++;
    currency -= 15;
    lcd.clear();
    lcd.print("BAKIYE = " + String(currency) + "TL");
    lcd.setCursor(0, 1);
    lcd.print(String(counter2) + "-kopukleme");
    if (currency < 0)
    {
      counter2--;
      currency-=15;
      lcd.clear();
      lcd.print("YETERSIZ BAKIYE");
      lcd.setCursor(0, 1);
      lcd.print("BAKIYE = " + String(currency) + "TL");
    }
    delay(500);
  }
}
void func_yikama()
{
  if (yikamaState == 0)
  {
  }
  else {
    counter1++;
    currency-=10;
    lcd.clear();
    lcd.print("BAKIYE = " + String(currency) + "TL");
    lcd.setCursor(0, 1);
    lcd.print(String(counter1) + "-yikama");
    if (currency < 0)
    {
      counter1--;
      currency+=15;
      lcd.clear();
      lcd.print("YETERSIZ BAKIYE");
      lcd.setCursor(0, 1);
      lcd.print("BAKIYE = " + String(currency) + "TL");
    }
    delay(500);
  }
}
void func_kurulama()
{
  if (kurulamaState == 0)
  {
  }
  else {
    counter5++;
    currency-=5;

    lcd.clear();
    lcd.print("BAKIYE = " + String(currency) + "TL");
    lcd.setCursor(0, 1);
    lcd.print(String(counter5) + "-kurulama");
    if (currency < 0)
    {
      counter5--;
      currency+=5;
      lcd.clear();
      lcd.print("YETERSIZ BAKIYE");
      lcd.setCursor(0, 1);
      lcd.print("BAKIYE = " + String(currency) + "TL");
    }
    delay(500);
  }
}
void func_cilalama()
{
  if (cilalamaState == 0)
  {
  }
  else {
    counter3++;
    currency -= 50;
    lcd.clear();
    lcd.print("BAKIYE = " + String(currency) + "TL");
    lcd.setCursor(0, 1);
    lcd.print(String(counter3) + "-cilalama");
    if (currency < 0)
    {
      counter3--;
      currency += 50;
      lcd.clear();
      lcd.print("YETERSIZ BAKIYE");
      lcd.setCursor(0, 1);
      lcd.print("BAKIYE = " + String(currency) + "TL");
    }
    delay(500);
  }
}

void func_Reset()
{
  if (ResetState == 0)
  {
  }
  else {
    resetCounters();
    lcd.clear();
    lcd.print("BAKIYE = " + String(currency) + "TL");
    lcd.setCursor(0, 1);
    lcd.print("TEKRAR SECIN");
  }
}
void func_Bitis()
{
  if (Bitis2State == 0)
  {
    digitalWrite(Redled, LOW);
    digitalWrite(greenled, LOW);

  }
  else {
    minusCounters();
    randomNum();
    delay(500);
  }
}
void randomNum()
{
  randomNumber = random(0, 4);
  Serial.println("Random Sayi= " + String(randomNumber));
  if (randomNumber == 2)
  {
    digitalWrite(Redled, HIGH);

    lcd.clear();
    lcd.print("PARA SIKISTI");
    lcd.setCursor(0, 1);
    lcd.print("RESET'E BASINIZ");
  }
  else
  {

    digitalWrite(greenled, HIGH);
    lcd.clear();
    lcd.print("PARA USTUNUZ");
    lcd.setCursor(0, 1);
    lcd.print(String(currency) + "TL");
    Serial.println(String(currency) + "TL");
    backInChange();
    Serial.println("Kasada kalan para miktarlari");
    Serial.println("5TL " + String(coinStocks[0]) + "  10TL " + String(coinStocks[1]) + "  20TL " + String(coinStocks[2]) + "  50TL " + String(coinStocks[3]) + "  100TL " + String(coinStocks[4]));
    Serial.println("Kasada kalan urun miktarlari");
    Serial.println("kurulama" + String(diziKurulama[0]) + " yikama" + String(diziYikama[0]) + " kurulama" + String(diziKurulama[0]) + " cilalama" + String(diziCilalama[0]));

  }
}
void paraUstu(){

float para_ustu=0;
  int yuz=0, elli=0,yirmi=0, on=0, bes=0;

 Serial.println(" Para miktarini TL olarak giriniz : "); /**/ scanf("%f", &para_ustu);

  yuz=para_ustu/100;
  para_ustu -=100*yuz;

  elli=para_ustu/50;
  para_ustu -=50*elli;

  yirmi = para_ustu/20;
  para_ustu -= 20*yirmi;

  on = para_ustu/10;
  para_ustu -= 10*on;

  bes = para_ustu/5;
  para_ustu -= 5*bes;


 

  system("PAUSE");

}
void resetCounters()
{
  diziKopukleme[0] = 20;
  diziYikama[0] = 20;
  diziKurulama[0] = 10;
  diziCilalama[0] = 30;

  counter1 = 0;
  counter2 = 0;
  counter3 = 0;
  counter4 = 0;
  counter5 = 0;
  currency = tempCurrency;
}
void minusCounters()
{
  diziKopukleme[0] -= counter1;
  diziYikama[0] -= counter2;
  diziKurulama[0] -= counter3;
  diziCilalama[0] -= counter4;

}

void backInChange()
{

  if (coinStocks[0] <= 0 && coinStocks[1] <= 0 && coinStocks[2] <= 0)
  {
    lcd.clear();
    lcd.print("Kasada yeterli");
    lcd.setCursor(0, 1);
    lcd.print("para yoktur");
  }
}
