#include "stdafx.h"
#include "UDPServer.h"

#include<stdio.h>
 
#pragma comment(lib,"ws2_32.lib") //Winsock Library
 
#define SERVER "127.0.0.1"  //ip address of udp server
#define BUFLEN 8192  //Max length of buffer
#define PORT 8888   //The port on which to listen for incoming data

#include <string>

UDPServer::UDPServer(void)
{
}


UDPServer::~UDPServer(void)
{
}

bool UDPServer::init()
{
	slen = sizeof(si_other);

	//Initialise winsock
    printf("\nInitialising Winsock...");
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
    {
        printf("Failed. Error Code : %d",WSAGetLastError());
        return false;
    }
    printf("Initialised.\n");
     
    //create socket
    if ( (s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == SOCKET_ERROR)
    {
        printf("socket() failed with error code : %d" , WSAGetLastError());
        return false;
    }

	//Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( PORT );
     
    //setup address structure
    memset((char *) &si_other, 0, sizeof(si_other));
    si_other.sin_family = AF_INET;
    si_other.sin_port = htons(PORT);
    si_other.sin_addr.S_un.S_addr = inet_addr(SERVER);


	//Bind
    if( bind(s ,(struct sockaddr *)&server , sizeof(server)) == SOCKET_ERROR)
    {
        printf("Bind failed with error code : %d" , WSAGetLastError());
        return false;
    }
    puts("Bind done");

	return true;

}

char* UDPServer::receive()
{
        //clear the buffer by filling null, it might have previously received data
        memset(buf,'\0', BUFLEN);
        //try to receive some data, this is a blocking call
        if ((recv_len = recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &slen)) == SOCKET_ERROR)
        {
            printf("recvfrom() failed with error code : %d" , WSAGetLastError());
            Sleep(500);
        } else {
			//puts(buf);
			return buf;
			//std::string s(buf);
			//printf(buf);

		}
 


}

void UDPServer::close()
{
	closesocket(s);
    WSACleanup();
}