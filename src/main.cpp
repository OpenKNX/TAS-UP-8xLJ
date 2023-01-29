#include "OpenKNX.h"
#include "Logic.h"
#include "HardwareModule.h"
#include "SmartMF.h"
#include "VirtualButtonModule.h"

void setup()
{
    const uint8_t firmwareRevision = 2;
    openknx.init(firmwareRevision);
    smartmf.init();
    openknx.addModule(1, new Logic());
    openknx.addModule(2, new VirtualButtonModule());
    openknx.addModule(3, new HardwareModule());
    openknx.setup();
}

void loop()
{
    openknx.loop();
}
