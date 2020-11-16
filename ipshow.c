/*
 * C Program to Get IP Address
 */
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <unistd.h>
#include <arpa/inet.h>


struct ifreq getIP(char* netInterfaceName){
    int n;
    struct ifreq ifr;
    char array[] = "eth0";
 
    n = socket(AF_INET, SOCK_DGRAM, 0);
    //Type of address to retrieve - IPv4 IP address
    ifr.ifr_addr.sa_family = AF_INET;
    //Copy the interface name in the ifreq structure
    strncpy(ifr.ifr_name , array , IFNAMSIZ - 1);
    ioctl(n, SIOCGIFADDR, &ifr);
    close(n);

    return ifr;
}
 
int main()
{
    struct ifreq ifr;
    char name[] = "eth0";
    //display result

    ifr = getIP(name);

    printf("IP Address is %s - %s\n" , name, inet_ntoa(( (struct sockaddr_in *)&ifr.ifr_addr )->sin_addr) );
    return 0;
}
