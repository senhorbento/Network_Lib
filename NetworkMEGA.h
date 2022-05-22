#ifndef _NETWORK_MEGA_H_
#define _NETWORK_MEGA_H_

#include "Network.h"

class NetworkMEGA : public Network{
    public:
        void IniciarComunicacao();
        void LerMensagem(int serial);
        void EnviarMensagem();
};

void NetworkMEGA :: IniciarComunicacao(){
    Serial.begin(VelocidadeSerial[0]);
    Serial3.begin(VelocidadeSerial[3]);
}

void NetworkMEGA :: LerMensagem(int serial){
    //NotWorking
}

void NetworkMEGA :: EnviarMensagem(){
    char aux [4];
    aux[0] = ConverterChar(mensagem.remetente);
    aux[1] = ConverterChar(mensagem.destino);
    aux[2] = ConverterChar(mensagem.mensagemEnviada);
    aux[3] = '*';
    
    if(mensagem.serial == 0)
        Serial3.write(aux);
    else
        Serial.write(aux);
}

#endif