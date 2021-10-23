# Node.js Wiring PI (V8 C++ addon)

Dead-simple and minimal V8 C++ addon for major versions of Node.js (tested on 10+) to work with GPIO.
Includes TypeScript typings.

## Installation

```bash
npm install https://github.com/Irelynx/node-wiring-pi

# or 

git clone https://github.com/Irelynx/node-wiring-pi
cd ./myNodejsApp
npm install ../node-wiring-pi
```

# Usage after installation

```javascript
const wpi = require('node-wiringPi')

// or 

const {
  wiringPiSetup,
  piBoardRev,
  digitalRead,
  digitalWrite,
  pinMode,
  delay,
  delayMicroseconds,
  LOW,
  HIGH,
  INPUT,
  OUTPUT
} = require('node-wiringPi');
```

## Verified versions of Node.js that works with addon

* Node.js v10.23.0 (V8 v6.8.275.32)
* Node.js v14.15.3 (V8 v8.4.371.19)

Tested at: 2020.12.30, on Orange Pi Zero (H2+, 512MB)

## Requirements

* Wiring Pi (or similar, like WiringOP. Tested on this version: https://github.com/orangepi-xunlong/wiringOP.git (latest commit: 35de0150a9c319a52badd15abe7ef172bc2e4afe 2020.12.14)
) must be installed on system
* g++ with C++ 11 support

## Available functions/variables

| Name | Type | Description |
| - | - | - |
| `wiringPiSetup`(): Number                                         | function  | Initial Setup, must be called before any other function will be called |
| `piBoardRev`(): Number                                            | function  | Get Pi board revision         |
| `pinMode`(`pin`: Number, `mode`: `OUTPUT` \| `INPUT`): `void`     | function  | Set pin mode                  |
| `digitalWrite`(`pin`: Number, `value`: `LOW` \| `HIGH`): `void`   | function  | Write digital value           |
| `digitalRead`(`pin`: Number): `LOW` \| `HIGH`                     | function  | Read digital value            |
| `delay`(`ms`: Number): `void`                                     | function  | **SYNC** Milliseconds delay   |
| `delayMicro`(`mks`: Number): `void`                               | function  | **SYNC** Microseconds delay   |
| `LOW`: Number = `0`                                               | Number    | LOW digital signal value      |
| `HIGH`: Number = `1`                                              | Number    | HIGH digital signal value     |
| `INPUT`: Number = `0`                                             | Number    | INPUT mode                    |
| `OUTPUT`: Number = `1`                                            | Number    | OUTPUT mode                   |

## Why yet another GPIO module?

* **Major part of modules** in NPM or GitHub for wiringPi library, that provides GPIO access, **does not compile on newer versions of Node.js**, or uses different versions of wiringPi with tweaks, or developers refuse to support new versions of Node.js (because of V8 API changes, like "removing" v8::Handle<T>), or projects are completely abandoned
* Practice

## Used links and documentations

* [Node.js C++ Addons (nodejs.org)](https://nodejs.org/api/addons.html)
* [V8 documentation for version 8.4.371, (Node.js v14.15) (v8docs.nodesource.com)](https://v8docs.nodesource.com/node-14.15/d2/dc3/namespacev8.html)
* [Getting started with embedding V8 (v8.dev)](https://v8.dev/docs/embed)
* [Source code of Native Abstractions for Node.js (github.com)](https://github.com/nodejs/nan)
