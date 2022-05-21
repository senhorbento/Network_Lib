#include "NetworkUNO.h"

void NetworkUNO :: IniciarComunicacao(){
    Serial.begin(VelocidadeSerial[0]);
}

void NetworkUNO :: LerMensagem(int serial){
    switch (serial){
        case 0:
            mensagem.remetente = Serial.parseInt();
            mensagem.destino = Serial.parseInt();
            mensagem.mensagemEnviada = Serial.parseInt();
        break;
    }
}

void NetworkUNO :: EnviarMensagem(){
    char aux [4];
    aux[0] = ConverterChar(mensagem.remetente);
    aux[1] = ConverterChar(mensagem.destino);
    aux[2] = ConverterChar(mensagem.mensagemEnviada);
    aux[3] = '*';
    Serial.print(aux);
}