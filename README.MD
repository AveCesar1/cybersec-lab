# 🔬 CyberSec Lab – Deep-Dive Coding Projects

> A journey from practical encryption tools to custom TLS channels, built from scratch in Python, C++, and Java.

## 👋 About Me
I’m a cybersecurity student obsessed with understanding how things break and how to defend them. This repository is my sandbox where I implement real protocols, exploit memory, and craft secure systems — not just use tools. Every project here is fully original code, written to learn the deepest layer of each concept.

## 🧰 Skills Demonstrated
| Area            | Technologies & Concepts                                      |
|-----------------|--------------------------------------------------------------|
| Cryptography    | AES-256, CBC/GCM, PBKDF2, S‑box math, RSA, DH, ECDH, PKI    |
| Networking      | Raw sockets, ARP, TCP/IP, custom binary protocols            |
| Secure Coding   | C++ memory safety, constant‑time operations, input validation |
| Exploitation    | Stack overflows, ROP, ASLR bypass, format strings            |
| Defensive       | IDS, traffic analysis, anomaly detection                      |
| Systems         | Linux sockets, C++ multi‑threading, CMake                     |

## 🗺️ Project Map
Pick any project — each folder contains its own detailed README with theory, architecture, and run instructions.

0. 🔐 [**AES-256 File Encryptor (C++)**](./00-aes-file-encryptor)  
   A terminal tool to encrypt any file with a password. Uses AES-256-CBC/GCM with PBKDF2 key derivation. Smart detection of `.enc` extension for automatic decryption. `-p` flag support. Built in modern C++ with OpenSSL.

1. 🔍 [Network Scanner](./01-network-scanner)  
   Pure Python, no libs — ARP sweep, ICMP ping sweep, SYN port scanner, raw socket packet crafting.

2. 🔐 [Crypto Toolkit](./02-crypto-toolkit)  
   AES-128 from the specification, RSA from modular arithmetic, classical ciphers. All in Python, all from scratch.

3. 🛡️ [Mini-IDS](./03-mini-ids)  
   Packet sniffing intrusion detection system with a configurable rule engine. Detects port scans, ARP spoofing, and suspicious DNS.

4. 📡 [Secure File Transfer Protocol](./04-secure-transfer)  
   Custom binary protocol over TCP with DH key exchange, HKDF, and AES-GCM encryption. Server and client in Python.

5. 💣 [Memory Exploit Lab](./05-memory-exploits)  
   Deliberately vulnerable C++ programs and their exploits (stack overflow, format string, ROP). Bypass ASLR, stack canaries.

6. ⛓️ [Blockchain from Scratch](./06-blockchain)  
   UTXO model, proof‑of‑work, Merkle trees, wallets with ECDSA, and a CLI to mine blocks and send transactions. Python.

7. 🔒 [TLS-like Secure Channel (C++)](./07-tls-channel)  
   Capstone project: a C++ library that does ECDH handshake, certificate verification, and AES-256-GCM encrypted streaming — just like a minimal TLS stack.

## 🧗 Learning Journey (Recommended Order)
1. **AES‑256 File Encryptor** – start with a real‑world crypto tool in C++. You’ll learn secure key derivation, block cipher modes, and command‑line design.  
2. **Network Scanner** – master raw sockets and packet structures.  
3. **Crypto Toolkit** – now build AES and RSA from absolute scratch; the math behind the tool you just made.  
4. **Mini‑IDS** – combine networking with detection logic.  
5. **Secure File Transfer** – design your own secure protocol end to end.  
6. **Memory Exploit Lab** – dive into C++ binary exploitation; this is where you become dangerous.  
7. **Blockchain from Scratch** – a fun, high‑visibility application of all previous crypto skills.  
8. **TLS-like Channel** – the grand finale: a C++ secure channel proving you can build what the internet runs on.

## 🎯 Why This Repo?
- No `pip install blackhat` shortcuts — everything is built from the socket, from the mathematical primitive, or from the language’s standard library.  
- Every project has its own deep‑dive README with diagrams, protocol specs, and references.  
- Code is clean, commented, and tested (CI badges coming soon).  
- Demonstrates the full spectrum: high‑level Python to low‑level C++, from theoretical math to practical exploits.

## 📬 Contact & CV
If you’re looking at this, you’re probably holding my CV. Feel free to explore the code, open an issue, or reach out on LinkedIn (link in my profile).
**Let’s build a safer world, one byte at a time.**