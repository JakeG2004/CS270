# Sockets
The concept of sockets and socket programming was developed in the 80s in teh UNIX environment as the Berkely Sockets Interface. A socket enables communication between a client and server process. Either connection oriented or connectionless

* Berkeley Sockets Interface is standard for networking apps
* Windows Sockets (WinSock) based on Berkeley Spec
* The sockets API provides generic access to interprocess communications services

* Recall that each TCP and UDP header includes source port and destination port fields
* These port values identify the respective users of the two TCP entities
* Also each IPv4 and v6 header includes src and dst address fields. These IP addr's identify the respective host systems. The concatenation of port value and IP addr forms a socket.

* Socket used to define an API, which is a generic communication interface for programs that use TCP or UDP
* In practice, when used as an API, a socket is identified by the triple (protocol, local addr, local process)

## 3 types of sockets
1) Stream sockets - make use of TCP, which provides connection-oriented reliable data transfer. Therefore, with stream sockets, all block are guaranteed for delivery and arrive in order
2) Datagram sockets - make use of UDP, which does not provide connection-oriented features. Therefore, delivery not guaranteed and order not preserved.
3) Raw sockets - provide direct access to lower layer protocols, such as IP

## Socket interface calls
To use sockets is a 3 step process
1) Socket setup
2) Socket connection
3) Socket communication

The typical TC client communication involves 4 steps
1) Create TCP socket using `socket()`
    * 3 parameters:
        1) protocol family is always **PF_INET**, for TCP / IP
        2) type specifies stream / datagram socket
        3) protocol specifies TCP or UDP
    * must have an addr to listen to. `bind()` binds a socket to an addr. Has structure
        ```
        struct sockaddr_in
        {
            short int sin_family;           // Address family (TCP / IP)
            unsigned short int sin_port;    // Port Number
            struct in_addr sin_addr;        // Internet addr
            unsigned char sin_zero[8];      // Same size as struct sockaddr
        };
        ```

2) Establish a connection to the server using `connect()`
    * For a steam socket, once the socket is created, a connection must be set up to a remote socket. One side functions as a client, the other as a server. Server side of a connection setup requires 2 steps:
        1) A server app issues a `listen()`, indicating that the given socket is ready to accept incoming connections. The parameter backlog is the number of connections allowed on the incoming queue. Each incoming connection is placed in this queue until a matching `accept()` is issued by the server side.
        2) the `accept()` call is used to remove one request form the queue. If the queue is empty, the `accept()` blocks the process until a connection request arrives. If there is a waiting call, then `accept()` returns a new file descriptor for the connection. This creates a new socket, which has the IP addr and port number of the remote party, the IP addr of this system, and a new port num.
    * If successful, `connect()` returns a 0 and fills the file descriptor parameter to include IP addr and port num
    * If unsuccessful, `connect()` returns -1

3) Communicate using `send()` and `recv()`
    * For stream communications, the functiosn `send()` and `recv()` are used to send or receive data over the connection
    * In the `send()` call, the `*msg` parameter points to the block of data to be sent and hte len paramater specifies the num of bytes to send.
    * The flags parameter contains control flags
    * The `send()` call retursn the num of bytes sent
    * `recv()` has `*buf` pointing to the buffer for storing the incoming data

4) Close the connection with `close()`
    * At any time, either side can close the connection with the `close()` call, which prevents further sends and receives. `shutdown()` allows the caller to terminate sending or receiving or both.

## Datagram Communication
For datagram communication, the functions `sendto()` and `recvfrom()` are used.
* `sendto()` includes all of the parameters of `send()` plus a specification of dest addr. Same thing applies to `recvfrom()`