#include<iostream>
#include<Winsock2.h>
using namespace std;
void main()
{
	WORD wVersionRequested;
	WSADATA wmxData;
	int err;
	wVersionRequested=MAKEWORD(1,1);
	err=WSAStartup(wVersionRequested,&wmxData);
	if(err!=0){
		return;
	}
	if(LOBYTE(wmxData.wVersion)!=1||HIBYTE(wmxData.wVersion)!=1){
		WSACleanup();
		return ;
	}
	SOCKET
	sockSrv=socket(AF_INET,SOCK_STREAM,0);
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr=htonl(INADDR_ANY);
	addrSrv.sin_family=AF_INET;
	addrSrv.sin_port=htons(6000);
	bind(sockSrv,(SOCKADDR*)&addrSrv,sizeof(SOCKADDR));
	listen(sockSrv,5);
	SOCKADDR_IN addrClient;
	int len=sizeof(SOCKADDR);
	while(1){
		SOCKET sockConn=accept(sockSrv,(SOCKADDR*)&addrClient,&len);
		char sendBuf[50];
		sprintf(sendBuf,"Welcome %s to here",inet_ntoa(addrClient.sin_addr));
		send(sockConn,sendBuf,strlen(sendBuf)+1,0);
		char recvBuf[50];
		recv(sockConn,recvBuf,50,0);
		printf("%s\n",recvBuf);
		closesocket(sockConn);
	}
}