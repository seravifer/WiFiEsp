/*--------------------------------------------------------------------
This file is part of the Arduino WiFiEsp library.

The Arduino WiFiEsp library is free software: you can redistribute it
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

The Arduino WiFiEsp library is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with The Arduino WiFiEsp library.  If not, see
<http://www.gnu.org/licenses/>.
--------------------------------------------------------------------*/

#ifndef WiFiEspServer_h
#define WiFiEspServer_h

#include <Server.h>

#include "WiFiEsp.h"


class WiFiEspClient;

class WiFiEspServer : public Server {

private:
    uint16_t _port;
    uint8_t _sock;
    bool _started;


public:
    WiFiEspServer(uint16_t);

    void begin(uint16_t port);

    WiFiEspClient available(uint8_t *status = NULL);

    uint8_t status();

    virtual size_t write(uint8_t);

    virtual size_t write(const uint8_t *buf, size_t size);

    using Print::write;

};

#endif
