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

    sockaddr_in serverAddr{};//구조체 만들고 0으로 초기화

    serverAddr.sin_family = AF_INET;//ipv4설정
    serverAddr.sin_port=htons(8080);//포트 설정
    serverAddr.sin_addr.s_addr=INADDR_ANY;//서버의 모든ip에서 연결허용
    
    if(bind(serverSocket,(sockaddr*)&serverAddr,sizeof(serverAddr))){
        cout<< "bind conected\n"; 
    }
    else cout<< "bind failed\n ";

    closesocket(serverSocket);
    WSACleanup();

    return 0;
}