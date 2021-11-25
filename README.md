# C++ Coding Challenge: Build a Periodic Task Scheduler

## Why?

Monitoring internal and external systems requires a fixed sample rate in order to perform statistical analysis and correlate data from multiple sources.

## Requirements

Implement a periodic task scheduler in C++ (not plain C). 

- The scheduler should support two kinds of tasks: network and system probes.
- It should be possible to customise the execution frequency for each task separately.
- Each task should return one or more “metrics” in the form of decimal values.
- Apart from raw metric data, the program must also calculate some aggregate metrics. For example: average, minimum, and maximum. The aggregate metrics must be kept up to date for each new data point that you collect.
- If the scheduler is stopped and restarted, it must continue where it left off, augmenting the existing data.

### Network probe Metrics
Choose from one of the following metrics for the Network Probe:
- Time to resolve a domain name to an IP address
- Time to connect to a TCP server, e.g., google.com port 80

### System probes
Choose from one of the following metrics for the System Probe:
- Current physical memory used by your process

### Output

DNS Table created successfully
TCP Table created successfully
MEMORY Table created successfully
Inserted into DNS table successfully
Inserted into TCP table successfully
Records created successfully


***********************************************************************************************
Table               Min(microseconds)       Max(microseconds)    Agerage(microseconds)
DnsResolveTime         30004.000000         30004.000000         30004.000000


***********************************************************************************************
Table               Min(microseconds)       Max(microseconds)    Agerage(microseconds)
TcpConnectionTime         17516.000000         17516.000000         17516.000000


***********************************************************************************************
Table               Min(bytes)              Max(bytes)           Agerage(bytes)
MemoryUsage       41775104.000000      41775104.000000      41775104.000000


***********************************************************************************************
Inserted into DNS table successfully
Inserted into TCP table successfully
Inserted into DNS table successfully
Inserted into TCP table successfully
Records created successfully


***********************************************************************************************
Table               Min(microseconds)       Max(microseconds)    Agerage(microseconds)
DnsResolveTime           987.000000         30004.000000         10700.000000


***********************************************************************************************
Table               Min(microseconds)       Max(microseconds)    Agerage(microseconds)
TcpConnectionTime         17516.000000         27332.000000         22827.000000


***********************************************************************************************
Table               Min(bytes)              Max(bytes)           Agerage(bytes)
MemoryUsage       41775104.000000      41820160.000000      41797632.000000


***********************************************************************************************
Inserted into DNS table successfully
Inserted into TCP table successfully
Inserted into DNS table successfully
Inserted into TCP table successfully
Records created successfully


***********************************************************************************************
Table               Min(microseconds)       Max(microseconds)    Agerage(microseconds)
DnsResolveTime           942.000000         30004.000000          6811.000000


***********************************************************************************************
Table               Min(microseconds)       Max(microseconds)    Agerage(microseconds)
TcpConnectionTime         15470.000000         27332.000000         21751.000000


***********************************************************************************************
Table               Min(bytes)              Max(bytes)           Agerage(bytes)
MemoryUsage       41775104.000000      41840640.000000      41811968.000000


***********************************************************************************************
Inserted into DNS table successfully
Inserted into TCP table successfully
Inserted into DNS table successfully
Inserted into TCP table successfully
Records created successfully


***********************************************************************************************
Table               Min(microseconds)       Max(microseconds)    Agerage(microseconds)
DnsResolveTime           934.000000         30004.000000          5148.000000


***********************************************************************************************
Table               Min(microseconds)       Max(microseconds)    Agerage(microseconds)
TcpConnectionTime         15470.000000         27479.000000         23345.000000


***********************************************************************************************
Table               Min(bytes)              Max(bytes)           Agerage(bytes)
MemoryUsage       41775104.000000      41840640.000000      41819136.000000


***********************************************************************************************
