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
        bool ChecarEndereco(int end){
            return end == enderecoLocal ? 1 : 0;
        }
        
        char ConverterChar(int n){
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
            }
        }

        int GetMensagem(){
            return mensagemRecebida;
        }

        void SetEnderecoLocal(int v){
            enderecoLocal = v;
        }

        void EscreverMensagem(int remetente, int destino, int msg){
            mensagem.remetente = remetente;
            mensagem.destino = destino;
            mensagem.mensagemEnviada = msg;
        }
        
        bool ReceberMensagem(){
            if(ChecarEndereco(mensagem.destino)){
                mensagemRecebida = mensagem.mensagemEnviada;
                return 1;
            }   
            else{
                EnviarMensagem();
                return 0;
            }        
        }
        
        virtual void IniciarComunicacao();
        virtual void LerMensagem(int serial);
        virtual void EnviarMensagem();        
};

#endif