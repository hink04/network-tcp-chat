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
    
    if(bind(serverSocket,(sockaddr*)&serverAddr,sizeof(serverAddr))==SOCKET_ERROR){//서버의 주소부여(bind)
        cout<< "bind failed\n"; 
    }
    else cout<< "bind conected\n";

    if(listen(serverSocket,SOMAXCONN)==SOCKET_ERROR){//서버연결요청 대기상태(listen)
        cout<< "listen failed\n";
    }
    else cout<< "listen created\n";

    sockaddr_in clientAddr{};//서버에 대기하는 클라이언트 구조체 설정
    int clientSize=sizeof(clientAddr);

    SOCKET clientSocket = accept(serverSocket,(sockaddr*)&clientAddr,&clientSize);//서버 연결(accept) 

    if(clientSocket==INVALID_SOCKET){
        cout<< "accept failed\n";
    }
    else cout<< "accept conneted\n";

    while(1){
    char buffer[1025];//클라이언트에게 받은 메세지 저장

    int received = recv(clientSocket,buffer,sizeof(buffer)-1,0);//메세지 받기(반환값이 바이트크기)

    if(received>0){//tcp는 메세지가 아니라 바이트로 받는것을 기억하자.
        buffer[received]='\0'; //받은 문자열 종료 표시
        cout<<"received message : "<<buffer<<"\n";

        int sent=send(clientSocket,buffer,received,0);//메세지 보내기
        if(sent==SOCKET_ERROR){
            cout<<"send failed\n";
        }
        else cout<<"send successed\n";
    }
    else if(received==0){
        cout<<"client disconnected\n";
        break;
    }//received가 0이면 
    else {
        cout<<"recv failed\n"<<WSAGetLastError()<<'\n';
        break;
    }
    }

    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();

    return 0;
}