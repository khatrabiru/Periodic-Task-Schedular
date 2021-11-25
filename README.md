# C++ Coding Challenge: Build a Periodic Task Scheduler

## Why?

Monitoring internal and external systems requires a fixed sample rate in order to perform statistical analysis and correlate data from multiple sources.

## Requirements

Implement a periodic task scheduler in C++ (not plain C). 

- The scheduler should support two kinds of tasks: network and system probes. See below for the metrics you can collect on each kind of probe.
- It should be possible to customise the execution frequency for each task separately.
- Each task should return one or more “metrics” in the form of decimal values.
- Apart from raw metric data, the program must also calculate some aggregate metrics. For example: average, minimum, and maximum. The aggregate metrics must be kept up to date for each new data point that you collect.
- If the scheduler is stopped and restarted, it must continue where it left off, augmenting the existing data.

### Network probe Metrics
Choose from one of the following metrics for the Network Probe:
- Time to resolve a domain name to an IP address
- Time to connect to a TCP server, e.g., google.com port 80
- ICMP ping time to a server, e.g., google.com

### System probes
Choose from one of the following metrics for the System Probe:
- Total swapfile size and current usage
- Current physical memory used by your process
- Total packets sent and received on a specific network interface

## Notes
- Please return your exercise within a week.
- Please do not feel obliged to spend more than 4 hours on the task.
- Some tasks are platform specific, so please indicate the platform used for development in your response. The program need only compile and run on one major Operating System (whichever one you like).
- Focus more on the scheduler and its design than the two tasks you choose.
- Before submitting your source code, keep in mind that we will be reviewing your submission not just for completeness, but for code quality as well.
- If you plan on uploading your code to GitHub, please make sure the repository is private!

## Submission
Please send completed submissions, or any questions, to [thousandeyes-endpoint-agent@cisco.com]. We look forward to seeing what you come up with!
