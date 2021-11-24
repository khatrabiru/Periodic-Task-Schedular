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
#include "Modules/Dns.hpp"

void printMonitoringData() {
    printf("\n\n***********************************************************************************************\n");
    std::cout << "Table               Min(microseconds)       Max(microseconds)    Agerage(microseconds)\n";
    float Min = getValue("DNS", "DnsResolveTime", "MIN");
    float Max = getValue("DNS", "DnsResolveTime", "MAX");
    float Average = getValue("DNS", "DnsResolveTime", "AVG");
    printf("DnsResolveTime %20f %20f %20f\n", Min, Max, Average);
    printf("\n\n***********************************************************************************************\n");
    
}

int main() {
    
    int networkProbeTaskFrequency = 3; // runs in every 5 seconds
    int systemProbeTaskFrequency = 6; // runs in every 5 seconds
    
    int cur = 0;
    
    // initialize Database
    initialize();
    
    while( true ) {
        if( cur%networkProbeTaskFrequency == 0 ) {
            long long dnsResolveTimeInMilliSeconds = getDnsResolveTime("lightoj.com");
            // Update Database
            insertIntoDnsTable(std::to_string(dnsResolveTimeInMilliSeconds));
        }
        
        usleep(1000000); // sleep for 1 second
        // Print metrics
        printMonitoringData();
        cur = cur + 1;
        break;
    }
    
    return 0;
}
