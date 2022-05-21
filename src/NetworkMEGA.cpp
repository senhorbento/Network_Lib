#include "NetworkMEGA.h"

void NetworkMEGA :: IniciarComunicacao(){
    Serial.begin(VelocidadeSerial[0]);
    Serial3.begin(VelocidadeSerial[3]);
}

void NetworkMEGA :: LerMensagem(int serial){
    switch (serial){
    case 0:
        mensagem.remetente = Serial1.parseInt();
        mensagem.destino = Serial1.parseInt();
        mensagem.mensagemEnviada = Serial1.parseInt();
    break;
    case 1:
        mensagem.remetente = Serial1.parseInt();
        mensagem.destino = Serial1.parseInt();
        mensagem.mensagemEnviada = Serial1.parseInt();
    break;
    case 2:
        mensagem.remetente = Serial2.parseInt();
        mensagem.destino = Serial2.parseInt();
        mensagem.mensagemEnviada = Serial2.parseInt();
    break;
    case 3:
        mensagem.remetente = Serial3.parseInt();
        mensagem.destino = Serial3.parseInt();
        mensagem.mensagemEnviada = Serial3.parseInt();
    break;
    }
}

void NetworkMEGA :: EnviarMensagem(){
    char aux [4];
    aux[0] = ConverterChar(mensagem.remetente);
    aux[1] = ConverterChar(mensagem.destino);
    aux[2] = ConverterChar(mensagem.mensagemEnviada);
    aux[3] = '*';
    
    if(mensagem.destino > enderecoLocal)
        Serial3.print(aux);
    else
        Serial.print(aux);
}