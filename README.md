# Tsunagu

**AI-Powered Smart Sign Language Glove**  
Real-time Sign-to-Speech translation using TinyML on ESP32-S3.

> "Tsunagu" (繋ぐ) means *"to connect"* in Japanese.

---

## Project Status

**Phase 0 — Simulation & Foundation** (Current)

We are building everything in simulation first.  
No physical hardware required at this stage.

---

## Vision

Tsunagu is a wearable glove that translates sign language into spoken speech in real time, running fully on-device with TinyML. It supports personalization per user and bidirectional communication (Sign → Speech + Speech → Haptic feedback).

---

## Repository Structure

```text
tsunagu/
├── docs/               # Design docs, architecture, decisions
├── hardware/           # Schematics, PCB, BOM, mechanical
├── firmware/           # ESP32-S3 firmware (FreeRTOS + TFLite Micro)
├── ml/                 # Dataset, training, quantization pipeline
├── mobile/             # Flutter companion app (future)
├── cloud/              # Backend / Firebase (future)
├── tools/              # Helper scripts & simulators
└── scripts/            # Utility scripts
```

---

## Current Focus (Simulation First)

1. Sensor data simulation
2. ML model training pipeline (Python)
3. Firmware logic simulation (C++)
4. End-to-end software prototype

Physical prototype comes later.

---

## Tech Stack (Planned)

| Layer          | Technology                          |
|----------------|-------------------------------------|
| MCU            | ESP32-S3                            |
| Firmware       | C++ / FreeRTOS / ESP-IDF or PlatformIO |
| On-device ML    | TensorFlow Lite Micro               |
| Training       | Python, TensorFlow / PyTorch        |
| Mobile App     | Flutter (later)                     |
| Cloud          | Firebase (later)                    |

---

## Getting Started

> Detailed setup instructions will be added as we progress.

```bash
git clone https://github.com/YOUR_USERNAME/tsunagu.git
cd tsunagu
```

---

## License

TBD (will be decided later)

---

## Contributors

- [wyyyrdx] — Project Lead
