# About the ft_irc project

You can find our ft_irc git repo [here](https://github.com/cseriildi/ft_irc). We collaborated on this with [Daniel](https://github.com/Csicsi).

## Summary
This project consists of building a simplified IRC *(Internet Relay Chat)* server in C++ using low-level socket programming. The server handles multiple simultaneous client connections and supports a subset of the IRC protocol, including some basic commands. It manages user sessions, channel memberships, and real-time message broadcasting. Networking is implemented using POSIX socket functions and poll for handling multiple clients efficiently.

- **Allowed external functions**: `socket`, `close`, `setsockopt`, `getsockname`, `getprotobyname`, `gethostbyname`, `getaddrinfo`, `freeaddrinfo`, `bind`, `connect`, `listen`, `accept`, `htons`, `htonl`, `ntohs`, `ntohl`, `inet_addr`, `inet_ntoa`, `send`, `recv`, `signal`, `sigaction`, `lseek`, `fstat`, `fcntl`, `poll` *(or equivalent)*

## Useful things
- [**Guide to Network Programming**](https://beej.us/guide/bgnet/pdf/bgnet_a4_c_1.pdf)
- [Internet Relay Chat Protocol](https://www.rfc-editor.org/rfc/rfc1459)
- [Internet Relay Chat: Architecture](https://www.rfc-editor.org/rfc/rfc2810)
- [Internet Relay Chat: Channel Management](https://www.rfc-editor.org/rfc/rfc2811)
- [**Internet Relay Chat: Client Protocol**](https://www.rfc-editor.org/rfc/rfc2812.html)
- [Internet Relay Chat: Server Protocol](https://www.rfc-editor.org/rfc/rfc2813)

## Mandatory Part
Implement:
- `NICK`: to set nickname
- `USER`: to set username
- `PASS`: to authenticate with password
- `JOIN`: to join a channel
- `PRIVMSG`: to send messages
- `KICK`: to kick someone from a channel
- `INVITE`: to invite someone to a channel
- `TOPIC`: to change or view a channel's topic
- `MODE`: to set or remove the following channel modes:
  - `i`: invite-only
  - `t`: topic changes only by operators
  - `k`: channel password protection
  - `o`: operator privilege of a user
  - `l`: limit number of users in channel

## Bonus Part
- Handle file transfer
- Add a bot

## Usage
```bash
make run ARGS="<port> <password>"
```
Example:
```bash
make run ARGS="6667 pass"
```
Use debug mode to see the raw messages sent between the server and client:
```bash
make debug ARGS="6667 pass"
```

Test with any IRC client, for example:
```bash
irssi -c localhost -p 6667 -w pass
```
```bash
nc -C localhost 6667
```
*Note: netcat is very manual, irssi retrieves the information required for authentication from the system and has separate windows for channels and private messages so you can read them separately and switch between them seamlessly. Irssi might modify your commands based on which window you are focused on, but you can send direct messages to the server with `/quote <command>`.*

## Bonus Usage

**File transfer using irssi**

Setup:
```
/load dcc
/set dcc_download_path <path>
```
Usage:

- Client 1:

```
/dcc send <nick> <file_path>
```
- Client 2:
```
/dcc list (optional)
/dcc get <nick> <filename>
```

**Bot usage**

After starting the server
```Bash
make run -C Bot ARGS="<port> <pass>"
```

*Note: It will create/join a channel called Trivia where it will send a funfact to any given message.*
