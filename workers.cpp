#include "workers.h"

#include <iostream>
#include <syncstream>

void f(char task_name, int action_id)
{
    std::osyncstream(std::cout) << "З набору " << task_name
                               << " виконано дію " << action_id << ".\n";
}


void worker_t1(SyncLatches& latches)
{
    f('a', 1);
    f('a', 3);

    latches.start_b_c.wait();

    f('b', 1); f('b', 2); f('b', 3);
    f('b', 4); f('b', 5); f('b', 6);
    latches.start_i.count_down();

    latches.start_e_f.wait();

    f('e', 4); f('e', 6); f('e', 8);
    latches.start_h.count_down();
    latches.start_i.count_down();

    latches.start_i.wait();

    f('i', 1); f('i', 2); f('i', 3); f('i', 4);
    latches.start_j.count_down();

    latches.start_h.wait();

    f('h', 5); f('h', 7);
    latches.start_j.count_down();

    latches.start_j.wait();

    f('j', 1); f('j', 3); f('j', 5);
    latches.main_wait.count_down();

    latches.start_k.wait();

    f('k', 5); f('k', 8);
    latches.main_wait.count_down();
}

void worker_t2(SyncLatches& latches)
{
    f('d', 1); f('d', 2); f('d', 3); f('d', 4); f('d', 5);
    latches.start_e_f.count_down();

    f('e', 1); f('e', 2); f('e', 3); f('e', 5); f('e', 7);

    f('f', 5); f('f', 7); f('f', 8);
    latches.start_g.count_down();

    latches.start_g.wait();

    f('g', 1); f('g', 2); f('g', 3); f('g', 4);

    latches.start_k.wait(); 

    f('k', 1); f('k', 2); f('k', 3); f('k', 6);
}

void worker_t3(SyncLatches& latches)
{
    f('a', 2); f('a', 4);
    latches.start_b_c.count_down();

    f('c', 1); f('c', 2); f('c', 3); f('c', 4);
    latches.start_h.count_down();
    latches.start_i.count_down();

    latches.start_e_f.wait();

    f('f', 1); f('f', 2); f('f', 3); f('f', 4); f('f', 6);

    latches.start_h.wait();

    f('h', 1); f('h', 2); f('h', 3); f('h', 4); f('h', 6);

    latches.start_g.wait();

    f('g', 5);
    latches.start_k.count_down();

    latches.start_j.wait();

    f('j', 2); f('j', 4);

    latches.start_k.wait();

    f('k', 4); f('k', 7);
}