# 📨 minitalk

`minitalk` is a small client-server communication project developed as part of the 42 School curriculum. It uses UNIX signals (`SIGUSR1` and `SIGUSR2`) to transmit data from a client process to a server process — one bit at a time.

This implementation includes both the **mandatory** and **bonus** features in a single executable. It supports sending full messages, including **Unicode characters and emojis** 🎉.

## 🛠 Build

To compile the project, simply run:

```bash
make
```

This will generate the `server` and `client` executables.

## 🚀 How to Use

### 1. Start the server

```bash
./server
```

This will print the server's **PID** (process ID) to the terminal.

### 2. Send a message from the client

```bash
./client <server_pid> "Your message here 😄"
```

Replace `<server_pid>` with the actual PID printed by the server.

Example:

```bash
./client 12345 "Hello from the client! 🚀"
```

## 💡 Notes

- The server prints each received message to the terminal.
- Unicode and emojis are fully supported.
- No need to run separate bonus or mandatory binaries — everything is included in one.

## 🧠 What I Learned

- Bitwise operations and data encoding
- Signal handling using `sigaction`
- Synchronization between processes
- Sending Unicode characters bit by bit

---

> Developed with ❤️ during the 42 Cursus
