#pragma once

#include<winsock2.h>

#define BUFLEN 8192

class UDPServer
{
public:
	UDPServer(void);
	~UDPServer(void);

	bool init();
	char* receive();
	void close();

private:
	struct sockaddr_in server, si_other;
    int slen;
	int s; //SOCKET
	int recv_len;
    char buf[BUFLEN];
    char message[BUFLEN];
    WSADATA wsa;
};

