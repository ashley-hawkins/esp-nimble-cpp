#pragma once

#if defined(CONFIG_NIMBLE_CPP_MODERN_CPP) && defined(__has_include) && __has_include(<span>)
# include <span>
template <typename T>
using NimBLESpan = std::span<T>;
# define NIMBLE_MODERN_CXX
#else
#if defined(CONFIG_NIMBLE_CPP_MODERN_CPP)
# warning "NIMBLE_CPP_MODERN_CPP is defined but <span> is not available. Falling back to std::vector."
#endif
# include <vector>

template <typename T>
struct NimBLESpanImplHelper {
    using type = std::vector<T>&;
};

template <typename T>
struct NimBLESpanImplHelper<T const> {
    using type = const std::vector<T>&;
};

template <typename T>
using NimBLESpan = typename NimBLESpanImplHelper<T>::type;
#endif