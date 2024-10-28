# TCP / IP

## IEEE / ISO Standards

### IEEE 802.1 High level interface
* 802.1B LAN management
* 802.1D Local Bridging
* 802.1E System load protocol
* 802.1F Guideline for layer management standards
* 802.1G Remote MAC brides
* 802.1I MAC bridges (FDDI supplement)
    * FDDI - Fiber distributed data interface

### IEEE 802.2 Logical Link Control
* Type 1: Unacknowledged connectionless link service
* Type 2: Connection oriented link service
* Type 3: Acknowledged connectionless link service, used in realtime applications such as manufacturing control

### IEEE 802.3 CSMA / CD
### IEEE 802.4 Token Bus
### IEEE 802.5 Token Ring
### IEEE 802.6 Metropolitan Area Networks (MANs)
### IEEE 802.7 Broadband LANs technical advisory group (TAG)
### IEEE 802.8 Fiber Optic LANs TAG
### IEEE 802.9 Integrated voice and data LANs

### IEEE 802.10 Secure LANs
Current proposals include two methods to address the lack of security in the original specifications. These are:
* A secure data exchange sub layer SDE sitting between the LLC (logical link controller) and the MAC sub layer. There will be different SDEs for different systems.
* Secure interoperable LAN system architecture SILS. This will define system standards for secure LAN communications

### IEEE 802.11 Wireless LANs
The IEEE 802.11 Wireless LAN standard uses the 2.4GHz band and allows operation to 1 or 2 Mbps. The 802.11 standard also uses the 2.4GHz band, but allows operation at 11 Mbps. The latest IEEE 802.11a specification uses the 5.7GHz band instead and allows operation at 54 Mbps.

### IEEE 802.12 Fast LANs

## TCP / IP
TCP / IP (Transmission Control Protocol / Internet Protocol) is the set (suite) of protocols used for communicaitons between hosts in most local networks and and the Internet.

TCP and IP are two of the protocols in this suite.

The most important "traditional" TCP / IP services are:
* **File Transfer:** The FTP allows a user on any computer to get files from another computer, or to end files to another computer.
* **Remote Login:** The network terminal protocol (TELNET) allows a user to log in on any other computer on the network. You start a remote session by specifying a computer to connect to. From that time until you finish the session, anything you type is sent to the other computer.
* **Computer Mail:** Allows messages to be sent to users on other computers. Originally, people tended to use only one or two specific computers.

## Client / Server
The preceding services should be present in any implementation of TCP / IP, except that micro-oriented implementations may not support computer mail. These traditional applications still play a very important role in TCP / IP based networks.
* A *server* is a system that provides a specific service for the rest of the network.
* A *client* is another system that uses that service.
* (Note that the server and client need not be on different computers. They could be different programs running on the same computer, like Minecraft :smile:.)

### Servers
Here are the kinds of servers typically present in a modern computer setup. Not that these computer services can all be provided within the framework of TCP / IP
* Network file systems
* Remote printing
* Remote execution
* Name servers
* Terminal servers
* Network-oriented window system

Some of the protocols described above were designed by Berkeley, Sun, or other organizations. This they are not officially part of the Internet Protocol suite. However, they are implemented using TCP / IP, just as normal TCP / IP applications

### TCP / IP Layers
| Layer | Purpose of the Layer |
|-------|--------|
| Application Layer | Defines the applications used to process requests and what ports and sockets are used. |
| Transport Layer | Defines the type of connection established between hosts and how acknowledgements are sent |
| Internet Layer | Defines the protocols used for addressing |
| Network Interface | The physical way that a client is connected to the network |

#### Relationship between OSI and TCP / IP layers
| OSI Model | TCP / IP Model |
| --------- | --------- |
|Applications, Presentation, Session | Application|
| Transport | Transport |
| Network | Internet|
| Datalink, Physical | Network Interface |

#### The Application Layer
The top level of the TCP / IP stack is the application layer. This layer is used to process requests form hosts and to make sure a connection is made to an appropriate port. A *port* is basically an address used to direct data to the proper destination application. There are 65536 possible TCP ports.

#### The Transport Layer
The transport layer protocols in TCP / IP are very important in establishing a network connection, managing the delivery of data between a source and destination host, and terminating the data connection.

There are two transport protocols within the TCP / IP transport layer, TCP, and UDP.

* TCP, the Transport Control Protocol is a *connection-oriented* protocol, which means it establishes the network connection, manages the data transfer, and terminates the connection
* UDP, the User Datagram Protocol, is a *connectionless* protocol. This means UDP packets are transported over the network without a connection being established and without and acknowledgedment that the data packest arrived at the destination.

#### The Internet Layer
The TCP / IP Internet layer defines the protocols used for addressing and routing the data packets. Protocols that are part of the TCP / IP Internet layer include IP, ARP, ICMP, and IGMP
* IP defines the addressing used to identify the source and destination addresses of data packets delivered over an IP network.
* ARP, the Address Resolution Protocol, is used to resolve an IP address to a hardware address for final delivery of data packets to the destination.
* The Internet Control Message Protocol (ICMP) is used to control the flow of data in the network, for reporting errors, and for performing diagnostics.
* IGMP is the Internet Group Message Protocol. It is used when one host needs to send data to many destination hosts. This is called *multicasting*.
The address used to send a multicast data packet are called *multicast addresses* and are reserved addresses not assigned to hosts in a network.

#### The Network interface layer
The network interface layer defines how the host connects to the network.

In the network interface layer, every data packet must have a destination and a source MAC address.

The MAC or hardware address is found on the host's network interface card or connection, and it is 12 hex characters in length.

For example, the network interface could have MAC address of 00-10-B4-21-99-3C

## IPV4 addressing
IP addressing provides a standardized format for assigning a unique routable address for every host in a TCP/ IP network.

IPv4 is the IP addressing version currently being used on the Internet and for TCP / IP data traffic. 5 address classes
* Classes ABC are primary addresses for internet traffic
* D is for multicastin
* E is experimental and not used on the internet

| Class | Ip Range|
| -----| ----- |
| A | 0.0.0.0 - 127.255.255.255 |
| B | 128.0.0.0 - 191.255.255.255 |
| C | 192.0.0.0 - 223.255.255.255 |
| D | 224.0.0.0 - 239.255.255.255 |
| E | 240.0.0.0 - 255.255.255.255 |

### Why are IP addresses needed?
Networked devices need a routable network address to deliver data packets outside the LAN. The IP address is similar ot a telephone number. The network portion of the IP address is similar
to the telephone's area code.