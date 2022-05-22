#ifndef _NETWORK_LIB_H_
#define _NETWORK_LIB_H_

#include <Arduino.h>

typedef struct{
    int remetente;
    int destino;
    int mensagemEnviada;
    int serial;
} TMensagem;

class Network{
    protected:
        int enderecoLocal;
        int mensagemRecebida;
        TMensagem mensagem;
        long int VelocidadeSerial[4] = {4800, 9600, 19200, 57600};
    public:
        bool ChecarEndereco(int end);
        char ConverterChar(int n);

        int GetMensagem();
        void SetEnderecoLocal(int v);
        void EscreverMensagem(int remetente, int destino, int msg, int serial);
        bool ReceberMensagem();
        
        virtual void IniciarComunicacao();
        virtual void LerMensagem(int serial);
        virtual void EnviarMensagem();        
};

bool Network :: ChecarEndereco(int end){
    return end == enderecoLocal ? 1 : 0;
}

char Network :: ConverterChar(int n){
    switch (n){
        case 0:
            return '0';
        case 1:
            return '1';
        case 2:
            return '2';
        case 3:
            return '3';
        case 4:
            return '4';
        case 5:
            return '5';
        case 6:
            return '6';
        case 7:
            return '7';
        case 8:
            return '8';
        case 9:
            return '9';
        default:
            return 'a';
    }
}

int Network :: GetMensagem(){
    return mensagemRecebida;
}

void Network :: SetEnderecoLocal(int v){
    enderecoLocal = v;
}

void Network :: EscreverMensagem(int remetente, int destino, int msg, int serial){
    mensagem.remetente = remetente;
    mensagem.destino = destino;
    mensagem.mensagemEnviada = msg;
    mensagem.serial = serial;
}

bool Network :: ReceberMensagem(){
    if(ChecarEndereco(mensagem.destino)){
        mensagemRecebida = mensagem.mensagemEnviada;
        return 1;
    }   
    else{
        EnviarMensagem();
        return 0;
    }        
}      

#endif