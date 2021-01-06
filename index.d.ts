declare namespace wiringPi {
    // constants
    
    // LOW digital level
    declare const LOW: 0;
    // HIGH digital level
    declare const HIGH: 1;
    // INPUT mode
    declare const INPUT: 0;
    // OUTPUT mode
    declare const OUTPUT: 1;
    
    // functions

    // wiringPi init
    declare function wiringPiSetup(): void;
    // get board revision field
    declare function piBoardRev(): void;
    // read from pin
    declare function digitalRead(pin: Number): void;
    // write to pin
    declare function digitalWrite(pin: Number, pinLevel: LOW | HIGH): void;
    // set pin mode
    declare function pinMode(pin: Number, pinMode: INPUT | OUTPUT): void;
    // Milliseconds delay
    declare function delay(howLong_ms: Number): void;
    // Microseconds delay
    declare function delayMicroseconds(howLong_mks: Number): void;
}

export = wiringPi;


