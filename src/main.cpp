#include <iomanip>
#include <iostream>
#include <unistd.h>

#include "Metrics.hpp"

int main(void) {
  Metrics metrics;

  while (true) {

    std::cout << metrics.getUsername() << std::endl;
    std::cout << metrics.getHostname() << std::endl;
    std::cout << metrics.getOs() << std::endl;
    std::cout << metrics.getKernel() << std::endl;
    std::cout << metrics.getTime() << std::endl;
    std::cout << metrics.getDate() << std::endl;
    std::cout << metrics.getVCpuCount() << std::endl;
    std::cout << metrics.getPCpuCount() << std::endl;
    std::cout << metrics.getRamTotalKb() << std::endl;
    std::cout << metrics.getRamUsedKb() << std::endl;
    std::vector<uint8_t> cpus = metrics.getCpusUsage();

    for (size_t i = 0; i < cpus.size(); ++i) {
      std::cout << "CPU" << i << ": " << static_cast<int>(cpus[i]) << "%"
                << std::endl;
    }

    std::vector<Metrics::Inet> inets = metrics.getInets();

    std::cout << std::left << std::setw(10) << "Iface" << std::setw(15) << "IP"
              << std::setw(12) << "RX Packets" << std::setw(14) << "RX Bits"
              << std::setw(12) << "TX Packets" << std::setw(14) << "TX Bits"
              << "\n";

    for (auto &inet : inets) {
      std::cout << std::left << std::setw(10) << inet.getName() << std::setw(15)
                << inet.getIpt() << std::setw(12) << inet.getRPackets()
                << std::setw(14) << inet.getRBits() << std::setw(12)
                << inet.getTPackets() << std::setw(14) << inet.getTBits()
                << "\n";
    }

    sleep(1);
  }
  return 0;
}
