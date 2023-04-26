#include <Servo.h>
const int ldrEsqCima=A3;
const int ldrDirCima=A0;
const int ldrEsqBaixo=A2;
const int ldrDirBaixo=A1;
const int tempoMov=5;
const int tolerancia=10;
int posicaoServoHorizontal=90;
int posicaoServoVertical=30;
Servo servoHorizontal;
Servo servoVertical;
void setup(){
  servoHorizontal.attach(10);
  servoVertical.attach(11);
}
void loop(){
  int leituraEsqCima=analogRead(ldrEsqCima);
  int leituraDirCima=analogRead(ldrDirCima);
  int leituraEsqBaixo=analogRead(ldrEsqBaixo);
  int leituraDirBaixo=analogRead(ldrDirBaixo);
  int mediaCima=(leituraEsqCima+leituraDirCima)/2;
  int mediaBaixo=(leituraEsqBaixo+leituraDirBaixo)/2;
  int mediaEsq=(leituraEsqCima+leituraEsqBaixo)/2;
  int mediaDir=(leituraDirCima+leituraDirBaixo)/2;
  int difVertical=mediaCima-mediaBaixo;
  int difHorizontal=mediaEsq-mediaDir;
  if(-1*tolerancia>difVertical||difVertical>tolerancia){
    if(mediaCima>mediaBaixo){
      posicaoServoVertical=++posicaoServoVertical;
      if(posicaoServoVertical>60)
        posicaoServoVertical=60;
    }
    else if(mediaCima<mediaBaixo){
      posicaoServoVertical=--posicaoServoVertical;
      if(posicaoServoVertical<0)
        posicaoServoVertical=0;
    }
    servoVertical.write(posicaoServoVertical);
  }
  if(-1*tolerancia>difHorizontal||difHorizontal>tolerancia){
    if(mediaEsq>mediaDir){
      posicaoServoHorizontal=--posicaoServoHorizontal;
      if(posicaoServoHorizontal<30)
        posicaoServoHorizontal=30;
    }
    else if(mediaEsq<mediaDir){
      posicaoServoHorizontal=++posicaoServoHorizontal;
      if(posicaoServoHorizontal>150)
        posicaoServoHorizontal=150;
    }
    servoHorizontal.write(posicaoServoHorizontal);
  }
delay(tempoMov);
} 
