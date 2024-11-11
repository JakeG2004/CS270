# Networking Transport

## Brief Review
Typical tasks to be performed
* Source system must either activate the direct data path or inform the communication network of the identity of the desired destination system
* The source system must ascertain that the destination system is prepared to receive data
* The file transfer application on the source system must ascertain that the file management program on the desination system is prepared to accept and sroe the file for this particular user.
* If the file formats or data representation used on the two system are incompatible, one or the other must yield, lest the connection drop.

The key elements of a protocol are as follows
* Syntax (data format, signal levels)
* Semantics (control information for coordination and error handling)
* Timing (speed matching and sequencing)

## Transport Layer
Manages connection, data transfer, and termination between 2+ computers

2 Most important protocols are
* TCP - *Transport Control Protocol*. More stable, reliable, slower.
* UDP - *User Datagram Protocol*. Shotgun approach, no connection, no acknowledgement, faster.

### TCP Header
20 Octets (8 bits) = 160 total bits
* Source port
* Destination Port
* Sequence Number
* Acknowledgement Number
* Header len
* Reserved
* Flags
* Window
* Checksum
* Urgnet Pointer
* Options + Padding

### UDP Header
8 Octets (8 bytes) = 64 bits
* Source Port
* Destination Port
* Segment Length
* Checksum

## IP and IPV6
IP has been the keystone of TCP / IP for decades

* IPv6 has less fields but much larger source and destination address fields.
* IPv6 has a total of 40 octets, as opposed to IPv4's 20 octets

## TCP / IP Applications
* SMTP (simple mail transfer protocol)
* FTP (File transfer protocol)
* TELNET (predecessor to SSH)

