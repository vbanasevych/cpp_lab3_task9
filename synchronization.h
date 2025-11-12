#pragma once
#include <latch>

struct SyncLatches
{
    std::latch start_b_c{1};

    std::latch start_e_f{1};

    std::latch start_g{1};

    std::latch start_h{2};

    std::latch start_i{3};

    std::latch start_j{2};

    std::latch start_k{1};

    std::latch main_wait{2};
};