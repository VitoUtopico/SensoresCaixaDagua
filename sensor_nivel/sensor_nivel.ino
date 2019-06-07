const int SENSOR_ALTO = D5;
const int SENSOR_BAIXO = D6;
const int CHAVE_BOMBA = D7;
const int VOLUME_CAIXA = 1000;
int contaConsumo = 0;



void setup() {
  Serial.begin(115200);
  pinMode(SENSOR_ALTO,0);
  pinMode(SENSOR_BAIXO,0);
  pinMode(CHAVE_BOMBA,1);

  digitalWrite(CHAVE_BOMBA, 0);
  Serial.println("\n");
  Serial.println("Sistema de verificação de nível d'água ACME ativo \n");
}

void loop() {
  if(digitalRead(SENSOR_ALTO)==1 and digitalRead(CHAVE_BOMBA)== 1){
    digitalWrite(CHAVE_BOMBA, 0);
    Serial.println("Bomba desligada. \n");
    Serial.println("-------------------------------------------------------------");
  }
  else if(digitalRead(SENSOR_ALTO)==0 and digitalRead(SENSOR_BAIXO)==0 and digitalRead(CHAVE_BOMBA) == 0){
    digitalWrite(CHAVE_BOMBA, 1);
    contaConsumo += 1;
    Serial.println("O volume total da caixa d'água foi consumido "+ String(contaConsumo) + " vezes.\n ");
    if(VOLUME_CAIXA != 0){          
          Serial.println("Total de " + String(contaConsumo * VOLUME_CAIXA) + " litros\n");
    }
    Serial.println("A bomba está ligada! \n");
     
  }
}
