#include <iostream>
#include <syncstream>
#include <thread>
#include <functional>

#include "synchronization.h"
#include "workers.h"

#ifdef _WIN32
#include <windows.h>
#endif

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(65001);
#endif

    std::osyncstream(std::cout) << "Обчислення розпочато.\n";

    SyncLatches latches;

    std::jthread t1(worker_t1, std::ref(latches));
    std::jthread t2(worker_t2, std::ref(latches));
    std::jthread t3(worker_t3, std::ref(latches));

    latches.main_wait.wait();

    std::osyncstream(std::cout) << "Обчислення завершено.\n";

    return 0;
}