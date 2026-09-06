# ULTRON — Single Plug Power Consolidation Plan

> Goal: run the entire ULTRON circuit from **one wall plug** with all devices working.
> Companion doc: `ULTRON_Circuit_Documentation.md`

---

## 1. Current Power Map (what draws from the wall)

| Device | Input | Draw | Notes |
|---|---|---|---|
| Raspberry Pi 4 8GB | USB-C | 5V / 3A (15W) | Central host — all USB peripherals are powered off it |
| Raspberry Pi 3A+ | Micro-USB | 5V / 2.5A (12.5W) | Tripwire node A |
| Raspberry Pi 3B | Micro-USB | 5V / 2.5A (12.5W) | Tripwire node B |
| 5-Port Ethernet Switch | DC barrel | ~5W | **Voltage varies by model — verify before buying cables** |
| ESP32-C3, ESP32-WROOM, SSD, Wi-Fi adapters, fan | — | 0W from wall | Already powered via Pi 4 USB / GPIO |

**Total worst case: ~45W sustained.** Design around this number.

---

## 2. Option A — Power Strip (baseline, zero risk)

One wall outlet → surge-protected power strip → all 4 existing adapters plug into the strip.

- Cost: ~₹300–500 (or reuse one you have)
- Risk: none — nothing changes electrically
- Verdict: fine if you just need it working today; not a real "reduction"

---

## 3. Option B — Single 65W+ GaN Charger (recommended)

One charger, one wall plug, 3–4 ports. This is the clean "reduced" solution.

| Port | Device | Cable needed |
|---|---|---|
| USB-C (PD) | Pi 4 | USB-C to USB-C (or USB-A to USB-C) |
| USB-A or USB-C | Pi 3A+ | USB-A to Micro-USB |
| USB-A or USB-C | Pi 3B | USB-A to Micro-USB |
| USB-C (PD) | Ethernet switch | USB-C PD trigger board → DC barrel (9V/12V switch) **or** USB-A to DC barrel (5V switch) |

### Critical caveats

1. **Check the charger's port-allocation table.** A 65W charger does NOT deliver 65W on every port simultaneously — typical split is 45W + 18W, etc. You need **45W sustained** (15 + 12.5 + 12.5 + 5). A **100W GaN** gives comfortable headroom if budget allows.
2. **Pi 4 USB-C quirk:** the Pi 4 accepts plain 5V (no PD negotiation needed), but avoid e-marked USB-C-to-USB-C cables. A standard USB-A-to-USB-C cable is the safest choice.
3. **Switch voltage — verify first:**
   - 5V switch (e.g., Netgear GS305, newer TP-Link TL-SG105): simple USB-A to DC barrel cable works.
   - 9V/12V switch (e.g., older TP-Link TL-SF1005D): needs a USB-C PD trigger board set to that voltage (~₹150). The PD port negotiates 9V/12V and feeds the barrel jack.

### Shopping list

| Item | Qty | Approx cost |
|---|---|---|
| 100W GaN charger (3–4 ports) | 1 | ₹2,000–3,000 |
| USB-A to Micro-USB cable | 2 | ₹200 |
| USB-C to USB-C cable | 1 | ₹200 |
| USB to DC barrel cable OR PD trigger board | 1 | ₹150–300 |

**Total: ~₹2,500–3,500. One plug into the wall.**

---

## 4. Option C — Single 5V/10A (50W) PSU + Distribution (engineering flex)

One Mean Well LRS-50-5 (~₹600) → terminal block → all devices.

- Deterministic power, no port-allocation guessing
- Looks intentional in a demo ("one clean PSU")
- Needs a buck/boost converter for a 9V/12V switch
- Needs adequate wire gauge to avoid voltage drop over long runs
- Only worth it if you want the engineered aesthetic

---

## 5. Recommendation

**Option B** — one 100W GaN charger + the cable list above. One plug, no soldering, ~₹2,500–3,500 total.

---

## 6. Safety Notes

- Verify the switch's input voltage before buying any barrel cable.
- Confirm the USB hub is bus-powered or externally powered — if bus-powered, the Pi 4's USB budget must cover hub + ESP32-WROOM + flash + TL-WN722N.
- Check SSD peak current (USB 3.0 enclosures can spike).
- Keep the fan on Pi 4 GPIO pins 4 (+5V) and 6 (GND) — it's already consolidated.
- Before first power-on, verify the flagged items from the circuit doc: shared tripwire ground, NeoPixel power/ground, UART pin mapping, and whether the two ESP32-C3 blocks are one device or two.