#include<iostream>
#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")

//全局变量
SOCKET sockSer, sockCli;
SOCKADDR_IN addrSer, addrCli;//address
int naddr = sizeof(SOCKADDR_IN);
const int BUF_SIZE = 2048;//缓冲区大小
char sendBuf[BUF_SIZE];
char inputBuf[BUF_SIZE];
char recvBuf[BUF_SIZE];

using namespace std;
int main()
{
	//加载socket库
	WSADATA wsadata;
	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0) {
		//输出出错信息
		cout << "载入socket库失败" << endl;
		system("pause");
		return 0;
	}
	//创建socket
	sockCli = socket(AF_INET, SOCK_STREAM, 0);
	//初始化地址包
	addrCli.sin_addr.s_addr = inet_addr("127.0.0.1");
	addrCli.sin_family = AF_INET;
	addrCli.sin_port = htons(9999);

	//初始化服务器地址包
	addrSer.sin_addr.s_addr = inet_addr("192.168.43.195");
	addrSer.sin_family = AF_INET;
	addrSer.sin_port = htons(9999);

	while (1) {
		if (connect(sockCli, (SOCKADDR*)&addrSer, sizeof(addrSer)) != SOCKET_ERROR) {
			recv(sockCli, recvBuf, sizeof(recvBuf), 0);
			cout << recvBuf << endl;
		}
	}
	closesocket(sockSer);
	closesocket(sockCli);
	WSACleanup();
	return 0;
}
