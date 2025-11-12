#pragma once

#include "synchronization.h"

void worker_t1(SyncLatches& latches);

void worker_t2(SyncLatches& latches);

void worker_t3(SyncLatches& latches);