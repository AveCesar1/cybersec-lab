# AES-256: THE PURE RAW MATH

## From Galois Fields to Ciphertext

**Notes:**
Welcome to *AES‑256: The Pure Raw Math*. Today we will dissect the Advanced Encryption Standard at the mathematical level — every Galois‑field operation, every matrix multiplication, every byte transformation. No hand‑waving. Just the math that protects the world's data.

---

## Journey into the Cipher

1. Why AES? Block Ciphers & SPN
2. Parameters: 256‑bit Key, 14 Rounds
3. The State & Byte Representation
4. Round Steps: SubBytes, ShiftRows, MixColumns, AddRoundKey
5. S‑box Deep Dive (GF(2⁸) & Affine Transform)
6. Key Expansion for AES‑256
7. Decryption & Modes
8. Security Considerations

**Notes:**
Here's our roadmap. We'll start with why AES exists, then dive into the parameters, the internal state representation, each transformation step in detail, the S‑box mathematics, key expansion, a live walkthrough, decryption, block‑cipher modes, and finally security analysis.

---

## Why AES?

> **Advanced Encryption Standard (2001)**
> * Superseded DES (broken by brute force)
> * Symmetric block cipher, 128‑bit block
> * Substitution‑Permutation Network (SPN)
> * Designed by Joan Daemen & Vincent Rijmen

### SPN Architecture
- Alternating layers of **confusion** (substitution) and **diffusion** (permutation)

**Notes:**
AES was selected by NIST in 2001 through an open competition. It replaced DES, which had become vulnerable to brute‑force attacks. AES is a symmetric block cipher — the same key encrypts and decrypts. It's built on a Substitution‑Permutation Network, the fundamental architecture for modern block ciphers. Think of SPN as alternating layers of confusion (substitution via S‑box) and diffusion (permutation via ShiftRows and MixColumns).

---

## AES‑256 at a Glance

| Parameter | Value |
|---|---|
| **Key size** | 256 bits (32 bytes) |
| **Block size** | 128 bits (16 bytes) |
| **Number of rounds** | 14 |
| **Key space** | 2^256 possible keys |
| **State matrix** | 4 × 4 byte matrix (per NIST FIPS‑197) |

### The 4×4 State Matrix
```
| s[0,0] | s[0,1] | s[0,2] | s[0,3] |
| s[1,0] | s[1,1] | s[1,2] | s[1,3] |
| s[2,0] | s[2,1] | s[2,2] | s[2,3] |
| s[3,0] | s[3,1] | s[3,2] | s[3,3] |
```
* Stored in **column‑major order**
* Each cell = 1 byte (8 bits) → total 16 bytes = 128 bits
* All bytes are elements of **GF(2⁸)** with irreducible polynomial \(m(x) = x⁸ + x⁴ + x³ + x + 1\) (hex 0x11B).

---

## AES Encryption Flow

```
Plaintext → AddRoundKey(0) →
  [Round 1‑13] SubBytes → ShiftRows → MixColumns → AddRoundKey →
  Final Round (14) SubBytes → ShiftRows → AddRoundKey → Ciphertext
```
### Round Structure Detail
* **Initial Round (Round 0):** AddRoundKey only — XOR plaintext with round‑key 0.
* **Standard Rounds (1‑13):** SubBytes → ShiftRows → MixColumns → AddRoundKey.
* **Final Round (14):** SubBytes → ShiftRows → AddRoundKey (no MixColumns).

---

## The 4×4 Byte State

State `s[r,c]` is stored column‑major. Each byte is a polynomial in **GF(2⁸)**.

*Example:* byte `0x57 = x⁶ + x⁴ + x² + x + 1`

**Irreducible polynomial:** \(m(x) = x⁸ + x⁴ + x³ + x + 1 = 0x11B\)

### Field Operations
* **Addition:** XOR (no carry)
* **Multiplication:** polynomial multiplication modulo \(m(x)\)
* **Inversion:** via extended Euclidean algorithm

### Input Byte Order (column‑major)
```
in[0] → s[0,0]   in[4] → s[0,1]
in[1] → s[1,0]   in[5] → s[1,1]
...               in[15] → s[3,3]
```

---

## SubBytes — The Heart of Confusion

`state[i][j] = S[state[i][j]]`  (16 × 16 lookup table)

### AES S‑Box (hex values)
```
63 7C 77 7B F2 6B 6F C5 30 01 67 2B FE D7 AB 76
CA 82 C9 7D FA 59 47 F0 AD D4 A2 AF 9C A4 72 C0
B7 FD 93 26 36 3F F7 CC 34 A5 E5 F1 71 D8 31 15
04 C7 23 C3 18 96 05 9A 07 12 80 E2 EB 27 B2 75
09 83 2C 1A 1B 6E 5A A0 52 3B D6 B3 29 E3 2F 84
53 D1 00 ED 20 FC B1 5B 6A CB BE 39 4A 4C 58 CF
D0 EF AA FB 43 4D 33 85 45 F9 02 7F 50 3C 9F A8
51 A3 40 8F 92 9D 38 F5 BC B6 DA 21 10 FF F3 D2
CD 0C 13 EC 5F 97 44 17 C4 A7 7E 3D 64 5D 19 73
60 81 4F DC 22 2A 90 88 46 EE B8 14 DE 5E 0B DB
E0 32 3A 0A 49 06 24 5C C2 D3 AC 62 91 95 E4 79
E7 C8 37 6D 8D D5 4E A9 6C 56 F4 EA 65 7A AE 08
BA 78 25 2E 1C A6 B4 C6 E8 DD 74 1F 4B BD 8B 8A
70 3E B5 66 48 03 F6 0E 61 35 57 B9 86 C1 1D 9E
E1 F8 98 11 69 D9 8E 94 9B 1E 87 E9 CE 55 28 DF
8C A1 89 0D BF E6 42 68 41 99 2D 0F B0 54 BB 16
```

### S‑Box Construction
1. **Multiplicative inverse** in GF(2⁸) (with `0x00 → 0x00`).
2. **Affine transform** over GF(2):
   \( b = A·inv + c \) with constant `c = 0x63` and matrix `A`:
```
1 0 0 0 1 1 1 1
1 1 0 0 0 1 1 1
1 1 1 0 0 0 1 1
1 1 1 1 0 0 0 1
1 1 1 1 1 0 0 0
0 1 1 1 1 1 0 0
0 0 1 1 1 1 1 0
0 0 0 1 1 1 1 1
```
*Example:* `0x53 → 0xED` (inverse = `0xCA`, affine → `0xED`).

---

## ShiftRows — Diffusion Across Columns

### Before
```
a00 a01 a02 a03
a10 a11 a12 a13
a20 a21 a22 a23
a30 a31 a32 a33
```
### After
```
a00 a01 a02 a03
a11 a12 a13 a10
a22 a23 a20 a21
a33 a30 a31 a32
```
* Row 0: no shift
* Row 1: shift left by 1 byte
* Row 2: shift left by 2 bytes
* Row 3: shift left by 3 bytes

---

## MixColumns — Matrix Multiplication in GF(2⁸)

` s' = M · s ` (per column)

### Fixed matrix **M**
```
02 03 01 01
01 02 03 01
01 01 02 03
03 01 01 02
```
* Multiplication rules:
  * `01` = identity
  * `02` = `xtime(b)` (left‑shift, xor 0x1B if overflow)
  * `03` = `xtime(b) XOR b`
  * `09` = `xtime(xtime(xtime(b))) XOR b` (used in inverse)

### Column computation (example for one column):
```
s'[0] = 02·s[0] ⊕ 03·s[1] ⊕ 01·s[2] ⊕ 01·s[3]
s'[1] = 01·s[0] ⊕ 02·s[1] ⊕ 03·s[2] ⊕ 01·s[3]
s'[2] = 01·s[0] ⊕ 01·s[1] ⊕ 02·s[2] ⊕ 03·s[3]
s'[3] = 03·s[0] ⊕ 01·s[1] ⊕ 01·s[2] ⊕ 02·s[3]
```
*`xtime(b) = (b << 1) XOR 0x1B` if the most‑significant bit of `b` is 1.

---

## AddRoundKey — Simple XOR

`state[r,c] = state[r,c] XOR roundKey[r,c]`

### Example
```
State          Round Key        Result (XOR)
32 88 31 E0    2B 28 AB 09    19 A0 9A E9
43 5A 31 37    7E AE F7 CF    3D F4 C6 F8
F6 30 98 07    15 D2 15 4F    E3 E2 8D 48
A8 8D A2 34    16 A6 88 3C    BE 2B 2A 08
```
* Properties:
  * Self‑inverse: `(a XOR k) XOR k = a`
  * Each round uses a unique sub‑key from the key‑expansion schedule.

---

## Key Expansion (256‑bit → 60 words)

* **Input:** 32‑byte key `K[0..31]`
* **Output:** 60 32‑bit words `W[0..59]` (15 round keys)

### Steps
1. **Initialize:** `W[0..7] = K` split into 8 words.
2. **Expand:** For `i = 8 … 59`
   ```
   if i mod 8 == 0:
       temp = SubWord(RotWord(W[i‑1])) XOR Rcon[i/8]
   elif i mod 8 == 4:   // AES‑256 only
       temp = SubWord(W[i‑1])
   else:
       temp = W[i‑1]
   W[i] = W[i‑8] XOR temp
   ```
3. **Form round keys:** `RoundKey[r] = W[4r .. 4r+3]` for `r = 0 … 14`.

### Rcon values (hex)
`01 02 04 08 10 20 40 80 1B …`

*Note:* The extra `SubWord` at `i mod 8 == 4` adds non‑linearity, strengthening AES‑256 against related‑key attacks.

---

## AES‑256 in Action (Sample Walk‑through)

**Plaintext (hex):** `32 43 F6 A8 88 5A 30 8D 31 31 98 A2 E0 37 07 34`
**Key:** 256‑bit sample key (omitted for brevity).

1. **Initial State** → column‑major arrangement.
2. **AddRoundKey(0)**
3. **SubBytes**
4. **ShiftRows**
5. **MixColumns**
6. **AddRoundKey(1)**

*After Round 1 the state becomes*:
```
04 E0 48 28
66 CB F8 06
81 19 D3 26
E5 9A 7A 4C
```
The subsequent steps continue similarly for the remaining rounds.

---

## Decryption: Inverse Operations

| Encrypt | Decrypt | Description |
|---|---|---|
| SubBytes | InvSubBytes | Inverse S‑box lookup |
| ShiftRows | InvShiftRows | Right shift (0,1,2,3) |
| MixColumns | InvMixColumns | Multiplication by inverse matrix |

### Inverse MixColumns Matrix
```
0E 0B 0D 09
09 0E 0B 0D
0D 09 0E 0B
0B 0D 09 0E
```
**Decryption flow:**
`Ciphertext → InvAddRoundKey → InvMixColumns → InvShiftRows → InvSubBytes → … → Plaintext`
(operations applied in reverse order).

---

## Beyond ECB — Block Cipher Modes

| Mode | Characteristics |
|---|---|
| **ECB** (Electronic Codebook) | Each block encrypted independently → insecure (identical plaintext → identical ciphertext) |
| **CBC** (Cipher Block Chaining) | XOR each plaintext block with previous ciphertext block before encryption; requires random IV (16 bytes) and PKCS#7 padding |
| **GCM** (Galois/Counter Mode) | Authenticated Encryption (AEAD); provides confidentiality + integrity; produces 128‑bit authentication tag |

**Practical guidance**
* Never reuse an IV/nonce with the same key (especially in CBC).
* Use PKCS#7 padding for CBC.
* Prefer GCM for new systems – it offers both encryption and integrity verification.
* Avoid ECB for any data with patterns.

---

## Why AES‑256 Remains Strong

* **Brute‑force resistance:** 2^256 key possibilities → far more than atoms in the observable universe.
* **Security summary:** No practical attack on full AES‑256. The best known attack (biclique) reduces complexity to ~2^254.4, only ~1.6× faster than brute force.
* **Related‑key attacks:** Theoretical only, requiring >2^100 effort.
* **Side‑channel resistance:** Constant‑time implementations mitigate timing and power‑analysis attacks.

*The math that protects the digital world.*

---