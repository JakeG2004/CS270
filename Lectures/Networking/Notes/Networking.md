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