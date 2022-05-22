#ifndef _NETWORK_UNO_H_
#define _NETWORK_UNO_H_

#include "Network.h"

class NetworkUNO : public Network{
    public:
        void IniciarComunicacao();
        void LerMensagem(int serial);
        void EnviarMensagem();
};

void NetworkUNO :: IniciarComunicacao(){
    Serial.begin(VelocidadeSerial[0]);
}

void NetworkUNO :: LerMensagem(int serial){
    //NotWorking
}

void NetworkUNO :: EnviarMensagem(){
    char aux [4];
    aux[0] = ConverterChar(mensagem.remetente);
    aux[1] = ConverterChar(mensagem.destino);
    aux[2] = ConverterChar(mensagem.mensagemEnviada);
    aux[3] = '*';
    Serial.write(aux);
}

#endif