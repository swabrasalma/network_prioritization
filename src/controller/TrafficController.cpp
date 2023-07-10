#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

// Traffic class representing an application
struct TrafficClass {
    std::string appName;
    std::queue<std::string> packets;
};

// Function to classify traffic based on server IP
void classifyTraffic(const std::string& packet, std::queue<TrafficClass>& trafficClasses, std::unordered_map<std::string, std::string>& ipToAppMapping) {
    // Perform traffic classification based on server IP
    
    // Example classification based on IP-to-Application mapping
    std::size_t ipStart = packet.find("ServerIP:") + 9;  // Assuming packet contains "ServerIP:<IP>"
    std::size_t ipEnd = packet.find(" ", ipStart);
    std::string serverIP = packet.substr(ipStart, ipEnd - ipStart);
    
    if (ipToAppMapping.find(serverIP) != ipToAppMapping.end()) {
        std::string appName = ipToAppMapping[serverIP];
        
        // Find the corresponding traffic class for the application
        for (auto& trafficClass : trafficClasses) {
            if (trafficClass.appName == appName) {
                // Push the packet to the traffic class's packet queue
                trafficClass.packets.push(packet);
                break;
            }
        }
    } else {
        // Other traffic
        // Handle or discard the packet based on requirements
    }
}

int main() {
    // Buffer to hold incoming packets
    std::queue<std::string> packetBuffer = {
        "Packet1 from ServerIP:192.168.1.10",
        "Packet2 from ServerIP:192.168.1.20",
        "Packet3 from ServerIP:192.168.1.10",
        "Packet4 from ServerIP:192.168.1.30",
        "Packet5 from ServerIP:192.168.1.20",
        "Packet6 from ServerIP:192.168.1.10",
        "Packet7 from ServerIP:192.168.1.20"
    };
    
    // Traffic classes (applications) and their corresponding server IP mappings
    std::queue<TrafficClass> trafficClasses;
    trafficClasses.push({"gmail", std::queue<std::string>()});
    trafficClasses.push({"youtube", std::queue<std::string>()});
    
    std::unordered_map<std::string, std::string> ipToAppMapping;
    ipToAppMapping["192.168.1.10"] = "gmail";
    ipToAppMapping["192.168.1.20"] = "youtube";
    
    // Process each packet in the buffer
    while (!packetBuffer.empty()) {
        // Get the next packet from the buffer
        std::string packet = packetBuffer.front();
        packetBuffer.pop();
        
        // Classify the packet and prioritize based on FIFO
        classifyTraffic(packet, trafficClasses, ipToAppMapping);
    }
    
    // Process packets from each traffic class in FIFO order
    while (!trafficClasses.empty()) {
        TrafficClass trafficClass = trafficClasses.front();
        trafficClasses.pop();
        
        std::cout << "Traffic for application \"" << trafficClass.appName << "\":" << std::endl;
        
        // Process packets in FIFO order for the traffic class
        while (!trafficClass.packets.empty()) {
            std::string packet = trafficClass.packets.front();
            trafficClass.packets.pop();
            
            // Process the packet
            std::cout << "Processing packet: " << packet << std::

        }
    }
}