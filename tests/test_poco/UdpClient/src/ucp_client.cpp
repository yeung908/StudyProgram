// client program  
#include "Poco/Net/SocketAddress.h"  
#include "Poco/Net/StreamSocket.h"  
#include "Poco/Net/SocketStream.h"  
#include "Poco/StreamCopier.h"  
#include <iostream>  

int main(int argc, char** argv) {
	const char* ipaddr = "1743x43n74.imwork.net"; // the server address.  
	Poco::Net::SocketAddress sa(ipaddr, 28624); // the server port.  
	Poco::Net::StreamSocket socket(sa);
	Poco::Net::SocketStream str(socket);

	// Writes all bytes readable from str into std::cout, using an internal buffer.  
	Poco::StreamCopier::copyStream(str, std::cout);

	return 0;
}