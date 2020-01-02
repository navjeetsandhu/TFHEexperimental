#pragma once
#include <array>
#include <cmath>
#include <cstdint>

namespace TFHEpp {
using namespace std;

const uint32_t DEF_n = 500;
const double DEF_α = 2.44e-5;
const uint32_t DEF_Nbit = 10;
const uint32_t DEF_N = 1 << DEF_Nbit;
const uint32_t DEF_l = 2;
const uint32_t DEF_Bgbit = 10;
const uint32_t DEF_Bg = 1 << DEF_Bgbit;
const double DEF_αbk = 3.73e-9;
const uint32_t DEF_t = 8;
const uint32_t DEF_basebit = 2;
const double DEF_αks = 2.44e-5;
const uint32_t DEF_μ = 1U << 29;

const uint32_t DEF_nbarbit = 11;
const uint32_t DEF_nbar = 1 << DEF_nbarbit;
const uint32_t DEF_lbar = 4;
const uint32_t DEF_Bgbitbar = 9;
const uint32_t DEF_Bgbar = 1 << DEF_Bgbitbar;
const double DEF_αbklvl02 = std::pow(2.0, -44);
const uint32_t DEF_tbar = 10;
const uint32_t DEF_basebitlvl21 = 3;
const double DEF_αprivks = std::pow(2, -31);
const uint64_t DEF_μbar = 1UL << 61;

using Keylvl0 = array<uint32_t, DEF_n>;
using Keylvl1 = array<uint32_t, DEF_N>;
using Keylvl2 = array<uint64_t, DEF_nbar>;

using TLWElvl0 = array<uint32_t, DEF_n + 1>;
using TLWElvl1 = array<uint32_t, DEF_N + 1>;
using TLWElvl2 = array<uint64_t, DEF_nbar + 1>;

using Polynomiallvl1 = array<uint32_t, DEF_N>;
using Polynomiallvl2 = array<uint64_t, DEF_nbar>;
using PolynomialInFDlvl1 = array<double, DEF_N>;
using PolynomialInFDlvl2 = array<double, DEF_nbar>;

using TRLWElvl1 = array<Polynomiallvl1, 2>;
using TRLWElvl2 = array<Polynomiallvl2, 2>;
using TRLWEInFDlvl1 = array<PolynomialInFDlvl1, 2>;
using TRLWEInFDlvl2 = array<PolynomialInFDlvl2, 2>;
using DecomposedTRLWElvl1 = array<Polynomiallvl1, 2 * DEF_l>;
using DecomposedTRLWElvl2 = array<Polynomiallvl2, 2 * DEF_lbar>;
using DecomposedTRLWEInFDlvl1 = array<PolynomialInFDlvl1, 2 * DEF_l>;
using DecomposedTRLWEInFDlvl2 = array<PolynomialInFDlvl2, 2 * DEF_lbar>;

using TRGSWlvl1 = array<TRLWElvl1, 2 * DEF_l>;
using TRGSWlvl2 = array<TRLWElvl2, 2 * DEF_lbar>;
using TRGSWFFTlvl1 = array<TRLWEInFDlvl1, 2 * DEF_l>;
using TRGSWFFTlvl2 = array<TRLWEInFDlvl2, 2 * DEF_lbar>;

using BootStrappingKeyFFTlvl01 = array<TRGSWFFTlvl1, DEF_n>;
using BootStrappingKeyFFTlvl02 = array<TRGSWFFTlvl2, DEF_n>;

using KeySwitchingKey =
    array<array<array<TLWElvl0, (1 << DEF_basebit) - 1>, DEF_t>, DEF_N>;
using PrivKeySwitchKey =
    array<array<array<array<TRLWElvl1, (1 << DEF_basebitlvl21) - 1>, DEF_tbar>,
                DEF_nbar + 1>,
          2>;

struct lweParams {
    const uint32_t n = DEF_N;
    const double α = DEF_α;
    const uint32_t Nbit = DEF_Nbit;
    const uint32_t N = DEF_N;
    const uint32_t l = DEF_l;
    const uint32_t Bgbit = DEF_Bgbit;
    const uint32_t Bg = DEF_Bg;
    const double αbk = DEF_αbk;
    const uint32_t t = DEF_t;
    const uint32_t basebit = DEF_basebit;
    const double αks = DEF_α;
    const uint32_t μ = DEF_μ;

    const uint32_t nbarbit = DEF_nbarbit;
    const uint32_t nbar = DEF_nbar;
    const uint32_t lbar = DEF_lbar;
    const uint32_t Bgbitbar = DEF_Bgbitbar;
    const uint32_t Bgbar = DEF_Bgbar;
    const double αbklvl02 = DEF_αbklvl02;
    const uint32_t tbar = DEF_tbar;
    const uint32_t basebitlvl21 = DEF_basebitlvl21;
    const double αprivks = DEF_αprivks;
    const uint64_t μbar = DEF_μbar;
};
}  // namespace TFHEpp