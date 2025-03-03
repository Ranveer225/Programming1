#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

const int PAGES = 100, PAGE_SIZE = 160, START_ADDR = 2000;
int memory[PAGES] = {0}, nextAddr = START_ADDR;

int main() {
    srand(time(0));
    int processId = 1;

    while (true) {
        int pagesNeeded = rand() % 30 + 1, processSize = pagesNeeded * 80;
        int pagesRequired = ceil((double)processSize / PAGE_SIZE);
        int freePages = 0;

        for (int i = 0; i < PAGES; i++) if (!memory[i]) freePages++;
        if (freePages < pagesRequired) break;

        for (int i = 0, count = 0; i < PAGES && count < pagesRequired; i++)
            if (!memory[i]) memory[i] = processId, count++;

        int totalUsed = pagesRequired * PAGE_SIZE, unused = totalUsed - processSize;
        cout << "Process " << processId << " to " << nextAddr << ", Size: " << processSize << "MB, Unused: " << unused << "MB\n";
        nextAddr += totalUsed;
        processId++;
    }
}
