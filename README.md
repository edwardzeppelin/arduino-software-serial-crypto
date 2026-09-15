# Multi-Node Encrypted Serial Communication System

A multi-node Arduino communication pipeline demonstrating encrypted serial data transmission across three microcontroller boards. Messages are encrypted on Node 1 using a Caesar cipher, passed through Node 2 as an intermediate relay, and decrypted back to plaintext on Node 3.

## Features

* **Caesar Cipher Security**: Encrypts and decrypts alphabetic characters using a shift key of 3 while preserving character case.
* **Multi-Node Architecture**: Demonstrates chained data forwarding across three hardware units using `SoftwareSerial` and hardware serial interfaces.
* **Transparent Relay**: Node 2 forwards encrypted streams directly to Node 3 without requiring decryption keys.

## Node Architecture

* `messenger_uart_m1.ino` — Reads text input from the Serial Monitor, encrypts it via `encryptCaesar` with a shift of 3, and transmits it over `SoftwareSerial` (RX 50, TX 51).
* `messenger_uart_m2.ino` — Receives encrypted strings from Node 1 via `SoftwareSerial` (pins 50/51) and forwards them to Node 3 via `Serial1`.
* `messenger_uart_m3.ino` — Receives encrypted data from `Serial1`, decrypts it via `decryptCaesar` with a shift of 3, and outputs plaintext to the Serial Monitor.

## Hardware Wiring

* **M1 to M2 Connection**: Connect M1 SoftwareSerial TX (Pin 51) to M2 SoftwareSerial RX (Pin 50).
* **M2 to M3 Connection**: Connect M2 `Serial1` TX (Pin 18 on Arduino Mega) to M3 `Serial1` RX (Pin 19 on Arduino Mega).
* **Common Ground**: Interconnect GND pins across all three boards to share a common ground reference.

## Usage

1. Upload `M1` code to Node 1, `M2` code to Node 2, and `M3` code to Node 3.
2. Open the Serial Monitor for Node 1 set to **9600 baud**.
3. Enter a text message in Node 1's Serial Monitor.
4. Observe the decrypted output in Node 3's Serial Monitor set to **9600 baud**.
