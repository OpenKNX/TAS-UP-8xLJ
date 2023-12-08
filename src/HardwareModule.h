#include "BinaryInputChannel.h"
#include "OpenKNX/Module.h"
#include "hardware.h"

struct HardwareTaster
{
    bool status = false;
    uint8_t pin;
};

class HardwareModule : public OpenKNX::Module
{

  public:
    const std::string name() override;
    const std::string version() override;
    void loop() override;
    void setup() override;

  private:
    void processBinaryInputs();
    void processTasterInputs();

    uint32_t _lastHardwareQuery = 0;

    BinaryInputChannel *_binaryInputChannels[BI_ChannelCount] = {
        new BinaryInputChannel(0),
        new BinaryInputChannel(1)};

    HardwareTaster _taster[8];
};