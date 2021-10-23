declare namespace wiringPi {
    // constants
    
    // LOW digital level
    export const LOW = 0;
    // HIGH digital level
    export const HIGH = 1;
    // INPUT mode
    export const INPUT = 0;
    // OUTPUT mode
    export const OUTPUT = 1;
    export type DigitalLevel = typeof LOW | typeof HIGH;
    export type DigitalMode = typeof INPUT | typeof OUTPUT;
    
    // functions

    // wiringPi init
    export function wiringPiSetup(): void;
    // get board revision field
    export function piBoardRev(): void;
    // read from pin
    export function digitalRead(pin: Number): DigitalLevel;
    // write to pin
    export function digitalWrite(pin: Number, pinLevel: DigitalLevel): void;
    // set pin mode
    export function pinMode(pin: Number, pinMode: DigitalMode): void;
    // Milliseconds delay
    export function delay(howLong_ms: Number): void;
    // Microseconds delay
    export function delayMicroseconds(howLong_mks: Number): void;
}

export = wiringPi;


