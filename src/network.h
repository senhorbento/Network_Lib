#ifndef _NETWORK_LIB_H_
#define _NETWORK_LIB_H_

#include <Arduino.h>

#define _DELAY_ 100

typedef struct{
    int remetente;
    int destino;
    int mensagemEnviada;
} TMensagem;

int velocidadeSerial[] = {
    4800, 
    9600, 
    19200, 
    57600
};

class Network{
    private:
        int endereco;
        int mensagemRecebida;
        TMensagem mensagem;
    public:
        boolean ChecarEndereco(int end);
        TMensagem LerMensagem(int serial);
        void IniciarComunicacao();
        void EnviarMensagem();
        void SetEndereco(int v);
        void ReceberMensagem(TMensagem msg);
        void EscreverMensagem(int remetente, int destino, int mensagem);
};

boolean Network::ChecarEndereco(int end){
    return end == endereco ? 1 : 0;
}

TMensagem Network::LerMensagem(int serial){
    TMensagem mensagemRecebida;
    switch (serial){
        case 0:
            mensagemRecebida.remetente = Serial.read();
            delay(_DELAY_);
            mensagemRecebida.destino = Serial.read();
            delay(_DELAY_);
            mensagemRecebida.mensagemEnviada = Serial.read();
            delay(_DELAY_);
        break;
        case 1:
            mensagemRecebida.remetente = Serial1.read();
            delay(_DELAY_);
            mensagemRecebida.destino = Serial1.read();
            delay(_DELAY_);
            mensagemRecebida.mensagemEnviada = Serial1.read();
            delay(_DELAY_);
        break;
        case 2:
            mensagemRecebida.remetente = Serial2.read();
            delay(_DELAY_);
            mensagemRecebida.destino = Serial2.read();
            delay(_DELAY_);
            mensagemRecebida.mensagemEnviada = Serial2.read();
            delay(_DELAY_);
        break;
        case 3:
            mensagemRecebida.remetente = Serial3.read();
            delay(_DELAY_);
            mensagemRecebida.destino = Serial3.read();
            delay(_DELAY_);
            mensagemRecebida.mensagemEnviada = Serial3.read();
            delay(_DELAY_);
        break;
    }
}

void Network::IniciarComunicacao(){
    Serial.begin(VelocidadeSerial[0]);
    Serial3.begin(VelocidadeSerial[3]);
}

void Network::EnviarMensagem(){
    if(mensagem.remetente > endereco){
        Serial3.print(mensagem.remetente);
        delay(_DELAY_);
        Serial3.print(mensagem.destino);
        delay(_DELAY_);
        Serial3.print(mensagem.mensagemEnviada);
        delay(_DELAY_);
    }
    else{
        Serial.print(mensagem.remetente);
        delay(_DELAY_);
        Serial.print(mensagem.destino);
        delay(_DELAY_);
        Serial.print(mensagem.mensagemEnviada);
        delay(_DELAY_);
    }
}

void Network::SetEndereco(int v){
    endereco = v;
}
void Network::ReceberMensagem(TMensagem msg){
    if(ChecarEndereco(msg.remetente))
        mensagemRecebida = msg.mensagemEnviada;
    else{
        EscreverMensagem(msg.remetente, msg.destino, msg.mensagemEnviada);
        EnviarMensagem();
    }        
}

void Network::EscreverMensagem(int remetente, int destino, int msg){
    mensagem.remetente = remetente;
    mensagem.destino = destino;
    mensagem.mensagemEnviada = msg;
}
#endif