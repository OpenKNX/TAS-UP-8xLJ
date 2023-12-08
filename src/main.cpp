#include "HardwareModule.h"
#include "Logic.h"
#include "OpenKNX.h"
#include "SmartMF.h"
#include "VirtualButtonModule.h"
#include "UsbExchangeModule.h"
#include "FileTransferModule.h"

void setup()
{
    const uint8_t firmwareRevision = 1;
    openknx.init(firmwareRevision);
    smartmf.init();
    openknx.addModule(1, new Logic());
    openknx.addModule(2, openknxVirtualButtonModule);
    openknx.addModule(3, new HardwareModule());
    openknx.addModule(4, openknxUsbExchangeModule);
    openknx.addModule(5, openknxFileTransferModule);
    openknx.setup();

}

void loop()
{
    openknx.loop();
}
