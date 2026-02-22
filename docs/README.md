# 🌱 Smart Agricultural IoT System  
### A Power-Optimized, Real-Time Smart Irrigation System Using Arduino, Sensors & IoT

![Arduino](https://img.shields.io/badge/Arduino-Uno-blue?logo=arduino)
![IoT](https://img.shields.io/badge/IoT-ThingSpeak-green)
![Power](https://img.shields.io/badge/Power%20Optimization-Enabled-yellow)
![License: MIT](https://img.shields.io/badge/License-MIT-lightgrey)
![Status](https://img.shields.io/badge/Status-Active-brightgreen)

---

## 📘 Overview

The **Smart Agricultural IoT System** is a real-time precision irrigation setup designed using **Arduino UNO**, **ESP8266**, and **multi-sensor data fusion** for optimized water usage.  

It automates irrigation using soil moisture, water level, environmental parameters, and a scheduled RTC clock—achieving:

- 💧 **35% water conservation**  
- ⚡ **70% power reduction (deep sleep + optimized polling)**  
- 📡 **Cloud monitoring using ESP8266 + ThingSpeak**  
- 📟 **LCD-based live monitoring for field usage**

A perfect practical model for farms, IoT learning, college projects, and agricultural automation.

---

## 🧱 Project Structure

Smart-Agricultural-IoT-System/
│
├── src/
│ ├── smart_irrigation.ino # Main Arduino irrigation logic
│ ├── esp8266_thingspeak.ino # ESP8266 + WiFi + ThingSpeak uploader
│ └── rtc_config.ino # RTC compiler-time configuration
│
├── docs/
│ ├── README.md # Documentation (this file)
│ └── media/
│ ├── Parts used.png # Components image (visible in README)
│ └── demo_images/ # Add system photos/videos here
│
├── LICENSE # MIT License
└── .gitignore



---

## 🔌 Hardware Used

Below is the complete list of components used in this project:

| Component | Purpose |
|----------|---------|
| **Arduino UNO** | Main controller for irrigation logic |
| **ESP8266 (NodeMCU)** | Uploads sensor data to ThingSpeak |
| **Soil Moisture Sensor** | Measures soil water content (%) |
| **Water Level Sensor** | Detects tank water level |
| **DS1307 RTC Module** | Provides real-time clock for scheduling |
| **16×2 LCD (with I2C)** | Displays real-time sensor data |
| **Relay Module** | Controls the irrigation water pump |
| **DC Water Pump** | Performs actual irrigation |
| **Battery Pack** | Power supply with optimization |

### 📸 **Parts Used (Image)**  
Your image is now included in README:

![Parts Used](./media/Parts%20used.png)

*(If the image does not load on GitHub, verify that the file path is exactly:*  
`docs/media/Parts used.png` *)*

---

## ⚙️ Features

### 🌿 Smart Irrigation Control  
- Automatic pump activation based on moisture threshold  
- Moisture-based decision making with multi-sensor logic  
- Scheduled irrigation using RTC  

### 📟 Live Monitoring  
Displays the following on the LCD screen:

- Current Time (HH:MM:SS)  
- Soil Moisture (%)  
- Water Tank Status  
- Pump Status  

### 📡 IoT Cloud Integration  
- ESP8266 pushes **three sensor fields** to ThingSpeak:
  - Soil moisture  
  - Water level  
  - Pump activity  

### 🔋 Power Optimization  
- 6-month battery life using:
  - Deep sleep mode  
  - Wake-on-interrupt  
  - Optimized sensor polling intervals  

---

## 🚀 Getting Started

### 1️⃣ Clone the Repository
```bash
git clone https://github.com/heymayur69/Smart-Agricultural-IoT-System-.git
cd Smart-Agricultural-IoT-System-
2️⃣ Upload Arduino Code

Upload the following to Arduino UNO:

src/smart_irrigation.ino

src/rtc_config.ino (run once to configure RTC)

3️⃣ Configure ESP8266

Open src/esp8266_thingspeak.ino and update:

const char* ssid = "your_wifi";
const char* password = "your_password";

unsigned long ChannelNo = YOUR_CHANNEL_ID;
const char* API_Key = "YOUR_THINGSPEAK_API_KEY";
Upload to ESP8266.

4️⃣ Connect Hardware

Follow your circuit diagram (you may place it inside /docs/media/).

5️⃣ Monitor Data on ThingSpeak

View real-time:

Moisture trends

Water tank level visualization

Pump logs

📊 ThingSpeak Field Mapping
Field	Description
Field 1	Soil moisture sensor
Field 2	Water level sensor
Field 3	Pump state
👨‍💻 Contributors
Name	GitHub
Mayur Mane	heymayur69

Anjali Nanavare 	Anjali163
📜 License

This project is licensed under the MIT License.
You are free to modify and distribute this project as long as the license is included.

⭐ Support the Project

If you found this project useful, consider giving it a star ⭐ on GitHub!
Your support encourages more open-source IoT projects.


