# 🌱 Smart Pot | گلدان هوشمند

<p align="center">
  <strong>A tiny, playful Arduino plant companion made as a handmade gift.</strong><br />
  <strong>یک همراه کوچک و دوست‌داشتنی برای گیاه، ساخته‌شده با آردوینو و به‌عنوان یک هدیه دست‌ساز.</strong>
</p>

<p align="center">
  <img alt="Arduino" src="https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white" />
  <img alt="License: MIT" src="https://img.shields.io/badge/License-MIT-green?style=for-the-badge" />
  <img alt="Status" src="https://img.shields.io/badge/Status-Fun%20Gift-ff69b4?style=for-the-badge" />
</p>

---

## 🇬🇧 English

### About

**Smart Pot** is a fun DIY plant-care project: when the soil moisture value goes above the configured threshold, the pot waits a short moment and then beeps to remind you that the plant needs attention. The current sensor value is also shown on a 16x2 I2C LCD.

This project was built as a personal gift for a friend, and the making process was shared as a vlog/post.

### What it does

- Reads a soil moisture sensor from analog pin `A6`.
- Shows the latest moisture reading on a 16x2 I2C LCD.
- Uses a buzzer on pin `12` as a simple alert.
- Uses a button on pin `2` with `INPUT_PULLUP` to silence/interrupt the alert.
- Uses a configurable moisture threshold in the sketch.

### Hardware

| Part | Notes |
| --- | --- |
| Arduino-compatible board | The sketch uses analog pin `A6`, so choose a board that exposes it, such as Arduino Nano-compatible boards. |
| Soil moisture sensor | Connected to `A6`. |
| 16x2 I2C LCD | Default I2C address: `0x27`. |
| Buzzer | Connected to digital pin `12`. |
| Push button | Connected to digital pin `2` and ground. |
| Jumper wires / power source | For wiring and powering the circuit. |

### Wiring

| Component | Arduino pin |
| --- | --- |
| Soil moisture sensor signal | `A6` |
| Buzzer | `D12` |
| Button | `D2` |
| I2C LCD SDA/SCL | Board I2C pins |
| I2C LCD address | `0x27` |

> The exact SDA/SCL pins depend on your Arduino-compatible board. For many Nano/Uno-style boards, SDA is `A4` and SCL is `A5`.

### Software requirements

- Arduino IDE or Arduino CLI
- [`LiquidCrystal_I2C`](https://github.com/johnrickman/LiquidCrystal_I2C) library

### Getting started

1. Clone this repository.
2. Open `smart_pot/smart_pot.ino` in the Arduino IDE.
3. Install the `LiquidCrystal_I2C` library if it is not already installed.
4. Select your Arduino-compatible board and port.
5. Upload the sketch.
6. Open the serial monitor is not required; the LCD shows the sensor reading directly.

### Calibration

The default threshold is:

```cpp
#define THRESHOLD 650
```

Moisture sensor values can vary depending on the sensor model, soil, wiring, and power source. If the alarm triggers too early or too late, adjust `THRESHOLD` in `smart_pot/smart_pot.ino`.

### Repository structure

```text
.
├── LICENSE
├── README.md
└── smart_pot
    └── smart_pot.ino
```

---

## 🇮🇷 فارسی

### درباره پروژه

**Smart Pot** یک پروژه فان و دست‌ساز برای مراقبت از گیاه است. وقتی مقدار سنسور رطوبت خاک از حد تعیین‌شده بیشتر شود، گلدان کمی صبر می‌کند و بعد با بازر هشدار می‌دهد تا حواستان به گیاه باشد. مقدار لحظه‌ای سنسور هم روی LCD کاراکتری 16x2 نمایش داده می‌شود.

این پروژه به‌عنوان یک هدیه برای یک دوست ساخته شده و روند ساخت آن هم به شکل ولاگ/پست منتشر شده است.

### قابلیت‌ها

- خواندن مقدار سنسور رطوبت خاک از پین آنالوگ `A6`.
- نمایش مقدار رطوبت روی LCD 16x2 با رابط I2C.
- هشدار صوتی با بازر متصل به پین `12`.
- امکان قطع/کنترل هشدار با دکمه متصل به پین `2` و حالت `INPUT_PULLUP`.
- امکان تغییر حد حساسیت از داخل کد.

### قطعات موردنیاز

| قطعه | توضیح |
| --- | --- |
| برد سازگار با Arduino | کد از پین آنالوگ `A6` استفاده می‌کند؛ بنابراین بردی مثل Arduino Nano یا بردهای مشابه که این پین را دارند مناسب است. |
| سنسور رطوبت خاک | خروجی سنسور به `A6` وصل می‌شود. |
| LCD 16x2 با I2C | آدرس پیش‌فرض در کد `0x27` است. |
| بازر | به پین دیجیتال `12` وصل می‌شود. |
| دکمه فشاری | به پین دیجیتال `2` و زمین وصل می‌شود. |
| سیم جامپر و منبع تغذیه | برای اتصال و راه‌اندازی مدار. |

### سیم‌کشی

| قطعه | پین روی آردوینو |
| --- | --- |
| خروجی سنسور رطوبت خاک | `A6` |
| بازر | `D12` |
| دکمه | `D2` |
| پایه‌های SDA/SCL نمایشگر I2C | پین‌های I2C برد |
| آدرس نمایشگر I2C | `0x27` |

> پین‌های SDA و SCL بسته به مدل برد متفاوت هستند. در بسیاری از بردهای شبیه Nano/Uno، پایه SDA برابر `A4` و پایه SCL برابر `A5` است.

### پیش‌نیازهای نرم‌افزاری

- Arduino IDE یا Arduino CLI
- کتابخانه [`LiquidCrystal_I2C`](https://github.com/johnrickman/LiquidCrystal_I2C)

### راه‌اندازی

1. مخزن را کلون کنید.
2. فایل `smart_pot/smart_pot.ino` را در Arduino IDE باز کنید.
3. اگر کتابخانه `LiquidCrystal_I2C` نصب نیست، آن را نصب کنید.
4. برد و پورت درست را انتخاب کنید.
5. کد را روی برد آپلود کنید.
6. نیازی به Serial Monitor نیست؛ مقدار سنسور مستقیم روی LCD نمایش داده می‌شود.

### کالیبراسیون

حد پیش‌فرض در کد این مقدار است:

```cpp
#define THRESHOLD 650
```

مقدار خروجی سنسور رطوبت می‌تواند با توجه به مدل سنسور، نوع خاک، سیم‌کشی و منبع تغذیه متفاوت باشد. اگر هشدار خیلی زود یا خیلی دیر فعال می‌شود، مقدار `THRESHOLD` را در فایل `smart_pot/smart_pot.ino` تغییر دهید.

### ساختار پروژه

```text
.
├── LICENSE
├── README.md
└── smart_pot
    └── smart_pot.ino
```

---

## License | مجوز

This project is released under the MIT License. See [`LICENSE`](LICENSE) for details.

این پروژه با مجوز MIT منتشر شده است. برای جزئیات بیشتر فایل [`LICENSE`](LICENSE) را ببینید.
