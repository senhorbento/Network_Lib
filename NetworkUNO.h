#ifndef _NETWORK_UNO_H_
#define _NETWORK_UNO_H_

#include "Network.h"

class NetworkUNO : public Network{
    public:
        void IniciarComunicacao();
        void LerMensagem(int serial);
        void EnviarMensagem();
};

#endif