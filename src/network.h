#ifndef _NETWORK_LIB_H_
#define _NETWORK_LIB_H_

#include <Arduino.h>

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
        void IniciarComunicacao();
        void SetEndereco(int v);
        void EscreverMensagem(int remetente, int destino, int mensagem);
        void EnviarMensagem();
        void ReceberMensagem(TMensagem msg);
};

boolean Network::ChecarEndereco(int end){
    return end == endereco ? 1 : 0;
}

void Network::IniciarComunicacao(){
    Serial.begin(VelocidadeSerial[0]);
    Serial3.begin(VelocidadeSerial[3]);
}

void Network::SetEndereco(int v){
    endereco = v;
}

void Network::EscreverMensagem(int remetente, int destino, int msg){
    mensagem.remetente = remetente;
    mensagem.destino = destino;
    mensagem.mensagemEnviada = msg;
}

void Network::EnviarMensagem(){
    if(mensagem.remetente > endereco){
        Serial3.print(mensagem.remetente);
        Serial3.print(mensagem.destino);
        Serial3.print(mensagem.mensagemEnviada);
    }
    else{
        Serial.print(mensagem.remetente);
        Serial.print(mensagem.destino);
        Serial.print(mensagem.mensagemEnviada);
    }
}

void Network::ReceberMensagem(TMensagem msg){
    EscreverMensagem(msg.remetente, msg.destino, msg.mensagemEnviada);
    if(ChecarEndereco(mensagem.remetente))
        mensagemRecebida = mensagem.mensagemEnviada;
    else
        EnviarMensagem();
}

#endif