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
void Network::IniciarComunicacao(){
    Serial.begin(VelocidadeSerial[0]);
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
    Serial.write(mensagem.remetente);
    Serial.write("*");
    Serial.write(mensagem.destino);
    Serial.write("*");
    Serial.write(mensagem.mensagemEnviada);
    Serial.write("*");
}
#endif