# Network TCP Chat

> Echo Server
>
> C++과 Winsock2를 이용하여 구현한 TCP Echo Server / Client 프로젝트입니다.

---

# 프로젝트 소개

이 프로젝트는 TCP 소켓 프로그래밍의 기본 동작 원리를 학습하기 위해 제작한 프로젝트입니다.

서버는 클라이언트의 연결을 수락한 후 메시지를 수신하고, 동일한 메시지를 다시 클라이언트에게 전송하는 Echo Server를 구현하였습니다.

또한 클라이언트와 서버가 반복적으로 메시지를 주고받을 수 있도록 구현하였으며, TCP 통신의 기본적인 흐름을 직접 구현하며 학습하는 것을 목표로 하였습니다.

---

# 개발 환경

- Language : C++
- OS : Windows 11
- IDE : Visual Studio Code
- Compiler : MinGW-w64 (g++)
- Library : Winsock2

---

# 프로젝트 구조


network-tcp-chat/
│
├── client/
│   └── client.cpp
│
├── server/
│   └── server.cpp
│
└── README.md

---

# 구현 기능

- Winsock 초기화 및 종료
- TCP Socket 생성
- 서버 Bind
- Listen 상태 진입
- Client 연결 수락(Accept)
- Client Connect
- 메시지 송신(Send)
- 메시지 수신(Recv)
- Echo 기능 구현
- 반복적인 메시지 송수신
- 빈 메시지 입력 방지
- 클라이언트 연결 종료 처리

---

# 동작 과정

```
Client
   │
   │ connect()
   ▼
Server
   │
bind()
   │
listen()
   │
accept()
   │
recv()
   │
send()
   │
Client가 동일한 메시지 수신
```
---

# 실행 예시

### Client


input data : Hello

server : Hello

### Server

received message : Hello

send successed

---

# 프로젝트를 통해 학습한 내용

- TCP와 UDP의 차이
- Winsock2 사용 방법
- TCP Socket 생성 과정
- bind(), listen(), accept()의 역할
- connect()를 통한 서버 연결
- recv()와 send()를 이용한 데이터 송수신
- Listening Socket과 Connected Socket의 차이
- TCP는 Message가 아닌 Byte Stream으로 동작한다는 개념
- recv() 반환값의 의미

---

# 개선 예정

- 멀티 클라이언트 지원
- Thread를 이용한 동시 채팅
- 사용자 닉네임 기능
- Broadcast 기능
- 파일 전송 기능
- 예외 처리 및 로그 출력 개선

---

# 프로젝트 목적

TCP 소켓 프로그래밍의 기본 구조를 직접 구현하며 서버와 클라이언트 간의 연결 과정과 데이터 송수신 과정을 이해하는 것을 목표로 하였습니다.

향후 멀티스레드 기반의 채팅 서버 및 다중 클라이언트 서버 구현의 기초 프로젝트로 활용할 예정입니다.