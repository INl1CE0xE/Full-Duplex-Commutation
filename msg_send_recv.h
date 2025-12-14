#pragma once

#include <thread>
#include <vector>
#include "init.h"


struct MSG_INIT {
	static const int BUFF_SIZE{ 1024 };

	std::vector <char> recvBuff, sendBuff;
	short packet_size = 0;

	MSG_INIT() : recvBuff(BUFF_SIZE), sendBuff(BUFF_SIZE) {}

	void send_msg(SOCKET mySocket) {
		std::cout << "Enter Message: ";
		fgets(sendBuff.data(), static_cast<int>(sendBuff.size()), stdin);
		
		if (send(mySocket, sendBuff.data(), static_cast<int>(sendBuff.size()), 0) == SOCKET_ERROR) {
			std::cout << "\nError send message" << std::endl;
		}
	}

	void recv_msg(SOCKET mySocket) {
		if (packet_size = static_cast<short>(recv(mySocket, recvBuff.data(), static_cast<int>(recvBuff.size()), 0)) > 0) {
			std::cout << "Other: " << recvBuff.data() << std::endl;
		}
		
	}

};