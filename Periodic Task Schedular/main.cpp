//
//  main.cpp
//  Periodic Task Schedular
//
//  Created by Bir Bahadur Khatri on 24/11/2021.
//

#include <stdio.h>
#include <iostream>
#include <unistd.h>

#include "Databases/Common.hpp"
#include "Databases/DNS.hpp"
#include "Databases/TCP.hpp"
#include "Databases/MEMORY.hpp"

#include "Modules/Dns.hpp"
#include "Modules/Tcp.hpp"
#include "Modules/Memory.hpp"

void printMonitoringData() {
    printf("\n\n***********************************************************************************************\n");
    std::cout << "Table               Min(microseconds)       Max(microseconds)    Agerage(microseconds)\n";
    float Min = getValue("DNS", "DnsResolveTime", "MIN");
    float Max = getValue("DNS", "DnsResolveTime", "MAX");
    float Average = getValue("DNS", "DnsResolveTime", "AVG");
    printf("DnsResolveTime %20f %20f %20f\n", Min, Max, Average);
    printf("\n\n***********************************************************************************************\n");
    
    std::cout << "Table               Min(microseconds)       Max(microseconds)    Agerage(microseconds)\n";
    Min = getValue("TCP", "TcpConnectionTime", "MIN");
    Max = getValue("TCP", "TcpConnectionTime", "MAX");
    Average = getValue("TCP", "TcpConnectionTime", "AVG");
    printf("TcpConnectionTime %20f %20f %20f\n", Min, Max, Average);
    printf("\n\n***********************************************************************************************\n");
    
    std::cout << "Table               Min(bytes)              Max(bytes)           Agerage(bytes)\n";
    Min = getValue("MEMORY", "MemoryUsage", "MIN");
    Max = getValue("MEMORY", "MemoryUsage", "MAX");
    Average = getValue("MEMORY", "MemoryUsage", "AVG");
    printf("MemoryUsage  %20f %20f %20f\n", Min, Max, Average);
    printf("\n\n***********************************************************************************************\n");
    
}

int main() {
    // we can customize the execution frequency for each task separately.
    int networkProbeTaskFrequency = 3; // runs in every 3 seconds
    int systemProbeTaskFrequency = 6; // runs in every 6 seconds
    
    int cur = 0;
    
    // initialize Database
    initialize();
    
    while( true ) {
        if( cur%networkProbeTaskFrequency == 0 ) {
            long long dnsResolveTimeInMilliSeconds = getDnsResolveTime("google.com");
            long long tcpConnectionTimeMilliSeconds = getTcpConnectionTime("google.com", 80);
            // Update Database
            insertIntoDnsTable(std::to_string(dnsResolveTimeInMilliSeconds));
            insertIntoTcpTable(std::to_string(tcpConnectionTimeMilliSeconds));
        }
        
        if(cur % systemProbeTaskFrequency == 0) {
            long memoryUsage = getMemoryUsage();
            insertIntoMemoryTable(std::to_string(memoryUsage));
        }
        
        usleep(1000000); // sleep for 1 second
        
        if(cur %networkProbeTaskFrequency == 0 && cur % systemProbeTaskFrequency == 0) {
            // Print metrics
            printMonitoringData();
        }
        
        cur = cur + 1;
    }
    
    return 0;
}
