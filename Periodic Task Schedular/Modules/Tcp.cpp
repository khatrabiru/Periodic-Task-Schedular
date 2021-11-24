//
//  Tcp.cpp
//  Periodic Task Schedular
//
//  Created by Bir Bahadur Khatri on 24/11/2021.
//

#include "Tcp.hpp"
#include <stdio.h>
#include <string>

#include <algorithm>
#include <chrono>
#include <iostream>
#include<vector>

#ifdef _WIN32
#  include "winsock.h"
#else
#  include <netdb.h>
#  include <arpa/inet.h>
#endif

using namespace std;
using namespace std::chrono;

long long getTcpConnectionTime(char *hostName, int port) {
    int sd;
    struct sockaddr_in server;
    struct hostent *hp;

    sd = socket(AF_INET,SOCK_STREAM,0);
    server.sin_family = AF_INET;

    hp = gethostbyname(hostName);
    
    // Get starting timepoint
    auto start = high_resolution_clock::now();

    bcopy(hp->h_addr, &(server.sin_addr.s_addr), hp->h_length);
    server.sin_port = htons(port);

    connect(sd, (const sockaddr *)&server, sizeof(server));
    
    // Get ending timepoint
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count();
}

