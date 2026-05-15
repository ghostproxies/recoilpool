# RecoilFuse™

[![RecoilFuse™](https://repository-images.githubusercontent.com/1194828506/810e0ef3-a313-4c82-b30f-68a85d18e07f)](https://github.com/ghostproxies/recoilfuse)

## Table of Contents

- [Introduction](README.md?tab=readme-ov-file#introduction)
- [Author](README.md?tab=readme-ov-file#author)
- [License](README.md?tab=readme-ov-file#license)
- [Reference](README.md?tab=readme-ov-file#reference)

## Introduction

RecoilFuse™ is the hyper-efficient 64-bit PRNG for 128-bit output.

In further detail, RecoilFuse™ is a non-cryptographic PRNG (for 64-bit architecture) that has 128 bits of output (for each `recoilfuse` result), [PulseField™](https://github.com/ghostproxies/pulsefield), a minimum period of at least 2⁶⁴, excellent statistical test results, hyper-fast speed and reversibility.

## Author

RecoilFuse™ was created by [William Stafford Parsons](https://github.com/williamstaffordparsons) as a product of [GhostProxies](https://ghostproxies.com).

## License

RecoilFuse™ is licensed with the [BSD-3-Clause](LICENSE) license.

## Reference

RecoilFuse™ was implemented in C (requiring the `stdint.h` header to define a 64-bit, unsigned integral type for `uint64_t`).

[recoilfuse.c](recoilfuse.c)

The `recoilfuse` function modifies the state in a `struct recoilfuse_state` instance to generate 2 pseudorandom `uint64_t` integers in the `output` array.

Each state variable (`a`, `b` and `c`) in a `struct recoilfuse_state` instance must be [seeded](https://ghostproxies.com/ectoplasm) (before generating a deterministic RecoilFuse™ sequence that must discard the first few `recoilfuse` results).

RecoilFuse™ uses [PulseField™](https://github.com/ghostproxies/pulsefield) to generate deterministic sequences that each have a minimum period of at least 2⁶⁴.

As specified by [PulseField™](https://github.com/ghostproxies/pulsefield), RecoilFuse™ can generate up to at least 2⁶⁴ independent parallel instances that each avoid full state collisions (for at least 2⁶⁴ `recoilfuse` results) among the set of parallel instances.

RecoilFuse™ yields excellent results in the latest stringent statistical test suites such as Dieharder 3.31.1, NIST STS, TestU01 1.2.3 BigCrush (using the 128-bit output as 4 32-bit integers) and PractRand 0.96.

Each of the following PRNG speed test results log the fastest process execution speed (from an AMD A4-9120C) among several repetitions of a test that generates (and hashes) 1 billion pseudorandom `uint64_t` integers in a `#pragma GCC unroll 0` loop.

| PRNG | Milliseconds |
| --- | --- |
| **`recoilfuse`** (`gcc -O3`) | **757ms** |
| `shishua_avx2` (`gcc -O3 -mavx2`) | 866ms |
| `shishua_sse4` (`gcc -O3 -msse4`) | 978ms |
| [`blastcircuit`](https://github.com/ghostproxies/blastcircuit) (`gcc -O3`) | 1072ms |
| `shishua_sse3` (`gcc -O3 -msse3`) | 1147ms |
| `shishua_sse2` (`gcc -O3 -msse2`)| 1154ms |
| `shishua` (`gcc -O3`) | 2251ms |
| `sfmt` (`gcc -O3 -msse2`) | 5525ms |
