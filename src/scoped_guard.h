//
// Created by peifeng on 7/25/18.
//

#ifndef PLASMA_POTD_SPOTLIGHT_SCOPED_GUARD_H
#define PLASMA_POTD_SPOTLIGHT_SCOPED_GUARD_H

#include <functional>
#include <optional>

template<typename Callable>
class scope_guard
{
public:
    scope_guard(scope_guard &&) = default;

    scope_guard(Callable &&func)
        : f(std::forward<Callable>(func))
    {
    }

    ~scope_guard()
    {
        if (f) {
            std::invoke(*f);
        }
    }

    void dismiss() noexcept
    {
        f.reset();
    }

private:
    scope_guard(const scope_guard &) = delete;
    void operator=(const scope_guard &) = delete;

    std::optional<Callable> f;
};

#endif // PLASMA_POTD_SPOTLIGHT_SCOPED_GUARD_H
