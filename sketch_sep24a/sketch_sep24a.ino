// C++ code
//

// Define as portas
#define greenLed 2
#define yellowLed 3
#define redLed 4
#define ldr A0
#define buzzer 5

// Variável inteira para a leitura do valor da luminozidade e do buzzer
int light = 0;
int buzzerYellow = 0;
int buzzerRed = 0;

void setup()
{
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(ldr, INPUT);
  Serial.begin(9600);
}

void loop()
{
  ldrF(); // Inicia o código que liga os LED's ao LDR
  onRedBuzzer(); // Inicia o código que liga o buzzer ao LED Vermelho
  onYellowBuzzer(); // Inicia o código que liga o buzzer ao LED Amarelo
  delay(1000);
}

/* Void que carrega o código
 que faz a leitura do LDR e instrui 
 qual LED deve estar aceso */
void ldrF(){
  light = analogRead(ldr); // Atribui o valor da leitura analógica ao inteiro light
  delay(100); // Delay para o código não travar o navegador
  /*Leitura condicional do valor de light para definir qual LED
  deve estar aceso.
  Deve ser definido em cada uma das condicionais quais LED's
  devem estar acesos e desligados, pois pode gerar um bug
  que mantem os LED's acesos quando a condição altera para uma
  anterior*/
  if((light)<700){ 
    digitalWrite(greenLed, HIGH);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, LOW);
  }
  else{
    if((light)> 700 && (light)<900){
      digitalWrite(greenLed, LOW);
      digitalWrite(yellowLed, HIGH);
      digitalWrite(redLed, LOW);
    }
    else{
      digitalWrite(greenLed, LOW);
      digitalWrite(yellowLed, LOW);
      digitalWrite(redLed, HIGH);
    }
  }
}
/* Void que carrega o código que
correlaciona o LED vermelho com o buzzer*/
void onYellowBuzzer(){
  buzzerYellow = digitalRead(yellowLed);
  delay(100);
  // Caso o LED amarelo esteja aceso, o buzzer soará
  if((buzzerYellow) == HIGH){
    tone(buzzer, 1000);
    delay(3000);
    noTone(buzzer);
    delay(3000);
  }
  else{
    noTone(buzzer);
  }
}

/* Void que carrega o código que
correlaciona o LED vermelho com o buzzer*/
void onRedBuzzer(){
  buzzerRed = digitalRead(redLed);
  delay(100);
  // Caso o LED vermelho esteja aceso, o buzzer soará
  if((buzzerRed) == HIGH){
    tone(buzzer, 1000);
    delay(10000);
  }
  else{
    noTone(buzzer);
  }
}