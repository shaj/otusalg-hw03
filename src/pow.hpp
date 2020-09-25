
#pragma once

#include <vector>

namespace otusalg
{
// Алгоритм отсюда
// https://ru.wikipedia.org/wiki/%D0%90%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC%D1%8B_%D0%B1%D1%8B%D1%81%D1%82%D1%80%D0%BE%D0%B3%D0%BE_%D0%B2%D0%BE%D0%B7%D0%B2%D0%B5%D0%B4%D0%B5%D0%BD%D0%B8%D1%8F_%D0%B2_%D1%81%D1%82%D0%B5%D0%BF%D0%B5%D0%BD%D1%8C#%D0%A1%D1%85%D0%B5%D0%BC%D0%B0_%D1%81_%D0%BF%D1%80%D0%B5%D0%B4%D0%B2%D0%B0%D1%80%D0%B8%D1%82%D0%B5%D0%BB%D1%8C%D0%BD%D1%8B%D0%BC_%D0%B2%D1%8B%D1%87%D0%B8%D1%81%D0%BB%D0%B5%D0%BD%D0%B8%D0%B5%D0%BC
template <typename T>
T pow(T base, unsigned int exp)
{
	static_assert(std::is_arithmetic<T>::value, "Arithmetic requred.");

    int cnt = 0;
    unsigned int ti = exp;
    std::vector<T> pow2(sizeof(exp) * 8);

    pow2[0] = base;
    ti = ti >> 1;
    while(ti) {
        cnt++;
        pow2[cnt] = pow2[cnt-1] * pow2[cnt-1];
        ti = ti >> 1;
    }

    ti = exp;
    T retval;
    int bitcnt = 0;
    bool init = false;
    while(ti) {
        if(ti & 1) {
            if(init) {
                retval = retval * pow2[bitcnt];
                cnt++;
            } else {
                retval = pow2[bitcnt];
                init = true;
            }
        }
        ti = ti >> 1;
        bitcnt++;
    }
    std::cout << "\npow2::cnt " << cnt << std::endl;
    return retval;
}

} // namespace otusalg



