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
