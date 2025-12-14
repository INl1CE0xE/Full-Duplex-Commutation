#pragma once

#include <iostream>
#include <WinSock2.h>
#include <Ws2tcpip.h>
//#include "client.h"
//#include "server.h"
#include <string>

#pragma comment(lib, "Ws2_32.lib")

#define CLIENT_SOCK 12
#define SERVER_SOCK 13

struct Init {
	SOCKET mySocket;
	Init(const int SOCK_TYPE) {
		WSADATA wsData;
		const char* myIp = "127.0.0.1";

		if (WSAStartup(MAKEWORD(2, 2), &wsData) != 0) {
			std::cout << "Error init WSA: " << WSAGetLastError();
			throw std::runtime_error("error");
		}
		else std::cout << "WSA INIT OK" << std::endl;

		mySocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

		if (mySocket == INVALID_SOCKET) {
			std::cout << "Error init socket: " << WSAGetLastError() << std::endl;

			if (closesocket(mySocket) == SOCKET_ERROR) {
				std::cout << "Error close socket: " << WSAGetLastError();
				throw std::runtime_error("error");
			}
			else {
				std::cout << "Socket has closed";
				WSACleanup();
			}
			throw std::runtime_error("error");
		}
		else std::cout << "HOST SOCKET OK" << std::endl;

		in_addr ip_to_num;
		if (inet_pton(AF_INET, myIp, &ip_to_num) != 1) {
			std::cout << "\nError IP reduction to spec. format" << std::endl;
		}

		SOCKADDR_IN socketInfo { AF_INET, htons(8080), ip_to_num };


		if (SOCK_TYPE == CLIENT_SOCK) {		// CLIENT
			if (connect(mySocket, (sockaddr*)&socketInfo, sizeof(socketInfo)) == SOCKET_ERROR) {
				std::cout << "\nError connection: " << WSAGetLastError();
			}
			else std::cout << "\nConnect Successful" << std::endl;
		}

		if (SOCK_TYPE == SERVER_SOCK) {		// SERVER
			if (bind(mySocket, (sockaddr*)&socketInfo, sizeof(socketInfo)) != 0) {
				std::cout << "\nError Bind socket" << std::endl;
			}
			else std::cout << "Bind sock is OK" << std::endl;

			if (listen(mySocket, SOMAXCONN) != 0) {
				std::cout << "\nError listen on socket" << std::endl;
			}
			else std::cout << "Listening in process" << std::endl;

			SOCKADDR_IN acceptClientInfo;
			ZeroMemory(&acceptClientInfo, sizeof(acceptClientInfo));
			int clientInfoSize = sizeof(acceptClientInfo);

			SOCKET acceptClientSock = accept(mySocket, (sockaddr*)&acceptClientInfo, &clientInfoSize);

			if (acceptClientSock == INVALID_SOCKET) {
				std::cout << "can't connect to a client. Error: " << WSAGetLastError();

			}
			else std::cout << "Connection to a client successful" << std::endl;
		}
	}
};