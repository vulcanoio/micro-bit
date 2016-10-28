#include "MicroBit.h"

MicroBitMessageBus bus;
MicroBitDisplay display;
MicroBitStorage storage;
MicroBitBLEManager bleManager(storage);
BLEDevice *ble;

int main()
{
    scheduler_init(bus);

    if (!ble) {
        bleManager.init("14539", "", bus, false);
        ble = bleManager.ble;
    }

    new MicroBitLEDService(*ble, display);

    display.scroll("*!*RESIN.IO*!*");

    release_fiber();
}