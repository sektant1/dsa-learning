#ifndef SWAP_H
#define SWAP_H

#include <string>
#include <vector>

inline void swap_db(double& lhs, double& rhs) noexcept
{
    auto tmp = lhs;
    lhs      = rhs;
    rhs      = tmp;
};

inline void swap_vec(std::vector<std::string>& lhs,
                     std::vector<std::string>& rhs) noexcept
{
    auto tmp = lhs;
    lhs      = rhs;
    rhs      = tmp;
};

#endif
