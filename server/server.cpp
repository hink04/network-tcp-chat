#include <iostream>
#include <winsock2.h>
using namespace std;

int main()
{   WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2,2), &wsaData);
    if(result==0){
        cout<< "Winsock success!" << "\n";
    }
    else{
        cout<< "Winsock failed" << "\n";
    }
  

    SOCKET serverSocket; //SOCKET은 운영체제가 만든 소켓을 가리키는 핸들이다.(구조체X)
    serverSocket = socket(
        AF_INET,
        SOCK_STREAM,
        0
    );

    if(serverSocket==INVALID_SOCKET) cout<< "Socket failed" << "\n";
    else cout<< "Socket created" << "\n";

    WSACleanup();

    return 0;
}