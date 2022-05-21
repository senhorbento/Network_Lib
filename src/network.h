#ifndef _NETWORK_LIB_H_
#define _NETWORK_LIB_H_

#include <Arduino.h>

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
        int enderecoLocal;
        int mensagemRecebida;
        TMensagem mensagem;
    public:
        boolean ChecarEndereco(int end);

        int GetMensagem();
        void SetEnderecoLocal(int v);

        void IniciarComunicacao(int qtd);
        void IniciarComunicacao();

        void EscreverMensagem(int remetente, int destino, int msg);
        void LerMensagem(int serial);   //1
        boolean ReceberMensagem();      //2
        void EnviarMensagem();          //3
        
};

//Metodo auxiliar
boolean Network::ChecarEndereco(int end){
    return end == enderecoLocal ? 1 : 0;
}

//Gets and Sets
int Network::GetMensagem(){
    return mensagemRecebida;
}
void Network::SetEnderecoLocal(int v){
    enderecoLocal = v;
}

//Iniciar comunicação
void Network::IniciarComunicacao(int qtd){
    switch (qtd){
        case 0:
            Serial.begin(VelocidadeSerial[0]);
        break;
        case 1:
            Serial1.begin(VelocidadeSerial[1]);
        break;
        case 2:
            Serial2.begin(VelocidadeSerial[2]);
        break;
        case 3:
            Serial3.begin(VelocidadeSerial[3]);
        break;
    }
}
void Network::IniciarComunicacao(){
    Serial.begin(VelocidadeSerial[0]);
    Serial3.begin(VelocidadeSerial[3]);
}

//Tratamento de mensagens
void Network::EscreverMensagem(int remetente, int destino, int msg){
    mensagem.remetente = remetente;
    mensagem.destino = destino;
    mensagem.mensagemEnviada = msg;
}

void Network::LerMensagem(int serial){
    switch (serial){
        case 0:
            mensagem.remetente = Serial.parseInt();
            mensagem.destino = Serial.parseInt();
            mensagem.mensagemEnviada = Serial.parseInt();
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

boolean Network::ReceberMensagem(){
    if(ChecarEndereco(mensagem.destino)){
        mensagemRecebida = mensagem.mensagemEnviada;
        return 1;
    }   
    else{
        EnviarMensagem();
        return 0;
    }        
}

void Network::EnviarMensagem(){
    if(mensagem.destino > enderecoLocal){
        Serial3.write(mensagem.remetente);
        Serial3.write("*");
        Serial3.write(mensagem.destino);
        Serial3.write("*");
        Serial3.write(mensagem.mensagemEnviada);
        Serial3.write("*");
    }
    else{
        Serial.write(mensagem.remetente);
        Serial.write("*");
        Serial.write(mensagem.destino);
        Serial.write("*");
        Serial.write(mensagem.mensagemEnviada);
        Serial.write("*");
    }
}
#endif