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