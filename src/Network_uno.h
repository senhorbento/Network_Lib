#ifndef _NETWORK_LIB_H_
#define _NETWORK_LIB_H_

#include <Arduino.h>

#define _DELAY_ 1000

typedef struct{
    int remetente;
    int destino;
    int mensagemEnviada;
} TMensagem;

long int VelocidadeSerial[] = {
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
        boolean ReceberMensagem(TMensagem msg);
        TMensagem LerMensagem(int serial);
        void IniciarComunicacao(int qtd);
        void IniciarComunicacao();
        void SetEndereco(int v);
        void EnviarMensagem();
        void EscreverMensagem(int remetente, int destino, int mensagem);
};

boolean Network::ChecarEndereco(int end){
    return end == endereco ? 1 : 0;
}

bool Network::ReceberMensagem(TMensagem msg){
    if(ChecarEndereco(msg.destino)){
        mensagemRecebida = msg.mensagemEnviada;
        return 1;
    }   
    else{
        EscreverMensagem(msg.remetente, msg.destino, msg.mensagemEnviada);
        EnviarMensagem();
        return 0;
    }        
}

TMensagem Network::LerMensagem(int serial){
    TMensagem mensagemRecebida;
    switch (serial){
        case 0:
            Serial.setTimeout(100);
            mensagemRecebida.remetente = Serial.parseInt();
            mensagemRecebida.destino = Serial.parseInt();
            mensagemRecebida.mensagemEnviada = Serial.parseInt();
        break;
    }
    return mensagemRecebida;
}

void Network::IniciarComunicacao(int qtd){
    switch (qtd){
        case 0:
            Serial.begin(VelocidadeSerial[0]);
        break;
    }
}

void Network::IniciarComunicacao(){
    Serial.begin(VelocidadeSerial[0]);
}

void Network::SetEndereco(int v){
    endereco = v;
}

void Network::EnviarMensagem(){
    Serial.write(mensagem.remetente);
    delay(_DELAY_);
    Serial.write(mensagem.destino);
    delay(_DELAY_);
    Serial.write(mensagem.mensagemEnviada);
    delay(_DELAY_);
}

void Network::EscreverMensagem(int remetente, int destino, int msg){
    mensagem.remetente = remetente;
    mensagem.destino = destino;
    mensagem.mensagemEnviada = msg;
}

#endif