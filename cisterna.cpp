#include <LiquidCrystal.h>

#define RS 2     
#define EN 3
#define DB4 4 
#define DB5 5
#define DB6 6
#define DB7 7
#define N1_90 12
#define N2_80 11
#define N3_20 10
#define valvula 9
#define bomba 13

LiquidCrystal lcd(RS, EN, DB4, DB5, DB6, DB7);

const int qtd_niveis = 3;
const int incrementaPorta = 1;
const int decrementaPorta = 8;
const int maximoNivelAgua = 10;
int nivelAgua = 0;

int leds[qtd_niveis]={
                    N1_90,
                    N2_80,
                    N3_20
                    };

void exibeUnicariocaEmAcao() {
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    // Print a message to the LCD.
    lcd.setCursor(3, 0);
    lcd.print("UNICARIOCA");
    lcd.setCursor(5, 1);
    lcd.print("AV1-165");
    delay(3000);
}

void exibeNivelAgua() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("NIVEL DA AGUA");
    lcd.setCursor(0, 1);  //( COLUNA , LINHA)  
    lcd.print("ATUALMENTE:   %");
    lcd.setCursor(11, 1);
    lcd.print(nivelAgua * 10);
}

void acionamentoNiveis(){
// Acende led do nível baixo
    if(nivelAgua>=2){ 
        digitalWrite(N3_20, HIGH);
    }
    else if(nivelAgua<2){ 
        digitalWrite(N3_20, LOW);
    }

    //Acende led do nível médio
    if(nivelAgua>=8){ 
        digitalWrite(N2_80, HIGH);
    }
    else if(nivelAgua<8){
        digitalWrite(N2_80, LOW);
    }

    //Acende led do nível alto
    if(nivelAgua>=9){
        digitalWrite(N1_90, HIGH);
    }
    else if(nivelAgua<9){
        digitalWrite(N1_90, LOW);
        
    }
}

void incrementa(){
    if (nivelAgua < 2) {
    digitalWrite(valvula,HIGH);
    } 
    else if (nivelAgua < 8) {
    digitalWrite(valvula,HIGH);
    } 
    else if (nivelAgua < 9) {
    digitalWrite(valvula,HIGH);
    }
    else {
    digitalWrite(bomba,HIGH);
    digitalWrite(valvula,LOW);
    }
}

void decrementa(){
    if (nivelAgua > 8) {
    digitalWrite(bomba,HIGH);
    digitalWrite(valvula,LOW);
    } 
    else if (nivelAgua <= 8 && nivelAgua > 2) {
    digitalWrite(bomba,HIGH);
    digitalWrite(valvula,LOW);
    } 
    else{
    digitalWrite(bomba,LOW);
    digitalWrite(valvula,HIGH); 
    }
}

void setup()
{
    pinMode(incrementaPorta, INPUT);
    pinMode(decrementaPorta, INPUT);
    pinMode(valvula, OUTPUT);
    pinMode(bomba, OUTPUT);

    for (int i=0; i<= qtd_niveis; i++)
    {
        pinMode(leds[i],OUTPUT);  
    }
    exibeUnicariocaEmAcao();
}

void loop() 
{
    int botaoIncrementoStatus = digitalRead(incrementaPorta);
    int botaoDecrementoStatus = digitalRead(decrementaPorta);

    if (nivelAgua == 0)
    {
        digitalWrite(valvula,HIGH);
    }
    
    if(botaoIncrementoStatus == HIGH && nivelAgua < maximoNivelAgua) 
    {
        nivelAgua += 1;    
        incrementa();
    }

    if(botaoDecrementoStatus == HIGH && nivelAgua > 0) 
    {
        nivelAgua -= 1;
        decrementa();
    }
    acionamentoNiveis();
    exibeNivelAgua();
    delay(200);
}
