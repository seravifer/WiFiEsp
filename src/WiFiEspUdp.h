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

#ifndef WiFiEspUdp_h
#define WiFiEspUdp_h

#include <Udp.h>


class WiFiEspUDP : public UDP {

private:
    uint8_t _sock;
    uint16_t _port;

    uint16_t _remotePort;
    char _remoteHost[30];


public:
    WiFiEspUDP();

    /**
     * Initialize UDPServer, start listening on specified port.
     * Returns 1 if successful, 0 if there are no sockets available to use
     */
    virtual uint8_t begin(uint16_t);

    /**
     * Return number of bytes available in the current packet,
     * will return 0 if parsePacket hasn't been called yet
     */
    virtual int available();

    /**
     * Release any resources being used by this WiFiUDP instance
     * Finish with the UDP socket
     */
    virtual void stop();

    /**
     * Start building up a packet to send to the remote host specific in ip and port
     * Returns 1 if successful, 0 if there was a problem with the supplied IP address or port
     */
    virtual int beginPacket(IPAddress ip, uint16_t port);

    /**
     * Start building up a packet to send to the remote host specific in host and port
     * Returns 1 if successful, 0 if there was a problem resolving the hostname or port
     */
    virtual int beginPacket(const char *host, uint16_t port);

    /**
     * Finish off this packet and send it
     * Returns 1 if the packet was sent successfully, 0 if there was an error
     * No At command
     */
    virtual int endPacket();

    /**
     * Write a single byte into the packet
     */
    virtual size_t write(uint8_t);

    /**
     * Write size bytes from buffer into the packet
     */
    virtual size_t write(const uint8_t *buffer, size_t size);

    /**
     * Start processing the next available incoming packet
     * Returns the size of the packet in bytes, or 0 if no packets are available
     */
    virtual int parsePacket();

    /**
     * Read a single byte from the current packet
     */
    virtual int read();

    /**
     * Read up to len bytes from the current packet and place them into buffer
     * Returns the number of bytes read, or 0 if none are available
     */
    virtual int read(unsigned char *buffer, size_t len);

    /**
     * Read up to len characters from the current packet and place them into buffer
     * Returns the number of characters read, or 0 if none are available
     */
    virtual int read(char *buffer, size_t len) { return read((unsigned char *) buffer, len); };

    /**
     * Return the next byte from the current packet without moving on to the next byte
     * No At command
     */
    virtual int peek();

    /**
     * Finish reading the current packet
     */
    virtual void flush();

    /**
     * Return the IP address of the host who sent the current incoming packet
     */
    virtual IPAddress remoteIP();

    /**
     * Return the port of the host who sent the current incoming packet
     */
    virtual uint16_t remotePort();

    using Print::write;


    friend class WiFiEspServer;
};

#endif
