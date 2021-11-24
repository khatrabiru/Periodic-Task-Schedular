//
//  Dns.cpp
//  Periodic Task Schedular
//
//  Created by Bir Bahadur Khatri on 24/11/2021.
//

#include <stdio.h>
#include <string>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
#include "Dns.hpp"

#ifdef _WIN32
#  include "winsock.h"
#else
#  include <netdb.h>
#  include <arpa/inet.h>
#endif

using namespace std;
using namespace std::chrono;

long long getDnsResolveTime(char *hostName) {
    struct hostent *hp;
    
    // Get starting timepoint
    auto start = high_resolution_clock::now();

    hp = gethostbyname(hostName);
    
    // Get ending timepoint
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count();
}

