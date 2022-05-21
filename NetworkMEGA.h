#ifndef _NETWORK_MEGA_H_
#define _NETWORK_MEGA_H_

#include "include\Network.h"

class NetworkMEGA : public Network{
    public:
        void IniciarComunicacao();
        void LerMensagem(int serial);
        void EnviarMensagem();
};

#endif