#include "init.h"
#include "msg_send_recv.h"
#include <thread>

void msgSendHandle(MSG_INIT msg_cmd, SOCKET sock) {
	while (true) {
		msg_cmd.send_msg(sock);
	}
}
void msgRecvHandle(MSG_INIT msg_cmd, SOCKET sock) {
	while (true) {
		msg_cmd.recv_msg(sock);
	}
}

int main(int argc, char* argv[]) {
	int SockType{};
	
	if (argc > 1 && strcmp(argv[1], "-s") == 0) {
		SockType = SERVER_SOCK;
	}
	else if (argc > 1 && strcmp(argv[1], "-help") == 0) {
		std::cout << "-s : server";
		std::cout << "\nEnter for client";
	}
	else {
		SockType = CLIENT_SOCK;
	}
	Init init(SockType);
	MSG_INIT msg_cmd;

	std::thread t1(msgSendHandle, msg_cmd, init.mySocket);
	std::thread t2(msgRecvHandle, msg_cmd, init.mySocket);
	
	t1.join();
	t2.join();

}