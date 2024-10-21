# Networking

## Brief introduction
Networking has become one of the most important issues in modern computing. There are several issues that must be overcome:
* Lots of terminology / acronyms!
* Babel: Operating systems, hardware, applications, etc.
* Numerous standards, formats, protocols, etc. to communicate

## Network vocabulary
* LAN - Local Area Network
* VLAN - Virtal LAN
* WAN - Wide Area Network
* Bridge
* Router
* Repeater
* Gateway
* OSI Model
* IP - Internet Protocal
* TCP - Transmission Control Protocol
* UDP - User Datagram Protocol
* TCP / IP - Protocols used in the Internet and other networks
* IP address (v4 and v6)
* "Dotted quad format" (xxx.xxx.xxx.xxx)
* URL
* Subnet
* Netmask
* Datagram
* Packet
* Header
* MAC Address - Media Access Control address
* checksum
* DNS - Domain Name System
* NFS - Network File System
* FTP - File Transfer Protocol
* telnet
* SSH - Secure shell
* SNMP - Simple Network Managemenet Protocol
* SMTP - Simple Mail Transfer Protocol
* ICMP - Internet Control Message Protocol
* SMB - Samba file share
* DHCP - Dynamic host configuration protocol
* HTTP - hypertext transfer protocol
* Port
* Reliable communication
* Unreliable communication
* Token ring

## LAN Setups
Local area networks (*LANS*) are defined in terms of *protocol* and *topology* used for accessing the network.

The networking *protocol* is the set of rules established for users to exchange information.

The *topology* is the network architecture used to interconnect the networking equipment.

The most common network architectures for LANs are the star, ring, and bus.

Star:
```
x x x
 \|/
x-x-x
 /|\
x x x
```

Ring:
```
  x-x
 /   \
x     x
 \   /
  x-x
```

Bus:
```
-----------
| | | | | |
x x x x x x
```

### Token Rings
In this topolgy, a "token" is placed in the data channel and circulates around the ring, hence the name token-ring. If a user wants to transmit, the computer waits until it has control of the token. This technique is called *token passing* and is based on the IEEE 802.5 Token-Ring Network standard. A token-ring network is a deterministic network, meaning each station connected to the network is assured access for transmission of its messages at regular or fixed time intervals.

Token-Ring:
```
  a-b
 /   \
f     c
 \   /
  e-d
```

In this diagram, the token is passed around as a -> b -> c -> d -> e -> f -> a, each node can only transmit if it has the token.

### Bus
In a bus system, the computers share the media (coax cable) for data transmission. In this topology, a coax cable (called ThinNet) is looped through each networking device to facilitate data transfer.

## Interconnecting LANS
LANs may be connected :smile:

## OSI Model
An open system interconnect (OSI) reference model was developed by the International Organization for Standardization in 1984 to enable different types of networks to be linked together.
The model contains seven layers, below. These layers describe networking functions from the physical network interface to the software applications interfaces. The intent of the OSI
model is to provide a framework for networking that ensures compatibility in the network hardware and software and to accelerate the development of new networking technologies.

```
+----------------+
|7) Application  |
|----------------+
|6) Presentation |
|----------------|
|5) Session      |
|----------------|
|4) Transport    |
|----------------|
|3) Network      |
|----------------|
|2) Data link    |
|----------------|
|1) Physical     |
+----------------+
```

### Summary of the OSI Layers
| Layer | Function | Examples |
| ----- | -------  | -------- |
| 7. Application | Support for applications | HTTPS, FTP, SMTP |
| 6. Presentation | Protocol conversion, data translation | ASCII, JPG |
| 5. Session | Establishes, manages, and terminates sessions | NFS, SQL|
| 4. Transport | Ensures error free packets | TCP, UDP|
| 3. Network | Provides routing decisions | IP, IPX |
| 2. Datalink | Provides for the flow of data | MAC Addresses|
| 1. Physical | Signals and media | Network Interface Card, Twisted Pairs, Fiber |  

#### Physical Layer
Provides the electrical and mechanical connection to the network. Examples of technologies working in this layer are EIA / TIA related technologies, UTP, fiber, and NICs

#### Datalink Layer
Handles error recovery, flow control, and sequencing (which terminals are sending and which are receiving). It is consideredthe media access control layer and is where MAC addressing is defined. The Ethernet 802.3 standard is defined in this area, which is why the MAC address is sometimes called the Ethernet address.

#### Network Layer
Accepts outgoing messages and combines messages or segments into packets, adding a header that includes routing information. It acts as the network controller. Examples are IP and IPX.

#### Transport Layer
Is concerned with message integrity between source and destination. It also segments / reassembles packets and handles flow control. Examples are TCP and UDP.

#### Session Layer
Provides the control functions necessary to establish, manage, and terminate the connections as required to satisfy the user request. Examples are NFS and SQL.

#### Presentation Layer
Accepts and structures the messages for the application. It translates the message from one code to another if necessary. This layer is responsible for data compression and encryption. Examples are ASCII and JPG.

#### Application Layer
Interacts with application programs that incorporate a communication component such as your Internet Browser and Email. This layer is responsible for logging the message in, interpreting the request, and determining what information is needed to support the request. Examples are Internet Browsers, Messaging Services, Online Games, HTTP, FTP, SMTP.