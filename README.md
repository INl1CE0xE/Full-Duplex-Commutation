# Full-Duplex-Commutation

# TCP Client/Server (WIP)

## Description
Multithreaded **TCP chat** in C++ with Winsock2. Supports **client** and **server** modes.

**⚠️ STATUS: DOES NOT WORK**  
Code contains critical bugs, under development.

## Usage
```bash
# Server mode
server.exe -s

# Client mode (default)
server.exe
```

## Project Files
```
.
├── main.cpp          # Entry point, send/recv threads
├── init.h            # Socket init (WSA, connect/bind/listen/accept)
└── msg_send_recv.h   # Message send/recv (fgets/send/recv)
```

## Implemented Features
- [x] WSAStartup 2.2
- [x] TCP socket creation (AF_INET, port 8080, 127.0.0.1)
- [x] **Client**: connect()
- [x] **Server**: bind() + listen() + accept()
- [x] Message buffers (1024 bytes)
- [x] Multithreading: send_thread + recv_thread

## 🚨 Critical Bugs (TODO)
- ❌ `recv_msg`: `=` instead of `==` (assignment vs comparison)
- ❌ **Server**: `accept()` blocks constructor
- ❌ **Single `MSG_INIT`** object in both threads (race condition)
- ❌ No destructor (socket leaks)
- ❌ No graceful shutdown (Ctrl+C)

## Build
```bash
g++ -std=c++17 main.cpp -lws2_32 -o server.exe -pthread
# Visual Studio: add ws2_32.lib
```

## Planned Improvements
- [ ] Fix MSG_INIT race condition
- [ ] Move accept() out of constructor
- [ ] Add mutex for thread safety
- [ ] Ctrl+C handling
- [ ] Error logging

**Status: 40%**  
**🚧 DO NOT USE 🚧** — work in progress!

#Русский
## Описание
Многопоточный **TCP чат** на C++ с Winsock2. Поддерживает **клиент** и **сервер** режимы.

**⚠️ СТАТУС: НЕ РАБОТАЕТ**  
Код содержит критические ошибки, находится в разработке.

## Запуск
```bash
# Сервер
server.exe -s

# Клиент (по умолчанию)
client.exe
```

## Файлы проекта
```
.
├── main.cpp          # Точка входа, потоки send/recv
├── init.h            # Инициализация сокетов (WSA, connect/bind/listen/accept)
└── msg_send_recv.h   # Отправка/получение сообщений (fgets/send/recv)
```

## Реализованный функционал
- [x] WSAStartup 2.2
- [x] Создание TCP сокета (AF_INET, 8080 порт, 127.0.0.1)
- [x] **Клиент**: connect()
- [x] **Сервер**: bind() + listen() + accept()
- [x] Буферы сообщений (1024 байт)
- [x] Многопоточность: send_thread + recv_thread

## 🚨 Критические ошибки (TODO)
- ❌ `recv_msg`: `=` вместо `==` (присваивание вместо сравнения)
- ❌ **Сервер**: `accept()` блокирует конструктор
- ❌ **Один объект `MSG_INIT`** в двух потоках (race condition)
- ❌ Нет деструктора (утечки сокетов)
- ❌ Нет graceful shutdown (Ctrl+C)

## Сборка
```bash
g++ -std=c++17 main.cpp -lws2_32 -o server.exe -pthread
# Visual Studio: добавить ws2_32.lib
```

## Планируемые улучшения
- [ ] Исправить race condition в MSG_INIT
- [ ] Вынести accept() из конструктора
- [ ] Добавить mutex для потокобезопасности
- [ ] Обработка Ctrl+C
- [ ] Логирование ошибок

**Статус: 40%**  
**🚧 НЕ ИСПОЛЬЗОВАТЬ 🚧** — дорабатывается!
