# MiniTalk - 42 Project

This repository contains my implementation of the **MiniTalk** project from 42 school, including both the mandatory part and the bonus. The project consists of a small communication program using UNIX signals to send messages between a client and a server.

## 🚀 Project Overview

MiniTalk is a simple client-server communication program where:

- The **server** waits for messages sent via UNIX signals.
- The **client** sends a message to the server using signals, encoding characters bit by bit.
- Both mandatory and bonus parts are implemented in this repository.

## 🗂️ Project Structure

MINITALK/
├── src/ # Source files for client and server
├── inc/ # Header files
├── Makefile # Build rules for both mandatory and bonus


## ⚙️ How to Compile and Run

To compile both the mandatory and bonus parts, simply run:

```bash
make
```

This will generate the executables:

    server

    client

📝 Usage

    Start the server in one terminal:

./server

It will display its PID.

    In another terminal, send a message with the client:

./client <server_pid> "Your message here"

The message will be transmitted character by character via signals.

🎯 Features

    Communication via SIGUSR1 and SIGUSR2 signals.

    Bitwise encoding of characters.

    Graceful handling of signal interruptions.

    Bonus features included in the same build system.

🛠️ Skills Demonstrated

    Signal handling in UNIX/Linux.

    Inter-process communication (IPC).

    Bitwise operations and character encoding.

    Robust error handling and input validation.

    Use of Makefile to manage project builds.

📫 Contact

If you want to discuss the project or need help, feel free to contact me:

    Email: jcarvalho.swe@gmail.com

    LinkedIn: linkedin.com/in/devjorginho
