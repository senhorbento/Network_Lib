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
    protected:
        int enderecoLocal;
        int mensagemRecebida;
        TMensagem mensagem;
    public:
        bool ChecarEndereco(int end);
        char ConverterChar(int n);

        int GetMensagem();
        void SetEnderecoLocal(int v);
        void EscreverMensagem(int remetente, int destino, int msg);
        bool ReceberMensagem();
        
        virtual void IniciarComunicacao();
        virtual void LerMensagem(int serial);
        virtual void EnviarMensagem();        
};

#endif