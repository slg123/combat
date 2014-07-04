#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main( int argc, char *argv[] ) 
{
    struct addrinfo hints, *res, *p;
    int status;
    char ipstr[INET6_ADDRSTRLEN];

    if ( argc != 2 ) {
        fprintf( stderr, "usage: showip hostname\n" ); 
        return 1;
    }

    memset( &hints, 0, sizeof hints ); 
    hints.ai_family = AF_UNSPEC;         // AF_INET or AF_INET6 to force version
    hints.ai_socktype = SOCK_STREAM;

    if (( status = getaddrinfo( argv[1], NULL, &hints, &res )) != 0 ) {
        fprintf( stderr, "getaddrinfo: %s\n", gai_strerror( status ));
        return 2;
    }

    printf( "IP addresses for %s: \n\n", argv[1] ); 

    for ( p = res; p != NULL; p = p->ai_next ) {
        void *addr;
        char *ipver;
        int *fl, *fam, *typ, *proto;

        if ( p->ai_family == AF_INET ) {
            struct sockaddr_in *ipv4 = ( struct sockaddr_in *)p->ai_addr;
            struct addrinfo *ipv4_addrinfo = ( struct addrinfo *)p->ai_next;
            addr  = &(ipv4->sin_addr); 
            fl    = &(ipv4_addrinfo->ai_flags);
            fam   = &(ipv4_addrinfo->ai_family);
            typ   = &(ipv4_addrinfo->ai_socktype);
            proto = &(ipv4_addrinfo->ai_protocol); 
            ipver = "IPv4"; 
        } else { // IPv6
            struct sockaddr_in6 *ipv6 = ( struct sockaddr_in6 *)p->ai_addr;
            struct addrinfo *ipv6_addrinfo = ( struct addrinfo *)p->ai_next;
            addr = &(ipv6->sin6_addr); 
            fl    = &(ipv6_addrinfo->ai_flags);
            fam   = &(ipv6_addrinfo->ai_family);
            typ   = &(ipv6_addrinfo->ai_socktype);
            proto = &(ipv6_addrinfo->ai_protocol); 
            ipver = "IPv6"; 
        }

        inet_ntop( p->ai_family, addr, ipstr, sizeof ipstr ); 
        printf( " %s: %s -> %d %d %d %d\n", ipver, ipstr, fl, fam, typ, proto ); 
    }
    freeaddrinfo( res );

    return 0;
}
