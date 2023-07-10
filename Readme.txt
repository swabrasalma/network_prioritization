--------------------------PROBMLEM DEFINITION-----------------------

Now I would like to address packet loss due to queue overflow and waiting times especially during peak 
times. My idea is to classify the relevant traffic(case study’s WLAN on a university faculty or school). 
After classification, we prioritize the traffic based on qos metrics eg. maximum delay limit & packet 
loss rate. Based on that criterion we can service the traffic and make evaluations against an ordinary 
FIFO in terms of packet overflow and delay.

-------------------------SPECS--------------------------------------

C++ 
Omnet Simulation
Non pre-emptive policy : all requests serviced but prioritized in FIFO

-------------------------MODULES BREAKDOWN--------------------------

********************************** WHAT DO WE CONSIDER SUCCESS ****************************


