# SIH26178 — Real World Research

> Factual foundation: India's environmental risks, current monitoring, NDMA/IMD/ISRO, SACHET/CAP, actual incidents.

---

## 1. India's Environmental Risk Landscape

| Hazard | Scale | Recent Evidence |
|---|---|---|
| **Urban flooding** | High | Monsoon 2023: Mumbai, Chennai, Hyderabad |
| **River floods** | High | Brahmaputra, Ganga basin annual cycles |
| **Forest fires** | High | Uttarakhand, Himachal Pradesh annual cycles |
| **Air pollution** | Very High | Delhi NCR, industrial corridors |
| **Extreme heat** | High | 2023: 50°C+ in Rajasthan |
| **Landslides** | Med | Himachal/Kerala monsoon events |
| **Industrial emissions** | Med | Bhopal-legacy awareness |
| **Water quality degradation** | Med | Ganga, industrial effluent |

---

## 2. Current Monitoring

| System | Owner | What it does | Limitation |
|---|---|---|---|
| **IMD satellite** | IMD | Weather forecasting | Revisit gaps, not local |
| **ISRO remote sensing** | ISRO | Satellite imagery | Periodic, not real-time |
| **CWC flood forecasting** | CWC | River flood prediction | Regional, not ward-level |
| **FSI forest fire** | FSI | Fire detection | Satellite-based, delayed |
| **CPCB air quality** | CPCB | Air quality monitoring | Sparse stations |

**Gap:** No village/ward-level, minutes-not-hours ground truth.

---

## 3. SACHET / CAP Integration

- **SACHET** — NDMA's Common Alerting Protocol (CAP) compliant alert system
- **CAP** — international standard for emergency alerts (OASIS)
- **Insight:** Feed our alerts into NDMA's existing SACHET/CAP bus rather than building a redundant standalone app
- **Why it matters:** Most teams build a new alert app; we integrate with the existing national infrastructure — a genuine differentiator

---

## 4. Institutional Context

- **NDMA** — national disaster management authority, owns SACHET/CAP
- **SDMAs** — state-level disaster management authorities (our primary users)
- **IMD/ISRO** — centralized monitoring (we complement, not replace)
- **FSI** — forest fire monitoring (fire is best-evidenced gap)

---

## 5. Key Sources

- NDMA SACHET/CAP documentation
- IMD/ISRO monitoring infrastructure
- CWC flood forecasting
- FSI forest fire monitoring
- CPCB air quality network
- Monsoon 2023 flood reporting
