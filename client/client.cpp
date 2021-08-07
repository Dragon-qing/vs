#include<iostream>
#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")

//ȫ�ֱ���
SOCKET sockSer, sockCli;
SOCKADDR_IN addrSer, addrCli;//address
int naddr = sizeof(SOCKADDR_IN);
const int BUF_SIZE = 2048;//��������С
char sendBuf[BUF_SIZE];
char inputBuf[BUF_SIZE];
char recvBuf[BUF_SIZE];

using namespace std;
int main()
{
	//����socket��
	WSADATA wsadata;
	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0) {
		//���������Ϣ
		cout << "����socket��ʧ��" << endl;
		system("pause");
		return 0;
	}
	//����socket
	sockCli = socket(AF_INET, SOCK_STREAM, 0);
	//��ʼ����ַ��
	addrCli.sin_addr.s_addr = inet_addr("127.0.0.1");
	addrCli.sin_family = AF_INET;
	addrCli.sin_port = htons(9999);

	//��ʼ����������ַ��
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
