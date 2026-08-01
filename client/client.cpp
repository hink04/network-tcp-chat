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
  

    SOCKET clientSocket; //SOCKET은 운영체제가 만든 소켓을 가리키는 핸들이다.(구조체X)
    clientSocket = socket(
        AF_INET,
        SOCK_STREAM,
        0
    );

    if(clientSocket==INVALID_SOCKET) cout<< "Socket failed" << "\n";
    else cout<< "Socket created" << "\n";

    sockaddr_in serverAddr{};

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port=htons(8080);
    serverAddr.sin_addr.s_addr=inet_addr("127.0.0.1");//서버는 이다음 bind()이고 클라는 connect이기때문에 보낼주소를 입력함

    //서버와 클라 연결(connect)
    if(connect(clientSocket,(sockaddr*)&serverAddr,sizeof(serverAddr))==SOCKET_ERROR){
        cout<<"connect failed\n";
    }
    else cout<<"connect server\n";

    closesocket(clientSocket);
    WSACleanup();

    return 0;
}