#pragma once

namespace RSA {

int GetD(int a, int m);
int GetN(int p, int q);
int GetPhi(int p, int q);
int GetE(int phi);

long Encode(long message, long e, long n);
long Decode(long message, long d, long n);

}  // namespace RSA
