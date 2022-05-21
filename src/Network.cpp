#include "Network.h"

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
    }
}

int Network :: GetMensagem(){
    return mensagemRecebida;
}

void Network :: SetEnderecoLocal(int v){
    enderecoLocal = v;
}

void Network :: EscreverMensagem(int remetente, int destino, int msg){
    mensagem.remetente = remetente;
    mensagem.destino = destino;
    mensagem.mensagemEnviada = msg;
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